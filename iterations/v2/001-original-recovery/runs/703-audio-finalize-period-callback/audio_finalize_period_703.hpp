// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/application_services.hpp"

namespace porsche {

// Recovered bodies of this batch. These declarations match the accepted Run697
// TU (audio_period_callback_probe_697.hpp) byte for byte; they close the two
// typed boundaries that Run697 declared as unowned.
std::int32_t __cdecl audio_bank_finalize_004a6bc0(const char* text,
    std::int32_t bank_result, const void* handle, std::uint32_t kind);
void __cdecl audio_period_callback_005901b0(std::int32_t flags,
    std::uint32_t period_value);

// New read-only literal owned by this batch. Raw original bytes at 005d141c
// are pinned in scope-evidence.json and compared before any pointer relocation.
// 005d1444/005d146c remain owned by Run697 (no overlap: literal ends at 005d1441).
extern const char audio_bank_add_fail_text_005d141c[38];

// New loader-zero BSS cells owned by this batch. No other accepted owner defines
// these VAs; raw PE has no file-backed bytes for either (zero-fill proven in
// scope-evidence.json). The stored constants are original code VAs, deliberately
// NOT relocated in production (same treatment as Run697's 0x005901b0 store).
extern std::uint32_t audio_period_handler_slots_006b16b0[3];
extern std::uint8_t audio_period_default_target_005e25b0[4];

// Canonical owners reused (never redefined here):
//   application_audio_records_006564a0 (application_services.hpp, 8 x 16B)
//   application_audio_device_state_006b48c0 (application_audio_device.hpp,
//     spans 006b48c0..006b4a4c; provides 006b4a10 [+0x150],
//     006b4a14 [+0x154] and the word at 006b48da [+0x1a]).
//   startup_service_noop_00516950      (startup_service_516950.hpp)
//   audio_backend_lock_005896d0 / audio_backend_unlock_005896f0 (audio_canonical_434.hpp)
//   audio_ds_apply_property_0058e780   (audio_directsound_initialize_462.hpp)
//   allocate_00531ca0 / free_00531f90  (fe_stream.hpp)
//   render_display_texture_report_005a177b (render_display.hpp)

// Unowned callees: typed boundaries only, no original body claimed here.
std::int32_t __cdecl audio_bank_open_00565b60(std::uint32_t* out_index,
    const void* handle);
std::int32_t __cdecl audio_bank_get_size_00565b30(std::int32_t bank_index);
std::int32_t __cdecl audio_bank_copy_00565ad0(void* dst_buffer,
    std::int32_t bank_index);
void __cdecl audio_backend_lock_005896d0();
void __cdecl audio_backend_unlock_005896f0();
std::int32_t __cdecl audio_ds_apply_property_0058e780(std::uint32_t a,
    std::uint32_t b, std::uint32_t c);
void __cdecl audio_period_configure_00598d10(std::uint32_t kind_word,
    std::uint32_t target_va);
void __cdecl audio_period_reset_00598e80();
void __cdecl startup_service_noop_00516950();
void* __cdecl allocate_00531ca0(const char* source, std::int32_t bytes,
    std::uint32_t heap_index);
std::uint32_t __cdecl free_00531f90(void* allocation);
void __cdecl render_display_texture_report_005a177b(const char* format,
    std::uint32_t detail);

} // namespace porsche
