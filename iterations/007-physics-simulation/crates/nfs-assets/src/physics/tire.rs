//! Tire friction and slip dynamics.
//!
//! Computes longitudinal and lateral forces via friction ellipse with grip factors from `.sim`.

use glam::Vec2;

/// State and forces for a single tire.
#[derive(Debug, Clone, PartialEq)]
pub struct Tire {
    /// Rolling radius (m, typically ~0.30 - 0.32m).
    pub radius: f32,
    /// Rotational inertia of wheel and tire assembly (kg*m^2).
    pub inertia: f32,
    /// Current wheel angular velocity (rad/s).
    pub omega: f32,
    /// Base peak friction coefficient (mu, typically ~1.0 - 1.1 on clean asphalt).
    pub base_friction_coeff: f32,
    /// Grip multiplier from `.sim` (normalized around 1.0, e.g. 100.0 / 100.0).
    pub grip_multiplier: f32,
    /// Cornering stiffness (1/rad, typically ~10.0 - 15.0).
    pub cornering_stiffness: f32,

    /// Calculated longitudinal slip ratio (-1.0 to +1.0).
    pub slip_ratio: f32,
    /// Calculated lateral slip angle in radians.
    pub slip_angle: f32,
    /// Vertical normal force on tire (N).
    pub normal_load: f32,
    /// Generated longitudinal force along wheel forward direction (N).
    pub longitudinal_force: f32,
    /// Generated lateral force perpendicular to wheel heading (N).
    pub lateral_force: f32,
}

impl Tire {
    /// Create a new tire with given radius and grip multiplier.
    pub fn new(radius: f32, grip_multiplier: f32) -> Self {
        Self {
            radius: radius.max(0.1),
            inertia: 1.2, // ~15 kg wheel with 0.31m radius ≈ 0.5 * 15 * 0.31^2 ≈ 0.72 - 1.2 kg*m^2
            omega: 0.0,
            base_friction_coeff: 1.0,
            grip_multiplier: grip_multiplier.max(0.1),
            cornering_stiffness: 12.0,
            slip_ratio: 0.0,
            slip_angle: 0.0,
            normal_load: 0.0,
            longitudinal_force: 0.0,
            lateral_force: 0.0,
        }
    }

    /// Linear ground speed of wheel surface due to rotation (m/s).
    pub fn surface_speed(&self) -> f32 {
        self.omega * self.radius
    }

