use glam::Vec3;
use nfs_assets::physics::original_support::{SupportPolygon, SupportVertices};
use nfs_assets::physics::original_support_loader::{AssembledSupport, SupportLoad};
use nfs_assets::physics::original_support_owner::OriginalSupportOwner;
use nfs_assets::physics::{RigidBody, SuspensionSystem};
use nfs_assets::RoadSurface;

fn surface() -> RoadSurface {
    // Opposite original/scene Z, two stacked source quads, different flags.
    let polygons = [(0.0, 1), (8.0, 1), (16.0, 0)]
        .into_iter()
        .enumerate()
        .map(|(i, (y, flags))| AssembledSupport {
            polygon: SupportPolygon::new(
                SupportVertices::Quad([
                    [-4.0, y, 20.0],
                    [4.0, y, 20.0],
                    [4.0, y, 28.0],
                    [-4.0, y, 28.0],
                ]),
                flags,
            ),
            colors: vec![0; 4],
            article_index: 0,
            primitive_index: i as u16,
            polygon_index: 0,
        })
        .collect();
    RoadSurface::from_original_support(
        SupportLoad {
            polygons,
            ..Default::default()
        },
        &["NON_RD".into()],
    )
    .unwrap()
}

#[test]
fn scene_reflection_flags_and_per_wheel_polygon_cache_are_live() {
    let surface = surface();
    assert!(surface.uses_original_support());
    assert!(surface.original_support_counts().unwrap().0 == 3);
    // No RD name gate; flags exclude the highest polygon.
    assert_eq!(
        surface
            .query(0.0, -24.0, 16.0, 100.0, 100.0)
            .unwrap()
            .height,
        8.0
    );
    assert!(surface.query(0.0, 24.0, 0.0, 100.0, 100.0).is_none());
    let mut owner = OriginalSupportOwner::default();
    let low = surface
        .original_support([0.0, 0.0, -24.0], &mut owner)
        .unwrap();
    assert_eq!(low.height, 0.0);
    // The original cached polygon is retained while XZ containment holds,
    // even when another deck is now closer to the query's Y.
    assert_eq!(
        surface
            .original_support([0.0, 8.0, -24.0], &mut owner)
            .unwrap()
            .height,
        0.0
    );
    assert_eq!(
        surface
            .original_support([0.0, 8.0, -24.0], &mut OriginalSupportOwner::default())
            .unwrap()
            .height,
        8.0
    );
}

#[test]
fn existing_force_adapter_uses_original_selection_without_grid_fallback() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../../../../local/game/GameData/Simulation/CarData");
    // Same optional original SIM policy as other live-model tests.
    let file = root.join("boxster25.sim");
    let Ok(bytes) = std::fs::read(file) else {
        return;
    };
    let sim = nfs_formats::parse_sim(&bytes).unwrap();
    let mut suspension = SuspensionSystem::from_sim(&sim);
    for wheel in &mut suspension.wheels {
        wheel.hardpoint_body = Vec3::ZERO;
    }
    let mut body = RigidBody::new(sim.mass_kg, 1.8, 1.3, 4.2, Vec3::ZERO);
    body.position = Vec3::new(0.0, 0.5, -24.0);
    let surface = surface();
    suspension.update_surface_contact(&mut body, Some(&surface), 1.0 / 240.0);
    assert!(suspension
        .wheels
        .iter()
        .all(|wheel| wheel.support_owner.polygon == Some(0) && wheel.in_contact));
    body.position.z = 24.0;
    suspension.update_surface_contact(&mut body, Some(&surface), 1.0 / 240.0);
    assert!(suspension
        .wheels
        .iter()
        .all(|wheel| wheel.support_owner.polygon.is_none() && !wheel.in_contact));
}
