//! Expectations captured from unmodified original x86, including real pr payloads.
use nfs_assets::physics::original_spatial::SpatialNode;
use nfs_assets::physics::original_support_assembly::{OriginalPrimitive, SelectedBaseMask};
use std::collections::BTreeMap;
use std::path::Path;

fn hex(text: &str) -> Vec<u8> {
    assert_eq!(text.len() % 2, 0);
    (0..text.len())
        .step_by(2)
        .map(|i| u8::from_str_radix(&text[i..i + 2], 16).unwrap())
        .collect()
}

fn numbers(text: &str) -> Vec<u32> {
    if text == "-" {
        vec![]
    } else {
        text.split(',').map(|x| x.parse().unwrap()).collect()
    }
}

#[test]
fn original_x86_primitive_readers() {
    let fixtures =
        include_str!("../../../runs/016-original-support-assembly/primitive-fixtures.tsv");
    let mut count = 0;
    for line in fixtures.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        assert_eq!(c.len(), 14);
        let payload = hex(c[1]);
        let primitive = OriginalPrimitive::new(&payload).unwrap();
        assert_eq!(
            primitive.vertex_count(),
            c[8].parse::<u32>().unwrap(),
            "{}",
            c[0]
        );
        assert_eq!(
            primitive.polygon_count(c[2].parse().unwrap()),
            c[9].parse::<u32>().unwrap(),
            "{}",
            c[0]
        );
        let descriptor = primitive
            .descriptor(c[6].parse().unwrap(), c[7].parse().unwrap())
            .unwrap();
        let expected = if c[10] == "-" {
            None
        } else {
            Some(c[10].parse::<usize>().unwrap())
        };
        assert_eq!(descriptor.map(|d| d.offset), expected, "{}", c[0]);
        let polygon = c[3].parse().unwrap();
        assert_eq!(
            primitive
                .indices(polygon, c[4].parse().unwrap(), c[5].parse().unwrap())
                .unwrap(),
            numbers(c[11]),
            "{}",
            c[0]
        );
        let (vt, df) = primitive.support_indices(polygon).unwrap();
        assert_eq!(vt, numbers(c[12]), "{} vt", c[0]);
        assert_eq!(df, numbers(c[13]), "{} df", c[0]);
        count += 1;
    }
    assert_eq!(count, 317);
}

#[test]
fn original_x86_selected_base_mask() {
    let fixtures = include_str!("../../../runs/016-original-support-assembly/base-fixtures.tsv");
    let mut count = 0;
    for line in fixtures.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        assert_eq!(c.len(), 9);
        let payload = hex(c[1]);
        let mask = SelectedBaseMask::from_payload(&payload).unwrap();
        assert_eq!(mask.is_none(), c[2] == "1", "{}", c[0]);
        if let Some(mask) = mask {
            assert_eq!(mask.ordinal, c[3].parse::<u32>().unwrap(), "{}", c[0]);
            assert_eq!(mask.static_enabled, c[5] == "1", "{}", c[0]);
            assert_eq!(
                mask.first_primitive,
                c[6].parse::<u16>().unwrap(),
                "{}",
                c[0]
            );
            assert_eq!(
                mask.last_primitive,
                c[7].parse::<u16>().unwrap(),
                "{}",
                c[0]
            );
            assert_eq!(
                mask.vertex_and_color_resource,
                c[8].parse::<u16>().unwrap(),
                "{}",
                c[0]
            );
        }
        count += 1;
    }
    assert_eq!(count, 60);
}

#[test]
fn original_x86_spatial_child_constructor() {
    let fixture =
        include_str!("../../../runs/016-original-support-assembly/insertion-child-fixtures.tsv");
    let mut count = 0;
    for line in fixture.lines().skip(1) {
        let c: Vec<u32> = line.split('\t').map(|x| x.parse().unwrap()).collect();
        assert_eq!(c.len(), 8);
        let child = SpatialNode::child(c[0], c[1]);
        assert_eq!(child.packed, c[2], "parent {:08x}, selector {}", c[0], c[1]);
        assert_eq!(&c[3..], &[0; 5]);
        assert_eq!(child.children, [None; 4]);
        assert!(!child.records_present);
        count += 1;
    }
    assert_eq!(count, 256);
}

#[test]
fn local_original_primitive_corpus() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../../local/game");
    if !root.join("GameData/Track").is_dir() {
        eprintln!("original track corpus unavailable; local census skipped");
        return;
    }
    let fixture = include_str!("../../../runs/016-original-support-assembly/primitive-census.tsv");
    let mut tracks = 0;
    for line in fixture.lines().skip(1) {
        let c: Vec<_> = line.split('\t').collect();
        let archive =
            nfs_formats::parse_track_crp(&std::fs::read(root.join(c[0])).unwrap()).unwrap();
        let mut histogram: BTreeMap<u16, usize> = BTreeMap::new();
        let mut bases = 0;
        for article in &archive.articles {
            for entry in &article.children {
                if entry.tag == "Base" {
                    SelectedBaseMask::from_payload(&entry.data).unwrap();
                    bases += 1;
                }
                if entry.tag != "pr" {
                    continue;
                }
                let kind = u16::from_le_bytes(entry.data[..2].try_into().unwrap());
                *histogram.entry(kind).or_default() += 1;
                let primitive = OriginalPrimitive::new(&entry.data).unwrap();
                let polygons = primitive.polygon_count(entry.count.try_into().unwrap());
                // Decode endpoints of every real pr, retaining original topology.
                // Selection and geometry bounds are not inferred from its index.
                if (polygons as i32) > 0 {
                    primitive.support_indices(0).unwrap();
                    primitive.support_indices(polygons - 1).unwrap();
                }
            }
        }
        assert_eq!(bases, c[1].parse::<usize>().unwrap(), "{}", c[0]);
        assert_eq!(
            histogram.values().sum::<usize>(),
            c[2].parse::<usize>().unwrap()
        );
        let expected: BTreeMap<u16, usize> = c[3]
            .split(',')
            .map(|pair| {
                let (kind, count) = pair.split_once(':').unwrap();
                (kind.parse().unwrap(), count.parse().unwrap())
            })
            .collect();
        assert_eq!(histogram, expected, "{}", c[0]);
        tracks += 1;
    }
    assert_eq!(tracks, 15);
}

#[test]
fn malformed_resources_are_rejected_without_fallbacks() {
    assert!(SelectedBaseMask::from_payload(&[]).is_err());
    let mut base = [0; 100];
    base[4..8].copy_from_slice(&3u32.to_le_bytes());
    assert!(SelectedBaseMask::from_payload(&base).is_err());
    let mut pr = [0; 64];
    pr[..4].copy_from_slice(&3u32.to_le_bytes());
    let primitive = OriginalPrimitive::new(&pr).unwrap();
    assert!(primitive.support_indices(0).is_err());
    assert!(primitive.indices(0, 0, 65534).is_err());
    pr[40..44].copy_from_slice(&2u32.to_le_bytes());
    assert!(OriginalPrimitive::new(&pr)
        .unwrap()
        .descriptor(0x76742020, 0)
        .is_err());
    pr[..4].copy_from_slice(&0xffffu32.to_le_bytes());
    assert!(OriginalPrimitive::new(&pr).is_err());
}
