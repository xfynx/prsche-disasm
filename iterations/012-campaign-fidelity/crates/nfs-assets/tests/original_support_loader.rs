use nfs_assets::physics::original_support::SupportVertices;
use nfs_assets::physics::original_support_loader::{
    assemble_initial_track_support, assemble_track_support, original_static_geometry_survives,
    SupportLoad,
};
use nfs_formats::{animdefs::AnimDefs, Entry, TrackCrp};

fn entry(tag: &str, index: u16, count: usize, data: Vec<u8>) -> Entry {
    Entry {
        tag: tag.into(),
        index,
        count,
        offset: 0,
        data,
        children: vec![],
    }
}

fn synthetic_track(vertex_count: usize, lifted_fourth: bool) -> TrackCrp {
    let mut base = vec![0; 0x70];
    base[0x64] = 1;
    let mut pr = vec![0; 0x50];
    let kind = if vertex_count == 4 { 4u32 } else { 3u32 };
    pr[0..4].copy_from_slice(&kind.to_le_bytes());
    pr[0x28..0x2c].copy_from_slice(&2u32.to_le_bytes());
    pr[0x30 + 0xa..0x30 + 0xc].copy_from_slice(&0u16.to_le_bytes());
    pr[0x30 + 0xe..0x30 + 0x10].copy_from_slice(&u16::MAX.to_le_bytes());
    pr[0x40 + 0xa..0x40 + 0xc].copy_from_slice(&3u16.to_le_bytes());
    pr[0x40 + 0xe..0x40 + 0x10].copy_from_slice(&u16::MAX.to_le_bytes());
    let points = [
        [0.0f32, 0.0, 0.0],
        [1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0],
        [1.0, if lifted_fourth { 0.2 } else { 0.0 }, 1.0],
    ];
    let mut vt = vec![0; vertex_count * 16];
    let mut df = vec![0; vertex_count * 4];
    for (i, point) in points[..vertex_count].iter().enumerate() {
        for (axis, value) in point.iter().enumerate() {
            vt[i * 16 + axis * 4..i * 16 + axis * 4 + 4].copy_from_slice(&value.to_le_bytes());
        }
        df[i * 4..i * 4 + 4].copy_from_slice(&0x00ff8040u32.to_le_bytes());
    }
    let article = Entry {
        tag: "Arti".into(),
        index: 0,
        count: 4,
        offset: 0,
        data: vec![],
        children: vec![
            entry("Base", 0, 1, base),
            entry("pr", 0, vertex_count, pr),
            entry("vt", 0, vertex_count, vt),
            entry("df", 0, vertex_count, df),
        ],
    };
    TrackCrp {
        articles: vec![article],
        misc: vec![entry("mt", 0, 1, 1u32.to_le_bytes().to_vec())],
        decoded_size: 0,
    }
}

#[test]
fn assembles_original_channel_words_and_preserves_source_identity() {
    let archive = synthetic_track(3, false);
    let result = assemble_track_support(&archive, &AnimDefs::default(), &[0]).unwrap();
    assert_eq!(result.polygons.len(), 1);
    assert_eq!(result.rejected_degenerate, 0);
    let source = &result.polygons[0];
    assert_eq!(
        (
            source.article_index,
            source.primitive_index,
            source.polygon_index
        ),
        (0, 0, 0)
    );
    assert_eq!(source.colors, [0x7e08; 3]);
    assert_eq!(source.polygon.flags_word_a, 1);
    assert!(matches!(
        source.polygon.vertices,
        SupportVertices::Triangle(_)
    ));
}

#[test]
fn quad_split_and_equal_xz_degeneracy_follow_loader_branches() {
    let archive = synthetic_track(4, true);
    let result = assemble_track_support(&archive, &AnimDefs::default(), &[0]).unwrap();
    assert_eq!(result.polygons.len(), 2);
    assert_eq!(result.polygons[0].colors, [0x7e08; 3]);
    assert_eq!(result.polygons[1].colors, [0x7e08; 3]);
    let mut archive = synthetic_track(3, false);
    for entry in &mut archive.articles[0].children {
        if entry.tag == "vt" {
            entry.data[16..20].copy_from_slice(&0.0f32.to_le_bytes());
            entry.data[32..36].copy_from_slice(&0.0f32.to_le_bytes());
            entry.data[40..44].copy_from_slice(&1.0f32.to_le_bytes());
        }
    }
    let result = assemble_track_support(&archive, &AnimDefs::default(), &[0]).unwrap();
    assert_eq!(result.polygons.len(), 0);
    assert_eq!(result.rejected_degenerate, 1);
}

