use nfs_assets::physics::original_support::{SupportPolygon, SupportVertices};
use nfs_assets::physics::original_support_owner::OriginalSupportOwner;
use nfs_assets::physics::original_support_tree::SupportTree;

fn triples(text: &str) -> Vec<[f32; 3]> {
    let numbers: Vec<f32> = text.split(',').map(|x| x.parse().unwrap()).collect();
    assert_eq!(numbers.len() % 3, 0);
    numbers
        .as_chunks::<3>()
        .0
        .iter()
        .map(|v| [v[0], v[1], v[2]])
        .collect()
}

fn polygons(text: &str) -> Vec<SupportPolygon> {
    text.split('/')
        .map(|text| match triples(text).as_slice() {
            [a, b, c] => SupportPolygon::new(SupportVertices::Triangle([*a, *b, *c]), 1),
            [a, b, c, d] => SupportPolygon::new(SupportVertices::Quad([*a, *b, *c, *d]), 1),
            _ => panic!("unsupported original fixture polygon"),
        })
        .collect()
}

#[test]
fn original_owner_cache_normal_and_plane_point() {
    let fixture = include_str!("../../../runs/018-original-support-runtime/owner-fixtures.tsv");
    let mut current = "";
    let mut tree = SupportTree::original_scene();
    let mut geometry = Vec::new();
    let mut owner = OriginalSupportOwner::default();
    let mut cases = 0;
    for line in fixture.lines().skip(1) {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 9);
        if columns[0] != current {
            current = columns[0];
            geometry = polygons(columns[1]);
            tree = SupportTree::original_scene();
            for index in 0..geometry.len() {
                tree.insert(&geometry, index).unwrap();
            }
            owner = OriginalSupportOwner::default();
        }
        let point = triples(columns[2])[0];
        let hit = owner
            .select(&tree, &geometry, point, columns[3] == "1")
            .unwrap();
        assert_eq!(
            owner.node.map(|i| tree.nodes[i].cell.packed),
            columns[5].parse().ok(),
            "{current}"
        );
        if columns[4] == "-" {
            assert!(hit.is_none(), "{current}");
        } else {
            let hit = hit.unwrap();
            assert_eq!(hit.polygon, columns[4].parse().unwrap(), "{current}");
            let normal = triples(columns[6])[0];
            let base = triples(columns[7])[0];
            for axis in 0..3 {
                assert!(
                    (hit.normal[axis] - normal[axis]).abs() <= 2e-6,
                    "{current} normal axis {axis}: {:?} != {:?}",
                    hit.normal,
                    normal
                );
                assert_eq!(hit.point[axis], base[axis], "{current} base axis {axis}");
            }
            let height: f32 = columns[8].parse().unwrap();
            assert!(
                (hit.height - height).abs() <= 2e-6,
                "{current} height: {} != {height}",
                hit.height
            );
        }
        cases += 1;
    }
    assert_eq!(cases, 10);
}
