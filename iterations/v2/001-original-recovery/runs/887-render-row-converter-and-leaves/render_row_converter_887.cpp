// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "render_row_converter_887.hpp"

#include <cstddef>
#include <cstdint>

#include "porsche/heap.hpp"

namespace porsche {

extern const std::uint8_t* render_color_lut_0069e0ac;
extern std::uint32_t render_palette_color_key_006a6420;

std::int32_t __cdecl render_shape_type_to_depth_index_005345e0(std::uint32_t shape_type);
std::uint32_t __cdecl render_descriptor_bits_00537f90(const void* descriptor_format);
std::uint32_t* __cdecl render_getclutptr_from_resource_005346d0(
    const void* descriptor, std::uint32_t* palette);
std::uint32_t __cdecl render_color_pack_00537ed0(std::uint32_t color);
void __cdecl render_palette_swap_rb555_00570260(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_565_to_1555_005702a0(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_8888_to_1555_alpha_00570330(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_888_to_1555_00570370(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_555_to_565_00570420(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_8888_to_565_alpha_005704c0(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_888_to_565_00570510(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_8888_to_4444_00570540(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_5551_to_8888_key_00570780(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_565_to_8888_key_00570820(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);

std::uint32_t* render_depthconv_palette_ptr_005de2f8 = nullptr;
std::uint32_t render_depthconv_palette_scratch_006bda20[256] = {};

namespace {

template <typename Fn>
const void* fn_slot(Fn* fn) {
    return reinterpret_cast<const void*>(fn);
}

constexpr std::uint8_t kIntermediateTypes_005de4fc[64] = {
    0x7au,0x7bu,0x7eu,0x78u,0x7bu,0x7bu,0x7bu,0x7eu,0x7au,0x7bu,0x7eu,0x78u,0x7fu,0x7du,0x6du,0x7eu,
    0x78u,0x78u,0x7eu,0x78u,0x78u,0x7du,0x7du,0x42u,0x7bu,0x7bu,0x7eu,0x78u,0x7fu,0x7du,0x6du,0x7eu,
    0x7du,0x7du,0x7du,0x7du,0x7fu,0x7du,0x7du,0x7du,0x78u,0x78u,0x7eu,0x78u,0x7fu,0x7du,0x6du,0x7eu,
    0x7du,0x7du,0x7du,0x7du,0x7du,0x7du,0x6du,0x7du,0x7eu,0x7eu,0x7eu,0x7eu,0x7eu,0x7eu,0x7eu,0x42u,
};

const void* const kDirectCallbacks_005de2fc[64] = {
    fn_slot(&render_row_4_copy_005700d0),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_16_lut_005703a0),
    fn_slot(&render_row_4_to_16_lut_005703a0),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_16_lut_005703a0),

    fn_slot(&render_row_8_to_4_005700f0),
    fn_slot(&render_row_8_copy_00570190),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_24_lut_00570650),
    fn_slot(&render_row_8_to_32_lut_00570750),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_16_lut_005703f0),

    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_5551_to_8888_key_00570780),
    fn_slot(&render_palette_5551_to_8888_key_00570780),
    fn_slot(&render_palette_swap_rb555_00570260),

    fn_slot(&render_row_565_to_8_005701b0),
    fn_slot(&render_row_565_to_8_005701b0),
    fn_slot(&render_palette_565_to_1555_005702a0),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_row_565_to_24_00570690),
    fn_slot(&render_palette_565_to_8888_key_00570820),
    fn_slot(&render_row_565_to_4444_key_005705a0),
    fn_slot(&render_palette_565_to_1555_005702a0),

    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_copy_00570700),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),

    fn_slot(&render_palette_8888_to_565_alpha_005704c0),
    fn_slot(&render_palette_8888_to_565_alpha_005704c0),
    fn_slot(&render_palette_8888_to_1555_alpha_00570330),
    fn_slot(&render_palette_8888_to_565_alpha_005704c0),
    fn_slot(&render_row_8888_to_24_00570720),
    fn_slot(&render_row_32_copy_00570a80),
    fn_slot(&render_palette_8888_to_4444_00570540),
    fn_slot(&render_palette_8888_to_1555_alpha_00570330),

    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_row_4444_to_8888_005708a0),

    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_row_16_copy_00570470),
};

const void* const kAlternateCallbacks_005de3fc[64] = {
    fn_slot(&render_row_4_copy_005700d0),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_16_lut_005703a0),
    fn_slot(&render_row_4_to_16_lut_005703a0),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_8_00570150),
    fn_slot(&render_row_4_to_16_lut_005703a0),

    fn_slot(&render_row_8_to_4_005700f0),
    fn_slot(&render_row_8_copy_00570190),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_24_lut_00570650),
    fn_slot(&render_row_8_to_32_lut_00570750),
    fn_slot(&render_row_8_to_16_lut_005703f0),
    fn_slot(&render_row_8_to_16_lut_005703f0),

    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_555_to_565_00570420),
    fn_slot(&render_palette_5551_to_8888_key_00570780),
    fn_slot(&render_palette_5551_to_8888_key_00570780),
    fn_slot(&render_palette_swap_rb555_00570260),

    fn_slot(&render_row_565_to_8_005701b0),
    fn_slot(&render_row_565_to_8_005701b0),
    fn_slot(&render_row_565_to_1555_005702f0),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_row_565_to_24_00570690),
    fn_slot(&render_palette_565_to_8888_key_00570820),
    fn_slot(&render_row_565_to_4444_key_005705a0),
    fn_slot(&render_row_565_to_1555_005702f0),

    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_copy_00570700),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),
    fn_slot(&render_row_24_to_8888_00570a00),

    fn_slot(&render_palette_888_to_565_00570510),
    fn_slot(&render_palette_888_to_565_00570510),
    fn_slot(&render_palette_888_to_1555_00570370),
    fn_slot(&render_palette_888_to_565_00570510),
    fn_slot(&render_row_8888_to_24_00570720),
    fn_slot(&render_row_32_copy_00570a80),
    fn_slot(&render_palette_8888_to_4444_00570540),
    fn_slot(&render_palette_888_to_1555_00570370),

    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_4444_to_8888_005708a0),
    fn_slot(&render_row_16_copy_00570470),
    fn_slot(&render_row_4444_to_8888_005708a0),

    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_palette_swap_rb555_00570260),
    fn_slot(&render_row_16_copy_00570470),
};

} // namespace

