// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00562cf0..00562eac (445B), 00562eb0..00562fcb (284B),
// 00563160..00563310 (433B), 00573f2a..00573fae (133B),
// 00573faf..00574040 (146B), and 0058ccf0..0058cd5f (112B).
#include "sprite_draw_817.hpp"

#include <cstring>

namespace porsche {

std::int32_t render_sprite_row_stride_006ad754 = 0;
std::int32_t render_sprite_row_count_006ad758 = 0;
std::uint32_t render_sprite_row_offsets_006b1c20[2048]{};

namespace {

std::int16_t read_i16(const void* base, std::size_t offset) {
    std::int16_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

std::int32_t read_cfg_i32(std::size_t index) {
    std::int32_t value = 0;
    std::memcpy(&value, &window_shutdown_config_005de620[index], sizeof(value));
    return value;
}

std::uint32_t blend_channel_pal8(
    std::uint32_t src_c, std::uint32_t pal_c, std::uint32_t inv_alpha_16) {
    const std::int64_t prod =
        static_cast<std::int64_t>(static_cast<std::int32_t>(pal_c)) *
        static_cast<std::int64_t>(static_cast<std::int32_t>(inv_alpha_16));
    const std::uint32_t rounded =
        static_cast<std::uint32_t>((prod >> 16) + ((prod >> 15) & 1));
    const std::uint32_t sum = src_c + rounded;
    return (sum > 0xffu) ? 0xffu : sum;
}

} // namespace

void __cdecl render_sprite_row_table_prepare_0058ccf0(const void* shape) {
    const std::int32_t stride = render_shape_row_stride_005712f0(shape);
    const std::int32_t height = static_cast<std::int32_t>(read_i16(shape, 6u));
    std::int32_t index = 0;
    std::uint32_t offset = 0u;

    if (stride == render_sprite_row_stride_006ad754) {
        const std::int32_t cached = render_sprite_row_count_006ad758;
        if (height <= cached) {
            return;
        }
        index = cached;
        offset = static_cast<std::uint32_t>(cached * stride);
    } else {
        render_sprite_row_stride_006ad754 = stride;
    }

    if (index >= height) {
        return;
    }
    render_sprite_row_count_006ad758 = height;
    const std::uint32_t groups = static_cast<std::uint32_t>(height - index + 3) >> 2u;
    const std::uint32_t step = static_cast<std::uint32_t>(stride);
    for (std::uint32_t g = 0u; g < groups; ++g) {
        render_sprite_row_offsets_006b1c20[index] = offset;
        offset += step;
        render_sprite_row_offsets_006b1c20[index + 1] = offset;
        offset += step;
        render_sprite_row_offsets_006b1c20[index + 2] = offset;
        offset += step;
        render_sprite_row_offsets_006b1c20[index + 3] = offset;
        offset += step;
        index += 4;
    }
}

void __cdecl render_pal8_blend_pixel_00562eb0(
    std::uint8_t* dst, std::uint32_t color) {
    const std::uint32_t alpha = color >> 24u;
    if (alpha == 0u) {
        return;
    }
    if (alpha == 0xffu) {
        *dst = static_cast<std::uint8_t>(render_color_888_to_pal8_00572f90(color));
        return;
    }

    const std::uint32_t inv_alpha_16 = 0x10000u - ((alpha << 8u) | alpha);
    const std::uint32_t pal = render_pixel_palette_006b4b20[*dst];
    const std::uint32_t out_r =
        blend_channel_pal8((color >> 16u) & 0xffu, (pal >> 16u) & 0xffu, inv_alpha_16);
    const std::uint32_t out_g =
        blend_channel_pal8((color >> 8u) & 0xffu, (pal >> 8u) & 0xffu, inv_alpha_16);
    const std::uint32_t out_b =
        blend_channel_pal8(color & 0xffu, pal & 0xffu, inv_alpha_16);
    const std::uint32_t blended =
        0xff000000u | (out_r << 16u) | (out_g << 8u) | out_b;
    *dst = static_cast<std::uint8_t>(render_color_888_to_pal8_00572f90(blended));
}

std::uint16_t* __cdecl render_rgb565_blend_pixel_00573f2a(
    std::uint16_t* dst, std::uint32_t color) {
    if (color < 0x10000000u) {
        return dst + 1;
    }
    if (color < 0xfc000000u) {
        const std::uint32_t px = static_cast<std::uint32_t>(*dst);
        const std::uint32_t unpacked =
            ((px << 16u) & 0xf8000000u) + (px & 0x001fu) + ((px & 0x07e0u) << 8u);
        const std::uint32_t inv_a = (color >> 24u) ^ 0xffu;
        const std::uint64_t prod =
            static_cast<std::uint64_t>(unpacked) * static_cast<std::uint64_t>(inv_a);
        const std::uint32_t lo = static_cast<std::uint32_t>(prod);
        const std::uint32_t hi = static_cast<std::uint32_t>(prod >> 32u);
        color += (hi << 16u) + ((lo >> 5u) & 0xffu) + ((lo >> 11u) & 0xff00u);
    }
    *dst = static_cast<std::uint16_t>(
        ((color & 0x00f80000u) >> 8u) +
        ((color & 0x0000fc00u) >> 5u) +
        ((color >> 3u) & 0x1fu));
    return dst + 1;
}

std::uint16_t* __cdecl render_argb1555_blend_pixel_00573faf(
    std::uint16_t* dst, std::uint32_t color) {
    if (color < 0x10000000u) {
        return dst + 1;
    }
    if (color < 0xfc000000u) {
        const std::uint32_t px = static_cast<std::uint32_t>(*dst);
        const std::uint32_t unpacked =
            ((px & 0x7c00u) << 17u) + ((px & 0x03e0u) << 9u) + (px & 0x001fu);
        const std::uint32_t inv_a = (color >> 24u) ^ 0xffu;
        const std::uint64_t prod =
            static_cast<std::uint64_t>(unpacked) * static_cast<std::uint64_t>(inv_a);
        const std::uint32_t lo = static_cast<std::uint32_t>(prod);
        const std::uint32_t hi = static_cast<std::uint32_t>(prod >> 32u);
        color += (hi << 16u) + ((lo >> 5u) & 0xffu) + ((lo >> 11u) & 0xff00u);
    }
    *dst = static_cast<std::uint16_t>(
        0x8000u +
        ((color & 0x00f80000u) >> 9u) +
        ((color & 0x0000f800u) >> 6u) +
        ((color >> 3u) & 0x1fu));
    return dst + 1;
}

void __cdecl render_sprite_span_blend_00562cf0(
    const void* shape, std::int32_t u_fixed, std::int32_t v_fixed,
    std::int32_t du_fixed, std::int32_t dv_fixed,
    std::int32_t dst_x, std::int32_t dst_y, std::int32_t count) {
    if (count <= 0) {
        return;
    }
    const auto mode = static_cast<std::uint8_t>(window_shutdown_config_005de620[3] & 0xffu);
    void* dst = render_buffer_address_00574050(dst_x, dst_y);
    const std::int32_t row_bytes = static_cast<std::int32_t>(read_i16(shape, 4u)) << 2;
    const auto* const shape_bytes = static_cast<const std::uint8_t*>(shape);

    for (std::int32_t i = 0; i < count; ++i) {
        const std::int32_t iu = u_fixed >> 16;
        const std::int32_t iv = v_fixed >> 16;
        const void* const src =
            shape_bytes + render_sprite_row_offsets_006b1c20[iv] + iu * 4 + 0x10;
        const std::uint32_t sampled =
            render_sprite_sample_0058ccbf(src, u_fixed, v_fixed, row_bytes);

        if (mode == 0x78u) {
            dst = render_rgb565_blend_pixel_00573f2a(static_cast<std::uint16_t*>(dst), sampled);
        } else if (mode == 0x7eu) {
            dst = render_argb1555_blend_pixel_00573faf(static_cast<std::uint16_t*>(dst), sampled);
        } else if (mode == 0x7bu) {
            auto* const dst_u8 = static_cast<std::uint8_t*>(dst);
            render_pal8_blend_pixel_00562eb0(dst_u8, sampled);
            dst = dst_u8 + 1;
        } else {
            render_sprite_blend_direct_00573b20(dst_x, dst_y, sampled);
            ++dst_x;
        }
        u_fixed += du_fixed;
        v_fixed += dv_fixed;
    }
}

void __cdecl splash_progress_draw_sprite_00563160(
    void* item, std::int32_t x, std::int32_t y,
    std::int32_t width, std::int32_t height) {
    void* allocated = nullptr;
    if (render_descriptor_bits_00537f90(item) != 0x20u) {
        allocated = render_sprite_convert_depth_005350a0(item, 0x20u);
        item = allocated;
    }

    const std::int32_t src_w = static_cast<std::int32_t>(read_i16(item, 4u));
    const std::int32_t src_h = static_cast<std::int32_t>(read_i16(item, 6u));
    const std::int32_t scale_x_raw = (width << 16) / src_w;
    const std::int32_t abs_scale_x = (scale_x_raw < 0) ? -scale_x_raw : scale_x_raw;
    if (width < 2) {
        width = 2;
    }
    if (height < 2) {
        height = 2;
    }

    if (abs_scale_x > 0x28f) {
        render_sprite_row_table_prepare_0058ccf0(item);
        const std::int32_t mip_raw = render_sprite_filter_select_00563ab0(abs_scale_x);
        const std::int32_t shifted = (mip_raw / 2) + static_cast<std::int32_t>(0xffff8000u);
        const std::int32_t margin = (shifted < 0) ? 0 : shifted;

        std::int32_t u_start = margin;
        std::int32_t v_start = margin;
        std::int32_t u_end = (src_w << 16) - margin - 0x10000;
        std::int32_t v_end = (src_h << 16) - margin - 0x10000;
        if (scale_x_raw < 0) {
            u_end = margin;
            u_start = (src_w << 16) - margin - 0x10000;
            v_start = (src_h << 16) - margin - 0x10000;
            v_end = margin;
        }

        const std::int32_t du = (u_end - u_start) / (width - 1);
        const std::int32_t dv = (v_end - v_start) / (height - 1);
        std::int32_t u0 = u_start;
        std::int32_t v0 = v_start;

        const std::int32_t clip_left_delta = read_cfg_i32(5u) - x;
        if (clip_left_delta > 0) {
            x += clip_left_delta;
            u0 = u_start + clip_left_delta * du;
            width -= clip_left_delta;
        }
        const std::int32_t clip_right_excess = x - read_cfg_i32(7u) + width;
        if (clip_right_excess > 0) {
            width -= clip_right_excess;
        }
        const std::int32_t clip_top_delta = read_cfg_i32(6u) - y;
        if (clip_top_delta > 0) {
            y += clip_top_delta;
            v0 = v_start + clip_top_delta * dv;
            height -= clip_top_delta;
        }
        const std::int32_t clip_bottom_excess = y - read_cfg_i32(8u) + height;
        if (clip_bottom_excess > 0) {
            height -= clip_bottom_excess;
        }

        for (std::int32_t row = 0; row < height; ++row) {
            render_sprite_span_blend_00562cf0(item, u0, v0, du, 0, x, y, width);
            v0 += dv;
            ++y;
        }
    }

    if (allocated != nullptr) {
        splash_progress_free_00531f90(allocated);
    }
}

} // namespace porsche
