//! Arcade car physics and chase camera for NFS track driving.

use glam::{Mat4, Vec3};
use nfs_assets::TopologyEdge;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum DriveViewMode {
    Chase,
    Bumper,
    Free,
}

#[derive(Debug, Clone)]
pub struct ArcadeCar {
    pub pos: Vec3,
    pub yaw: f32,         // radians, 0 = -Z
    pub pitch: f32,       // road grade tilt (radians)
    pub roll: f32,        // road banking tilt (radians)
    pub speed: f32,       // m/s (1 m/s = 3.6 km/h)
    pub steer_angle: f32, // current wheel turn angle in radians
    pub is_braking: bool,
    pub is_handbraking: bool,
    pub is_reversing: bool,
    pub gear: i32, // -1 (R), 0 (N), 1..5
    pub rpm: f32,  // 0.0 .. 1.0
    pub view_mode: DriveViewMode,
    pub camera_eye: Vec3,
    pub camera_target: Vec3,
    pub paint_color_idx: usize,
    pub spawn_pos: Vec3,
    pub spawn_yaw: f32,
}

const WHEELBASE: f32 = 2.45;
const MAX_FORWARD_SPEED: f32 = 38.0; // ~137 km/h (controllable arcade speed)
const MAX_REVERSE_SPEED: f32 = -9.0; // ~32 km/h
const ACCEL_RATE: f32 = 9.5; // m/s^2 (~0-100 in ~4s, responsive and controllable)
const BRAKE_RATE: f32 = 22.0; // m/s^2
const HANDBRAKE_RATE: f32 = 30.0; // m/s^2
const COLLISION_RADIUS: f32 = 1.30; // meters

impl ArcadeCar {
    pub fn new(spawn_pos: Vec3, spawn_yaw: f32) -> Self {
        let forward = Vec3::new(-spawn_yaw.sin(), 0.0, -spawn_yaw.cos());
        let eye = spawn_pos + Vec3::new(0.0, 2.0, 0.0) - forward * 5.8;
        let target = spawn_pos + Vec3::new(0.0, 0.9, 0.0) + forward * 1.5;

        Self {
            pos: spawn_pos,
            yaw: spawn_yaw,
            pitch: 0.0,
            roll: 0.0,
            speed: 0.0,
            steer_angle: 0.0,
            is_braking: false,
            is_handbraking: false,
            is_reversing: false,
            gear: 1,
            rpm: 0.15,
            view_mode: DriveViewMode::Chase,
            camera_eye: eye,
            camera_target: target,
            paint_color_idx: 0,
            spawn_pos,
            spawn_yaw,
        }
    }

    pub fn cycle_view_mode(&mut self) -> DriveViewMode {
        self.view_mode = match self.view_mode {
            DriveViewMode::Chase => DriveViewMode::Bumper,
            DriveViewMode::Bumper => DriveViewMode::Free,
            DriveViewMode::Free => DriveViewMode::Chase,
        };
        self.view_mode
    }

    pub fn cycle_paint(&mut self) -> usize {
        self.paint_color_idx = (self.paint_color_idx + 1) % 6;
        self.paint_color_idx
    }

    pub fn forward(&self) -> Vec3 {
        Vec3::new(-self.yaw.sin(), 0.0, -self.yaw.cos()).normalize_or_zero()
    }

    pub fn right(&self) -> Vec3 {
        let fwd = self.forward();
        fwd.cross(Vec3::Y).normalize_or_zero()
    }

    pub fn speed_kmh(&self) -> f32 {
        self.speed * 3.6
    }

    pub fn model_matrix(&self) -> Mat4 {
        Mat4::from_translation(self.pos)
            * Mat4::from_rotation_y(self.yaw)
            * Mat4::from_rotation_x(self.pitch)
            * Mat4::from_rotation_z(self.roll)
    }

