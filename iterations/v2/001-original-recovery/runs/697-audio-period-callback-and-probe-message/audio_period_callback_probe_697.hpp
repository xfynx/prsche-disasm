// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"

namespace porsche {

// Recovered bodies of this batch. These declarations match the accepted
// Run690 TU (application_audio_probe_690.hpp) byte for byte so the previously
// unresolved typed boundaries are now defined by this translation unit.
std::int32_t __cdecl audio_period_callback_set_00590250(std::uint32_t flags);
void __cdecl application_audio_probe_message_004a6c90(const char* text,
    std::uint32_t kind);

// New read-only cells consumed by 004a6c90. Raw original bytes are pinned in
// scope-evidence.json and compared before any pointer relocation in the native
// fixture.
extern const char audio_bank_load_fail_text_005d1444[40];
extern const char audio_bank_suffix_text_005d146c[5];

// Canonical owners reused (never redefined here):
//   application_audio_device_state_006b48c0 (device state, Porsche.exe)
//   audio_ds_notify_kind_006b4886            (audio_directsound_state_462)
//   audio_device_callback_006b4898           (audio_device_lifecycle_455)
//   audio_system_active_006b499c             (frame_loop_clusters_400)
//   audio_ds_notify_value_006b4a08           (audio_directsound_state_462)
extern std::int8_t audio_ds_notify_kind_006b4886;
extern std::uint32_t audio_device_callback_006b4898;
extern std::uint8_t audio_system_active_006b499c;
extern std::uint32_t& audio_ds_notify_value_006b4a08;

// Accepted canonical providers reused as typed boundaries.
void* __cdecl resource_open_quiet_0059d9b0(const char* name, std::uint32_t flags);
std::int32_t __cdecl resource_predicate_0059dd00(const char* path);
void __cdecl render_display_texture_report_005a177b(const char* format,
    std::uint32_t detail);

// Unowned callees: typed boundaries, no original body is claimed here.
// 005901b0(flags, period_value) is the period callback; 004a6bc0 is the bank
// registration tail with the original four-argument stack area.
void __cdecl audio_period_callback_005901b0(std::int32_t flags,
    std::uint32_t period_value);
std::int32_t __cdecl audio_bank_finalize_004a6bc0(const char* text,
    std::int32_t bank_result, const void* handle, std::uint32_t kind);

} // namespace porsche