void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode) {
    const auto shape_type = static_cast<std::uint32_t>(
        *static_cast<const std::uint8_t*>(shape));
    const auto source_index = render_shape_type_to_depth_index_005345e0(shape_type);
    const auto target_index = render_shape_type_to_depth_index_005345e0(target_type);
    const std::size_t index = static_cast<std::size_t>(source_index * 8 + target_index);
    const std::uint32_t mapped_type = kIntermediateTypes_005de4fc[index];
    if (mapped_type != target_type) {
        return nullptr;
    }

    const auto callback_source_index =
        render_shape_type_to_depth_index_005345e0(shape_type);
    const auto callback_target_index =
        render_shape_type_to_depth_index_005345e0(target_type);
    const std::size_t callback_index = static_cast<std::size_t>(
        callback_source_index * 8 + callback_target_index);
    const void* const callback = (direct_mode != 0)
        ? kDirectCallbacks_005de2fc[callback_index]
        : kAlternateCallbacks_005de3fc[callback_index];
    const auto source_bits = render_descriptor_bits_00537f90(shape);
    const auto target_bits = render_descriptor_bits_00537f90(&mapped_type);
    if (source_bits < 9u && target_bits > 8u) {
        const std::uint32_t count = 1u << (source_bits & 31u);
        render_depthconv_palette_ptr_005de2f8 =
            render_getclutptr_from_resource_005346d0(
                shape, render_depthconv_palette_scratch_006bda20);
        if (target_type == 0x6du) {
            render_palette_8888_to_4444_00570540(
                reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
        } else if (target_bits == 15u) {
            if (direct_mode != 0) {
                render_palette_8888_to_1555_alpha_00570330(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            } else {
                render_palette_888_to_1555_00570370(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            }
        } else if (target_bits == 16u) {
            if (direct_mode != 0) {
                render_palette_8888_to_565_alpha_005704c0(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            } else {
                render_palette_888_to_565_00570510(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            }
        }
    }
    return const_cast<void*>(callback);
}

void __cdecl render_row_4_copy_005700d0(void* dst, const void* src, std::int32_t count) {
    heap_copy_dispatch_005323e0(dst, src, static_cast<std::uint32_t>((count + 1) >> 1));
}

void __cdecl render_row_8_to_4_005700f0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::size_t byte_index = static_cast<std::size_t>(i >> 1);
        if ((i & 1) != 0) {
            d[byte_index] = static_cast<std::uint8_t>(
                (static_cast<std::uint32_t>(s[i]) << 4) | (d[byte_index] & 0x0fu));
        } else {
            d[byte_index] = static_cast<std::uint8_t>(
                (s[i] & 0x0fu) ^ (d[byte_index] & 0xf0u));
        }
    }
}

void __cdecl render_row_4_to_8_00570150(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint8_t packed = s[i >> 1];
        d[i] = static_cast<std::uint8_t>((i & 1) != 0 ? (packed >> 4) : (packed & 0x0fu));
    }
}

void __cdecl render_row_8_copy_00570190(void* dst, const void* src, std::int32_t count) {
    heap_copy_dispatch_005323e0(dst, src, static_cast<std::uint32_t>(count));
}

void __cdecl render_row_565_to_8_005701b0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint16_t*>(src);
    const std::uint8_t* lut = render_color_lut_0069e0ac;
    if (lut == nullptr) {
        for (std::int32_t i = 0; i < count; ++i) {
            const std::uint32_t p = s[i];
            const std::uint32_t ecx = (p & 0xfffff800u) | 0xffff0000u;
            const std::uint32_t edx = p & 0x07e0u;
            const std::uint32_t eax = p & 0x001fu;
            const std::uint32_t color = (((((ecx << 3) | edx) << 2) | eax) << 3);
            d[i] = static_cast<std::uint8_t>(render_color_pack_00537ed0(color));
        }
        return;
    }
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t p = s[i];
        const std::uint32_t idx =
            ((((p >> 11) << 5) | ((p >> 6) & 0x1fu)) << 5) | (p & 0x1fu);
        d[i] = lut[idx];
    }
}

