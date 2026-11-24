// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00556d20..00557085 (870B) and 00557240..0055734a (267B).
#include "render_driver_query_802.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char render_driver_query_pbuf_tag_005cf80c[5] = "PBUF";
const char render_driver_query_uv_test_005cf814[8] = "UV Test";

namespace {

struct QueryVertex {
    std::uint32_t words[8];
};

std::uint32_t read_u32(const void* base, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

std::uint16_t read_u16(const void* base, std::size_t offset) {
    std::uint16_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

const void* read_ptr(const void* base, std::size_t offset) {
    return reinterpret_cast<const void*>(
        static_cast<std::uintptr_t>(read_u32(base, offset)));
}

std::uint32_t expand_5_to_8(std::uint32_t v) {
    return (v * 255u + 16u) / 31u;
}

std::uint32_t expand_6_to_8(std::uint32_t v) {
    return (v * 255u + 31u) / 63u;
}

std::uint32_t mode_bytes_per_pixel(std::uint32_t mode) {
    switch (mode) {
    case 5u:
        return 3u;
    case 6u:
        return 4u;
    case 3u:
    case 4u:
    case 7u:
    default:
        return 2u;
    }
}

std::uint32_t mode_bit_width(std::uint32_t mode) {
    switch (mode) {
    case 1u:
        return 4u;
    case 2u:
    case 8u:
        return 8u;
    case 5u:
        return 24u;
    case 6u:
        return 32u;
    default:
        return 16u;
    }
}

std::uint32_t read_pixel_by_bits(const std::uint8_t* src, std::uint32_t bits) {
    if (bits == 4u || bits == 8u) {
        return static_cast<std::uint32_t>(*src);
    }
    if (bits == 24u || bits == 32u) {
        return read_u32(src, 0u);
    }
    return static_cast<std::uint32_t>(read_u16(src, 0u));
}

QueryVertex make_vertex(
    std::uint32_t x_bits, std::uint32_t y_bits, std::uint32_t u_bits, std::uint32_t v_bits) {
    QueryVertex q{};
    q.words[0] = x_bits;
    q.words[1] = y_bits;
    q.words[2] = 0x3f7fff00u;
    q.words[3] = 0x37800080u;
    q.words[4] = 0xffffffffu;
    q.words[5] = 0u;
    q.words[6] = u_bits;
    q.words[7] = v_bits;
    return q;
}

} // namespace

std::uint32_t __cdecl render_pixel_to_argb8888_00557240(
    std::uint32_t pixel, std::uint32_t mode) {
    switch (mode) {
    case 3u:
    case 11u: {
        if (pixel == 0u) {
            return 0u;
        }
        const std::uint32_t r = expand_5_to_8((pixel >> 10u) & 0x1fu);
        const std::uint32_t g = expand_5_to_8((pixel >> 5u) & 0x1fu);
        const std::uint32_t b = expand_5_to_8(pixel & 0x1fu);
        return 0xff000000u | (r << 16u) | (g << 8u) | b;
    }
    case 4u: {
        if (pixel == 0u) {
            return 0u;
        }
        const std::uint32_t r = expand_5_to_8((pixel >> 11u) & 0x1fu);
        const std::uint32_t g = expand_6_to_8((pixel >> 5u) & 0x3fu);
        const std::uint32_t b = expand_5_to_8(pixel & 0x1fu);
        return 0xff000000u | (r << 16u) | (g << 8u) | b;
    }
    case 5u:
    case 6u:
        return pixel | 0xff000000u;
    default:
        return pixel;
    }
}

std::uint32_t __fastcall render_driver_probe_00556d20(void*, void*) {
    const QueryVertex v0 = make_vertex(0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u);
    const QueryVertex v1 = make_vertex(0x43000000u, 0x00000000u, 0x3f800000u, 0x00000000u);
    const QueryVertex v2 = make_vertex(0x43000000u, 0x43000000u, 0x3f800000u, 0x3f800000u);
    const QueryVertex v3 = make_vertex(0x00000000u, 0x43000000u, 0x00000000u, 0x3f800000u);

    const std::uint32_t saved_state2 = render_display_getstate_006bd984(2u);
    const std::uint32_t saved_state7 = render_display_getstate_006bd984(7u);
    const std::uint32_t saved_state10 = render_display_getstate_006bd984(10u);
    const std::uint32_t saved_state3 = render_display_getstate_006bd984(3u);

    render_display_thr_cleanup_00555390();
    render_display_setstate_006bd97c(2u, 0u);
    render_display_setstate_006bd97c(7u, 0u);
    render_display_setstate_006bd97c(10u, 2u);

    const std::uint32_t info_raw = render_display_getstate_006bd984(0x1du);
    const auto* const driver_info =
        reinterpret_cast<const void*>(static_cast<std::uintptr_t>(info_raw));

    render_display_window_006bd9b0(2u);
    render_display_setstate_006bd97c(3u, 0xff000000u);
    render_display_set_texture_006bd954(0u);
    render_display_clear_window_006bd91c();

    void* const tex_desc = render_display_texture_create_00535950(0x80u, 0x80u, 0x10u, 0u);
    render_display_texture_bind_00534480(tex_desc);
    render_display_fill_00537e00(0xff000000u);

    for (std::int32_t x = 0; x < 0x80; x += 2) {
        render_display_select_buffer_00556910(static_cast<std::uint32_t>(x), 0u, 1u);
    }

    void* const tex_alloc = render_display_texture_alloc_00554960(
        0x80u, 0x80u, 4u, 0u, 0u, render_driver_query_uv_test_005cf814);
    render_display_texture_update_005550e0();
    const auto* const src_pixels = static_cast<const std::uint8_t*>(read_ptr(tex_desc, 0x28u));
    render_display_texture_copy_00554d70(
        tex_alloc, const_cast<std::uint8_t*>(src_pixels + 0x10u), 0u);
    render_display_texture_release_00555440(tex_alloc);

    render_display_draw_quad_006bd9a8(&v0, &v1, &v2, &v3);
    render_display_flush_006bd970();
    render_display_sync_006bd978(0u);
    render_display_window_006bd9b0(2u);

    const std::uint32_t mode = read_u32(driver_info, 8u);
    const std::uint32_t bpp_bytes = mode_bytes_per_pixel(mode);
    auto* const pbuf = static_cast<std::uint8_t*>(
        render_display_buffer_alloc_00531ca0(
            render_driver_query_pbuf_tag_005cf80c, 140u * bpp_bytes, 0u));
    render_display_read_rect_006bd96c(0u, 0u, 0x80u, 1u, pbuf);

    std::uint32_t zero_count = 0u;
    const std::uint8_t* cursor = pbuf;
    for (std::uint32_t i = 0u; i < 0x80u; ++i) {
        const std::uint32_t bits = mode_bit_width(mode);
        const std::uint32_t pixel = read_pixel_by_bits(cursor, bits);
        if ((render_pixel_to_argb8888_00557240(pixel, mode) & 0xffu) == 0u) {
            ++zero_count;
        }
        cursor += bpp_bytes;
    }

    const std::uint32_t mismatch = (zero_count != 0x40u) ? 1u : 0u;
    render_display_thr_cleanup_00555390();
    render_display_release_texture_00533f80(tex_desc);

    render_display_setstate_006bd97c(2u, saved_state2);
    render_display_setstate_006bd97c(7u, saved_state7);
    render_display_setstate_006bd97c(10u, saved_state10);
    render_display_setstate_006bd97c(3u, saved_state3);

    return (mismatch != 0u) ? 1u : 0u;
}

} // namespace porsche
