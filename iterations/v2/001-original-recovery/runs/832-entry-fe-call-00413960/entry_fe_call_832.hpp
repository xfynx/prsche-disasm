// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run832: entry_fe_call_00413960 closure (14 functions, 710B code, 0B data/bss):
//   00413960 (536B) entry_fe_call_00413960
//   0046d980 ( 39B) scene_camera_elem_at_0046d980
//   00469b20 ( 33B) camera_elem_vec3_b4_00469b20
//   00469a80 (  7B) camera_elem_u32_80_00469a80
//   00469a90 (  7B) camera_elem_f32_84_00469a90
//   00469aa0 (  7B) camera_elem_u32_88_00469aa0
//   00469ab0 (  7B) camera_elem_u32_8c_00469ab0
//   00469ac0 (  4B) camera_elem_u32_78_00469ac0
//   00469ad0 (  7B) camera_elem_u32_90_00469ad0
//   00469ae0 (  7B) camera_elem_f32_94_00469ae0
//   00469af0 (  7B) camera_elem_u32_98_00469af0
//   00469b00 (  7B) camera_elem_f32_9c_00469b00
//   00469b10 (  7B) camera_elem_f32_a0_00469b10
//   0046af50 (  4B) camera_elem_u32_7c_0046af50
#pragma once

#include <cstdint>

namespace porsche {

// Matches accepted caller declaration in runs/692-entry-fe-loop-and-leaves/fe_entry_leaves_692.hpp
// and runs/702-entry-fe-scene-route-transfer-leaves/entry_fe_scene_leaves_702.hpp.
void __cdecl entry_fe_call_00413960(std::uint32_t value);

void* __cdecl scene_camera_elem_at_0046d980(std::uint32_t index);
void* __fastcall camera_elem_vec3_b4_00469b20(void* self, void* unused_edx, void* out_vec3);

std::uint32_t __fastcall camera_elem_u32_80_00469a80(const void* self, void* unused_edx);
float __fastcall camera_elem_f32_84_00469a90(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_88_00469aa0(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_8c_00469ab0(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_78_00469ac0(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_90_00469ad0(const void* self, void* unused_edx);
float __fastcall camera_elem_f32_94_00469ae0(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_98_00469af0(const void* self, void* unused_edx);
float __fastcall camera_elem_f32_9c_00469b00(const void* self, void* unused_edx);
float __fastcall camera_elem_f32_a0_00469b10(const void* self, void* unused_edx);
std::uint32_t __fastcall camera_elem_u32_7c_0046af50(const void* self, void* unused_edx);

} // namespace porsche
