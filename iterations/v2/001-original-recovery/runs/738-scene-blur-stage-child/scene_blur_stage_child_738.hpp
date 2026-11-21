// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run738: original 00468440..004685d0 (401B), __thiscall RET 0x18.
#pragma once

#include <cstdint>

namespace porsche {

void __fastcall scene_blur_program_stage_00468440(
    void* self, void* unused_edx,
    std::uint32_t index, void* source,
    std::uint32_t slot_1f_value, std::uint32_t slot_1d_value,
    std::uint32_t slot_20_value, std::uint32_t enabled);

void* __cdecl scene_pass_create_0053f230(
    std::uint32_t kind, std::uint32_t subkind, std::uint32_t flags);
void __fastcall scene_pass_append_0053f160(
    void* self, void* unused_edx, void* pass);

void __fastcall scene_blur_state_flag_00537a70(
    void* self, void* unused_edx, std::uint32_t value);
void __fastcall scene_blur_state_one_00537a40(
    void* self, void* unused_edx, std::uint32_t value);
void __fastcall scene_blur_state_quality_00537a30(
    void* self, void* unused_edx, std::uint32_t value);
void __fastcall scene_blur_state_commit_00536470(
    void* self, void* unused_edx, const void* state_28_bytes);

} // namespace porsche
