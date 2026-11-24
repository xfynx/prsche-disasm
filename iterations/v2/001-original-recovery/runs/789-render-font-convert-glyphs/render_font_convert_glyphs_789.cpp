// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00594980..005949da (91B), 005949e0..00594a25 (70B),
// 00594a30..00594b4c (285B), 00594b50..00594c2b (220B), and
// 00594c30..00594ca0 (113B).
#include "render_font_convert_glyphs_789.hpp"

#include <cstring>

namespace porsche {

namespace {

std::uint32_t load_u32(const void* src) {
    std::uint32_t v = 0u;
    std::memcpy(&v, src, sizeof v);
    return v;
}

void* load_ptr(const void* src) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(load_u32(src)));
}

std::uint32_t clamp_channel(std::int32_t value) {
    if (value > 255) {
        return 255u;
    }
    if (value < 0) {
        return 0u;
    }
    return static_cast<std::uint32_t>(value);
}

} // namespace

std::uint32_t __cdecl render_font_blend_argb_00594a30(
    std::uint32_t c0, std::int32_t w0, std::uint32_t c1, std::int32_t w1) {
    const std::int32_t denom = w0 + w1;
    const std::int32_t a0 = static_cast<std::int32_t>((c0 >> 24u) & 0xffu);
    const std::int32_t r0 = static_cast<std::int32_t>((c0 >> 16u) & 0xffu);
    const std::int32_t g0 = static_cast<std::int32_t>((c0 >> 8u) & 0xffu);
    const std::int32_t b0 = static_cast<std::int32_t>(c0 & 0xffu);

    const std::int32_t a1 = static_cast<std::int32_t>((c1 >> 24u) & 0xffu);
    const std::int32_t r1 = static_cast<std::int32_t>((c1 >> 16u) & 0xffu);
    const std::int32_t g1 = static_cast<std::int32_t>((c1 >> 8u) & 0xffu);
    const std::int32_t b1 = static_cast<std::int32_t>(c1 & 0xffu);

    const std::uint32_t a = clamp_channel((a1 * w1 + a0 * w0) / denom);
    const std::uint32_t r = clamp_channel((r1 * w1 + r0 * w0) / denom);
    const std::uint32_t g = clamp_channel((g1 * w1 + g0 * w0) / denom);
    const std::uint32_t b = clamp_channel((b1 * w1 + b0 * w0) / denom);
    return (a << 24u) | (r << 16u) | (g << 8u) | b;
}

void __cdecl render_font_palette_ramp2_005949e0(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg) {
    const std::uint32_t effective_bg =
        ((bg & 0xff000000u) != 0u) ? bg : (fg & 0x00ffffffu);
    for (std::int32_t i = 0; i < 16; ++i) {
        out16[i] = render_font_blend_argb_00594a30(fg, i, effective_bg, 15 - i);
    }
}

void __cdecl render_font_palette_ramp3_00594b50(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg, std::uint32_t outline) {
    const std::uint32_t effective_bg = ((bg & 0xff000000u) != 0u) ? bg : 0u;
    out16[0] = effective_bg;
    out16[1] = outline;
    out16[2] = render_font_blend_argb_00594a30(outline, 3, effective_bg, 1);
    out16[3] = render_font_blend_argb_00594a30(outline, 2, effective_bg, 2);
    out16[4] = render_font_blend_argb_00594a30(outline, 1, effective_bg, 3);
    out16[5] = render_font_blend_argb_00594a30(effective_bg, 4, fg, 1);
    out16[6] = render_font_blend_argb_00594a30(effective_bg, 3, fg, 2);
    out16[7] = render_font_blend_argb_00594a30(effective_bg, 2, fg, 3);
    out16[8] = render_font_blend_argb_00594a30(effective_bg, 1, fg, 4);
    out16[9] = fg;
    out16[10] = render_font_blend_argb_00594a30(fg, 4, outline, 1);
    out16[11] = render_font_blend_argb_00594a30(fg, 3, outline, 2);
    out16[12] = render_font_blend_argb_00594a30(fg, 2, outline, 3);
    out16[13] = render_font_blend_argb_00594a30(fg, 1, outline, 4);
    out16[14] = 0u;
    out16[15] = 0u;
}

void __cdecl render_font_palette_split_00594c30(
    std::uint32_t* out16, std::uint32_t fg, std::uint32_t bg, std::uint32_t mid_color) {
    const std::uint32_t effective_bg =
        ((bg & 0xff000000u) != 0u) ? bg : (mid_color & 0x00ffffffu);
    for (std::int32_t i = 0; i < 8; ++i) {
        out16[i] = render_font_blend_argb_00594a30(effective_bg, 8 - i, mid_color, i);
    }
    for (std::int32_t i = 0; i < 8; ++i) {
        out16[8 + i] = render_font_blend_argb_00594a30(mid_color, 7 - i, fg, i);
    }
}

void __cdecl render_font_convert_glyphs_00594980(void* font) {
    auto* const font_bytes = static_cast<std::uint8_t*>(font);
    const auto* const desc = static_cast<const std::uint8_t*>(load_ptr(font_bytes + 0x24u));
    const std::uint32_t flags = load_u32(desc + 0x0cu);
    auto* const out16 = reinterpret_cast<std::uint32_t*>(font_bytes + 0x6cu);
    const std::uint32_t fg = load_u32(font_bytes + 0x5cu);
    const std::uint32_t bg = load_u32(font_bytes + 0x60u);
    if ((flags & 2u) != 0u) {
        const std::uint32_t outline = load_u32(font_bytes + 0x64u);
        render_font_palette_ramp3_00594b50(out16, fg, bg, outline);
    } else if ((flags & 4u) != 0u) {
        const std::uint32_t extra = load_u32(font_bytes + 0x68u);
        render_font_palette_split_00594c30(out16, fg, bg, extra);
    } else {
        render_font_palette_ramp2_005949e0(out16, fg, bg);
    }
}

} // namespace porsche
