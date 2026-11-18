// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original 005702a0..005702e3 (68B, __cdecl, ret 0; void).
void __cdecl render_palette_565_to_1555_005702a0(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);

// Original 00570920..00570985 (102B, __cdecl, ret 0; void).
void __cdecl render_palette_a555_to_8888_00570920(
    std::uint32_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 00570990..005709f4 (101B, __cdecl, ret 0; void).
void __cdecl render_palette_a565_to_8888_00570990(
    std::uint32_t* dst, const std::uint32_t* src, std::int32_t count);

// Original 00570ff0..005710a7 (184B, __cdecl, ret 0; void).
void __cdecl render_palette_vga6_to_8888_00570ff0(
    std::int32_t count, const std::uint8_t* src, std::uint8_t* dst);

// Original 00571160..005711ad (78B, __cdecl, ret 0; void).
void __cdecl render_palette_rgb24_to_8888_00571160(
    std::int32_t count, const std::uint8_t* src, std::uint8_t* dst);

} // namespace porsche
