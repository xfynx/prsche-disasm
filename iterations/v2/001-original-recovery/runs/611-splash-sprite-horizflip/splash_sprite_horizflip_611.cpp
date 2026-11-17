// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056e2a8..0056e2bf, 24 bytes, sha256 a9c10bb3ae44528ab961d3026ab3f81c24f5a1b670d66e610ffe5202323c337f.
// Original 005712f0..00571320, 49 bytes, sha256 4f8f9547765a6535b98a0d3292121df2a8b5113e237b22ea120ce78653d39fa2.
// Original 00563320..0056343d, 286 bytes, sha256 48483524cca2ef9a8bbd29364a1054ab3fd3594f4d7e43bf4e1b285504e3dace.
#include "splash_sprite_horizflip_611.hpp"

#include <cstring>

namespace porsche {

const char splash_hflip_bits_fmt_005bced8[47] = "SHAPE_horizflip - CAN NOT FLIP %d BIT SHAPES.\n";
const char splash_hflip_packed_fmt_005bcf08[61] = "SHAPE_horizflip - CAN NOT FLIP PACKED SHAPES. PACKTYPE %02x\n";
const char splash_hflip_file_005bcf48[18] = "\\real\\cmn\\hflip.c";

std::uint32_t __cdecl render_buffer_read_word_0056e2a8(const void* src, std::int32_t bytes) {
    const auto* const p = static_cast<const std::uint8_t*>(src) + bytes - 4;
    std::uint32_t val = 0u;
    std::memcpy(&val, p, sizeof val);
    const std::uint32_t shift = static_cast<std::uint32_t>((-bytes) * 8 + 32) & 0x1fu;
    return val >> shift;
}

std::int32_t __cdecl splash_shape_row_stride_005712f0(const void* shape) {
    const auto* const bytes = static_cast<const std::uint8_t*>(shape);
    std::int16_t w16 = 0;
    std::memcpy(&w16, bytes + 4, sizeof w16);
    const std::int32_t width = w16;
    if (bytes[0] == 0x7bu) {
        return width;
    }
    std::int32_t bpp = static_cast<std::int32_t>(render_descriptor_bits_00537f90(shape));
    if (bpp == 15) {
        bpp = 16;
    }
    return (bpp * width + 7) >> 3;
}

void __cdecl splash_progress_update_sprite_00563320(void* item) {
    auto* const base = static_cast<std::uint8_t*>(item);
    std::uint32_t head0 = 0u;
    std::memcpy(&head0, base, sizeof head0);
    if ((head0 & 0x80u) != 0u) {
        shared_runtime_word_005deb74 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&splash_hflip_file_005bcf48[0]));
        shared_runtime_word_005deb78 = 0x35u;
        reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t)>(diagnostic_handler_005debf0)(
            &splash_hflip_packed_fmt_005bcf08[0], head0 & 0xffu);
    }
    std::int16_t w16 = 0, h16 = 0;
    std::memcpy(&w16, base + 4, sizeof w16);
    std::memcpy(&h16, base + 6, sizeof h16);
    const std::int32_t width = w16;
    const std::int32_t height = h16;
    const std::int32_t bpp = static_cast<std::int32_t>(render_descriptor_bits_00537f90(item));
    const std::int32_t stride = splash_shape_row_stride_005712f0(item);
    if (bpp < 8) {
        shared_runtime_word_005deb74 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&splash_hflip_file_005bcf48[0]));
        shared_runtime_word_005deb78 = 0x3du;
        reinterpret_cast<void(__cdecl*)(const char*, std::int32_t)>(diagnostic_handler_005debf0)(
            &splash_hflip_bits_fmt_005bced8[0], bpp);
    }
    const std::int32_t even_bpp = static_cast<std::int32_t>((static_cast<std::uint32_t>(bpp + 1) & 0xfffffffeu));
    const std::int32_t bytes_per_pixel = even_bpp / 8;
    const std::int32_t last_off = (width - 1) * bytes_per_pixel;
    if (height > 0) {
        std::uint8_t* row_left = base + 0x10;
        std::uint8_t* row_right = row_left + last_off;
        std::int32_t rows_left = height;
        do {
            std::uint8_t* p_left = row_left;
            std::uint8_t* p_right = row_right;
            while (p_left < p_right) {
                const std::uint32_t v_left = render_buffer_read_word_0056e2a8(p_left, bytes_per_pixel);
                const std::uint32_t v_right = render_buffer_read_word_0056e2a8(p_right, bytes_per_pixel);
                (void)render_buffer_word_0056e301(p_left, v_right, bytes_per_pixel);
                (void)render_buffer_word_0056e301(p_right, v_left, bytes_per_pixel);
                p_left += bytes_per_pixel;
                p_right -= bytes_per_pixel;
            }
            row_left += stride;
            row_right += stride;
            --rows_left;
        } while (rows_left != 0);
    }
    std::int16_t x16 = 0;
    std::memcpy(&x16, base + 8, sizeof x16);
    const std::int16_t new_x16 = static_cast<std::int16_t>(static_cast<std::uint16_t>(width) - static_cast<std::uint16_t>(x16));
    std::memcpy(base + 8, &new_x16, sizeof new_x16);
}

} // namespace porsche
