// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00570780..00570813 (148B), 00570820..0057089f (128B),
// and 00534830..005349d2 (419B).
#include "render_clut16_689.hpp"

#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"
#include "../685-render-palette-pixel-expand-leaves/render_palette_expand_685.hpp"
#include "../686-render-palette-convert-leaf-table/render_palette_convert_686.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
#include "../536-render-resource-nodes/render_resource_node_536.hpp"
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"

#include <cstring>

namespace porsche {

namespace {

inline std::uint32_t read_dword(const void* p, std::uint32_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(p) + offset, 4u);
    return value;
}

inline std::int32_t read_word_signed(const void* p, std::uint32_t offset) {
    std::int16_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(p) + offset, 2u);
    return static_cast<std::int32_t>(value);
}

} // namespace

std::uint32_t render_palette_color_key_006a6420{};
const char render_clut16_file_005bb3e4[23] = "\\real\\cmn\\depthconv.c";
const char render_clut16_message_005bb428[43] =
    "getclut16ptr - UNSUPPORTED CLUT TYPE 0x%x\n";

void __cdecl render_palette_5551_to_8888_key_00570780(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        if (v == render_palette_color_key_006a6420) {
            dst[i] = 0u;
            continue;
        }
        const std::uint32_t r5 = (v >> 10) & 0x1fu;
        const std::uint32_t g5 = (v >> 5) & 0x1fu;
        const std::uint32_t b5 = v & 0x1fu;
        const std::uint32_t a8 = (v & 0x8000u) ? 0xffu : 0x00u;
        dst[i] = (a8 << 24) | (((r5 << 3) | (r5 >> 2)) << 16) |
                 (((g5 << 3) | (g5 >> 2)) << 8) | ((b5 << 3) | (b5 >> 2));
    }
}

void __cdecl render_palette_565_to_8888_key_00570820(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count) {
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t v = src[i];
        if (v == render_palette_color_key_006a6420) {
            dst[i] = 0u;
            continue;
        }
        const std::uint32_t r5 = (v >> 11) & 0x1fu;
        const std::uint32_t g6 = (v >> 5) & 0x3fu;
        const std::uint32_t b5 = v & 0x1fu;
        dst[i] = 0xff000000u | (((r5 << 3) | (r5 >> 2)) << 16) |
                 (((g6 << 2) | (g6 >> 4)) << 8) | ((b5 << 3) | (b5 >> 2));
    }
}

std::uint16_t* __cdecl render_clut16_from_resource_00534830(
    const void* descriptor, std::uint16_t* palette) {
    std::uint8_t scratch[0x400];
    const std::uint8_t* clut = static_cast<const std::uint8_t*>(
        render_resource_node_palette_00537fb0(descriptor));
    if (clut == nullptr) {
        render_palette_8888_to_565_alpha_005704c0(
            palette, render_pixel_palette_006b4b20, 0x100);
        return palette;
    }
    const std::uint32_t type = read_dword(clut, 0u) & 0xffu;
    if (type == 0x29u) {
        return reinterpret_cast<std::uint16_t*>(
            const_cast<std::uint8_t*>(clut) + 0x10);
    }
    const std::int32_t count = read_word_signed(clut, 4u);
    palette[0xff] = 0u;
    switch (type) {
    case 0x24u:
        render_palette_rgb24_to_8888_00571160(
            count, clut + 0x10, scratch);
        render_palette_8888_to_565_alpha_005704c0(
            palette, reinterpret_cast<const std::uint32_t*>(scratch), count);
        return palette;
    case 0x2cu:
        render_palette_copy_strided16_00570490(
            palette, reinterpret_cast<const std::uint16_t*>(clut + 0x10), count);
        return palette;
    case 0x2eu:
        render_palette_copy_strided16_00570490(
            reinterpret_cast<std::uint16_t*>(scratch),
            reinterpret_cast<const std::uint16_t*>(clut + 0x10), count);
        render_palette_555_to_565_00570420(
            palette, reinterpret_cast<const std::uint16_t*>(scratch), count);
        return palette;
    case 0x2du:
        render_palette_555_to_565_00570420(
            palette, reinterpret_cast<const std::uint16_t*>(clut + 0x10), count);
        return palette;
    case 0x2au:
        render_palette_8888_to_565_alpha_005704c0(
            palette, reinterpret_cast<const std::uint32_t*>(clut + 0x10), count);
        return palette;
    case 0x22u:
        render_palette_vga6_to_8888_00570ff0(count, clut + 0x10, scratch);
        render_palette_8888_to_565_alpha_005704c0(
            palette, reinterpret_cast<const std::uint32_t*>(scratch), count);
        return palette;
    case 0x23u:
        render_palette_swap_rb555_00570260(
            palette, reinterpret_cast<const std::uint16_t*>(clut + 0x10), count);
        return palette;
    default:
        diagnostic_file_005deb74_set(render_clut16_file_005bb3e4);
        shared_runtime_word_005deb78 = 0x137u;
        reinterpret_cast<void (__cdecl*)(const char*, ...)>(
            diagnostic_handler_005debf0)(render_clut16_message_005bb428, type);
        return palette;
    }
}

} // namespace porsche
