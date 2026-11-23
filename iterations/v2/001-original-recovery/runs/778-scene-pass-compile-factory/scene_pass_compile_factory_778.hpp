// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run778: Run737 scene pass children + leaf constructors:
//   0053f380..0053f425 (166B) scene_pass_compile_0053f380
//   0053f980..0053fce1 (866B) scene_pass_factory_default_0053f980
//   0053fd60..0053fd80 ( 33B) scene_pass_init_kind1_0053fd60
//   00574ab0..00574aca ( 27B) scene_pass_init_kind2_00574ab0
#pragma once

#include <cstdint>

namespace porsche {

// Matches caller declarations in runs/737-scene-pass-children/scene_pass_children_737.hpp.
void __fastcall scene_pass_compile_0053f380(void* self);
void* __cdecl scene_pass_factory_default_0053f980(
    std::uint32_t kind, std::uint32_t subkind);

// Leaf constructors reached by scene_pass_factory_default_0053f980 (__thiscall, returns self, RET 4).
void* __fastcall scene_pass_init_kind1_0053fd60(
    void* self, void* unused_edx, std::uint32_t subkind);
void* __fastcall scene_pass_init_kind2_00574ab0(
    void* self, void* unused_edx, std::uint32_t subkind);

} // namespace porsche
