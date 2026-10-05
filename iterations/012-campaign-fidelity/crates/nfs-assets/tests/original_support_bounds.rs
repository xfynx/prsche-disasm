use nfs_assets::physics::original_support_bounds;

fn triple(text: &str) -> [f32; 3] {
    let values: Vec<f32> = text.split(',').map(|x| x.parse().unwrap()).collect();
    [values[0], values[1], values[2]]
}

fn vertices(text: &str) -> Vec<[f32; 3]> {
    text.split(',')
        .map(|x| x.parse::<f32>().unwrap())
        .collect::<Vec<_>>()
        .as_chunks::<3>()
        .0
        .iter()
        .map(|v| [v[0], v[1], v[2]])
        .collect()
}

#[test]
fn original_callback_outputs() {
    let fixture =
        include_str!("../../../runs/017-original-support-insertion/bounds-callback-fixtures.tsv");
    let mut count = 0;
    for line in fixture.lines().skip(1) {
        let fields: Vec<_> = line.split('\t').collect();
        let v = vertices(fields[1]);
        assert_eq!(v.len(), fields[0].parse::<usize>().unwrap());
        let actual_center = original_support_bounds::center(&v);
        let expected_center = triple(fields[2]);
        for axis in 0..3 {
            assert_eq!(
                actual_center[axis].to_bits(),
                expected_center[axis].to_bits(),
                "{line}"
            );
        }
        let (lower, upper) =
            original_support_bounds::bounds(&v, [101.0, 105.0, 103.0], [104.0, 108.0, 106.0]);
        assert_eq!(lower, triple(fields[3]), "{line}");
        assert_eq!(upper, triple(fields[4]), "{line}");
        count += 1;
    }
    assert_eq!(count, 38);
}

#[test]
fn original_node_object_predicate() {
    let fixture =
        include_str!("../../../runs/017-original-support-insertion/bounds-predicate-fixtures.tsv");
    let mut count = 0;
    for line in fixture.lines().skip(1) {
        let fields: Vec<_> = line.split('\t').collect();
        let v = vertices(fields[1]);
        assert_eq!(v.len(), fields[0].parse::<usize>().unwrap());
        let mut widths = [0.0_f32; 16];
        widths[0] = fields[2].parse().unwrap();
        let extent: f32 = fields[3].parse().unwrap();
        let x: u32 = fields[4].parse().unwrap();
        let z: u32 = fields[5].parse().unwrap();
        let packed = (z << 14) | x;
        let actual = original_support_bounds::node_overlap(packed, &widths, extent, &v);
        assert_eq!(actual, fields[6] == "1", "{line}");
        count += 1;
    }
    assert_eq!(count, 304);
}
