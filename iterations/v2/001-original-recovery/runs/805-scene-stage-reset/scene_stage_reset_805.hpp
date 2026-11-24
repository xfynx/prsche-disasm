// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run805: scene stage reset & context table ctor cluster:
//   00448b10..00448bb6 (167B) scene_stage_reset_00448b10
//   0044d0b0..0044d153 (164B) scene_stage_table_ctor_0044d0b0
#pragma once

#include <cstdint>

namespace porsche {

// Newly owned .data pointer array (8B at 0x005cdeac..0x005cdeb3 -> "common.fsh", "particle.fsh").
extern const char* scene_stage_reset_fsh_names_005cdeac[2];

// Newly owned loader-zero .bss slot (4B at 0x00613e08, adjacent to Run649's 00613e04).
extern void* scene_stage_particle_table_owner_00613e08;

// Matches exact accepted caller declaration in runs/693-view-setup-teardown-scene-enter/application_view_lifecycle_693.hpp.
void __cdecl scene_stage_reset_00448b10();

void* __fastcall scene_stage_table_ctor_0044d0b0(
    void* self, void* unused_edx, void* owner, std::uint32_t capacity);

// Single typed child frontier reached by 00448b10 (0044d270..0044d314, 165B, __thiscall, RET 0x8).
void __fastcall scene_stage_table_load_0044d270(
    void* self, void* unused_edx, const char* path, std::uint32_t zero);

} // namespace porsche