void __cdecl render_row_565_to_1555_005702f0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint16_t*>(dst);
    const auto* s = static_cast<const std::uint16_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint16_t p = s[i];
        d[i] = static_cast<std::uint16_t>(((p >> 1) & 0x7fe0u) | (p & 0x001fu));
    }
}

void __cdecl render_row_4_to_16_lut_005703a0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint16_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    const auto* lut = reinterpret_cast<const std::uint16_t*>(render_depthconv_palette_scratch_006bda20);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint8_t packed = s[i >> 1];
        const std::uint32_t idx = (i & 1) != 0 ? (packed >> 4) : (packed & 0x0fu);
        d[i] = lut[idx];
    }
}

void __cdecl render_row_8_to_16_lut_005703f0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint16_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    const auto* lut = reinterpret_cast<const std::uint16_t*>(render_depthconv_palette_scratch_006bda20);
    for (std::int32_t i = 0; i < count; ++i) {
        d[i] = lut[s[i]];
    }
}

void __cdecl render_row_16_copy_00570470(void* dst, const void* src, std::int32_t count) {
    heap_copy_dispatch_005323e0(dst, src, static_cast<std::uint32_t>(count) * 2u);
}

void __cdecl render_row_565_to_4444_key_005705a0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint16_t*>(dst);
    const auto* s = static_cast<const std::uint16_t*>(src);
    const std::uint32_t key = render_palette_color_key_006a6420;
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint16_t p = s[i];
        if (static_cast<std::uint32_t>(p) == key) {
            d[i] = 0u;
        } else {
            std::uint16_t bx = static_cast<std::uint16_t>(((p >> 1) & 0xf807u) | (p & 0x0780u));
            bx = static_cast<std::uint16_t>((bx >> 2) | (p & 0x001eu));
            bx = static_cast<std::uint16_t>((bx >> 1) | 0xf000u);
            d[i] = bx;
        }
    }
}

