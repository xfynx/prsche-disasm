// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "render_driver_draw_890.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

#include "porsche/application_alloc.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

extern std::int32_t render_fill_backend_005decd8;

std::uint32_t __cdecl render_descriptor_format_00556880(std::uint32_t format);
std::uint32_t __cdecl render_descriptor_bits_00537f90(const void* descriptor_format);
std::int32_t __cdecl splash_shape_row_stride_005712f0(const void* shape);
void* __cdecl scene_texture_shape_create_00574c70(
    std::int32_t width, std::int32_t height,
    std::int32_t depth, std::uint32_t flags);
void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode);
void __cdecl render_shape_transfer_00571630(
    const void* shape, std::int32_t x, std::int32_t y, const void* const* table);
void __cdecl render_mmx_empty_00573070();

std::uint32_t render_choptex_color_005dfb7c = 0xffffffffu;
RenderChopTex* render_choptex_handle_006a6450 = nullptr;

namespace {

template <typename Fn>
const void* fn_slot(Fn* fn) {
    return reinterpret_cast<const void*>(fn);
}

const void* token_slot(std::uintptr_t v) {
    return reinterpret_cast<const void*>(v);
}

std::int16_t read_i16(const void* ptr, std::size_t offset) {
    std::int16_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(ptr) + offset, sizeof(value));
    return value;
}

std::uint32_t read_u32(const void* ptr, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(ptr) + offset, sizeof(value));
    return value;
}

void write_u32(void* ptr, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(ptr) + offset, &value, sizeof(value));
}

struct ChopVertex {
    float x;
    float y;
    float z;
    float rhw;
    std::uint32_t color;
    std::uint32_t specular;
    float u;
    float v;
};
static_assert(sizeof(ChopVertex) == 32u, "32-byte quad vertex");

using ThrashAboutFn = const std::uint32_t*(__stdcall*)();
using ThrashGetStateFn = std::uint32_t(__stdcall*)(std::uint32_t key);
using ThrashSetStateFn = void(__stdcall*)(std::uint32_t key, std::uint32_t value);
using ThrashSetTextureFn = void(__stdcall*)(std::uint32_t texture);
using ThrashTAllocFn = std::uint32_t(__stdcall*)(
    std::uint32_t width, std::uint32_t height, std::uint32_t depth,
    std::uint32_t z0, std::uint32_t z1);
using ThrashTFreeFn = std::int32_t(__stdcall*)(std::uint32_t texture);
using ThrashTUpdateFn = void(__stdcall*)(
    std::uint32_t texture, void* pixels, std::uint32_t zero);
using ThrashDrawQuadFn = void(__stdcall*)(
    const void* v0, const void* v1, const void* v2, const void* v3);
using RowConverterFn = void(__cdecl*)(void* dst, const void* src, std::int32_t count);

template <typename Fn>
Fn thrash_slot(std::uint32_t va) {
    const std::size_t idx = static_cast<std::size_t>((va - 0x006bd910u) / 4u);
    return reinterpret_cast<Fn>(static_cast<std::uintptr_t>(render_thrash_exports_006bd910[idx]));
}

} // namespace

const void* const render_span_table_scalar_005dec38[8] = {
    fn_slot(&heap_copy_005b0000),
    fn_slot(&render_span_scalar_16_0053d390),
    fn_slot(&render_span_scalar_16_0053d390),
    fn_slot(&render_span_scalar_24_0053d3b0),
    fn_slot(&render_span_scalar_32_0053d3d0),
    nullptr,
    token_slot(2u),
    nullptr,
};

const void* const render_span_table_fpu_005dec58[8] = {
    fn_slot(&heap_copy_005b0c00),
    fn_slot(&render_span_fpu_16_0053d3f0),
    fn_slot(&render_span_fpu_16_0053d3f0),
    fn_slot(&render_span_fpu_24_0053d410),
    fn_slot(&render_span_fpu_32_0053d430),
    nullptr,
    token_slot(2u),
    nullptr,
};

const void* const render_span_table_mmx_a_005dec78[8] = {
    fn_slot(&heap_copy_005b0100),
    fn_slot(&render_span_mmx_a_16_0053d450),
    fn_slot(&render_span_mmx_a_16_0053d450),
    fn_slot(&render_span_mmx_a_24_0053d470),
    fn_slot(&render_span_mmx_a_32_0053d490),
    nullptr,
    token_slot(2u),
    nullptr,
};

