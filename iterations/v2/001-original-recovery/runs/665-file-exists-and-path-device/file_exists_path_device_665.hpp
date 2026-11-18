// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/disk_open.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_search.hpp"
#include "porsche/resource_leaf.hpp"

namespace porsche {

using DiskGetFullPathNameA = std::uint32_t (__stdcall*)(
    const char* file_name, std::uint32_t buffer_length, char* buffer, char** file_part);
using DiskCharUpperA = char* (__stdcall*)(char* text);

// Win32 IAT facades for 005916a0 (`[0x005b221c]` GetFullPathNameA, `[0x005b2290]` CharUpperA).
extern DiskGetFullPathNameA platform_disk_get_full_path_name;
extern DiskCharUpperA platform_disk_char_upper;

// Original 005916a0..0059170e (111B, __cdecl, ret 0; returns uppercase drive letter in AL or 0).
char __cdecl disk_path_drive_letter_005916a0(const char* path);

// Original 00568260..00568292 (51B, __cdecl, ret 0).
std::uint32_t __cdecl request_exists_00568260(
    const char* path, std::uint32_t group, void* context);

// Original 00533f00..00533f33 (52B, __cdecl, ret 0).
std::int32_t __cdecl file_exists_sync_00533f00(
    const char* path, std::uint32_t group);

// Canonical definitions provided here for declarations already in porsche/*.hpp:
// - disk_path_device_00591760           (`porsche/disk_open.hpp`,        00591760..0059177a, 27B)
// - file_device_name_00568e90           (`porsche/files.hpp`,            00568e90..00568eb2, 35B)
// - file_exists_00561b80                (`porsche/files.hpp`,            00561b80..00561b93, 20B)
// Reuses canonical formatter_search_character_005a2780 from formatter_search.cpp (`porsche/formatter_search.hpp`).

} // namespace porsche
