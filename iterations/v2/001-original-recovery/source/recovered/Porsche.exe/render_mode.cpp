#include "porsche/render_mode.hpp"
#include "porsche/render_activate.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
std::uint8_t render_mode_state_00619790[0x71]{};
std::uint32_t render_mode_time_value_005ce908{};
std::uint8_t render_mode_option_0069dd1d{};

namespace {
constexpr std::size_t state_offset(std::uint32_t address) {
    return static_cast<std::size_t>(address - 0x00619790u);
}
std::uint8_t byte_at(std::uint32_t address) {
    return render_mode_state_00619790[state_offset(address)];
}
void put_byte(std::uint32_t address, std::uint8_t value) {
    render_mode_state_00619790[state_offset(address)] = value;
}
std::uint32_t dword_at(std::uint32_t address) {
    std::uint32_t value;
    std::memcpy(&value, render_mode_state_00619790 + state_offset(address), sizeof(value));
    return value;
}
void put_dword(std::uint32_t address, std::uint32_t value) {
    std::memcpy(render_mode_state_00619790 + state_offset(address), &value, sizeof(value));
}
std::uint32_t display_word(std::size_t offset) {
    std::uint32_t value;
    auto* display = reinterpret_cast<const std::uint8_t*>(render_display_00628130);
    std::memcpy(&value, display + offset, sizeof(value));
    return value;
}
std::uint32_t read_record_word(const std::uint8_t* record, std::size_t index) {
    std::uint32_t value;
    std::memcpy(&value, record + index * sizeof(value), sizeof(value));
    return value;
}
void* mode_record_pointer(void* driver, std::uint32_t index) {
    std::uint32_t modes;
    std::memcpy(&modes, static_cast<const std::uint8_t*>(driver) + 8, sizeof(modes));
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(modes + index * 0x28u));
}
}

void __cdecl render_mode_query_0044e720(std::uint32_t index,
    std::uint32_t* record10) {
    auto* display = reinterpret_cast<const std::uint8_t*>(render_display_00628130);
    if (display[0x60] != 0) {
        record10[0] = 640;
        record10[1] = 480;
        record10[2] = 16;
        record10[5] = 2;
        return;
    }
    auto* driver = reinterpret_cast<void*>(static_cast<std::uintptr_t>(display_word(0x70)));
    render_mode_driver_prepare_vslot9(driver);
    const auto* record = static_cast<const std::uint8_t*>(mode_record_pointer(driver, index));
    for (std::size_t i = 0; i != 10; ++i) record10[i] = read_record_word(record, i);
}

void __cdecl render_mode_commit_0044ebf0(std::uint32_t index) {
    auto* display = reinterpret_cast<const std::uint8_t*>(render_display_00628130);
    std::uint32_t width = 640, height = 480, format = 16;
    if (display[0x60] == 0) {
        auto* driver = reinterpret_cast<void*>(static_cast<std::uintptr_t>(display_word(0x70)));
        render_mode_driver_prepare_vslot9(driver);
        const auto* record = static_cast<const std::uint8_t*>(mode_record_pointer(driver, index));
        width = read_record_word(record, 0);
        height = read_record_word(record, 1);
        format = read_record_word(record, 2);
    }
    render_display_mode_index_00619780 = index;
    render_display_actual_width_00619784 = width;
    render_display_actual_height_00619788 = height;
    render_display_actual_mode_0061978c = format == 15 ? 16 : format;
    put_byte(0x0061979a, 1);
    render_mode_apply_settings_0044e890();
}

