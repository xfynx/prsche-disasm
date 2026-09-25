//! Vehicle powertrain (engine, transmission, drivetrain).
//!
//! Uses the 500-RPM torque curve grid (21 points) from NFS 5 `.sim` specifications.

use nfs_formats::SimCar;

const FT_LB_TO_NM: f32 = 1.355_818;

/// Vehicle powertrain representing engine, clutch, and transmission.
#[derive(Debug, Clone, PartialEq)]
pub struct Powertrain {
    /// 21 torque points in ft-lb spaced at 500 RPM intervals (0, 500, ..., 10000 RPM).
    pub torque_curve_ft_lb: [f32; 21],
    /// Idle engine RPM (e.g. 800 - 1000 RPM).
    pub idle_rpm: f32,
    /// Maximum engine RPM / redline limiter (e.g. 5800 - 8000 RPM).
    pub redline_rpm: f32,
    /// Current engine RPM.
    pub current_rpm: f32,

    /// Number of forward gears (e.g. 4, 5, 6).
    pub forward_gears: u32,
    /// Forward gear ratios (indices 0..5 corresponding to gears 1..6).
    pub gear_ratios: [f32; 8],
    /// Reverse gear ratio (typically negative).
    pub reverse_ratio: f32,
    /// Final drive differential gear ratio.
    pub final_drive: f32,

    /// Current gear: -1 = Reverse, 0 = Neutral, 1..6 = Forward gears.
    pub current_gear: i32,
    /// Clutch engagement (0.0 = disengaged, 1.0 = fully engaged).
    pub clutch: f32,
    /// Drivetrain mechanical efficiency (typically 0.90 .. 0.93).
    pub efficiency: f32,
    /// Rotational inertia of engine and flywheel (kg*m^2).
    pub engine_inertia: f32,
}

impl Powertrain {
    /// Construct a powertrain from a verified `SimCar` descriptor.
    pub fn from_sim(sim: &SimCar) -> Self {
        let forward_gears = (sim.gear_count.clamp(1, 8)) as u32;
        let mut gear_ratios = [0.0f32; 8];
        for (i, ratio) in sim.forward_gears.iter().take(8).enumerate() {
            gear_ratios[i] = *ratio;
        }
        let idle_rpm = if sim.idle_or_step_rpm > 50.0 && sim.idle_or_step_rpm < 2000.0 {
            sim.idle_or_step_rpm
        } else {
            850.0
        };
        let redline_rpm = sim.redline_rpm.max(idle_rpm + 500.0);

        Self {
            torque_curve_ft_lb: sim.torque_curve,
            idle_rpm,
            redline_rpm,
            current_rpm: idle_rpm,
            forward_gears,
            gear_ratios,
            reverse_ratio: sim.reverse_gear,
            final_drive: sim.final_drive,
            current_gear: 1,
            clutch: 1.0,
            efficiency: 0.92,
            engine_inertia: 0.18,
        }
    }

    /// Calculate engine torque output (Nm) at wide-open throttle for a given RPM.
    pub fn engine_torque_at_rpm(&self, rpm: f32) -> f32 {
        if rpm > self.redline_rpm {
            return 0.0;
        }

        // Each index corresponds to 500 RPM
        let idx_float = (rpm / 500.0).max(0.0);
        let idx = idx_float as usize;

        if idx >= 20 {
            return self.torque_curve_ft_lb[20] * FT_LB_TO_NM;
        }

        let frac = idx_float - (idx as f32);
        let tq0 = self.torque_curve_ft_lb[idx];
        let tq1 = self.torque_curve_ft_lb[idx + 1];
        let tq_ft_lb = tq0 * (1.0 - frac) + tq1 * frac;

        tq_ft_lb * FT_LB_TO_NM
    }

    /// Total gear ratio from crankshaft to driven wheel axle.
    pub fn total_gear_ratio(&self) -> f32 {
        if self.current_gear == 0 {
            0.0
        } else if self.current_gear == -1 {
            self.reverse_ratio.abs() * self.final_drive
        } else {
            let g = (self.current_gear - 1) as usize;
            if g < (self.forward_gears as usize) {
                self.gear_ratios[g] * self.final_drive
            } else {
                0.0
            }
        }
    }

    /// Shift up one gear (up to max forward gear).
    pub fn shift_up(&mut self) {
        if self.current_gear < (self.forward_gears as i32) {
            self.current_gear += 1;
        }
    }

    /// Shift down one gear (down to reverse -1).
    pub fn shift_down(&mut self) {
        if self.current_gear > -1 {
            self.current_gear -= 1;
        }
    }

    /// Set gear directly (-1 = Reverse, 0 = Neutral, 1..forward_gears).
    pub fn set_gear(&mut self, gear: i32) {
        if gear >= -1 && gear <= (self.forward_gears as i32) {
            self.current_gear = gear;
        }
    }

    /// Shift directly to specified gear.
    pub fn shift_to(&mut self, gear: i32) {
        self.set_gear(gear);
    }

    /// Current transmission gear ratio without final drive.
    pub fn current_ratio(&self) -> f32 {
        if self.current_gear == 0 {
            0.0
        } else if self.current_gear == -1 {
            self.reverse_ratio
        } else {
            let g = (self.current_gear - 1) as usize;
            if g < (self.forward_gears as usize) {
                self.gear_ratios[g]
            } else {
                0.0
            }
        }
    }

