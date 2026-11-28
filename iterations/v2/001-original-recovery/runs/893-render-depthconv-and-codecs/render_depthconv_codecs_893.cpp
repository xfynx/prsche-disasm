// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run893: 00534d40..0053533f, 00571330..00571482, 00593640..00594977 (14 functions).
#include "render_depthconv_codecs_893.hpp"

#include "porsche/heap.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/shared_runtime_globals.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

extern std::uint32_t render_alloc_flags_005deb60;
extern std::uint32_t* render_depthconv_palette_ptr_005de2f8;
extern std::uint32_t render_depthconv_palette_scratch_006bda20[256];
extern std::uint32_t render_pixel_palette_006b4b20[256];
extern const char render_clut16_file_005bb3e4[23];
extern void(__cdecl* diagnostic_handler_005debf0)(const char*);

std::int32_t __cdecl render_shape_type_to_depth_index_005345e0(std::uint32_t shape_type);
std::uint32_t* __cdecl render_getclutptr_from_resource_005346d0(
    const void* descriptor, std::uint32_t* palette);
std::int32_t __cdecl render_depth_format_index_00535340(std::uint32_t format_index);
std::uint32_t __cdecl render_depth_level_00535360(std::int32_t depth_index);
std::uint32_t __cdecl render_descriptor_bits_00537f90(const void* descriptor_format);
void* __cdecl render_resource_node_palette_00537fb0(const void* descriptor);
std::uint32_t __cdecl render_descriptor_read_be_0056e290(
    const void* source, std::uint32_t count);
std::uint32_t __cdecl render_buffer_read_word_0056e2a8(
    const void* src, std::int32_t bytes);
std::int32_t __cdecl splash_shape_row_stride_005712f0(const void* shape);
std::uint32_t __cdecl render_chunk_size_wrapper_00571520(const void* header);

