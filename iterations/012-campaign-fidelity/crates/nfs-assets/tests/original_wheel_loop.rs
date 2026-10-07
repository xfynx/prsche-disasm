use nfs_assets::physics::{
    original_support::{SupportPolygon, SupportVertices},
    original_support_owner::OriginalSupportOwner,
    original_support_tree::SupportTree,
    original_wheel_loop::{advance_wheel_loop, FrontOffsetPart, WheelLoopInput, WheelLoopState},
    original_wheel_state::{MaterialHeightState, MaterialRandomState},
};

fn floats(s: &str) -> Vec<f32> {
    s.split(',').map(|v| v.parse().unwrap()).collect()
}

fn near(a: f32, b: f32, label: &str) {
    assert!(a.is_finite() && b.is_finite());
    assert!(
        (a - b).abs() <= 2e-6_f32.max(2e-6 * a.abs().max(b.abs())),
        "{label}: {a} != {b}"
    );
}

#[test]
fn first_four_wheel_loop_matches_original_x86() {
    let fixture = include_str!("../../../runs/020-original-wheel-loop/wheel-loop-fixtures.tsv");
    let mut count = 0;
    for line in fixture.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let v = floats(c[1]);
        let mut parts = [FrontOffsetPart::default(); 20];
        if c[6] != "-" {
            for (part, row) in parts.iter_mut().zip(c[6].split('/')) {
                let p = floats(row);
                *part = FrontOffsetPart {
                    kind_26: p[0] as u16,
                    weight_60: p[1],
                    mask_48: p[2] as u16,
                    bias_164: p[3],
                };
            }
        }
        let input = WheelLoopInput {
            points_1dc: c[7]
                .split('/')
                .map(|s| floats(s).try_into().unwrap())
                .collect::<Vec<_>>()
                .try_into()
                .unwrap(),
            up_370: floats(c[2]).try_into().unwrap(),
            reference_334: v[7],
            ride_120: v[10],
            limit_124: v[11],
            fallback_normal_3e8: floats(c[3]).try_into().unwrap(),
            fallback_base_400: floats(c[4]).try_into().unwrap(),
            gate_3a0: v[8],
            speed_35c: v[9],
            quality_606ac4: v[3] as i32,
            skip_657408: v[4] != 0.,
            car_dac: v[5] != 0.,
            remap_6573f8: v[6] != 0.,
            modifiers_4e4: floats(c[5]).try_into().unwrap(),
            parts_768: parts,
        };
        let poly = SupportVertices::Quad([
            [-10., v[1] - 10. * v[0], -10.],
            [-10., v[1] - 10. * v[0], 10.],
            [10., v[1] + 10. * v[0], 10.],
            [10., v[1] + 10. * v[0], -10.],
        ]);
        let polygons = [SupportPolygon::new(poly, v[2] as u16)];
        let mut tree = SupportTree::original_scene();
        tree.insert(&polygons, 0).unwrap();
        let mut states = std::array::from_fn(|_| WheelLoopState {
            owner: OriginalSupportOwner::default(),
            compression_64: v[12],
            angle_6c: 0.,
            material: MaterialHeightState {
                previous: v[17],
                current: v[16],
                phase: v[15],
            },
            flag_80: v[13] != 0.,
            phase_84: v[14],
        });
        let mut rng = MaterialRandomState {
            seed_5d1028: 123,
            multiplier_5d102c: 16807,
            product_655a0c: 999,
        };
        let result = advance_wheel_loop(&input, &mut states, &mut rng, &tree, &polygons).unwrap();
        for ((sample, state), row) in result.wheels.iter().zip(states.iter()).zip(c[8].split('/')) {
            let e = floats(row);
            for (actual, expected) in sample
                .query
                .iter()
                .chain(sample.point.iter())
                .chain(sample.normal.iter())
                .zip(e.iter())
            {
                near(*actual, *expected, c[0]);
            }
            assert_eq!(sample.material_88, e[9] as u16, "{}", c[0]);
            assert_eq!(sample.selected, e[10] != 0., "{}", c[0]);
            for (actual, expected) in [
                state.material.previous,
                state.material.current,
                state.material.phase,
                state.compression_64,
                state.angle_6c,
            ]
            .iter()
            .zip(e[11..].iter())
            {
                near(*actual, *expected, c[0]);
            }
        }
        for (a, b) in result
            .multipliers
            .iter()
            .zip(floats(c[9]))
            .chain(result.sum.iter().zip(floats(c[10])))
        {
            near(*a, b, c[0]);
        }
        assert_eq!(rng.seed_5d1028, c[11].parse().unwrap(), "{}", c[0]);
        assert_eq!(rng.product_655a0c, c[12].parse().unwrap(), "{}", c[0]);
        count += 1;
    }
    assert_eq!(count, 47);
}
