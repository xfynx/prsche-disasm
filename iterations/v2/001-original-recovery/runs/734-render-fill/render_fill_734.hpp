// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../317-scalar-fill-backend/005b0980.hpp"
#include "../319-mmx-fill-backend/005b0a40.hpp"
#include "../320-sse-fill-backend/005b0b00.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
#include "../381-pixel-draw-helpers/pixel_draw_helpers.hpp"
#include "../611-splash-sprite-horizflip/splash_sprite_horizflip_611.hpp"
#include "../674-render-depth-helper-leaves/render_depth_helpers_674.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_display.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

// Owned initialized .data backend selector at 005decd8..005decdf (4B, initial -1).
extern std::int32_t render_fill_backend_005decd8;

// Owned initialized .data span-callback tables at 005df880..005df8f3 (116B total):
// three 8-entry (32B) format tables (scalar, MMX, SSE) and the 5-entry (20B)
// backend selector table 005df8e0..005df8f3.
extern const void* const render_fill_table_scalar_005df880[8];
extern const void* const render_fill_table_mmx_005df8a0[8];
extern const void* const render_fill_table_sse_005df8c0[8];
extern const void* const* const render_fill_mode_tables_005df8e0[5];

// Owned zero-initialized .bss packed fill color at 006a5bb8..006a5bbb (4B).
extern std::uint32_t render_fill_color_006a5bb8;

// Original 00562500..00562519 (26B, __cdecl, ret 0).
void* __cdecl render_fill_span_scalar_8_00562500(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562520..0056253c (29B, __cdecl, ret 0).
void* __cdecl render_fill_span_scalar_16_00562520(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562540..00562569 (42B, __cdecl, ret 0).
void* __cdecl render_fill_span_24_00562540(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562570..00562590 (33B, __cdecl, ret 0).
void* __cdecl render_fill_span_scalar_32_00562570(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 005625a0..005625b9 (26B, __cdecl, ret 0).
void* __cdecl render_fill_span_mmx_8_005625a0(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 005625c0..005625dc (29B, __cdecl, ret 0).
void* __cdecl render_fill_span_mmx_16_005625c0(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 005625e0..00562600 (33B, __cdecl, ret 0).
void* __cdecl render_fill_span_mmx_32_005625e0(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562610..00562629 (26B, __cdecl, ret 0).
void* __cdecl render_fill_span_sse_8_00562610(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562630..0056264c (29B, __cdecl, ret 0).
void* __cdecl render_fill_span_sse_16_00562630(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Original 00562650..00562670 (33B, __cdecl, ret 0).
void* __cdecl render_fill_span_sse_32_00562650(
    void* dst, std::uint32_t src_unused, std::uint32_t count);

// Unrecovered downstream software shape/span transfer engine at 00571630..00571984 (853B).
void __cdecl render_shape_transfer_00571630(
    const void* shape, std::int32_t x, std::int32_t y, const void* const* table);

// splash_progress_draw_text_00562680 (00562680..005627ef, 368B) is declared in
// porsche/splash_progress.hpp.
// render_display_fill_00537e00 (00537e00..00537e2c, 45B) is declared in
// porsche/render_display.hpp.

} // namespace porsche