void __cdecl render_row_4_copy_005700d0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_4_005700f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_4_to_8_00570150(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_copy_00570190(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_8_005701b0(void* dst, const void* src, std::int32_t count);
void __cdecl render_palette_swap_rb555_00570260(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_565_to_1555_005702a0(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_row_565_to_1555_005702f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_palette_8888_to_1555_alpha_00570330(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_888_to_1555_00570370(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_row_4_to_16_lut_005703a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_16_lut_005703f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_palette_555_to_565_00570420(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_row_16_copy_00570470(void* dst, const void* src, std::int32_t count);
void __cdecl render_palette_8888_to_565_alpha_005704c0(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_888_to_565_00570510(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_palette_8888_to_4444_00570540(
    std::uint16_t* dst, const std::uint32_t* src, std::int32_t count);
void __cdecl render_row_565_to_4444_key_005705a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_24_lut_00570650(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_24_00570690(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_24_copy_00570700(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8888_to_24_00570720(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_32_lut_00570750(void* dst, const void* src, std::int32_t count);
void __cdecl render_palette_5551_to_8888_key_00570780(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_palette_565_to_8888_key_00570820(
    std::uint32_t* dst, const std::uint16_t* src, std::int32_t count);
void __cdecl render_row_4444_to_8888_005708a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_24_to_8888_00570a00(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_32_copy_00570a80(void* dst, const void* src, std::int32_t count);

namespace {

using RowConvFn = void(__cdecl*)(void* dst, const void* src, std::int32_t count);
using DiagFn = void(__cdecl*)(const char*, ...);

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

constexpr std::int32_t kTextureBits_005de53c[35] = {
    0, 4, 8, 16, 16, 24, 32, 16,
    8, 16, 16, 15, 4, 8, -1, 0,
    1, 2, 3, 4, 5, 6, -1, -1,
    -1, 2, -1, -1, 1, 2, 3, 4,
    5, 6, 7,
};

constexpr std::uint32_t kClutShapeType_005de5c8[8] = {
    0u, 11u, 4u, 5u, 6u, 7u, 3u, 0u,
};

// Private BPE decompression state matching original .bss 006af150..006af163.
std::uint8_t* codec_bpe_right_006af150 = nullptr;
std::uint8_t* codec_bpe_dst_006af154 = nullptr;
const std::uint8_t* codec_bpe_src_006af158 = nullptr;
std::uint8_t* codec_bpe_flag_006af15c = nullptr;
std::uint8_t* codec_bpe_left_006af160 = nullptr;

// Helper matching 00593800's big-endian 16-bit-chunked MSB bitstream reader.
struct HuffBitReader {
    const std::uint8_t* src;
    std::uint32_t bitbuf;
    std::uint32_t top;
    std::int32_t bits;

    void refill() {
        const std::uint32_t w = (static_cast<std::uint32_t>(src[0]) << 8) | src[1];
        src += 2;
        bitbuf = (bitbuf << 16) | w;
        top = bitbuf << (static_cast<std::uint32_t>(-bits) & 31u);
        bits += 16;
    }

    std::uint32_t read_bits(std::int32_t count) {
        if (count <= 16) {
            const std::uint32_t v = top >> ((32 - count) & 31);
            top <<= (count & 31);
            bits -= count;
            if (bits < 0) {
                refill();
            }
            return v;
        }
        const std::uint32_t hi = top >> ((48 - count) & 31);
        top <<= ((count - 16) & 31);
        bits += (16 - count);
        if (bits < 0) {
            refill();
        }
        const std::uint32_t lo = top >> 16;
        top <<= 16;
        bits -= 16;
        if (bits < 0) {
            refill();
        }
        return (hi << 16) | lo;
    }

    std::int32_t read_var_count() {
        if (static_cast<std::int32_t>(top) < 0) {
            return static_cast<std::int32_t>(read_bits(3)) - 4;
        }
        std::int32_t count = 2;
        if ((top & 0xffff0000u) == 0u) {
            std::uint32_t msb;
            do {
                ++count;
                msb = top >> 31;
                top <<= 1;
                --bits;
                if (bits < 0) {
                    refill();
                }
            } while (msb == 0u);
        } else {
            std::uint32_t prev;
            do {
                prev = top;
                top <<= 1;
                ++count;
            } while (static_cast<std::int32_t>(top) >= 0);
            top = prev << 2;
            bits += (1 - count);
            if (bits < 0) {
                refill();
            }
        }
        const std::uint32_t v = read_bits(count);
        return static_cast<std::int32_t>((v - 4u) + (1u << (count & 31)));
    }
};

std::uint16_t rd_u16(const void* base, std::size_t offset) {
    std::uint16_t v = 0u;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + offset, sizeof(v));
    return v;
}

std::uint32_t rd_u32(const void* base, std::size_t offset) {
    std::uint32_t v = 0u;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + offset, sizeof(v));
    return v;
}

void wr_u16(void* base, std::size_t offset, std::uint16_t v) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &v, sizeof(v));
}

void wr_u32(void* base, std::size_t offset, std::uint32_t v) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &v, sizeof(v));
}

} // namespace

void* __cdecl render_shape_convert_type_00534d40(
    const void* shape, std::uint32_t target_type,
    std::int32_t use_dither, std::int32_t direct_mode) {
    const void* cur_shape = shape;
    void* prev_alloc = nullptr;
    std::uint32_t next_type = 0u;
    std::int32_t remaining = 10;

    if ((rd_u32(cur_shape, 0) & 0x80u) != 0u) {
        cur_shape = render_shape_unpack_00571330(cur_shape);
        prev_alloc = const_cast<void*>(cur_shape);
    }

    void* const clut_resource = render_resource_node_palette_00537fb0(cur_shape);
    std::uint32_t* out_words = nullptr;

    do {
        const std::uint32_t cur_type = rd_u32(cur_shape, 0) & 0xffu;
        const std::int32_t src_idx = render_shape_type_to_depth_index_005345e0(cur_type);
        const std::int32_t dst_idx = render_shape_type_to_depth_index_005345e0(target_type);
        const std::size_t table_idx = static_cast<std::size_t>(src_idx * 8 + dst_idx);
        const auto row_fn = reinterpret_cast<RowConvFn>(
            (direct_mode == 0) ? kAlternateCallbacks_005de3fc[table_idx]
                               : kDirectCallbacks_005de2fc[table_idx]);

        next_type = kIntermediateTypes_005de4fc[table_idx];
        if (next_type == 0u) {
            shared_runtime_word_005deb74 = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&render_clut16_file_005bb3e4[0]));
            shared_runtime_word_005deb78 = 0x201u;
            reinterpret_cast<DiagFn>(diagnostic_handler_005debf0)(
                "SHAPE_converttype - UNABLE TO CONVERT TO TARGET SHAPE TYPE.\n"
                "Initial shape type ($%02x). Target shape type ($%02x)\n",
                cur_type, target_type);
        }

        const std::int32_t src_bits =
            static_cast<std::int32_t>(render_descriptor_bits_00537f90(cur_shape));
        const std::int32_t dst_bits =
            static_cast<std::int32_t>(render_descriptor_bits_00537f90(&next_type));
        const std::uint32_t word1 = rd_u32(cur_shape, 4);
        const std::int32_t width = static_cast<std::int16_t>(word1 & 0xffffu);
        const std::int32_t height = static_cast<std::int16_t>(rd_u16(cur_shape, 6));
        const std::int32_t src_stride = splash_shape_row_stride_005712f0(cur_shape);
        const std::int32_t dst_stride =
            static_cast<std::int32_t>(
                ((static_cast<std::uint32_t>(dst_bits) + 1u) & 0xfffffffeu) *
                    static_cast<std::uint32_t>(width) +
                7u) >>
            3;

        if (src_bits < 9 && dst_bits > 8) {
            const std::int32_t palette_count = 1 << (src_bits & 31);
            if (use_dither == 0) {
                render_depthconv_palette_ptr_005de2f8 =
                    render_getclutptr_from_resource_005346d0(
                        clut_resource, render_depthconv_palette_scratch_006bda20);
            } else {
                for (std::int32_t i = 0; i < palette_count; ++i) {
                    render_depthconv_palette_scratch_006bda20[i] =
                        render_pixel_palette_006b4b20[i & 0xff];
                }
                render_depthconv_palette_ptr_005de2f8 =
                    render_depthconv_palette_scratch_006bda20;
            }

            auto* const scratch16 =
                reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20);
            if (target_type == 0x6du) {
                render_palette_8888_to_4444_00570540(
                    scratch16, render_depthconv_palette_ptr_005de2f8, palette_count);
            } else if (dst_bits == 15) {
                if (direct_mode != 0) {
                    render_palette_8888_to_1555_alpha_00570330(
                        scratch16, render_depthconv_palette_ptr_005de2f8, palette_count);
                } else {
                    render_palette_888_to_1555_00570370(
                        scratch16, render_depthconv_palette_ptr_005de2f8, palette_count);
                }
            } else if (dst_bits == 16) {
                if (direct_mode != 0) {
                    render_palette_8888_to_565_alpha_005704c0(
                        scratch16, render_depthconv_palette_ptr_005de2f8, palette_count);
                } else {
                    render_palette_888_to_565_00570510(
                        scratch16, render_depthconv_palette_ptr_005de2f8, palette_count);
                }
            }
            use_dither = 0;
        }

        char tag[32]{};
        render_loader_format_005a0fbf(tag, "%dto%d", src_bits, dst_bits);
        const std::int32_t pixel_bytes = dst_stride * height;
        out_words = static_cast<std::uint32_t*>(
            allocate_00531ca0(tag, pixel_bytes + 0x14, render_alloc_flags_005deb60));
        void* const sentinel_ptr =
            reinterpret_cast<std::uint8_t*>(out_words) + pixel_bytes + 0x10;
        heap_word_0056e2c0(sentinel_ptr, 0x43534850u, 4);

        const std::uint32_t word2 = rd_u32(cur_shape, 8);
        wr_u16(out_words, 4, static_cast<std::uint16_t>(word1 & 0xffffu));
        wr_u16(out_words, 8, static_cast<std::uint16_t>(word2 & 0xffffu));
        wr_u16(out_words, 10, rd_u16(cur_shape, 10));
        out_words[0] = next_type & 0xffu;

        const std::uint32_t word3 = rd_u32(cur_shape, 12);
        const std::uint32_t packed_lo =
            (static_cast<std::uint32_t>(static_cast<std::int32_t>(word3 << 20) >> 20) ^
             out_words[3]) &
                0xfffu ^
            out_words[3];
        out_words[3] = packed_lo;
        wr_u16(out_words, 6, static_cast<std::uint16_t>(height));
        out_words[3] =
            (static_cast<std::uint32_t>(static_cast<std::int32_t>(word3 << 4) >> 4) ^
             packed_lo) &
                0xfff0000u ^
            packed_lo;

        const auto* src_rows = static_cast<const std::uint8_t*>(cur_shape) + 0x10;
        auto* dst_rows = reinterpret_cast<std::uint8_t*>(out_words) + 0x10;
        for (std::int32_t row = 0; row < height; ++row) {
            row_fn(dst_rows, src_rows, width);
            src_rows += src_stride;
            dst_rows += dst_stride;
        }

        if (render_descriptor_read_be_0056e290(sentinel_ptr, 4u) != 0x43534850u) {
            shared_runtime_word_005deb74 = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&render_clut16_file_005bb3e4[0]));
            shared_runtime_word_005deb78 = 0x255u;
            reinterpret_cast<DiagFn>(diagnostic_handler_005debf0)(
                "convshp - SENTINAL CORRUPTED. %dx%dx%d->%dx%dx%d\n",
                width, height, src_bits, width, height, dst_bits);
        }

        if (prev_alloc != nullptr) {
            free_00531f90(prev_alloc);
        }

        if (static_cast<std::uint8_t>(out_words[0]) == static_cast<std::uint8_t>(target_type)) {
            break;
        }
        --remaining;
        cur_shape = out_words;
        prev_alloc = out_words;
    } while (remaining != 0);

    return out_words;
}

std::int32_t __cdecl render_texture_depth_convert_005350e0(
    std::uint32_t src_type, std::uint32_t src_fmt,
    std::uint32_t dst_type, std::uint32_t dst_fmt,
    std::uint32_t src_data, std::uint32_t dst_data,
    std::uint32_t src_clut, std::uint32_t dst_clut,
    std::int32_t count) {
    std::int32_t remaining = 10;
    std::uint32_t cur_type = src_type;
    std::uint32_t cur_src = src_data;
    bool free_src = false;

    if (src_type == 0xcu) {
        if (dst_type == 0xcu) {
            heap_copy_dispatch_005323e0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(dst_data)),
                reinterpret_cast<const void*>(static_cast<std::uintptr_t>(src_data)),
                static_cast<std::uint32_t>(count / 2));
            return 1;
        }
        const std::uint32_t bytes = render_chunk_size_wrapper_00571520(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(src_data)));
        void* const unpacked = allocate_00531ca0("TEXto565", static_cast<std::int32_t>(bytes), 0u);
        codec_decompress_wrapper_00571470(
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(src_data)), unpacked);
        cur_type = 4u;
        cur_src = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(unpacked));
        free_src = true;
    }

    std::uint32_t next_type = 0u;
    std::int32_t src_bits = 0;
    std::int32_t next_bits = 0;

    do {
        const std::int32_t si = render_depth_format_index_00535340(cur_type);
        const std::int32_t di = render_depth_format_index_00535340(dst_type);
        const std::size_t table_idx = static_cast<std::size_t>(si * 8 + di);
        const auto row_fn = reinterpret_cast<RowConvFn>(kDirectCallbacks_005de2fc[table_idx]);
        next_type = render_depth_level_00535360(
            render_shape_type_to_depth_index_005345e0(kIntermediateTypes_005de4fc[table_idx]));
        if (next_type == 0u) {
            shared_runtime_word_005deb74 = static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&render_clut16_file_005bb3e4[0]));
            shared_runtime_word_005deb78 = 0x350u;
            reinterpret_cast<DiagFn>(diagnostic_handler_005debf0)(
                "TEXTURE_converttype - UNABLE TO CONVERT TO TARGET TEXTURE TYPE.\n"
                "Initial texture type ($%02x). Target texture type ($%02x)\n",
                src_type, dst_type);
        }

        src_bits = kTextureBits_005de53c[cur_type];
        next_bits = kTextureBits_005de53c[next_type];
        std::uint32_t cur_dst = dst_data;
        bool free_next = false;

        if (next_type != dst_type) {
            char tag[32]{};
            render_loader_format_005a0fbf(tag, "%dto%d", src_bits, next_bits);
            const std::int32_t aligned_bits =
                static_cast<std::int32_t>(static_cast<std::uint32_t>(next_bits) + 1u) &
                static_cast<std::int32_t>(0xfffffffeu);
            const std::int32_t byte_len = (aligned_bits * count) / 8;
            void* const tmp = allocate_00531ca0(tag, byte_len, render_alloc_flags_005deb60);
            cur_dst = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(tmp));
            free_next = true;
        }

        if (src_bits < 9 && next_bits > 8) {
            render_texture_depth_convert_005350e0(
                kClutShapeType_005de5c8[src_fmt], 0u,
                next_type, 0u,
                src_clut,
                static_cast<std::uint32_t>(
                    reinterpret_cast<std::uintptr_t>(render_depthconv_palette_scratch_006bda20)),
                0u, 0u,
                1 << (src_bits & 31));
        }

        row_fn(
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(cur_dst)),
            reinterpret_cast<const void*>(static_cast<std::uintptr_t>(cur_src)),
            count);

        if (free_src) {
            free_00531f90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(cur_src)));
        }

        if (next_type == dst_type) {
            break;
        }
        cur_src = cur_dst;
        free_src = free_next;
        cur_type = next_type;
        --remaining;
    } while (remaining != 0);

    if (next_type == dst_type) {
        if (next_bits < 9 && src_fmt != 0u && dst_fmt != 0u && src_clut != 0u && dst_clut != 0u) {
            render_texture_depth_convert_005350e0(
                kClutShapeType_005de5c8[src_fmt], 0u,
                kClutShapeType_005de5c8[dst_fmt], 0u,
                src_clut, dst_clut,
                0u, 0u,
                1 << (src_bits & 31));
        }
        return 1;
    }
    return 0;
}

