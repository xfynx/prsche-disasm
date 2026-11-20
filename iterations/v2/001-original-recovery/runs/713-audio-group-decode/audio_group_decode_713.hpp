// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Accepted Run710 caller declaration (audio_reverb_children_710.hpp) matched
// byte for byte. Full original body 00590a80..00590b4c (205 bytes).
std::int32_t __cdecl audio_group_decode_00590a80(const void* source,
    const void* ctx, void* scratch);

// Typed boundaries: canonical owner recovered in Run451, unowned reload child.
// Neither body is redefined in this translation unit.
std::int32_t __cdecl audio_group_decode_00599100(std::uint32_t* cursor,
    void* record);
std::int32_t __cdecl audio_group_process_reload_00599610(void* record,
    const void* ctx, void* scratch);

} // namespace porsche
