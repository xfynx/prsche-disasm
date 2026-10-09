#pragma once
#include <cstdint>

namespace porsche {
// Original Porsche.exe 005728b0, cdecl, four DWORD stack arguments.
// Stack arguments are x, y, button mask, and transition (nonzero for down).
void __cdecl mouse_input_consumer_005728b0(std::uint32_t x,
                                            std::uint32_t y,
                                            std::uint32_t button_mask,
                                            std::uint32_t transition);
}
