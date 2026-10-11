#include "porsche/application_audio_device.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static_assert(sizeof(void*) == 4, "Run 133 requires Win32 x86 pointers");

namespace {
struct Scenario {
    unsigned function;
    std::uint32_t initialized;
    std::uint32_t active;
    std::uint16_t channels;
    std::uint16_t format;
    std::uint8_t mode;
    std::uint32_t callback;
    std::int32_t initialize_result;
    std::int32_t device_result;
};

constexpr Scenario kScenarios[] = {
    {0, 0, 0, 0, 0, 0, 0, 0x1234, 0}, // query: initialization path
    {0, 1, 0, 0, 0, 0, 0, -7, 0},     // query: already initialized; no boundary call
    {1, 1, 0, 0, 0, 0, 0, 0, 0},       // apply descriptor
    {2, 0, 1, 0, 16, 1, 0, 0, 0},      // active device early return
    {2, 1, 0, 2, 8, 2, 0x11223344, 0, 0}, // cached channels, alternate table
    {2, 0, 0, 0, 16, 1, 0, -3, 0},     // query init failure and early rollback
    {2, 0, 0, 0, 16, 1, 0, 0, -5},     // device failure after allocations
    {2, 1, 0, 0, 16, 1, 0, 0, 0},      // normal query/apply and successful start
    {2, 1, 0, 0xffff, 16, 1, 0, 0, 0}, // signed channel count and modulo size
    {1, 1, 0, 0, 0, 0, 0, 0, 0},       // overlapping apply source/destination
};

Scenario scenario{};
std::vector<std::string> calls;
char alternate_marker_target[60]{};

std::string hex32(std::uint32_t value) {
    std::ostringstream out;
    out << std::hex << std::setfill('0') << std::setw(8) << value;
    return out.str();
}

std::string hex_bytes(const std::uint8_t* data, std::size_t size) {
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (std::size_t i = 0; i < size; ++i)
        out << std::setw(2) << static_cast<unsigned>(data[i]);
    return out.str();
}

void call(std::string value) { calls.push_back(std::move(value)); }

void seed_state() {
    for (std::size_t i = 0; i < porsche::application_audio_device_state_006b48c0.backing.size(); ++i)
        porsche::application_audio_device_state_006b48c0.backing[i] =
            static_cast<std::uint8_t>((i * 29u + 7u) & 0xffu);
    porsche::application_audio_device_state_006b48c0[0xdc] =
        static_cast<std::uint8_t>(scenario.active);
    porsche::application_audio_device_state_006b48c0[0x18] =
        static_cast<std::uint8_t>(scenario.format);
    porsche::application_audio_device_state_006b48c0[0x19] =
        static_cast<std::uint8_t>(scenario.format >> 8);
    porsche::application_audio_device_state_006b48c0[0x1c] = scenario.mode;
    porsche::application_audio_device_state_006b48c0[0xe4] =
        static_cast<std::uint8_t>(scenario.channels);
    porsche::application_audio_device_state_006b48c0[0xe5] =
        static_cast<std::uint8_t>(scenario.channels >> 8);
    for (unsigned i = 0; i < 4; ++i)
        porsche::application_audio_device_state_006b48c0[0xec + i] =
            static_cast<std::uint8_t>(scenario.callback >> (8 * i));
    porsche::application_audio_descriptor_initialized_006a5c30 = scenario.initialized;
    for (unsigned i = 0; i < sizeof(alternate_marker_target); ++i)
        alternate_marker_target[i] = static_cast<char>(0xa0u + i);
    porsche::application_audio_marker_pointer_005e246c =
        porsche::application_audio_author_text_005e2470;
}
}

namespace porsche {
std::int32_t __cdecl application_audio_backend_initialize_0058a4f0() {
    call("0058a4f0");
    return scenario.initialize_result;
}

void __cdecl application_audio_backend_apply_0058a690() {
    call("0058a690");
}

void __cdecl application_audio_backend_configure_0058fef0(
    std::uint32_t buffer, std::uint32_t bytes) {
    call("0058fef0:" + hex32(buffer) + ":" + hex32(bytes));
}

void __cdecl application_audio_backend_configure_0058aa90(
    std::uint32_t buffer, std::uint32_t bytes) {
    call("0058aa90:" + hex32(buffer) + ":" + hex32(bytes));
}

std::uint32_t __cdecl application_audio_backend_allocate_0058aae0(
    std::uint32_t bytes) {
    const auto ordinal = static_cast<unsigned>(std::count_if(
        calls.begin(), calls.end(), [](const auto& event) {
            return event.rfind("0058aae0:", 0) == 0;
        }));
    call("0058aae0:" + hex32(bytes));
    return ordinal == 0 ? 0x71001000u : 0x71002000u;
}

void __cdecl application_audio_backend_start_0058e2d0() { call("0058e2d0"); }

std::int32_t __cdecl application_audio_backend_start_device_0058fdb0() {
    call("0058fdb0");
    return scenario.device_result;
}

void __cdecl application_audio_backend_stop_device_0058fe80() { call("0058fe80"); }
void __cdecl application_audio_backend_stop_0058e2e0() { call("0058e2e0"); }
void __cdecl application_audio_backend_finalize_0058e0e0() { call("0058e0e0"); }
}

int main(int argc, char** argv) {
    const auto id = argc > 1 ? static_cast<unsigned>(std::strtoul(argv[1], nullptr, 10)) : 0;
    if (id >= sizeof(kScenarios) / sizeof(kScenarios[0])) return 2;
    scenario = kScenarios[id];
    calls.clear();
    seed_state();

    std::array<std::uint8_t, 0x7c> descriptor{};
    for (std::size_t i = 0; i < descriptor.size(); ++i)
        descriptor[i] = static_cast<std::uint8_t>((i * 17u + 0x31u) & 0xffu);
    std::int32_t result{};
    if (scenario.function == 0) {
        result = porsche::application_audio_query_config_00565680(descriptor.data());
    } else if (scenario.function == 1) {
        const auto* input = id == 9
            ? porsche::application_audio_device_state_006b48c0.preceding_data()
            : descriptor.data();
        result = static_cast<std::int32_t>(
            porsche::application_audio_apply_config_005656d0(input));
    } else {
        porsche::application_audio_marker_pointer_005e246c = id == 3
            ? alternate_marker_target
            : porsche::application_audio_author_text_005e2470;
        result = porsche::application_audio_create_device_00565720(
            0x22004000u, 0x40000u, 0x12345678u);
    }

    std::cout << "result=" << hex32(static_cast<std::uint32_t>(result))
              << ",initialized=" << hex32(porsche::application_audio_descriptor_initialized_006a5c30)
              << '\n';
    std::cout << "state=" << hex_bytes(porsche::application_audio_device_state_006b48c0.data(),
        porsche::application_audio_device_state_006b48c0.size()) << '\n';
    std::cout << "output=" << hex_bytes(descriptor.data(), descriptor.size()) << '\n';
    std::cout << "author=" << hex_bytes(reinterpret_cast<const std::uint8_t*>(
        porsche::application_audio_author_text_005e2470), 60) << '\n';
    std::cout << "target=" << hex_bytes(reinterpret_cast<const std::uint8_t*>(
        porsche::application_audio_marker_pointer_005e246c), 60) << '\n';
    std::cout << "trace=";
    for (std::size_t i = 0; i < calls.size(); ++i) {
        if (i) std::cout << ';';
        std::cout << calls[i];
    }
    std::cout << '\n';
    return 0;
}
