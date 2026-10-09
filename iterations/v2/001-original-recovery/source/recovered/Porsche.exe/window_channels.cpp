#include "porsche/window_channels.hpp"

namespace porsche {
namespace {
struct ChannelKeys {
    std::uint8_t virtual_key;
    std::uint8_t scan_code;
    std::uint32_t keydown_flags;
    std::uint32_t keyup_flags;
};

constexpr ChannelKeys keys[] = {
    {0x14, 0x3a, 0, 2}, // VK_CAPITAL
    {0x90, 0x45, 1, 3}, // VK_NUMLOCK; extended key on down and up
    {0x91, 0x46, 0, 2}, // VK_SCROLL
};
}

void __cdecl window_channel_005739b0(std::uint32_t channel,
    std::uint32_t desired_toggle_state) {
    if (channel >= sizeof(keys) / sizeof(keys[0])) return;

    const ChannelKeys& key = keys[channel];
    const std::uint32_t current_toggle_state =
        static_cast<std::uint16_t>(window_channels_get_key_state(key.virtual_key)) & 1u;
    if (current_toggle_state == desired_toggle_state) return;

    window_channels_keybd_event(key.virtual_key, key.scan_code,
        key.keydown_flags, 0);
    window_channels_keybd_event(key.virtual_key, key.scan_code,
        key.keyup_flags, 0);
}

}
