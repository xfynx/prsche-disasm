// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00566ea0..00567011, 370 bytes, sha256 dd84e42c82e79485f8c9a0c364c6a00c979a958e7194842ac7ba1204bedf98e8.
#include "audio_stream_schl_parent_748.hpp"

#include <cstring>

namespace porsche {

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

inline B read_u8(U addr) noexcept {
    B value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u8(U addr, B value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline void* ptr_from_va(U addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

} // namespace

std::int32_t __cdecl audio_stream_service_chunk_schl_00566ea0(
    std::uint32_t slot_index,
    void* chunk) {
    using Notify = void(__cdecl*)(const void*);

    const U stream_va = audio_stream_service_storage_006b7740.slots[slot_index];
    const I entry_index = static_cast<std::int8_t>(read_u8(stream_va + 0x17u));
    const U entry_va = read_u32(stream_va + 0x00u) + static_cast<U>(entry_index * 0x2c);
    const U chunk_va = va_from_ptr(chunk);

    U parsed_flags = slot_index;
    (void)audio_stream_header_parse_00590f70(
        ptr_from_va(chunk_va + 0x08u),
        ptr_from_va(stream_va + 0x30u),
        ptr_from_va(stream_va + 0x88u),
        &parsed_flags);
    write_u32(entry_va + 0x18u, parsed_flags);

    U list_va = stream_va + 0xbcu;
    while (read_u32(list_va) != 0u) {
        U notification[5];
        notification[0] = 3u;
        notification[1] = read_u32(list_va);
        notification[2] = read_u32(list_va + 0x10u);
        // Original stack dword notification[3] is opaque and unwritten.
        notification[4] = read_u32(entry_va + 0x04u);
        list_va += 4u;
        I callback_index = 0;
        while (callback_index < static_cast<std::int8_t>(
                   application_audio_device_state_006b48c0[0xe2u])) {
            U callback_va = 0u;
            std::memcpy(
                &callback_va,
                &application_audio_device_state_006b48c0[
                    0x120u + static_cast<U>(callback_index) * 4u],
                sizeof callback_va);
            const Notify callback = reinterpret_cast<Notify>(static_cast<std::uintptr_t>(callback_va));
            callback(notification);
            ++callback_index;
        }
    }

    audio_stream_codec_release_chunk_0056c620(read_u32(stream_va + 0x04u), chunk);
    write_u32(
        entry_va + 0x10u,
        static_cast<U>(audio_stream_header_byte_rate_00590ef0(ptr_from_va(stream_va + 0x30u))));

    bool header_matches = read_u32(stream_va + 0x2cu) == read_u32(stream_va + 0x30u);
    if (header_matches) {
        for (U i = 0u; i < 0x15u; ++i) {
            if (read_u32(stream_va + 0x34u + i * 4u) !=
                read_u32(stream_va + 0x88u + i * 4u)) {
                header_matches = false;
                break;
            }
        }
        if (header_matches && read_u32(stream_va + 0x9cu) != 0u) {
            header_matches = false;
        }
    }

    if (!header_matches) {
        if (read_u16(stream_va + 0x2cu) != 0u) {
            write_u8(stream_va + 0x14u, 2u);
            return 0;
        }
        write_u32(stream_va + 0x2cu, read_u32(stream_va + 0x30u));
        for (U i = 0u; i < 0x15u; ++i) {
            write_u32(stream_va + 0x34u + i * 4u, read_u32(stream_va + 0x88u + i * 4u));
        }
        write_u32(stream_va + 0x9cu, 0u);
    }

    if (read_u8(stream_va + 0x14u) != 1u) {
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
    return 0;
}

} // namespace porsche