    /// Reset car to spawn position and clear velocity
    pub fn reset_to_road(&mut self, _edges: &[TopologyEdge]) {
        self.pos = self.spawn_pos;
        self.yaw = self.spawn_yaw;
        self.pitch = 0.0;
        self.roll = 0.0;
        self.speed = 0.0;
        self.steer_angle = 0.0;
        self.is_braking = false;
        self.is_handbraking = false;
        self.is_reversing = false;
        self.gear = 1;
        self.rpm = 0.15;

        let fwd = self.forward();
        self.camera_eye = self.pos + Vec3::new(0.0, 2.0, 0.0) - fwd * 5.8;
        self.camera_target = self.pos + Vec3::new(0.0, 0.9, 0.0) + fwd * 1.5;
    }

    /// Advance arcade vehicle physics by `dt` seconds with inputs.
    pub fn update(
        &mut self,
        dt: f32,
        throttle: f32, // -1.0 (brake/reverse) .. +1.0 (gas)
        steer: f32,    // -1.0 (left) .. +1.0 (right)
        handbrake: bool,
        edges: &[TopologyEdge],
        sample_elevation: impl Fn(f32, f32) -> Option<f32>,
    ) {
        let dt = dt.clamp(0.001, 0.1);

        // 1. Steering dynamics (speed-sensitive arcade damping)
        let speed_ratio = (self.speed.abs() / MAX_FORWARD_SPEED).clamp(0.0, 1.0);
        let max_steer =
            (35.0_f32.to_radians()).max(12.0_f32.to_radians() * (1.0 - speed_ratio * 0.65));
        let target_steer = steer.clamp(-1.0, 1.0) * max_steer;
        self.steer_angle += (target_steer - self.steer_angle) * (14.0 * dt).min(1.0);

        // 2. Throttle, braking, and reverse
        self.is_handbraking = handbrake;
        self.is_braking = false;
        self.is_reversing = false;

        if handbrake {
            // Handbrake: rapid deceleration
            let decel = HANDBRAKE_RATE * dt;
            if self.speed > 0.0 {
                self.speed = (self.speed - decel).max(0.0);
            } else {
                self.speed = (self.speed + decel).min(0.0);
            }
        } else if throttle > 0.05 {
            if self.speed < -0.5 {
                // Moving backward: gas acts as brake
                self.speed += BRAKE_RATE * dt;
                self.is_braking = true;
            } else {
                // Forward acceleration with aerodynamic drag and power tapering
                let speed_ratio = (self.speed / MAX_FORWARD_SPEED).clamp(0.0, 1.0);
                let power_taper = 1.0 - speed_ratio * 0.40;
                let drag = 0.006 * self.speed * self.speed;
                let accel = (ACCEL_RATE * throttle * power_taper - drag).max(0.0);
                self.speed = (self.speed + accel * dt).min(MAX_FORWARD_SPEED);
            }
        } else if throttle < -0.05 {
            if self.speed > 0.5 {
                // Moving forward: brake
                self.speed = (self.speed - BRAKE_RATE * (-throttle) * dt).max(0.0);
                self.is_braking = true;
            } else {
                // Reverse gear
                self.is_reversing = true;
                let accel = ACCEL_RATE * 0.55 * (-throttle);
                self.speed = (self.speed - accel * dt).max(MAX_REVERSE_SPEED);
            }
        } else {
            // Coasting: natural drag & rolling friction
            let friction = 3.2 * dt;
            let drag = 0.012 * self.speed * self.speed * dt;
            if self.speed > 0.0 {
                self.speed = (self.speed - friction - drag).max(0.0);
            } else {
                self.speed = (self.speed + friction + drag).min(0.0);
            }
        }

        // 3. Angular velocity / heading update
        if self.speed.abs() > 0.05 {
            let mut angular_vel = (self.speed / WHEELBASE) * self.steer_angle.tan();
            if handbrake && self.speed.abs() > 3.0 {
                // Drift amplification
                angular_vel *= 1.85;
            }
            // Invert sign: turning right (steer > 0) rotates yaw negatively towards +X
            self.yaw -= angular_vel * dt;
        }

        // 4. Update horizontal position
        let fwd = self.forward();
        let delta_pos = fwd * self.speed * dt;
        self.pos.x += delta_pos.x;
        self.pos.z += delta_pos.z;

        // 5. Road boundary collision & bounce
        self.handle_edge_collisions(edges);

        // 6. Surface elevation, road grade pitch & roll
        if let Some(y_center) = sample_elevation(self.pos.x, self.pos.z) {
            self.pos.y = y_center;

            let fwd_h = self.forward();
            let right_h = self.right();

            let front = self.pos + fwd_h * 1.3;
            let rear = self.pos - fwd_h * 1.3;
            let left = self.pos - right_h * 0.8;
            let right = self.pos + right_h * 0.8;

            let y_front = sample_elevation(front.x, front.z).unwrap_or(y_center);
            let y_rear = sample_elevation(rear.x, rear.z).unwrap_or(y_center);
            let y_left = sample_elevation(left.x, left.z).unwrap_or(y_center);
            let y_right = sample_elevation(right.x, right.z).unwrap_or(y_center);

            let target_pitch = ((y_front - y_rear) / 2.6).atan();
            let target_roll = -((y_right - y_left) / 1.6).atan();

            self.pitch += (target_pitch - self.pitch) * (18.0 * dt).min(1.0);
            self.roll += (target_roll - self.roll) * (18.0 * dt).min(1.0);
        }

        // 7. Calculate gear and RPM for speedometer
        self.update_gear_and_rpm();

        // 8. Update chase camera
        self.update_camera(dt);
    }

