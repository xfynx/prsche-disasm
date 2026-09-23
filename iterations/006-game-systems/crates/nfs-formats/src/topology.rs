//! Track topology parsers for Porsche Unleashed:
//! - `.jnc` (junctions and branch weights)
//! - `.edg` (road boundary edges and surface flags)
//! - `.map` (sections, slice ranges, texture mappings and lighting)

use crate::{f32le, parse_ini, u32le, Result};
use std::collections::BTreeMap;

/// A single junction record in a `.jnc` file (36 bytes).
#[derive(Debug, Clone, PartialEq)]
pub struct JunctionRecord {
    pub index: u32,
    pub weights: [f32; 8],
}

/// Collection of junctions parsed from a `.jnc` file.
#[derive(Debug, Clone, PartialEq)]
pub struct Junctions {
    pub records: Vec<JunctionRecord>,
}

/// Parse a `.jnc` file containing 36-byte junction records.
pub fn parse_jnc(input: &[u8]) -> Result<Junctions> {
    if !input.len().is_multiple_of(36) {
        return Err(format!(
            "invalid .jnc size {}: must be a multiple of 36 bytes",
            input.len()
        ));
    }
    let count = input.len() / 36;
    let mut records = Vec::with_capacity(count);
    for i in 0..count {
        let off = i * 36;
        let index = u32le(input, off)?;
        let mut weights = [0.0f32; 8];
        for (w, item) in weights.iter_mut().enumerate() {
            *item = f32le(input, off + 4 + w * 4)?;
        }
        records.push(JunctionRecord { index, weights });
    }
    Ok(Junctions { records })
}

/// A 3D road edge segment from an `.edg` file (28 bytes).
#[derive(Debug, Clone, PartialEq)]
pub struct EdgeSegment {
    pub flags: u8,
    pub p1: [f32; 3],
    pub p2: [f32; 3],
}

/// Collection of road boundary segments parsed from an `.edg` file.
#[derive(Debug, Clone, PartialEq)]
pub struct RoadEdges {
    pub header: u32,
    pub segments: Vec<EdgeSegment>,
}

/// Parse an `.edg` file containing an 8-byte header and 28-byte edge records.
pub fn parse_edg(input: &[u8]) -> Result<RoadEdges> {
    if input.len() < 4 {
        return Err(format!(
            "invalid .edg size {}: minimum size is 4 bytes",
            input.len()
        ));
    }
    let data_len = input.len() - 4;
    if !data_len.is_multiple_of(28) {
        return Err(format!(
            "invalid .edg payload size {}: must be a multiple of 28 bytes",
            data_len
        ));
    }
    let header = u32le(input, 0)?;
    let count = data_len / 28;
    let mut segments = Vec::with_capacity(count);
    for i in 0..count {
        let off = 4 + i * 28;
        let flags = input[off];
        let p1 = [
            f32le(input, off + 4)?,
            f32le(input, off + 8)?,
            f32le(input, off + 12)?,
        ];
        let p2 = [
            f32le(input, off + 16)?,
            f32le(input, off + 20)?,
            f32le(input, off + 24)?,
        ];
        segments.push(EdgeSegment { flags, p1, p2 });
    }
    Ok(RoadEdges { header, segments })
}

fn parse_4_floats(s: &str) -> [f32; 4] {
    let mut res = [1.0f32; 4];
    for (i, part) in s.split(',').enumerate() {
        if i >= 4 {
            break;
        }
        if let Ok(val) = part.trim().parse::<f32>() {
            res[i] = val;
        }
    }
    res
}

/// Track global lighting parameters from the `[header]` section of a `.map` file.
#[derive(Debug, Clone, PartialEq)]
pub struct MapHeader {
    pub count: usize,
    pub tint: [f32; 4],
    pub ambient: [f32; 4],
    pub interior: [f32; 4],
    pub lightdecal: [f32; 4],
    pub interiordiffuse: [f32; 4],
}

impl Default for MapHeader {
    fn default() -> Self {
        Self {
            count: 0,
            tint: [1.0; 4],
            ambient: [1.0; 4],
            interior: [1.0; 4],
            lightdecal: [1.0; 4],
            interiordiffuse: [1.0; 4],
        }
    }
}

/// A slice range section from a `.map` file.
#[derive(Debug, Clone, PartialEq)]
pub struct MapSection {
    pub index: usize,
    pub startslice: u32,
    pub endslice: u32,
    pub texturesize: f32,
    pub aspect: f32,
    pub properties: BTreeMap<String, String>,
}

/// Parsed `.map` track section and mapping configuration.
#[derive(Debug, Clone, PartialEq)]
pub struct TrackMap {
    pub header: MapHeader,
    pub sections: Vec<MapSection>,
}

