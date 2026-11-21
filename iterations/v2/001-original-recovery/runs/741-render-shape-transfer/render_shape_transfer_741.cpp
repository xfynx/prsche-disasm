// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00571630..00571984 (853B) and 005719c0..00571a04 (69B).
#include "render_shape_transfer_741.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char render_shape_invalid_fmt_005c073c[37] = "movdfl - INVALID SHAPE TYPE ($%02x)\n";
const char render_shape_source_file_005c0764[18] = "\\real\\pc\\movdfl.c";

RenderShapeSpanFn render_shape_stage1_fn_006a6424 = nullptr;
RenderShapeSpanFn render_shape_stage2_fn_006a6428 = nullptr;

namespace {

std::int32_t sar3(std::int32_t value) {
    const std::uint32_t u = static_cast<std::uint32_t>(value);
    const std::uint32_t sign = (value < 0) ? 0xe0000000u : 0u;
    return static_cast<std::int32_t>((u >> 3u) | sign);
}

std::uint32_t read_u32(const void* ptr) {
    std::uint32_t v = 0u;
    std::memcpy(&v, ptr, sizeof v);
    return v;
}

std::int16_t read_i16(const void* ptr, std::size_t offset) {
    std::int16_t v = 0;
    std::memcpy(&v, static_cast<const std::uint8_t*>(ptr) + offset, sizeof v);
    return v;
}

} // namespace

void __cdecl render_shape_two_stage_span_005719c0(
    void* dst, const void* src, std::uint32_t count) {
    std::uint8_t scratch[0x1900];
    render_shape_stage1_fn_006a6424(scratch, src, count);
    render_shape_stage2_fn_006a6428(dst, scratch, count);
}

void __cdecl render_shape_transfer_00571630(
    const void* shape, std::int32_t x, std::int32_t y, const void* const* table) {
    void* allocated_shape = nullptr;
    if (render_descriptor_bits_00537f90(shape) == 0u) {
        const std::uint32_t bad_type = read_u32(shape) & 0xffu;
        shared_runtime_word_005deb74 = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(&render_shape_source_file_005c0764[0]));
        shared_runtime_word_005deb78 = 0x2au;
        reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t)>(
            diagnostic_handler_005debf0)(
            &render_shape_invalid_fmt_005c073c[0], bad_type);
    }

    const std::uint32_t cfg_2c = window_shutdown_config_005de620[3];
    std::uint32_t target_type = cfg_2c & 0xffu;
    render_shape_stage1_fn_006a6424 = nullptr;
    const void* span_fn = table[5];
    const auto override_type = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(table[7]));
    if (override_type != 0u) {
        target_type = override_type;
    }
    const void* active_shape = shape;
    if (span_fn == nullptr && (read_u32(shape) & 0xffu) != target_type) {
        const auto mode_flag = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(table[6]));
        const std::int32_t direct_mode = (mode_flag != 2u) ? 1 : 0;
        void* const conv_fn = render_shape_row_converter_00534b90(
            shape, target_type, direct_mode);
        span_fn = conv_fn;
        if (conv_fn == nullptr) {
            allocated_shape = render_shape_convert_type_00534d40(
                shape, target_type, (mode_flag == 1u) ? 1 : 0, direct_mode);
            active_shape = allocated_shape;
        } else if (mode_flag != 2u) {
            span_fn = nullptr;
            render_shape_stage1_fn_006a6424 =
                reinterpret_cast<RenderShapeSpanFn>(conv_fn);
        }
    }

    std::int32_t width = read_i16(active_shape, 4u);
    std::int32_t height = read_i16(active_shape, 6u);
    const auto* src_ptr = static_cast<const std::uint8_t*>(active_shape) + 0x10u;
    const std::int32_t even_bpp = static_cast<std::int32_t>(
        (render_descriptor_bits_00537f90(active_shape) + 1u) & 0xfffffffeu);
    const std::int32_t full_src_row_bytes = sar3(even_bpp * width);
    std::int32_t src_stride_gap =
        splash_shape_row_stride_005712f0(active_shape) - full_src_row_bytes;

    const std::int32_t clip_top = static_cast<std::int32_t>(window_shutdown_config_005de620[6]);
    const std::int32_t top_delta = clip_top - y;
    if (top_delta > 0) {
        src_ptr += full_src_row_bytes * top_delta;
        height -= top_delta;
        y += top_delta;
    }
    const std::int32_t clip_bottom = static_cast<std::int32_t>(window_shutdown_config_005de620[8]);
    const std::int32_t bot_delta = height - clip_bottom + y;
    if (bot_delta > 0) {
        height -= bot_delta;
    }
    const std::int32_t clip_left = static_cast<std::int32_t>(window_shutdown_config_005de620[5]);
    const std::int32_t left_delta = clip_left - x;
    if (left_delta > 0) {
        const std::int32_t skip = sar3(left_delta * even_bpp);
        src_ptr += skip;
        width -= left_delta;
        x += left_delta;
        src_stride_gap += skip;
    }
    const std::int32_t clip_right = static_cast<std::int32_t>(window_shutdown_config_005de620[7]);
    const std::int32_t right_delta = width - clip_right + x;
    if (right_delta > 0) {
        src_stride_gap += sar3(right_delta * even_bpp);
        width -= right_delta;
    }

    if (width > 0 && height > 0) {
        const std::int32_t src_row_bytes = sar3(even_bpp * width);
        const std::int32_t dst_storage_bits =
            static_cast<std::int32_t>((cfg_2c >> 16u) & 0xffu);
        const std::int32_t dst_row_bytes = sar3(dst_storage_bits * width);
        std::int32_t dst_offset = render_pixel_offset_00574080(x, y);
        auto* const dst_base = reinterpret_cast<std::uint8_t*>(
            static_cast<std::uintptr_t>(window_shutdown_state_005de64c));
        const std::int32_t dst_stride_gap =
            static_cast<std::int32_t>(window_shutdown_config_005de620[9]) - dst_row_bytes;

        if (span_fn == nullptr) {
            switch ((cfg_2c >> 8u) & 0xffu) {
            case 8u:
                span_fn = table[0];
                break;
            case 15u:
                span_fn = table[1];
                break;
            case 16u:
                span_fn = table[2];
                break;
            case 24u:
                span_fn = table[3];
                break;
            case 32u:
                span_fn = table[4];
                break;
            default:
                break;
            }
        }

        if (render_shape_stage1_fn_006a6424 != nullptr) {
            render_shape_stage2_fn_006a6428 = reinterpret_cast<RenderShapeSpanFn>(
                const_cast<void*>(span_fn));
            span_fn = reinterpret_cast<const void*>(&render_shape_two_stage_span_005719c0);
        }

        auto* const fn = reinterpret_cast<RenderShapeSpanFn>(const_cast<void*>(span_fn));
        if (dst_stride_gap == 0 && src_stride_gap == 0 &&
            fn != &render_shape_two_stage_span_005719c0) {
            fn(dst_base + dst_offset, src_ptr, static_cast<std::uint32_t>(height * width));
        } else {
            const std::int32_t src_step = src_row_bytes + src_stride_gap;
            const std::int32_t dst_step = dst_row_bytes + dst_stride_gap;
            std::int32_t rows = height;
            do {
                fn(dst_base + dst_offset, src_ptr, static_cast<std::uint32_t>(width));
                src_ptr += src_step;
                dst_offset += dst_step;
                --rows;
            } while (rows != 0);
        }
    }

    if (allocated_shape != nullptr) {
        (void)free_00531f90(allocated_shape);
    }
}

} // namespace porsche
