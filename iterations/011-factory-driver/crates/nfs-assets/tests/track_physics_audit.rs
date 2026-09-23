use nfs_assets::{
    calculate_grid_slot, load_track, AiOpponent, AiProfile, AssetFiles, BarrierCollider,
    BarrierCollisionConfig, TopologyEdge,
};
use std::path::Path;

const TRACK_NAMES: [&str; 15] = [
    "alps",
    "autobahn",
    "canyon",
    "castle",
    "coastal",
    "farmland",
    "foothills",
    "forest",
    "industrial",
    "monaco1",
    "monaco2",
    "monaco3",
    "monaco4",
    "monaco5",
    "skidpad",
];

fn get_track_dir() -> Option<std::path::PathBuf> {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../../local/game/GameData/Track");
    if root.exists() {
        Some(root)
    } else {
        None
    }
}

fn load_track_assets(track_dir: &Path, track_name: &str) -> Option<AssetFiles> {
    let crp_path = track_dir.join(format!("{track_name}.crp"));
    let fsh_path = track_dir.join(format!("{track_name}.fsh"));
    if !crp_path.exists() || !fsh_path.exists() {
        return None;
    }

    let mut files = AssetFiles::new();
    files.insert(format!("{track_name}.crp"), std::fs::read(&crp_path).ok()?);
    files.insert(format!("{track_name}.fsh"), std::fs::read(&fsh_path).ok()?);

    let edg_path = track_dir.join(format!("{track_name}.edg"));
    if edg_path.exists() {
        if let Ok(d) = std::fs::read(&edg_path) {
            files.insert(format!("{track_name}.edg"), d);
        }
    }

    let jnc_path = track_dir.join(format!("{track_name}.jnc"));
    if jnc_path.exists() {
        if let Ok(d) = std::fs::read(&jnc_path) {
            files.insert(format!("{track_name}.jnc"), d);
        }
    }

    let map_path = track_dir.join(format!("{track_name}.map"));
    if map_path.exists() {
        if let Ok(d) = std::fs::read(&map_path) {
            files.insert(format!("{track_name}.map"), d);
        }
    }

    // Try finding LSP in racer/work/<track>0.lsp or <track>0.lsp
    let lsp0_work = track_dir.join(format!("racer/work/{track_name}0.lsp"));
    let lsp0_bare = track_dir.join(format!("{track_name}0.lsp"));
    let lsp_bare = track_dir.join(format!("{track_name}.lsp"));

    if lsp0_work.exists() {
        if let Ok(d) = std::fs::read(&lsp0_work) {
            files.insert(format!("{track_name}0.lsp"), d);
        }
    } else if lsp0_bare.exists() {
        if let Ok(d) = std::fs::read(&lsp0_bare) {
            files.insert(format!("{track_name}0.lsp"), d);
        }
    } else if lsp_bare.exists() {
        if let Ok(d) = std::fs::read(&lsp_bare) {
            files.insert(format!("{track_name}.lsp"), d);
        }
    }

    Some(files)
}

