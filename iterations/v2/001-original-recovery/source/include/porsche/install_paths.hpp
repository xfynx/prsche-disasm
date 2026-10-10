#pragma once
#include <cstdint>

namespace porsche {
// Run 116's canonical views of the original install path data cells.
extern void* install_paths_blob_0065b29c;
extern const char* install_paths_table_0065b2a0[60];

std::uint32_t __cdecl install_paths_load_004b6ff0();
std::uint32_t __cdecl install_paths_cleanup_004b7070();
std::uint32_t __cdecl install_paths_size_00556640(const void* blob);
}
