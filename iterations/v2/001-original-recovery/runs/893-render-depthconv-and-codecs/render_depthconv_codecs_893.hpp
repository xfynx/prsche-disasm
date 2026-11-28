// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original 00534d40..00535098 (857B, __cdecl, ret 0).
void* __cdecl render_shape_convert_type_00534d40(
    const void* shape, std::uint32_t target_type,
    std::int32_t use_dither, std::int32_t direct_mode);

// Original 005350e0..0053533f (608B, __cdecl, ret 0).
std::int32_t __cdecl render_texture_depth_convert_005350e0(
    std::uint32_t src_type, std::uint32_t src_fmt,
    std::uint32_t dst_type, std::uint32_t dst_fmt,
    std::uint32_t src_data, std::uint32_t dst_data,
    std::uint32_t src_clut, std::uint32_t dst_clut,
    std::int32_t count);

// Original 00571330..0057139a (107B, __cdecl, ret 0).
void* __cdecl render_shape_unpack_00571330(const void* shape);

// Original 005713a0..00571418 (121B, __cdecl, ret 0).
std::uint32_t __cdecl codec_decompress_005713a0(const void* src, void* dst);

// Original 00571470..00571482 (19B, __cdecl, ret 0).
std::uint32_t __cdecl codec_decompress_wrapper_00571470(const void* src, void* dst);

// Original 00593640..00593788 (329B, __cdecl, ret 0).
std::int32_t __cdecl codec_bpe_decode_00593640(const void* src, void* dst);

// Original 00593790..005937fd (110B, __cdecl, ret 0).
void __cdecl codec_bpe_emit_00593790(std::uint8_t sym);

// Original 00593800..005943d4 (3029B, __cdecl, ret 0).
std::uint32_t __cdecl codec_huff_decode_00593800(
    const void* src, void* dst, std::int32_t decode);

// Original 00594400..00594486 (135B, __cdecl, ret 0).
std::int32_t __cdecl codec_dxt1_decode_00594400(
    const void* src, void* dst, std::int32_t decode);

// Original 00594490..0059475d (718B, __cdecl, ret 0).
void __cdecl codec_dxt1_block_00594490(
    std::uint16_t* dst, std::int32_t pitch, const void* block);

// Original 00594760..005948b0 (337B, __cdecl, ret 0).
std::int32_t __cdecl codec_refpack_decode_00594760(
    const void* src, void* dst, std::int32_t decode);

// Original 005948c0..005948e4 (37B, __cdecl, ret 0).
void* __cdecl codec_refpack_copy_dwords_005948c0(
    void* dst, const void* src, std::int32_t bytes);

// Original 005948f0..0059495e (111B, __cdecl, ret 0).
void* __cdecl codec_refpack_match_copy_005948f0(
    void* dst, std::uint32_t dist, std::uint32_t len);

// Original 00594960..00594977 (24B, __cdecl, ret 0).
void __cdecl codec_refpack_copy_bytes_00594960(
    void* dst, const void* src, std::int32_t count);

} // namespace porsche
