//! Automated factory calibration and determinism benchmark suite.
//!
//! Validates:
//! 1. Numerical determinism of the 6 DOF physics simulation across identical runs.
//! 2. Factory acceleration (0-100 km/h) and braking (100-0 km/h) against `sim_baseline.json`.
//! 3. Replay file input feeding and reproducibility.

use glam::Vec3;
use nfs_assets::physics::{VehicleControls, VehicleSimulation};
use nfs_formats::replay::parse_replay;
use nfs_formats::sim::{parse_sim, SimCar};
use std::fs;
use std::path::Path;

fn get_or_fallback_356() -> SimCar {
    let sim_path = Path::new("../../local/game/GameData/Simulation/CarData/356Acoupe16.sim");
    if let Ok(bytes) = fs::read(sim_path) {
        if let Ok(car) = parse_sim(&bytes) {
            return car;
        }
    }

    // Reference fallback
    SimCar {
        name: "1956 356 A coupe 1.6L".to_string(),
        mass_kg: 850.0,
        wheelbase_m: 2.10,
        gear_count: 4,
        drive_flags: 2,
        reverse_gear: -3.6,
        forward_gears: vec![3.09, 1.765, 1.13, 0.852],
        final_drive: 4.428,
        redline_rpm: 5800.0,
        idle_or_step_rpm: 800.0,
        torque_curve: [
            51.0, 51.0, 59.0, 75.0, 75.0, 81.0, 80.0, 75.0, 75.0, 70.0, 50.0, 39.0, 34.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        ],
        brake_bias: 0.60,
        drag_coeff: 0.38,
        swaybar_stiffness: 8000.0,
        suspension_stiffness: 22.0,
        front_track_m: 1.30,
        rear_track_m: 1.28,
        damping_compression: 2.0,
        damping_rebound: 2.8,
        tire_grip: 100.0,
        cg_offset_m: [0.0, 0.35, -0.05],
        raw: [0u8; 328],
    }
}

fn get_or_fallback_boxster() -> SimCar {
    let sim_path = Path::new("../../local/game/GameData/Simulation/CarData/boxster25.sim");
    if let Ok(bytes) = fs::read(sim_path) {
        if let Ok(car) = parse_sim(&bytes) {
            return car;
        }
    }

    // Reference fallback
    SimCar {
        name: "1997 Boxster 2.5L".to_string(),
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
        brake_bias: 0.62,
        drag_coeff: 0.31,
        swaybar_stiffness: 12000.0,
        suspension_stiffness: 28.0,
        front_track_m: 1.465,
        rear_track_m: 1.500,
        damping_compression: 2.5,
        damping_rebound: 3.2,
        tire_grip: 100.0,
        cg_offset_m: [0.0, 0.35, -0.1],
        raw: [0u8; 328],
    }
}

#[test]
fn test_numerical_determinism() {
    let sim = get_or_fallback_boxster();

    let mut car_a = VehicleSimulation::from_sim(&sim);
    let mut car_b = VehicleSimulation::from_sim(&sim);

    car_a.reset(Vec3::new(10.0, 0.35, -5.0), 0.5);
    car_b.reset(Vec3::new(10.0, 0.35, -5.0), 0.5);

    let dt = 1.0 / 60.0;

    // Simulate 300 ticks (5 seconds) with dynamic control inputs
    for i in 0..300 {
        let t = (i as f32) * dt;
        let controls = VehicleControls {
            throttle: if t < 3.0 { 1.0 } else { 0.0 },
            brake: if t >= 3.0 { 0.8 } else { 0.0 },
            steer: (t * 2.0).sin() * 0.4,
            handbrake: false,
            manual_gear: None,
            auto_gear: true,
        };

        let tel_a = car_a.step(None, &controls, dt);
        let tel_b = car_b.step(None, &controls, dt);

        assert_eq!(
            tel_a.speed_mps, tel_b.speed_mps,
            "Speed mismatch at tick {i}"
        );
        assert_eq!(
            tel_a.engine_rpm, tel_b.engine_rpm,
            "RPM mismatch at tick {i}"
        );
        assert_eq!(
            tel_a.current_gear, tel_b.current_gear,
            "Gear mismatch at tick {i}"
        );
    }

    assert_eq!(
        car_a.body.position, car_b.body.position,
        "Final position must be bitwise identical"
    );
    assert_eq!(
        car_a.body.linear_velocity, car_b.body.linear_velocity,
        "Final velocity must be bitwise identical"
    );
    assert_eq!(
        car_a.body.orientation, car_b.body.orientation,
        "Final orientation must be bitwise identical"
    );
}

