// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../817-splash-draw-sprite/sprite_draw_817.hpp"
#include "porsche/render_loader.hpp"

namespace porsche {

// Owned zero-initialized .data blend flags at 005deba0..005deba3 (4B).
extern std::uint32_t render_blend_mode_flags_005deba0;

// Canonical cross-run callees already recovered in 375/378/380/611/741.
std::uint32_t __cdecl texture_depth_format_00535380(std::uint32_t depth);
void* __cdecl render_shape_convert_type_00534d40(
    const void* shape, std::uint32_t target_type,
    std::int32_t use_dither, std::int32_t direct_mode);
void __cdecl render_buffer_select_00556910(
    std::int32_t x, std::int32_t y, std::uint32_t pixel);
std::uint32_t __cdecl render_buffer_read_word_0056e2a8(
    const void* src, std::int32_t bytes);

// Original 00570d50..00570e71 (290B, __cdecl, ret 0; returns pixel value in EAX).
std::uint32_t __cdecl render_buffer_read_pixel_00570d50(std::int32_t x, std::int32_t y);

// Original 005350a0..005350bf (32B), 00563ab0..00563acb (28B), and 00573b20..00573d8d (622B)
// are declared in ../817-splash-draw-sprite/sprite_draw_817.hpp.

} // namespace porsche
