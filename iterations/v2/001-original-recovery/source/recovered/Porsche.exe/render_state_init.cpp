#include "porsche/render_state_init.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
std::uint8_t state_byte(std::uint32_t address) {
    return render_mode_state_00619790[address - 0x00619790u];
}
void put_byte(std::uint32_t address, std::uint8_t value) {
    render_mode_state_00619790[address - 0x00619790u] = value;
}
std::uint32_t state_dword(std::uint32_t address) {
    std::uint32_t value;
    std::memcpy(&value, render_mode_state_00619790 + (address - 0x00619790u), sizeof(value));
    return value;
}
void put_dword(std::uint32_t address, std::uint32_t value) {
    std::memcpy(render_mode_state_00619790 + (address - 0x00619790u), &value, sizeof(value));
}
}

void __cdecl render_mode_update_alternate_0044f020() {
    // FILD -> FMUL -> FSTP rounds the product to binary32 before comparison.
    volatile float product = static_cast<float>(render_mode_setting_00657d80) * 0.01f;
    const float selected = product <= 0.25f ? 0.25f : product;
    std::uint32_t selected_bits;
    std::memcpy(&selected_bits, &selected, sizeof(selected_bits));
    render_mode_setstate_iat_006bd918(0x2e, selected_bits);

    render_mode_time_value_005ce908 = render_mode_clock_00555bc0();
    render_display_clock_005deb1c = 0;
    put_byte(0x006197c2, 0);
    put_dword(0x006197f8, 0);
    render_mode_set_option_00535b40(0);

    put_byte(0x006197e5, 0);
    put_dword(0x006197e0, 0x100);
    put_byte(0x006197e6, 1);
    put_dword(0x006197fc, 1);
    put_byte(0x006197e7, 1);
    put_dword(0x006197ec, 7);
    put_dword(0x006197f0, 300);
    put_dword(0x006197f4, 3);
    put_byte(0x006197c8, 1);
    put_byte(0x006197c9, 1);
    put_byte(0x006197ca, 1);
    put_byte(0x006197cb, 1);

    const auto flags = state_dword(0x006197f8) |
        (render_mode_setting_00657d60 == 0 ? 1u : 3u);
    put_dword(0x006197f8, flags);

    const auto device = static_cast<std::uint32_t>(render_mode_setting_00657d68);
    put_dword(0x006197c4, device == 0 ? 0u : device == 1 ? 1u : 2u);
    if (state_byte(0x006197a8) != 0 && (flags & 2u) != 0)
        put_dword(0x006197f8, (flags & ~3u) | 4u);

    put_byte(0x006197e4, 0);
    put_byte(0x006197c1, 0);
    put_byte(0x006197c0, 0);
    put_dword(0x006197d4, 0);
    put_dword(0x006197cc, 0);
    put_byte(0x006197c3, 1);
    put_dword(0x006197d8, 8);
    put_dword(0x006197dc, 1);
}
}
