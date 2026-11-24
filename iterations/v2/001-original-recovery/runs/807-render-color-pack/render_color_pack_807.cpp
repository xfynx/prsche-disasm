// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00537e30..00537ecb (156B), 00537ed0..00537f2e (95B),
// 00572f90..00572fdc (77B), and 00573000..0057302e (47B).
#include "render_color_pack_807.hpp"

namespace porsche {

const std::uint8_t render_palette_enabled_005de790[256] = {
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u,
    1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 0u, 0u
};

const std::uint8_t* render_color_lut_0069e0ac = nullptr;

std::uint32_t __cdecl render_palette_nearest_00537e30(
    const void* palette, std::uint32_t color) {
    const auto* entries = static_cast<const std::uint8_t*>(
        palette != nullptr ? palette : static_cast<const void*>(render_pixel_palette_006b4b20));
    const std::int32_t b = static_cast<std::int32_t>(color & 0xffu);
    const std::int32_t g = static_cast<std::int32_t>((color >> 8u) & 0xffu);
    const std::int32_t r = static_cast<std::int32_t>((color >> 16u) & 0xffu);
    std::int32_t best_dist = 0x1869f;
    std::uint32_t best_index = 0u;

    for (std::uint32_t i = 0u; i < 256u; ++i) {
        const std::int32_t eb = static_cast<std::int32_t>(entries[0]);
        const std::int32_t eg = static_cast<std::int32_t>(entries[1]);
        const std::int32_t er = static_cast<std::int32_t>(entries[2]);
        entries += 4;
        if (render_palette_enabled_005de790[i] == 0u) {
            continue;
        }
        const std::int32_t db = b - eb;
        const std::int32_t dg = g - eg;
        const std::int32_t dr = r - er;
        const std::int32_t dist = dr * dr + dg * dg + db * db;
        if (dist < best_dist) {
            best_dist = dist;
            best_index = i;
        }
    }
    return best_index;
}

std::uint32_t __cdecl render_color_888_to_pal8_00572f90(std::uint32_t color) {
    if (render_color_lut_0069e0ac != nullptr) {
        const std::uint32_t lut_index =
            ((color & 0x00f80000u) >> 9u) +
            ((color & 0x0000f800u) >> 6u) +
            ((color >> 3u) & 0x1fu);
        return static_cast<std::uint32_t>(render_color_lut_0069e0ac[lut_index]);
    }
    return render_palette_nearest_00537e30(render_pixel_palette_006b4b20, color);
}

std::uint32_t __cdecl render_color_8888_to_4444_00573000(std::uint32_t color) {
    const std::uint32_t a_hi = (color >> 28u) << 4u;
    const std::uint32_t r_lo = (color >> 20u) & 0x0fu;
    const std::uint32_t g_lo = (color >> 12u) & 0x0fu;
    const std::uint32_t b_lo = (color >> 4u) & 0x0fu;
    return (((((a_hi | r_lo) << 4u) | g_lo) << 4u) | b_lo);
}

std::uint32_t __cdecl render_color_pack_00537ed0(std::uint32_t color) {
    const auto* const cfg = reinterpret_cast<const std::uint8_t*>(window_shutdown_config_005de620);
    const std::uint8_t bpp = cfg[0x0du];
    if (bpp <= 8u) {
        return render_color_888_to_pal8_00572f90(color);
    }
    if (bpp == 0x0fu) {
        return render_color_888_to_1555_00572f5b(color);
    }
    if (bpp == 0x10u) {
        if (cfg[0x0cu] == 0x6du) {
            return render_color_8888_to_4444_00573000(color);
        }
        return render_color_888_to_565_00572f30(color);
    }
    return (bpp >= 0x18u) ? color : 0u;
}

} // namespace porsche
