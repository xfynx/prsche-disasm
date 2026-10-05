//! Regression vectors captured by executing the original Porsche.exe x86 bytes
//! at 0x4940ae with the optional 0x493f10 callback, 468 prepared contacts.

use nfs_assets::physics::original_contact::{
    respond_prepared_contact, PreparedContact, PreparedContactState,
};

const FIXTURES: &str =
    include_str!("../../../runs/012-original-contact-kernel/response-fixtures.tsv");

fn close(label: &str, actual: f32, expected: f32, name: &str) {
    let delta = (actual - expected).abs();
    let limit = 2e-6_f32.max(2e-6 * actual.abs().max(expected.abs()));
    assert!(
        delta <= limit,
        "{name} {label}: actual={actual}, original={expected}, delta={delta}"
    );
}

#[test]
fn matches_original_prepared_contact_response() {
    let mut lines = FIXTURES.lines();
    let header = lines.next().expect("fixture header");
    assert!(header.starts_with("name\tvx\tvy\tvz\tnx\tny\tnz\talternate\tangular\told_forward\t"));
    let mut count = 0;
    for line in lines {
        let cols: Vec<_> = line.split('\t').collect();
        assert_eq!(cols.len(), 41, "fixture columns: {}", cols[0]);
        let name = cols[0];
        let number = |i: usize| -> f32 {
            cols[i]
                .parse()
                .unwrap_or_else(|_| panic!("{name} column {i}"))
        };
        let vector =
            |start: usize| -> [f32; 3] { [number(start), number(start + 1), number(start + 2)] };
        let velocity = vector(1);
        let initial_speed = {
            let x = velocity[0].abs() as f64;
            let z = velocity[2].abs() as f64;
            (x.max(z) + 0.25 * x.min(z)) as f32
        };
        let mut state = PreparedContactState {
            position_330: [10.0, 20.0, 30.0],
            velocity_33c: velocity,
            speed_35c: initial_speed,
            basis_364: [1.0, 0.0, 0.0],
            basis_370: [0.0, 1.0, 0.0],
            basis_37c: [0.0, 0.0, 1.0],
            field_38c: 0.375,
            field_434: 1234.0,
            basis_490: [0.0, 0.0, -1.0],
            basis_4a8: [1.0, 0.0, 0.0],
            local_velocity_d58: [11.0, 12.0, number(9)],
            wheel_points_7f8: [[40.0, 50.0, 60.0]; 4],
            wheel_fields_870: [9.0; 4],
            field_db8: 7.0,
            field_dc0: 8.0,
        };
        let magnitude = respond_prepared_contact(
            &mut state,
            PreparedContact {
                normal: vector(4),
                correction: [0.125, -0.25, 0.5],
                alternate_52c_mask_04: cols[7] == "1",
                angular_callback: cols[8] == "1",
            },
        );
        for (label, actual, expected) in [
            ("velocity", &state.velocity_33c[..], &cols[10..13]),
            ("position", &state.position_330[..], &cols[13..16]),
            ("projection", &state.local_velocity_d58[..], &cols[16..19]),
        ] {
            for (i, (actual, expected)) in actual.iter().zip(expected.iter()).enumerate() {
                close(
                    &format!("{label}[{i}]"),
                    *actual,
                    expected.parse().unwrap(),
                    name,
                );
            }
        }
        close("speed", state.speed_35c, number(19), name);
        close("return", magnitude, number(20), name);
        for (i, point) in state.wheel_points_7f8.iter().flatten().enumerate() {
            close(&format!("wheel[{i}]"), *point, number(21 + i), name);
        }
        for (i, reset) in state
            .wheel_fields_870
            .iter()
            .chain([&state.field_db8, &state.field_dc0])
            .enumerate()
        {
            close(&format!("reset[{i}]"), *reset, number(33 + i), name);
        }
        close("angular", state.field_38c, number(39), name);
        close("field_434", state.field_434, number(40), name);
        count += 1;
    }
    assert_eq!(count, 468);
}
