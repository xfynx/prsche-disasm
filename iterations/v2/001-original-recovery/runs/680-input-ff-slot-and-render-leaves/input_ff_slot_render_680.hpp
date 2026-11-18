// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../494-render-resource-leaves/render_resource_494.hpp"
#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "porsche/input_state.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

// Original 005337a0..005337d5 (54B, __cdecl, ret 0; returns HRESULT in EAX).
std::uint32_t __cdecl input_effect_download_005337a0(
    InputDevice* device, void* effect);

// Original 005337e0..00533808 (41B, __cdecl, ret 0; void).
void __cdecl frame_control_slot_unload_005337e0(std::int32_t slot);

// Original 00533730..00533757 (40B, __cdecl, ret 0; returns slot index 0..31 or -1).
std::int32_t __cdecl frame_control_slot_find_free_00533730();

// Original 00533760..0053379f (64B, __cdecl, ret 0; void).
void __cdecl frame_control_slot_download_00533760(std::int32_t slot);

// Original 00533120..0053315b (60B, __cdecl, ret 0; returns HRESULT in EAX).
std::uint32_t __cdecl input_slot_reset_ff_00533120(std::int32_t slot_index);

// Original 00574080..0057409c (29B, __cdecl, ret 0; returns byte offset in EAX).
std::int32_t __cdecl render_pixel_offset_00574080(std::int32_t x, std::int32_t y);

} // namespace porsche
