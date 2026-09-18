//! Bounded, filesystem-free readers for Porsche Unleashed resources.
use std::collections::BTreeMap;

pub type Result<T> = std::result::Result<T, String>;
pub fn bytes(data: &[u8], offset: usize, length: usize) -> Result<&[u8]> {
    data.get(offset..offset.checked_add(length).ok_or("offset overflow")?)
        .ok_or_else(|| {
            format!(
                "offset 0x{offset:x}: need {length} bytes, file has {}",
                data.len()
            )
        })
}
pub fn u16le(d: &[u8], o: usize) -> Result<u16> {
    Ok(u16::from_le_bytes(bytes(d, o, 2)?.try_into().unwrap()))
}
pub fn u32le(d: &[u8], o: usize) -> Result<u32> {
    Ok(u32::from_le_bytes(bytes(d, o, 4)?.try_into().unwrap()))
}
pub fn f32le(d: &[u8], o: usize) -> Result<f32> {
    let f = f32::from_bits(u32le(d, o)?);
    if f.is_finite() {
        Ok(f)
    } else {
        Err(format!("offset 0x{o:x}: non-finite float"))
    }
}

/// EA RefPack, 24-bit length header used by the original car CRPs.
pub fn decompress(d: &[u8]) -> Result<Vec<u8>> {
    if !d.starts_with(&[0x10, 0xfb]) {
        return Ok(d.to_vec());
    }
    let h = bytes(d, 2, 3)?;
    let size = ((h[0] as usize) << 16) | ((h[1] as usize) << 8) | h[2] as usize;
    let mut out = Vec::with_capacity(size);
    let mut p = 5;
    loop {
        let c = bytes(d, p, 1)?[0] as usize;
        p += 1;
        let (literal, count, distance) = if c < 0x80 {
            let a = bytes(d, p, 1)?[0] as usize;
            p += 1;
            (c & 3, ((c >> 2) & 7) + 3, ((c >> 5) << 8) + a + 1)
        } else if c < 0xc0 {
            let ab = bytes(d, p, 2)?;
            p += 2;
            (
                (ab[0] >> 6) as usize,
                (c & 63) + 4,
                (((ab[0] & 63) as usize) << 8) + ab[1] as usize + 1,
            )
        } else if c < 0xe0 {
            let ab = bytes(d, p, 3)?;
            p += 3;
            (
                c & 3,
                ((c >> 2) & 3) * 256 + ab[2] as usize + 5,
                ((c & 16) << 12) + (ab[0] as usize) * 256 + ab[1] as usize + 1,
            )
        } else {
            (if c < 0xfc { (c & 31) * 4 + 4 } else { c & 3 }, 0, 0)
        };
        if out.len() + literal + count > size {
            return Err(format!("offset 0x{p:x}: decompressed size exceeded"));
        }
        out.extend_from_slice(bytes(d, p, literal)?);
        p += literal;
        if count > 0 {
            if distance > out.len() {
                return Err(format!(
                    "offset 0x{p:x}: invalid backward distance {distance}"
                ));
            }
            for _ in 0..count {
                let b = out[out.len() - distance];
                out.push(b);
            }
        }
        if c >= 0xfc {
            break;
        }
    }
    if out.len() != size {
        return Err(format!(
            "offset 0x{p:x}: expected {size} output bytes, got {}",
            out.len()
        ));
    }
    Ok(out)
}

