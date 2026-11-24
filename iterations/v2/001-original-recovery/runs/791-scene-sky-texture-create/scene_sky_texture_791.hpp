// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run791: scene sky texture create cluster:
//   0044da10..0044db1f (272B) scene_sky_texture_create_0044da10
//   00536460..0053646a ( 11B) render_resource_node_prepare_00536460
//   00554950..0055495f ( 16B) render_texture_format_table_set_00554950
//   00555630..00555630 (  1B) render_texture_noop_00555630
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned 32-byte .data preference tables (0x005ce52c..0x005ce56b).
extern std::uint32_t scene_sky_format_prefs_a_005ce52c[8];
extern std::uint32_t scene_sky_format_prefs_b_005ce54c[8];

// Matches typed child declaration in runs/786-scene-flare-entries-resolve/scene_flare_resolve_786.hpp.
void* __cdecl scene_sky_texture_create_0044da10(
    const void* chunk, std::uint32_t tag, std::uint32_t mode,
    void* driver, std::uint32_t flags);

void __fastcall render_resource_node_prepare_00536460(void* self, void* unused_edx);
void __cdecl render_texture_format_table_set_00554950(
    std::uint32_t slot, std::uint32_t* table);
void __cdecl render_texture_noop_00555630(std::uint32_t value);

// Single typed child frontier reached by 0044da10 (0044d7e0..0044d991, 434B, __thiscall, RET 0x0c).
void* __fastcall scene_texture_descriptor_parse_0044d7e0(
    void* out_desc, void* unused_edx,
    const void* chunk, std::uint32_t mode, std::uint32_t fourcc);

} // namespace porsche
