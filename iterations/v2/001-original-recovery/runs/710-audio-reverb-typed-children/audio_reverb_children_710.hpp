// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Recovered full bodies of this batch. Declarations match the accepted Run705
// TU (audio_bank_period_705.hpp) byte for byte.
std::int32_t __cdecl audio_bank_open_tail_005900b0(const void* a,
    const void* b);
std::int32_t __cdecl audio_reverb_query_00598cd0(std::uint32_t kind_word,
    float value);
void __cdecl audio_reverb_finalize_00598a70();

// Newly owned loader-zero .data cells (raw PE .data beyond SizeOfRawData).
// 006b0a80..006b0e80: 1024-byte reverb mix buffer zeroed by finalize through
// the canonical backend configure provider.
extern std::uint8_t audio_reverb_mix_buffer_006b0a80[1024u];
// 006b1680: finalize writes 0x7d0 (2000) into this 4-byte counter.
extern std::uint32_t audio_reverb_finalize_counter_006b1680;

// Unowned callees: typed boundaries only, no original body claimed here.
std::uint32_t __cdecl audio_group_select_00590170(std::uint32_t header,
    std::int32_t item);
std::int32_t __cdecl audio_group_decode_00590a80(const void* source,
    const void* ctx, void* scratch);
void __cdecl application_audio_backend_configure_0058fef0(
    std::uint32_t buffer_va, std::uint32_t buffer_bytes);
std::int64_t __cdecl audio_stream_ftol_005a0f98();

} // namespace porsche