const void* const render_span_table_mmx_b_005dec98[8] = {
    fn_slot(&heap_copy_005b02c0),
    fn_slot(&render_span_mmx_b_16_0053d4b0),
    fn_slot(&render_span_mmx_b_16_0053d4b0),
    fn_slot(&render_span_mmx_b_24_0053d4d0),
    fn_slot(&render_span_mmx_b_32_0053d4f0),
    nullptr,
    token_slot(2u),
    nullptr,
};

const void* const render_span_table_sse_005decb8[8] = {
    fn_slot(&heap_copy_005b0480),
    fn_slot(&render_span_sse_16_0053d510),
    fn_slot(&render_span_sse_16_0053d510),
    fn_slot(&render_span_sse_24_0053d530),
    fn_slot(&render_span_sse_32_0053d550),
    nullptr,
    token_slot(2u),
    nullptr,
};

const void* const* const render_span_tables_005decdc[5] = {
    render_span_table_scalar_005dec38,
    render_span_table_fpu_005dec58,
    render_span_table_mmx_a_005dec78,
    render_span_table_mmx_b_005dec98,
    render_span_table_sse_005decb8,
};

void __cdecl splash_progress_driver_draw_0053d570(
    std::uint32_t texture, std::int32_t x, std::int32_t y) {
    const std::uint8_t mode = window_shutdown_mode_005de630;
    if (mode != 0u && mode != 0xffu && window_shutdown_state_005de64c == 0u) {
        const auto get_state = thrash_slot<ThrashGetStateFn>(0x006bd984u);
        const auto set_state = thrash_slot<ThrashSetStateFn>(0x006bd97cu);
        const std::uint32_t saved_a = get_state(0xau);
        const std::uint32_t saved_1 = get_state(1u);
        if (render_choptex_handle_006a6450 == nullptr) {
            const auto about_fn = thrash_slot<ThrashAboutFn>(0x006bd934u);
            const std::uint32_t* const about = about_fn();
            const auto* const caps = reinterpret_cast<const std::uint8_t*>(
                static_cast<std::uintptr_t>(about[0x30u / 4u]));
            const std::uint32_t bits = read_u32(caps, 0x18u);
            const std::int32_t depth = ((bits & 3u) == 1u) ? 6 : 7;
            render_choptex_handle_006a6450 = render_choptex_create_00572a90(64, 64, depth, 0u);
        }
        set_state(0xau, 0u);
        const auto* const shape = reinterpret_cast<const void*>(static_cast<std::uintptr_t>(texture));
        const std::int32_t w = read_i16(shape, 4u);
        const std::int32_t h = read_i16(shape, 6u);
        render_choptex_draw_00572b40(render_choptex_handle_006a6450, shape, x, y, w, h);
        if (render_choptex_free_00572ee0(render_choptex_handle_006a6450) != 0) {
            render_choptex_handle_006a6450 = nullptr;
        }
        set_state(0xau, saved_a);
        thrash_slot<ThrashSetTextureFn>(0x006bd954u)(saved_1);
        return;
    }

    std::int32_t backend = render_fill_backend_005decd8;
    if (backend < 0) {
        if (shared_runtime_word_005deb1c != 0u) {
            backend = 4;
        } else {
            backend = (copy_flag_005deb18 != 0u) ? 3 : 0;
        }
        render_fill_backend_005decd8 = backend;
    }
    const auto* const shape = reinterpret_cast<const void*>(static_cast<std::uintptr_t>(texture));
    render_shape_transfer_00571630(shape, x, y, render_span_tables_005decdc[backend]);
    if (render_fill_backend_005decd8 == 3) {
        render_mmx_empty_00573070();
    }
}

