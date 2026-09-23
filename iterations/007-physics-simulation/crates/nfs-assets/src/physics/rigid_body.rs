//! 6 DOF Rigid Body dynamics for vehicle chassis.

use glam::{Mat4, Quat, Vec3};

/// A rigid body in 3D space with 6 degrees of freedom (position, orientation, linear & angular velocity).
#[derive(Debug, Clone, PartialEq)]
pub struct RigidBody {
    /// World position of the body reference point (m).
    pub position: Vec3,
    /// World orientation unit quaternion (identity = facing -Z, +Y up, +X right).
    pub orientation: Quat,
    /// Linear velocity in world coordinates (m/s).
    pub linear_velocity: Vec3,
    /// Angular velocity in body coordinates (rad/s).
    pub angular_velocity: Vec3,

    /// Total mass (kg).
    pub mass: f32,
    /// Inverse mass (1/kg).
    pub inv_mass: f32,
    /// Principal diagonal moments of inertia in body frame [Ixx, Iyy, Izz] (kg*m^2).
    pub inertia: Vec3,
    /// Inverse moments of inertia [1/Ixx, 1/Iyy, 1/Izz].
    pub inv_inertia: Vec3,
    /// Center of mass offset from body reference point in body frame (m).
    pub center_of_mass: Vec3,

    /// Accumulated force in world coordinates for current sub-step (N).
    pub accum_force: Vec3,
    /// Accumulated torque in body coordinates for current sub-step (N*m).
    pub accum_torque: Vec3,

    /// Linear velocity damping factor (per second).
    pub linear_damping: f32,
    /// Angular velocity damping factor (per second).
    pub angular_damping: f32,
}

impl RigidBody {
    /// Create a new rigid body with given mass, bounding dimensions (width, height, length in meters), and CG offset.
    pub fn new(mass: f32, width: f32, height: f32, length: f32, center_of_mass: Vec3) -> Self {
        let safe_mass = mass.max(1.0);
        let inv_mass = 1.0 / safe_mass;

        // Principal moments of inertia for a cuboid:
        // Ixx (roll)  = (1/12) * m * (height^2 + length^2)
        // Iyy (yaw)   = (1/12) * m * (width^2 + length^2)
        // Izz (pitch) = (1/12) * m * (width^2 + height^2)
        let c = safe_mass / 12.0;
        let ixx = (c * (height * height + length * length)).max(10.0);
        let iyy = (c * (width * width + length * length)).max(10.0);
        let izz = (c * (width * width + height * height)).max(10.0);

        let inertia = Vec3::new(ixx, iyy, izz);
        let inv_inertia = Vec3::new(1.0 / ixx, 1.0 / iyy, 1.0 / izz);

        Self {
            position: Vec3::ZERO,
            orientation: Quat::IDENTITY,
            linear_velocity: Vec3::ZERO,
            angular_velocity: Vec3::ZERO,
            mass: safe_mass,
            inv_mass,
            inertia,
            inv_inertia,
            center_of_mass,
            accum_force: Vec3::ZERO,
            accum_torque: Vec3::ZERO,
            linear_damping: 0.001,
            angular_damping: 0.05,
        }
    }

    /// World position of the Center of Mass (COM).
    pub fn world_com(&self) -> Vec3 {
        self.position + self.orientation * self.center_of_mass
    }

    /// Forward unit vector in world space (vehicle points along -Z in local space).
    pub fn forward(&self) -> Vec3 {
        self.orientation * Vec3::new(0.0, 0.0, -1.0)
    }

    /// Right unit vector in world space (+X in local space).
    pub fn right(&self) -> Vec3 {
        self.orientation * Vec3::new(1.0, 0.0, 0.0)
    }

    /// Up unit vector in world space (+Y in local space).
    pub fn up(&self) -> Vec3 {
        self.orientation * Vec3::new(0.0, 1.0, 0.0)
    }

    /// Forward speed in m/s along vehicle heading (positive = moving forward along -Z).
    pub fn forward_speed(&self) -> f32 {
        self.linear_velocity.dot(self.forward())
    }

    /// Transformation matrix for the rigid body pose in world coordinates.
    pub fn transform_matrix(&self) -> Mat4 {
        Mat4::from_rotation_translation(self.orientation, self.position)
    }

    /// Transform a point from body space to world space.
    pub fn to_world_pos(&self, body_point: Vec3) -> Vec3 {
        self.position + self.orientation * body_point
    }

    /// Transform a vector from body space to world space.
    pub fn to_world_vec(&self, body_vec: Vec3) -> Vec3 {
        self.orientation * body_vec
    }

    /// Transform a point from world space to body space.
    pub fn to_body_pos(&self, world_point: Vec3) -> Vec3 {
        self.orientation.inverse() * (world_point - self.position)
    }

    /// Transform a vector from world space to body space.
    pub fn to_body_vec(&self, world_vec: Vec3) -> Vec3 {
        self.orientation.inverse() * world_vec
    }

    /// Velocity of a specific point on the rigid body in world space.
    pub fn point_velocity(&self, world_point: Vec3) -> Vec3 {
        let r_world = world_point - self.world_com();
        let ang_vel_world = self.orientation * self.angular_velocity;
        self.linear_velocity + ang_vel_world.cross(r_world)
    }

