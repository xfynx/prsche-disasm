//! 4-wheel independent suspension and surface contact.
//!
//! Raycasts from chassis suspension mounts against the static RoadSurface spatial grid,
//! computing spring, damping (bump/rebound from `.sim`), and anti-roll bar forces.

use glam::Vec3;
use nfs_formats::SimCar;

use super::original_support_owner::OriginalSupportOwner;
use crate::physics::rigid_body::RigidBody;
use crate::physics::tire::Tire;
use crate::surface::RoadSurface;

pub const WHEEL_FL: usize = 0;
pub const WHEEL_FR: usize = 1;
pub const WHEEL_RL: usize = 2;
pub const WHEEL_RR: usize = 3;

/// A single wheel suspension assembly.
#[derive(Debug, Clone, PartialEq)]
pub struct SuspensionWheel {
    /// Original per-wheel polygon/node cache. The force solver below remains
    /// the existing adapter; this state belongs only to recovered geometry queries.
    pub support_owner: OriginalSupportOwner,
    /// Suspension top mount position in vehicle body frame (m).
    pub hardpoint_body: Vec3,
    /// Uncompressed suspension spring length (m).
    pub rest_length: f32,
    /// Maximum allowable suspension travel in compression (m).
    pub max_compression: f32,
    /// Spring stiffness constant (N/m).
    pub spring_k: f32,
    /// Shock absorber bump damping coefficient during compression (N*s/m).
    pub damper_bump: f32,
    /// Shock absorber rebound damping coefficient during extension (N*s/m).
    pub damper_rebound: f32,

    /// Current spring compression distance (m).
    pub compression: f32,
    /// Compression rate of change (m/s, > 0 compressing, < 0 extending).
    pub compression_velocity: f32,
    /// True if tire is touching the ground.
    pub in_contact: bool,
    /// Contact point in world space.
    pub contact_point_world: Vec3,
    /// Ground surface normal in world space.
    pub ground_normal_world: Vec3,

    /// Steering angle of this wheel relative to chassis forward (radians).
    pub steer_angle: f32,
    /// Whether this wheel steers (true for front wheels).
    pub is_steered: bool,
    /// Whether this wheel receives powertrain drive torque (RWD / 4WD).
    pub is_driven: bool,

    /// Tire state and friction model.
    pub tire: Tire,
}

impl SuspensionWheel {
    pub fn new(
        hardpoint_body: Vec3,
        spring_k: f32,
        damper_bump: f32,
        damper_rebound: f32,
        is_steered: bool,
        is_driven: bool,
        grip_mult: f32,
    ) -> Self {
        Self {
            support_owner: OriginalSupportOwner::default(),
            hardpoint_body,
            rest_length: 0.35,
            max_compression: 0.20,
            spring_k: spring_k.max(1000.0),
            damper_bump: damper_bump.max(100.0),
            damper_rebound: damper_rebound.max(100.0),
            compression: 0.0,
            compression_velocity: 0.0,
            in_contact: false,
            contact_point_world: Vec3::ZERO,
            ground_normal_world: Vec3::Y,
            steer_angle: 0.0,
            is_steered,
            is_driven,
            tire: Tire::new(0.31, grip_mult),
        }
    }
}

/// 4-wheel independent suspension system.
#[derive(Debug, Clone, PartialEq)]
pub struct SuspensionSystem {
    /// 4 wheels in order: [FL, FR, RL, RR].
    pub wheels: [SuspensionWheel; 4],
    /// Front anti-roll bar stiffness (N/m).
    pub anti_roll_front: f32,
    /// Rear anti-roll bar stiffness (N/m).
    pub anti_roll_rear: f32,
}