RenderChopTex* __cdecl render_choptex_create_00572a90(
    std::int32_t width, std::int32_t height, std::int32_t depth, std::uint32_t flags) {
    const std::uint32_t fmt = render_descriptor_format_00556880(static_cast<std::uint32_t>(depth));
    const std::uint32_t bpp = render_descriptor_bits_00537f90(&fmt);
    auto* const chop = static_cast<RenderChopTex*>(
        application_allocator_entry_00531f70("CHOP texes", 0xcu, flags));
    if (chop == nullptr) {
        return nullptr;
    }
    heap_fill_0053c290(chop, 0u, 0xcu);
    void* const tile = scene_texture_shape_create_00574c70(
        width, height, static_cast<std::int32_t>(bpp), flags);
    chop->tile_shape = tile;
    if (tile == nullptr) {
        return nullptr;
    }
    const std::uint32_t head = read_u32(tile, 0u);
    write_u32(tile, 0u, (head & 0xffffff00u) | (fmt & 0xffu));
    const auto talloc = thrash_slot<ThrashTAllocFn>(0x006bd968u);
    chop->textures[0] = talloc(
        static_cast<std::uint32_t>(width), static_cast<std::uint32_t>(height),
        static_cast<std::uint32_t>(depth), 0u, 0u);
    if (chop->textures[0] == 0u) {
        return nullptr;
    }
    chop->textures[1] = talloc(
        static_cast<std::uint32_t>(width), static_cast<std::uint32_t>(height),
        static_cast<std::uint32_t>(depth), 0u, 0u);
    if (chop->textures[1] == 0u) {
        return nullptr;
    }
    return chop;
}

std::int32_t __cdecl render_choptex_draw_00572b40(
    RenderChopTex* chop, const void* shape, std::int32_t x, std::int32_t y,
    std::int32_t dst_w, std::int32_t dst_h) {
    void* const tile_shape = chop->tile_shape;
    const std::int32_t src_h = read_i16(shape, 6u);
    const std::int32_t src_w = read_i16(shape, 4u);
    const std::int32_t tile_h = read_i16(tile_shape, 6u);
    const std::int32_t tile_w = read_i16(tile_shape, 4u);
    const std::int32_t bytes_per_pixel =
        static_cast<std::int32_t>(render_descriptor_bits_00537f90(shape) + 7u) >> 3;
    const std::int32_t src_stride = splash_shape_row_stride_005712f0(shape);
    std::int32_t tex_idx = 0;

    const float scale_x = static_cast<float>(static_cast<double>(dst_w) / static_cast<double>(src_w));
    const float scale_y = static_cast<float>(static_cast<double>(dst_h) / static_cast<double>(src_h));

    const std::uint32_t tile_type = read_u32(tile_shape, 0u) & 0xffu;
    const auto conv_fn = reinterpret_cast<RowConverterFn>(
        render_shape_row_converter_00534b90(shape, tile_type, 1));
    if (conv_fn == nullptr) {
        return 0;
    }

    const std::int32_t row_tiles = (tile_h + src_h - 1) / tile_h;
    std::int32_t y_start = 0;
    if (row_tiles < 1) {
        return 1;
    }

    const std::int32_t col_tiles = (tile_w + src_w - 1) / tile_w;
    std::int32_t y_end_bound = tile_h;
    const auto tupdate = thrash_slot<ThrashTUpdateFn>(0x006bd940u);
    const auto tsettexture = thrash_slot<ThrashSetTextureFn>(0x006bd954u);
    const auto drawquad = thrash_slot<ThrashDrawQuadFn>(0x006bd9a8u);

    for (std::int32_t y_tile = 0; y_tile < row_tiles; ++y_tile) {
        const std::int32_t y_end = (y_end_bound > src_h) ? (y_start + (src_h % tile_h)) : (y_start + tile_h);
        const std::int32_t copy_h = y_end - y_start;
        if (col_tiles >= 1) {
            std::int32_t x_start = 0;
            std::int32_t x_end_bound = tile_w;
            for (std::int32_t x_tile = 0; x_tile < col_tiles; ++x_tile) {
                const std::int32_t x_end = (x_end_bound > src_w) ? (x_start + (src_w % tile_w)) : (x_start + tile_w);
                const std::int32_t copy_w = x_end - x_start;
                if (copy_h > 0) {
                    const auto* src_row = static_cast<const std::uint8_t*>(shape) + 0x10 +
                        y_start * src_stride + x_start * bytes_per_pixel;
                    for (std::int32_t row = 0; row < copy_h; ++row) {
                        const std::int32_t tile_stride = splash_shape_row_stride_005712f0(tile_shape);
                        auto* const dst_row = static_cast<std::uint8_t*>(tile_shape) + 0x10 + row * tile_stride;
                        conv_fn(dst_row, src_row, copy_w);
                        src_row += src_stride;
                    }
                }
                const float x0 = static_cast<float>(static_cast<double>(x) + static_cast<double>(x_start) * scale_x);
                const float y0 = static_cast<float>(static_cast<double>(y) + static_cast<double>(y_start) * scale_y);
                const float x1 = static_cast<float>(static_cast<double>(x) + static_cast<double>(x_end) * scale_x);
                const float y1 = static_cast<float>(static_cast<double>(y) + static_cast<double>(y_end) * scale_y);
                const float u_max = static_cast<float>(static_cast<double>(copy_w) / static_cast<double>(tile_w));
                const float v_max = static_cast<float>(static_cast<double>(copy_h) / static_cast<double>(tile_h));
                const std::uint32_t c = render_choptex_color_005dfb7c;
                const ChopVertex v0 = {x0, y0, 0.0f, 1.0f, c, 0u, 0.0f, 0.0f};
                const ChopVertex v1 = {x1, y0, 0.0f, 1.0f, c, 0u, u_max, 0.0f};
                const ChopVertex v2 = {x1, y1, 0.0f, 1.0f, c, 0u, u_max, v_max};
                const ChopVertex v3 = {x0, y1, 0.0f, 1.0f, c, 0u, 0.0f, v_max};
                const std::uint32_t tex = chop->textures[tex_idx];
                tupdate(tex, static_cast<std::uint8_t*>(tile_shape) + 0x10, 0u);
                tsettexture(tex);
                drawquad(&v0, &v1, &v2, &v3);
                tex_idx ^= 1;
                x_start = x_end;
                x_end_bound += tile_w;
            }
        }
        y_start = y_end;
        y_end_bound += tile_h;
    }
    return 1;
}