void __cdecl render_mode_update_state_0044ed10() {
    if (byte_at(0x00619800) != 0) {
        render_mode_update_alternate_0044f020();
        return;
    }

    const float product = static_cast<float>(render_mode_setting_00657d80) * 0.01f;
    const float selected = product <= 0.25f ? 0.25f : product;
    std::uint32_t selected_bits;
    std::memcpy(&selected_bits, &selected, sizeof(selected_bits));
    render_mode_setstate_iat_006bd918(0x2e, selected_bits);

    render_mode_time_value_005ce908 = render_mode_clock_00555bc0();
    render_display_clock_005deb1c = 0;
    static constexpr std::uint32_t table[4] = {
        0x3f000000u, 0x3f2b851fu, 0x3f547ae1u, 0x3f800000u};
    const std::uint32_t table_bits = table[static_cast<std::uint32_t>(render_mode_setting_00657d70)];
    put_dword(0x006197d0, table_bits);

    const bool previous = byte_at(0x00619799) != 0;
    if (previous) {
        render_mode_setting_00657d6c = 0;
        render_mode_setting_00657d5c = 1;
        put_byte(0x006197c2, 1);
    } else {
        put_byte(0x006197c2, 0);
    }
    put_dword(0x006197f8, render_mode_setting_00657d78 == 1 ? 8u : 0u);
    render_mode_set_option_00535b40(0);
    put_byte(0x006197e6, static_cast<std::uint8_t>(dword_at(0x006197b0) != 0xe));

    switch (static_cast<std::uint32_t>(render_mode_setting_00657d6c)) {
    case 0:
        put_byte(0x006197e5, 0); put_dword(0x006197e0, 0); put_byte(0x006197e6, 0);
        put_dword(0x006197fc, 0); put_byte(0x006197e7, 0); put_dword(0x006197ec, 0xf);
        put_dword(0x006197f0, 0x3c); put_dword(0x006197f4, 0); break;
    case 1:
        put_byte(0x006197e5, 0); put_dword(0x006197e0, 100); put_byte(0x006197e6, 0);
        put_dword(0x006197fc, 0); put_byte(0x006197e7, 0); put_dword(0x006197ec, 0xf);
        put_dword(0x006197f0, 0x8c); put_dword(0x006197f4, 1); break;
    case 2:
        put_byte(0x006197e5, 0); put_dword(0x006197e0, 200);
        put_byte(0x006197e6, static_cast<std::uint8_t>(dword_at(0x006197b0) != 0xe));
        put_dword(0x006197fc, 0); put_byte(0x006197e7, 1); put_dword(0x006197ec, 7);
        put_dword(0x006197f0, 0xdc); put_dword(0x006197f4, 2); break;
    default:
        put_byte(0x006197e6, static_cast<std::uint8_t>(dword_at(0x006197b0) != 0xe));
        put_byte(0x006197e5, 0); put_dword(0x006197e0, 0x100); put_dword(0x006197fc, 1);
        put_byte(0x006197e7, 1); put_dword(0x006197ec, 7); put_dword(0x006197f0, 300);
        put_dword(0x006197f4, 3);
        if (byte_at(0x006197a6) != 0) render_mode_set_option_00535b40(1);
        break;
    }

    if (render_mode_setting_00657d60 == 0) {
        put_byte(0x006197c8, 0); put_byte(0x006197c9, 0); put_byte(0x006197ca, 0);
        put_byte(0x006197cb, 0); put_dword(0x006197f8, dword_at(0x006197f8) | 1u);
    } else if (render_mode_setting_00657d60 == 1) {
        put_byte(0x006197c8, 1); put_byte(0x006197c9, 1); put_byte(0x006197ca, 0);
        put_byte(0x006197cb, 0); put_dword(0x006197f8, dword_at(0x006197f8) | 3u);
    } else {
        put_byte(0x006197c8, 1); put_byte(0x006197c9, 1); put_byte(0x006197ca, 1);
        put_byte(0x006197cb, 1); put_dword(0x006197f8, dword_at(0x006197f8) | 3u);
    }
    const auto device = static_cast<std::uint32_t>(render_mode_setting_00657d68);
    put_dword(0x006197c4, device == 0 ? 0u : device == 1 ? 1u : 2u);
    if (byte_at(0x006197a8) != 0 && (byte_at(0x006197f8) & 2) != 0)
        put_dword(0x006197f8, (dword_at(0x006197f8) & ~3u) | 4u);
    put_dword(0x006197dc, 1); put_byte(0x006197e4, 0); put_byte(0x006197c1, 0);
    put_byte(0x006197c0, 0); put_dword(0x006197d4, 0); put_dword(0x006197cc, 0);
    put_byte(0x006197c3, 1); put_dword(0x006197d8, 8);
}

// The original 0x535b40 stores only the low byte of its cdecl argument.
void __cdecl render_mode_set_option_00535b40(std::uint32_t value) {
    render_mode_option_0069dd1d = static_cast<std::uint8_t>(value);
}
}