    /// Advance powertrain simulation by `dt` seconds given throttle input (0.0 .. 1.0)
    /// and average angular velocity of driven wheels (rad/s).
    ///
    /// Returns total drive torque delivered to driven wheels (Nm).
    pub fn step(&mut self, throttle: f32, driven_wheel_omega: f32, dt: f32) -> f32 {
        let throttle = throttle.clamp(0.0, 1.0);
        let ratio = self.total_gear_ratio();

        // Calculate wheel-coupled engine RPM
        let coupled_rpm = if ratio.abs() > 0.01 {
            driven_wheel_omega.abs() * ratio * 60.0 / (2.0 * std::f32::consts::PI)
        } else {
            0.0
        };

        // If in gear and clutch engaged, engine is coupled to wheels;
        // otherwise, engine revs freely with throttle and friction damping.
        if self.current_gear != 0 && self.clutch > 0.5 && coupled_rpm > self.idle_rpm {
            // Smoothly track coupled RPM
            self.current_rpm = coupled_rpm.clamp(self.idle_rpm, self.redline_rpm);
        } else {
            // Free-revving engine dynamics:
            // d(omega)/dt = (Torque_combustion - Friction_torque) / Inertia
            let available_tq = self.engine_torque_at_rpm(self.current_rpm);
            let drive_tq = available_tq * throttle;
            let friction_tq = 15.0 + 0.005 * self.current_rpm; // engine internal drag
            let net_tq = drive_tq - friction_tq;

            let d_omega = (net_tq / self.engine_inertia) * dt;
            let d_rpm = d_omega * 60.0 / (2.0 * std::f32::consts::PI);
            self.current_rpm = (self.current_rpm + d_rpm).clamp(self.idle_rpm, self.redline_rpm);
        }

        // Deliverable engine torque
        let engine_tq = self.engine_torque_at_rpm(self.current_rpm) * throttle;

        // Drive torque delivered to wheels
        if self.current_gear == 0 || ratio.abs() < 0.01 {
            0.0
        } else {
            let sign = if self.current_gear == -1 { -1.0 } else { 1.0 };
            sign * engine_tq * ratio * self.efficiency * self.clutch
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn test_sim_boxster() -> SimCar {
        SimCar {
            name: "Test Boxster".to_string(),
            mass_kg: 1252.0,
            wheelbase_m: 2.415,
            gear_count: 5,
            drive_flags: 2,
            reverse_gear: -3.44,
            forward_gears: vec![3.50, 2.12, 1.43, 1.03, 0.79],
            final_drive: 3.89,
            redline_rpm: 6700.0,
            idle_or_step_rpm: 800.0,
            torque_curve: [
                98.0, 102.0, 130.0, 138.0, 157.0, 157.0, 169.0, 169.0, 173.0, 181.0, 181.0, 173.0,
                146.0, 110.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            ],
            brake_bias: 0.6,
            drag_coeff: 0.31,
            swaybar_stiffness: 10000.0,
            suspension_stiffness: 25.0,
            front_track_m: 1.465,
            rear_track_m: 1.500,
            damping_compression: 2.5,
            damping_rebound: 3.0,
            tire_grip: 100.0,
            cg_offset_m: [0.0, 0.35, -0.1],
            raw: [0u8; 328],
        }
    }

    #[test]
    fn torque_curve_interpolation() {
        let sim = test_sim_boxster();
        let pt = Powertrain::from_sim(&sim);

        // At 0 RPM: 98 ft-lb * 1.355818 ≈ 132.87 Nm
        let tq_0 = pt.engine_torque_at_rpm(0.0);
        assert!((tq_0 - 132.87).abs() < 1.0);

        // At 4500 RPM (index 9): 181 ft-lb * 1.355818 ≈ 245.4 Nm
        let tq_4500 = pt.engine_torque_at_rpm(4500.0);
        assert!((tq_4500 - 245.4).abs() < 1.0);

        // At 4750 RPM (halfway between index 9 and 10): 181 ft-lb
        let tq_4750 = pt.engine_torque_at_rpm(4750.0);
        assert!((tq_4750 - 245.4).abs() < 1.0);

        // Beyond redline: 0 Nm
        assert_eq!(pt.engine_torque_at_rpm(7000.0), 0.0);
    }

    #[test]
    fn transmission_gear_ratios() {
        let sim = test_sim_boxster();
        let mut pt = Powertrain::from_sim(&sim);

        // 1st gear: 3.50 * 3.89 = 13.615
        assert_eq!(pt.current_gear, 1);
        assert!((pt.total_gear_ratio() - (3.50 * 3.89)).abs() < 1e-4);

        // Shift up to 2nd gear: 2.12 * 3.89
        pt.shift_up();
        assert_eq!(pt.current_gear, 2);
        assert!((pt.total_gear_ratio() - (2.12 * 3.89)).abs() < 1e-4);

        // Neutral: 0.0
        pt.set_gear(0);
        assert_eq!(pt.total_gear_ratio(), 0.0);

        // Reverse: |-3.44| * 3.89
        pt.set_gear(-1);
        assert!((pt.total_gear_ratio() - (3.44 * 3.89)).abs() < 1e-4);
    }

    #[test]
    fn wheel_torque_delivery() {
        let sim = test_sim_boxster();
        let mut pt = Powertrain::from_sim(&sim);

        // 1st gear full throttle with wheels rolling at ~20 rad/s (~22 km/h)
        let wheel_tq = pt.step(1.0, 20.0, 0.01);
        assert!(wheel_tq > 1000.0); // 245 Nm * 13.6 ratio * 0.92 efficiency ≈ 3060 Nm

        // Zero throttle delivers zero drive torque
        let idle_tq = pt.step(0.0, 20.0, 0.01);
        assert_eq!(idle_tq, 0.0);
    }
}
