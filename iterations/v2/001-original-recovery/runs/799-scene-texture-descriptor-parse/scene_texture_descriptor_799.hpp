// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run799: scene texture descriptor parse & MIP shrink cluster:
//   0044d7e0..0044d991 (434B) scene_texture_descriptor_parse_0044d7e0
//   0044d710..0044d7cf (194B) scene_texture_descriptor_shrink_mip_0044d710
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned 32-byte .data format preference tables (0x005ce48c..0x005ce52b).
extern std::uint32_t scene_texture_format_prefs_0_005ce48c[8];
extern std::uint32_t scene_texture_format_prefs_1_005ce4ac[8];
extern std::uint32_t scene_texture_format_prefs_2_005ce4cc[8];
extern std::uint32_t scene_texture_format_prefs_3_005ce4ec[8];
extern std::uint32_t scene_texture_format_prefs_4_005ce50c[8];

// Matches exact typed child declaration in runs/791-scene-sky-texture-create/scene_sky_texture_791.hpp.
void* __fastcall scene_texture_descriptor_parse_0044d7e0(
    void* out_desc, void* unused_edx,
    const void* chunk, std::uint32_t mode, std::uint32_t fourcc);

void* __stdcall scene_texture_descriptor_shrink_mip_0044d710(const void* descriptor);

// Single typed child frontier reached by 0044d7e0 (005557d0..0055596e, 415B, __cdecl).
void* __cdecl scene_texture_descriptor_shrink_005557d0(const void* descriptor);

} // namespace porsche