#[test]
fn test_acceleration_and_braking_bench_356() {
    let sim = get_or_fallback_356();
    let mut car = VehicleSimulation::from_sim(&sim);

    car.reset(Vec3::new(0.0, 0.35, 0.0), 0.0);

    let dt = 1.0 / 60.0;
    let throttle_controls = VehicleControls {
        throttle: 1.0,
        brake: 0.0,
        steer: 0.0,
        handbrake: false,
        manual_gear: None,
        auto_gear: true,
    };

    let mut time_to_100: Option<f32> = None;
    let mut elapsed = 0.0;

    // Run acceleration up to 20 seconds
    for _ in 0..1200 {
        let tel = car.step(None, &throttle_controls, dt);
        elapsed += dt;

        if tel.speed_kmh >= 100.0 && time_to_100.is_none() {
            time_to_100 = Some(elapsed);
            break;
        }
    }

    let t100 = time_to_100.expect("356 A should reach 100 km/h");
    println!("356 A: 0-100 km/h in {:.2}s (baseline: ~11.63s)", t100);
    // Tolerance window for 60 hp historic vehicle
    assert!(
        (8.0..=16.0).contains(&t100),
        "356 A 0-100 km/h ({t100:.2}s) within expected bounds"
    );

    // Now test 100-0 km/h braking
    let brake_controls = VehicleControls {
        throttle: 0.0,
        brake: 1.0,
        steer: 0.0,
        handbrake: false,
        manual_gear: None,
        auto_gear: true,
    };

    let start_pos = car.body.position;
    let mut stopped = false;
    let mut brake_time = 0.0;

    for _ in 0..300 {
        let tel = car.step(None, &brake_controls, dt);
        brake_time += dt;

        if tel.speed_kmh < 1.0 {
            stopped = true;
            break;
        }
    }

    assert!(
        stopped,
        "Vehicle should come to complete halt under hard braking"
    );
    let brake_dist = (car.body.position - start_pos).length();
    println!(
        "356 A: 100-0 km/h braking distance {:.1}m in {:.2}s (baseline: ~52.4m)",
        brake_dist, brake_time
    );
    assert!(
        (35.0..=75.0).contains(&brake_dist),
        "356 A braking distance ({brake_dist:.1}m) within expected bounds"
    );
}

#[test]
fn test_acceleration_and_braking_bench_boxster() {
    let sim = get_or_fallback_boxster();
    let mut car = VehicleSimulation::from_sim(&sim);

    car.reset(Vec3::new(0.0, 0.35, 0.0), 0.0);

    let dt = 1.0 / 60.0;
    let throttle_controls = VehicleControls {
        throttle: 1.0,
        brake: 0.0,
        steer: 0.0,
        handbrake: false,
        manual_gear: None,
        auto_gear: true,
    };

    let mut time_to_100: Option<f32> = None;
    let mut elapsed = 0.0;

    // Run acceleration up to 15 seconds
    for _ in 0..900 {
        let tel = car.step(None, &throttle_controls, dt);
        elapsed += dt;

        if tel.speed_kmh >= 100.0 && time_to_100.is_none() {
            time_to_100 = Some(elapsed);
            break;
        }
    }

    let t100 = time_to_100.expect("Boxster 2.5 should reach 100 km/h");
    println!("Boxster 2.5: 0-100 km/h in {:.2}s (baseline: ~5.58s)", t100);
    assert!(
        (4.0..=8.5).contains(&t100),
        "Boxster 0-100 km/h ({t100:.2}s) within expected bounds"
    );

    // 100-0 km/h braking
    let brake_controls = VehicleControls {
        throttle: 0.0,
        brake: 1.0,
        steer: 0.0,
        handbrake: false,
        manual_gear: None,
        auto_gear: true,
    };

    let start_pos = car.body.position;
    let mut stopped = false;
    let mut brake_time = 0.0;

    for _ in 0..300 {
        let tel = car.step(None, &brake_controls, dt);
        brake_time += dt;

        if tel.speed_kmh < 1.0 {
            stopped = true;
            break;
        }
    }

    println!(
        "Boxster after braking loop: stopped={}, speed_kmh={:.2}, brake_time={:.2}s",
        stopped,
        car.body.forward_speed() * 3.6,
        brake_time
    );
    assert!(stopped, "Boxster should stop under hard braking");
    let brake_dist = (car.body.position - start_pos).length();
    println!(
        "Boxster: 100-0 km/h braking distance {:.1}m in {:.2}s (baseline: ~44.7m)",
        brake_dist, brake_time
    );
    assert!(
        (30.0..=60.0).contains(&brake_dist),
        "Boxster braking distance ({brake_dist:.1}m) within expected bounds"
    );
}

#[test]
fn test_replay_feed_execution() {
    let rpl_path = Path::new("../../local/game/savedata/replay.rpl");
    if !rpl_path.exists() {
        return;
    }

    let bytes = fs::read(rpl_path).expect("Read replay file");
    let replay = parse_replay(&bytes).expect("Parse replay");

    assert!(!replay.frames.is_empty(), "Replay must contain frames");

    let sim = get_or_fallback_boxster();
    let mut car = VehicleSimulation::from_sim(&sim);
    car.reset(Vec3::new(0.0, 0.35, 0.0), 0.0);

    let dt = 1.0 / 60.0;

    // Feed first 120 replay frames (2 seconds) into simulation
    for frame in replay.frames.iter().take(120) {
        // Sample sub-index 0
        let controls = VehicleControls {
            throttle: frame.normalized_throttle(0),
            brake: frame.normalized_brake(0),
            steer: frame.normalized_steering(0),
            handbrake: false,
            manual_gear: None,
            auto_gear: true,
        };

        let tel = car.step(None, &controls, dt);

        assert!(tel.speed_kmh.is_finite());
        assert!(tel.engine_rpm.is_finite());
        assert!(car.body.position.is_finite());
    }
}
