// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005350a0..005350bf (32B), 00563ab0..00563acb (28B),
// 00570d50..00570e71 (290B), and 00573b20..00573d8d (622B).
#include "sprite_blend_leaves_822.hpp"

#include <cstring>

namespace porsche {

std::uint32_t render_blend_mode_flags_005deba0 = 0u;

namespace {

std::int32_t read_cfg_i32(std::size_t index) {
    std::int32_t value = 0;
    std::memcpy(&value, &window_shutdown_config_005de620[index], sizeof(value));
    return value;
}

std::uint32_t read_u32(const void* p) {
    std::uint32_t value = 0u;
    std::memcpy(&value, p, sizeof(value));
    return value;
}

std::uint16_t read_u16(const void* p) {
    std::uint16_t value = 0u;
    std::memcpy(&value, p, sizeof(value));
    return value;
}

bool in_clip_rect(std::int32_t x, std::int32_t y) {
    return x >= read_cfg_i32(5u) && x < read_cfg_i32(7u) &&
           y >= read_cfg_i32(6u) && y < read_cfg_i32(8u);
}

std::uint32_t blend_rounded_16(
    std::uint32_t src_c, std::uint32_t dst_c, std::uint32_t inv_alpha_16) {
    const std::int64_t prod =
        static_cast<std::int64_t>(static_cast<std::int32_t>(dst_c)) *
        static_cast<std::int64_t>(static_cast<std::int32_t>(inv_alpha_16));
    const std::uint32_t term =
        static_cast<std::uint32_t>((prod >> 16) + ((prod >> 15) & 1));
    const std::int32_t sum = static_cast<std::int32_t>(src_c + term);
    return (sum > 255) ? 255u : static_cast<std::uint32_t>(sum);
}

} // namespace

void* __cdecl render_sprite_convert_depth_005350a0(
    const void* shape, std::uint32_t bits) {
    const std::uint32_t target_type = texture_depth_format_00535380(bits);
    return render_shape_convert_type_00534d40(shape, target_type, 0, 1);
}

std::int32_t __cdecl render_sprite_filter_select_00563ab0(std::int32_t abs_scale) {
    return static_cast<std::int32_t>(
        static_cast<std::int64_t>(0x100000000LL) / static_cast<std::int64_t>(abs_scale));
}

std::uint32_t __cdecl render_buffer_read_pixel_00570d50(std::int32_t x, std::int32_t y) {
    const std::uint8_t* pixel_ptr =
        reinterpret_cast<const std::uint8_t*>(static_cast<std::uintptr_t>(static_cast<std::uint32_t>(y)));

    if (window_shutdown_mode_005de630 != 0u &&
        window_shutdown_mode_005de630 != 0xffu &&
        window_shutdown_state_005de64c == 0u) {
        using LockWindowFn = void* (__stdcall*)();
        using UnlockWindowFn = std::uint32_t (__stdcall*)(void*);
        auto* const lock_fn = reinterpret_cast<LockWindowFn>(
            static_cast<std::uintptr_t>(render_thrash_exports_006bd910[21]));
        void* const locked = lock_fn();
        if (locked != nullptr && in_clip_rect(x, y)) {
            const std::int32_t bpp_bytes =
                0x20 / static_cast<std::int32_t>(splash_progress_format_005dead0);
            const std::uint32_t base = read_u32(locked);
            const std::int32_t pitch = static_cast<std::int32_t>(
                read_u32(static_cast<const std::uint8_t*>(locked) + 4u));
            const std::uint32_t addr =
                base + static_cast<std::uint32_t>(pitch * y) +
                static_cast<std::uint32_t>(bpp_bytes * x);
            pixel_ptr = reinterpret_cast<const std::uint8_t*>(static_cast<std::uintptr_t>(addr));
            auto* const unlock_fn = reinterpret_cast<UnlockWindowFn>(
                static_cast<std::uintptr_t>(render_thrash_exports_006bd910[7]));
            (void)unlock_fn(locked);
        }
    } else if (in_clip_rect(x, y)) {
        pixel_ptr = static_cast<const std::uint8_t*>(render_buffer_address_00574050(x, y));
    }

    const auto* const cfg = reinterpret_cast<const std::uint8_t*>(window_shutdown_config_005de620);
    const std::uint8_t bpp = cfg[0x0du];
    if (bpp == 4u) {
        const std::uint8_t byte_val = *pixel_ptr;
        return ((x & 1) != 0) ? (static_cast<std::uint32_t>(byte_val) >> 4u)
                              : (static_cast<std::uint32_t>(byte_val) & 0x0fu);
    }
    if (bpp == 8u) {
        return static_cast<std::uint32_t>(*pixel_ptr);
    }
    if (bpp == 15u || bpp == 16u) {
        return static_cast<std::uint32_t>(read_u16(pixel_ptr));
    }
    if (bpp == 24u) {
        return render_buffer_read_word_0056e2a8(pixel_ptr, 3);
    }
    if (bpp == 32u) {
        return read_u32(pixel_ptr);
    }
    return 0u;
}

void __cdecl render_sprite_blend_direct_00573b20(
    std::int32_t x, std::int32_t y, std::uint32_t argb) {
    if (!in_clip_rect(x, y)) {
        return;
    }
    const auto* const cfg = reinterpret_cast<const std::uint8_t*>(window_shutdown_config_005de620);
    if (cfg[0x0cu] == 0x78u && window_shutdown_state_005de64c != 0u) {
        void* const dst = render_buffer_address_00574050(x, y);
        (void)render_rgb565_blend_pixel_00573f2a(static_cast<std::uint16_t*>(dst), argb);
        return;
    }

    const std::uint32_t src_a = argb >> 24u;
    if (src_a == 0xffu) {
        render_buffer_select_00556910(x, y, render_color_pack_00537ed0(argb));
        return;
    }
    if (src_a == 0u) {
        return;
    }

    const std::uint32_t src_r = (argb >> 16u) & 0xffu;
    const std::uint32_t src_g = (argb >> 8u) & 0xffu;
    const std::uint32_t src_b = argb & 0xffu;
    const std::uint32_t inv_alpha_16 = 0x10000u - (src_a << 8u);

    const std::uint32_t dst_raw = render_buffer_read_pixel_00570d50(x, y);
    const std::uint32_t dst_argb = render_buffer_convert_00574b70(dst_raw);
    const std::uint32_t dst_a = (dst_argb >> 24u) & 0xffu;
    if (dst_a == 0u) {
        render_buffer_select_00556910(x, y, render_color_pack_00537ed0(argb));
        return;
    }

    const std::uint32_t dst_r = (dst_argb >> 16u) & 0xffu;
    const std::uint32_t dst_g = (dst_argb >> 8u) & 0xffu;
    const std::uint32_t dst_b = dst_argb & 0xffu;

    const std::int32_t inv_src_a = 255 - static_cast<std::int32_t>(src_a);
    const std::int32_t inv_dst_a = 255 - static_cast<std::int32_t>(dst_a);
    const std::uint32_t out_a = static_cast<std::uint32_t>(255 - ((inv_dst_a * inv_src_a) / 255));

    std::uint32_t out_r = 0u;
    std::uint32_t out_g = 0u;
    std::uint32_t out_b = 0u;
    if ((render_blend_mode_flags_005deba0 & 1u) != 0u) {
        const std::int32_t dst_w = (static_cast<std::int32_t>(dst_a) * inv_src_a) >> 8;
        const std::int32_t denom = static_cast<std::int32_t>(out_a);
        out_r = static_cast<std::uint32_t>(
            (dst_w * static_cast<std::int32_t>(dst_r) + static_cast<std::int32_t>(src_r * src_a)) / denom);
        out_g = static_cast<std::uint32_t>(
            (dst_w * static_cast<std::int32_t>(dst_g) + static_cast<std::int32_t>(src_g * src_a)) / denom);
        out_b = static_cast<std::uint32_t>(
            (dst_w * static_cast<std::int32_t>(dst_b) + static_cast<std::int32_t>(src_b * src_a)) / denom);
    } else {
        out_r = blend_rounded_16(src_r, dst_r, inv_alpha_16);
        out_g = blend_rounded_16(src_g, dst_g, inv_alpha_16);
        out_b = blend_rounded_16(src_b, dst_b, inv_alpha_16);
    }

    const std::uint32_t packed =
        (out_a << 24u) | (out_r << 16u) | (out_g << 8u) | out_b;
    render_buffer_select_00556910(x, y, render_color_pack_00537ed0(packed));
}

} // namespace porsche
