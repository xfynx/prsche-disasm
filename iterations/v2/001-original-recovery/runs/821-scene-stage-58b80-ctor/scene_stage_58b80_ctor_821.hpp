// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run821: scene stage-58b80 constructor closure (16 functions, 3,677B code, 33B .data):
//   00458c90 (906B) scene_stage_58b80_ctor_00458c90
//   00456ed0 (354B) scene_particle_emitter_ctor_00456ed0
//   004577a0 (377B) scene_splt_emitter_ctor_004577a0
//   00457920 (1339B) scene_splt_quad_init_00457920
//   00456790 ( 62B) scene_particle_slot_init_00456790
//   004580e0 (109B) scene_splt_zero_tables_004580e0
//   00458150 ( 78B) scene_splt_init_uvs_00458150
//   005327d0 (  7B) math_fsqrt_005327d0
//   005327e0 ( 13B) math_fsin_tau_005327e0
//   00532880 ( 24B) vec3_cross_00532880
//   005328a0 ( 42B) vec3_cross_normalize_005328a0
//   005328d0 ( 50B) vec3_normalize_005328d0
//   0053c490 (145B) vec4_weighted_add_0053c490
//   0053c5d0 ( 63B) vec4_scale_0053c5d0
//   005561d0 ( 39B) rand_unit_005561d0
//   0056e8f5 ( 69B) vec3_cross_raw_0056e8f5
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned .data string at 0x005ceeb8..0x005ceed8 (33B, NUL-terminated).
// Four 4CC particle tags for snow ("0ons".."3ons") followed by four for rain ("0nar".."3nar").
extern const char scene_stage_particle_tags_005ceeb8[33];

// Matches accepted caller declaration in runs/700-scene-reset-leaf-chain/scene_stage_reset_700.hpp
// and runs/706-scene-child-ctor-and-slot-binding/scene_children_706.hpp.
void* __fastcall scene_stage_58b80_ctor_00458c90(void* self, void* unused_edx);

void* __fastcall scene_particle_emitter_ctor_00456ed0(
    void* self, void* unused_edx, const void* spec);
void __fastcall scene_particle_slot_init_00456790(void* self, void* unused_edx);
void* __fastcall scene_splt_emitter_ctor_004577a0(
    void* self, void* unused_edx, const float* quad, std::uint32_t tex_handle);
void __fastcall scene_splt_quad_init_00457920(
    void* self, void* unused_edx, const float* quad);
void __fastcall scene_splt_zero_tables_004580e0(void* self, void* unused_edx);
void __fastcall scene_splt_init_uvs_00458150(void* self, void* unused_edx);

double __cdecl math_fsqrt_005327d0(float value);
double __cdecl math_fsin_tau_005327e0(float turns);
float* __cdecl vec3_cross_raw_0056e8f5(const float* a, const float* b, float* dst);
void __cdecl vec3_cross_00532880(const float* a, const float* b, float* out);
void __cdecl vec3_cross_normalize_005328a0(const float* a, const float* b, float* out);
void __cdecl vec3_normalize_005328d0(const float* src, float* dst);
void __cdecl vec4_weighted_add_0053c490(
    std::int32_t count, const float* a, const float* b, float* out);
void __cdecl vec4_scale_0053c5d0(
    std::int32_t count, const float* src, float scale, float* dst);
float __cdecl rand_unit_005561d0();

} // namespace porsche
