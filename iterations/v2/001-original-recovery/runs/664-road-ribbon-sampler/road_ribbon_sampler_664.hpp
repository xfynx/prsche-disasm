// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/startup_sequence.hpp"

namespace porsche {

struct RoadRibbonPoint {
    float x;
    float y;
    float z;
    float w;
};
static_assert(sizeof(RoadRibbonPoint) == 16u, "RoadRibbonPoint must match 16-byte original stride");

// Shared loader-zero .data BSS global (`00628bc0`, 123 refs in references.jsonl):
// points to track road header (`+0x00`: int32 slice_count, `+0x0c`: slice array base).
extern void* track_road_data_00628bc0;

// Owned loader-zero .data BSS output table (`0060fde0..00610a5f`, 3,200 bytes):
// 200 sampled (x, y, z, 1.0f) ribbon points written exclusively by 00434aa0.
extern RoadRibbonPoint road_ribbon_points_0060fde0[200];

// Original 00532860..00532870 (17B, __cdecl, ret 0):
// Computes atan2(y, x) * 0.1591549515724182 (`0x005bb2c8`, ~1/(2*pi)) via x87 fpatan.
float __cdecl math_angle_turns_00532860(float y, float x);

// Original 00434aa0..00434d8d (750B, __cdecl, ret 0):
// Samples up to 200 curvature-spaced road ribbon points from track_road_data_00628bc0
// into road_ribbon_points_0060fde0 and tail-fills remaining slots with the last slice.
void __cdecl road_ribbon_sample_00434aa0();

// Original 00434a90..00434a94 (5B thunk jmp 0x00434aa0) is declared in
// porsche/startup_sequence.hpp as startup_sequence_call_00434a90().

} // namespace porsche
