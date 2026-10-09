#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/render_mode.hpp"
#include "porsche/render_activate.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>

namespace porsche {
RenderDisplay* render_display_00628130{};
std::uint32_t render_display_mode_index_00619780{};
std::uint32_t render_display_actual_width_00619784{}, render_display_actual_height_00619788{};
std::uint32_t render_display_actual_mode_0061978c{};
static std::uint8_t object_bytes[0x100]{};
static std::uint8_t driver_bytes[0x20]{};
static std::uint8_t records[0x28 * 4]{};
static unsigned vslot_calls{}, apply_calls{}, alternate_calls{}, setstate_calls{};
static std::uint32_t clock_result{};
void __cdecl render_mode_driver_prepare_vslot9(void*) { ++vslot_calls; }
void __cdecl render_mode_apply_settings_0044e890() { ++apply_calls; }
void __cdecl render_mode_update_alternate_0044f020() { ++alternate_calls; }
std::uint32_t __cdecl render_mode_clock_00555bc0() { return clock_result; }
void __stdcall render_mode_setstate_iat_006bd918(std::uint32_t, std::uint32_t) { ++setstate_calls; }
}

int main() {
    using namespace porsche;
    unsigned op, index, fullscreen, seed, previous, clock_value;
    std::uint32_t words[10];
    int setting5c,setting60,setting68,setting6c,setting70,setting78,setting80,settinga6;
    while (std::cin >> op >> index >> fullscreen >> seed >> previous >> clock_value
        >> setting5c >> setting60 >> setting68 >> setting6c >> setting70 >> setting78 >> setting80 >> settinga6
        >> words[0] >> words[1] >> words[2] >> words[3] >> words[4]
        >> words[5] >> words[6] >> words[7] >> words[8] >> words[9]) {
        std::memset(object_bytes, 0, sizeof(object_bytes));
        std::memset(driver_bytes, 0, sizeof(driver_bytes));
        std::memset(records, 0, sizeof(records));
        for (std::size_t record=0;record<4;++record)
            std::memcpy(records + record*0x28, words, sizeof(words));
        *reinterpret_cast<std::uint32_t*>(driver_bytes + 8) = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(records));
        *reinterpret_cast<std::uint32_t*>(object_bytes + 0x70) = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(driver_bytes));
        object_bytes[0x60] = static_cast<std::uint8_t>(fullscreen);
        render_display_00628130 = reinterpret_cast<RenderDisplay*>(object_bytes);
        render_display_mode_index_00619780 = 0x11111111;
        render_display_actual_width_00619784 = 0x22222222;
        render_display_actual_height_00619788 = 0x33333333;
        render_display_actual_mode_0061978c = 0x44444444;
        render_display_clock_005deb1c = 0x55555555;
        std::memset(render_mode_state_00619790, static_cast<int>(seed & 0xff), sizeof(render_mode_state_00619790));
        render_mode_state_00619790[0x09]=static_cast<std::uint8_t>(previous);
        render_mode_state_00619790[0x16]=static_cast<std::uint8_t>(settinga6);
        render_mode_setting_00657d5c=setting5c; render_mode_setting_00657d60=setting60;
        render_mode_setting_00657d68=setting68; render_mode_setting_00657d6c=setting6c;
        render_mode_setting_00657d70=setting70; render_mode_setting_00657d78=setting78;
        render_mode_setting_00657d80=setting80;
        render_mode_time_value_005ce908=0x66666666; render_mode_option_0069dd1d=0x77;
        clock_result=clock_value; vslot_calls=apply_calls=alternate_calls=setstate_calls=0;
        std::uint32_t out[10]; for (auto& v:out) v=0xa5a5a5a5;
        if (op==0) render_mode_query_0044e720(index,out);
        else if (op==1) render_mode_commit_0044ebf0(index);
        else render_mode_update_state_0044ed10();
        std::cout << "{\"op\":" << op << ",\"out\":[";
        for (int i=0;i<10;++i) std::cout << (i?",":"") << out[i];
        std::cout << "],\"globals\":[" << render_display_mode_index_00619780 << ','
            << render_display_actual_width_00619784 << ',' << render_display_actual_height_00619788 << ','
            << render_display_actual_mode_0061978c << ',' << render_display_clock_005deb1c << ','
            << render_mode_time_value_005ce908 << ',' << static_cast<unsigned>(render_mode_option_0069dd1d)
            << "],\"counts\":[" << vslot_calls << ',' << apply_calls << ',' << alternate_calls << ',' << setstate_calls
            << "],\"state\":[";
        for (std::size_t i=0;i<sizeof(render_mode_state_00619790);++i)
            std::cout << (i?",":"") << static_cast<unsigned>(render_mode_state_00619790[i]);
        std::cout << "]}\n";
    }
}
