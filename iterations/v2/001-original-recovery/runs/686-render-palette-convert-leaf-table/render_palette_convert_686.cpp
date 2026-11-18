// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005702a0..005702e3 (68B), 00570920..00570985 (102B),
// 00570990..005709f4 (101B), 00570ff0..005710a7 (184B),
// and 00571160..005711ad (78B).
#include "render_palette_convert_686.hpp"

namespace porsche {

namespace {

inline std::uint32_t expand_5_to_8(std::uint32_t c5) {
    return (c5 << 3) | (c5 >> 2);
}

inline std::uint32_t expand_6_to_8(std::uint32_t c6) {
    return (c6 << 2) | (c6 >> 4);
}

inline std::uint8_t scale_vga6_to_u8(std::uint8_t value) {
    return static_cast<std::uint8_t>((static_cast<std::int32_t>(value) * 255 + 32) / 63);
}

} // namespace

void __cdecl render_palette_565_to_1555_005702a0(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        if (v == 0u) {
            dst[i] = 0u;
        } else {
            dst[i] = static_cast<std::uint16_t>(
                0x8000u | ((v >> 1) & 0xffe0u) | (v & 0x1fu));
        }
    }
}

void __cdecl render_palette_a555_to_8888_00570920(
    std::uint32_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        const std::uint32_t a8 = v >> 24;
        const std::uint32_t r8 = expand_5_to_8((v >> 10) & 0x1fu);
        const std::uint32_t g8 = expand_5_to_8((v >> 5) & 0x1fu);
        const std::uint32_t b8 = expand_5_to_8(v & 0x1fu);
        dst[i] = (a8 << 24) | (r8 << 16) | (g8 << 8) | b8;
    }
}

void __cdecl render_palette_a565_to_8888_00570990(
    std::uint32_t* dst, const std::uint32_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        const std::uint32_t a8 = v >> 24;
        const std::uint32_t r8 = expand_5_to_8((v >> 11) & 0x1fu);
        const std::uint32_t g8 = expand_6_to_8((v >> 5) & 0x3fu);
        const std::uint32_t b8 = expand_5_to_8(v & 0x1fu);
        dst[i] = (a8 << 24) | (r8 << 16) | (g8 << 8) | b8;
    }
}

void __cdecl render_palette_vga6_to_8888_00570ff0(
    std::int32_t count, const std::uint8_t* src, std::uint8_t* dst) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint8_t alpha = static_cast<std::uint8_t>((i == 255) ? 0x00u : 0xffu);
        const std::uint8_t r = src[i * 3 + 0];
        dst[i * 4 + 3] = alpha;
        const std::uint8_t g = src[i * 3 + 1];
        dst[i * 4 + 2] = scale_vga6_to_u8(r);
        const std::uint8_t b = src[i * 3 + 2];
        dst[i * 4 + 1] = scale_vga6_to_u8(g);
        dst[i * 4 + 0] = scale_vga6_to_u8(b);
    }
}

void __cdecl render_palette_rgb24_to_8888_00571160(
    std::int32_t count, const std::uint8_t* src, std::uint8_t* dst) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint8_t alpha = static_cast<std::uint8_t>((i == 255) ? 0x00u : 0xffu);
        dst[i * 4 + 3] = alpha;
        dst[i * 4 + 2] = src[i * 3 + 0];
        dst[i * 4 + 1] = src[i * 3 + 1];
        dst[i * 4 + 0] = src[i * 3 + 2];
    }
}

} // namespace porsche
