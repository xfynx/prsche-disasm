//! Original x86 pointer and flag consumer outputs, not inferred expectations.

use nfs_assets::physics::original_support_material::SupportMaterialTable;
use nfs_formats::Entry;
use std::collections::BTreeMap;
use std::path::Path;

const FIXTURES: &str =
    include_str!("../../../runs/015-original-support-loader/material-fixtures.tsv");

#[test]
fn original_x86_material_lookup() {
    let mut lines = FIXTURES.lines();
    assert_eq!(
        lines.next(),
        Some("flags\tindex\trelative\tcaller_flag\toriginal_flags\tpolygon_word\talternate")
    );
    let mut count = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 7);
        let raw: u32 = columns[0].parse().unwrap();
        let index: u16 = columns[1].parse().unwrap();
        // A different source cull word at +0xc prevents confusing it with
        // the support flag word at +0. The replay uses the same sentinel.
        let mut payload = vec![0; 0x138];
        payload[..4].copy_from_slice(&raw.to_le_bytes());
        payload[12..16].copy_from_slice(&0xa5a55a5au32.to_le_bytes());
        let entry = Entry {
            tag: "mt".into(),
            index,
            count: 1,
            offset: 0,
            data: payload,
            children: vec![],
        };
        let table = SupportMaterialTable::from_entries(&[entry]).unwrap();
        let mut primitive = [0; 8];
        primitive[4..8].copy_from_slice(&(0xbeef0000u32 | index as u32).to_le_bytes());
        let flags = table.for_primitive(&primitive).unwrap();
        let expected_raw: u32 = columns[4].parse().unwrap();
        let expected_polygon: u16 = columns[5].parse().unwrap();
        assert_eq!(flags.raw, expected_raw, "case {count}");
        assert_eq!(flags.polygon_word(), expected_polygon, "case {count}");
        assert_eq!(
            flags.requires_alternate_primitive(columns[3] == "1"),
            columns[6] == "1",
            "case {count}"
        );
        count += 1;
    }
    assert_eq!(count, 208);
}

#[test]
fn local_original_track_material_corpus() {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../../local/game");
    if !root.join("GameData/Track").is_dir() {
        eprintln!("original track material corpus unavailable; local test skipped");
        return;
    }
    let fixture = include_str!("../../../runs/015-original-support-loader/material-census.tsv");
    let mut lines = fixture.lines();
    assert_eq!(
        lines.next(),
        Some("path\tmaterial_count\ttable_size\toccupied\teffective_histogram")
    );
    let mut count = 0;
    for line in lines {
        let columns: Vec<_> = line.split('\t').collect();
        assert_eq!(columns.len(), 5);
        let input = std::fs::read(root.join(columns[0])).unwrap();
        let archive = nfs_formats::parse_track_crp(&input).unwrap();
        let table = SupportMaterialTable::from_entries(&archive.misc).unwrap();
        assert_eq!(
            archive
                .misc
                .iter()
                .filter(|entry| entry.tag == "mt")
                .count(),
            columns[1].parse::<usize>().unwrap(),
            "{} source entries",
            columns[0]
        );
        assert_eq!(table.entries.len(), columns[2].parse::<usize>().unwrap());
        let mut histogram: BTreeMap<u32, usize> = BTreeMap::new();
        for flags in table.entries.iter().flatten() {
            *histogram.entry(flags.raw).or_default() += 1;
        }
        assert_eq!(
            histogram.values().sum::<usize>(),
            columns[3].parse::<usize>().unwrap()
        );
        let expected: BTreeMap<u32, usize> = columns[4]
            .split(',')
            .map(|pair| {
                let (word, count) = pair.split_once(':').unwrap();
                (word.parse().unwrap(), count.parse().unwrap())
            })
            .collect();
        assert_eq!(histogram, expected, "{} effective table", columns[0]);
        count += 1;
    }
    assert_eq!(count, 15);
}