void* __cdecl render_shape_unpack_00571330(const void* shape) {
    const auto* src_bytes = static_cast<const std::uint8_t*>(shape);
    if ((src_bytes[0] & 0x80u) == 0u) {
        return const_cast<void*>(shape);
    }

    const std::uint32_t unpacked_size = render_chunk_size_wrapper_00571520(src_bytes + 0x10);
    auto* const dst_bytes = static_cast<std::uint8_t*>(
        allocate_00531ca0("unshp", static_cast<std::int32_t>(unpacked_size) + 0x10, 0u));
    heap_copy_dispatch_005323e0(dst_bytes, src_bytes, 0x10u);
    codec_decompress_wrapper_00571470(src_bytes + 0x10, dst_bytes + 0x10);

    const std::uint32_t dst_word = rd_u32(dst_bytes, 0) & 0xffffff7fu;
    const std::uint32_t src_word = rd_u32(src_bytes, 0);
    wr_u32(dst_bytes, 0, dst_word);
    if ((src_word & 0xffffff00u) != 0u) {
        const std::uint32_t delta = static_cast<std::uint32_t>(src_bytes - dst_bytes);
        const std::uint32_t rel =
            ((delta << 8) + (src_word & 0xffffff00u)) ^ (dst_word & 0x7fu);
        wr_u32(dst_bytes, 0, rel);
    }
    return dst_bytes;
}

