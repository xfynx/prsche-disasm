#pragma once

#include <cstdint>

namespace porsche {

// 0055feb0 is the input/device-state provider called by 00560080 with selector 6.
// Its DirectInput and diagnostic closure remains an explicit typed boundary.
const std::uint8_t* __cdecl window_event_key_state_0055feb0(std::uint32_t selector);

// This address is read by 00560080 before the type-1 process-exit path.
extern std::uint32_t window_event_flag_005de020;

std::uint32_t __cdecl window_event_translate_00560080(std::uint32_t payload,
                                                       std::uint32_t type);

}
