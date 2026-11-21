// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00561680..005616a5, 38 bytes, sha256 4b8b571133e065eb76963e1341325019b5d73d9f1e4088381bdf8a03ad1de4f0.
// Original 005616d0..005616fc, 45 bytes, sha256 7ad3d5af74bac04a37861b76558ce209e9d62cdc28651f8b47b17aab6e3924e3.
// Original 00567020..00567051, 50 bytes, sha256 47ee270c8d97b066ec69391de20fe75500310b721db47d8463082d76b0194b8c.
// Original 00567140..00567164, 37 bytes, sha256 54b5378a9be71b54c51188457b2f8872cbe058dc6505836cb59adc01975c3d1a.
// Original 00567170..005671ec, 125 bytes, sha256 ec31560b7e4d972d701e95f782e3e74902aff0d536c0730dbd28fd7e56cce3f6.
// Original 005671f0..00567266, 119 bytes, sha256 575245218e5926006c92fd8b789707de5dc69aed88b9ff797c988cb7b2d14ef6.
// Original 00567270..005673a9, 314 bytes, sha256 e02f09058f2fd98b639d180426cb3f7aafa992c4cc31695c53f467eb1b327476.
// Original 0056c740..0056c78a, 75 bytes, sha256 0b96ae47dbc2360f5b73083e334281c59ab1b8e54c6f5dd5825148941d53c55e.
// Original 0056c790..0056c7da, 75 bytes, sha256 60b1ff77ed98986b83c57ab5be03d5ee3c3ba7980b9ba65008e0e89f1658c088.
// Original 00590e70..00590ee0, 113 bytes, sha256 c9c31879e43030805dc72fea280e06121812a55a4ea4c0487f822f6f599f329b.
// Original 00599710..00599712, 3 bytes, sha256 4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e.
#include "audio_stream_service_tick_733.hpp"

#include <cstring>

namespace porsche {

const char stream_err_gettable_invalid_handle_005bde44[41] =
    "STREAM_gettable - invalid stream handle\n";
const char stream_err_state_invalid_handle_005bde70[38] =
    "STREAM_state - invalid stream handle\n";

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

inline std::uint16_t read_u16(U addr) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u16(U addr, std::uint16_t value) noexcept {
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

inline void* ptr_from_va(U addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

} // namespace

std::int32_t __cdecl audio_stream_slot_free_chunks_00561680(std::uint32_t index) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const U record_va = audio_stream_slots_006b7cc0[index];
    const I capacity = static_cast<std::int16_t>(read_u16(record_va + 0x18u));
    const I used = static_cast<std::int16_t>(read_u16(record_va + 0x10u));
    return capacity - used - 1;
}

std::int32_t __cdecl audio_stream_slot_locked_total_005616d0(std::uint32_t index) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    audio_backend_lock_005896d0();
    const U total = audio_stream_slot_total_005616b0(index);
    audio_backend_unlock_005896f0();
    return static_cast<I>(total);
}

std::uint32_t __cdecl audio_voice_noop_00599710(
    std::uint32_t voice_slot,
    const void* params) {
    (void)voice_slot;
    (void)params;
    return 0u;
}

std::int32_t __cdecl audio_backend_channel_apply_00590e70(
    std::uint32_t handle,
    const void* params) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    audio_backend_lock_005896d0();
    const I channel = audio_backend_find_channel_00589d20(handle);
    if (channel >= 0) {
        U voice_slot = 0xffffffffu;
        while (audio_backend_next_voice_00590340(channel, &voice_slot) != 0u) {
            (void)audio_voice_noop_00599710(voice_slot, params);
        }
    }
    audio_backend_unlock_005896f0();
    return channel;
}

std::uint32_t __cdecl audio_stream_codec_avail_0056c740(std::uint32_t codec_handle) {
    U codec_va = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &codec_va, &codec_handle) != 0u) {
        diagnostic_file_005deb74_set(stream_source_file_005bd978);
        diagnostic_line_005deb78 = 0x88eu;
        diagnostic_handler_005debf0(stream_err_gettable_invalid_handle_005bde44);
        return 0u;
    }
    return read_u32(codec_handle + 0x08u);
}

std::uint32_t __cdecl audio_stream_codec_state_0056c790(std::uint32_t codec_handle) {
    U scratch = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &codec_handle, &scratch) != 0u) {
        diagnostic_file_005deb74_set(stream_source_file_005bd978);
        diagnostic_line_005deb78 = 0x8c2u;
        diagnostic_handler_005debf0(stream_err_state_invalid_handle_005bde70);
        return 0u;
    }
    return read_u32(codec_handle + 0x28u);
}

std::int32_t __cdecl audio_stream_service_check_refill_005671f0(void* stream) {
    const U stream_va = va_from_ptr(stream);
    const I entry_idx = static_cast<std::int8_t>(read_u8(stream_va + 0x17u));
    const U entry_va = read_u32(stream_va + 0x00u) +
        static_cast<U>(entry_idx * 0x2c);
    if (read_u32(entry_va + 0x10u) == 0u) {
        return 0;
    }
    const std::int16_t initial_wait = static_cast<std::int16_t>(read_u16(entry_va + 0x28u));
    if (initial_wait < 0) {
        return 1;
    }
    if (initial_wait == 0) {
        return 0;
    }

    const U codec_handle = read_u32(stream_va + 0x04u);
    U avail = audio_stream_codec_avail_0056c740(codec_handle);
    if (avail > 0x3d0900u) {
        avail = 0x3d0900u;
    }
    const U scaled = avail * 1000u;
    const U divisor = read_u32(entry_va + 0x10u);
    const U quotient = scaled / divisor;
    const U threshold = static_cast<U>(
        static_cast<I>(static_cast<std::int16_t>(read_u16(entry_va + 0x28u))));
    if (quotient < threshold) {
        if (audio_stream_codec_state_0056c790(codec_handle) != 2u) {
            return 1;
        }
    }
    write_u16(entry_va + 0x28u, 0u);
    return 0;
}