std::uint32_t __cdecl codec_decompress_005713a0(const void* src, void* dst) {
    const auto* bytes = static_cast<const std::uint8_t*>(src);
    if (bytes[1] != 0xfbu && bytes[1] != 0x32u) {
        return 0u;
    }
    switch (bytes[0] & 0xfeu) {
    case 0x10u:
        return static_cast<std::uint32_t>(codec_refpack_decode_00594760(src, dst, 1));
    case 0x18u:
        return static_cast<std::uint32_t>(codec_dxt1_decode_00594400(src, dst, 1));
    case 0x30u:
    case 0x32u:
    case 0x34u:
        return codec_huff_decode_00593800(src, dst, 1);
    case 0x46u:
        return static_cast<std::uint32_t>(codec_bpe_decode_00593640(src, dst));
    default:
        return 0u;
    }
}

std::uint32_t __cdecl codec_decompress_wrapper_00571470(const void* src, void* dst) {
    return codec_decompress_005713a0(src, dst);
}

std::int32_t __cdecl codec_bpe_decode_00593640(const void* src, void* dst) {
    std::uint8_t flag_buf[256]{};
    std::uint8_t left_buf[256]{};
    std::uint8_t right_buf[256]{};

    codec_bpe_flag_006af15c = flag_buf;
    codec_bpe_left_006af160 = left_buf;
    codec_bpe_right_006af150 = right_buf;
    codec_bpe_src_006af158 = static_cast<const std::uint8_t*>(src);
    codec_bpe_dst_006af154 = static_cast<std::uint8_t*>(dst);

    if (src == nullptr) {
        return 0;
    }

    const auto* in = codec_bpe_src_006af158;
    const auto* p = in + 2;
    if ((static_cast<std::uint32_t>(in[0]) * 0x100u + in[1]) == 0x47fbu) {
        p = in + 5;
    }
    const std::int32_t out_len =
        static_cast<std::int32_t>((static_cast<std::uint32_t>(p[0]) << 16) |
                                  (static_cast<std::uint32_t>(p[1]) << 8) |
                                  static_cast<std::uint32_t>(p[2]));
    flag_buf[p[3]] = 1u;
    codec_bpe_src_006af158 = p + 5;
    for (std::uint32_t pairs = p[4]; pairs != 0u; --pairs) {
        const std::uint8_t code = codec_bpe_src_006af158[0];
        left_buf[code] = codec_bpe_src_006af158[1];
        flag_buf[code] = 0xffu;
        right_buf[code] = codec_bpe_src_006af158[2];
        codec_bpe_src_006af158 += 3;
    }

    for (;;) {
        const std::uint8_t sym = *codec_bpe_src_006af158;
        const auto f = static_cast<std::int8_t>(codec_bpe_flag_006af15c[sym]);
        if (f == 0) {
            *codec_bpe_dst_006af154++ = sym;
            ++codec_bpe_src_006af158;
        } else if (f < 0) {
            ++codec_bpe_src_006af158;
            codec_bpe_emit_00593790(codec_bpe_left_006af160[sym]);
            codec_bpe_emit_00593790(codec_bpe_right_006af150[sym]);
        } else {
            const std::uint8_t lit = codec_bpe_src_006af158[1];
            codec_bpe_src_006af158 += 2;
            if (lit == 0u) {
                break;
            }
            *codec_bpe_dst_006af154++ = lit;
        }
    }
    return out_len;
}

