// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00537e00..00537e2c (45B), 00562680..005627ef (368B),
// and span-fill leaves 00562500..00562670 (306B across 10 entries).
#include "render_fill_734.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::int32_t render_fill_backend_005decd8 = -1;

std::uint32_t render_fill_color_006a5bb8 = 0u;

void* __cdecl render_fill_span_scalar_8_00562500(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_scalar_005b0980_core(dst, render_fill_color_006a5bb8, count);
}

void* __cdecl render_fill_span_scalar_16_00562520(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_scalar_005b0980_core(dst, render_fill_color_006a5bb8, count * 2u);
}

void* __cdecl render_fill_span_24_00562540(
    void* dst, std::uint32_t, std::uint32_t count) {
    auto* out = static_cast<std::uint8_t*>(dst);
    void* result = out;
    do {
        const std::uint32_t pixel = render_buffer_read_word_0056e2a8(out, 3);
        result = render_buffer_word_0056e301(out, pixel, 3);
        out += 3;
        --count;
    } while (count != 0u);
    return result;
}

void* __cdecl render_fill_span_scalar_32_00562570(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_scalar_005b0980_core(dst, render_fill_color_006a5bb8, count * 4u);
}

void* __cdecl render_fill_span_mmx_8_005625a0(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_mmx_005b0a40_core(dst, render_fill_color_006a5bb8, count);
}

void* __cdecl render_fill_span_mmx_16_005625c0(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_mmx_005b0a40_core(dst, render_fill_color_006a5bb8, count * 2u);
}

void* __cdecl render_fill_span_mmx_32_005625e0(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_mmx_005b0a40_core(dst, render_fill_color_006a5bb8, count * 4u);
}

void* __cdecl render_fill_span_sse_8_00562610(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_sse_005b0b00_core(dst, render_fill_color_006a5bb8, count);
}

void* __cdecl render_fill_span_sse_16_00562630(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_sse_005b0b00_core(dst, render_fill_color_006a5bb8, count * 2u);
}

void* __cdecl render_fill_span_sse_32_00562650(
    void* dst, std::uint32_t, std::uint32_t count) {
    return heap_fill_sse_005b0b00_core(dst, render_fill_color_006a5bb8, count * 4u);
}

const void* const render_fill_table_scalar_005df880[8] = {
    reinterpret_cast<const void*>(&render_fill_span_scalar_8_00562500),
    reinterpret_cast<const void*>(&render_fill_span_scalar_16_00562520),
    reinterpret_cast<const void*>(&render_fill_span_scalar_16_00562520),
    reinterpret_cast<const void*>(&render_fill_span_24_00562540),
    reinterpret_cast<const void*>(&render_fill_span_scalar_32_00562570),
    nullptr,
    nullptr,
    nullptr,
};

const void* const render_fill_table_mmx_005df8a0[8] = {
    reinterpret_cast<const void*>(&render_fill_span_mmx_8_005625a0),
    reinterpret_cast<const void*>(&render_fill_span_mmx_16_005625c0),
    reinterpret_cast<const void*>(&render_fill_span_mmx_16_005625c0),
    reinterpret_cast<const void*>(&render_fill_span_24_00562540),
    reinterpret_cast<const void*>(&render_fill_span_mmx_32_005625e0),
    nullptr,
    nullptr,
    nullptr,
};

const void* const render_fill_table_sse_005df8c0[8] = {
    reinterpret_cast<const void*>(&render_fill_span_sse_8_00562610),
    reinterpret_cast<const void*>(&render_fill_span_sse_16_00562630),
    reinterpret_cast<const void*>(&render_fill_span_sse_16_00562630),
    reinterpret_cast<const void*>(&render_fill_span_24_00562540),
    reinterpret_cast<const void*>(&render_fill_span_sse_32_00562650),
    nullptr,
    nullptr,
    nullptr,
};

const void* const* const render_fill_mode_tables_005df8e0[5] = {
    render_fill_table_scalar_005df880,
    render_fill_table_scalar_005df880,
    render_fill_table_scalar_005df880,
    render_fill_table_mmx_005df8a0,
    render_fill_table_sse_005df8c0,
};

