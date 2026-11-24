// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../515-render-driver-constructors/render_driver_515.hpp"
#include "porsche/render_display.hpp"

namespace porsche {

// Read-only .rdata string tags owned by 00556d20.
extern const char render_driver_query_pbuf_tag_005cf80c[5];
extern const char render_driver_query_uv_test_005cf814[8];

// Original 00556d20..00557085 (870B, __thiscall -> __fastcall, ret 0; uint32).
// Declared in ../515-render-driver-constructors/render_driver_515.hpp.
std::uint32_t __fastcall render_driver_probe_00556d20(void* self, void* unused_edx);

// Original 00557240..0055734a (267B, __cdecl, ret 0; uint32).
std::uint32_t __cdecl render_pixel_to_argb8888_00557240(
    std::uint32_t pixel, std::uint32_t mode);

} // namespace porsche
