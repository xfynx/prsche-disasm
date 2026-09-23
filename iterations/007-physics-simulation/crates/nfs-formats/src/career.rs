//! NFS5 career data formats: profile saves (.sav), car catalog (nfs5.car),
//! track catalog (nfs5.trk), and factory driver missions (nfs5.fac).
use crate::{bytes, u32le, Result};

pub const FACTORY_MISSION_REC_SIZE: usize = 240;
pub const FACTORY_MISSION_COUNT: usize = 34;
pub const CAR_CATALOG_REC_SIZE: usize = 1648;
pub const TRACK_CATALOG_REC_SIZE: usize = 1192;
pub const TRACK_CATALOG_COUNT: usize = 15;

/// Known top-level section in a profile save file (.sav).
#[derive(Debug, Clone, PartialEq)]
pub struct SaveSection {
    pub tag: String,
    pub offset: usize,
    pub payload: Vec<u8>,
}

/// Parsed player profile save file (.sav).
#[derive(Debug, Clone, PartialEq)]
pub struct SaveFile {
    /// Identified modular sections in the save file.
    pub sections: Vec<SaveSection>,
    /// Player cash / credits from PlayerInfo.
    pub cash: u32,
    /// Number of cars owned in player's garage.
    pub owned_cars_count: u32,
    /// Factory driver mission IDs parsed from Missions section.
    pub mission_codes: Vec<String>,
}

impl SaveFile {
    /// Find a section by its ASCII tag name.
    pub fn get_section(&self, tag: &str) -> Option<&[u8]> {
        self.sections
            .iter()
            .find(|s| s.tag == tag)
            .map(|s| s.payload.as_slice())
    }
}

/// Known registered section tags in nfs5.exe save linked list.
const REGISTERED_SAVE_TAGS: &[&str] = &[
    "Missions",
    "PartsMarket",
    "Tournament",
    "PlayerInfo",
    "TrackRecords",
    "UsedCarMarket",
    "Personalities",
    "Knockout",
    "CDPlayer",
];

/// Parse a profile `.sav` file into modular sections and player profile data.
pub fn parse_save(data: &[u8]) -> Result<SaveFile> {
    if data.len() < 32 {
        return Err(format!("save file too small: {} bytes", data.len()));
    }

    let mut found_sections = Vec::new();
    for &tag_name in REGISTERED_SAVE_TAGS {
        let tag_bytes = format!("{tag_name}\0").into_bytes();
        let mut pos = 0;
        while pos + tag_bytes.len() <= data.len() {
            if let Some(idx) = data[pos..]
                .windows(tag_bytes.len())
                .position(|w| w == tag_bytes)
            {
                let abs_idx = pos + idx;
                found_sections.push((abs_idx, tag_name.to_string(), tag_bytes.len()));
                pos = abs_idx + tag_bytes.len();
            } else {
                break;
            }
        }
    }

    found_sections.sort_by_key(|&(offset, _, _)| offset);

    let mut sections = Vec::new();
    for i in 0..found_sections.len() {
        let (start_offset, ref tag, header_len) = found_sections[i];
        let next_start = if i + 1 < found_sections.len() {
            found_sections[i + 1].0
        } else {
            data.len()
        };
        let payload_start = start_offset + header_len;
        let payload = if payload_start <= next_start {
            data[payload_start..next_start].to_vec()
        } else {
            Vec::new()
        };
        sections.push(SaveSection {
            tag: tag.clone(),
            offset: start_offset,
            payload,
        });
    }

    // Extract player credits and car count from PlayerInfo
    let mut cash = 0u32;
    let mut owned_cars_count = 0u32;
    if let Some(pi) = sections.iter().find(|s| s.tag == "PlayerInfo") {
        if pi.payload.len() >= 8 {
            owned_cars_count = u32le(&pi.payload, 0).unwrap_or(0);
            cash = u32le(&pi.payload, 4).unwrap_or(0);
        }
    }

    // Extract factory driver mission codes from Missions section
    let mut mission_codes = Vec::new();
    if let Some(m_sec) = sections.iter().find(|s| s.tag == "Missions") {
        // Payload starts with 4-byte size (8160) + header, missions start at offset 67
        for chunk in m_sec
            .payload
            .windows(FACTORY_MISSION_REC_SIZE)
            .step_by(FACTORY_MISSION_REC_SIZE)
        {
            // Find [0-9][mM][0-9]{2} in chunk
            for w in chunk.windows(4) {
                if (w[0].is_ascii_digit())
                    && (w[1] == b'm' || w[1] == b'M')
                    && (w[2].is_ascii_digit())
                    && (w[3].is_ascii_digit())
                {
                    if let Ok(code) = std::str::from_utf8(w) {
                        mission_codes.push(code.to_string());
                        break;
                    }
                }
            }
        }
    }

    Ok(SaveFile {
        sections,
        cash,
        owned_cars_count,
        mission_codes,
    })
}

