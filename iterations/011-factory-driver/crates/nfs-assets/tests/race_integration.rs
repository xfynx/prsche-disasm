use nfs_assets::{
    calculate_grid_slot, AiOpponent, AiProfile, BarrierCollider, BarrierCollisionConfig,
    CourseProgressTracker, RacePhase, RaceSession, TrackCourse,
};
use nfs_formats::topology::SplinePoint;

#[test]
fn test_end_to_end_race_session_lifecycle() {
    // 1. Build a synthetic circular race track with 16 waypoints
    let radius = 100.0;
    let n_pts = 16;
    let mut spline_pts = Vec::new();
    for i in 0..n_pts {
        let theta = (i as f32 / n_pts as f32) * std::f32::consts::TAU;
        spline_pts.push(SplinePoint {
            x: theta.cos() * radius,
            z: theta.sin() * radius,
        });
    }

    let course = TrackCourse::from_spline_points(&spline_pts, true, |_, _| 0.0)
        .expect("Track course generation failed");
    assert!(course.is_circuit);
    assert_eq!(course.checkpoints.len(), 4);

    // 2. Initialize race session: 2 laps, 4 racers
    let total_laps = 2;
    let mut session = RaceSession::new("test_circuit", total_laps, false);

    // Add Player (slot 0)
    session.add_participant(0, "Player", true, "911 Carrera");

    // Add 3 AI Opponents
    let mut ai_opponents = Vec::new();
    let profiles = [
        ("Pro", AiProfile::pro()),
        ("Veteran", AiProfile::veteran()),
        ("Rookie", AiProfile::novice()),
    ];
    for (i, (name, profile)) in profiles.into_iter().enumerate() {
        let slot = i + 1;
        let ai = AiOpponent::new(slot, name, "911 Carrera", profile, slot, &course);
        session.add_participant(slot, name, false, "911 Carrera");
        ai_opponents.push(ai);
    }
    assert_eq!(session.participants.len(), 4);

    // Player trackers and position
    let (p0_pos, _, _) = calculate_grid_slot(0, &course);
    let mut player_pos = p0_pos;
    let mut player_tracker = CourseProgressTracker::new(player_pos);
    let mut player_theta = 0.0_f32;

    // 3. Verify Countdown Phase
    assert!(matches!(session.phase, RacePhase::Countdown { .. }));
    let mut dt = 0.5;
    for _ in 0..6 {
        session.step(dt);
    }
    // Countdown was 3.0s, after 6 * 0.5s = 3.0s it should transition to Racing
    assert!(session.phase.is_racing());

    // 4. Run race loop simulation until player finishes
    let mut steps = 0;
    dt = 0.1;
    let barrier_config = BarrierCollisionConfig::default();

    while steps < 2000 {
        steps += 1;
        session.step(dt);

        // Advance AI opponents along course
        for ai in &mut ai_opponents {
            ai.step_kinematics(dt, &course, |_, _| 0.0);
            let res = ai.tracker.update(ai.position, ai.forward, &course, dt);
            if let Some(true) = res {
                ai.laps_completed += 1;
            }
            let (_, dist_along) = course.find_closest_waypoint(ai.position);
            ai.distance_along_course = dist_along;
        }

        // Simulate Player driving cleanly along track at 45 m/s (~162 km/h)
        player_theta += 45.0 * dt / radius;
        player_pos = [
            player_theta.cos() * radius,
            0.0,
            -player_theta.sin() * radius,
        ];
        let fwd = [-player_theta.sin(), 0.0, -player_theta.cos()];

        // Verify barrier resolution
        let mut sim_vel = [0.0, 0.0, 0.0];
        BarrierCollider::resolve_collision(&mut player_pos, &mut sim_vel, &[], &barrier_config);

        let (_, dist_along) = course.find_closest_waypoint(player_pos);
        let lap_completed = player_tracker.update(player_pos, fwd, &course, dt);

        assert!(
            !player_tracker.is_wrong_way,
            "Forward driving should not trigger wrong way"
        );

        if let Some(true) = lap_completed {
            session.on_player_lap_completed();
        }

        // Sync standings
        for p in &mut session.participants {
            if p.is_player {
                p.distance_along_track = dist_along;
            } else if let Some(ai) = ai_opponents.iter().find(|a| a.id == p.id) {
                p.distance_along_track = ai.distance_along_course;
                p.laps_completed = ai.laps_completed;
            }
        }
        session.update_standings();

        if session.phase.is_finished() {
            break;
        }
    }

    // 5. Verify Race Completion & Standings
    assert!(session.phase.is_finished());
    assert_eq!(
        session.lap_tracker.completed_laps.len(),
        total_laps as usize
    );
    assert!(session.lap_tracker.best_lap_time.is_some());
    assert!(session.lap_tracker.best_lap_time.unwrap() > 0.0);

    // Verify standings
    assert_eq!(session.participants.len(), 4);
    assert_eq!(session.participants[0].current_position, 1);
    assert_eq!(session.participants[1].current_position, 2);
    assert_eq!(session.participants[2].current_position, 3);
    assert_eq!(session.participants[3].current_position, 4);

    // Step 4.0s to pass cooldown and enter Results screen
    for _ in 0..8 {
        session.step(0.5);
    }
    assert_eq!(session.phase, RacePhase::Results);

    // 6. Verify Race Restart
    session.restart(3.0);
    assert!(matches!(
        session.phase,
        RacePhase::Countdown {
            remaining_secs: 3.0,
            ..
        }
    ));
    assert_eq!(session.lap_tracker.current_lap, 1);
    assert_eq!(session.lap_tracker.completed_laps.len(), 0);
}
