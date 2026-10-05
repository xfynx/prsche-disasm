//! Differential fixtures executed on original Porsche.exe x86 instructions.

use nfs_assets::physics::original_spatial::{SpatialGrid, SpatialNode};

const GRID: &str = include_str!("../../../runs/014-original-spatial-query/grid-fixtures.tsv");
const BOUNDS: &str = include_str!("../../../runs/014-original-spatial-query/bounds-fixtures.tsv");
const QUERY: &str = include_str!("../../../runs/014-original-spatial-query/query-fixtures.tsv");
const CACHE: &str = include_str!("../../../runs/014-original-spatial-query/cache-fixtures.tsv");

fn lines<'a>(input: &'a str, header: &str) -> impl Iterator<Item = &'a str> {
    let mut lines = input.lines();
    assert_eq!(lines.next(), Some(header));
    lines
}

fn parse_nodes(encoded: &str) -> Vec<SpatialNode> {
    encoded
        .split(';')
        .map(|entry| {
            let mut fields = entry.split(':');
            let packed = fields.next().unwrap().parse().unwrap();
            let children: Vec<_> = fields
                .next()
                .unwrap()
                .split(',')
                .map(|value| {
                    let index: i32 = value.parse().unwrap();
                    (index >= 0).then_some(index as usize)
                })
                .collect();
            let records_present = fields.next() == Some("1");
            assert!(fields.next().is_none());
            SpatialNode {
                packed,
                children: children.try_into().unwrap(),
                records_present,
            }
        })
        .collect()
}

#[test]
fn original_x86_grid_widths() {
    let mut cases = 0;
    for line in lines(GRID, "half_extent\tdepth\twidths") {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 3);
        let half_extent = columns[0].parse().unwrap();
        let depth = columns[1].parse().unwrap();
        let grid = SpatialGrid::new(half_extent, depth);
        let expected: Vec<f32> = columns[2].split(',').map(|x| x.parse().unwrap()).collect();
        assert_eq!(expected.len(), 16);
        assert_eq!(grid.widths.as_slice(), expected.as_slice(), "case {cases}");
        cases += 1;
    }
    assert_eq!(cases, 12);
}

#[test]
fn original_x86_packed_bounds() {
    let mut cases = 0;
    for line in lines(BOUNDS, "half_extent\tpacked\tpx\tpy\tpz\tcontains") {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 6);
        let grid = SpatialGrid::new(columns[0].parse().unwrap(), 16);
        let packed = columns[1].parse().unwrap();
        let point = [
            columns[2].parse().unwrap(),
            columns[3].parse().unwrap(),
            columns[4].parse().unwrap(),
        ];
        assert_eq!(
            grid.contains(packed, point),
            columns[5] == "1",
            "case {cases}"
        );
        cases += 1;
    }
    assert_eq!(cases, 112);
}

fn check_lookup_fixture(input: &str, cached_lookup: bool, expected_count: usize) {
    let grid = SpatialGrid::new(32.0, 16);
    let mut cases = 0;
    for line in lines(input, "nodes\tpx\tpy\tpz\tcached\tleaf\tcache_hit") {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 7);
        let nodes = parse_nodes(columns[0]);
        let point = [
            columns[1].parse().unwrap(),
            columns[2].parse().unwrap(),
            columns[3].parse().unwrap(),
        ];
        let cached: i32 = columns[4].parse().unwrap();
        let expected_leaf: usize = columns[5].parse().unwrap();
        let expected_hit = columns[6] == "1";
        if cached_lookup {
            let cached = (cached >= 0).then_some(cached as usize);
            assert_eq!(
                grid.resolve_cached(&nodes, point, cached),
                (expected_leaf, expected_hit),
                "case {cases}"
            );
        } else {
            assert_eq!(grid.query(&nodes, point), expected_leaf, "case {cases}");
        }
        cases += 1;
    }
    assert_eq!(cases, expected_count);
}

#[test]
fn original_x86_tree_traversal() {
    check_lookup_fixture(QUERY, false, 112);
}

#[test]
fn original_x86_cached_resolution() {
    check_lookup_fixture(CACHE, true, 336);
}
