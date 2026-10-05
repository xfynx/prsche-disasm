//! Original support material lookup, outside the gameplay loop.
//!
//! `Porsche.exe` SHA256
//! `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
//! Loader `0x44aa22..0x44abf7` indexes mt entries and stores their payload
//! pointers; owner constructor `0x489160` retains the material container.
//! Consumer `0x475398..0x4753d2` selects primitive+4's low word and reads
//! mt payload+0. See `material-loader-source.jsonl` and Run 015 fixtures.

use nfs_formats::{Entry, Result};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct SupportMaterialFlags {
    /// Full source word; quad splitting tests all 32 bits, not only low 16.
    pub raw: u32,
}

impl SupportMaterialFlags {
    pub fn from_mt_payload(payload: &[u8]) -> Result<Self> {
        let bytes = payload
            .get(..4)
            .ok_or("mt payload lacks flags word at +0")?;
        Ok(Self {
            raw: u32::from_le_bytes(bytes.try_into().unwrap()),
        })
    }

    /// Constructors 0x4853c0/0x485c50 retain only the low word at polygon+0xa.
    pub fn polygon_word(self) -> u16 {
        self.raw as u16
    }

    /// Exact branch at 0x4753b6..0x4753d2. The caller flag's mode meaning and
    /// subsequent alternate-primitive lookup remain outside this API.
    pub fn requires_alternate_primitive(self, caller_flag: bool) -> bool {
        caller_flag && self.raw & 0xffffff0f == 0
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct SupportMaterialTable {
    /// Sparse original table: unassigned indices retain null slots.
    pub entries: Vec<Option<SupportMaterialFlags>>,
}

impl SupportMaterialTable {
    /// Supply parsed, indexed mt entries, as used by the current original
    /// track corpus. Duplicate indices are assigned in input order.
    /// Other misc resource types do not enter the original mt loop.
    pub fn from_entries(misc: &[Entry]) -> Result<Self> {
        let maximum = misc
            .iter()
            .filter(|entry| entry.tag == "mt")
            .map(|entry| entry.index)
            .max()
            .unwrap_or(0);
        let mut entries = vec![None; maximum as usize + 1];
        for entry in misc.iter().filter(|entry| entry.tag == "mt") {
            entries[entry.index as usize] =
                Some(SupportMaterialFlags::from_mt_payload(&entry.data)?);
        }
        Ok(Self { entries })
    }

    /// Validates buffer bounds and missing entries rather than reproducing
    /// invalid original memory access. No fallback material is invented.
    pub fn for_primitive(&self, primitive: &[u8]) -> Result<SupportMaterialFlags> {
        let bytes = primitive
            .get(4..6)
            .ok_or("primitive lacks material index at +4")?;
        let index = u16::from_le_bytes(bytes.try_into().unwrap()) as usize;
        self.entries
            .get(index)
            .copied()
            .flatten()
            .ok_or_else(|| format!("primitive references missing original mt index {index}"))
    }
}
