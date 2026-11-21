// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run742: scene stage group constructor (0059f070, 329B) and its four leaf helpers
// (0053f320 33B, 0053f600 29B, 00537a20 10B, 00537a60 10B).
#pragma once

#include <cstdint>

namespace porsche {

// Original 0053f320..0053f340 (33B, __thiscall, 2 stack dwords, returns self, RET 8).
void* __fastcall scene_pass_init_0053f320(
    void* self, void* unused_edx, std::uint32_t kind, std::uint32_t subkind);

// Original 0053f600..0053f61c (29B, __thiscall, 1 stack dword, returns self, RET 4).
void* __fastcall scene_pass_init_alt_0053f600(
    void* self, void* unused_edx, std::uint32_t subkind);

// Original 00537a20..00537a29 (10B, __thiscall, 1 stack dword, void return, RET 4).
void __fastcall scene_mode_set_c_00537a20(
    void* self, void* unused_edx, std::uint32_t value);

// Original 00537a60..00537a69 (10B, __thiscall, 1 stack dword, void return, RET 4).
void __fastcall scene_mode_set_10_00537a60(
    void* self, void* unused_edx, std::uint32_t value);

// Original 0059f070..0059f1b8 (329B, __thiscall, returns self, RET 0).
// Matches accepted caller declaration in runs/721-scene-stage-stack-input-core/scene_stage_stack_core_721.hpp.
void* __fastcall scene_stage_group_ctor_0059f070(void* self, void* unused_edx);

} // namespace porsche
