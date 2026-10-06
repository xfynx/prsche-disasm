use nfs_assets::physics::original_spatial::SpatialGrid;
use nfs_assets::physics::original_support::{SupportPolygon, SupportVertices};
use nfs_assets::physics::original_support_tree::{SceneRef, SupportTree};
use std::collections::BTreeMap;

fn polygons(text: &str) -> Vec<SupportPolygon> {
    text.split('/')
        .map(|polygon| {
            let values: Vec<f32> = polygon.split(',').map(|x| x.parse().unwrap()).collect();
            let points: Vec<[f32; 3]> = values.as_chunks::<3>().0.to_vec();
            let vertices = match points.len() {
                3 => SupportVertices::Triangle(points.try_into().unwrap()),
                4 => SupportVertices::Quad(points.try_into().unwrap()),
                count => panic!("unsupported fixture polygon {count}"),
            };
            SupportPolygon::new(vertices, 1)
        })
        .collect()
}

fn canonical(tree: &SupportTree) -> String {
    fn visit(tree: &SupportTree, index: usize, output: &mut Vec<String>) {
        let node = &tree.nodes[index];
        let mask: u32 = node
            .cell
            .children
            .iter()
            .enumerate()
            .filter(|(_, child)| child.is_some())
            .map(|(slot, _)| 1 << slot)
            .sum();
        let records = match &node.records {
            None => "-".to_string(),
            Some(records) if records.is_empty() => "_".to_string(),
            Some(records) => records
                .iter()
                .map(|record| match record {
                    SceneRef::Polygon(index) => index.to_string(),
                    SceneRef::Object(_) => panic!("unexpected object in polygon fixture"),
                })
                .collect::<Vec<_>>()
                .join(","),
        };
        assert_eq!(node.cell.records_present, node.records.is_some());
        output.push(format!("{}:{mask}:{records}", node.cell.packed));
        for child in node.cell.children.iter().flatten() {
            visit(tree, *child, output);
        }
    }
    let mut rows = vec![];
    visit(tree, 0, &mut rows);
    assert_eq!(rows.len(), tree.nodes.len(), "unreachable arena node");
    rows.join(";")
}

#[test]
fn original_dynamic_insertion_splitting_and_record_order() {
    let fixture = include_str!("../../../runs/017-original-support-insertion/tree-fixtures.tsv");
    let mut count = 0;
    for line in fixture.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        assert_eq!(c.len(), 5);
        let geometry = polygons(c[2]);
        let mut tree = SupportTree::new(SpatialGrid::new(8192., 15), c[1].parse().unwrap());
        for index in c[3].split(',').map(|i| i.parse().unwrap()) {
            tree.insert(&geometry, index).unwrap();
        }
        assert_eq!(
            canonical(&tree),
            c[4],
            "{} after {} insertions",
            c[0],
            c[3].split(',').count()
        );
        count += 1;
    }
    assert_eq!(count, 36);
}

#[test]
fn original_full_cached_query_on_constructed_tree() {
    let fixture = include_str!("../../../runs/017-original-support-insertion/tree-fixtures.tsv");
    let mut trees = BTreeMap::new();
    // Later rows replace earlier snapshots, leaving the final tree per case.
    for line in fixture.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let geometry = polygons(c[2]);
        let mut tree = SupportTree::new(SpatialGrid::new(8192., 15), c[1].parse().unwrap());
        for index in c[3].split(',').map(|i| i.parse().unwrap()) {
            tree.insert(&geometry, index).unwrap();
        }
        trees.insert(c[0], (tree, geometry, None::<usize>));
    }
    let queries =
        include_str!("../../../runs/017-original-support-insertion/tree-query-fixtures.tsv");
    let mut count = 0;
    for line in queries.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let (tree, geometry, cached) = trees.get_mut(c[0]).unwrap();
        let point: Vec<f32> = c[1].split(',').map(|v| v.parse().unwrap()).collect();
        if let Some(cached) = cached {
            assert_eq!(
                tree.nodes[*cached].cell.packed,
                c[4].parse::<u32>().unwrap()
            );
        } else {
            assert_eq!(c[4], "-");
        }
        let (selected, leaf) = tree
            .query(geometry, point.try_into().unwrap(), *cached)
            .unwrap();
        let expected = if c[2] == "-" {
            None
        } else {
            Some(c[2].parse::<usize>().unwrap())
        };
        assert_eq!(selected, expected, "{} query {}", c[0], c[1]);
        assert_eq!(
            tree.nodes[leaf].cell.packed,
            c[3].parse::<u32>().unwrap(),
            "{} leaf",
            c[0]
        );
        *cached = Some(leaf);
        count += 1;
    }
    assert_eq!(count, 72);
}
