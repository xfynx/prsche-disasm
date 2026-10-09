#pragma once
#include <cstdint>

namespace porsche {
extern std::uint8_t startup_joystick_initialized_005deac4;
extern std::int32_t startup_joystick_count_006a5bf4;
extern std::uint32_t& startup_keyboard_value_0069e5a0;

std::int32_t __cdecl startup_keyboard_detect_00564e70();
void __cdecl startup_joystick_enumerate_00564ab0();
void __cdecl startup_joystick_thunk_00564850();

// Win32 multimedia/user32 boundaries used by these startup routines.
std::uint32_t __cdecl startup_get_keyboard_type(std::uint32_t kind);
std::int32_t __cdecl startup_joy_get_num_devs();
std::uint32_t __cdecl startup_joy_get_dev_caps(std::uint32_t id,void* caps,
                                                std::uint32_t bytes);
}