namespace {

std::uint32_t signed_fild_fstp_bits(std::int32_t value) {
    std::uint32_t bits = 0u;
    __asm {
        fild dword ptr value
        fstp dword ptr bits
    }
    return bits;
}

struct RenderFillShapeLocal {
    std::uint32_t type_00;
    std::uint16_t width_04;
    std::uint16_t height_06;
    std::uint32_t opaque_08[3];
};

} // namespace

void __cdecl splash_progress_draw_text_00562680(
    std::int32_t x, std::int32_t y,
    std::uint32_t value, std::uint32_t font, std::uint32_t color) {
    const std::uint8_t mode_byte = window_shutdown_mode_005de630;
    if (mode_byte != 0u && mode_byte != 0xffu && window_shutdown_state_005de64c == 0u) {
        const std::uint32_t saved_state_10 = render_display_getstate_006bd984(0x0au);
        const std::uint32_t saved_state_1 = render_display_getstate_006bd984(0x01u);
        render_display_setstate_006bd97c(0x0au, 0u);
        render_display_set_texture_006bd954(0u);
        const std::uint32_t converted = render_buffer_convert_00574b70(color);
        const std::uint32_t h_bits = signed_fild_fstp_bits(static_cast<std::int32_t>(font));
        const std::uint32_t w_bits = signed_fild_fstp_bits(static_cast<std::int32_t>(value));
        const std::uint32_t y_bits = signed_fild_fstp_bits(y);
        const std::uint32_t x_bits = signed_fild_fstp_bits(x);
        render_draw_rectangle_bits_0056daf0(x_bits, y_bits, w_bits, h_bits, converted);
        render_display_setstate_006bd97c(0x0au, saved_state_10);
        render_display_set_texture_006bd954(saved_state_1);
        return;
    }

    const std::uint32_t cfg_2c = window_shutdown_config_005de620[3];
    const std::uint32_t bpp = (cfg_2c >> 8u) & 0xffu;
    std::uint32_t packed_color = color;
    switch (bpp) {
    case 4u: {
        const std::uint32_t low = color & 0x0fu;
        packed_color = low | (low << 4u);
        break;
    }
    case 8u: {
        const std::uint32_t low = color & 0xffu;
        const std::uint32_t word = low | (low << 8u);
        packed_color = word | (word << 16u);
        break;
    }
    case 15u:
    case 16u: {
        const std::uint32_t low = color & 0xffffu;
        packed_color = low | (low << 16u);
        break;
    }
    default:
        break;
    }
    render_fill_color_006a5bb8 = packed_color;

    std::int32_t backend = render_fill_backend_005decd8;
    if (backend < 0) {
        if (copy_flag_005deb1c != 0u) {
            backend = 4;
        } else {
            backend = (copy_flag_005deb18 != 0u) ? 3 : 0;
        }
        render_fill_backend_005decd8 = backend;
    }

    RenderFillShapeLocal desc;
    desc.type_00 = cfg_2c & 0xffu;
    desc.width_04 = static_cast<std::uint16_t>(value);
    desc.height_06 = static_cast<std::uint16_t>(font);
    render_shape_transfer_00571630(
        &desc, x, y, render_fill_mode_tables_005df8e0[backend]);
    if (render_fill_backend_005decd8 == 3) {
        render_mmx_empty_00573070();
    }
}

void __cdecl render_display_fill_00537e00(std::uint32_t color) {
    const std::uint32_t clip_bottom = window_shutdown_config_005de620[8];
    const std::uint32_t clip_right = window_shutdown_config_005de620[7];
    const std::uint32_t clip_top = window_shutdown_config_005de620[6];
    const std::uint32_t clip_left = window_shutdown_config_005de620[5];
    splash_progress_draw_text_00562680(
        static_cast<std::int32_t>(clip_left),
        static_cast<std::int32_t>(clip_top),
        clip_right - clip_left,
        clip_bottom - clip_top,
        color);
}

} // namespace porsche
