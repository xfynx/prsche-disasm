//! Bounded static support assembly from the original track resource consumer.
//!
//! Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39,
//! `0x4750b0` (notably `0x47533a..0x47591e`). The caller must supply the
//! current Base ordinal; its producer is not established by raw CRP contents.

use nfs_formats::{animdefs::AnimDefs, Entry, Result, TrackCrp};

use super::original_support::{split_quad_if_needed, SupportPolygon, SupportVertices};
use super::original_support_assembly::{OriginalPrimitive, SelectedBaseMask};
use super::original_support_material::SupportMaterialTable;

#[derive(Clone, Debug)]
pub struct AssembledSupport {
    pub polygon: SupportPolygon,
    pub colors: Vec<u16>,
    pub article_index: usize,
    pub primitive_index: u16,
    pub polygon_index: u32,
}

#[derive(Default, Debug)]
pub struct SupportLoad {
    pub polygons: Vec<AssembledSupport>,
    pub skipped_library_articles: usize,
    pub skipped_special_articles: usize,
    pub skipped_disabled_articles: usize,
    pub rejected_degenerate: usize,
}

fn word(bytes: &[u8], offset: usize) -> Result<u32> {
    let value = bytes
        .get(offset..offset.checked_add(4).ok_or("support offset overflow")?)
        .ok_or("support channel index outside resource")?;
    Ok(u32::from_le_bytes(value.try_into().unwrap()))
}

fn vertex(bytes: &[u8], index: u32) -> Result<[f32; 3]> {
    let start = (index as usize)
        .checked_mul(16)
        .ok_or("support vertex offset overflow")?;
    Ok([
        f32::from_bits(word(bytes, start)?),
        f32::from_bits(word(bytes, start + 4)?),
        f32::from_bits(word(bytes, start + 8)?),
    ])
}

fn color(bytes: &[u8], index: u32) -> Result<u16> {
    let offset = (index as usize)
        .checked_mul(4)
        .ok_or("support color offset overflow")?;
    let bgra = word(bytes, offset)?;
    // 0x475574..0x47559d: bytes +2,+1,+0, each shifted right by three.
    Ok(((((bgra >> 16) & 0xff) >> 3) << 10
        | (((bgra >> 8) & 0xff) >> 3) << 5
        | ((bgra & 0xff) >> 3)) as u16)
}

fn equal_xyz(a: [f32; 3], b: [f32; 3]) -> bool {
    a == b
}

fn degenerate(points: &[[f32; 3]]) -> bool {
    // 0x4755ae..0x4755e8 checks X/Z of the first three. The triangle
    // branch then checks all three pairwise XYZ equalities at 0x475795.
    let all_xz = points[..3]
        .iter()
        .all(|point| point[0] == points[0][0] && point[2] == points[0][2]);
    if all_xz {
        return true;
    }
    points.len() == 3
        && (equal_xyz(points[0], points[1])
            || equal_xyz(points[0], points[2])
            || equal_xyz(points[1], points[2]))
}

/// Decision at `0x4755ae..0x47580a` for finite 3/4-vertex records.
pub fn original_static_geometry_survives(points: &[[f32; 3]]) -> Result<bool> {
    if !matches!(points.len(), 3 | 4) || points.iter().flatten().any(|v| !v.is_finite()) {
        return Err("support degeneracy requires finite triangle or quad".into());
    }
    Ok(!degenerate(points))
}

fn selected_channel<'a>(article: &'a Entry, tag: &str, index: u16) -> Option<&'a Entry> {
    if index == u16::MAX {
        article
            .children
            .iter()
            .find(|entry| entry.tag == tag && entry.index == 0)
    } else {
        article.find(tag, index)
    }
}