void __cdecl codec_bpe_emit_00593790(std::uint8_t sym) {
    if (codec_bpe_flag_006af15c[sym] != 0u) {
        do {
            codec_bpe_emit_00593790(codec_bpe_left_006af160[sym]);
            sym = codec_bpe_right_006af150[sym];
        } while (codec_bpe_flag_006af15c[sym] != 0u);
    }
    *codec_bpe_dst_006af154++ = sym;
}

std::uint32_t __cdecl codec_huff_decode_00593800(
    const void* src, void* dst, std::int32_t decode) {
    if (src == nullptr) {
        return 0u;
    }

    const auto* in = static_cast<const std::uint8_t*>(src);
    auto* out = static_cast<std::uint8_t*>(dst);

    std::uint16_t hdr = static_cast<std::uint16_t>((in[0] << 8) | in[1]);
    HuffBitReader br{};
    br.src = in + 4;
    br.bitbuf = (static_cast<std::uint32_t>(in[0]) << 24) |
                (static_cast<std::uint32_t>(in[1]) << 16) |
                (static_cast<std::uint32_t>(in[2]) << 8) |
                static_cast<std::uint32_t>(in[3]);
    br.bits = 0;
    br.top = br.bitbuf << 16;

    if ((in[0] & 1u) != 0u) {
        br.bits = 8;
        br.bitbuf = (static_cast<std::uint32_t>(in[4]) << 24) |
                    (static_cast<std::uint32_t>(in[5]) << 16) |
                    (static_cast<std::uint32_t>(in[6]) << 8) |
                    static_cast<std::uint32_t>(in[7]);
        br.src = in + 8;
        br.top = br.bitbuf << 8;
    }

    hdr = static_cast<std::uint16_t>(hdr & 0xfeffu);
    const std::uint32_t len_hi = br.read_bits(8);
    const std::uint32_t len_lo = br.read_bits(16);
    const std::uint32_t ulen = (len_hi << 16) | len_lo;

    std::uint32_t cmpbits[18]{};
    std::int32_t offset[18]{};
    std::int32_t numbits[17]{};
    std::uint8_t quicklen[256]{};
    std::uint8_t quicksym[256]{};
    std::uint8_t codemap[256]{};

    std::uint32_t clue = 0xffffffffu;
    std::int32_t clue_bits = 0;

    if (decode != 0) {
        clue = br.read_bits(8);

        std::int32_t maxbits = 1;
        std::int32_t total = 0;
        std::int32_t tblptr = 0;
        std::uint32_t base_code = 0u;
        for (;;) {
            const std::int32_t base2 = tblptr * 2;
            offset[maxbits] = base2 - total;
            const std::int32_t n = br.read_var_count();
            total += n;
            numbits[maxbits] = n;
            tblptr = base2 + n;
            std::uint32_t cmp = 0u;
            if (n != 0) {
                cmp = (static_cast<std::uint32_t>(tblptr) << ((16 - maxbits) & 31)) & 0xffffu;
            }
            cmpbits[maxbits] = cmp;
            base_code = cmp;
            ++maxbits;
            if (n != 0 && base_code == 0u) {
                break;
            }
        }
        cmpbits[maxbits - 1] = 0xffffffffu;
        --maxbits;

        std::uint8_t sym_present[256]{};
        std::uint8_t cur_sym = 0xffu;
        for (std::int32_t idx = 0; idx < total; ++idx) {
            std::int32_t skip = br.read_var_count() + 1;
            do {
                cur_sym = static_cast<std::uint8_t>(cur_sym + 1u);
                if (sym_present[cur_sym] == 0u) {
                    --skip;
                }
            } while (skip != 0);
            sym_present[cur_sym] = 1u;
            codemap[idx] = cur_sym;
        }

        std::memset(quicklen, 0x40, sizeof(quicklen));

        const std::uint8_t* map_ptr = codemap;
        std::uint8_t* qsym_ptr = quicksym;
        std::uint8_t* qlen_ptr = quicklen;
        std::int32_t shift = 7;
        for (std::int32_t bitlen = 1; bitlen <= maxbits; ++bitlen, --shift) {
            if (shift < 0) {
                break;
            }
            const std::int32_t fill_count = 1 << (shift & 31);
            for (std::int32_t k = numbits[bitlen]; k != 0; --k) {
                const std::uint8_t sym = *map_ptr++;
                std::uint8_t qv;
                if (sym == clue) {
                    clue_bits = bitlen;
                    qv = 0x60u;
                } else {
                    qv = static_cast<std::uint8_t>(bitlen);
                }
                if (fill_count > 0) {
                    std::memset(qlen_ptr, qv, static_cast<std::size_t>(fill_count));
                    std::memset(qsym_ptr, sym, static_cast<std::size_t>(fill_count));
                    qlen_ptr += fill_count;
                    qsym_ptr += fill_count;
                }
            }
        }
    }

    for (;;) {
        for (;;) {
            const std::uint32_t peek = br.top >> 24;
            const std::int32_t qlen = quicklen[peek];
            br.bits -= qlen;
            if (br.bits >= 0) {
                br.top <<= (qlen & 31);
                *out++ = quicksym[peek];
                continue;
            }
            br.bits += 16;
            if (br.bits >= 0) {
                *out++ = quicksym[peek];
                const std::uint32_t w =
                    (static_cast<std::uint32_t>(br.src[0]) << 8) | br.src[1];
                br.src += 2;
                br.bitbuf = (br.bitbuf << 16) | w;
                br.top = br.bitbuf << (static_cast<std::uint32_t>(16 - br.bits) & 31u);
                continue;
            }

            // Slow path (>8 bits) or clue escape (qlen == 0x60).
            br.bits += qlen - 16;
            std::int32_t blen;
            if (qlen == 0x60) {
                blen = clue_bits;
            } else {
                const std::uint32_t code16 = br.top >> 16;
                blen = 8;
                do {
                    ++blen;
                } while (cmpbits[blen] <= code16);
            }

            const std::uint32_t code_val = br.top >> ((32 - blen) & 31);
            br.top <<= (blen & 31);
            br.bits -= blen;
            const std::uint8_t sym = codemap[static_cast<std::int32_t>(code_val) - offset[blen]];
            if (sym != clue) {
                if (br.bits < 0) {
                    br.refill();
                }
                *out++ = sym;
                break;
            }

            if (br.bits < 0) {
                br.refill();
            }

            const std::int32_t run = br.read_var_count();
            if (run == 0) {
                const std::int32_t stop_bit = static_cast<std::int32_t>(br.top) < 0 ? 1 : 0;
                br.top <<= 1;
                --br.bits;
                if (br.bits < 0) {
                    br.refill();
                }
                if (stop_bit != 0) {
                    auto* p = static_cast<std::uint8_t*>(dst);
                    if (hdr == 0x32fbu) {
                        std::uint8_t acc = 0u;
                        for (std::uint32_t i = 0; i < ulen; ++i) {
                            acc = static_cast<std::uint8_t>(acc + p[i]);
                            p[i] = acc;
                        }
                    } else if (hdr == 0x34fbu) {
                        std::uint8_t d1 = 0u;
                        std::uint8_t d2 = 0u;
                        for (std::uint32_t i = 0; i < ulen; ++i) {
                            d1 = static_cast<std::uint8_t>(d1 + p[i]);
                            d2 = static_cast<std::uint8_t>(d2 + d1);
                            p[i] = d2;
                        }
                    }
                    return ulen;
                }
                *out++ = static_cast<std::uint8_t>(br.read_bits(8));
                break;
            }

            const std::uint8_t prev = out[-1];
            for (std::int32_t i = 0; i < run; ++i) {
                *out++ = prev;
            }
            break;
        }
    }
}

