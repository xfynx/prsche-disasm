// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056b790..0056b7f8, 105 bytes, sha256 34f012e052cf9303930d6d75fa23fa7a7ece0b13b24dcf3f9f729288f7d7bfa0.
// Original 0056b800..0056b85a, 91 bytes, sha256 4aadac1dcbfd0f90cbaea291eda7441848f0a09dc29a99da5bcfeb6889981b5e.
// Original 0056b690..0056b789, 250 bytes, sha256 3bf0f6a00ddb6c9fd46f1910c7ef9f5de003e3dc2c5e1bbc503a399c3f22e9eb.
// Original 0056c040..0056c131, 242 bytes, sha256 3be6197e4425e92db0b9bf9c6f13c12d7f15baff5d3281c556a3aca77054daef.
// Original 00567550..0056765a, 267 bytes, sha256 b9eeaa6a11b9823aee36d503f54fdf85d06b29c71c5f18d423f6f98b4a64e76c.
#include "audio_service_stream_start_662.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {

const char stream_err_queuefile_invalid_005bdbd0[42] =
    "STREAM_queuefile - invalid stream handle\n";
const char stream_err_queuemem_invalid_005bdd04[41] =
    "STREAM_queuemem - invalid stream handle\n";

std::uint32_t audio_stream_request_serial_006a5df0 = 0u;

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

inline void report_stream_error(U line, const char* msg) {
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    diagnostic_handler_005debf0(msg);
}

} // namespace

void* __cdecl audio_stream_codec_alloc_request_0056b790(void* codec) {
    const U codec_va = va_from_ptr(codec);
    void* const lock = ptr_from_va(read_u32(codec_va + 0x04u));
    heap_enter_005322b0(lock);

    const U req_va = read_u32(codec_va + 0x58u);
    if (req_va == 0u) {
        heap_leave_005322c0(lock);
        return nullptr;
    }

    write_u32(codec_va + 0x58u, read_u32(req_va + 0x0cu));
    audio_stream_request_serial_006a5df0 += 0x100u;
    if (audio_stream_request_serial_006a5df0 == 0u) {
        audio_stream_request_serial_006a5df0 = 0x100u;
    }
    const U id_word = (read_u32(req_va + 0x00u) & 0xffu) | audio_stream_request_serial_006a5df0;
    write_u32(req_va + 0x00u, id_word);

    heap_leave_005322c0(lock);
    return ptr_from_va(req_va);
}

void __cdecl audio_stream_codec_enqueue_request_0056b800(void* codec, void* req) {
    const U codec_va = va_from_ptr(codec);
    const U req_va = va_from_ptr(req);

    write_u32(req_va + 0x04u, 1u);
    write_u32(req_va + 0x0cu, 0u);

    void* const lock = ptr_from_va(read_u32(codec_va + 0x04u));
    heap_enter_005322b0(lock);

    const U tail_va = read_u32(codec_va + 0x54u);
    write_u32(req_va + 0x08u, tail_va);
    if (tail_va == 0u) {
        write_u32(codec_va + 0x4cu, req_va);
        write_u32(codec_va + 0x50u, req_va);
        write_u32(codec_va + 0x54u, req_va);
    } else {
        write_u32(tail_va + 0x0cu, req_va);
        write_u32(codec_va + 0x54u, req_va);
    }

    heap_leave_005322c0(lock);
}

std::uint32_t __cdecl audio_stream_codec_queue_file_0056b690(
    std::uint32_t codec_handle,
    const char* path,
    std::uint32_t offset,
    std::uint32_t tag) {
    U codec_va = 0u;
    U scratch = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &codec_va, &scratch) != 0u) {
        report_stream_error(0x617u, stream_err_queuefile_invalid_005bdbd0);
        return 0u;
    }

    void* const req = audio_stream_codec_alloc_request_0056b790(ptr_from_va(codec_va));
    if (req == nullptr) {
        return 0u;
    }

    const U req_va = va_from_ptr(req);
    write_u32(req_va + 0x10u, 0u);

    char* const dst = reinterpret_cast<char*>(ptr_from_va(req_va + 0x14u));
    std::size_t i = 0u;
    for (; i < 0x103u && path[i] != '\0'; ++i) {
        dst[i] = path[i];
    }
    for (; i < 0x103u; ++i) {
        dst[i] = '\0';
    }

    write_u32(req_va + 0x11cu, offset);
    write_u32(req_va + 0x120u, tag);

    audio_stream_codec_enqueue_request_0056b800(ptr_from_va(codec_va), req);

    heap_enter_005322b0(ptr_from_va(read_u32(codec_va + 0x04u)));
    const U prev_state28 = read_u32(codec_va + 0x28u);
    if (prev_state28 == 0u) {
        write_u32(codec_va + 0x28u, 1u);
    }
    heap_leave_005322c0(ptr_from_va(read_u32(codec_va + 0x04u)));

    if (prev_state28 == 0u) {
        const U advance_offset = (read_u32(codec_va + 0x38u) != 0u)
            ? read_u32(codec_va + 0x30u)
            : read_u32(codec_va + 0x2cu);
        audio_stream_codec_advance_0056b860(ptr_from_va(codec_va), advance_offset);
    }

    return read_u32(req_va + 0x00u);
}

