// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_main.hpp"
#include "porsche/application_services.hpp"
#include "porsche/application_services_next.hpp"
#include "porsche/application_state.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/frame_services.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/startup_service_516950.hpp"
#include "porsche/window_runtime.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../464-audio-probe-startup/audio_probe_startup_464.hpp"
// 0065b318 and the 005d1a1c "Lil" literal are already owned by the accepted
// Run690 provider application_audio_probe_690.cpp; bind to those exact symbols
// rather than defining a second copy of the same storage.
#include "../690-audio-probe-start-and-period-control/application_audio_probe_690.hpp"

namespace porsche {

// Owned zero-initialized BSS record table 00656528..00656828 (32 records of
// 0x18 bytes). 004a8570 scans the same base with the same stride, 004a8660
// resets fields +04/+08/+14, and this batch's 004a88a0 releases fields
// +04/+08/+14. Untouched fields stay opaque; the 8-byte gap 00656520..00656528
// is not part of this table.
struct SimAudioRecord00656528 {
    std::uint32_t raw_00;
    std::int32_t channel_04;
    std::int32_t handle_08;
    std::uint32_t raw_0c;
    std::uint32_t opaque_10;
    std::uint32_t data_14;
};
static_assert(sizeof(SimAudioRecord00656528) == 0x18, "record stride 0x18");
extern SimAudioRecord00656528 application_audio_records_00656528[32];

// Reused from Run690: application_audio_path_prefix_0065b318 (loader-zero
// pointer cell outside the 006573e8 arena span) and
// application_audio_lil_text_005d1a1c. Consumers scan the pointed string to
// NUL; no extent is proved. Do not redefine either cell here.

// Newly owned read-only .data literal. Raw initial bytes are pinned against
// the PE in the native proof before any relocation.
extern const char application_audio_bank_suffix_005d1a20[12];
extern const char sim_deinit_done_log_005d6e60[6];
extern const char sim_deinit_log_005d6e68[13];

// Unbounded original BSS tables. 005e8b34 holds per-player object pointers and
// 005e75a0 receives 0x96-DWORD blocks at stride 0x258; other consumers index
// them with their own runtime counts (005e8b58, 00690ad8), so no extent is
// proved here (same pattern as application_audio_source_storage_005e8bfc).
// The fixture owns bounded allocations; the production game graph keeps these
// as explicit unresolved storage dependencies.
extern std::uint32_t application_player_object_table_005e8b34[];
extern std::uint32_t application_player_setup_table_005e75a0[];

// Unrecovered effect boundaries. Declarations model only the observed callsite
// ABI of the three recovered bodies; their algorithms stay external. Returns
// that no recovered callsite observes are omitted.
void __cdecl application_sim_boundary_004afd30();
void __cdecl application_sim_boundary_004a8660();
void __cdecl application_sim_boundary_004b0a20();
std::int32_t __cdecl application_sim_boundary_004a8570(std::int32_t first,
                                                       std::int32_t second,
                                                       std::int32_t flag);
std::int32_t __cdecl application_sim_boundary_004b04d0(std::int32_t first,
                                                       std::int32_t second);
void __cdecl application_sim_boundary_004af5c0();
void __cdecl application_sim_boundary_004ae470(std::int32_t first,
                                               std::uint32_t* second);
void __cdecl application_sim_boundary_004acc10(std::int32_t first,
                                               std::uint32_t buffer_va);
void __cdecl application_sim_boundary_004ad4d0();
void __cdecl application_sim_boundary_004a6c90(const char* path,
                                               std::int32_t kind);
void __cdecl application_sim_boundary_004690f0();
void __cdecl application_sim_boundary_00413fd0();
void __cdecl application_sim_boundary_004a8a80();
void __cdecl application_sim_boundary_004afe50();
void __cdecl application_sim_boundary_004a4760();
void __cdecl application_sim_boundary_00414f80();
void __cdecl application_sim_boundary_00471c40();
void __cdecl application_sim_boundary_004642f0();
void __cdecl application_sim_boundary_00425330();
void __cdecl application_sim_boundary_00412cd0();
void __cdecl application_sim_boundary_00412e60();

} // namespace porsche