std::int32_t __cdecl codec_dxt1_decode_00594400(
    const void* src, void* dst, std::int32_t decode) {
    const auto* in = static_cast<const std::uint8_t*>(src);
    auto* out = static_cast<std::uint8_t*>(dst);

    const std::int32_t total_bytes =
        static_cast<std::int32_t>(render_descriptor_read_be_0056e290(in + 2, 3u));
    const std::int32_t width =
        static_cast<std::int32_t>(render_descriptor_read_be_0056e290(in + 6, 2u));

    if (decode != 0) {
        const std::uint8_t* blocks = in + 8;
        for (std::int32_t decoded = 0; decoded < total_bytes; decoded += width * 8) {
            if (width > 0) {
                std::uint32_t blocks_x = static_cast<std::uint32_t>(width + 3) >> 2;
                do {
                    codec_dxt1_block_00594490(
                        reinterpret_cast<std::uint16_t*>(out), width * 2, blocks);
                    out += 8;
                    blocks += 8;
                    --blocks_x;
                } while (blocks_x != 0u);
            }
            out += width * 6;
        }
    }
    return total_bytes;
}

void __cdecl codec_dxt1_block_00594490(
    std::uint16_t* dst, std::int32_t pitch, const void* block) {
    const auto* b = static_cast<const std::uint8_t*>(block);
    std::uint32_t c[4]{};
    c[0] = render_buffer_read_word_0056e2a8(b, 2);
    c[1] = render_buffer_read_word_0056e2a8(b + 2, 2);

    if (c[0] > c[1]) {
        c[2] = (((c[1] & 0xf800u) * 0x5556u + (c[0] & 0xf800u) * 0xaaaau) & 0xf800ffffu |
                ((c[1] & 0x07e0u) * 0x5556u + (c[0] & 0x07e0u) * 0xaaaau) & 0x07e00000u |
                ((c[1] & 0x001fu) * 0x5556u + (c[0] & 0x001fu) * 0xaaaau) & 0x001f0000u) >>
               16;
        c[3] = (((c[0] & 0xf800u) * 0x5556u + (c[1] & 0xf800u) * 0xaaaau) & 0xf800ffffu |
                ((c[0] & 0x07e0u) * 0x5556u + (c[1] & 0x07e0u) * 0xaaaau) & 0x07e00000u |
                ((c[0] & 0x001fu) * 0x5556u + (c[1] & 0x001fu) * 0xaaaau) & 0x001f0000u) >>
               16;
    } else {
        c[2] = (((c[1] & 0xf800u) + (c[0] & 0xf800u)) & 0x1f001u |
                ((c[1] & 0x07e0u) + (c[0] & 0x07e0u)) & 0x0fc0u |
                ((c[1] & 0x001fu) + (c[0] & 0x001fu)) & 0x003eu) >>
               1;
        c[3] = 0u;
    }

    auto* row = reinterpret_cast<std::uint8_t*>(dst);
    for (std::size_t y = 0; y < 4; ++y) {
        const std::uint8_t idx = b[4 + y];
        auto* p = reinterpret_cast<std::uint16_t*>(row);
        p[0] = static_cast<std::uint16_t>(c[idx & 3u]);
        p[1] = static_cast<std::uint16_t>(c[(idx >> 2) & 3u]);
        p[2] = static_cast<std::uint16_t>(c[(idx >> 4) & 3u]);
        p[3] = static_cast<std::uint16_t>(c[idx >> 6]);
        row += pitch;
    }
}

