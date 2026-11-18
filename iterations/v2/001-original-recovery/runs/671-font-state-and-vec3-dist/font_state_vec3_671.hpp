// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"

namespace porsche {

// Owned read-only .rdata string at 005bbb44..005bbb66 (35B).
extern const char font_setstatef_invalid_state_005bbb44[35];

// Original 0053eea0..0053eeb2 (19B, __cdecl, ret 0).
void __cdecl font_state_set_pair_0053eea0(
    void* obj, std::uint32_t first, std::uint32_t second);

// Original 0053e890..0053e970 (225B, __cdecl, ret 0).
void __cdecl font_setstatef_0053e890(
    void* font, std::int32_t state, float value);

// Original 00532b20..00532b44 (37B, __cdecl, ret 0; returns float in ST(0)).
float __cdecl vec3_length_00532b20(const float* vec);

// Original 005323a0..005323d4 (53B, __cdecl, ret 0; returns float in ST(0)).
float __cdecl vec3_distance_005323a0(const float* a, const float* b);

} // namespace porsche