    /// Clear force and torque accumulators for a new integration sub-step.
    pub fn clear_accumulators(&mut self) {
        self.accum_force = Vec3::ZERO;
        self.accum_torque = Vec3::ZERO;
    }

    /// Apply a force in world space at the center of mass (no torque).
    pub fn apply_central_force(&mut self, world_force: Vec3) {
        self.accum_force += world_force;
    }

    /// Apply a torque directly in body space.
    pub fn apply_body_torque(&mut self, body_torque: Vec3) {
        self.accum_torque += body_torque;
    }

    /// Apply a force in world coordinates at a specific world position.
    pub fn apply_force_at_world_pos(&mut self, world_force: Vec3, world_pos: Vec3) {
        self.accum_force += world_force;
        let r_world = world_pos - self.world_com();
        let torque_world = r_world.cross(world_force);
        let torque_body = self.orientation.inverse() * torque_world;
        self.accum_torque += torque_body;
    }

    /// Apply a force in body coordinates at a specific body position.
    pub fn apply_force_at_body_pos(&mut self, body_force: Vec3, body_pos: Vec3) {
        let world_force = self.to_world_vec(body_force);
        let world_pos = self.to_world_pos(body_pos);
        self.apply_force_at_world_pos(world_force, world_pos);
    }

    /// Integrate the rigid body state by time step `dt` seconds using semi-implicit Euler.
    pub fn integrate(&mut self, dt: f32, gravity: Vec3) {
        if dt <= 0.0 || !dt.is_finite() {
            return;
        }

        // 1. Linear dynamics
        let linear_accel = (self.accum_force * self.inv_mass) + gravity;
        self.linear_velocity += linear_accel * dt;

        // Apply linear damping
        let lin_damp = (1.0 - self.linear_damping * dt).clamp(0.0, 1.0);
        self.linear_velocity *= lin_damp;

        // Update position
        self.position += self.linear_velocity * dt;

        // 2. Angular dynamics in body frame (Euler's equations of motion)
        // I * domega/dt + omega x (I * omega) = tau
        // domega/dt = inv_I * (tau - omega x (I * omega))
        let i_omega = self.inertia * self.angular_velocity;
        let gyroscopic_torque = self.angular_velocity.cross(i_omega);
        let angular_accel = self.inv_inertia * (self.accum_torque - gyroscopic_torque);

        self.angular_velocity += angular_accel * dt;

        // Apply angular damping
        let ang_damp = (1.0 - self.angular_damping * dt).clamp(0.0, 1.0);
        self.angular_velocity *= ang_damp;

        // Update orientation quaternion:
        // dq/dt = 0.5 * omega_world * q
        let ang_vel_world = self.orientation * self.angular_velocity;
        let rot_delta = Quat::from_scaled_axis(ang_vel_world * dt);
        self.orientation = (rot_delta * self.orientation).normalize();

        // 3. Clear accumulators
        self.clear_accumulators();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn free_fall_under_gravity() {
        let mut body = RigidBody::new(1000.0, 1.8, 1.3, 4.2, Vec3::ZERO);
        let gravity = Vec3::new(0.0, -9.81, 0.0);
        let dt = 1.0 / 240.0;

        for _ in 0..240 {
            body.integrate(dt, gravity);
        }

        // After 1 second: v ≈ -9.81 m/s, y ≈ -4.905 m
        assert!((body.linear_velocity.y - (-9.81)).abs() < 0.1);
        assert!((body.position.y - (-4.905)).abs() < 0.1);
    }

    #[test]
    fn central_force_produces_no_rotation() {
        let mut body = RigidBody::new(1000.0, 1.8, 1.3, 4.2, Vec3::ZERO);
        body.apply_central_force(Vec3::new(5000.0, 0.0, 0.0));
        body.integrate(0.1, Vec3::ZERO);

        assert!(body.linear_velocity.x > 0.0);
        assert_eq!(body.angular_velocity, Vec3::ZERO);
        assert_eq!(body.orientation, Quat::IDENTITY);
    }

    #[test]
    fn offset_force_produces_rotation() {
        let mut body = RigidBody::new(1000.0, 1.8, 1.3, 4.2, Vec3::ZERO);
        // Apply forward force (+Z in world) at right side (+X in body)
        let right_pos = body.to_world_pos(Vec3::new(1.0, 0.0, 0.0));
        body.apply_force_at_world_pos(Vec3::new(0.0, 0.0, -1000.0), right_pos);
        body.integrate(0.01, Vec3::ZERO);

        // Yaw torque should be produced around Y
        assert!(body.angular_velocity.y.abs() > 0.0);
    }

    #[test]
    fn local_and_world_roundtrip() {
        let mut body = RigidBody::new(1000.0, 1.8, 1.3, 4.2, Vec3::ZERO);
        body.position = Vec3::new(10.0, 2.0, -50.0);
        body.orientation = Quat::from_rotation_y(0.785); // 45 deg

        let local_pt = Vec3::new(0.5, 0.2, -1.2);
        let world_pt = body.to_world_pos(local_pt);
        let recovered = body.to_body_pos(world_pt);

        assert!((local_pt - recovered).length() < 1e-5);
    }
}
