// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../611-splash-sprite-horizflip/splash_sprite_horizflip_611.hpp"
#include "../671-font-state-and-vec3-dist/font_state_vec3_671.hpp"
#include "../782-render-calibrate-service/render_calibrate_service_782.hpp"
#include "porsche/shared_runtime_globals.hpp"

namespace porsche {

// Read-only .rdata string owned by 0053e5c0 (34 bytes).
extern const char font_setstate_invalid_state_005bbb20[34];

// Shift-JIS half-width ASCII (0x20..0x7f) -> full-width lookup table at 005dfcc8..005dfd87 (192 bytes).
extern const std::uint16_t font_ascii_to_sjis_fullwidth_005dfcc8[96];

// Original 0053c6c0..0053c8a9 (490B, __cdecl, ret 0; void*).
// Declared in ../782-render-calibrate-service/render_calibrate_service_782.hpp.
void* __cdecl render_debug_font_create_0053c6c0(const void* font_data);

// Original 0053d920..0053d969 (74B, __cdecl, ret 0; const void*).
const void* __cdecl font_find_glyph_0053d920(const void* font, std::uint32_t ch);

// Original 0053d970..0053d9b9 (74B, __cdecl, ret 0; const void*).
const void* __cdecl font_bsearch_glyph_0053d970(
    std::uint32_t key, const void* table, std::int32_t count, std::int32_t stride);

// Original 0053e5c0..0053e842 (643B, __cdecl, ret 0; void).
void __cdecl font_setstate_0053e5c0(void* font, std::int32_t state, std::uint32_t value);

// Original 00573a90..00573aa0 (17B, __cdecl, ret 0; uint32).
std::uint32_t __cdecl font_read_u16_cursor_00573a90(const std::uint8_t** cursor);

// Original 00573ab0..00573abd (14B, __cdecl, ret 0; uint32).
std::uint32_t __cdecl font_read_u8_cursor_00573ab0(const std::uint8_t** cursor);

// Original 00573ac0..00573add (30B, __cdecl, ret 0; uint32).
std::uint32_t __cdecl font_ascii_to_sjis_fullwidth_00573ac0(std::uint32_t ch);

// Original 00573ae0..00573b1a (59B, __cdecl, ret 0; uint32).
std::uint32_t __cdecl font_read_sjis_cursor_00573ae0(const std::uint8_t** cursor);

} // namespace porsche
