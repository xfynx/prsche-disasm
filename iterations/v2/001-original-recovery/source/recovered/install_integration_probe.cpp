#include "porsche/application_instance.hpp"
#include "porsche/install_paths.hpp"
#include "porsche/process_exit.hpp"
#include "porsche/exit_shutdown.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/splash_progress.hpp"

#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

namespace {
constexpr std::uintptr_t arena_base = 0x03600000;
constexpr std::size_t arena_size = 0x10000;
constexpr std::size_t blob_offset = 0x1000;
std::uint8_t* arena;
std::uint8_t* blob;
std::string opened_path;
std::uint32_t open_mode;
std::uint32_t free_count;
std::uint32_t free_address;
std::uint32_t shutdown_code, shutdown_a, shutdown_b;
struct exit_signal {};

std::uint32_t address(const void* p) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}
}

namespace porsche {
void __cdecl startup_subsystem_004b6ff0();
void __cdecl startup_exit_005a246e(std::uint32_t);
void __cdecl render_driver_failure_005a246e(std::uint32_t);
void __cdecl application_instance_exit_005a246e(std::uint32_t);

void* __cdecl game_setup_resource_file_open_0059d8e0(const char* path,
                                                       std::uint32_t mode) {
    opened_path = path ? path : "<null>";
    open_mode = mode;
    return blob;
}
std::uint32_t __cdecl free_00531f90(void* pointer) {
    ++free_count;
    free_address = address(pointer);
    return 1;
}
void __cdecl exit_shutdown_execute_005a2490(std::uint32_t code,
                                             std::int32_t a,
                                             std::uint32_t b) {
    shutdown_code = code;
    shutdown_a = a;
    shutdown_b = b;
    throw exit_signal{};
}
}

int main() {
    arena = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(arena_base), arena_size,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!arena) return 3;
    blob = arena + blob_offset;

    std::string operation;
    while (std::cin >> operation) {
        if (operation == "ALIASES") {
            porsche::game_setup_earts_base_0065b32c = reinterpret_cast<const char*>(0x101u);
            porsche::game_setup_load_base_0065b334 = reinterpret_cast<const char*>(0x102u);
            porsche::engine_service_root_0065b360 = reinterpret_cast<const char*>(0x103u);
            porsche::splash_progress_alternate_base_0065b350 = reinterpret_cast<const char*>(0x104u);
            porsche::render_display_name_0065b304 = reinterpret_cast<const char*>(0x105u);
            std::cout << "{\"op\":\"ALIASES\",\"table_address\":"
                      << address(porsche::install_paths_table_0065b2a0) << ",\"addresses\":["
                      << address(&porsche::game_setup_earts_base_0065b32c) << ','
                      << address(&porsche::game_setup_load_base_0065b334) << ','
                      << address(&porsche::engine_service_root_0065b360) << ','
                      << address(&porsche::splash_progress_alternate_base_0065b350) << ','
                      << address(&porsche::render_display_name_0065b304)
                      << "],\"offsets\":[140,148,192,176,100],\"values\":["
                      << address(porsche::install_paths_table_0065b2a0[35]) << ','
                      << address(porsche::install_paths_table_0065b2a0[37]) << ','
                      << address(porsche::install_paths_table_0065b2a0[48]) << ','
                      << address(porsche::install_paths_table_0065b2a0[44]) << ','
                      << address(porsche::install_paths_table_0065b2a0[25]) << "]}\n";
        } else if (operation == "LOAD") {
            std::uint32_t length;
            std::string hex;
            if (!(std::cin >> length >> hex) || length > 0x3000 ||
                hex.size() != static_cast<std::size_t>(length) * 2) return 4;
            std::memset(arena, 0, arena_size);
            std::memcpy(blob - 12, &length, 4);
            auto digit = [](char c) -> std::uint8_t {
                return static_cast<std::uint8_t>(c <= '9' ? c - '0' : (c | 32) - 'a' + 10);
            };
            for (std::uint32_t i = 0; i < length; ++i)
                blob[i] = static_cast<std::uint8_t>((digit(hex[i * 2]) << 4) | digit(hex[i * 2 + 1]));
            for (std::uint32_t i = 0; i < 60; ++i)
                porsche::install_paths_table_0065b2a0[i] =
                    reinterpret_cast<const char*>(static_cast<std::uintptr_t>(0x1000 + i));
            open_mode = 0xffffffff;
            porsche::startup_subsystem_004b6ff0();
            const auto ptr_offset = [=](const char* value) -> std::int32_t {
                return value ? static_cast<std::int32_t>(address(value) - address(blob)) : -1;
            };
            std::cout << "{\"op\":\"LOAD\",\"open_path\":\"" << opened_path << "\",\"open_mode\":"
                      << open_mode << ",\"blob_offset\":"
                      << static_cast<std::int32_t>(address(porsche::install_paths_blob_0065b29c) - address(arena))
                      << ",\"table_offsets\":[";
            for (std::uint32_t i = 0; i < 60; ++i) {
                if (i) std::cout << ',';
                std::cout << ptr_offset(porsche::install_paths_table_0065b2a0[i]);
            }
            std::cout << "],\"alias_offsets\":["
                      << ptr_offset(porsche::game_setup_earts_base_0065b32c) << ','
                      << ptr_offset(porsche::game_setup_load_base_0065b334) << ','
                      << ptr_offset(porsche::engine_service_root_0065b360) << ','
                      << ptr_offset(porsche::splash_progress_alternate_base_0065b350) << ','
                      << ptr_offset(porsche::render_display_name_0065b304) << "]}\n";
        } else if (operation == "CLEAN") {
            std::uint32_t present;
            if (!(std::cin >> present) || present > 1) return 5;
            porsche::install_paths_blob_0065b29c = present ? blob : nullptr;
            free_count = free_address = 0;
            const auto result = porsche::install_paths_cleanup_004b7070();
            const auto current = porsche::install_paths_blob_0065b29c;
            std::cout << "{\"op\":\"CLEAN\",\"result\":" << result
                      << ",\"free_count\":" << free_count
                      << ",\"free_offset\":"
                      << (free_count ? static_cast<std::int32_t>(free_address - address(arena)) : -1)
                      << ",\"blob_offset\":"
                      << (current ? static_cast<std::int32_t>(address(current) - address(arena)) : -1)
                      << "}\n";
        } else if (operation == "EXIT") {
            std::uint32_t which, code;
            if (!(std::cin >> which >> code) || which > 2) return 6;
            shutdown_code = 0xffffffff;
            shutdown_a = shutdown_b = 0xffffffff;
            bool terminal = false;
            try {
                if (which == 0) porsche::startup_exit_005a246e(code);
                else if (which == 1) porsche::render_driver_failure_005a246e(code);
                else porsche::application_instance_exit_005a246e(code);
            } catch (const exit_signal&) { terminal = true; }
            std::cout << "{\"op\":\"EXIT\",\"terminal\":" << (terminal ? "true" : "false")
                      << ",\"which\":" << which << ",\"code\":" << shutdown_code
                      << ",\"a\":" << shutdown_a << ",\"b\":" << shutdown_b << "}\n";
        } else return 7;
    }
}
