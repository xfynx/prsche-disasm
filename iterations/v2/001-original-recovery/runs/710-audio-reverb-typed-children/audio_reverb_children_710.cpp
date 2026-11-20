// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005900b0..00590134 (133 bytes), 00598a70..00598a8c (29 bytes),
// 00598cd0..00598d01 (50 bytes). Body SHA-256 values are pinned in
// native-config.json / scope-evidence.json.
#include "audio_reverb_children_710.hpp"

#include <cstring>

namespace porsche {

std::uint8_t audio_reverb_mix_buffer_006b0a80[1024u]{};
std::uint32_t audio_reverb_finalize_counter_006b1680 = 0u;

namespace {

inline void write_u32(void* p, std::uint32_t v) noexcept {
    std::memcpy(p, &v, 4u);
}

inline std::uint16_t read_u16(const void* p) noexcept {
    std::uint16_t v = 0u;
    std::memcpy(&v, p, 2u);
    return v;
}

inline std::uint32_t unsigned_count(const void* header) noexcept {
    return static_cast<std::uint32_t>(
        read_u16(static_cast<const std::uint8_t*>(header) + 6u));
}

} // namespace

// Original 005900b0..00590134 (133 bytes). The 2048-byte stack scratch has
// every first dword of each 8-byte group set to -1; the other dword stays
// opaque. EBP starts at the original default return 7. The word at a+6 is the
// unsigned (zero-extended word) item count, re-read every iteration and
// compared against the increasing index; the JL comparison is signed but both
// operands stay in [0, 65535].
// For each item, 00590170 selects a source pointer; a non-null source is
// decoded by 00590a80 and any return other than 7 changes the result to 8.
std::int32_t __cdecl audio_bank_open_tail_005900b0(const void* a,
                                                   const void* b) {
    alignas(8) std::uint8_t scratch[0x800u];
    for (std::uint32_t i = 0u; i < 0x100u; ++i) {
        write_u32(scratch + i * 8u, 0xffffffffu);
    }

    if (read_u16(static_cast<const std::uint8_t*>(a) + 6u) == 0u) {
        return 7;
    }

    std::int32_t result = 7;
    std::uint32_t item = 0u;
    for (;;) {
        const std::uint32_t selected = audio_group_select_00590170(
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(a)),
            static_cast<std::int32_t>(item));
        if (selected != 0u) {
            const void* source = reinterpret_cast<const void*>(
                static_cast<std::uintptr_t>(selected));
            if (audio_group_decode_00590a80(source, b, scratch) != 7) {
                result = 8;
            }
        }
        ++item;
        if (item >= unsigned_count(a)) {
            break;
        }
    }
    return result;
}

// Original 00598a70..00598a8c (29 bytes). Writes the original counter value
// 0x7d0 (2000) at 006b1680, then zeroes 1024 bytes of the owned 006b0a80 mix
// buffer through the already accepted 0058fef0 backend configure provider.
void __cdecl audio_reverb_finalize_00598a70() {
    audio_reverb_finalize_counter_006b1680 = 0x7d0u;
    application_audio_backend_configure_0058fef0(
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
            audio_reverb_mix_buffer_006b0a80)),
        0x400u);
}

// Original 00598cd0..00598d01 (50 bytes). The first stack argument is loaded
// as a signed dword, multiplied by the second (float) argument with the 80-bit
// x87 product left in ST0, then consumed once by the canonical __ftol at
// 005a0f98. ESI takes the low 32 bits of the signed 64-bit result. The original
// loop returns the smallest prime >= max(ESI, 2): for each candidate it tries
// divisors 2..candidate in order; on a divisor hit it returns the divisor only
// if it equals the candidate (prime), otherwise it increments the candidate
// and restarts at divisor 2.
std::int32_t __cdecl audio_reverb_query_00598cd0(std::uint32_t kind_word,
                                                 float value) {
    volatile std::int32_t kind_i = static_cast<std::int32_t>(kind_word);
    volatile float factor = value;
    volatile std::int32_t truncated = 0;
    using FtolFn = std::int64_t (__cdecl*)();
    volatile FtolFn ftol = &audio_stream_ftol_005a0f98;
    __asm {
        fild dword ptr [kind_i]
        fmul dword ptr [factor]
        mov eax, ftol
        call eax
        mov truncated, eax
    }

    std::int32_t candidate = truncated;
    for (;;) {
        std::int32_t divisor = 2;
        if (candidate > 1) {
            do {
                if (candidate % divisor == 0) {
                    break;
                }
                ++divisor;
            } while (divisor <= candidate);
        }
        if (divisor == candidate) {
            return candidate;
        }
        ++candidate;
    }
}

} // namespace porsche
