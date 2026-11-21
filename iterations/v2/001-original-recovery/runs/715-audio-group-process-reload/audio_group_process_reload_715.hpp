// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Extern declaration copied byte for byte from the accepted Run713 caller
// (runs/713-audio-group-decode/audio_group_decode_713.hpp). Full original body
// 00599610..005996c5 (182 bytes); the linker symbol is
// ?audio_group_process_reload_00599610@porsche@@YAHPAXPBX0@Z.
std::int32_t __cdecl audio_group_process_reload_00599610(void* record,
    const void* ctx, void* scratch);

// Typed child boundaries used by this body. The first three are unowned in the
// canonical registry; the fourth is the canonical Run452 provider and is only
// declared here (never redefined).
std::uint32_t __cdecl audio_group_step_0058a970(std::uint32_t* out,
    const void* record);
void* __cdecl audio_group_slot_0058f7a0(std::uint32_t key);
std::uint32_t __cdecl audio_group_configure_0058f220(std::uint32_t byte13,
    std::uint32_t word56, std::uint32_t at58, std::uint32_t at5c,
    std::uint32_t at60, std::uint32_t pointer0);
std::uint32_t __cdecl audio_resource_erase_0058f7e0(std::uint32_t key);

} // namespace porsche
