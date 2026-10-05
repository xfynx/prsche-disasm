//! Original Base selection and primitive channel/index readers, outside gameplay.
//!
//! Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! Sources: 0x475152..0x475177, 0x47533a..0x475363,
//! 0x4754dd..0x475538, and 0x5a0b70..0x5a0ca9. See Run 016.
//! Special colliders, alternate primitives, degeneracy, and tree insertion are
//! not implemented here. Bounds errors replace invalid original memory access.

use nfs_formats::Result;

pub const VT_TAG: u32 = 0x76742020;
pub const DF_TAG: u32 = 0x64662020;
const TAGS: [u32; 7] = [
    VT_TAG, 0x6e6d2020, 0x75762020, DF_TAG, 0x42617365, 0x70722020, 0x65662020,
];
const VERTEX_COUNTS: [u32; 5] = [0, 3, 2, 3, 4];
const STEPS: [u32; 5] = [0, 1, 2, 3, 4];
const SHIFTS: [i32; 5] = [0, 0, 1, -1, 2];

fn word(data: &[u8], offset: usize) -> Result<u32> {
    let bytes = data
        .get(offset..offset.checked_add(4).ok_or("word offset overflow")?)
        .ok_or("original resource word outside payload")?;
    Ok(u32::from_le_bytes(bytes.try_into().unwrap()))
}

fn half_word(data: &[u8], offset: usize) -> Result<u16> {
    let bytes = data
        .get(offset..offset.checked_add(2).ok_or("word offset overflow")?)
        .ok_or("original resource half word outside payload")?;
    Ok(u16::from_le_bytes(bytes.try_into().unwrap()))
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct SelectedBaseMask {
    pub ordinal: u32,
    /// Only the first byte gates static primitives. Other bytes remain uninterpreted.
    pub static_enabled: bool,
    pub first_primitive: u16,
    pub last_primitive: u16,
    pub vertex_and_color_resource: u16,
}

impl SelectedBaseMask {
    /// Reads the CURRENT ordinal at Base+4; does not choose an ordinal from the
    /// count at +12 or assume that the raw file's initial ordinal stays zero.
    /// None is the early Base flags bit-0x40 branch, before special-collider lookup.
    /// static_enabled applies only AFTER that separate lookup has failed.
    pub fn from_payload(base: &[u8]) -> Result<Option<Self>> {
        let ordinal = word(base, 4)?;
        if base[0] & 0x40 != 0 {
            return Ok(None);
        }
        let offset = ordinal.wrapping_mul(12).wrapping_add(0x64) as usize;
        let mask = base
            .get(offset..offset.checked_add(12).ok_or("Base mask offset overflow")?)
            .ok_or("selected Base mask outside payload")?;
        Ok(Some(Self {
            ordinal,
            static_enabled: mask[0] != 0,
            first_primitive: half_word(mask, 4)?,
            last_primitive: half_word(mask, 6)?,
            vertex_and_color_resource: half_word(mask, 8)?,
        }))
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct ChannelDescriptor {
    pub offset: usize,
    pub byte_offset: u32,
    pub row: u16,
}

#[derive(Clone, Copy, Debug)]
pub struct OriginalPrimitive<'a> {
    payload: &'a [u8],
    kind: usize,
}

impl<'a> OriginalPrimitive<'a> {
    pub fn new(payload: &'a [u8]) -> Result<Self> {
        // The source sign-extends the low word. Only the five proven table
        // entries are admitted, rather than reading beyond those tables.
        let kind = word(payload, 0)? as u16 as i16;
        if !(0..=4).contains(&kind) {
            return Err(format!("unproven original primitive type {kind}"));
        }
        Ok(Self {
            payload,
            kind: kind as usize,
        })
    }

    pub fn vertex_count(self) -> u32 {
        VERTEX_COUNTS[self.kind]
    }

    /// Exact unsigned arithmetic of 0x5a0b80, including wraparound. A caller
    /// must validate resource bounds before iterating this returned count.
    pub fn polygon_count(self, total_indices: u32) -> u32 {
        let remaining = total_indices.wrapping_sub(self.vertex_count());
        let shift = SHIFTS[self.kind];
        if shift < 0 {
            (remaining / 3).wrapping_add(1)
        } else {
            (remaining >> shift).wrapping_add(1)
        }
    }

    pub fn descriptor(self, tag: u32, mut occurrence: u32) -> Result<Option<ChannelDescriptor>> {
        let count = word(self.payload, 0x28)? as usize;
        let end = count
            .checked_mul(16)
            .and_then(|bytes| bytes.checked_add(0x30))
            .ok_or("primitive descriptor extent overflow")?;
        if end > self.payload.len() {
            return Err("primitive descriptors outside payload".into());
        }
        for offset in (0x30..end).step_by(16) {
            let kind = half_word(self.payload, offset + 0xa)?;
            let actual_tag = if kind < 0x100 {
                *TAGS
                    .get(kind as usize)
                    .ok_or("descriptor uses unproven original tag table entry")?
            } else {
                ((kind as u32) << 16) | 0x2020
            };
            if actual_tag == tag {
                if occurrence == 0 {
                    return Ok(Some(ChannelDescriptor {
                        offset,
                        byte_offset: word(self.payload, offset + 4)?,
                        row: half_word(self.payload, offset + 0xe)?,
                    }));
                }
                occurrence -= 1;
            }
        }
        Ok(None)
    }

    /// 0x5a0bc0. A type-1 strip stays 012, 123, 234; no alternating winding.
    pub fn indices(self, polygon: u32, base: u32, row: u16) -> Result<Vec<u32>> {
        let step = STEPS[self.kind].wrapping_mul(polygon);
        let count = self.vertex_count();
        if row == u16::MAX {
            return Ok((0..count)
                .map(|i| base.wrapping_add(step).wrapping_add(i))
                .collect());
        }
        let descriptors = word(self.payload, 0x28)?;
        let rows = word(self.payload, 0x2c)?;
        let table_offset = (row as u32)
            .wrapping_add(descriptors.wrapping_mul(2))
            .wrapping_mul(8)
            .wrapping_add(0x34);
        let data_offset = rows
            .wrapping_add(descriptors.wrapping_mul(2))
            .wrapping_add(6)
            .wrapping_mul(8);
        let offset = word(self.payload, table_offset as usize)?
            .wrapping_add(data_offset)
            .wrapping_add(step) as usize;
        let bytes = self
            .payload
            .get(
                offset
                    ..offset
                        .checked_add(count as usize)
                        .ok_or("index extent overflow")?,
            )
            .ok_or("primitive indices outside payload")?;
        Ok(bytes
            .iter()
            .map(|byte| base.wrapping_add(*byte as u32))
            .collect())
    }

    /// Source support consumer selects occurrence zero of vt and df, using
    /// descriptor byte offsets >>4 and >>2 respectively. Missing channels
    /// return an error; no color or vertex index fallback is invented.
    pub fn support_indices(self, polygon: u32) -> Result<(Vec<u32>, Vec<u32>)> {
        let vt = self
            .descriptor(VT_TAG, 0)?
            .ok_or("support primitive lacks vt")?;
        let df = self
            .descriptor(DF_TAG, 0)?
            .ok_or("support primitive lacks df")?;
        Ok((
            self.indices(polygon, vt.byte_offset >> 4, vt.row)?,
            self.indices(polygon, df.byte_offset >> 2, df.row)?,
        ))
    }
}
