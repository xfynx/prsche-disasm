// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005615c0..0056167f, 192 bytes, sha256 5b2dfeb4f0724b3b69f8804223e1433fc4ba95e5c5e71a2a8a0405a2f3e02ea5.
// Original 00566b40..00566d3b, 508 bytes, sha256 a7ee17baaa248714c2279073290bfb72c59b9f29c75bff12fc751c4153d5636e.
// Original 00567060..00567131, 210 bytes, sha256 eef0cbe5d9cad364ddee312ee1dfbfa1e42c4df10ad51bac111b6ca5be862ad0.
#include "audio_stream_scdl_chunk_740.hpp"

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

inline I div_28_signed(I value) noexcept {
    return value / 28;
}

} // namespace

std::int32_t __cdecl audio_stream_slot_push_chunk_005615c0(
    std::uint32_t index,
    const void* items) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }

    const U record_va = audio_stream_slots_006b7cc0[index];
    audio_backend_lock_005896d0();

    const I capacity = static_cast<std::int16_t>(read_u16(record_va + 0x18u));
    const I used = static_cast<std::int16_t>(read_u16(record_va + 0x10u));
    if (used >= capacity - 1) {
        audio_backend_unlock_005896f0();
        return -13;
    }

    const I write_idx = static_cast<std::int16_t>(read_u16(record_va + 0x1eu));
    const U entry_va = record_va + static_cast<U>((write_idx + 3) * 24);
    const U items_va = va_from_ptr(items);
    const U chunk_bytes = read_u32(items_va + 0x04u);
    write_u32(entry_va + 0x04u, chunk_bytes);
    write_u32(entry_va + 0x00u, read_u32(record_va + 0x04u));

    const I sub_count = static_cast<I>(read_u8(record_va + 0x36u));
    for (I p = 0; p < sub_count; ++p) {
        write_u32(entry_va + 0x08u + static_cast<U>(p) * 4u,
                  read_u32(items_va + 0x0cu + static_cast<U>(p) * 4u));
        const U used_off = record_va + 0x10u + static_cast<U>(p) * 2u;
        write_u16(used_off, static_cast<std::uint16_t>(read_u16(used_off) + 1u));
    }

    write_u32(record_va + 0x20u, read_u32(record_va + 0x20u) + chunk_bytes);
    const U ret_id = read_u32(record_va + 0x04u);
    write_u32(record_va + 0x04u, ret_id + 1u);

    const std::int16_t next_write =
        static_cast<std::int16_t>(read_u16(record_va + 0x1eu) + 1u);
    write_u16(record_va + 0x1eu,
              (next_write < capacity) ? static_cast<std::uint16_t>(next_write) : 0u);

    audio_backend_unlock_005896f0();
    return static_cast<I>(ret_id);
}