std::int32_t __cdecl codec_refpack_decode_00594760(
    const void* src, void* dst, std::int32_t decode) {
    if (src == nullptr) {
        return 0;
    }

    const auto* in = static_cast<const std::uint8_t*>(src);
    const std::uint8_t* p = in + 2;
    if ((in[0] & 1u) != 0u) {
        p = in + 5;
    }
    const std::int32_t ulen =
        static_cast<std::int32_t>((static_cast<std::uint32_t>(p[0]) << 16) |
                                  (static_cast<std::uint32_t>(p[1]) << 8) |
                                  static_cast<std::uint32_t>(p[2]));
    p += 3;

    if (decode == 0) {
        return ulen;
    }

    auto* out = static_cast<std::uint8_t*>(dst);
    for (;;) {
        const std::uint32_t op = rd_u32(p, 0);
        if ((op & 0x80u) == 0u) {
            const std::uint32_t lit = op & 3u;
            wr_u32(out, 0, rd_u32(p, 2));
            p += lit + 2;
            const std::uint32_t dist = ((op & 0x60u) << 3) + ((op >> 8) & 0xffu) + 1u;
            const std::uint32_t match = ((op >> 2) & 7u) + 3u;
            out = static_cast<std::uint8_t*>(
                codec_refpack_match_copy_005948f0(out + lit, dist, match));
        } else if ((op & 0x40u) == 0u) {
            const std::uint32_t lit = (op >> 14) & 3u;
            wr_u32(out, 0, rd_u32(p, 3));
            p += lit + 3;
            const std::uint32_t dist = (op & 0x3f00u) + ((op >> 16) & 0xffu) + 1u;
            const std::uint32_t match = (op & 0x3fu) + 4u;
            out = static_cast<std::uint8_t*>(
                codec_refpack_match_copy_005948f0(out + lit, dist, match));
        } else if ((op & 0x20u) == 0u) {
            const std::uint32_t lit = op & 3u;
            wr_u32(out, 0, rd_u32(p, 4));
            p += lit + 4;
            const std::uint32_t dist =
                ((op & 0x10u) << 12) + (op & 0xff00u) + ((op >> 16) & 0xffu) + 1u;
            const std::uint32_t match = ((op & 0x0cu) << 6) + (op >> 24) + 5u;
            out = static_cast<std::uint8_t*>(
                codec_refpack_match_copy_005948f0(out + lit, dist, match));
        } else {
            const std::uint32_t b0 = op & 0xffu;
            const std::uint8_t* lit_src = p + 1;
            if (b0 > 0xfbu) {
                for (std::uint32_t rem = b0 & 3u; rem != 0u; --rem) {
                    *out++ = *lit_src++;
                }
                return ulen;
            }
            const std::int32_t lit_bytes = static_cast<std::int32_t>((b0 & 0x1fu) * 4u + 4u);
            codec_refpack_copy_dwords_005948c0(out, lit_src, lit_bytes);
            p = lit_src + lit_bytes;
            out += lit_bytes;
        }
    }
}

