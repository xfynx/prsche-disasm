// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run708: recovered body 005556a0 (scene_texture_callback, 10B).
//
// 005a177b is already owned as formatter_stdio_printf_005a177b (formatter_stdio.cpp);
// Run708 reuses that canonical provider and does not redefine it.
// 005a134b is the CRT __RTDynamicCast primitive (external); excluded from recovery.
#pragma once

#include <cstdint>

#include "texture_process_575.hpp"

namespace porsche {

// Recovered original body (exact Run700 extern name/signature).
void __cdecl scene_texture_callback_005556a0(void* callback);

} // namespace porsche