/// Parse a `.map` INI-format file.
pub fn parse_map(input: &[u8]) -> Result<TrackMap> {
    let ini = parse_ini(input)?;
    let mut header = MapHeader::default();

    if let Some(hdr) = ini.get("header") {
        if let Some(c) = hdr.get("count") {
            header.count = c.parse().unwrap_or(0);
        }
        if let Some(t) = hdr.get("tint") {
            header.tint = parse_4_floats(t);
        }
        if let Some(a) = hdr.get("ambient") {
            header.ambient = parse_4_floats(a);
        }
        if let Some(i) = hdr.get("interior") {
            header.interior = parse_4_floats(i);
        }
        if let Some(l) = hdr.get("lightdecal") {
            header.lightdecal = parse_4_floats(l);
        }
        if let Some(id) = hdr.get("interiordiffuse") {
            header.interiordiffuse = parse_4_floats(id);
        }
    }

    let mut sections = Vec::new();
    let mut s_idx = 0;
    while let Some(sec) = ini.get(&format!("section{s_idx}")) {
        let startslice = sec
            .get("startslice")
            .and_then(|v| v.parse().ok())
            .unwrap_or(0);
        let endslice = sec
            .get("endslice")
            .and_then(|v| v.parse().ok())
            .unwrap_or(0);
        let texturesize = sec
            .get("texturesize")
            .and_then(|v| v.parse().ok())
            .unwrap_or(6.0);
        let aspect = sec
            .get("aspect")
            .and_then(|v| v.parse().ok())
            .unwrap_or(1.0);

        sections.push(MapSection {
            index: s_idx,
            startslice,
            endslice,
            texturesize,
            aspect,
            properties: sec.clone(),
        });
        s_idx += 1;
    }

    Ok(TrackMap { header, sections })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn invalid_jnc_size_rejected() {
        assert!(parse_jnc(&[0; 35]).is_err());
        assert!(parse_jnc(&[0; 37]).is_err());
    }

    #[test]
    fn valid_jnc_parses() {
        let mut data = vec![0u8; 72];
        data[0..4].copy_from_slice(&0u32.to_le_bytes());
        data[4..8].copy_from_slice(&1.0f32.to_le_bytes());
        data[36..40].copy_from_slice(&1u32.to_le_bytes());
        data[40..44].copy_from_slice(&0.85f32.to_le_bytes());

        let jnc = parse_jnc(&data).unwrap();
        assert_eq!(jnc.records.len(), 2);
        assert_eq!(jnc.records[0].index, 0);
        assert_eq!(jnc.records[0].weights[0], 1.0);
        assert_eq!(jnc.records[1].index, 1);
        assert_eq!(jnc.records[1].weights[0], 0.85);
    }

    #[test]
    fn invalid_edg_size_rejected() {
        assert!(parse_edg(&[0; 3]).is_err());
        assert!(parse_edg(&[0; 31]).is_err());
    }

    #[test]
    fn valid_edg_parses() {
        let mut data = vec![0u8; 32];
        data[0..4].copy_from_slice(&0x3235u32.to_le_bytes());
        data[4] = 0x10; // flags
        data[8..12].copy_from_slice(&10.0f32.to_le_bytes()); // p1.x
        data[12..16].copy_from_slice(&3.0f32.to_le_bytes()); // p1.y
        data[16..20].copy_from_slice(&20.0f32.to_le_bytes()); // p1.z
        data[20..24].copy_from_slice(&15.0f32.to_le_bytes()); // p2.x
        data[24..28].copy_from_slice(&3.0f32.to_le_bytes()); // p2.y
        data[28..32].copy_from_slice(&25.0f32.to_le_bytes()); // p2.z

        let edg = parse_edg(&data).unwrap();
        assert_eq!(edg.header, 0x3235);
        assert_eq!(edg.segments.len(), 1);
        assert_eq!(edg.segments[0].flags, 0x10);
        assert_eq!(edg.segments[0].p1, [10.0, 3.0, 20.0]);
        assert_eq!(edg.segments[0].p2, [15.0, 3.0, 25.0]);
    }

    #[test]
    fn valid_map_parses() {
        let text = b"[header]\ncount=1\ntint=1.0,0.5,0.5,1.0\nambient=0.2,0.2,0.2,1.0\n\n[section0]\nstartslice=0\nendslice=10\ntexturesize=5.0\naspect=0.5\ntexture1.open=12345\n";
        let map = parse_map(text).unwrap();
        assert_eq!(map.header.count, 1);
        assert_eq!(map.header.tint, [1.0, 0.5, 0.5, 1.0]);
        assert_eq!(map.header.ambient, [0.2, 0.2, 0.2, 1.0]);
        assert_eq!(map.sections.len(), 1);
        assert_eq!(map.sections[0].startslice, 0);
        assert_eq!(map.sections[0].endslice, 10);
        assert_eq!(map.sections[0].texturesize, 5.0);
        assert_eq!(map.sections[0].aspect, 0.5);
        assert_eq!(
            map.sections[0].properties.get("texture1.open").unwrap(),
            "12345"
        );
    }

    #[test]
    fn test_all_15_tracks_topology_parse() {
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../../local/game/GameData/Track");
        if !root.exists() {
            return;
        }

        let tracks = [
            "alps",
            "autobahn",
            "canyon",
            "castle",
            "coastal",
            "farmland",
            "foothills",
            "forest",
            "industrial",
            "monaco1",
            "monaco2",
            "monaco3",
            "monaco4",
            "monaco5",
            "skidpad",
        ];

        for t in &tracks {
            let jnc_path = root.join(format!("{t}.jnc"));
            let edg_path = root.join(format!("{t}.edg"));
            let map_path = root.join(format!("{t}.map"));

            if jnc_path.exists() {
                let data = std::fs::read(&jnc_path).unwrap();
                let jnc = parse_jnc(&data).unwrap();
                assert!(!jnc.records.is_empty(), "Track {t} .jnc is empty");
            }

            if edg_path.exists() {
                let data = std::fs::read(&edg_path).unwrap();
                let edg = parse_edg(&data).unwrap();
                assert!(!edg.segments.is_empty(), "Track {t} .edg is empty");
            }

            if map_path.exists() {
                let data = std::fs::read(&map_path).unwrap();
                let map = parse_map(&data).unwrap();
                assert!(!map.sections.is_empty(), "Track {t} .map has no sections");
            }
        }
    }
}