std::int32_t __cdecl render_choptex_free_00572ee0(RenderChopTex* chop) {
    std::int32_t ok = 1;
    if (chop != nullptr) {
        const auto tfree = thrash_slot<ThrashTFreeFn>(0x006bd94cu);
        if (chop->textures[0] != 0u) {
            ok = tfree(chop->textures[0]);
        }
        if (chop->textures[1] != 0u) {
            ok = tfree(chop->textures[1]);
        }
        if (ok != 0) {
            if (chop->tile_shape != nullptr) {
                (void)free_00531f90(chop->tile_shape);
            }
            (void)free_00531f90(chop);
        }
    }
    return ok;
}

void __cdecl heap_copy_005b0c00(void* dst, const void* src, std::uint32_t bytes) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    std::int32_t rem = static_cast<std::int32_t>(bytes);
    const std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(d);
    if ((addr & 7u) != 0u) {
        if ((addr & 1u) != 0u && rem >= 1) {
            *d++ = *s++;
            rem -= 1;
        }
        if ((addr & 2u) != 0u && rem >= 2) {
            std::memcpy(d, s, 2u);
            d += 2;
            s += 2;
            rem -= 2;
        }
        if ((addr & 4u) != 0u && rem >= 4) {
            std::memcpy(d, s, 4u);
            d += 4;
            s += 4;
            rem -= 4;
        }
    }
    if (rem > 0) {
        std::memcpy(d, s, static_cast<std::size_t>(rem));
    }
}

void __cdecl render_span_scalar_16_0053d390(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0000(dst, src, count * 2u);
}
void __cdecl render_span_scalar_24_0053d3b0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0000(dst, src, count * 3u);
}
void __cdecl render_span_scalar_32_0053d3d0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0000(dst, src, count * 4u);
}
void __cdecl render_span_fpu_16_0053d3f0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0c00(dst, src, count * 2u);
}
void __cdecl render_span_fpu_24_0053d410(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0c00(dst, src, count * 3u);
}
void __cdecl render_span_fpu_32_0053d430(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0c00(dst, src, count * 4u);
}
void __cdecl render_span_mmx_a_16_0053d450(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0100(dst, src, count * 2u);
}
void __cdecl render_span_mmx_a_24_0053d470(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0100(dst, src, count * 3u);
}
void __cdecl render_span_mmx_a_32_0053d490(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0100(dst, src, count * 4u);
}
void __cdecl render_span_mmx_b_16_0053d4b0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b02c0(dst, src, count * 2u);
}
void __cdecl render_span_mmx_b_24_0053d4d0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b02c0(dst, src, count * 3u);
}
void __cdecl render_span_mmx_b_32_0053d4f0(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b02c0(dst, src, count * 4u);
}
void __cdecl render_span_sse_16_0053d510(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0480(dst, src, count * 2u);
}
void __cdecl render_span_sse_24_0053d530(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0480(dst, src, count * 3u);
}
void __cdecl render_span_sse_32_0053d550(void* dst, const void* src, std::uint32_t count) {
    heap_copy_005b0480(dst, src, count * 4u);
}

} // namespace porsche