#[test]
fn test_all_15_tracks_complete_physics_and_collision_audit() {
    let track_dir = match get_track_dir() {
        Some(d) => d,
        None => {
            println!("Skipping track audit: local/game assets not available");
            return;
        }
    };

    println!("\n========================================================");
    println!("     NFS: PORSCHE UNLEASHED - 15 TRACK PHYSICS AUDIT     ");
    println!("========================================================");

    let mut audited_count = 0;

    for &track_name in &TRACK_NAMES {
        let files = match load_track_assets(&track_dir, track_name) {
            Some(f) => f,
            None => {
                panic!("Missing required assets for track: {track_name}");
            }
        };

        // 1. Load Track Scene
        let scene = load_track(&files, track_name)
            .unwrap_or_else(|e| panic!("Failed to load scene for track {track_name}: {e}"));

        // Verify scene geometry bounds
        assert!(
            scene.bounds[0][0] < scene.bounds[1][0],
            "Track {track_name} has invalid X bounds"
        );
        assert!(
            scene.bounds[0][2] < scene.bounds[1][2],
            "Track {track_name} has invalid Z bounds"
        );

        // Verify RoadSurface
        assert!(
            scene.road_surface.is_some(),
            "Track {track_name} missing road surface"
        );
        let surface = scene.road_surface.as_ref().unwrap();
        assert!(
            surface.triangle_count() > 0,
            "Track {track_name} has 0 road surface triangles"
        );
        let report = surface.report();
        assert!(
            report.accepted > 0,
            "Track {track_name} accepted 0 road surface triangles"
        );

        // Verify Topology & Barriers
        assert!(
            scene.topology.is_some(),
            "Track {track_name} missing topology"
        );
        let topology = scene.topology.as_ref().unwrap();
        assert!(
            !topology.edges.is_empty(),
            "Track {track_name} has 0 topology boundary edges"
        );

        // Verify Course & Waypoints
        assert!(
            scene.course.is_some(),
            "Track {track_name} missing course spline"
        );
        let course = scene.course.as_ref().unwrap();
        assert!(
            course.waypoints.len() >= 10,
            "Track {track_name} has insufficient waypoints: {}",
            course.waypoints.len()
        );
        assert!(
            !course.checkpoints.is_empty(),
            "Track {track_name} has 0 checkpoints"
        );
        assert!(
            course.total_length > 100.0,
            "Track {track_name} total length is implausibly short: {:.1}m",
            course.total_length
        );

        // 2. Road Surface Continuity & Hole Audit Along Course Spline
        let mut holes_found = 0;
        let mut sampled_points = 0;
        let mut prev_hit: Option<([f32; 2], f32)> = None;
        let mut multi_level_steps = 0;
        let mut max_vertical_step = 0.0_f32;
        let mut max_grade = 0.0_f32;

        for wp in &course.waypoints {
            sampled_points += 1;
            let query_hit =
                surface.query(wp.position[0], wp.position[2], wp.position[1], 15.0, 15.0);
            if let Some(hit) = query_hit {
                let curr_xz = [wp.position[0], wp.position[2]];
                if let Some((prev_xz, prev_y)) = prev_hit {
                    let dx = curr_xz[0] - prev_xz[0];
                    let dz = curr_xz[1] - prev_xz[1];
                    let dist = (dx * dx + dz * dz).sqrt();
                    let diff = (hit.height - prev_y).abs();
                    if diff > max_vertical_step {
                        max_vertical_step = diff;
                    }
                    if dist > 0.1 {
                        let grade = diff / dist;
                        if grade > max_grade {
                            max_grade = grade;
                        }
                        if grade > 1.0 {
                            // Layered multi-level flyover / bridge overpass in track geometry
                            multi_level_steps += 1;
                        }
                    }
                }
                prev_hit = Some((curr_xz, hit.height));
            } else {
                holes_found += 1;
                prev_hit = None; // Reset across gaps/bridges/tunnels
            }
        }

        let coverage_pct = 100.0 * (sampled_points - holes_found) as f32 / sampled_points as f32;
        assert!(
            coverage_pct >= 70.0,
            "Track {track_name} has insufficient road surface coverage: {:.1}%",
            coverage_pct
        );

        // 3. Barrier Containment & Boundary Enclosure Audit
        let barrier_config = BarrierCollisionConfig::default();
        let barrier_edges: Vec<TopologyEdge> = topology
            .edges
            .iter()
            .filter(|e| (e.flags & 0x10) != 0 || e.flags == 0)
            .cloned()
            .collect();

        assert!(
            !barrier_edges.is_empty(),
            "Track {track_name} has no candidate barrier edges"
        );

        // Test collision response on sampled barrier edges at high impact speed (60 m/s ~ 216 km/h)
        let sample_edge = &barrier_edges[0];
        let mid = [
            (sample_edge.p1[0] + sample_edge.p2[0]) * 0.5,
            (sample_edge.p1[1] + sample_edge.p2[1]) * 0.5,
            (sample_edge.p1[2] + sample_edge.p2[2]) * 0.5,
        ];
        let edge_dir = [
            sample_edge.p2[0] - sample_edge.p1[0],
            sample_edge.p2[2] - sample_edge.p1[2],
        ];
        let edge_len = (edge_dir[0] * edge_dir[0] + edge_dir[1] * edge_dir[1])
            .sqrt()
            .max(1.0);
        let normal = [-edge_dir[1] / edge_len, edge_dir[0] / edge_len];

        // Vehicle starting just inside barrier and moving directly into it
        let mut test_pos = [mid[0] + normal[0] * 0.5, mid[1], mid[2] + normal[1] * 0.5];
        let mut test_vel = [-normal[0] * 50.0, 0.0, -normal[1] * 50.0];

        let collided = BarrierCollider::resolve_collision(
            &mut test_pos,
            &mut test_vel,
            std::slice::from_ref(sample_edge),
            &barrier_config,
        );
        assert!(
            collided,
            "Track {track_name}: Barrier did not register high-speed impact"
        );
        // Outward penetration must be resolved
        let outward_vel = test_vel[0] * normal[0] + test_vel[2] * normal[1];
        assert!(
            outward_vel > -1.0,
            "Track {track_name}: Vehicle tunneled through barrier with negative normal velocity: {:.2}",
            outward_vel
        );

        // 4. Dynamic Vehicle Kinematics Run on Track
        let (grid_pos, _, grid_yaw) = calculate_grid_slot(0, course);
        let profile = AiProfile::veteran();
        let mut ai_car = AiOpponent::new(0, "AuditRacer", "Porsche 911", profile, 0, course);
        ai_car.position = grid_pos;
        ai_car.yaw = grid_yaw;

        let dt = 0.05;
        let total_steps = 300; // 15 seconds of active driving simulation
        let elevation_sampler = |x: f32, z: f32| -> f32 {
            surface
                .query(x, z, 0.0, 100.0, 100.0)
                .map(|h| h.height)
                .unwrap_or(0.0)
        };

        for _ in 0..total_steps {
            ai_car.step_kinematics(dt, course, elevation_sampler);

            // Barrier resolution during driving
            BarrierCollider::resolve_collision(
                &mut ai_car.position,
                &mut ai_car.velocity,
                &barrier_edges[..barrier_edges.len().min(128)],
                &barrier_config,
            );

            let (_, dist_along) = course.find_closest_waypoint(ai_car.position);
            ai_car.distance_along_course = dist_along;
            ai_car
                .tracker
                .update(ai_car.position, ai_car.forward, course, dt);

            // Check non-degeneracy
            assert!(
                ai_car.position[0].is_finite()
                    && ai_car.position[1].is_finite()
                    && ai_car.position[2].is_finite(),
                "Track {track_name}: Vehicle coordinates became non-finite during driving"
            );
            assert!(
                ai_car.current_speed.is_finite() && ai_car.current_speed >= 0.0,
                "Track {track_name}: Speed became non-finite or negative"
            );
        }

        // Verify that the car successfully accelerated and progressed along the course
        assert!(
            ai_car.current_speed > 10.0,
            "Track {track_name}: Vehicle did not accelerate (speed = {:.1} m/s)",
            ai_car.current_speed
        );
        assert!(
            ai_car.distance_along_course > 50.0,
            "Track {track_name}: Vehicle did not progress along course (distance = {:.1}m)",
            ai_car.distance_along_course
        );

        println!(
            "[OK] {:11} | Len: {:6.1}m | Type: {:7} | WPs: {:4} | RD Tris: {:5} | EDG: {:5} | Coverage: {:5.1}% | MultiLvl: {:2} | CarSpeed: {:5.1} km/h",
            track_name,
            course.total_length,
            if course.is_circuit { "Circuit" } else { "Sprint" },
            course.waypoints.len(),
            surface.triangle_count(),
            topology.edges.len(),
            coverage_pct,
            multi_level_steps,
            ai_car.current_speed * 3.6,
        );

        audited_count += 1;
    }

    assert_eq!(
        audited_count, 15,
        "Expected to audit all 15 tracks, audited: {audited_count}"
    );
    println!("========================================================");
    println!("ALL 15 TRACKS PASSED PHYSICS, SURFACE & BARRIER AUDIT!");
    println!("========================================================\n");
}
