use nfs_assets::physics::original_wheel_state::{
    advance_material_height, height_branch, MaterialHeightState, MaterialRandomState,
};

#[test]
fn original_height_branch_cases() {
    let cases =
        include_str!("../../../runs/019-original-contact-runtime/wheel-branch-fixtures.tsv");
    let mut count = 0;
    for line in cases.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        assert_eq!(
            height_branch(c[1].parse().unwrap(), c[2].parse().unwrap(), 2.) as u8,
            c[4].parse::<u8>().unwrap(),
            "{}",
            c[0]
        );
        count += 1;
    }
    assert_eq!(count, 5);
}

#[test]
fn original_material_state_cases() {
    let cases =
        include_str!("../../../runs/019-original-contact-runtime/wheel-material-fixtures.tsv");
    let mut count = 0;
    for line in cases.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let f = |i: usize| c[i].parse::<f32>().unwrap();
        let mut state = MaterialHeightState {
            phase: f(3),
            previous: f(4),
            current: f(5),
        };
        let mut rng = MaterialRandomState {
            seed_5d1028: c[6].parse().unwrap(),
            multiplier_5d102c: c[13].parse().unwrap(),
            product_655a0c: 999,
        };
        let height =
            advance_material_height(&mut state, f(12), f(1), c[2].parse().unwrap(), &mut rng);
        for (a, e) in [
            (height, f(7)),
            (state.phase, f(8)),
            (state.previous, f(9)),
            (state.current, f(10)),
        ] {
            assert!(
                (a - e).abs() <= 2e-6_f32.max(2e-6 * a.abs().max(e.abs())),
                "{}: {a} != {e}",
                c[0]
            );
        }
        assert_eq!(rng.seed_5d1028, c[11].parse().unwrap());
        assert_eq!(rng.product_655a0c, c[14].parse().unwrap());
        count += 1;
    }
    assert_eq!(count, 29);
}
