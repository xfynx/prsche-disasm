// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Owned palette pointer (005de2f8..005de2fb) and 256-entry scratch (006bda20..006bde1f).
extern std::uint32_t* render_depthconv_palette_ptr_005de2f8;
extern std::uint32_t render_depthconv_palette_scratch_006bda20[256];

// Original 00534b90..00534d35 (422B, __cdecl, ret 0).
void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode);

// Original 18 row-converter callbacks from 005de2fc / 005de3fc (all __cdecl, ret 0).
void __cdecl render_row_4_copy_005700d0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_4_005700f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_4_to_8_00570150(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_copy_00570190(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_8_005701b0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_1555_005702f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_4_to_16_lut_005703a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_16_lut_005703f0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_16_copy_00570470(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_4444_key_005705a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_24_lut_00570650(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_565_to_24_00570690(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_24_copy_00570700(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8888_to_24_00570720(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_8_to_32_lut_00570750(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_4444_to_8888_005708a0(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_24_to_8888_00570a00(void* dst, const void* src, std::int32_t count);
void __cdecl render_row_32_copy_00570a80(void* dst, const void* src, std::int32_t count);

} // namespace porsche