    /// Compute contact forces and update wheel rotational velocity.
    ///
    /// - `normal_load`: vertical force from suspension (N)
    /// - `wheel_forward_speed`: velocity component along wheel heading (m/s)
    /// - `wheel_lateral_speed`: velocity component perpendicular to wheel heading (m/s)
    /// - `drive_torque`: motor/drivetrain torque applied to wheel (Nm)
    /// - `brake_torque`: braking torque opposing rotation (Nm, always >= 0)
    /// - `dt`: simulation step time (s)
    pub fn step(
        &mut self,
        normal_load: f32,
        wheel_forward_speed: f32,
        wheel_lateral_speed: f32,
        drive_torque: f32,
        brake_torque: f32,
        dt: f32,
    ) -> Vec2 {
        self.normal_load = normal_load.max(0.0);

        if self.normal_load <= 1e-3 {
            // Tire is airborne: zero contact forces
            self.slip_ratio = 0.0;
            self.slip_angle = 0.0;
            self.longitudinal_force = 0.0;
            self.lateral_force = 0.0;

            // Free wheel rotation under drive/brake torque
            let net_torque =
                drive_torque - self.omega.signum() * brake_torque.min(drive_torque.abs());
            self.omega += (net_torque / self.inertia) * dt;
            return Vec2::ZERO;
        }

        // 1. Longitudinal slip ratio kappa = (omega * r - v_x) / max(|v_x|, 1.0)
        let v_long = wheel_forward_speed;
        let v_roll = self.omega * self.radius;
        let denom = v_long.abs().max(1.0);
        self.slip_ratio = ((v_roll - v_long) / denom).clamp(-1.0, 1.0);

        // 2. Lateral slip angle alpha = -atan2(v_lat, |v_long| + 0.1)
        self.slip_angle = -wheel_lateral_speed.atan2(v_long.abs().max(0.5));

        // 3. Peak friction budget (Coulomb friction limit)
        let mu_peak = self.base_friction_coeff * self.grip_multiplier;
        let max_traction = mu_peak * self.normal_load;

        // 4. Unconstrained requested forces:
        // Longitudinal force proportional to slip ratio:
        let f_long_req = self.slip_ratio * max_traction * 2.0;

        // Lateral cornering force proportional to slip angle:
        let f_lat_req = (self.slip_angle * self.cornering_stiffness * self.normal_load)
            .clamp(-max_traction, max_traction);

        // 5. Combined friction ellipse:
        // (F_long / max_traction)^2 + (F_lat / max_traction)^2 <= 1
        let norm_long = f_long_req / max_traction.max(1.0);
        let norm_lat = f_lat_req / max_traction.max(1.0);
        let combined_demand = (norm_long * norm_long + norm_lat * norm_lat).sqrt();

        if combined_demand > 1.0 {
            self.longitudinal_force = f_long_req / combined_demand;
            self.lateral_force = f_lat_req / combined_demand;
        } else {
            self.longitudinal_force = f_long_req;
            self.lateral_force = f_lat_req;
        }

        // 6. Update wheel rotational speed:
        // I * domega/dt = DriveTorque - BrakeTorque*sign(omega) - F_long * Radius
        let tire_torque = self.longitudinal_force * self.radius;
        let ext_torque = drive_torque - tire_torque;

        if self.omega.abs() < 0.2 && ext_torque.abs() <= brake_torque {
            // Static brake lock: brake torque exceeds external torque holding wheel stationary
            self.omega = 0.0;
        } else {
            let brake_oppose = if self.omega.abs() >= 0.2 {
                self.omega.signum() * brake_torque
            } else {
                ext_torque.signum() * brake_torque
            };
            let net_wheel_torque = ext_torque - brake_oppose;
            self.omega += (net_wheel_torque / self.inertia) * dt;
        }

        // Prevent micro-oscillations near zero speed
        if v_long.abs() < 0.2 && drive_torque.abs() < 1.0 && brake_torque > 10.0 {
            self.omega = 0.0;
            self.longitudinal_force = -v_long * self.normal_load * 2.0;
        }

        Vec2::new(self.longitudinal_force, self.lateral_force)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn airborne_tire_has_zero_forces() {
        let mut tire = Tire::new(0.31, 1.0);
        let forces = tire.step(0.0, 20.0, 2.0, 500.0, 0.0, 0.01);
        assert_eq!(forces, Vec2::ZERO);
        assert_eq!(tire.longitudinal_force, 0.0);
        assert_eq!(tire.lateral_force, 0.0);
    }

    #[test]
    fn traction_under_forward_acceleration() {
        let mut tire = Tire::new(0.31, 1.0);
        let normal_force = 4000.0; // ~400 kg wheel load
        tire.omega = 100.0; // spinning faster than vehicle ground speed
        let forces = tire.step(normal_force, 20.0, 0.0, 1000.0, 0.0, 0.01);

        // Positive forward drive force
        assert!(forces.x > 0.0);
        assert!(forces.x <= normal_force * 1.08 * 1.05); // capped by friction
        assert_eq!(forces.y, 0.0); // no lateral slip
    }

    #[test]
    fn friction_ellipse_limits_combined_forces() {
        let mut tire = Tire::new(0.31, 1.0);
        let normal_force = 3000.0;
        let max_traction = normal_force * 1.08;

        tire.omega = 150.0; // extreme slip
        let forces = tire.step(normal_force, 20.0, 15.0, 5000.0, 0.0, 0.01);

        let combined = (forces.x * forces.x + forces.y * forces.y).sqrt();
        assert!(combined <= max_traction * 1.02); // within friction budget
    }
}
