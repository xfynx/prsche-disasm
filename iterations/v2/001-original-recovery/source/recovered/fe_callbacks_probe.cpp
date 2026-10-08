#include "porsche/fe_callbacks.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

namespace {
std::uint32_t call_index, call_mode, call_count, present;
unsigned hex_byte(const std::string& s, std::size_t offset) {
    return static_cast<unsigned>(std::stoul(s.substr(offset, 2), nullptr, 16));
}
void print_byte(unsigned value) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << value;
}
void print_word(std::uint32_t value) {
    for (int i = 0; i < 4; ++i) print_byte((value >> (8 * i)) & 255);
}
}
namespace porsche {
std::uint32_t fe_action_state_005e9130[0x21e];
void* __cdecl fe_input_getstate_00532e10(std::uint32_t index, std::uint32_t mode) {
    call_index = index; call_mode = mode; ++call_count;
    return present ? reinterpret_cast<void*>(0x12340000u) : nullptr;
}
}
int main() {
    std::uint32_t kind, packed;
    std::string list, masks;
    while (std::cin >> kind >> packed >> present >> list >> masks) {
        if (list.size() != 64 || masks.size() != 256) return 2;
        for (std::size_t i = 0; i < 32; ++i) {
            porsche::fe_input_devices_005e8e60[i] = static_cast<std::int8_t>(hex_byte(list, i * 2));
            std::uint32_t word = 0;
            for (int j = 0; j < 4; ++j) word |= hex_byte(masks, i * 8 + j * 2) << (j * 8);
            porsche::fe_input_masks_005e9380[i] = word;
        }
        call_index = call_mode = call_count = 0;
        std::uint32_t result = 0xffffffffu;
        switch (kind) {
        case 0: result = porsche::callback_004119e0(static_cast<std::int32_t>(packed)); break;
        case 1: result = porsche::callback_00411a80(static_cast<std::int32_t>(packed)); break;
        case 2: result = porsche::callback_00411b40(static_cast<std::int32_t>(packed)); break;
        default: return 3;
        }
        for (auto value : porsche::fe_input_devices_005e8e60) print_byte(static_cast<std::uint8_t>(value));
        std::cout << ' ';
        for (std::size_t i = 0; i < 32; ++i) print_word(porsche::fe_input_masks_005e9380[i]);
        std::cout << std::dec << ' ' << call_count << ' ' << call_index << ' ' << call_mode
                  << ' ' << result << '\n';
    }
}
