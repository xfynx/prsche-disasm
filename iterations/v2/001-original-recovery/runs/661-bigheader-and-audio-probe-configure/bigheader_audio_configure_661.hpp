// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_lifecycle.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/application_services.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/heap.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/resource_leaf.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../556-application-audio-lifecycle/application_audio_lifecycle_556.hpp"
#include "../590-game-setup-object-init/game_setup_object_init_590.hpp"
#include "../658-resource-loadat-and-reset/resource_loadat_658.hpp"

namespace porsche {

// Owned loader-zero .data BSS global at 0065b314 (4B, single ref in 004ae100).
extern const char* audio_probe_viv_prefix_0065b314;

// Owned .data strings (each referenced only by 004ae100).
extern const char audio_probe_viv_fmt_005d1bf0[12];
extern const char audio_probe_buffer_name_005d1bfc[13];
extern const char audio_probe_globals_name_005d1c0c[14];

// Owned .rdata strings (each referenced only by 00562100).
extern const char file_load_bigheader_open_err_005bcde4[45];
extern const char file_load_bigheader_mem_err_005bce14[59];
extern const char file_load_bigheader_hdr_err_005bce50[57];

// Unrecovered child declared with exact original ABI matching 564-audio-callback-resource-chain.
std::uint32_t __cdecl audio_resource_size_00566560(std::uint32_t source);

// Original 00568b50..00568b8f (64B, __cdecl, ret 0).
std::uint32_t __cdecl request_read_offset_00568b50(
    void* handle, std::uint32_t offset, void* buffer, std::int32_t size,
    std::uint32_t group, void* context);

// Original 00533d70..00533d96 (39B, __cdecl, ret 0).
std::uint32_t __cdecl file_read_offset_00533d70(
    void* handle, std::uint32_t offset, void* buffer, std::int32_t size,
    std::uint32_t group);

// Original 00562100..005622f2 (499B, __cdecl, ret 0; absent from functions.jsonl).
std::int32_t __cdecl file_load_bigheader_callback_00562100(
    std::uint32_t group, void* opaque_context);

// Original 00562300..0056233e (63B, __cdecl, ret 0).
void* __cdecl file_load_bigheader_quiet_00562300(
    const char* path, std::uint32_t flags);

// Original 0059df70..0059e03d (206B, __cdecl, ret 0).
void* __cdecl resource_load_bigheader_quiet_0059df70(
    const char* name, std::uint32_t flags);

// Canonical application_audio_probe_configure_004ae100 is declared in porsche/application_services.hpp.

} // namespace porsche