impl SuspensionSystem {
    /// Build suspension system from `SimCar` vehicle specification.
    pub fn from_sim(sim: &SimCar) -> Self {
        let wheelbase = sim.wheelbase_m.clamp(1.5, 3.5);
        let front_track = sim.front_track_m.clamp(1.0, 2.2);
        let rear_track = sim.rear_track_m.clamp(1.0, 2.2);

        // Weight distribution: rear-engine cars have ~60% rear weight
        let rear_weight_bias = 0.58;
        // The axle opposite a load carries that load's moment: a 58% rear
        // static bias puts the front axle 58% of the wheelbase ahead of COM.
        let z_front = -wheelbase * rear_weight_bias;
        let z_rear = wheelbase * (1.0 - rear_weight_bias);
        let x_front = front_track * 0.5;
        let x_rear = rear_track * 0.5;

        // Springs from .sim (scale ~1000 N/m)
        let spring_f = (sim.suspension_stiffness * 1200.0).clamp(18_000.0, 70_000.0);
        let spring_r = (sim.suspension_stiffness * 1400.0).clamp(20_000.0, 80_000.0);

        // Dampers from .sim (bump / rebound)
        let bump_f = (sim.damping_compression * 1000.0).clamp(1_200.0, 6_000.0);
        let rebound_f = (sim.damping_rebound * 1000.0).clamp(2_000.0, 9_000.0);
        let bump_r = (sim.damping_compression * 1100.0).clamp(1_400.0, 6_500.0);
        let rebound_r = (sim.damping_rebound * 1100.0).clamp(2_200.0, 9_500.0);

        let grip = if sim.tire_grip > 0.3 && sim.tire_grip < 3.0 {
            sim.tire_grip
        } else {
            (sim.tire_grip / 100.0).clamp(0.5, 2.0)
        };

        let fl = SuspensionWheel::new(
            Vec3::new(-x_front, 0.1, z_front),
            spring_f,
            bump_f,
            rebound_f,
            true,
            false,
            grip,
        );
        let fr = SuspensionWheel::new(
            Vec3::new(x_front, 0.1, z_front),
            spring_f,
            bump_f,
            rebound_f,
            true,
            false,
            grip,
        );
        let rl = SuspensionWheel::new(
            Vec3::new(-x_rear, 0.1, z_rear),
            spring_r,
            bump_r,
            rebound_r,
            false,
            true,
            grip,
        );
        let rr = SuspensionWheel::new(
            Vec3::new(x_rear, 0.1, z_rear),
            spring_r,
            bump_r,
            rebound_r,
            false,
            true,
            grip,
        );

        let arb = sim.swaybar_stiffness.clamp(2000.0, 40_000.0);

        Self {
            wheels: [fl, fr, rl, rr],
            anti_roll_front: arb * 0.8,
            anti_roll_rear: arb * 1.2,
        }
    }

    /// Set front wheel steering angle (radians, positive = steering right).
    pub fn set_steer_angle(&mut self, angle: f32) {
        self.wheels[WHEEL_FL].steer_angle = angle;
        self.wheels[WHEEL_FR].steer_angle = angle;
    }