void __cdecl render_row_8_to_24_lut_00570650(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    const auto* lut = reinterpret_cast<const std::uint8_t*>(render_depthconv_palette_ptr_005de2f8);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::size_t off = static_cast<std::size_t>(s[i]) * 4u;
        d[i * 3 + 0] = lut[off + 0];
        d[i * 3 + 1] = lut[off + 1];
        d[i * 3 + 2] = lut[off + 2];
    }
}

void __cdecl render_row_565_to_24_00570690(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint16_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t p = s[i];
        const std::uint32_t b = p & 0x1fu;
        const std::uint32_t g = (p >> 5) & 0x3fu;
        const std::uint32_t r = p >> 11;
        d[i * 3 + 0] = static_cast<std::uint8_t>((b >> 2) | (b << 3));
        d[i * 3 + 1] = static_cast<std::uint8_t>((g >> 4) | (g << 2));
        d[i * 3 + 2] = static_cast<std::uint8_t>((r >> 2) | (r << 3));
    }
}

void __cdecl render_row_24_copy_00570700(void* dst, const void* src, std::int32_t count) {
    heap_copy_dispatch_005323e0(dst, src, static_cast<std::uint32_t>(count) * 3u);
}

void __cdecl render_row_8888_to_24_00570720(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        d[i * 3 + 0] = s[i * 4 + 0];
        d[i * 3 + 1] = s[i * 4 + 1];
        d[i * 3 + 2] = s[i * 4 + 2];
    }
}

void __cdecl render_row_8_to_32_lut_00570750(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint32_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    const std::uint32_t* lut = render_depthconv_palette_ptr_005de2f8;
    for (std::int32_t i = 0; i < count; ++i) {
        d[i] = lut[s[i]];
    }
}

void __cdecl render_row_4444_to_8888_005708a0(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint32_t*>(dst);
    const auto* s = static_cast<const std::uint16_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        const std::uint32_t p = s[i];
        const std::uint32_t n3 = p >> 12;
        const std::uint32_t n2 = (p >> 8) & 0x0fu;
        const std::uint32_t n1 = (p >> 4) & 0x0fu;
        const std::uint32_t n0 = p & 0x0fu;
        d[i] = (n3 << 28) | (n3 << 24) | (n2 << 20) | (n2 << 16) |
               (n1 << 12) | (n1 << 8) | (n0 << 4) | n0;
    }
}

void __cdecl render_row_24_to_8888_00570a00(void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint32_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    for (std::int32_t i = 0; i < count; ++i) {
        d[i] = 0xff000000u |
               (static_cast<std::uint32_t>(s[i * 3 + 2]) << 16) |
               (static_cast<std::uint32_t>(s[i * 3 + 1]) << 8) |
               static_cast<std::uint32_t>(s[i * 3 + 0]);
    }
}

void __cdecl render_row_32_copy_00570a80(void* dst, const void* src, std::int32_t count) {
    heap_copy_dispatch_005323e0(dst, src, static_cast<std::uint32_t>(count) * 4u);
}

} // namespace porsche
