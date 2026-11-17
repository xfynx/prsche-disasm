#pragma once

#include <cstdint>
#include "porsche/render_loader.hpp"

namespace porsche {

// Loader-zero .data DWORD owned by 005759f0 (0x006a64c0, 4 bytes).
extern std::uint32_t render_saved_display_hook_006a64c0;

// Original entry 005759f0..00575a1a (43 bytes).
void __cdecl render_initialize_callbacks_005759f0();

} // namespace porsche