    fn handle_edge_collisions(&mut self, edges: &[TopologyEdge]) {
        if edges.is_empty() {
            return;
        }

        let px = self.pos.x;
        let pz = self.pos.z;

        for edge in edges {
            let x1 = edge.p1[0];
            let z1 = edge.p1[2];
            let x2 = edge.p2[0];
            let z2 = edge.p2[2];

            let dx = x2 - x1;
            let dz = z2 - z1;
            let seg_len_sq = dx * dx + dz * dz;
            if seg_len_sq < 1e-4 {
                continue;
            }

            let t = (((px - x1) * dx + (pz - z1) * dz) / seg_len_sq).clamp(0.0, 1.0);
            let closest_x = x1 + t * dx;
            let closest_z = z1 + t * dz;

            let dist_x = px - closest_x;
            let dist_z = pz - closest_z;
            let dist_sq = dist_x * dist_x + dist_z * dist_z;

            if dist_sq < COLLISION_RADIUS * COLLISION_RADIUS && dist_sq > 1e-6 {
                let dist = dist_sq.sqrt();
                let penetration = COLLISION_RADIUS - dist;
                let nx = dist_x / dist;
                let nz = dist_z / dist;

                // Push car away from boundary
                self.pos.x += nx * penetration;
                self.pos.z += nz * penetration;

                // Bounce / scrub speed
                self.speed *= 0.84;

                // Slight yaw deflection
                let fwd = self.forward();
                let dot = fwd.x * nx + fwd.z * nz;
                if dot < 0.0 {
                    self.yaw += dot * 0.15;
                }
            }
        }
    }

    fn update_gear_and_rpm(&mut self) {
        let kmh = self.speed.abs() * 3.6;
        if self.speed < -0.2 {
            self.gear = -1; // Reverse
            self.rpm = (kmh / 45.0).clamp(0.2, 0.95);
        } else if kmh < 0.5 {
            self.gear = 1;
            self.rpm = 0.15;
        } else if kmh < 45.0 {
            self.gear = 1;
            self.rpm = 0.20 + (kmh / 45.0) * 0.75;
        } else if kmh < 82.0 {
            self.gear = 2;
            self.rpm = 0.28 + ((kmh - 45.0) / 37.0) * 0.68;
        } else if kmh < 124.0 {
            self.gear = 3;
            self.rpm = 0.32 + ((kmh - 82.0) / 42.0) * 0.65;
        } else if kmh < 165.0 {
            self.gear = 4;
            self.rpm = 0.35 + ((kmh - 124.0) / 41.0) * 0.62;
        } else {
            self.gear = 5;
            self.rpm = 0.40 + ((kmh - 165.0) / 50.0).clamp(0.0, 1.0) * 0.58;
        }
    }

