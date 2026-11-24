// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../380-pixel-helpers/pixel_helpers.hpp"
#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

// Owned initialized .data palette entry enable flags at 005de790..005de88f (256B).
extern const std::uint8_t render_palette_enabled_005de790[256];

// Owned zero-initialized .bss 15-bit->8-bit palette lookup table pointer at 0069e0ac..0069e0af (4B).
extern const std::uint8_t* render_color_lut_0069e0ac;

// Original 00537e30..00537ecb (156B, __cdecl, ret 0; returns palette index in EAX).
std::uint32_t __cdecl render_palette_nearest_00537e30(
    const void* palette, std::uint32_t color);

// Original 00537ed0..00537f2e (95B, __cdecl, ret 0; returns packed pixel in EAX).
std::uint32_t __cdecl render_color_pack_00537ed0(std::uint32_t color);

// Original 00572f90..00572fdc (77B, __cdecl, ret 0; returns palette index in EAX).
std::uint32_t __cdecl render_color_888_to_pal8_00572f90(std::uint32_t color);

// Original 00573000..0057302e (47B, __cdecl, ret 0; returns ARGB4444 in EAX).
std::uint32_t __cdecl render_color_8888_to_4444_00573000(std::uint32_t color);

} // namespace porsche
