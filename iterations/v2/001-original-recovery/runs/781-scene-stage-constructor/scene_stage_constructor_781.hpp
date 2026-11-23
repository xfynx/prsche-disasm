// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run781: scene stage flare constructor cluster:
//   004522b0..00452496 (487B) scene_stage_constructor_004522b0
//   004524a0..00452507 (104B) scene_flare_entry_ctor_004524a0
//   0059ece0..0059ecf1 ( 18B) context_table_size_0059ece0
#pragma once

#include <cstdint>

namespace porsche {

// Original 0059ece0..0059ecf1 (18B, __cdecl, returns uint32_t size).
std::uint32_t __cdecl context_table_size_0059ece0(const void* block);

// Original 004524a0..00452507 (104B, __thiscall, returns self, RET 4).
void* __fastcall scene_flare_entry_ctor_004524a0(
    void* self, void* unused_edx, std::uint32_t tag);

// Original 004522b0..00452496 (487B, __thiscall, returns self, RET 0).
// Matches caller declaration in runs/706-scene-child-ctor-and-slot-binding/scene_children_706.hpp.
void* __fastcall scene_stage_constructor_004522b0(void* self, void* unused_edx);

// Typed unresolved child reached by scene_stage_constructor_004522b0 (00452120..004521b9, 154B, __thiscall, RET 0).
void __fastcall scene_flare_entries_resolve_00452120(void* self, void* unused_edx);

} // namespace porsche
