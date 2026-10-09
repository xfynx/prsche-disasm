#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/render_state_init.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

namespace porsche {
std::uint8_t render_mode_state_00619790[0x71]{};
std::uint32_t render_mode_time_value_005ce908{};
std::uint8_t render_mode_option_0069dd1d{};

namespace {
std::uint32_t clock_result{};
struct Event { const char* kind; std::uint32_t a, b; };
std::vector<Event> events;
void print_events() {
    std::cout << '[';
    for (std::size_t i=0; i<events.size(); ++i) {
        if (i) std::cout << ',';
        std::cout << "[\"" << events[i].kind << "\"," << events[i].a << ',' << events[i].b << ']';
    }
    std::cout << ']';
}
}

void __stdcall render_mode_setstate_iat_006bd918(std::uint32_t key, std::uint32_t value) {
    events.push_back({"setstate", key, value});
}
std::uint32_t __cdecl render_mode_clock_00555bc0() {
    events.push_back({"clock", 0, clock_result});
    return clock_result;
}
void __cdecl render_mode_set_option_00535b40(std::uint32_t value) {
    render_mode_option_0069dd1d = static_cast<std::uint8_t>(value);
    events.push_back({"option", value, 0});
}
}

int main() {
    using namespace porsche;
    std::uint32_t seed{}, setting80{}, setting60{}, setting68{}, byte_a8{}, clock{};
    while (std::cin >> seed >> setting80 >> setting60 >> setting68 >> byte_a8 >> clock) {
        std::memset(render_mode_state_00619790, static_cast<int>(seed & 0xff), sizeof(render_mode_state_00619790));
        render_mode_state_00619790[0xa8 - 0x90] = static_cast<std::uint8_t>(byte_a8);
        render_mode_setting_00657d80 = static_cast<std::int32_t>(setting80);
        render_mode_setting_00657d60 = static_cast<std::int32_t>(setting60);
        render_mode_setting_00657d68 = static_cast<std::int32_t>(setting68);
        render_mode_option_0069dd1d = static_cast<std::uint8_t>(seed);
        render_mode_time_value_005ce908 = seed ^ 0x11223344u;
        render_display_clock_005deb1c = seed ^ 0x55667788u;
        clock_result = clock;
        events.clear();
        render_mode_update_alternate_0044f020();
        std::cout << "{\"state\":[";
        for (std::size_t i=0; i<sizeof(render_mode_state_00619790); ++i)
            std::cout << (i ? "," : "") << static_cast<unsigned>(render_mode_state_00619790[i]);
        std::cout << "],\"time\":[" << render_mode_time_value_005ce908 << ','
                  << render_display_clock_005deb1c << "],\"option\":"
                  << static_cast<unsigned>(render_mode_option_0069dd1d) << ",\"calls\":";
        print_events();
        std::cout << "}\n";
    }
}
