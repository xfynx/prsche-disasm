// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../782-render-calibrate-service/render_calibrate_service_782.hpp"
#include "porsche/application_alloc.hpp"

namespace porsche {

// Typed unrecovered child boundary called by 00571a10.
void __cdecl render_font_convert_glyphs_00594980(void* font);

// Original 00571a10..00571a8c (125B, __cdecl, ret 0).
// Declared in ../782-render-calibrate-service/render_calibrate_service_782.hpp.
void __cdecl render_font_prepare_00571a10(void* font);

// Original 00536840..0053686b (44B, __thiscall/fastcall, ret 4).
void* __fastcall render_calibration_dtor_00536840(
    void* self, void* unused_edx, std::uint32_t flags);

// Original 0053c8b0..0053c8c8 (25B, __cdecl, ret 0).
void __cdecl render_font_destroy_0053c8b0(void* font);

// Original 00571a90..00571ab8 (41B, __cdecl, ret 0).
void __cdecl render_font_release_handle_00571a90(void* font);

} // namespace porsche