/// Car entry from master vehicle specification catalog (`nfs5.car`).
#[derive(Debug, Clone, PartialEq)]
pub struct CarCatalogEntry {
    /// Human-readable car name (e.g. `'50 356 1100 Cabriolet`).
    pub display_name: String,
    /// Spec code identifier (e.g. `1950356Cabrio11`).
    pub spec_code: String,
    /// 3D model CRP name (e.g. `356_1`).
    pub model_name: String,
    /// Physics simulation file name without extension (e.g. `356cabrio11`).
    pub sim_name: String,
    /// Body style name (e.g. `Cabrio`).
    pub body_style: String,
}

/// Parse the master car catalog (`nfs5.car`).
pub fn parse_car_catalog(data: &[u8]) -> Result<Vec<CarCatalogEntry>> {
    if !data.len().is_multiple_of(CAR_CATALOG_REC_SIZE) {
        return Err(format!(
            "invalid nfs5.car size: {} is not a multiple of {CAR_CATALOG_REC_SIZE}",
            data.len()
        ));
    }

    let count = data.len() / CAR_CATALOG_REC_SIZE;
    let mut entries = Vec::with_capacity(count);

    for i in 0..count {
        let rec = bytes(data, i * CAR_CATALOG_REC_SIZE, CAR_CATALOG_REC_SIZE)?;

        fn extract_str(slice: &[u8]) -> String {
            let start = match slice.iter().position(|&b| b.is_ascii_graphic()) {
                Some(p) => p,
                None => return String::new(),
            };
            let end = slice[start..]
                .iter()
                .position(|&b| b == 0)
                .unwrap_or(slice.len() - start);
            String::from_utf8_lossy(&slice[start..start + end])
                .trim()
                .to_string()
        }

        let display_name = extract_str(&rec[0x000..0x034]);
        let spec_code = extract_str(&rec[0x048..0x07c]);
        let model_name = extract_str(&rec[0x07c..0x0b0]);
        let sim_name = extract_str(&rec[0x0b0..0x0e2]);
        let body_style = extract_str(&rec[0x1b0..0x1c2]);

        entries.push(CarCatalogEntry {
            display_name,
            spec_code,
            model_name,
            sim_name,
            body_style,
        });
    }

    Ok(entries)
}

/// Track entry from track catalog (`nfs5.trk`).
#[derive(Debug, Clone, PartialEq)]
pub struct TrackCatalogEntry {
    /// Internal track name (e.g. `coastal`, `skidpad`).
    pub internal_name: String,
    /// Track location description (e.g. `Alberta`).
    pub location: String,
}

/// Parse the track catalog (`nfs5.trk`).
pub fn parse_track_catalog(data: &[u8]) -> Result<Vec<TrackCatalogEntry>> {
    if !data.len().is_multiple_of(TRACK_CATALOG_REC_SIZE) {
        return Err(format!(
            "invalid nfs5.trk size: {} is not a multiple of {TRACK_CATALOG_REC_SIZE}",
            data.len()
        ));
    }

    let count = data.len() / TRACK_CATALOG_REC_SIZE;
    let mut entries = Vec::with_capacity(count);

    for i in 0..count {
        let rec = bytes(data, i * TRACK_CATALOG_REC_SIZE, TRACK_CATALOG_REC_SIZE)?;

        fn extract_str(slice: &[u8]) -> String {
            let start = match slice.iter().position(|&b| b.is_ascii_graphic()) {
                Some(p) => p,
                None => return String::new(),
            };
            let end = slice[start..]
                .iter()
                .position(|&b| b == 0)
                .unwrap_or(slice.len() - start);
            String::from_utf8_lossy(&slice[start..start + end])
                .trim()
                .to_string()
        }

        let internal_name = extract_str(&rec[0x008..0x030]);
        let location = extract_str(&rec[0x1b0..0x1c4]);

        entries.push(TrackCatalogEntry {
            internal_name,
            location,
        });
    }

    Ok(entries)
}

