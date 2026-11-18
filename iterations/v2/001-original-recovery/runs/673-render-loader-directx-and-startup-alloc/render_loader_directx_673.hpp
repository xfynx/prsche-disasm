// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/exit_registry.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_loader.hpp"

namespace porsche {

using RenderDirectxGetVersionExA = std::int32_t (__stdcall*)(void* version_information);
using RenderDirectxGetFileVersionInfoSizeA =
    std::uint32_t (__stdcall*)(const char* filename, std::uint32_t* handle);
using RenderDirectxGetFileVersionInfoA = std::int32_t (__stdcall*)(
    const char* filename, std::uint32_t handle, std::uint32_t len, void* data);
using RenderDirectxVerQueryValueA = std::int32_t (__stdcall*)(
    const void* block, const char* sub_block, void** buffer, std::uint32_t* len);

// Win32 IAT facades for 00574eb0:
// [0x005b2150] GetVersionExA, [0x005b2334] (via 00594cbc) GetFileVersionInfoSizeA,
// [0x005b232c] (via 00594cb6) GetFileVersionInfoA, [0x005b2330] (via 00594cb0) VerQueryValueA.
extern RenderDirectxGetVersionExA render_directx_get_version_ex_a;
extern RenderDirectxGetFileVersionInfoSizeA render_directx_get_file_version_info_size_a;
extern RenderDirectxGetFileVersionInfoA render_directx_get_file_version_info_a;
extern RenderDirectxVerQueryValueA render_directx_ver_query_value_a;

// Canonical definition provided here for declaration already in porsche/render_loader.hpp:
// - render_loader_directx_00574eb0 (00574eb0..00574f79, 202B, __cdecl, ret 0)
// Reuses canonical exit_registry_malloc_005a3be5 (`porsche/exit_registry.hpp`)
// and formatter_crt_free_005a3b9d (`porsche/formatter_crt_runtime.hpp`).

// Original 00414bd0..00414c1a (75B, __cdecl, ret 0; returns table* in EAX).
void* __cdecl startup_sorted_table_create_00414bd0(
    const char* name, std::int32_t capacity);

// Original 00414c30..00414cab (124B, __cdecl, ret 0; void).
void __cdecl startup_sorted_table_insert_00414c30(
    void* table, std::uint32_t value0, std::uint32_t value1, std::int32_t key);

} // namespace porsche
