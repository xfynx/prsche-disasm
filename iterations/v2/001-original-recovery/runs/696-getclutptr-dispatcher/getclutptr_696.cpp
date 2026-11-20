// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005346d0..0053482f (352B).
#include "getclutptr_696.hpp"

#include "../689-render-clut16-and-keyed-8888-leaves/render_clut16_689.hpp"
#include "../685-render-palette-pixel-expand-leaves/render_palette_expand_685.hpp"
#include "../686-render-palette-convert-leaf-table/render_palette_convert_686.hpp"
#include "../536-render-resource-nodes/render_resource_node_536.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
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

const char render_getclutptr_message_005bb3fc[41] =
    "getclutptr - UNSUPPORTED CLUT TYPE 0x%x\n";

std::uint32_t* __cdecl render_getclutptr_from_resource_005346d0(
    const void* descriptor, std::uint32_t* palette) {
    const std::uint8_t* clut = static_cast<const std::uint8_t*>(
        render_resource_node_palette_00537fb0(descriptor));
    if (clut == nullptr) {
        return render_pixel_palette_006b4b20;
    }
    const std::uint32_t type = read_dword(clut, 0u) & 0xffu;
    if (type == 0x2au) {
        return reinterpret_cast<std::uint32_t*>(
            const_cast<std::uint8_t*>(clut) + 0x10u);
    }
    const std::int32_t count = read_word_signed(clut, 4u);
    palette[0xffu] = 0u;
    std::uint8_t scratch[0x200];
    switch (type) {
    case 0x24u:
        render_palette_rgb24_to_8888_00571160(
            count, clut + 0x10u, reinterpret_cast<std::uint8_t*>(palette));
        return palette;
    case 0x29u:
        render_palette_565_to_8888_key_00570820(
            palette, reinterpret_cast<const std::uint16_t*>(clut + 0x10u), count);
        return palette;
    case 0x2du:
        render_palette_5551_to_8888_key_00570780(
            palette, reinterpret_cast<const std::uint16_t*>(clut + 0x10u), count);
        return palette;
    case 0x2cu:
        render_palette_a565_to_8888_00570990(
            palette, reinterpret_cast<const std::uint32_t*>(clut + 0x10u), count);
        return palette;
    case 0x2eu:
        render_palette_a555_to_8888_00570920(
            palette, reinterpret_cast<const std::uint32_t*>(clut + 0x10u), count);
        return palette;
    case 0x22u:
        render_palette_vga6_to_8888_00570ff0(
            count, clut + 0x10u, reinterpret_cast<std::uint8_t*>(palette));
        return palette;
    case 0x23u:
        render_palette_swap_rb555_00570260(
            reinterpret_cast<std::uint16_t*>(scratch),
            reinterpret_cast<const std::uint16_t*>(clut + 0x10u), 0x100);
        render_palette_5551_to_8888_key_00570780(
            palette, reinterpret_cast<const std::uint16_t*>(scratch), 0x100);
        return palette;
    default:
        diagnostic_file_005deb74_set(render_clut16_file_005bb3e4);
        shared_runtime_word_005deb78 = 0xcau;
        reinterpret_cast<void (__cdecl*)(const char*, ...)>(
            diagnostic_handler_005debf0)(render_getclutptr_message_005bb3fc, type);
        return palette;
    }
}

} // namespace porsche