std::uint32_t __cdecl audio_stream_codec_queue_memory_0056c040(
    std::uint32_t codec_handle,
    const void* data,
    std::uint32_t size,
    std::uint32_t tag) {
    U codec_va = 0u;
    U scratch = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &codec_va, &scratch) != 0u) {
        report_stream_error(0x677u, stream_err_queuemem_invalid_005bdd04);
        return 0u;
    }

    void* const req = audio_stream_codec_alloc_request_0056b790(ptr_from_va(codec_va));
    if (req == nullptr) {
        return 0u;
    }

    const U data_va = va_from_ptr(data);
    U resolved_size = size;
    if (resolved_size == 0u) {
        U cursor_va = data_va;
        while (read_u32(cursor_va + 0x00u) != tag) {
            const U chunk_size = read_u32(cursor_va + 0x04u);
            cursor_va += chunk_size;
            resolved_size += chunk_size;
        }
        resolved_size += read_u32(cursor_va + 0x04u);
    }

    const U req_va = va_from_ptr(req);
    write_u32(req_va + 0x10u, 1u);
    write_u32(req_va + 0x118u, data_va);
    write_u32(req_va + 0x11cu, resolved_size);
    write_u32(req_va + 0x120u, tag);

    audio_stream_codec_enqueue_request_0056b800(ptr_from_va(codec_va), req);

    heap_enter_005322b0(ptr_from_va(read_u32(codec_va + 0x04u)));
    const U prev_state28 = read_u32(codec_va + 0x28u);
    if (prev_state28 == 0u) {
        write_u32(codec_va + 0x28u, 1u);
    }
    heap_leave_005322c0(ptr_from_va(read_u32(codec_va + 0x04u)));

    if (prev_state28 == 0u) {
        audio_stream_codec_advance_0056b860(ptr_from_va(codec_va), 0u);
    }

    return read_u32(req_va + 0x00u);
}

std::int32_t __cdecl audio_service_stream_start_00567550(
    std::uint32_t channel_tag,
    std::uint32_t stream_flags,
    std::uint32_t arg2,
    std::uint32_t offset_or_size,
    std::uint32_t arg4) {
    if (application_audio_device_state_006b48c0[0xdc] == 0u) {
        return -10;
    }

    const U chan_va = audio_stream_service_lookup_00566d60(static_cast<I>(channel_tag));
    if (chan_va == 0u) {
        return -8;
    }

    const std::int8_t max_slots = static_cast<std::int8_t>(read_u8(chan_va + 0x15u));
    const std::int8_t cur_slots = static_cast<std::int8_t>(read_u8(chan_va + 0x16u));
    if (cur_slots >= max_slots) {
        return -13;
    }

    U stream_id = 0u;
    if (arg4 == 0u) {
        stream_id = audio_stream_codec_queue_file_0056b690(
            read_u32(chan_va + 0x04u),
            reinterpret_cast<const char*>(static_cast<std::uintptr_t>(arg2)),
            offset_or_size,
            0x6c454353u);
    } else if (arg4 == 1u) {
        stream_id = audio_stream_codec_queue_memory_0056c040(
            read_u32(chan_va + 0x04u),
            ptr_from_va(arg2),
            0u,
            0x6c454353u);
    } else {
        stream_id = offset_or_size;
    }

    if (stream_id == 0u) {
        return -1;
    }

    audio_backend_lock_005896d0();
    const std::int8_t slot_idx = static_cast<std::int8_t>(read_u8(chan_va + 0x16u));
    const U entry_va = read_u32(chan_va + 0x00u) +
        static_cast<U>(static_cast<I>(slot_idx) * 0x2c);
    write_u32(entry_va + 0x00u, stream_id);

    const U next_serial = read_u32(chan_va + 0x10u) + 0x100u;
    write_u32(chan_va + 0x10u, (static_cast<I>(next_serial) < 0) ? 0u : next_serial);

    const U stream_handle = read_u32(chan_va + 0x10u) | channel_tag;
    write_u32(entry_va + 0x04u, stream_handle);
    write_u16(entry_va + 0x28u, static_cast<std::uint16_t>(stream_flags));
    write_u8(chan_va + 0x16u, static_cast<B>(static_cast<U>(slot_idx) + 1u));

    write_u32(entry_va + 0x10u, 0u);
    write_u32(entry_va + 0x08u, 0xffffffffu);
    write_u32(entry_va + 0x0cu, 0xffffffffu);
    write_u32(entry_va + 0x14u, 0u);
    write_u32(entry_va + 0x1cu, 0u);
    write_u32(entry_va + 0x20u, 0u);
    write_u32(entry_va + 0x24u, 0u);
    audio_backend_unlock_005896f0();

    return static_cast<I>(read_u32(entry_va + 0x04u));
}

} // namespace porsche
