// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/application_state.hpp"
#include "porsche/frame_services.hpp"

namespace porsche {

// New data cells of this batch. 0065b318 is a zero-initialized BSS pointer
// read by 004a8660/004a8b80/004a8cd0/004acc10/004affd0; its writer is not in
// the disassembly index, so the cell starts at the original loader value.
extern char* application_audio_path_prefix_0065b318;
// Raw .data literal cells consumed by 004a8b80 and 004a8660/004acc10.
extern const char application_audio_replay_text_005cce90[7];
extern const char application_audio_spl_text_005d1a04[5];
extern const char application_audio_fesfx_text_005d1a14[6];
extern const char application_audio_lil_text_005d1a1c[4];

// Recovered bodies of this batch. The five-argument signature matches the
// accepted callers (application_audio_lifecycle.hpp / application_audio_init);
// 004a8b80 is the no-argument boundary declared by application_services.hpp.
void __cdecl application_audio_period_control_00565c70(std::uint32_t flags,
    std::uint32_t value, std::uint32_t third, std::uint32_t fourth,
    std::uint32_t fifth);
void __cdecl application_audio_probe_start_004a8b80();

// Accepted canonical provider (Run658, runs/658-resource-loadat-and-reset).
std::uint32_t __cdecl resource_loadat_quiet_0059db50(const char* name,
    void* buffer, std::uint32_t max_bytes);

// Unowned typed boundaries, signatures from the observed call sites. The
// caller ignores the callee's EAX, so no scalar return is claimed; internals
// remain external until their own recovery batches.
std::int32_t __cdecl audio_period_callback_set_00590250(std::uint32_t flags);
void __cdecl application_audio_probe_message_004a6c90(const char* text,
    std::uint32_t kind);

} // namespace porsche
