use nfs_assets::physics::{
    original_scene_objects::{EdgeObject, SceneObject},
    original_support::{SupportPolygon, SupportVertices},
    original_support_tree::{SceneRef, SupportTree},
};

fn points(value: &str) -> Vec<[f32; 3]> {
    value
        .split(',')
        .map(|v| v.parse::<f32>().unwrap())
        .collect::<Vec<_>>()
        .as_chunks::<3>()
        .0
        .to_vec()
}

fn canonical(tree: &SupportTree) -> String {
    fn visit(tree: &SupportTree, index: usize, rows: &mut Vec<String>) {
        let node = &tree.nodes[index];
        let mask: u32 = node
            .cell
            .children
            .iter()
            .enumerate()
            .filter(|(_, v)| v.is_some())
            .map(|(i, _)| 1 << i)
            .sum();
        let records = match &node.records {
            None => "-".into(),
            Some(v) if v.is_empty() => "_".into(),
            Some(v) => v
                .iter()
                .map(|r| match r {
                    SceneRef::Polygon(i) => format!("p{i}"),
                    SceneRef::Object(i) => format!("e{i}"),
                })
                .collect::<Vec<_>>()
                .join(","),
        };
        rows.push(format!("{}:{mask}:{records}", node.cell.packed));
        for child in node.cell.children.iter().flatten() {
            visit(tree, *child, rows);
        }
    }
    let mut rows = vec![];
    visit(tree, 0, &mut rows);
    assert_eq!(rows.len(), tree.nodes.len());
    rows.join(";")
}

#[test]
fn matches_original_mixed_insertion_and_edge_selection() {
    let trees = include_str!("../../../runs/019-original-contact-runtime/mixed-tree-fixtures.tsv");
    let queries =
        include_str!("../../../runs/019-original-contact-runtime/mixed-edge-fixtures.tsv");
    let mut tree_count = 0;
    let mut query_count = 0;
    for line in trees.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let polygons: Vec<_> = c[1]
            .split('/')
            .map(|v| {
                SupportPolygon::new(SupportVertices::Triangle(points(v).try_into().unwrap()), 1)
            })
            .collect();
        let objects: Vec<_> = c[2]
            .split('/')
            .enumerate()
            .map(|(i, v)| {
                SceneObject::Edge(EdgeObject::from_source(
                    10 + i as u16,
                    points(v).try_into().unwrap(),
                    i,
                ))
            })
            .collect();
        for (object, original) in objects.iter().zip(c[3].split('/')) {
            let SceneObject::Edge(edge) = object else {
                unreachable!()
            };
            assert_eq!(
                edge.endpoints.as_slice(),
                points(original),
                "{} constructor",
                c[0]
            );
        }
        let mut tree = SupportTree::original_scene();
        for label in c[4].split(',') {
            let index = label[1..].parse().unwrap();
            let record = if label.starts_with('p') {
                SceneRef::Polygon(index)
            } else {
                SceneRef::Object(index)
            };
            tree.insert_scene(&polygons, &objects, record).unwrap();
        }
        assert_eq!(canonical(&tree), c[5], "{} full tree", c[0]);
        for query in queries.lines().skip(1) {
            let q: Vec<_> = query.split('\t').collect();
            if q[0] != c[0] {
                continue;
            }
            let result = tree
                .query_scene_edges(&objects, points(q[1]).try_into().unwrap(), q[2] == "1")
                .unwrap();
            if q[3] == "-" {
                assert!(result.is_none(), "{} unexpected edge", c[0]);
            } else {
                let result = result.expect("original selected edge");
                assert_eq!(format!("e{}", result.object), q[3], "{} selected", c[0]);
                assert_eq!(result.endpoints.as_slice(), points(q[4]));
                assert_eq!(result.word, q[5].parse().unwrap());
            }
            query_count += 1;
        }
        tree_count += 1;
    }
    assert_eq!(tree_count, 3);
    assert_eq!(query_count, 27);
}