std::uint32_t __cdecl audio_stream_deinterleave_chunk_00566b40(
    void* data,
    std::uint32_t chunk_len,
    std::uint32_t channels,
    std::uint32_t codec_mode) {
    const U data_va = va_from_ptr(data);
    U copy_bytes = chunk_len;
    I span_words = 0;

    if (codec_mode == 3u) {
        const I blocks = div_28_signed(static_cast<I>(chunk_len) + 0x1b);
        span_words = blocks * 28;
        const I per_chan_bytes = div_28_signed(span_words * 15) + 4;
        copy_bytes = static_cast<U>(per_chan_bytes);
        if (channels == 1u) {
            const I mono_payload = per_chan_bytes - 4;
            for (I i = 0; i < mono_payload; ++i) {
                write_u8(data_va + 4u + static_cast<U>(i),
                         read_u8(data_va + 8u + static_cast<U>(i)));
            }
            return 0u;
        }
    } else if (codec_mode == 2u) {
        if (channels == 1u) {
            return 0u;
        }
        span_words = static_cast<I>(chunk_len);
    } else if (codec_mode == 0u) {
        if (channels == 1u) {
            return 0u;
        }
        span_words = static_cast<I>(chunk_len);
        copy_bytes = chunk_len + chunk_len;
    } else {
        return 0u;
    }

    void* const scratch = platform_virtual_alloc(nullptr, copy_bytes, 0x3000u, 4u);
    const U scratch_va = va_from_ptr(scratch);

    if (codec_mode == 3u) {
        const I nibble_count = div_28_signed(span_words * 30);
        write_u32(scratch_va, read_u32(data_va + 4u));
        for (I i = 0; i < nibble_count; ++i) {
            const B src = read_u8(data_va + 8u + static_cast<U>(i));
            const U dst_addr = scratch_va + 4u + static_cast<U>(i >> 1);
            if ((i & 1) != 0) {
                write_u8(dst_addr, static_cast<B>(read_u8(dst_addr) | (src & 0x0fu)));
            } else {
                write_u8(dst_addr, static_cast<B>(src << 4u));
            }
        }
        for (I i = 0; i < nibble_count; ++i) {
            const B src = read_u8(data_va + 8u + static_cast<U>(i));
            const U dst_addr = data_va + 4u + static_cast<U>(i >> 1);
            if ((i & 1) != 0) {
                write_u8(dst_addr, static_cast<B>(read_u8(dst_addr) | (src >> 4u)));
            } else {
                write_u8(dst_addr, static_cast<B>(src & 0xf0u));
            }
        }
    } else if (codec_mode == 2u) {
        for (I i = 0; i < span_words; ++i) {
            write_u8(scratch_va + static_cast<U>(i),
                     read_u8(data_va + 1u + static_cast<U>(i) * 2u));
        }
        for (I i = 0; i < span_words; ++i) {
            write_u8(data_va + static_cast<U>(i),
                     read_u8(data_va + static_cast<U>(i) * 2u));
        }
    } else if (codec_mode == 0u) {
        for (I i = 0; i < span_words; ++i) {
            write_u16(scratch_va + static_cast<U>(i) * 2u,
                      read_u16(data_va + 2u + static_cast<U>(i) * 4u));
        }
        for (I i = 0; i < span_words; ++i) {
            write_u16(data_va + static_cast<U>(i) * 2u,
                      read_u16(data_va + static_cast<U>(i) * 4u));
        }
    }

    if (copy_bytes != 0u) {
        std::memcpy(ptr_from_va(data_va + copy_bytes), scratch, copy_bytes);
    }
    (void)platform_virtual_free(scratch, 0u, 0x8000u);
    return copy_bytes;
}

std::int32_t __cdecl audio_stream_service_chunk_scdl_00567060(
    void* stream,
    void* chunk) {
    const U stream_va = va_from_ptr(stream);
    const U chunk_va = va_from_ptr(chunk);
    const U chunk_len = read_u32(chunk_va + 0x08u);

    U items[7] = {};
    items[1] = chunk_len;

    if (read_u8(stream_va + 0x3bu) == 0u) {
        const U channels = read_u8(stream_va + 0x2eu);
        const U codec_mode = read_u8(stream_va + 0x2fu);
        const U stride = audio_stream_deinterleave_chunk_00566b40(
            ptr_from_va(chunk_va + 0x0cu), chunk_len, channels, codec_mode);
        U cursor = chunk_va + 0x0cu;
        for (U i = 0u; i < channels; ++i) {
            items[3u + i] = cursor;
            cursor += stride;
        }
    } else {
        const U channels = read_u8(stream_va + 0x2eu);
        const U base = chunk_va + 0x0cu + channels * 4u;
        for (U i = 0u; i < channels; ++i) {
            items[3u + i] = read_u32(chunk_va + 0x0cu + i * 4u) + base;
        }
    }

    const I entry_idx = static_cast<std::int8_t>(read_u8(stream_va + 0x17u));
    const U entry_va = read_u32(stream_va + 0x00u) +
        static_cast<U>(entry_idx * 0x2c);

    write_u32(items[3] - 4u, chunk_va);
    write_u32(chunk_va + 0x00u, read_u32(entry_va + 0x04u));
    write_u32(entry_va + 0x1cu, read_u32(entry_va + 0x1cu) + chunk_len);
    write_u32(entry_va + 0x20u, read_u32(entry_va + 0x20u) + 1u);

    const I push_res = audio_stream_slot_push_chunk_005615c0(
        read_u32(stream_va + 0x0cu), items);
    write_u32(entry_va + 0x0cu, static_cast<U>(push_res));
    if (static_cast<I>(read_u32(entry_va + 0x08u)) < 0) {
        write_u32(entry_va + 0x08u, read_u32(entry_va + 0x0cu));
    }
    return 1;
}

} // namespace porsche
