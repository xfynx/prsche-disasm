// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../374-render-descriptor/render_descriptor.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
#include "../807-render-color-pack/render_color_pack_807.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

// Owned zero-initialized .bss row-offset cache for scaled sprite sampling at 006ad754..006ad75b and 006b1c20..006b3c1f.
extern std::int32_t render_sprite_row_stride_006ad754;
extern std::int32_t render_sprite_row_count_006ad758;
extern std::uint32_t render_sprite_row_offsets_006b1c20[2048];

// Typed unrecovered downstream sprite/shape boundaries.
void* __cdecl render_sprite_convert_depth_005350a0(const void* shape, std::uint32_t bits);
std::int32_t __cdecl render_sprite_filter_select_00563ab0(std::int32_t abs_scale);
std::int32_t __cdecl render_shape_row_stride_005712f0(const void* shape);
std::uint32_t __cdecl render_sprite_sample_0058ccbf(
    const void* src, std::int32_t u_fixed, std::int32_t v_fixed, std::int32_t row_bytes);
void __cdecl render_sprite_blend_direct_00573b20(
    std::int32_t x, std::int32_t y, std::uint32_t argb);

// Original 00563160..00563310 (433B, __cdecl, ret 0) declared in porsche/splash_progress.hpp.
// Original 00562cf0..00562eac (445B, __cdecl, ret 0).
void __cdecl render_sprite_span_blend_00562cf0(
    const void* shape, std::int32_t u_fixed, std::int32_t v_fixed,
    std::int32_t du_fixed, std::int32_t dv_fixed,
    std::int32_t dst_x, std::int32_t dst_y, std::int32_t count);

// Original 00562eb0..00562fcb (284B, __cdecl, ret 0).
void __cdecl render_pal8_blend_pixel_00562eb0(std::uint8_t* dst, std::uint32_t color);

// Original 00573f2a..00573fae (133B, __cdecl, ret 0; returns dst + 1 in EAX).
std::uint16_t* __cdecl render_rgb565_blend_pixel_00573f2a(
    std::uint16_t* dst, std::uint32_t color);

// Original 00573faf..00574040 (146B, __cdecl, ret 0; returns dst + 1 in EAX).
std::uint16_t* __cdecl render_argb1555_blend_pixel_00573faf(
    std::uint16_t* dst, std::uint32_t color);

// Original 0058ccf0..0058cd5f (112B, __cdecl, ret 0).
void __cdecl render_sprite_row_table_prepare_0058ccf0(const void* shape);

} // namespace porsche
