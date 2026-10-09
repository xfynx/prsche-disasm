#include "porsche/window_event_translation.hpp"
#include "porsche/window_runtime.hpp"

#include <array>
#include <cstdint>
#include <iostream>
#include <string>

namespace porsche {
std::uint32_t window_create_state_005de024 = 0;
std::array<std::uint8_t, 0xbd> fixture_key_state{};
std::uint32_t provider_calls = 0;
std::uint32_t provider_selector = 0xffffffffu;
std::uint32_t exit_calls = 0;
std::uint32_t exit_code = 0xffffffffu;

const std::uint8_t* __cdecl window_event_key_state_0055feb0(std::uint32_t selector) {
    ++provider_calls;
    provider_selector = selector;
    return fixture_key_state.data();
}

struct TerminalExit {};
void __cdecl application_instance_exit_005a246e(std::uint32_t code) {
    ++exit_calls;
    exit_code = code;
    throw TerminalExit{};
}
}

int main() {
    using namespace porsche;
    std::uint32_t payload, type, window_state, guard;
    std::string hex;
    while (std::cin >> payload >> type >> window_state >> guard >> hex) {
        if (hex.size() != fixture_key_state.size() * 2) return 2;
        for (std::size_t i = 0; i < fixture_key_state.size(); ++i)
            fixture_key_state[i] = static_cast<std::uint8_t>(std::stoul(hex.substr(i * 2, 2), nullptr, 16));
        window_create_state_005de024 = window_state;
        window_event_flag_005de020 = guard;
        provider_calls = 0;
        provider_selector = 0xffffffffu;
        exit_calls = 0;
        exit_code = 0xffffffffu;
        std::uint32_t result = 0xffffffffu;
        bool exited = false;
        try {
            result = window_event_translate_00560080(payload, type);
        } catch (const TerminalExit&) {
            exited = true;
        }
        std::cout << static_cast<unsigned>(exited) << ' ' << result << ' '
                  << provider_calls << ' ' << provider_selector << ' '
                  << window_create_state_005de024 << ' ' << window_event_flag_005de020 << ' '
                  << exit_calls << ' ' << exit_code << std::endl;
    }
}
