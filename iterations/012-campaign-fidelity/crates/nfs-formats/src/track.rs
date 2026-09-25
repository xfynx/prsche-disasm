//! Track CRP parser and data structures for Porsche Unleashed.
use crate::{bytes, decompress, entry, u32le, Entry, Result};

pub const TRACK_CRP_MAGIC: &[u8; 4] = b"karT";

#[derive(Debug)]
pub struct TrackCrp {
    pub articles: Vec<Entry>,
    pub misc: Vec<Entry>,
    pub decoded_size: usize,
}

/// Parse a track CRP archive. Validates RefPack/QFS compression and `karT` signature.
pub fn parse_track_crp(input: &[u8]) -> Result<TrackCrp> {
    let d = decompress(input)?;
    if bytes(&d, 0, 4)? != TRACK_CRP_MAGIC {
        return Err("offset 0x0: expected track CRP magic 'karT'".into());
    }
    let ac = (u32le(&d, 4)? >> 5) as usize;
    let mc = u32le(&d, 8)? as usize;
    let start = (u32le(&d, 12)? as usize)
        .checked_mul(16)
        .ok_or("table offset overflow")?;
    let total = ac.checked_add(mc).ok_or("table count overflow")?;
    bytes(
        &d,
        start,
        total.checked_mul(16).ok_or("table size overflow")?,
    )?;
    let mut articles = Vec::with_capacity(ac);
    let mut misc = Vec::with_capacity(mc);
    for i in 0..total {
        let e = entry(&d, start + i * 16, 0)?;
        if i < ac {
            if e.tag != "Arti" {
                return Err(format!(
                    "article table index {i} contains non-article tag '{}'",
                    e.tag
                ));
            }
            articles.push(e);
        } else {
            misc.push(e);
        }
    }
    Ok(TrackCrp {
        articles,
        misc,
        decoded_size: d.len(),
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bad_track_magic_rejected() {
        assert!(parse_track_crp(b"not a valid track crp").is_err());
        assert!(parse_track_crp(b" raC").is_err());
    }

    #[test]
    fn truncated_track_crp_rejected() {
        let short = b"karT";
        assert!(parse_track_crp(short).is_err());
    }

    #[test]
    fn local_skidpad_crp_parses() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../../local/game/GameData/Track/skidpad.crp");
        if let Ok(data) = std::fs::read(&path) {
            let crp = parse_track_crp(&data).unwrap();
            assert_eq!(crp.articles.len(), 276);
            assert_eq!(crp.misc.len(), 188);
            assert_eq!(crp.decoded_size, 2596864);
        }
    }

    #[test]
    fn local_skidpad_fsh_parses() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../../local/game/GameData/Track/skidpad.fsh");
        if let Ok(data) = std::fs::read(&path) {
            let images = crate::parse_fsh(&data).unwrap();
            assert_eq!(images.len(), 98);
            assert!(images.iter().any(|img| img.name == "rds7"));
            assert!(images.iter().any(|img| img.name == "tir1"));
        }
    }
}
