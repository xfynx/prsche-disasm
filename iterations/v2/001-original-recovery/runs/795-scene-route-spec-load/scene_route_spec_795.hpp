// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run795: scene route track-spec load & default init cluster:
//   00475c80..00475d61 (226B) scene_route_dispatch_00475c80
//   00475a60..00475c7b (540B) scene_route_track_spec_default_00475a60
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned loader-zero .bss cells (0x00628a18..0x00628b2f).
// Note: 0x00628a28 is offset +0x08 inside scene_route_track_spec_00628a20 and
// is also exported separately as startup_night_shape_enabled_00628a28 by Run649.
extern std::int32_t scene_route_spec_index_00628a18;
extern std::uint8_t scene_route_track_spec_00628a20[0x108u];
extern std::int32_t scene_route_spec_last_index_00628b28;
extern std::int32_t scene_route_spec_count_00628b2c;

// Matches exact accepted caller declaration in runs/702-entry-fe-scene-route-transfer-leaves/entry_fe_scene_leaves_702.hpp.
void __cdecl scene_route_dispatch_00475c80(std::uint32_t value);

void __cdecl scene_route_track_spec_default_00475a60(void* spec_out);

} // namespace porsche
