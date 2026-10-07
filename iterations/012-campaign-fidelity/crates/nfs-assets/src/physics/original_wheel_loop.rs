//! Original 0x499a70 through 0x499f16, before later force accumulation.
//! Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! Inputs retain source field names. No gameplay car-state mapping is implied.

use super::original_support::SupportPolygon;
use super::original_support_owner::OriginalSupportOwner;
use super::original_support_tree::SupportTree;
use super::original_wheel_state::{
    advance_material_height_unrounded, MaterialHeightState, MaterialRandomState,
};
use nfs_formats::Result;

#[derive(Clone, Copy, Debug, Default)]
pub struct FrontOffsetPart {
    pub kind_26: u16,
    pub weight_60: f32,
    pub mask_48: u16,
    pub bias_164: f32,
}

/// 0x493bc0: all twenty valid component pointers are supplied as records.
/// Only kinds 4/5/8 count. Masked modifier means, weighted contributions and
/// the final part mean stay unrounded until the caller's eventual f32 store.
pub fn front_offset(parts: &[FrontOffsetPart; 20], modifiers: &[f32; 10]) -> f64 {
    let mut sum = 0.0;
    let mut count = 0;
    for part in parts {
        if !matches!(part.kind_26, 4 | 5 | 8) {
            continue;
        }
        let weight = 1.5 - part.weight_60 as f64 * f32::from_bits(0x3ba3d70a) as f64;
        let mut masked_sum = 0.0;
        let mut masked_count = 0;
        for (i, modifier) in modifiers.iter().enumerate() {
            if part.mask_48 & (1 << i) != 0 {
                masked_sum += *modifier as f64;
                masked_count += 1;
            }
        }
        if masked_count > 1 {
            masked_sum /= masked_count as f64;
        }
        sum += masked_sum * weight + part.bias_164 as f64;
        count += 1;
    }
    if count > 1 {
        sum / count as f64
    } else {
        sum
    }
}

#[derive(Clone, Debug)]
pub struct WheelLoopInput {
    pub points_1dc: [[f32; 3]; 4],
    pub up_370: [f32; 3],
    pub reference_334: f32,
    pub ride_120: f32,
    pub limit_124: f32,
    pub fallback_normal_3e8: [f32; 3],
    pub fallback_base_400: [f32; 3],
    pub gate_3a0: f32,
    pub speed_35c: f32,
    pub quality_606ac4: i32,
    pub skip_657408: bool,
    pub car_dac: bool,
    pub remap_6573f8: bool,
    pub modifiers_4e4: [f32; 10],
    pub parts_768: [FrontOffsetPart; 20],
}

#[derive(Clone, Debug)]
pub struct WheelLoopState {
    pub owner: OriginalSupportOwner,
    pub compression_64: f32,
    pub angle_6c: f32,
    pub material: MaterialHeightState,
    pub flag_80: bool,
    pub phase_84: f32,
}

#[derive(Clone, Copy, Debug)]
pub struct WheelLoopSample {
    pub query: [f32; 3],
    pub point: [f32; 3],
    pub normal: [f32; 3],
    pub material_88: u16,
    pub selected: bool,
}

#[derive(Clone, Debug)]
pub struct WheelLoopResult {
    pub wheels: [WheelLoopSample; 4],
    /// The four locals at stack+0x9c, used by the later force loop.
    pub multipliers: [f32; 4],
    /// Stack+0x3c..0x44, before division by four at 0x499f16.
    pub sum: [f32; 3],
}

fn plane(query: [f32; 3], normal: [f32; 3], base: [f32; 3]) -> f64 {
    (-((query[0] as f64 - base[0] as f64) * normal[0] as f64)
        - (query[2] as f64 - base[2] as f64) * normal[2] as f64)
        / normal[1] as f64
        + base[1] as f64
}