void* __cdecl codec_refpack_copy_dwords_005948c0(
    void* dst, const void* src, std::int32_t bytes) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    std::uint8_t* const end = d + bytes;
    std::int32_t rem = bytes;
    do {
        rem -= 4;
        std::memcpy(d, s, 4);
        d += 4;
        s += 4;
    } while (rem > 0);
    return end;
}

void* __cdecl codec_refpack_match_copy_005948f0(
    void* dst, std::uint32_t dist, std::uint32_t len) {
    auto* d = static_cast<std::uint8_t*>(dst);
    if (dist > 3u) {
        return codec_refpack_copy_dwords_005948c0(d, d - dist, static_cast<std::int32_t>(len));
    }
    if (dist == 1u) {
        const std::uint8_t fill = d[-1];
        const std::uint32_t fill4 = static_cast<std::uint32_t>(fill) * 0x01010101u;
        auto* cur = d;
        for (std::uint32_t q = len >> 2; q != 0u; --q) {
            wr_u32(cur, 0, fill4);
            cur += 4;
        }
        for (std::uint32_t r = len & 3u; r != 0u; --r) {
            *cur++ = fill;
        }
        return d + len;
    }
    codec_refpack_copy_bytes_00594960(d, d - dist, static_cast<std::int32_t>(len));
    return d + len;
}

void __cdecl codec_refpack_copy_bytes_00594960(
    void* dst, const void* src, std::int32_t count) {
    auto* d = static_cast<std::uint8_t*>(dst);
    const auto* s = static_cast<const std::uint8_t*>(src);
    do {
        *d++ = *s++;
        --count;
    } while (count != 0);
}

} // namespace porsche
