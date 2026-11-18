// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00570260..0057029e (63B), 00570330..00570367 (56B),
// 00570370..0057039d (46B), 005704c0..00570503 (68B),
// 00570510..0057053d (46B), and 00570540..0057059a (91B).
#include "render_palette_expand_685.hpp"

namespace porsche {

void __cdecl render_palette_swap_rb555_00570260(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        dst[i] = static_cast<std::uint16_t>(
            ((v & 0x001fu) << 10) | (v & 0x03e0u) | ((v >> 10) & 0x001fu));
    }
}

void __cdecl render_palette_8888_to_1555_alpha_00570330(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t color = src[i];
        std::uint16_t pixel = 0u;
        if (color >= 0x40000000u) {
            pixel = static_cast<std::uint16_t>(render_color_888_to_1555_00572f5b(color));
        }
        dst[i] = pixel;
    }
}

void __cdecl render_palette_888_to_1555_00570370(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        dst[i] = static_cast<std::uint16_t>(render_color_888_to_1555_00572f5b(src[i]));
    }
}

void __cdecl render_palette_8888_to_565_alpha_005704c0(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t color = src[i];
        std::uint16_t pixel = 0u;
        if (color >= 0x40000000u) {
            pixel = static_cast<std::uint16_t>(render_color_888_to_565_00572f30(color));
            if (pixel == 0u) {
                pixel = 1u;
            }
        }
        dst[i] = pixel;
    }
}

void __cdecl render_palette_888_to_565_00570510(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        dst[i] = static_cast<std::uint16_t>(render_color_888_to_565_00572f30(src[i]));
    }
}

void __cdecl render_palette_8888_to_4444_00570540(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t color = src[i];
        dst[i] = static_cast<std::uint16_t>(
            ((color >> 16) & 0xf000u) |
            ((color >> 12) & 0x0f00u) |
            ((color >> 8) & 0x00f0u) |
            ((color >> 4) & 0x000fu));
    }
}

} // namespace porsche
