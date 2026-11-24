// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run786: scene flare entry resolve & sky/chunk lookup cluster:
//   00452120..004521b9 (154B) scene_flare_entries_resolve_00452120
//   0045dd80..0045dd85 (  6B) scene_flare_table_get_0045dd80
//   0045cfb0..0045cfb5 (  6B) scene_route_sky_get_0045cfb0
//   00460b10..00460b4a ( 59B) scene_sky_find_tag_00460b10
//   00460b50..00460c51 (258B) scene_sky_find_name_00460b50
//   0053c680..0053c6be ( 63B) scene_chunk_find_tag_0053c680
//   00460c80..00460cc4 ( 69B) scene_sky_texture_get_00460c80
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned loader-zero .bss pointer cells.
extern void* scene_flare_table_00627e48;
extern void* scene_route_sky_00627e4c;

// Matches typed child declaration in runs/781-scene-stage-constructor/scene_stage_constructor_781.hpp.
void __fastcall scene_flare_entries_resolve_00452120(void* self, void* unused_edx);

void* __cdecl scene_flare_table_get_0045dd80();
void* __fastcall scene_route_sky_get_0045cfb0(void* unused_ecx, void* unused_edx);
std::int32_t __fastcall scene_sky_find_tag_00460b10(
    void* self, void* unused_edx, std::uint32_t tag);
std::int32_t __fastcall scene_sky_find_name_00460b50(
    void* self, void* unused_edx, const char* name);
void* __cdecl scene_chunk_find_tag_0053c680(const void* archive, const char* name);
void* __fastcall scene_sky_texture_get_00460c80(
    void* self, void* unused_edx, std::int32_t index);

// Single shared typed child frontier reached by 00460c80.
void* __cdecl scene_sky_texture_create_0044da10(
    const void* chunk, std::uint32_t tag, std::uint32_t mode,
    void* driver, std::uint32_t flags);

} // namespace porsche