    fn update_camera(&mut self, dt: f32) {
        let fwd = self.forward();
        match self.view_mode {
            DriveViewMode::Chase => {
                let ideal_target = self.pos + Vec3::new(0.0, 0.95, 0.0) + fwd * 1.8;
                let ideal_eye = self.pos + Vec3::new(0.0, 2.05, 0.0) - fwd * 5.9;

                // Smooth exponential spring damping for camera tracking
                let eye_rate = (8.5 * dt).min(1.0);
                let target_rate = (14.0 * dt).min(1.0);

                self.camera_eye += (ideal_eye - self.camera_eye) * eye_rate;
                self.camera_target += (ideal_target - self.camera_target) * target_rate;
            }
            DriveViewMode::Bumper => {
                self.camera_eye = self.pos + Vec3::new(0.0, 0.75, 0.0) + fwd * 1.6;
                self.camera_target = self.camera_eye + fwd * 12.0;
            }
            DriveViewMode::Free => {
                // Free camera doesn't lock to car orientation, orbits center
                self.camera_target = self.pos + Vec3::new(0.0, 0.9, 0.0);
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_car_acceleration_and_gears() {
        let mut car = ArcadeCar::new(Vec3::ZERO, 0.0);
        assert_eq!(car.speed, 0.0);
        assert_eq!(car.gear, 1);

        // Accelerate for 2 seconds
        for _ in 0..100 {
            car.update(0.02, 1.0, 0.0, false, &[], |_, _| Some(0.0));
        }

        assert!(car.speed > 10.0, "Car should accelerate forward");
        assert!(car.speed_kmh() > 36.0);
        assert!(car.rpm > 0.0 && car.rpm <= 1.0);
        assert!(car.gear >= 1);
    }

    #[test]
    fn test_car_braking_and_reverse() {
        let mut car = ArcadeCar::new(Vec3::ZERO, 0.0);

        // Reverse from standstill
        for _ in 0..50 {
            car.update(0.02, -1.0, 0.0, false, &[], |_, _| Some(0.0));
        }

        assert!(car.speed < 0.0, "Car should move backwards");
        assert_eq!(car.gear, -1, "Gear should be reverse (R)");
        assert!(car.is_reversing);
    }

    #[test]
    fn test_car_handbrake() {
        let mut car = ArcadeCar::new(Vec3::ZERO, 0.0);
        car.speed = 30.0; // 108 km/h

        for _ in 0..20 {
            car.update(0.02, 0.0, 0.0, true, &[], |_, _| Some(0.0));
        }

        assert!(car.speed < 20.0, "Handbrake should decelerate quickly");
    }

    #[test]
    fn test_car_view_and_paint_cycling() {
        let mut car = ArcadeCar::new(Vec3::ZERO, 0.0);
        assert_eq!(car.view_mode, DriveViewMode::Chase);

        assert_eq!(car.cycle_view_mode(), DriveViewMode::Bumper);
        assert_eq!(car.cycle_view_mode(), DriveViewMode::Free);
        assert_eq!(car.cycle_view_mode(), DriveViewMode::Chase);

        assert_eq!(car.paint_color_idx, 0);
        assert_eq!(car.cycle_paint(), 1);
        assert_eq!(car.cycle_paint(), 2);
    }

    #[test]
    fn test_car_reset() {
        let mut car = ArcadeCar::new(Vec3::new(10.0, 5.0, 10.0), 1.57);
        car.speed = 25.0;
        car.pos = Vec3::new(50.0, 0.0, 50.0);

        car.reset_to_road(&[]);
        assert_eq!(car.speed, 0.0);
        assert_eq!(car.pos, Vec3::new(10.0, 5.0, 10.0));
        assert_eq!(car.yaw, 1.57);
    }

    #[test]
    fn test_car_steering_direction() {
        let mut car_right = ArcadeCar::new(Vec3::ZERO, 0.0);
        car_right.speed = 10.0;
        for _ in 0..20 {
            car_right.update(0.02, 0.0, 1.0, false, &[], |_, _| Some(0.0));
        }
        assert!(
            car_right.forward().x > 0.0,
            "Steering right must orient car forward vector towards +X (right)"
        );

        let mut car_left = ArcadeCar::new(Vec3::ZERO, 0.0);
        car_left.speed = 10.0;
        for _ in 0..20 {
            car_left.update(0.02, 0.0, -1.0, false, &[], |_, _| Some(0.0));
        }
        assert!(
            car_left.forward().x < 0.0,
            "Steering left must orient car forward vector towards -X (left)"
        );
    }
}
