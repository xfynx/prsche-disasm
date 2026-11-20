// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00565b60..00565ba6 (71 bytes), 00598d10..00598e71 (354 bytes),
// 00598e80..00598ea7 (40 bytes). Body SHA-256 values are pinned in
// native-config.json / scope-evidence.json.
#include "audio_bank_period_705.hpp"

#include "porsche/application_audio_device.hpp"

#include <cstring>

namespace porsche {

std::uint32_t audio_reverb_count_words_006b08c0[3]{};
AudioReverbSlot705 audio_reverb_slots_006b08e0[11]{};

namespace {

inline std::uint32_t read_u32(const void* p) noexcept {
    std::uint32_t v = 0u;
    std::memcpy(&v, p, 4u);
    return v;
}

inline void write_u32(void* p, std::uint32_t v) noexcept {
    std::memcpy(p, &v, 4u);
}

inline std::uint32_t device_word(std::size_t offset) noexcept {
    return read_u32(application_audio_device_state_006b48c0.data() + offset);
}

inline void device_set_word(std::size_t offset, std::uint32_t v) noexcept {
    write_u32(application_audio_device_state_006b48c0.data() + offset, v);
}

inline float float_from_bits(std::uint32_t bits) noexcept {
    float f = 0.0f;
    std::memcpy(&f, &bits, 4u);
    return f;
}

} // namespace

// Original 00565b60..00565ba6 (71 bytes). When the audio system is inactive
// (device byte +0xdc) the original returns -10 without touching any state.
// Otherwise it allocates a bank index, stores the original callback VA at
// device +0x130, writes the index through the out parameter, fills the three
// words of the 12-byte bank-table entry selected by the index (no original
// bounds check; proof bounds the index to the owned slot range), and forwards
// both copies of the handle to the original two-argument open tail. The EAX
// return of that tail is the original return value.
std::int32_t __cdecl audio_bank_open_00565b60(std::uint32_t* out_index,
                                              const void* handle) {
    if (device_word(0xdcu) == 0u) {
        return -10;
    }
    const std::int32_t index = audio_bank_find_free_slot_00590140();
    device_set_word(0x130u, 0x5659f0u);
    *out_index = static_cast<std::uint32_t>(index);
    const std::uint32_t entry =
        device_word(0x144u) + static_cast<std::uint32_t>(index) * 12u;
    const std::uint32_t handle_va = reinterpret_cast<std::uint32_t>(handle);
    write_u32(reinterpret_cast<void*>(entry), handle_va);
    write_u32(reinterpret_cast<void*>(entry + 4u), handle_va);
    *reinterpret_cast<std::uint8_t*>(entry + 0xau) = 0u;
    return audio_bank_open_tail_005900b0(handle, handle);
}

// Original 00598e80..00598ea7 (40 bytes). Walks the eleven reverb slot pointer
// fields from 006b08ec in 36-byte steps; every non-null pointer is passed to the
// canonical backend release and the field is cleared. Null fields are left
// untouched (opaque slots stay opaque).
void __cdecl audio_period_reset_00598e80() {
    std::uint8_t* slot =
        reinterpret_cast<std::uint8_t*>(&audio_reverb_slots_006b08e0[0].pointer_0c);
    const std::uint8_t* const end =
        reinterpret_cast<const std::uint8_t*>(&audio_reverb_slots_006b08e0[11]) + 0xcu;
    for (; slot < end; slot += 0x24u) {
        const std::uint32_t value = read_u32(slot);
        if (value != 0u) {
            (void)audio_backend_pool_release_0058ac30(value);
            write_u32(slot, 0u);
        }
    }
}

// Original 00598d10..00598e71 (354 bytes). Rebuilds all reverb slots from a
// caller-owned record. The three count words at 006b08c0..006b08cc each receive
// a byte from the record; for every inner entry the original computes two
// coefficients with x87 (bit-exact constants pinned in scope-evidence.json),
// reads an integer from the record, queries the reverb backend and allocates a
// zeroed scratch buffer. EDI is a global slot index incremented once per inner
// iteration, so all outer groups share the same 11 slot records. The exact x87
// sequence is kept in inline asm so /Od and /O2 produce identical 32-bit float
// stores.
void __cdecl audio_period_configure_00598d10(std::uint32_t kind_word,
                                             std::uint32_t target_va) {
    (void)audio_period_reset_00598e80();

    const std::uint8_t* const record = reinterpret_cast<const std::uint8_t*>(target_va);
    const float k1 = float_from_bits(0x3c010204u);
    const float k2 = float_from_bits(0x3b3e3ee7u);
    const float k3 = float_from_bits(0x3a83126fu);
    const float one = 1.0f;

    std::uint32_t slot_index = 0u;
    std::uint32_t outer = 0u;
    for (; outer < 3u; ++outer) {
        const std::uint32_t count = record[4u + outer];
        audio_reverb_count_words_006b08c0[outer] = count;
        if (static_cast<std::int32_t>(count) <= 0) {
            continue;
        }
        for (std::uint32_t inner = 0u; inner < count; ++inner) {
            AudioReverbSlot705& slot = audio_reverb_slots_006b08e0[slot_index];
            const std::int32_t d1 = static_cast<std::int8_t>(
                record[slot_index * 4u + 0xau + 1u]);
            const std::int32_t d2 = static_cast<std::int8_t>(
                record[slot_index * 4u + 0xau]);
            const float scale = static_cast<float>(
                static_cast<std::uint32_t>(record[7u]) + 100u);

            volatile float f0 = 0.0f;
            volatile float f1 = 0.0f;
            volatile float coeff = 0.0f;
            volatile float neg_coeff = 0.0f;
            __asm {
                fild dword ptr [d1]
                fmul dword ptr [k1]
                fst dword ptr [f0]
                fld dword ptr [one]
                fsub st(0), st(1)
                fstp dword ptr [f1]
                fstp st(0)
                fld dword ptr [scale]
                fmul dword ptr [f0]
                fmul dword ptr [k2]
                fstp dword ptr [f0]
                fld dword ptr [scale]
                fmul dword ptr [f1]
                fmul dword ptr [k2]
                fstp dword ptr [f1]
                fild dword ptr [d2]
                fmul dword ptr [k1]
                fst dword ptr [coeff]
                fchs
                fstp dword ptr [neg_coeff]
            }
            slot.f0_1c = f0;
            slot.f1_20 = f1;
            slot.coeff_10 = coeff;
            slot.neg_coeff_14 = neg_coeff;

            const std::int32_t read_value = audio_integer_read_0059bd90(
                reinterpret_cast<const void*>(record + slot_index * 4u + 8u), 2u);
            volatile float query = 0.0f;
            __asm {
                fild dword ptr [read_value]
                fmul dword ptr [k3]
                fstp dword ptr [query]
            }
            const std::int32_t count_out =
                audio_reverb_query_00598cd0(kind_word, query);
            const std::uint32_t bytes = static_cast<std::uint32_t>(count_out) * 4u;
            const std::uint32_t allocation =
                application_audio_backend_allocate_0058aae0(bytes);
            slot.pointer_0c = allocation;
            slot.count_08 = static_cast<std::uint32_t>(count_out);
            slot.raw_04 = static_cast<std::uint32_t>(count_out);
            slot.raw_00 = 0u;
            slot.zero_18 = 0u;
            if (count_out > 0) {
                std::memset(reinterpret_cast<void*>(allocation), 0,
                            static_cast<std::size_t>(bytes));
            }
            ++slot_index;
        }
    }
    audio_reverb_finalize_00598a70();
}

} // namespace porsche
