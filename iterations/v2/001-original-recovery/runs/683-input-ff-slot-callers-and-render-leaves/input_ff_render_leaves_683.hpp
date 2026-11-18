// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.hpp"
#include "porsche/fe_callbacks.hpp"
#include "porsche/input_state.hpp"

namespace porsche {

// Owned zero-initialized .data/.bss pointer at 0069cb08..0069cb0b (4B).
extern void* input_directinput_0069cb08;

// Original 005330a0..00533115 (118B, __cdecl, ret 0; returns 0 or 1 in EAX).
std::uint32_t __cdecl input_slot_enable_ff_005330a0(std::int32_t slot_index);

// Original 00533320..0053335a (59B, __cdecl, ret 0; void).
void __cdecl input_slot_pause_ff_00533320(std::int32_t slot_index);

// Original 00533360..0053339a (59B, __cdecl, ret 0; void).
void __cdecl input_slot_continue_ff_00533360(std::int32_t slot_index);

// Original 00572f30..00572f5a (43B, __cdecl, ret 0; returns RGB565 in EAX).
std::uint32_t __cdecl render_color_888_to_565_00572f30(std::uint32_t color);

// Original 00572f5b..00572f8f (53B, __cdecl, ret 0; returns ARGB1555 in EAX).
std::uint32_t __cdecl render_color_888_to_1555_00572f5b(std::uint32_t color);

// Original 00570420..0057046b (76B, __cdecl, ret 0; void).
void __cdecl render_palette_555_to_565_00570420(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);

// Original 00570490..005704b1 (34B, __cdecl, ret 0; void).
void __cdecl render_palette_copy_strided16_00570490(
    std::uint16_t* dst, const std::uint16_t* src, std::int32_t count);

} // namespace porsche
