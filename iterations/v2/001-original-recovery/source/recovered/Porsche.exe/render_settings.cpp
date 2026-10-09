#include "porsche/render_settings.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
constexpr std::size_t offset(std::uint32_t address) {
    return static_cast<std::size_t>(address - 0x00619790u);
}
std::uint8_t& byte_at(std::uint32_t address) {
    return render_mode_state_00619790[offset(address)];
}
void put_dword(std::uint32_t address, std::uint32_t value) {
    std::memcpy(render_mode_state_00619790 + offset(address), &value, sizeof(value));
}
std::uint32_t read_word(const RenderSettingsDevice* device, std::size_t at) {
    std::uint32_t value;
    std::memcpy(&value, device->bytes + at, sizeof(value));
    return value;
}
std::int32_t read_signed(const RenderSettingsDevice* device, std::size_t at) {
    std::int32_t value;
    std::memcpy(&value, device->bytes + at, sizeof(value));
    return value;
}
}

void __cdecl render_mode_apply_settings_0044e890() {
    const auto* device = render_settings_current_device_006bd934();

    byte_at(0x00619799) = 0;
    const auto old24 = render_settings_get_state_006bd984(0x24);
    const auto result24 = render_settings_set_state_006bd97c(0x24, 0x80);
    render_settings_set_state_006bd97c(0x24, old24);
    byte_at(0x0061979c) = static_cast<std::uint8_t>(result24 != 0);
    byte_at(0x0061979d) = 1;

    const auto old2f = render_settings_get_state_006bd984(0x2f);
    const auto result2f = render_settings_set_state_006bd97c(0x2f, 1);
    render_settings_set_state_006bd97c(0x2f, old2f);
    byte_at(0x0061979e) = static_cast<std::uint8_t>(result2f != 0);

    const auto old06 = render_settings_get_state_006bd984(6);
    const auto result06 = render_settings_set_state_006bd97c(6, 2);
    render_settings_set_state_006bd97c(6, old06);
    byte_at(0x0061979f) = static_cast<std::uint8_t>(result06 != 0);
    byte_at(0x006197a0) = static_cast<std::uint8_t>((read_word(device, 0x0c) & 0x40u) == 0);

    const auto old15 = render_settings_get_state_006bd984(0x15);
    const auto result15 = render_settings_set_state_006bd97c(0x15, 1);
    render_settings_set_state_006bd97c(0x15, old15);
    byte_at(0x006197a1) = static_cast<std::uint8_t>(result15 != 0);

    const auto old07 = render_settings_get_state_006bd984(7);
    const auto result07 = render_settings_set_state_006bd97c(7, 1);
    render_settings_set_state_006bd97c(7, old07);
    byte_at(0x006197a2) = static_cast<std::uint8_t>(result07 != 0);
    byte_at(0x006197a3) = 0;
    byte_at(0x006197a4) = 0;

    const auto old0b_1 = render_settings_get_state_006bd984(0x0b);
    const auto result0b_1 = render_settings_set_state_006bd97c(0x0b, 1);
    render_settings_set_state_006bd97c(0x0b, old0b_1);
    byte_at(0x006197a5) = static_cast<std::uint8_t>(result0b_1 != 0);

    const auto old0b_3 = render_settings_get_state_006bd984(0x0b);
    const auto result0b_3 = render_settings_set_state_006bd97c(0x0b, 3);
    render_settings_set_state_006bd97c(0x0b, old0b_3);
    byte_at(0x006197a6) = static_cast<std::uint8_t>(result0b_3 != 0);

    const auto old38 = render_settings_get_state_006bd984(0x38);
    const auto result38 = render_settings_set_state_006bd97c(0x38, 1);
    render_settings_set_state_006bd97c(0x38, old38);
    byte_at(0x006197a7) = static_cast<std::uint8_t>(result38 != 0);
    const auto width_a = read_signed(device, 0x14);
    const auto width_b = read_signed(device, 0x20);
    const auto minimum = width_a < width_b ? width_a : width_b;
    std::memcpy(render_mode_state_00619790 + offset(0x006197b4), &minimum, sizeof(minimum));
    put_dword(0x006197b8, read_word(device, 0x44));

    const auto old04 = render_settings_get_state_006bd984(4);
    const auto result04 = render_settings_set_state_006bd97c(4, 2);
    render_settings_set_state_006bd97c(4, old04);
    byte_at(0x0061979b) = static_cast<std::uint8_t>(result04 != 0);
    byte_at(0x006197ad) = 0;
    byte_at(0x006197ae) = static_cast<std::uint8_t>(render_settings_value_00657da4 == 0);

    const auto old29_1 = render_settings_get_state_006bd984(0x29);
    render_settings_set_state_006bd97c(0x29, 6);
    render_settings_set_state_006bd97c(0x29, old29_1);
    const auto old29_2 = render_settings_get_state_006bd984(0x29);
    render_settings_set_state_006bd97c(0x29, 8);
    render_settings_set_state_006bd97c(0x29, old29_2);

    byte_at(0x006197a8) = 0;
    put_dword(0x00619794, read_word(device, 0x70));
    if (render_settings_read_config_005a1e10(
            reinterpret_cast<char*>(const_cast<std::uint8_t*>(device->bytes + 0x80)),
            "Trident Blade") != 0) {
        byte_at(0x006197ad) = 1;
        render_settings_set_state_006bd97c(0x3c, 1);
    }

    const auto device_id = read_word(device, 0);
    const auto device_type = read_word(device, 0x6c);
    const auto surface_bytes = read_word(device, 0x70);
    if (device_id == 0x33444632u || device_id == 0x33444658u) {
        byte_at(0x00619798) = 1;
        put_dword(0x00619790, surface_bytes);
        byte_at(0x006197aa) = 1;
        byte_at(0x006197a9) = 1;
        put_dword(0x006197b0, 0);
        return;
    }

    if (device_type == 1) byte_at(0x006197ae) = 0;
    if (device_type == 9 || device_type == 10) {
        byte_at(0x00619798) = 1;
        put_dword(0x00619790, surface_bytes);
        byte_at(0x006197a8) = 0;
    } else {
        if (render_settings_read_config_005a1e10(
                reinterpret_cast<char*>(const_cast<std::uint8_t*>(device->bytes + 0x80)),
                "Voodoo") != 0) {
            byte_at(0x006197a8) = 0;
        }
        if (device_type == 0x0f) byte_at(0x006197a8) = 0;
        const std::uint32_t pixels =
            (render_display_actual_mode_0061978c >> 3) *
            render_display_actual_height_00619788 * render_display_actual_width_00619784;
        byte_at(0x00619798) = 0;
        put_dword(0x00619790, surface_bytes - pixels * 3u);
    }

    byte_at(0x006197a9) = 0;
    put_dword(0x006197b0, device_type);
    const auto supported = render_settings_set_state_006bd97c(0x1c3, 0);
    byte_at(0x006197aa) = static_cast<std::uint8_t>(supported != 0);
    if (device_type == 3 || device_type == 0x0e || device_type == 2) {
        byte_at(0x006197aa) = 0;
        return;
    }
}
}
