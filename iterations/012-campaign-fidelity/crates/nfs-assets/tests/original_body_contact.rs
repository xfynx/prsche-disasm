use nfs_assets::physics::{
    original_body_contact::{first_body_contact, BodyContactInput},
    original_scene_objects::{EdgeObject, SceneObject},
    original_support::{SupportPolygon, SupportVertices},
    original_support_owner::OriginalSupportOwner,
    original_support_tree::{SceneRef, SupportTree},
};

fn vector(text: &str) -> [f32; 3] {
    text.split(',')
        .map(|v| v.parse().unwrap())
        .collect::<Vec<_>>()
        .try_into()
        .unwrap()
}

#[test]
fn original_first_contact_and_no_hit_cases() {
    let polygon = SupportPolygon::new(
        SupportVertices::Quad([
            [0., 0., -10.],
            [0., 0., 10.],
            [10., 0., 10.],
            [10., 0., -10.],
        ]),
        1,
    );
    let polygons = vec![polygon];
    let objects: Vec<_> = [0., 10.]
        .into_iter()
        .enumerate()
        .map(|(i, y)| {
            SceneObject::Edge(EdgeObject::from_source(
                10 + i as u16,
                [[0., y, -5.], [0., y, 5.]],
                i,
            ))
        })
        .collect();
    let mut tree = SupportTree::original_scene();
    tree.insert_scene(&polygons, &objects, SceneRef::Polygon(0))
        .unwrap();
    for i in 0..objects.len() {
        tree.insert_scene(&polygons, &objects, SceneRef::Object(i))
            .unwrap();
    }
    let fixtures =
        include_str!("../../../runs/019-original-contact-runtime/body-selection-fixtures.tsv");
    let mut count = 0;
    for line in fixtures.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let input = BodyContactInput {
            position_330: vector(c[1]),
            velocity_33c: vector(c[2]),
            basis_364: [1., 0., 0.],
            basis_370: [0., 1., 0.],
            basis_37c: [0., 0., 1.],
            extents_3a8: [c[3].parse().unwrap(), 0.75, 2.],
        };
        let result = first_body_contact(
            input,
            &OriginalSupportOwner::default(),
            &tree,
            &polygons,
            &objects,
        )
        .unwrap();
        if c[4] == "-" {
            assert!(result.is_none(), "{}", c[0]);
        } else {
            let result = result.expect("original accepted contact");
            assert_eq!(result.candidate, c[4].parse().unwrap());
            assert_eq!(result.word, c[8].parse().unwrap());
            assert_eq!(
                result.segment[0],
                vector(c[9]),
                "{} fallback segment start",
                c[0]
            );
            for (a, e) in [
                (result.point, vector(c[5])),
                (result.normal, vector(c[6])),
                (result.displacement, vector(c[7])),
            ] {
                for (a, e) in a.into_iter().zip(e) {
                    assert!(
                        (a - e).abs() <= 2e-6_f32.max(2e-6 * a.abs().max(e.abs())),
                        "{}: {a} != {e}",
                        c[0]
                    );
                }
            }
        }
        count += 1;
    }
    assert_eq!(count, 8);
}
