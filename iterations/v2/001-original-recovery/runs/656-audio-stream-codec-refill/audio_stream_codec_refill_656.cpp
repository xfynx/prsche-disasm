// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056baf0..0056bcda, 491 bytes, sha256 c696b811c7c9d07c46753ae15753780f2e6b4995b992198bca69dab1b49a183a.
// Original 0056bd70..0056be30, 193 bytes, sha256 2dbfea5b820f8dcadfa65485477dd0c98f74351a980d2024cf3b26c7be7f6df5.
// Original 0056be40..0056bff2, 435 bytes, sha256 994f168245534cd55c3733e907b87689e86597090b68e8f443c55f4b02a7e5db.
// Original 0056c000..0056c03b, 60 bytes, sha256 47cbab69c9f1a826e7aa58d48842456f844a51a4efec969ac6899712fa8e4354.
#include "audio_stream_codec_refill_656.hpp"

#include <cstring>

namespace porsche {

const char stream_err_unable_to_read_005bdc70[39] =
    "STREAM - unable to initiate file read\n";
const char stream_err_invalid_chunk_005bdc98[66] =
    "STREAM - invalid chunk (%02x %02x %02x %02x %02x %02x %02x %02x)\n";
const char stream_err_abort_tap_005bdcdc[38] =
    "STREAM - chunk received at abort tap\n";

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

inline U read_u8(U addr) noexcept {
    B value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return static_cast<U>(value);
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

inline void report_invalid_chunk_error(U line, U chunk_va) {
    using Diagnostic8BytesFn = void(__cdecl*)(
        const char*, U, U, U, U, U, U, U, U);
    Diagnostic8BytesFn fn = nullptr;
    static_assert(sizeof fn == sizeof diagnostic_handler_005debf0, "fn ptr size");
    std::memcpy(&fn, &diagnostic_handler_005debf0, sizeof fn);

    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    fn(stream_err_invalid_chunk_005bdc98,
       read_u8(chunk_va + 0u),
       read_u8(chunk_va + 1u),
       read_u8(chunk_va + 2u),
       read_u8(chunk_va + 3u),
       read_u8(chunk_va + 4u),
       read_u8(chunk_va + 5u),
       read_u8(chunk_va + 6u),
       read_u8(chunk_va + 7u));
}

} // namespace

std::int32_t __cdecl audio_stream_codec_match_tap_0056c000(
    const void* codec,
    const std::uint32_t* chunk_header) {
    const U codec_va = va_from_ptr(codec);
    const U tag_word = *chunk_header;
    const I num_filters = static_cast<I>(read_u32(codec_va + 0x14u));
    if (num_filters <= 0) {
        return -2;
    }

    U desc = read_u32(codec_va + 0x10u);
    for (I i = 0; i < num_filters; ++i) {
        if ((read_u32(desc + 0x00u) & tag_word) == read_u32(desc + 0x04u)) {
            return static_cast<I>(read_u32(desc + 0x08u));
        }
        desc += 0x0cu;
    }
    return -2;
}

std::int32_t __cdecl audio_stream_codec_process_ring_0056be40(void* codec) {
    const U codec_va = va_from_ptr(codec);
    const U req = read_u32(codec_va + 0x50u);
    U write_cur = read_u32(codec_va + 0x44u);
    U write_limit = read_u32(codec_va + 0x48u);

    while (static_cast<I>(write_limit - write_cur) >= 8) {
        const U size = read_u32(write_cur + 0x04u);
        if ((size & 0xff000000u) != 0u) {
            report_invalid_chunk_error(0x192u, write_cur);
            return 0;
        }

        const U chunk_end = write_cur + size;
        if (chunk_end > write_limit) {
            return 0;
        }

        const I tap_idx = audio_stream_codec_match_tap_0056c000(
            codec,
            reinterpret_cast<const std::uint32_t*>(ptr_from_va(write_cur)));

        U skip = 0u;
        if (tap_idx < 0) {
            if (tap_idx == -2) {
                report_stream_error(0x19eu, stream_err_abort_tap_005bdcdc);
            }
            void* const lock = ptr_from_va(read_u32(codec_va + 0x04u));
            heap_enter_005322b0(lock);
            skip = (read_u32(req + 0x04u) == 4u) ? 1u : 0u;
            if (skip == 0u) {
                write_u32(write_cur + 0x00u, 0xfffffffeu);
                write_u32(codec_va + 0x44u, read_u32(codec_va + 0x44u) + size);
            }
            heap_leave_005322c0(lock);
        } else {
            write_u32(write_cur + 0x04u,
                      read_u32(write_cur + 0x04u) | (static_cast<U>(tap_idx) << 24u));
            heap_enter_005322b0(ptr_from_va(read_u32(codec_va + 0x04u)));
            skip = (read_u32(req + 0x04u) == 4u) ? 1u : 0u;
            if (skip == 0u) {
                const U tap = read_u32(codec_va + 0x18u) +
                              static_cast<U>(tap_idx - 1) * 0x10u;
                const U new_tap_bytes = read_u32(tap + 0x08u) + size;
                write_u32(tap + 0x08u, new_tap_bytes);
                if (new_tap_bytes == size) {
                    write_u32(tap + 0x0cu, write_cur);
                }

                const U old_write44 = read_u32(codec_va + 0x44u);
                const U old_queued = read_u32(codec_va + 0x3cu);
                const I target = static_cast<I>(read_u32(codec_va + 0x34u));
                const U new_queued = size + old_queued;
                write_u32(codec_va + 0x44u, old_write44 + size);
                write_u32(codec_va + 0x3cu, new_queued);
                if (static_cast<I>(old_queued) < target && static_cast<I>(new_queued) >= target) {
                    write_u32(codec_va + 0x38u, 0u);
                }
            }
            heap_leave_005322c0(ptr_from_va(read_u32(codec_va + 0x04u)));
        }

        if (skip != 0u) {
            return 0;
        }
        if (read_u32(write_cur + 0x00u) == read_u32(req + 0x120u)) {
            return 1;
        }

        write_limit = read_u32(codec_va + 0x48u);
        write_cur = read_u32(codec_va + 0x44u);
    }

    return 0;
}

void __cdecl audio_stream_codec_read_done_0056bd70(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec) {
    (void)op_handle;
    (void)status;

    const U codec_va = va_from_ptr(codec);
    const U req = read_u32(codec_va + 0x50u);
    U bytes = 0u;
    U short_or_eof = 0u;

    if (read_u32(req + 0x10u) == 1u) {
        bytes = read_u32(codec_va + 0x16cu);
        const I total_read = static_cast<I>(read_u32(codec_va + 0x164u) + bytes);
        const I req_len = static_cast<I>(read_u32(req + 0x11cu));
        short_or_eof = (total_read >= req_len) ? 1u : 0u;
    } else {
        bytes = operation_complete_00567df0(read_u32(codec_va + 0x168u));
        const I expected_bytes = static_cast<I>(read_u32(codec_va + 0x16cu));
        short_or_eof = (static_cast<I>(bytes) < expected_bytes) ? 1u : 0u;
    }

    write_u32(codec_va + 0x164u, read_u32(codec_va + 0x164u) + bytes);
    write_u32(codec_va + 0x48u, read_u32(codec_va + 0x48u) + bytes);

    const I found_sentinel = audio_stream_codec_process_ring_0056be40(codec);
    if (read_u32(req + 0x04u) == 4u) {
        audio_stream_codec_advance_0056b860(codec, read_u32(codec_va + 0x30u));
        return;
    }

    if (short_or_eof == 0u && found_sentinel == 0) {
        audio_stream_codec_refill_0056baf0(codec, read_u32(codec_va + 0x30u));
        return;
    }

    void* const lock = ptr_from_va(read_u32(codec_va + 0x04u));
    heap_enter_005322b0(lock);
    write_u32(req + 0x04u, 3u);
    heap_leave_005322c0(lock);

    audio_stream_codec_advance_0056b860(codec, read_u32(codec_va + 0x30u));
}

void __cdecl audio_stream_codec_refill_0056baf0(
    void* codec,
    std::uint32_t offset) {
    const U codec_va = va_from_ptr(codec);
    U read40 = read_u32(codec_va + 0x40u);
    const U write44_init = read_u32(codec_va + 0x44u);

    while (read40 != write44_init) {
        const U word0 = read_u32(read40 + 0x00u);
        if (word0 == 0xffffffffu) {
            write_u32(codec_va + 0x40u, read_u32(codec_va + 0x20u));
        } else if (word0 == 0xfffffffeu) {
            write_u32(codec_va + 0x40u, read40 + read_u32(read40 + 0x04u));
        } else {
            break;
        }
        read40 = read_u32(codec_va + 0x40u);
    }

    heap_enter_005322b0(ptr_from_va(read_u32(codec_va + 0x04u)));
    U head = read_u32(codec_va + 0x4cu);
    U next = read_u32(head + 0x0cu);
    while (next != 0u) {
        if (read_u32(next + 0x04u) == 1u) {
            break;
        }
        if (audio_stream_ring_contains_0056bce0(
                read_u32(codec_va + 0x40u),
                read_u32(codec_va + 0x48u),
                read_u32(next + 0x124u) - 1u) != 0u) {
            break;
        }
        audio_stream_request_unlink_0056bd10(codec_va, head);
        head = read_u32(codec_va + 0x4cu);
        next = read_u32(head + 0x0cu);
    }
    heap_leave_005322c0(ptr_from_va(read_u32(codec_va + 0x04u)));

    const U read_cur = read_u32(codec_va + 0x40u);
    const U write48_cur = read_u32(codec_va + 0x48u);
    I avail = 0;

    if (read_cur > write48_cur) {
        avail = static_cast<I>((read_cur - write48_cur) - 1u);
        if (avail < 0x2000) {
            write_u32(codec_va + 0x28u, 2u);
            return;
        }
    } else {
        avail = static_cast<I>(read_u32(codec_va + 0x24u) - write48_cur - 8u);
        if (avail < 0x2000) {
            const U write44_cur = read_u32(codec_va + 0x44u);
            const U ring_start = read_u32(codec_va + 0x20u);
            const U tail_bytes = write48_cur - write44_cur;
            const U head_space = read_cur - ring_start;
            if (static_cast<I>(head_space) < static_cast<I>(tail_bytes + 1u)) {
                write_u32(codec_va + 0x28u, 2u);
                return;
            }
            if (tail_bytes != 0u) {
                std::memmove(ptr_from_va(ring_start), ptr_from_va(write44_cur), tail_bytes);
            }
            write_u32(write44_cur + 0x00u, 0xffffffffu);
            write_u32(write44_cur + 0x04u, 8u);
            const U new_ring_start = read_u32(codec_va + 0x20u);
            write_u32(codec_va + 0x44u, new_ring_start);
            const U new_write48 = new_ring_start + tail_bytes;
            write_u32(codec_va + 0x48u, new_write48);
            avail = static_cast<I>((read_u32(codec_va + 0x40u) - new_write48) - 1u);
            if (avail < 0x2000) {
                write_u32(codec_va + 0x28u, 2u);
                return;
            }
        }
    }

    const U req = read_u32(codec_va + 0x50u);
    if (read_u32(req + 0x10u) == 1u) {
        const U pos164 = read_u32(codec_va + 0x164u);
        const U req_len = read_u32(req + 0x11cu);
        U copy_bytes = static_cast<U>(avail);
        if (static_cast<I>(pos164 + copy_bytes) > static_cast<I>(req_len)) {
            copy_bytes = req_len - pos164;
        }
        write_u32(codec_va + 0x16cu, copy_bytes);
        const U n = read_u32(codec_va + 0x16cu);
        if (n != 0u) {
            std::memcpy(
                ptr_from_va(read_u32(codec_va + 0x48u)),
                ptr_from_va(read_u32(req + 0x118u)),
                n);
        }
        write_u32(req + 0x118u, read_u32(req + 0x118u) + read_u32(codec_va + 0x16cu));
        audio_stream_codec_read_done_0056bd70(0u, 0, codec);
        return;
    }

    write_u32(codec_va + 0x16cu, 0x2000u);
    const U op_id = request_read_00568b10(
        ptr_from_va(read_u32(codec_va + 0x160u)),
        read_u32(codec_va + 0x164u),
        ptr_from_va(read_u32(codec_va + 0x48u)),
        0x2000,
        offset,
        codec);
    write_u32(codec_va + 0x168u, op_id);
    if (op_id == 0u) {
        report_stream_error(0x321u, stream_err_unable_to_read_005bdc70);
        return;
    }

    operation_callback_005680c0(op_id, &audio_stream_codec_read_done_0056bd70);
}

} // namespace porsche