#[test]
fn requires_explicit_ordinal_for_each_article() {
    let archive = synthetic_track(3, false);
    assert!(assemble_track_support(&archive, &AnimDefs::default(), &[]).is_err());
    let _ = SupportLoad::default();
}

#[test]
fn original_x86_degeneracy_branch_fixtures() {
    let fixtures =
        include_str!("../../../runs/018-original-support-runtime/support-loader-fixtures.tsv");
    let mut cases = 0;
    for line in fixtures.lines().skip(1) {
        let columns: Vec<_> = line.split('\t').collect();
        let vertices = columns[2].trim_start_matches('[').trim_end_matches(']');
        let points = vertices
            .split("],[")
            .map(|vertex| {
                let values: Vec<f32> = vertex
                    .trim_matches(&['[', ']'][..])
                    .split(',')
                    .map(|value| value.parse().unwrap())
                    .collect();
                [values[0], values[1], values[2]]
            })
            .collect::<Vec<_>>();
        assert_eq!(
            original_static_geometry_survives(&points).unwrap(),
            columns[3] == "1",
            "{}",
            columns[0]
        );
        cases += 1;
    }
    assert_eq!(cases, 9);
}

#[test]
fn shipped_alps_support_assembles_from_crp_channels() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../../../../local/game/GameData/Track");
    if !root.join("alps.crp").is_file() {
        eprintln!("local original corpus unavailable; alps assembly skipped");
        return;
    }
    let archive =
        nfs_formats::parse_track_crp(&std::fs::read(root.join("alps.crp")).unwrap()).unwrap();
    let anim = nfs_formats::animdefs::parse_animdefs(
        &std::fs::read_to_string(root.join("animdefs.txt")).unwrap(),
    )
    .unwrap();
    let assembled = assemble_initial_track_support(&archive, &anim).unwrap();
    assert!(!assembled.polygons.is_empty());
    let library_polygons = assembled
        .polygons
        .iter()
        .filter(|item| {
            let base = archive.articles[item.article_index]
                .find("Base", 0)
                .unwrap();
            u32::from_le_bytes(base.data[0..4].try_into().unwrap()) & 0x8000 != 0
        })
        .count();
    eprintln!(
        "alps: {} support polygons ({} library), {} special articles, {} degenerate",
        assembled.polygons.len(),
        library_polygons,
        assembled.skipped_special_articles,
        assembled.rejected_degenerate
    );
}

#[test]
fn shipped_tracks_library_articles_do_not_emit_static_support() {
    let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../../../../local/game/GameData/Track");
    if !root.join("animdefs.txt").is_file() {
        return;
    }
    let anim = nfs_formats::animdefs::parse_animdefs(
        &std::fs::read_to_string(root.join("animdefs.txt")).unwrap(),
    )
    .unwrap();
    let mut tracks = 0;
    let mut library_articles = 0;
    for path in std::fs::read_dir(&root)
        .unwrap()
        .map(|entry| entry.unwrap().path())
        .filter(|path| path.extension().is_some_and(|ext| ext == "crp"))
    {
        let archive = nfs_formats::parse_track_crp(&std::fs::read(&path).unwrap()).unwrap();
        let assembled = assemble_initial_track_support(&archive, &anim).unwrap();
        eprintln!(
            "{}: {} original type-1 polygons, {} library articles skipped",
            path.file_name().unwrap().to_string_lossy(),
            assembled.polygons.len(),
            assembled.skipped_library_articles
        );
        library_articles += assembled.skipped_library_articles;
        assert!(!assembled.polygons.is_empty(), "{}", path.display());
        for support in assembled.polygons {
            let base = archive.articles[support.article_index]
                .find("Base", 0)
                .unwrap();
            let flags = u32::from_le_bytes(base.data[0..4].try_into().unwrap());
            assert_eq!(
                flags & 0x8000,
                0,
                "{} emits library polygon",
                path.display()
            );
        }
        tracks += 1;
    }
    assert_eq!(tracks, 15);
    assert_eq!(library_articles, 1050);
}