std::int32_t __cdecl audio_stream_service_chunk_sccl_00567020(void* stream, void* chunk) {
    const U stream_va = va_from_ptr(stream);
    const U chunk_va = va_from_ptr(chunk);
    audio_stream_codec_release_chunk_0056c620(read_u32(stream_va + 0x04u), chunk);
    const I entry_idx = static_cast<std::int8_t>(read_u8(stream_va + 0x17u));
    const U entry_va = read_u32(stream_va + 0x00u) +
        static_cast<U>(entry_idx * 0x2c);
    write_u32(entry_va + 0x24u, read_u32(chunk_va + 0x08u));
    return 1;
}

std::int32_t __cdecl audio_stream_service_chunk_scel_00567140(void* stream, void* chunk) {
    const U stream_va = va_from_ptr(stream);
    audio_stream_codec_release_chunk_0056c620(read_u32(stream_va + 0x04u), chunk);
    write_u8(stream_va + 0x17u, static_cast<B>(read_u8(stream_va + 0x17u) + 1u));
    return 1;
}

std::int32_t __cdecl audio_stream_service_handle_chunk_00567170(
    std::uint32_t slot_index,
    void* chunk) {
    const U chunk_va = va_from_ptr(chunk);
    const U tag = read_u32(chunk_va + 0x00u);
    const U stream_va = audio_stream_service_storage_006b7740.slots[slot_index];
    void* const stream = ptr_from_va(stream_va);
    if (tag == 0x6c444353u) {
        return audio_stream_service_chunk_scdl_00567060(stream, chunk);
    }
    if (tag == 0x6c484353u) {
        return audio_stream_service_chunk_schl_00566ea0(slot_index, chunk);
    }
    if (tag == 0x6c454353u) {
        return audio_stream_service_chunk_scel_00567140(stream, chunk);
    }
    if (tag == 0x6c434353u) {
        return audio_stream_service_chunk_sccl_00567020(stream, chunk);
    }
    audio_stream_codec_release_chunk_0056c620(read_u32(stream_va + 0x04u), chunk);
    return 1;
}

void __cdecl audio_stream_service_tick_00567270() {
    using GuardCallback = std::uint32_t(__cdecl*)();
    const U guard_va = read_u32(
        va_from_ptr(application_audio_device_state_006b48c0.data() + 0x74u));
    const GuardCallback guard_fn =
        reinterpret_cast<GuardCallback>(static_cast<std::uintptr_t>(guard_va));
    if (guard_fn() != 0u) {
        return;
    }

    audio_backend_lock_005896d0();
    for (U slot_index = 0u; slot_index < 16u; ++slot_index) {
        const U stream_va = audio_stream_service_storage_006b7740.slots[slot_index];
        if (stream_va == 0u) {
            continue;
        }
        if (read_u8(stream_va + 0x16u) == 0u) {
            continue;
        }
        if (read_u8(stream_va + 0x14u) == 2u) {
            if (audio_stream_slot_locked_total_005616d0(read_u32(stream_va + 0x0cu)) > 0) {
                continue;
            }
            write_u32(stream_va + 0x2cu, read_u32(stream_va + 0x30u));
            for (U i = 0u; i < 0x15u; ++i) {
                write_u32(stream_va + 0x34u + i * 4u,
                          read_u32(stream_va + 0x88u + i * 4u));
            }
            write_u32(stream_va + 0x9cu, 0u);
            network_lifecycle_device_cancel_00561730(read_u32(stream_va + 0x0cu));
            const I voice_handle = audio_stream_voice_start_005612a0(
                read_u32(stream_va + 0x0cu),
                ptr_from_va(stream_va + 0x2cu),
                ptr_from_va(stream_va + 0x34u),
                ptr_from_va(stream_va + 0xdcu));
            write_u32(stream_va + 0x08u, static_cast<U>(voice_handle));
            if (read_u8(stream_va + 0x19u) != 0u) {
                (void)audio_backend_channel_apply_00590e70(
                    read_u32(stream_va + 0x08u),
                    ptr_from_va(stream_va + 0x1cu));
            }
            write_u8(stream_va + 0x14u, 1u);
        }

        if (audio_stream_service_check_refill_005671f0(ptr_from_va(stream_va)) != 0) {
            continue;
        }

        I budget = 0xa;
        if (read_u8(stream_va + 0x14u) == 1u) {
            budget = audio_stream_slot_free_chunks_00561680(read_u32(stream_va + 0x0cu));
            if (budget == 0) {
                continue;
            }
        }

        const U codec_handle = read_u32(stream_va + 0x04u);
        I handled = 0;
        do {
            budget = static_cast<I>(static_cast<U>(budget) - 1u);
            const U chunk_va = audio_stream_get_0056c540(codec_handle);
            if (chunk_va != 0u) {
                handled = audio_stream_service_handle_chunk_00567170(
                    slot_index, ptr_from_va(chunk_va));
            }
            if (handled == 0) {
                break;
            }
        } while (budget > 0);
    }
    audio_backend_unlock_005896f0();
}

} // namespace porsche
