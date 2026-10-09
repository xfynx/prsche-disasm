#include "porsche/window_channels.hpp"

#include <cstdint>
#include <iostream>

namespace {
std::int32_t key_state;
std::uint32_t key_queries;
std::uint32_t queried_key;
std::uint32_t event_count;
std::uint32_t events[8][4];
}

namespace porsche {
std::int16_t __stdcall window_channels_get_key_state(std::int32_t virtual_key) {
    ++key_queries;
    queried_key = static_cast<std::uint32_t>(virtual_key);
    return static_cast<std::int16_t>(key_state);
}

void __stdcall window_channels_keybd_event(std::uint8_t virtual_key,
    std::uint8_t scan_code, std::uint32_t flags, std::uint32_t extra_info) {
    if (event_count >= 8) return;
    events[event_count][0] = virtual_key;
    events[event_count][1] = scan_code;
    events[event_count][2] = flags;
    events[event_count][3] = extra_info;
    ++event_count;
}
}

int main() {
    std::uint32_t channel, desired, state;
    while (std::cin >> channel >> desired >> state) {
        key_state = static_cast<std::int32_t>(state);
        key_queries = queried_key = event_count = 0;
        porsche::window_channel_005739b0(channel, desired);
        std::cout << key_queries << ' ' << queried_key << ' ' << event_count;
        for (std::uint32_t i = 0; i != event_count; ++i)
            for (std::uint32_t j = 0; j != 4; ++j)
                std::cout << ' ' << events[i][j];
        std::cout << '\n';
    }
}
