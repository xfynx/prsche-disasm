// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run885: scene_flare_ctor_0045d800 (777B) and closed setup/config/keyframe
// helpers (20 functions, 4,819B code, 0 new .bss cells).
#pragma once

#include <cstdint>

namespace porsche {

// External canonical callees and globals owned by prior recovered TUs (Run884).
extern const char* startup_resource_prefix_0065b30c;
void* __cdecl resource_open_0059d8e0(const char* name, std::uint32_t flags);
void* __cdecl resource_open_quiet_0059d9b0(const char* name, std::uint32_t flags);

// Retained multi-KB flare effect builders (typed opaque boundaries).
void* __fastcall scene_flare_final_effect_ctor_00459b50(
    void* self, void* unused_edx, void* sky, void* resource);
void* __fastcall scene_flare_effect_a_ctor_0045adf0(
    void* self, void* unused_edx, void* entry, void* sky,
    void* resource, std::uint8_t is_water);
void* __fastcall scene_flare_effect_b_ctor_0045b5a0(
    void* self, void* unused_edx, void* entry, void* sky,
    void* resource, std::uint32_t variant, std::uint8_t is_water);
void* __fastcall scene_flare_effect_c_ctor_0045bf80(
    void* self, void* unused_edx, void* entry, void* sky, void* resource);

// Recovered original functions (20 bodies, 4,819B).
void* __fastcall scene_flare_ctor_0045d800(
    void* self, void* unused_edx, const char* name);
void __cdecl scene_flare_resource_init_00459600(const char* name);
void* __fastcall scene_flare_resource_ctor_00459660(
    void* self, void* unused_edx, const char* name);
void __fastcall scene_flare_resource_upgrade_00459700(
    void* self, void* unused_edx, std::int32_t version);
void __cdecl scene_flare_aux_init_00459950();
void* __fastcall scene_flare_cursor_a_ctor_0045a2c0(
    void* self, void* unused_edx, void* keys, void* resource);
void* __fastcall scene_flare_cursor_b_ctor_0045a490(
    void* self, void* unused_edx, void* keys, void* resource);
void* __fastcall scene_flare_cursor_c_ctor_0045a970(
    void* self, void* unused_edx, void* keys, void* resource);
void* __fastcall scene_route_sky_aux_ctor_0045cb80(
    void* self, void* unused_edx, void* sky);
void __cdecl scene_route_sky_bytes_init_0045cc40(
    const char* name, void* sky, void* resource);
void* __fastcall scene_flare_cfg_entry_0045fb00(
    void* self, void* unused_edx, std::int32_t index);
std::int32_t __fastcall scene_flare_cfg_tokenize_0045fb10(
    void* self, void* unused_edx, char* begin, char* end);
void* __fastcall scene_flare_cfg_ctor_0045fb80(
    void* self, void* unused_edx, const char* name, std::int32_t weather_idx);
void __fastcall scene_flare_cfg_dtor_00460170(void* self, void* unused_edx);
void __cdecl scene_flare_pos_init_004601f0(void* resource);
void* __fastcall scene_flare_pos_ctor_00460780(
    void* self, void* unused_edx, void* resource);
void* __fastcall scene_sky_chunk_get_00460c70(
    void* self, void* unused_edx, std::int32_t index);
void __cdecl scene_flare_sun_dir_00461090(
    float x, float y, float turns, float elev, float scale,
    float* out_vec4, float radius);
double __cdecl math_fcos_tau_005327f0(float turns);
std::uint32_t __stdcall get_tick_count_0053bfd0();

} // namespace porsche
