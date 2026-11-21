// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../374-render-descriptor/render_descriptor.hpp"
#include "../611-splash-sprite-horizflip/splash_sprite_horizflip_611.hpp"
#include "../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.hpp"
#include "../734-render-fill/render_fill_734.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

using RenderShapeSpanFn = void(__cdecl*)(void* dst, const void* src, std::uint32_t count);

// Owned read-only .rdata strings at 005c073c..005c0775 (55B total).
extern const char render_shape_invalid_fmt_005c073c[37];
extern const char render_shape_source_file_005c0764[18];

// Owned zero-initialized .bss two-stage span callback pointers at 006a6424..006a642b (8B total).
extern RenderShapeSpanFn render_shape_stage1_fn_006a6424;
extern RenderShapeSpanFn render_shape_stage2_fn_006a6428;

// Original 005719c0..00571a04 (69B, __cdecl, ret 0).
void __cdecl render_shape_two_stage_span_005719c0(
    void* dst, const void* src, std::uint32_t count);

// Unrecovered downstream shape conversion helpers called by 00571630.
void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode);
void* __cdecl render_shape_convert_type_00534d40(
    const void* shape, std::uint32_t target_type,
    std::int32_t use_dither, std::int32_t direct_mode);

// render_shape_transfer_00571630 (00571630..00571984, 853B) is declared in
// ../734-render-fill/render_fill_734.hpp.

} // namespace porsche