/// Factory driver mission template from `nfs5.fac`.
#[derive(Debug, Clone, PartialEq)]
pub struct FactoryMissionTemplate {
    /// Mission identifier (e.g. `0M01`, `1m01`).
    pub code: String,
    /// Numerical mission ID.
    pub id: u32,
}

/// Parse factory driver mission templates (`nfs5.fac`).
pub fn parse_factory_missions(data: &[u8]) -> Result<Vec<FactoryMissionTemplate>> {
    if !data.len().is_multiple_of(FACTORY_MISSION_REC_SIZE) {
        return Err(format!(
            "invalid nfs5.fac size: {} is not a multiple of {FACTORY_MISSION_REC_SIZE}",
            data.len()
        ));
    }

    let count = data.len() / FACTORY_MISSION_REC_SIZE;
    let mut missions = Vec::with_capacity(count);

    for i in 0..count {
        let rec = bytes(data, i * FACTORY_MISSION_REC_SIZE, FACTORY_MISSION_REC_SIZE)?;
        let id = u32le(rec, 0)?;

        let mut code = String::new();
        for w in rec.windows(4) {
            if (w[0].is_ascii_digit())
                && (w[1] == b'm' || w[1] == b'M')
                && (w[2].is_ascii_digit())
                && (w[3].is_ascii_digit())
            {
                if let Ok(c) = std::str::from_utf8(w) {
                    code = c.to_string();
                    break;
                }
            }
        }

        missions.push(FactoryMissionTemplate { code, id });
    }

    Ok(missions)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_local_save_files() {
        let savedata_dir = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/savedata");
        if !savedata_dir.exists() {
            return;
        }

        for save_name in ["0xfynx.sav", "XXDefXX.sav"] {
            let path = savedata_dir.join(save_name);
            if path.exists() {
                let data = std::fs::read(&path).unwrap();
                let save = parse_save(&data).unwrap();
                assert!(!save.sections.is_empty(), "sections empty in {save_name}");
                assert!(save.get_section("Missions").is_some());
                assert!(save.get_section("PlayerInfo").is_some());
                assert_eq!(save.mission_codes.len(), FACTORY_MISSION_COUNT);
                if save_name == "XXDefXX.sav" {
                    assert_eq!(save.cash, 11000); // Starting Evolution career credits
                    assert_eq!(save.owned_cars_count, 0);
                }
            }
        }
    }

    #[test]
    fn parse_local_car_catalog() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/FEData/Data/nfs5.car");
        if !path.exists() {
            return;
        }

        let data = std::fs::read(&path).unwrap();
        let catalog = parse_car_catalog(&data).unwrap();
        assert_eq!(catalog.len(), 109);
        assert!(catalog.iter().any(|c| c.model_name == "356_1"));
        assert!(catalog.iter().any(|c| c.sim_name == "356cabrio11"));
    }

    #[test]
    fn parse_local_track_catalog() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/FEData/Data/nfs5.trk");
        if !path.exists() {
            return;
        }

        let data = std::fs::read(&path).unwrap();
        let catalog = parse_track_catalog(&data).unwrap();
        assert_eq!(catalog.len(), TRACK_CATALOG_COUNT);
        assert!(catalog.iter().any(|t| t.internal_name == "coastal"));
    }

    #[test]
    fn parse_local_factory_missions() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/FEData/Data/nfs5.fac");
        if !path.exists() {
            return;
        }

        let data = std::fs::read(&path).unwrap();
        let missions = parse_factory_missions(&data).unwrap();
        assert_eq!(missions.len(), FACTORY_MISSION_COUNT);
        assert_eq!(missions[0].code, "0M01");
        assert_eq!(missions[1].code, "1m01");
    }
}
