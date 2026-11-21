#pragma once

#include <cstdint>

namespace porsche {

// Original 0053f160..0053f1ab (thiscall, RET 4) through a fastcall bridge.
void __fastcall scene_pass_append_0053f160(
    void* self, void* unused_edx, void* pass);

// Original 0053f230..0053f29c (cdecl, RET 0).
void* __cdecl scene_pass_create_0053f230(
    std::uint32_t kind, std::uint32_t subkind, std::uint32_t flags);

// Original 0053f2a0..0053f318 (thiscall, RET 0) through a fastcall bridge.
void __fastcall scene_pass_finalize_0053f2a0(
    void* self, void* unused_edx);

// Typed, unrecovered children reached by the recovered bodies.
void __fastcall scene_pass_compile_0053f380(void* self);
void* __cdecl scene_pass_factory_default_0053f980(
    std::uint32_t kind, std::uint32_t subkind);

} // namespace porsche
