//! Complete source 0x494000 calls with a real original support tree and owner.
use nfs_assets::physics::{
    original_contact::PreparedContactState,
    original_scene_contact::{respond_scene_contact, SceneContactRequest},
    original_support::{SupportPolygon, SupportVertices},
    original_support_owner::OriginalSupportOwner,
    original_support_tree::SupportTree,
};

const FIXTURES: &str =
    include_str!("../../../runs/019-original-contact-runtime/scene-response-fixtures.tsv");

fn floats(value: &str) -> Vec<f32> {
    value.split(',').map(|v| v.parse().unwrap()).collect()
}

fn vector(value: &str) -> [f32; 3] {
    floats(value).try_into().unwrap()
}

fn close(name: &str, actual: &[f32], expected: &str) {
    let expected = floats(expected);
    assert_eq!(actual.len(), expected.len());
    for (&a, e) in actual.iter().zip(expected) {
        assert!(
            (a - e).abs() <= 2e-6_f32.max(2e-6 * a.abs().max(e.abs())),
            "{name}: actual {a}, original {e}"
        );
    }
}

#[test]
fn matches_complete_original_scene_response() {
    let tri = [[0., 0., 0.], [0., 0., 10.], [10., 0., 0.]];
    let polygons = vec![
        SupportPolygon::new(SupportVertices::Triangle(tri), 1),
        SupportPolygon::new(
            SupportVertices::Triangle(tri.map(|[x, _, z]| [x, 10., z])),
            1,
        ),
    ];
    let mut tree = SupportTree::original_scene();
    for index in 0..polygons.len() {
        tree.insert(&polygons, index).unwrap();
    }
    let mut count = 0;
    for line in FIXTURES.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        assert_eq!(c.len(), 20);
        let mut owner = OriginalSupportOwner::default();
        if c[1] != "-" {
            owner.select(&tree, &polygons, vector(c[1]), true).unwrap();
        }
        let initial_owner = owner.clone();
        let velocity = vector(c[4]);
        let mut state = PreparedContactState {
            position_330: [2., 3., 2.],
            velocity_33c: velocity,
            speed_35c: velocity[0].abs().max(velocity[2].abs())
                + 0.25 * velocity[0].abs().min(velocity[2].abs()),
            basis_364: [1., 0., 0.],
            basis_370: [0., 1., 0.],
            basis_37c: [0., 0., 1.],
            field_38c: 0.375,
            field_434: 1234.,
            basis_490: [0., 0., -1.],
            basis_4a8: [1., 0., 0.],
            local_velocity_d58: [11., 12., 25.],
            wheel_points_7f8: [[4., 5., 6.]; 4],
            wheel_fields_870: [9.; 4],
            field_db8: 7.,
            field_dc0: 8.,
        };
        let result = respond_scene_contact(
            &mut state,
            &owner,
            &tree,
            &polygons,
            SceneContactRequest {
                normal: [1., 0., 0.],
                point: vector(c[2]),
                displacement: vector(c[3]),
                angular_callback: c[5] == "1",
                alternate_52c_mask_04: c[6] == "1",
            },
        )
        .unwrap();
        let selected = if c[7] == "-" {
            None
        } else {
            Some(c[7].parse().unwrap())
        };
        assert_eq!(result.support, selected, "{} support", c[0]);
        assert_eq!(owner, initial_owner, "source uses a private owner copy");
        close(c[0], &result.prepared.correction, c[8]);
        close(c[0], &state.position_330, c[9]);
        close(c[0], &state.velocity_33c, c[10]);
        close(c[0], &[state.speed_35c], c[11]);
        close(c[0], &state.local_velocity_d58, c[12]);
        close(c[0], &[state.field_38c], c[13]);
        close(c[0], &[state.field_434], c[14]);
        close(c[0], &state.wheel_points_7f8.concat(), c[15]);
        close(c[0], &state.wheel_fields_870, c[16]);
        close(c[0], &[state.field_db8], c[17]);
        close(c[0], &[state.field_dc0], c[18]);
        close(c[0], &[result.magnitude], c[19]);
        count += 1;
    }
    assert_eq!(count, 45);
}