#[derive(Debug, Clone)]
pub struct Entry {
    pub tag: String,
    pub index: u16,
    pub count: usize,
    pub offset: usize,
    pub data: Vec<u8>,
    pub children: Vec<Entry>,
}
impl Entry {
    pub fn find(&self, tag: &str, index: u16) -> Option<&Entry> {
        self.children
            .iter()
            .find(|e| e.tag == tag && e.index == index)
    }
}
fn entry(d: &[u8], o: usize, depth: usize) -> Result<Entry> {
    if depth > 1 {
        return Err(format!("offset 0x{o:x}: nested article depth exceeded"));
    }
    let id = u32le(d, o)?;
    let lf = u32le(d, o + 4)?;
    let len = (lf >> 8) as usize;
    let count = u32le(d, o + 8)? as usize;
    let rel = u32le(d, o + 12)? as usize;
    let indexed = lf & 1 != 0;
    let idbytes = if indexed {
        ((id >> 16) as u16).to_be_bytes().to_vec()
    } else {
        id.to_be_bytes().to_vec()
    };
    let tag = String::from_utf8_lossy(&idbytes).into_owned();
    let target = o
        .checked_add(if len == 0 {
            rel.checked_mul(16).ok_or("article offset overflow")?
        } else {
            rel
        })
        .ok_or("entry offset overflow")?;
    let mut e = Entry {
        tag,
        index: if indexed { id as u16 } else { 0 },
        count,
        offset: target,
        data: Vec::new(),
        children: Vec::new(),
    };
    if len == 0 {
        if e.tag != "Arti" {
            return Err(format!(
                "offset 0x{o:x}: unsupported zero-length entry {}",
                e.tag
            ));
        }
        bytes(
            d,
            target,
            count.checked_mul(16).ok_or("entry count overflow")?,
        )?;
        for i in 0..count {
            e.children.push(entry(d, target + i * 16, depth + 1)?);
        }
    } else {
        e.data = bytes(d, target, len)?.to_vec();
    }
    Ok(e)
}
#[derive(Debug)]
pub struct Crp {
    pub articles: Vec<Entry>,
    pub misc: Vec<Entry>,
    pub decoded_size: usize,
}
pub fn parse_crp(input: &[u8]) -> Result<Crp> {
    let d = decompress(input)?;
    if bytes(&d, 0, 4)? != b" raC" {
        return Err("offset 0x0: expected car CRP magic".into());
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
    let mut articles = Vec::new();
    let mut misc = Vec::new();
    for i in 0..total {
        let e = entry(&d, start + i * 16, 0)?;
        if i < ac {
            if e.tag != "Arti" {
                return Err("article table contains non-article".into());
            }
            articles.push(e);
        } else {
            misc.push(e);
        }
    }
    Ok(Crp {
        articles,
        misc,
        decoded_size: d.len(),
    })
}

#[derive(Debug, Clone)]
pub struct Image {
    pub name: String,
    pub width: u32,
    pub height: u32,
    pub x: u32,
    pub y: u32,
    pub rgba: Vec<u8>,
}
pub fn parse_fsh(input: &[u8]) -> Result<Vec<Image>> {
    let decoded = decompress(input)?;
    if bytes(&decoded, 0, 4)? != b"SHPI" {
        return Err("offset 0x0: expected SHPI FSH".into());
    }
    // The directory offsets are relative to the FSH, not to trailing data in a
    // surrounding container.  Restrict every read to the declared archive.
    let length = u32le(&decoded, 4)? as usize;
    let d = bytes(&decoded, 0, length)?;
    let n = u32le(d, 8)? as usize;
    bytes(d, 16, n.checked_mul(8).ok_or("FSH count overflow")?)?;
    let mut images = Vec::new();
    for i in 0..n {
        let name = String::from_utf8_lossy(bytes(d, 16 + i * 8, 4)?)
            .trim()
            .to_ascii_lowercase();
        let o = u32le(d, 20 + i * 8)? as usize;
        let code = u32le(d, o)?;
        let width = u16le(d, o + 4)? as u32;
        let height = u16le(d, o + 6)? as u32;
        if width == 0 || height == 0 || width > 4096 || height > 4096 {
            return Err(format!("offset 0x{o:x}: invalid image dimensions"));
        }
        let x = u16le(d, o + 12)? as u32;
        let y = u16le(d, o + 14)? as u32;
        let count = width
            .checked_mul(height)
            .ok_or_else(|| format!("offset 0x{o:x}: image pixel count overflow"))?
            as usize;
        let rgba_len = count
            .checked_mul(4)
            .ok_or_else(|| format!("offset 0x{o:x}: image byte count overflow"))?;
        let mut rgba = Vec::with_capacity(rgba_len);
        match code & 255 {
            0x7d => {
                for p in bytes(d, o + 16, rgba_len)?.as_chunks::<4>().0 {
                    rgba.extend_from_slice(&[p[2], p[1], p[0], p[3]]);
                }
            }
            0x7f => {
                for p in bytes(
                    d,
                    o + 16,
                    count.checked_mul(3).ok_or("FSH RGB byte count overflow")?,
                )?
                .as_chunks::<3>()
                .0
                {
                    rgba.extend_from_slice(&[p[2], p[1], p[0], 255]);
                }
            }
            0x7b => {
                let pixels = bytes(d, o + 16, count)?;
                let pal = o
                    .checked_add((code >> 8) as usize)
                    .ok_or("FSH palette offset overflow")?;
                if pal == o {
                    return Err(format!("offset 0x{o:x}: missing palette"));
                }
                let pc = u32le(d, pal)? & 255;
                let pn = u16le(d, pal + 4)? as usize;
                let stride = match pc {
                    0x2a => 4,
                    0x24 => 3,
                    0x29 | 0x2d => 2,
                    _ => return Err(format!("offset 0x{pal:x}: unsupported palette {pc:x}")),
                };
                let palette = bytes(
                    d,
                    pal + 16,
                    pn.checked_mul(stride).ok_or("FSH palette size overflow")?,
                )?;
                for &idx in pixels {
                    let p = bytes(palette, idx as usize * stride, stride)?;
                    let pixel = match pc {
                        0x2a => [p[2], p[1], p[0], p[3]],
                        0x24 => [p[2], p[1], p[0], 255],
                        _ => {
                            let v = u16::from_le_bytes([p[0], p[1]]);
                            if pc == 0x29 {
                                [
                                    (((v >> 11) & 31) * 255 / 31) as u8,
                                    (((v >> 5) & 63) * 255 / 63) as u8,
                                    ((v & 31) * 255 / 31) as u8,
                                    255,
                                ]
                            } else {
                                [
                                    (((v >> 10) & 31) * 255 / 31) as u8,
                                    (((v >> 5) & 31) * 255 / 31) as u8,
                                    ((v & 31) * 255 / 31) as u8,
                                    if v & 0x8000 != 0 { 255 } else { 0 },
                                ]
                            }
                        }
                    };
                    rgba.extend_from_slice(&pixel);
                }
            }
            f => {
                return Err(format!(
                    "offset 0x{o:x}: unsupported FSH pixel format 0x{f:x}"
                ))
            }
        }
        images.push(Image {
            name,
            width,
            height,
            x,
            y,
            rgba,
        });
    }
    Ok(images)
}

pub type Ini = BTreeMap<String, BTreeMap<String, String>>;
/// TPG repeats sections; later keys replace earlier keys while preserving others.
pub fn parse_ini(input: &[u8]) -> Result<Ini> {
    let text = std::str::from_utf8(input)
        .map_err(|e| format!("invalid INI text: {e}"))?
        .trim_start_matches('\u{feff}');
    let mut ini = Ini::new();
    let mut section = String::new();
    for (line_number, line) in text.lines().enumerate() {
        let line = line.trim();
        if line.is_empty() || line.starts_with(';') || line.starts_with('#') {
            continue;
        }
        if line.starts_with('[') {
            if !line.ends_with(']') {
                return Err(format!(
                    "INI line {}: unterminated section",
                    line_number + 1
                ));
            }
            section = line[1..line.len() - 1].trim().to_ascii_lowercase();
            if section.is_empty() {
                return Err(format!("INI line {}: empty section", line_number + 1));
            }
        } else if let Some((k, v)) = line.split_once('=') {
            let key = k.trim();
            if key.is_empty() {
                return Err(format!("INI line {}: empty key", line_number + 1));
            }
            ini.entry(section.clone())
                .or_default()
                .insert(key.to_ascii_lowercase(), v.trim().to_string());
        } else {
            return Err(format!(
                "INI line {}: expected section or key=value",
                line_number + 1
            ));
        }
    }
    Ok(ini)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn literal_and_overlap() {
        assert_eq!(
            decompress(&[0x10, 0xfb, 0, 0, 8, 0xe0, b'a', b'b', b'c', b'd', 4, 0, 0xfc]).unwrap(),
            b"abcddddd"
        );
    }
    #[test]
    fn terminal_literal() {
        assert_eq!(
            decompress(&[0x10, 0xfb, 0, 0, 3, 0xff, 1, 2, 3]).unwrap(),
            [1, 2, 3]
        );
    }
    #[test]
    fn invalid_streams() {
        for d in [
            vec![0x10, 0xfb],
            vec![0x10, 0xfb, 0, 0, 3, 0, 0],
            vec![0x10, 0xfb, 0, 0, 1, 0xfc],
            vec![0x10, 0xfb, 0, 0, 1, 0xe0, 1, 2, 3, 4],
        ] {
            assert!(decompress(&d).is_err());
        }
    }
    #[test]
    fn bad_crp() {
        assert!(parse_crp(b"anything").is_err());
        let mut d = b" raC".to_vec();
        d.extend_from_slice(&32u32.to_le_bytes());
        d.extend_from_slice(&0u32.to_le_bytes());
        d.extend_from_slice(&1u32.to_le_bytes());
        assert!(parse_crp(&d).is_err());
    }
    #[test]
    fn repeated_ini() {
        let i = parse_ini(b"[x]\na=1\nb=2\n[x]\na=3\n").unwrap();
        assert_eq!(i["x"]["a"], "3");
        assert_eq!(i["x"]["b"], "2");
    }
    #[test]
    fn fsh_truncated() {
        assert!(parse_fsh(b"SHPI").is_err());
    }
    #[test]
    fn fsh_rejects_directory_outside_declared_archive() {
        let mut d = b"SHPI".to_vec();
        d.extend_from_slice(&24u32.to_le_bytes());
        d.extend_from_slice(&1u32.to_le_bytes());
        d.extend_from_slice(&0u32.to_le_bytes());
        d.extend_from_slice(b"test");
        d.extend_from_slice(&24u32.to_le_bytes());
        d.extend_from_slice(&[
            0x7d, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255,
        ]);
        assert!(parse_fsh(&d).is_err());
    }
    #[test]
    fn malformed_ini_is_reported() {
        assert!(parse_ini(b"[broken\na=1\n").is_err());
        assert!(parse_ini(b"=x\n").is_err());
    }
    #[test]
    fn local_356_crps_have_known_shape() {
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/GameData/CarModel");
        for (car, articles, misc, decoded) in
            [("356a", 181, 87, 3_764_224), ("356b", 152, 72, 3_346_432)]
        {
            let path = root.join(format!("{car}.crp"));
            if !path.exists() {
                return;
            }
            let crp = parse_crp(&std::fs::read(&path).unwrap())
                .unwrap_or_else(|error| panic!("{}: {error}", path.display()));
            assert_eq!(
                (crp.articles.len(), crp.misc.len(), crp.decoded_size),
                (articles, misc, decoded)
            );
            assert!(crp
                .misc
                .iter()
                .any(|entry| entry.tag == "sf" && entry.index == 0));
            assert!(crp.misc.iter().any(|entry| entry.tag == "mt"));
        }
    }
}
