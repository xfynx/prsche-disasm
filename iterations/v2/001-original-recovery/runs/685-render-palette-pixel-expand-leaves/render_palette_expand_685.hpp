// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"

namespace porsche {

// Original 00570260..0057029e (63B, __cdecl, ret 0; void).
void __cdecl render_palette_swap_rb555_00570260(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);

// Original 00570330..00570367 (56B, __cdecl, ret 0; void).
void __cdecl render_palette_8888_to_1555_alpha_00570330(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 00570370..0057039d (46B, __cdecl, ret 0; void).
void __cdecl render_palette_888_to_1555_00570370(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 005704c0..00570503 (68B, __cdecl, ret 0; void).
void __cdecl render_palette_8888_to_565_alpha_005704c0(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 00570510..0057053d (46B, __cdecl, ret 0; void).
void __cdecl render_palette_888_to_565_00570510(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 00570540..0057059a (91B, __cdecl, ret 0; void).
void __cdecl render_palette_8888_to_4444_00570540(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);

} // namespace porsche
