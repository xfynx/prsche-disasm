#include "porsche/application_services.hpp"
#include "porsche/application_state.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/install_paths.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace porsche {
namespace {
std::vector<std::array<std::uint32_t, 5>> trace;
std::uint8_t init_result = 0;
std::int32_t measure_result = 0;
std::uint32_t allocation_result = 1;
std::int32_t message_result = 0x1234;
std::int32_t directory_result = 1;
int allocation_token = 7;
std::string captured_text, captured_title, captured_path;

void record(std::uint32_t id, std::uint32_t a = 0, std::uint32_t b = 0,
            std::uint32_t c = 0, std::uint32_t d = 0) {
    trace.push_back({id, a, b, c, d});
}
}

void* __cdecl allocate_00531ca0(const char* name, std::int32_t bytes,
                                std::uint32_t flags) {
    record(3, name && std::strcmp(name, "audio heap") == 0 ? 0x005d13ecu : 0,
           static_cast<std::uint32_t>(bytes), flags);
    return allocation_result ? &allocation_token : nullptr;
}
std::uint32_t __cdecl free_00531f90(void* address) {
    record(10, address == &allocation_token ? 0x23000000u
        : static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(address)));
    return 1;
}
std::uint8_t __cdecl application_audio_probe_initialize_004a66b0() {
    record(4); return init_result;
}
void __cdecl application_audio_probe_configure_004ae100(
    std::int32_t first, std::uint32_t second, std::uint32_t config_va) {
    record(5, static_cast<std::uint32_t>(first), second, config_va);
}
void __cdecl application_audio_probe_start_004a8b80() { record(6); }
void __cdecl application_audio_probe_prepare_004ae2b0() { record(7); }
void __cdecl application_audio_probe_finish_004ab4b0() { record(8); }
std::int32_t __cdecl application_audio_probe_measure_00565890() {
    record(9); return measure_result;
}
std::int32_t __cdecl application_service_message_box_api(
    const char* text, const char* title) {
    captured_text = text ? text : "<null>";
    captured_title = title ? title : "<null>";
    record(1, 0, 0, 0);
    return message_result;
}
std::int32_t __cdecl application_service_create_directory_api(const char* path) {
    captured_path = path ? path : "<null>";
    record(2, 0x0065b360u);
    return directory_result;
}
}

using namespace porsche;

static void write_output(std::uint32_t first, std::uint32_t second) {
    std::cout << "{\"trace\":[";
    for (std::size_t i = 0; i < trace.size(); ++i) {
        if (i) std::cout << ',';
        const auto& e = trace[i];
        std::cout << '[' << e[0] << ',' << e[1] << ',' << e[2] << ','
                  << e[3] << ',' << e[4] << ']';
    }
    std::cout << "],\"arena\":[";
    for (std::size_t i = 0; i < application_state_word_count; ++i) {
        if (i) std::cout << ',';
        std::cout << application_state_006573e8.words()[i];
    }
    std::cout << "],\"outside\":[" << application_audio_config_00655d34
              << ',' << application_audio_mode_00655d38 << ','
              << static_cast<unsigned>(application_audio_flag_00655d3c)
              << ',' << (application_audio_buffer_00655d44 ==
                  static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&allocation_token))
                  ? 0x23000000u : application_audio_buffer_00655d44) << ','
              << application_audio_active_005d1734 << "],\"records\":[";
    for (std::size_t i = 0; i < 8; ++i) {
        if (i) std::cout << ',';
        const auto& r = application_audio_records_006564a0[i];
        std::cout << '[' << r.raw_00 << ',' << r.opaque_04 << ','
                  << r.raw_08 << ',' << r.opaque_0c << ']';
    }
    std::cout << "],\"apis\":[\"" << captured_text << "\",\""
              << captured_title << "\",\"" << captured_path
              << "\"],\"args\":[" << first << ',' << second << "]}\n";
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::uint32_t first, second, mode, gate, init, alloc, measure;
        if (!(std::istringstream(line) >> first >> second >> mode >> gate >> init >>
              alloc >> measure)) return 2;
        trace.clear(); captured_text.clear(); captured_title.clear(); captured_path.clear();
        init_result = static_cast<std::uint8_t>(init);
        allocation_result = alloc;
        measure_result = static_cast<std::int32_t>(measure);
        application_state_006573e8.words().fill(0xabababab);
        application_state_006573e8.word(0x00657c94u) = gate;
        application_state_006573e8.word(0x00657c98u) = mode;
        application_state_006573e8.word(0x00657c9cu) = 0xcccccccc;
        application_audio_config_00655d34 = 0x11111111;
        application_audio_mode_00655d38 = 0x22222222;
        application_audio_flag_00655d3c = 0x33;
        application_audio_buffer_00655d44 = 0x44444444;
        application_audio_active_005d1734 = 0x55555555;
        for (std::size_t i = 0; i < 8; ++i) {
            auto& r = application_audio_records_006564a0[i];
            r = {static_cast<std::uint32_t>(0x1000 + i),
                 static_cast<std::uint32_t>(0x2000 + i),
                 static_cast<std::uint32_t>(0x3000 + i),
                 static_cast<std::uint32_t>(0x4000 + i)};
        }
        install_paths_table_0065b2a0[48] = "install-root";
        (void)application_main_memory_dialog("Insufficient space in the swap file.  Please make additional space available and try again.",
                                             "Memory full");
        application_main_create_directory(0x0065b360u);
        application_main_setup_heaps(first, second);
        write_output(first, second);
    }
}
