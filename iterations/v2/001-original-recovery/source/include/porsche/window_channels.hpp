#pragma once

#include <cstdint>

namespace porsche {

// Win32 API boundaries called by the original channel toggle routine.
std::int16_t __stdcall window_channels_get_key_state(std::int32_t virtual_key);
void __stdcall window_channels_keybd_event(std::uint8_t virtual_key,
    std::uint8_t scan_code, std::uint32_t flags, std::uint32_t extra_info);

// Original Porsche.exe 005739b0; cdecl caller supplies (channel, desired low bit).
void __cdecl window_channel_005739b0(std::uint32_t channel,
    std::uint32_t desired_toggle_state);

}
