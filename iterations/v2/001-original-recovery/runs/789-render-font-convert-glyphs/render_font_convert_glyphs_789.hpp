// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../787-render-font-destroy-and-prepare/render_font_destroy_787.hpp"

namespace porsche {

// Original 00594980..005949da (91B, __cdecl, ret 0; void).
// Declared in ../787-render-font-destroy-and-prepare/render_font_destroy_787.hpp.
void __cdecl render_font_convert_glyphs_00594980(void* font);

// Original 005949e0..00594a25 (70B, __cdecl, ret 0; void).
void __cdecl render_font_palette_ramp2_005949e0(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg);

// Original 00594a30..00594b4c (285B, __cdecl, ret 0; ARGB8888 in EAX).
std::uint32_t __cdecl render_font_blend_argb_00594a30(
    std::uint32_t c0, std::int32_t w0, std::uint32_t c1, std::int32_t w1);

// Original 00594b50..00594c2b (220B, __cdecl, ret 0; void).
void __cdecl render_font_palette_ramp3_00594b50(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg, std::uint32_t outline);

// Original 00594c30..00594ca0 (113B, __cdecl, ret 0; void).
void __cdecl render_font_palette_split_00594c30(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg, std::uint32_t mid_color);

} // namespace porsche
