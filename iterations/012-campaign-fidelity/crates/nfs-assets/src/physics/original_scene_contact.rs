//! Scene-dependent preparation at Porsche.exe 0x494000..0x4940ae.
//! SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! Complete response replay: runs/019-original-contact-runtime. This API
//! requires original car fields; it does not infer them from the current solver.

use nfs_formats::Result;

use super::original_contact::{respond_prepared_contact, PreparedContact, PreparedContactState};
use super::original_support::SupportPolygon;
use super::original_support_owner::OriginalSupportOwner;
use super::original_support_tree::SupportTree;

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct SceneContactRequest {
    pub normal: [f32; 3],
    pub point: [f32; 3],
    pub displacement: [f32; 3],
    pub alternate_52c_mask_04: bool,
    pub angular_callback: bool,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct SceneContactResult {
    pub support: Option<usize>,
    pub prepared: PreparedContact,
    pub magnitude: f32,
}

/// 0x494000 copies the owner at car+8 and queries point+displacement with
/// caller flag zero. A miss suppresses correction, but does NOT suppress the
/// velocity response. Source 0x532b20 computes length; it does not normalize
/// displacement. Its unused return has no effect on this bounded finite API.
pub fn respond_scene_contact(
    state: &mut PreparedContactState,
    persistent_owner: &OriginalSupportOwner,
    tree: &SupportTree,
    polygons: &[SupportPolygon],
    request: SceneContactRequest,
) -> Result<SceneContactResult> {
    if request
        .normal
        .iter()
        .chain(&request.point)
        .chain(&request.displacement)
        .any(|value| !value.is_finite())
    {
        return Err("nonfinite contact outside proven scene response contract".into());
    }
    let query = std::array::from_fn(|axis| {
        (request.point[axis] as f64 + request.displacement[axis] as f64) as f32
    });
    // The source private 48-byte copy never changes the persistent owner.
    let mut local_owner = persistent_owner.clone();
    local_owner.select(tree, polygons, query, false)?;
    // Selection validity is the raw low nibble, independent of finite-plane
    // convenience return from OriginalSupportOwner::select.
    let support = local_owner.polygon.filter(|&index| {
        polygons
            .get(index)
            .is_some_and(|polygon| polygon.flags_word_a & 15 != 0)
    });
    let correction = std::array::from_fn(|axis| {
        let value = if support.is_some() {
            request.displacement[axis]
        } else {
            // 0x494065: scale the incoming NORMAL by zero, preserving signed
            // zeros. It is not a copy or scaling of the displacement.
            (request.normal[axis] as f64 * 0.0) as f32
        };
        (value as f64 * f32::from_bits(0x3f866666) as f64) as f32
    });
    let prepared = PreparedContact {
        normal: request.normal,
        correction,
        alternate_52c_mask_04: request.alternate_52c_mask_04,
        angular_callback: request.angular_callback,
    };
    let magnitude = respond_prepared_contact(state, prepared);
    Ok(SceneContactResult {
        support,
        prepared,
        magnitude,
    })
}