/// Source geometry/cache selection, alternate plane, material RNG, front
/// offset and compression/angle transition. Later force/body callbacks and
/// source producers/cadence remain required before binding this to gameplay.
pub fn advance_wheel_loop(
    input: &WheelLoopInput,
    states: &mut [WheelLoopState; 4],
    rng: &mut MaterialRandomState,
    tree: &SupportTree,
    polygons: &[SupportPolygon],
) -> Result<WheelLoopResult> {
    let mut samples = Vec::with_capacity(4);
    let mut sum = [0.0f32; 3];
    let mut multipliers = [1.0; 4];
    for (i, state) in states.iter_mut().enumerate() {
        let mut query = input.points_1dc[i];
        query[1] = (query[1] as f64 + input.ride_120 as f64 * input.up_370[1] as f64) as f32;
        let hit = state.owner.select(tree, polygons, query, true)?;
        let flags = hit.map_or(0, |h| polygons[h.polygon].flags_word_a);
        let material = if input.remap_6573f8 && matches!(flags & 15, 1 | 10) {
            2
        } else {
            flags
        };
        let alternate = flags & 15 == 0
            || hit.is_some_and(|h| {
                (plane(query, h.normal, h.point) - input.reference_334 as f64).abs() > 4.0
            });
        let (normal, height) = if alternate {
            let normal = if input.fallback_normal_3e8[1] > f32::from_bits(0x3dcccccd) {
                input.fallback_normal_3e8
            } else {
                [0.0, 1.0, 0.0]
            };
            (normal, plane(query, normal, input.fallback_base_400) as f32)
        } else {
            let h = hit.ok_or("nonzero wheel material without original polygon")?;
            let base_height = plane(query, h.normal, h.point) as f32;
            let noise = advance_material_height_unrounded(
                &mut state.material,
                input.gate_3a0,
                input.speed_35c,
                material as u32,
                rng,
            );
            let mut height = (base_height as f64 + noise) as f32;
            if i < 2 {
                let angle =
                    (i as f64 * 0.5 + state.phase_84 as f64) * f32::from_bits(0x40c90fd0) as f64;
                height = (height as f64
                    + angle.sin()
                        * front_offset(&input.parts_768, &input.modifiers_4e4)
                        * f64::from_bits(0x3f45d867c3ece2a5)) as f32;
            }
            (h.normal, height)
        };
        let point = [query[0], height, query[2]];
        for axis in 0..3 {
            sum[axis] = (sum[axis] as f64 + point[axis] as f64) as f32;
        }
        if input.quality_606ac4 < 2 || (input.skip_657408 && input.car_dac) {
            state.compression_64 = 0.0;
            state.angle_6c = 0.0;
        } else {
            let delta: [f32; 3] =
                std::array::from_fn(|axis| (point[axis] as f64 - query[axis] as f64) as f32);
            let mut projection = (delta[0] as f64 * input.up_370[0] as f64
                + delta[1] as f64 * input.up_370[1] as f64)
                + delta[2] as f64 * input.up_370[2] as f64;
            if input.up_370[1] < f32::from_bits(0x3e99999a) {
                projection = f32::from_bits(0xbdcccccd) as f64;
            }
            if projection > 0.0 {
                let factor = if i < 2 {
                    f32::from_bits(0x3f666666)
                } else {
                    0.75
                };
                let ceiling = (input.limit_124 as f64 - input.ride_120 as f64) * factor as f64;
                if projection > 2.0 * ceiling {
                    multipliers[i] = 1.25;
                }
                projection = projection.min(ceiling as f32 as f64);
                state.compression_64 = projection as f32;
            } else {
                let factor = if state.flag_80 {
                    f32::from_bits(0xbfd33333)
                } else {
                    f32::from_bits(0xbfcccccd)
                };
                let floor = (input.limit_124 as f64 * factor as f64) as f32;
                projection = projection.max(floor as f64);
                state.compression_64 = ((projection + state.compression_64 as f64) * 0.5) as f32;
            }
            let mut argument = (input.ride_120 as f64 * f32::from_bits(0x3dcccccd) as f64) as f32;
            if projection > 0.0 {
                argument = (argument as f64
                    + state.compression_64 as f64 * f32::from_bits(0x3dcccccd) as f64)
                    as f32;
            }
            let angle = (argument as f64).asin();
            state.angle_6c = (if i == 1 || i == 3 { -angle } else { angle }) as f32;
        }
        samples.push(WheelLoopSample {
            query,
            point,
            normal,
            material_88: material,
            selected: hit.is_some(),
        });
    }
    Ok(WheelLoopResult {
        wheels: samples.try_into().expect("four original wheels"),
        multipliers,
        sum,
    })
}
