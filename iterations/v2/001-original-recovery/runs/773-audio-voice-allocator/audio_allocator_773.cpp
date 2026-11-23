// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005898b0..005898e0, 49 bytes, sha256 66173fda19494edcca424054de25ca4a4f66de80a29bc8c024b97be685da3556.
// Original 005898f0..00589bf2, 771 bytes, sha256 339fbcaa839f7fa4cf676eb1305faea97b9bb646ded691960f0d9cbe790670fc.
#include "audio_allocator_773.hpp"

#include <cstring>

namespace porsche {

std::int16_t audio_voice_selection_006b48a8[4]{};
std::uint32_t audio_voice_generation_006ad74c = 0u;

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline std::int16_t read_i16(U addr) noexcept {
    std::int16_t value = 0;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_i16(U addr, std::int16_t value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline B read_u8(U addr) noexcept {
    B value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u8(U addr, B value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline U read_device_stamp() noexcept {
    U stamp = 0u;
    std::memcpy(&stamp, &application_audio_device_state_006b48c0[0xe8u], sizeof stamp);
    return stamp;
}

} // namespace

std::int32_t __cdecl audio_voice_selection_contains_005898b0(
    std::int32_t candidate,
    std::int32_t count) {
    if (count <= 0) {
        return 0;
    }
    for (I i = 0; i < count; ++i) {
        if (static_cast<I>(audio_voice_selection_006b48a8[i]) == candidate) {
            return 1;
        }
    }
    return 0;
}

std::int32_t __cdecl audio_backend_allocate_voice_005898f0(
    std::int32_t channel_count,
    std::uint32_t priority,
    std::uint32_t* handle,
    std::uint32_t first,
    std::uint32_t last) {
    I selected_count = 0;
    if (channel_count > 0) {
        for (I i = 0; i < channel_count; ++i) {
            audio_voice_selection_006b48a8[i] = -1;
        }
    }

    const U next_gen = audio_voice_generation_006ad74c + 0x100u;
    audio_voice_generation_006ad74c = (static_cast<I>(next_gen) < 0) ? 0u : next_gen;

    const I first_i = static_cast<I>(first);
    const I last_i = static_cast<I>(last);

    if (channel_count > 0) {
        for (I pass = 0; pass < channel_count; ++pass) {
            U best_weight = 0xffffffffu;
            I best_slot = -1;
            const U table_va = audio_backend_channels_006b4a00;
            for (I slot = first_i; slot < last_i; ++slot) {
                const U rec_va = table_va + static_cast<U>(slot) * 0x70u;
                if (read_u8(rec_va + 0x0fu) == 0u &&
                    audio_voice_selection_contains_005898b0(slot, selected_count) == 0) {
                    const U weight = read_u32(rec_va + 0x20u);
                    if (weight < best_weight) {
                        best_weight = weight;
                        best_slot = slot;
                    }
                }
            }
            if (best_slot >= 0) {
                audio_voice_selection_006b48a8[selected_count++] =
                    static_cast<std::int16_t>(static_cast<std::int8_t>(best_slot));
            }
        }
    }

    if (selected_count < channel_count) {
        for (I pass = selected_count; pass < channel_count; ++pass) {
            I best_slot = -1;
            U best_weight = 0xffffffffu;
            U best_prio = 0x66u;
            const U table_va = audio_backend_channels_006b4a00;
            for (I slot = first_i; slot < last_i; ++slot) {
                if (audio_voice_selection_contains_005898b0(slot, selected_count) == 0) {
                    const U rec_va = table_va + static_cast<U>(slot) * 0x70u;
                    const U rec_prio = read_u8(rec_va + 0x1au);
                    if (rec_prio < 0x65u) {
                        const U weight = read_u32(rec_va + 0x20u);
                        if (rec_prio < best_prio ||
                            (rec_prio == best_prio && weight < best_weight)) {
                            best_weight = weight;
                            best_prio = rec_prio;
                            best_slot = slot;
                        }
                    }
                }
            }
            if (best_slot >= 0) {
                audio_voice_selection_006b48a8[selected_count++] =
                    static_cast<std::int16_t>(static_cast<std::int8_t>(best_slot));
                if (selected_count >= channel_count) {
                    break;
                }
            }
        }
    }

    if (selected_count != channel_count) {
        return -9;
    }

    I head_slot = static_cast<I>(audio_voice_selection_006b48a8[0]);
    *handle = static_cast<U>(head_slot) | audio_voice_generation_006ad74c;

    if (selected_count > 0) {
        for (I i = 0; i < selected_count; ++i) {
            const U table_va = audio_backend_channels_006b4a00;
            const I slot = static_cast<I>(audio_voice_selection_006b48a8[i]);
            const U rec_va = table_va + static_cast<U>(slot) * 0x70u;
            if (read_u8(rec_va + 0x0fu) == 1u) {
                I stop_handle = static_cast<I>(read_u32(rec_va + 0x00u));
                if (stop_handle < 0) {
                    const I parent_slot = static_cast<I>(read_i16(rec_va + 0x1cu));
                    stop_handle = static_cast<I>(
                        read_u32(table_va + static_cast<U>(parent_slot) * 0x70u));
                }
                (void)audio_channel_stop_00565d60(static_cast<U>(stop_handle));
                head_slot = static_cast<I>(audio_voice_selection_006b48a8[0]);
            }
            write_u8(rec_va + 0x0fu, 1u);
            write_u8(rec_va + 0x1au, static_cast<B>(priority));
            write_u32(rec_va + 0x20u, read_device_stamp());
        }
    }

    const U table_va = audio_backend_channels_006b4a00;
    const U head_va = table_va + static_cast<U>(head_slot) * 0x70u;
    write_u32(head_va + 0x00u, *handle);
    write_i16(head_va + 0x04u, static_cast<std::int16_t>(head_slot));
    write_i16(head_va + 0x1cu, -1);

    if (selected_count > 1) {
        for (I i = 1; i < selected_count; ++i) {
            const std::int16_t child_slot = audio_voice_selection_006b48a8[i];
            write_i16(head_va + 0x04u + static_cast<U>(i) * 2u, child_slot);
            const U child_va = table_va + static_cast<U>(static_cast<I>(child_slot)) * 0x70u;
            write_u32(child_va + 0x00u, 0xffffffffu);
            write_i16(child_va + 0x1cu, static_cast<std::int16_t>(head_slot));
        }
    }

    return head_slot;
}

} // namespace porsche
