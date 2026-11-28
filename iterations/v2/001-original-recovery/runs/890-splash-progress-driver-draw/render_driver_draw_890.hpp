// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

struct RenderChopTex {
    std::uint32_t textures[2];
    void* tile_shape;
};
static_assert(sizeof(RenderChopTex) == 12u, "original 12-byte chop-tex record");

// Owned initialized .data color (005dfb7c) and .bss chop-tex handle (006a6450).
extern std::uint32_t render_choptex_color_005dfb7c;
extern RenderChopTex* render_choptex_handle_006a6450;

// Owned initialized .data span tables 005dec38..005decb8 and selector 005decdc..005decef.
extern const void* const render_span_table_scalar_005dec38[8];
extern const void* const render_span_table_fpu_005dec58[8];
extern const void* const render_span_table_mmx_a_005dec78[8];
extern const void* const render_span_table_mmx_b_005dec98[8];
extern const void* const render_span_table_sse_005decb8[8];
extern const void* const* const render_span_tables_005decdc[5];

// Original 0053d570..0053d692 (291B, __cdecl, ret 0).
void __cdecl splash_progress_driver_draw_0053d570(
    std::uint32_t texture, std::int32_t x, std::int32_t y);

// Original 00572a90..00572b3b (172B), 00572b40..00572ed8 (921B), 00572ee0..00572f2f (80B).
RenderChopTex* __cdecl render_choptex_create_00572a90(
    std::int32_t width, std::int32_t height, std::int32_t depth, std::uint32_t flags);
std::int32_t __cdecl render_choptex_draw_00572b40(
    RenderChopTex* chop, const void* shape, std::int32_t x, std::int32_t y,
    std::int32_t dst_w, std::int32_t dst_h);
std::int32_t __cdecl render_choptex_free_00572ee0(RenderChopTex* chop);

// Original 005b0c00..005b0d81 (359B noncontiguous PE range, __cdecl, ret 0).
void __cdecl heap_copy_005b0c00(void* dst, const void* src, std::uint32_t bytes);

// Original 15 span copy wrappers 0053d390..0053d56f (27B..31B, __cdecl, ret 0).
void __cdecl render_span_scalar_16_0053d390(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_scalar_24_0053d3b0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_scalar_32_0053d3d0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_fpu_16_0053d3f0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_fpu_24_0053d410(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_fpu_32_0053d430(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_a_16_0053d450(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_a_24_0053d470(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_a_32_0053d490(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_b_16_0053d4b0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_b_24_0053d4d0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_mmx_b_32_0053d4f0(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_sse_16_0053d510(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_sse_24_0053d530(void* dst, const void* src, std::uint32_t count);
void __cdecl render_span_sse_32_0053d550(void* dst, const void* src, std::uint32_t count);

} // namespace porsche
