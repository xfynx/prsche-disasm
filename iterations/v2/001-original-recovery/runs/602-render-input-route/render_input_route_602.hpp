#pragma once

#include <cstdint>

namespace porsche {

using RenderInputHandler_602 = void (__cdecl *)();

// Loader-zero .data arrays owned by 00586cd0 (0x006ad440..0x006ad743, 772 bytes total).
extern RenderInputHandler_602 render_input_handlers_006ad440[65];
extern std::uint8_t render_input_low_map_006ad544[256];
extern std::uint8_t render_input_high_map_006ad644[256];

// Original entry 00586cd0..00586d0e (63 bytes).
std::uint32_t __cdecl render_input_dispatch_00586cd0(std::uint32_t event);

} // namespace porsche
