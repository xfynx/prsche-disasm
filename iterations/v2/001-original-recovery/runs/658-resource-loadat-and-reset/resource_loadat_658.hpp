// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/resource_leaf.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp"

namespace porsche {

// Owned read-only .rdata string at 005bcd90..005bcdb5 (38B).
extern const char file_loadat_open_err_005bcd90[38];

// Unrecovered child declared with exact original ABI matching 564-audio-callback-resource-chain.
std::uint32_t __cdecl audio_resource_kind_00566520(std::uint32_t source);

// Original 00561e90..00561f19 (138B, __cdecl, ret 0).
std::int32_t __cdecl file_loadat_callback_00561e90(
    std::uint32_t group, void* opaque_context);

// Original 00561e40..00561e86 (71B, __cdecl, ret 0; absent from functions.jsonl).
std::uint32_t __cdecl file_loadat_00561e40(
    const char* path, void* buffer, std::uint32_t max_bytes);

// Original 00561f20..00561f66 (71B, __cdecl, ret 0).
std::uint32_t __cdecl file_loadat_quiet_00561f20(
    const char* path, void* buffer, std::uint32_t max_bytes);

// Original 0059db50..0059dc29 (218B, __cdecl, ret 0).
std::uint32_t __cdecl resource_loadat_quiet_0059db50(
    const char* name, void* buffer, std::uint32_t max_bytes);

// Original 00566880..005668bd (62B, __cdecl, ret 0).
std::uint32_t __cdecl audio_resource_data_offset_00566880(std::uint32_t source);

// Original 004adf50..004ae00b (188B, __cdecl, ret 0).
void __cdecl audio_resource_query_root_reset_004adf50();

} // namespace porsche
