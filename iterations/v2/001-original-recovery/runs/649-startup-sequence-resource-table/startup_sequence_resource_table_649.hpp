// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/resource_predicate.hpp"
#include "porsche/startup_sequence.hpp"
#include "render_startup_text_leaves_644.hpp"
#include "resource_open_334.hpp"
#include "startup_context_table_helpers_646.hpp"

namespace porsche {

// Loader-zero .data BSS globals touched by 00452590 and 004690d0.
extern std::uint16_t startup_night_shape_enabled_00628a28;
extern const char* startup_resource_prefix_0065b30c;
extern void* startup_night_shape_buffer_0061c164;
extern void* startup_night_shape_data_0061e1cc;
extern void* startup_context_table_owner_00613e04;
extern std::uint32_t startup_head_state_a_0061bcc8;
extern std::uint32_t startup_head_state_b_0061e180;
extern void* startup_head_table_entry_0061e1d4;
extern std::uint8_t startup_sequence_flag_00619760;

// Original 00561e00..00561e3e (63B, __cdecl, ret 0):
// Quiet sibling of file_open_00561ca0; sets callback_diagnostic_flag = 0.
void* __cdecl file_open_quiet_00561e00(const char* path, std::uint32_t flags);

// Original 0059d9b0..0059da7d (206B, __cdecl, ret 0):
// Quiet sibling of resource_open_0059d8e0; opens via file_open_quiet_00561e00
// and invokes missing_file_006afbe4(name, -2) when rooted lookups fail.
void* __cdecl resource_open_quiet_0059d9b0(const char* name, std::uint32_t flags);

// Original 00452590..00452655 (198B, __cdecl, ret 0):
// Loads %snight.psh ("nght" entry + 0x10) when 00628a28 != 0, resets
// 0061bcc8/0061e180, and queries (0, "HEAD") from 00613e04 via 0044d320.
void __cdecl startup_sequence_resource_table_setup_00452590();

// Original 004690d0..004690e0 (17B, __cdecl, ret 0) is declared in
// porsche/startup_sequence.hpp as startup_sequence_call_004690d0().

} // namespace porsche
