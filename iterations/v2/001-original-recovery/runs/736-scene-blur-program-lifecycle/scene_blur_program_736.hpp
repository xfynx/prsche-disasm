// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run736: scene blur program constructor (00468240, 200B) and setup (004685e0, 73B).
#pragma once

#include <cstdint>

namespace porsche {

// Original 00468240..00468307 (200B, __thiscall, 5 stack dwords, RET 0x14).
// Matches accepted caller declaration in runs/726-scene-blur-stage-and-stack-binding/scene_blur_stage_726.hpp.
void* __fastcall scene_blur_program_ctor_00468240(
    void* self, void* unused_edx,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e);

// Original 004685e0..00468628 (73B, __thiscall, 6 stack dwords, RET 0x18).
// Matches accepted caller declaration in runs/726-scene-blur-stage-and-stack-binding/scene_blur_stage_726.hpp.
void __fastcall scene_blur_program_setup_004685e0(
    void* self, void* unused_edx,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e, std::uint32_t f);

// Unowned downstream typed child frontiers referenced by 00468240 and 004685e0.
void* __cdecl scene_pass_create_0053f230(
    std::uint32_t kind, std::uint32_t subkind, std::uint32_t flags);
void __fastcall scene_pass_append_0053f160(
    void* self, void* unused_edx, void* pass);
void __fastcall scene_pass_finalize_0053f2a0(
    void* self, void* unused_edx);
void __fastcall scene_blur_program_stage_00468440(
    void* self, void* unused_edx,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e, std::uint32_t f);

} // namespace porsche
