// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005916a0..0059170e (111B),
// 00591760..0059177a (27B), 00568e90..00568eb2 (35B), 00568260..00568292 (51B),
// 00533f00..00533f33 (52B), and 00561b80..00561b93 (20B).
#include "file_exists_path_device_665.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace porsche {

namespace {

std::uint32_t __stdcall os_get_full_path_name_a(
    const char* file_name, std::uint32_t buffer_length, char* buffer, char** file_part) {
    return static_cast<std::uint32_t>(
        ::GetFullPathNameA(file_name, buffer_length, buffer, file_part));
}

char* __stdcall os_char_upper_a(char* text) {
    return ::CharUpperA(text);
}

} // namespace

DiskGetFullPathNameA platform_disk_get_full_path_name = os_get_full_path_name_a;
DiskCharUpperA platform_disk_char_upper = os_char_upper_a;

char __cdecl disk_path_drive_letter_005916a0(const char* path) {
    if (formatter_search_character_005a2780(path, 0x7c) != nullptr) {
        return 0;
    }
    if (path == nullptr) {
        path = ".";
    }
    char* file_part = nullptr;
    char buffer[261];
    const std::uint32_t len = platform_disk_get_full_path_name(
        path, 0x105u, buffer, &file_part);
    (void)platform_disk_char_upper(buffer);
    if (static_cast<std::int32_t>(len) <= 1) {
        return 0;
    }
    if (buffer[1] != ':') {
        return 0;
    }
    return buffer[0];
}

std::uint8_t __cdecl disk_path_device_00591760(const char* path) {
    const std::uint32_t letter =
        static_cast<std::uint8_t>(disk_path_drive_letter_005916a0(path));
    if (letter == 0u) {
        return 0u;
    }
    return static_cast<std::uint8_t>(letter - 0x40u);
}

std::uint32_t __cdecl file_device_name_00568e90(const char* path) {
    if (formatter_search_character_005a2780(path, 0x7c) != nullptr) {
        return 0u;
    }
    return static_cast<std::uint32_t>(disk_path_device_00591760(path));
}

std::uint32_t __cdecl request_exists_00568260(
    const char* path, std::uint32_t group, void* context) {
    const std::uint32_t device = file_device_name_00568e90(path);
    FileOperation* const op = operation_allocate_005682a0(
        6u, static_cast<std::uint8_t>(group), context, device);
    operation_name_005684e0(op, path);
    return operation_queue_00568200(op);
}

std::int32_t __cdecl file_exists_sync_00533f00(
    const char* path, std::uint32_t group) {
    const std::uint32_t id = request_exists_00568260(path, group, nullptr);
    if (id == 0u) {
        return 0;
    }
    (void)file_wait_00567f70(id);
    return static_cast<std::int32_t>(operation_complete_00567df0(id));
}

std::int32_t __cdecl file_exists_00561b80(const char* path) {
    return file_exists_sync_00533f00(path, resource_leaf_group_005df770);
}

} // namespace porsche
