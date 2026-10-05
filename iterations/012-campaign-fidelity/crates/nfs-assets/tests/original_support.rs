//! Original x86 constructor, containment, and supplied-leaf selection vectors.

use nfs_assets::physics::original_support::{
    plane_normal, quad_plane_gap, select_support_polygon, split_quad_if_needed, SupportLeafRecord,
    SupportPolygon, SupportVertices,
};

const FIXTURES: &str =
    include_str!("../../../runs/013-original-support-query/polygon-fixtures.tsv");
const SELECTION_FIXTURES: &str =
    include_str!("../../../runs/013-original-support-query/selection-fixtures.tsv");
const PLANE_FIXTURES: &str =
    include_str!("../../../runs/015-original-support-loader/plane-fixtures.tsv");
const SPLIT_FIXTURES: &str =
    include_str!("../../../runs/015-original-support-loader/plane-split-fixtures.tsv");

fn close(actual: f32, expected: f32, label: &str) {
    let limit = 2e-6_f32.max(2e-6 * actual.abs().max(expected.abs()));
    assert!(
        (actual - expected).abs() <= limit,
        "{label}: actual {actual}, original {expected}"
    );
}

#[test]
fn original_x86_polygon_vectors() {
    let mut lines = FIXTURES.lines();
    let header = lines.next().expect("fixture header");
    assert_eq!(header.split('\t').count(), 21);
    let mut cases = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 21);
        let number = |i: usize| -> f32 { columns[i].parse().unwrap() };
        let vector = |i: usize| -> [f32; 3] { [number(i), number(i + 1), number(i + 2)] };
        let vertices = match columns[0] {
            "3" => SupportVertices::Triangle([vector(1), vector(4), vector(7)]),
            "4" => SupportVertices::Quad([vector(1), vector(4), vector(7), vector(10)]),
            other => panic!("unexpected vertex count: {other}"),
        };
        let polygon = SupportPolygon::new(vertices, 1);
        assert_eq!(
            polygon.winding_8,
            columns[16] == "1",
            "case {cases} winding"
        );
        assert_eq!(
            polygon.contains_xz(vector(13)),
            columns[17] == "1",
            "case {cases} containment"
        );
        for axis in 0..3 {
            close(
                polygon.center[axis],
                number(18 + axis),
                &format!("case {cases} center[{axis}]"),
            );
        }
        cases += 1;
    }
    assert_eq!(cases, 36);
}

fn horizontal_triangle(height: f32, flags: u16) -> SupportPolygon {
    SupportPolygon::new(
        SupportVertices::Triangle([[0.0, height, 0.0], [10.0, height, 0.0], [0.0, height, 10.0]]),
        flags,
    )
}

#[test]
fn original_x86_supplied_leaf_selection() {
    let mut lines = SELECTION_FIXTURES.lines();
    assert_eq!(
        lines.next(),
        Some("h0\th1\tflags0\tflags1\ttype0\ttype1\tpx\tpy\tpz\tselected")
    );
    let mut cases = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 10);
        let heights = [columns[0].parse().unwrap(), columns[1].parse().unwrap()];
        let flags = [columns[2].parse().unwrap(), columns[3].parse().unwrap()];
        let kinds = [columns[4].parse().unwrap(), columns[5].parse().unwrap()];
        let point = [
            columns[6].parse().unwrap(),
            columns[7].parse().unwrap(),
            columns[8].parse().unwrap(),
        ];
        let selected: i32 = columns[9].parse().unwrap();
        let expected = if selected < 0 {
            None
        } else {
            Some(selected as usize)
        };
        let polygons = [
            horizontal_triangle(heights[0], flags[0]),
            horizontal_triangle(heights[1], flags[1]),
        ];
        let records = [
            SupportLeafRecord {
                record_type: kinds[0],
                polygon: &polygons[0],
            },
            SupportLeafRecord {
                record_type: kinds[1],
                polygon: &polygons[1],
            },
        ];
        assert_eq!(
            select_support_polygon(&records, point),
            expected,
            "case {cases}"
        );
        cases += 1;
    }
    assert_eq!(cases, 10);
}

#[test]
fn original_x86_plane_and_quad_gap() {
    let mut lines = PLANE_FIXTURES.lines();
    assert_eq!(
        lines.next(),
        Some("name\tvertices\tnx_bits\tny_bits\tnz_bits\tgap_bits")
    );
    let mut cases = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 6);
        let values: Vec<f32> = columns[1].split(',').map(|x| x.parse().unwrap()).collect();
        assert_eq!(values.len(), 12);
        let vertices: [[f32; 3]; 4] =
            std::array::from_fn(|i| [values[i * 3], values[i * 3 + 1], values[i * 3 + 2]]);
        let normal = plane_normal([vertices[0], vertices[1], vertices[2]]);
        for axis in 0..3 {
            let original_bits: u32 = columns[2 + axis].parse().unwrap();
            let expected = f32::from_bits(original_bits);
            if expected == 0.0 {
                assert_eq!(
                    normal[axis].to_bits(),
                    original_bits,
                    "{} normal zero[{axis}]",
                    columns[0]
                );
            } else {
                close(
                    normal[axis],
                    expected,
                    &format!("{} normal[{axis}]", columns[0]),
                );
            }
        }
        let original_gap_bits: u32 = columns[5].parse().unwrap();
        let original_gap = f32::from_bits(original_gap_bits);
        let gap = quad_plane_gap(vertices);
        if original_gap.is_nan() {
            assert!(gap.is_nan(), "{} expected NaN gap", columns[0]);
        } else {
            close(gap, original_gap, &format!("{} gap", columns[0]));
        }
        cases += 1;
    }
    assert_eq!(cases, 10);
}

#[test]
fn original_x86_quad_split_branch() {
    let mut lines = SPLIT_FIXTURES.lines();
    assert_eq!(lines.next(), Some("flags\tvertices\tsplit"));
    let mut cases = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 3);
        let flags = columns[0].parse().unwrap();
        let values: Vec<f32> = columns[1].split(',').map(|x| x.parse().unwrap()).collect();
        assert_eq!(values.len(), 12);
        let vertices: [[f32; 3]; 4] =
            std::array::from_fn(|i| [values[i * 3], values[i * 3 + 1], values[i * 3 + 2]]);
        let pieces = split_quad_if_needed(vertices, flags);
        let original_split = columns[2] == "1";
        assert_eq!(
            pieces.len(),
            if original_split { 2 } else { 1 },
            "case {cases}"
        );
        if original_split {
            assert_eq!(
                pieces[0],
                SupportVertices::Triangle([vertices[0], vertices[1], vertices[2]])
            );
            assert_eq!(
                pieces[1],
                SupportVertices::Triangle([vertices[0], vertices[2], vertices[3]])
            );
        } else {
            assert_eq!(pieces[0], SupportVertices::Quad(vertices));
        }
        cases += 1;
    }
    assert_eq!(cases, 10);
}