    /// Update suspension raycasting against the road surface grid and apply suspension forces.
    pub fn update_surface_contact(
        &mut self,
        body: &mut RigidBody,
        surface: Option<&RoadSurface>,
        _dt: f32,
    ) {
        let up = body.up();

        // 1. Raycast each wheel against ground surface
        for wheel in &mut self.wheels {
            let mount_world = body.to_world_pos(wheel.hardpoint_body);
            let uncompressed_len = wheel.rest_length + wheel.tire.radius;

            // Query surface elevation and normal
            let ground = if let Some(surf) = surface {
                // Search only the suspension's reach. A missing road triangle is
                // not a hidden plane at y=0, nor permission to attach to another deck.
                if surf.uses_original_support() {
                    // Porsche.exe 0x499a70 selects by wheel XZ and evaluates
                    // its cached plane. Keep the existing force adapter's local
                    // spring-length conversion, explicitly separate from the
                    // unrecovered original suspension/alternate-height branch.
                    surf.original_support(mount_world.to_array(), &mut wheel.support_owner)
                        .and_then(|hit| {
                            let normal = Vec3::from_array(hit.normal);
                            let denominator = up.dot(normal);
                            (denominator > 0.01).then(|| {
                                (
                                    (mount_world.y - hit.height) * normal.y / denominator,
                                    normal,
                                )
                            })
                        })
                } else {
                    surf.suspension_ray(mount_world, up, uncompressed_len, 0.49)
                        .map(|(distance, hit)| (distance, Vec3::from_array(hit.normal)))
                }
            } else {
                // Explicit flat-ground fixture used by CPU calibration benches.
                (up.y > 0.01).then(|| (mount_world.y / up.y, Vec3::Y))
            };

            let Some((dist_to_ground, ground_normal)) = ground else {
                wheel.in_contact = false;
                wheel.compression = 0.0;
                wheel.compression_velocity = 0.0;
                wheel.contact_point_world = mount_world - up * uncompressed_len;
                wheel.ground_normal_world = Vec3::Y;
                continue;
            };

            let ground_pt = mount_world - up * dist_to_ground;

            let compression = (uncompressed_len - dist_to_ground).clamp(0.0, wheel.max_compression);

            if dist_to_ground < uncompressed_len && dist_to_ground > -0.5 {
                // Finite differences across a first/reacquired contact produce
                // compression/dt impulses even when the car is stationary.
                // Damping must oppose the actual closing velocity instead.
                let comp_vel = -body.point_velocity(mount_world).dot(ground_normal);

                wheel.in_contact = true;
                wheel.compression = compression;
                wheel.compression_velocity = comp_vel;
                wheel.contact_point_world = ground_pt;
                wheel.ground_normal_world = ground_normal;
            } else {
                wheel.in_contact = false;
                wheel.compression = 0.0;
                wheel.compression_velocity = 0.0;
                wheel.contact_point_world = mount_world - up * uncompressed_len;
                wheel.ground_normal_world = Vec3::Y;
            }
        }

        // 2. Anti-roll bar differential compression
        let arb_front_force = (self.wheels[WHEEL_FL].compression
            - self.wheels[WHEEL_FR].compression)
            * self.anti_roll_front;
        let arb_rear_force = (self.wheels[WHEEL_RL].compression
            - self.wheels[WHEEL_RR].compression)
            * self.anti_roll_rear;

        // 3. Compute and apply vertical normal forces to chassis
        for (i, wheel) in self.wheels.iter_mut().enumerate() {
            if !wheel.in_contact {
                wheel.tire.normal_load = 0.0;
                continue;
            }

            let arb_diff = match i {
                // More compression on the left must add upward support there
                // and remove it on the right, opposing rather than amplifying roll.
                WHEEL_FL => arb_front_force,
                WHEEL_FR => -arb_front_force,
                WHEEL_RL => arb_rear_force,
                WHEEL_RR => -arb_rear_force,
                _ => 0.0,
            };

            let spring_force = wheel.spring_k * wheel.compression;
            let damper_force = if wheel.compression_velocity > 0.0 {
                wheel.damper_bump * wheel.compression_velocity
            } else {
                wheel.damper_rebound * wheel.compression_velocity
            };

            let normal_force = (spring_force + damper_force + arb_diff).max(0.0);
            wheel.tire.normal_load = normal_force;

            // Apply normal force along ground normal at suspension mount
            let mount_world = body.to_world_pos(wheel.hardpoint_body);
            body.apply_force_at_world_pos(wheel.ground_normal_world * normal_force, mount_world);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn test_sim_356() -> SimCar {
        SimCar {
            name: "1956 356 A coupe 1.6L".to_string(),
            mass_kg: 850.0,
            wheelbase_m: 2.1,
            gear_count: 4,
            drive_flags: 2,
            reverse_gear: -3.6,
            forward_gears: vec![3.09, 1.765, 1.13, 0.852],
            final_drive: 4.428,
            redline_rpm: 5800.0,
            idle_or_step_rpm: 800.0,
            torque_curve: [
                51.0, 51.0, 59.0, 75.0, 75.0, 81.0, 80.0, 75.0, 75.0, 70.0, 50.0, 39.0, 34.0, 0.0,
                0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
            ],
            brake_bias: 0.6,
            drag_coeff: 0.38,
            swaybar_stiffness: 8000.0,
            suspension_stiffness: 22.0,
            front_track_m: 1.3,
            rear_track_m: 1.28,
            damping_compression: 2.0,
            damping_rebound: 2.8,
            tire_grip: 100.0,
            cg_offset_m: [0.0, 0.35, -0.05],
            raw: [0u8; 328],
        }
    }

    #[test]
    fn suspension_initializes_with_four_wheels() {
        let sim = test_sim_356();
        let susp = SuspensionSystem::from_sim(&sim);

        assert_eq!(susp.wheels.len(), 4);
        assert!(susp.wheels[WHEEL_FL].is_steered);
        assert!(susp.wheels[WHEEL_FR].is_steered);
        assert!(!susp.wheels[WHEEL_RL].is_steered);
        assert!(!susp.wheels[WHEEL_RR].is_steered);

        assert!(susp.wheels[WHEEL_RL].is_driven);
        assert!(susp.wheels[WHEEL_RR].is_driven);
        let front_arm = -susp.wheels[WHEEL_FL].hardpoint_body.z;
        let rear_arm = susp.wheels[WHEEL_RL].hardpoint_body.z;
        assert!(
            front_arm > rear_arm,
            "rear-biased mass needs a longer front axle arm"
        );
        assert!(((front_arm / (front_arm + rear_arm)) - 0.58).abs() < 1e-5);
    }

    #[test]
    fn tilted_suspension_uses_ray_distance_and_rejects_inverted_contact() {
        let sim = test_sim_356();
        let mut susp = SuspensionSystem::from_sim(&sim);
        for wheel in &mut susp.wheels {
            wheel.hardpoint_body = Vec3::ZERO;
        }
        let mut body = RigidBody::new(sim.mass_kg, 1.6, 1.3, 4.0, Vec3::ZERO);
        body.position = Vec3::new(0.0, 0.4, 0.0);
        body.orientation = glam::Quat::from_rotation_z(std::f32::consts::FRAC_PI_4);
        susp.update_surface_contact(&mut body, None, 1.0 / 240.0);
        for wheel in &susp.wheels {
            let reach = wheel.rest_length + wheel.tire.radius;
            let expected_length = 0.4 / body.up().y;
            assert!(wheel.in_contact);
            assert!(
                (wheel.compression - (reach - expected_length)).abs() < 1e-5,
                "compression must use ray/plane distance, not projection"
            );
            assert!(
                (wheel.contact_point_world - (body.position - body.up() * expected_length))
                    .length()
                    < 1e-5
            );
        }
        body.orientation = glam::Quat::from_rotation_z(std::f32::consts::PI);
        susp.update_surface_contact(&mut body, None, 1.0 / 240.0);
        assert!(susp
            .wheels
            .iter()
            .all(|w| !w.in_contact && w.tire.normal_load == 0.0));
    }

    #[test]
    fn anti_roll_bar_opposes_body_roll_without_adding_heave() {
        let sim = test_sim_356();
        for roll in [-0.035, 0.035] {
            let mut body = RigidBody::new(sim.mass_kg, 1.6, 1.3, 4.0, Vec3::ZERO);
            body.position = Vec3::new(0.0, 0.45, 0.0);
            body.orientation = glam::Quat::from_rotation_z(roll);
            let mut baseline = body.clone();
            let mut springs = SuspensionSystem::from_sim(&sim);
            springs.anti_roll_front = 0.0;
            springs.anti_roll_rear = 0.0;
            springs.update_surface_contact(&mut baseline, None, 1.0 / 240.0);
            let mut with_bar = SuspensionSystem::from_sim(&sim);
            with_bar.update_surface_contact(&mut body, None, 1.0 / 240.0);
            assert!(with_bar
                .wheels
                .iter()
                .all(|w| w.in_contact && w.tire.normal_load > 0.0));
            let bar_torque = body.accum_torque.z - baseline.accum_torque.z;
            assert!(
                bar_torque * roll < 0.0,
                "bar must restore roll {roll}, but adds torque {bar_torque}"
            );
            assert!(
                (body.accum_force.y - baseline.accum_force.y).abs() < 0.01,
                "bar transfers load between wheels, not total axle support"
            );
        }
    }

    #[test]
    fn ground_contact_compresses_suspension() {
        let sim = test_sim_356();
        let mut susp = SuspensionSystem::from_sim(&sim);
        let mut body = RigidBody::new(sim.mass_kg, 1.6, 1.3, 4.0, Vec3::ZERO);

        // Position car chassis so suspension is partially compressed
        body.position = Vec3::new(0.0, 0.45, 0.0);

        susp.update_surface_contact(&mut body, None, 1.0 / 240.0);

        for w in &susp.wheels {
            assert!(w.in_contact);
            assert!(w.compression > 0.0);
            assert!(w.tire.normal_load > 0.0);
        }
    }
}
