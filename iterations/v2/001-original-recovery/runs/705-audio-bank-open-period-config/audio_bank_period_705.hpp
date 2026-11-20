// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Recovered bodies of this batch. Declarations match the accepted Run703 TU
// (audio_finalize_period_703.hpp) byte for byte.
std::int32_t __cdecl audio_bank_open_00565b60(std::uint32_t* out_index,
    const void* handle);
void __cdecl audio_period_configure_00598d10(std::uint32_t kind_word,
    std::uint32_t target_va);
void __cdecl audio_period_reset_00598e80();

// New loader-zero BSS owned by this batch (raw PE .data beyond SizeOfRawData).
// 006b08c0..006b08cc: three reverb count words.
extern std::uint32_t audio_reverb_count_words_006b08c0[3];
// 006b08e0..006b0a6c: eleven 36-byte reverb slot records. The pointer field at
// +0x0c is the address 006b08ec released by audio_period_reset_00598e80.
struct AudioReverbSlot705 {
    std::uint32_t raw_00;
    std::uint32_t raw_04;
    std::uint32_t count_08;
    std::uint32_t pointer_0c;
    float coeff_10;
    float neg_coeff_14;
    std::uint32_t zero_18;
    float f0_1c;
    float f1_20;
};
static_assert(sizeof(AudioReverbSlot705) == 36u, "36-byte reverb slot");
extern AudioReverbSlot705 audio_reverb_slots_006b08e0[11];

// Unowned callees: typed boundaries only, no original body claimed here.
std::int32_t __cdecl audio_bank_find_free_slot_00590140();
std::int32_t __cdecl audio_bank_open_tail_005900b0(const void* a,
    const void* b);
std::int32_t __cdecl audio_backend_pool_release_0058ac30(std::uint32_t address);
std::int32_t __cdecl audio_integer_read_0059bd90(const void* bytes,
    std::uint32_t count);
std::int32_t __cdecl audio_reverb_query_00598cd0(std::uint32_t kind_word,
    float value);
void __cdecl audio_reverb_finalize_00598a70();
std::uint32_t __cdecl application_audio_backend_allocate_0058aae0(
    std::uint32_t bytes);

} // namespace porsche
