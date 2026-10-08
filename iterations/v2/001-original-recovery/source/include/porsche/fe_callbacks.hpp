#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// PE .bss: zero before 0x00411680 fills the list and masks with 0xff.
extern std::int8_t fe_input_devices_005e8e60[32];
// Aliases fe_action_state_005e9130 at byte offset 0x250 (word offset 0x94).
extern std::uint32_t* const fe_input_masks_005e9380;

// Original input getstate service 0x00532e10, mode 6. Still an external boundary.
void* __cdecl fe_input_getstate_00532e10(std::uint32_t index, std::uint32_t mode);

// Each original callback returns zero in EAX.
std::uint32_t __cdecl callback_004119e0(std::int32_t packed);
std::uint32_t __cdecl callback_00411a80(std::int32_t packed);
std::uint32_t __cdecl callback_00411b40(std::int32_t packed);
}
