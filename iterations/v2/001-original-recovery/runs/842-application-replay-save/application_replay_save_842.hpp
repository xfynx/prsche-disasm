// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#pragma once

#include <cstdint>

#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/resource_leaf.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/startup_sequence.hpp"
#include "startup_replay_load_668.hpp"

namespace porsche {

// Canonical declaration matching 661-bigheader-and-audio-probe-configure.
std::uint32_t __cdecl file_read_offset_00533d70(
    void* handle, std::uint32_t offset, void* buffer, std::int32_t size,
    std::uint32_t group);

// Owned .data / .rdata string literals for 00413fd0 and 00562390.
extern const char replay_default_filename_005cc68c[11];
extern const char replay_final_gametick_fmt_005cc678[19];
extern const char file_save_source_005bcd00[20];
extern const char file_save_write_err_005bceb0[40];
extern const char file_save_open_err_005bce8c[36];

// Original 00562390..00562451 (194B, __cdecl, ret 0; supplemented in original-index-supplement.json).
std::int32_t __cdecl file_save_callback_00562390(std::uint32_t group, void* opaque_context);

// Original 00562460..005624a6 (71B, __cdecl, ret 0).
void __cdecl file_save_00562460(const char* path, void* buffer, std::int32_t size);

// Original 0059e170..0059e1af (64B, __cdecl, ret 0).
void __cdecl resource_save_0059e170(const char* name, const void* buffer, std::int32_t size);

// Original 00413fd0..0041405d (142B, __cdecl, ret 0).
void __cdecl application_sim_boundary_00413fd0();

} // namespace porsche