/// Assemble one source article. `ordinal` is the scene's CURRENT Base+4 value.
/// `AnimDefs` preserves `animdefs.txt` ANIM order; an unmatched nonzero tag
/// falls back to its first entry in `0x47ed90`.
pub fn assemble_article(
    article_index: usize,
    article: &Entry,
    materials: &SupportMaterialTable,
    anim: &AnimDefs,
    ordinal: u32,
    caller_flag: bool,
    output: &mut SupportLoad,
) -> Result<()> {
    let base = article
        .children
        .iter()
        .find(|entry| entry.tag == "Base")
        .ok_or("support article lacks Base")?;
    let mut selected = base.data.clone();
    selected
        .get_mut(4..8)
        .ok_or("Base lacks current ordinal")?
        .copy_from_slice(&ordinal.to_le_bytes());
    let Some(mask) = SelectedBaseMask::from_payload(&selected)? else {
        output.skipped_disabled_articles += 1;
        return Ok(());
    };
    let tag = word(&base.data, 0x44)?;
    if matches!(
        anim.find_tag_or_first(tag).map(|entry| entry.collide_type),
        Some(1 | 2)
    ) {
        output.skipped_special_articles += 1;
        return Ok(());
    }
    if !mask.static_enabled {
        output.skipped_disabled_articles += 1;
        return Ok(());
    }
    let vt = selected_channel(article, "vt", mask.vertex_and_color_resource)
        .ok_or("selected support vt missing")?;
    let df = selected_channel(article, "df", mask.vertex_and_color_resource)
        .ok_or("selected support df missing")?;
    // 0x43cd50/0x59f700 select the first `pr` at or after the low ID and
    // within the upper bound. Both ordinary advance at 0x47591e and the
    // alternate advance at 0x4510f0 then require next ID < upper bound.
    let mut candidates = article.children.iter().filter(|entry| entry.tag == "pr");
    let Some(mut entry) = candidates
        .find(|entry| entry.index >= mask.first_primitive && entry.index <= mask.last_primitive)
    else {
        return Ok(());
    };
    loop {
        let primitive_index = entry.index;
        let primitive = OriginalPrimitive::new(&entry.data)?;
        let vertex_count = primitive.vertex_count() as usize;
        if vertex_count != 3 && vertex_count != 4 {
            return Err(format!(
                "unproven support primitive vertex count {vertex_count}"
            ));
        }
        let material = materials.for_primitive(&entry.data)?;
        if material.requires_alternate_primitive(caller_flag) {
            // The retained owner+0x24 pass invokes 0x4750b0 with caller flag
            // one. `0x4510f0` advances the current pr iterator and skips this
            // geometry when the original material predicate is satisfied.
            match candidates
                .next()
                .filter(|next| next.index < mask.last_primitive)
            {
                Some(next) => {
                    entry = next;
                    continue;
                }
                None => break,
            }
        }
        let total = u32::try_from(entry.count).map_err(|_| "pr count exceeds u32")?;
        if total < vertex_count as u32 {
            return Err("pr index count below support vertex count".into());
        }
        let count = primitive.polygon_count(total);
        // Original loop compares the signed count. Malformed wrapping lengths
        // are rejected by indexed channel bounds before any allocation.
        if (count as i32) <= 0 {
            match candidates
                .next()
                .filter(|next| next.index < mask.last_primitive)
            {
                Some(next) => {
                    entry = next;
                    continue;
                }
                None => break,
            }
        }
        for polygon_index in 0..count {
            let (vt_indices, df_indices) = primitive.support_indices(polygon_index)?;
            let points = vt_indices
                .into_iter()
                .map(|index| vertex(&vt.data, index))
                .collect::<Result<Vec<_>>>()?;
            let colors = df_indices
                .into_iter()
                .map(|index| color(&df.data, index))
                .collect::<Result<Vec<_>>>()?;
            if !original_static_geometry_survives(&points)? {
                output.rejected_degenerate += 1;
                continue;
            }
            let shapes = if vertex_count == 3 {
                vec![SupportVertices::Triangle(
                    points.as_slice().try_into().unwrap(),
                )]
            } else {
                split_quad_if_needed(points.as_slice().try_into().unwrap(), material.raw)
            };
            for (piece, shape) in shapes.into_iter().enumerate() {
                let piece_colors =
                    if vertex_count == 4 && matches!(&shape, SupportVertices::Triangle(_)) {
                        if piece == 0 {
                            vec![colors[0], colors[1], colors[2]]
                        } else {
                            vec![colors[0], colors[2], colors[3]]
                        }
                    } else {
                        colors.clone()
                    };
                output.polygons.push(AssembledSupport {
                    polygon: SupportPolygon::new(shape, material.polygon_word()),
                    colors: piece_colors,
                    article_index,
                    primitive_index,
                    polygon_index,
                });
            }
        }
        match candidates
            .next()
            .filter(|next| next.index < mask.last_primitive)
        {
            Some(next) => entry = next,
            None => break,
        }
    }
    Ok(())
}

/// `ordinals` is indexed by article position and supplied by scene state.
pub fn assemble_track_support(
    archive: &TrackCrp,
    anim: &AnimDefs,
    ordinals: &[u32],
) -> Result<SupportLoad> {
    if archive.articles.len() != ordinals.len() {
        return Err("current Base ordinal missing for one or more articles".into());
    }
    let materials = SupportMaterialTable::from_entries(&archive.misc)?;
    let mut output = SupportLoad::default();
    for (index, (article, ordinal)) in archive.articles.iter().zip(ordinals).enumerate() {
        let base = article
            .children
            .iter()
            .find(|entry| entry.tag == "Base")
            .ok_or("support article lacks Base")?;
        // `0x4781a0` puts Base bit 0x8000 in the library/prop group; only
        // clear-bit articles enter the ordinary +0x18 group.
        if word(&base.data, 0)? & 0x8000 != 0 {
            output.skipped_library_articles += 1;
            continue;
        }
        assemble_article(
            index,
            article,
            &materials,
            anim,
            *ordinal,
            true,
            &mut output,
        )?;
    }
    Ok(output)
}

/// Initial scene assembly input: the Base payload's stored `+4` word.
/// `0x475152` consumes this word directly through `0x43c6d0`; no alternate
/// LOD is selected inside `0x4750b0`. This reconstructs the retained flag-1
/// build at `0x48839f`, not later mutable scene LOD transitions.
pub fn assemble_initial_track_support(archive: &TrackCrp, anim: &AnimDefs) -> Result<SupportLoad> {
    let ordinals = archive
        .articles
        .iter()
        .map(|article| {
            let base = article
                .children
                .iter()
                .find(|entry| entry.tag == "Base")
                .ok_or("support article lacks Base")?;
            word(&base.data, 4)
        })
        .collect::<Result<Vec<_>>>()?;
    assemble_track_support(archive, anim, &ordinals)
}
