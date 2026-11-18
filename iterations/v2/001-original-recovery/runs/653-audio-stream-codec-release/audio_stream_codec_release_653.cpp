// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00566e10..00566e33, 36 bytes, sha256 53207ea2ce397bb1df94431d284b7a9c02643717470cd2ce5205d36abebf6a1f.
// Original 0056b3b0..0056b45e, 175 bytes, sha256 eb1d1d1000e23fc0eb0f3a91b8d917351c17e1f2f73fb87ea18581285e82c72b.
// Original 0056c140..0056c377, 568 bytes, sha256 a85ed49b2b67c6dcb24fceafebfb13795bf185987bc7d0c26aaf0a2a283a4d3b.
// Original 0056c420..0056c537, 280 bytes, sha256 0103e90f596744505d318693746b3b4e322e0be24f4d0f45c67b91507d9bf9b8.
// Original 0056c620..0056c73e, 287 bytes, sha256 0e45f351da30eaf61d0d166cb12bbfbeac45f467e94e15226d07ff5332938776.
#include "audio_stream_codec_release_653.hpp"

#include <cstring>

namespace porsche {

const char stream_err_destroy_invalid_handle_005bdaa0[40] =
    "STREAM_destroy - invalid stream handle\n";
const char stream_err_cancelrequest_invalid_handle_005bdd30[46] =
    "STREAM_cancelrequest - invalid stream handle\n";
const char stream_err_kill_invalid_handle_005bdd60[37] =
    "STREAM_kill - invalid stream handle\n";
const char stream_err_release_wrong_stream_005bddac[60] =
    "STREAM_release - chunk does not belong to specified stream\n";
const char stream_err_release_already_released_005bdde8[50] =
    "STREAM_release - chunk has already been released\n";
const char stream_err_release_invalid_handle_005bde1c[40] =
    "STREAM_release - invalid stream handle\n";

namespace {

using U = std::uint32_t;
using I = std::int32_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline void* ptr_from_va(U addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

inline void report_stream_error(U line, const char* msg) {
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    diagnostic_handler_005debf0(msg);
}

} // namespace

void __cdecl audio_stream_service_release_00566e10(std::uint32_t chunk_data_va) {
    const U header_va = read_u32(chunk_data_va - 4u);
    const U slot_idx = read_u32(header_va) & 0xffu;
    const U channel_va = audio_stream_service_storage_006b7740.slots[slot_idx];
    const U codec_handle = read_u32(channel_va + 4u);
    audio_stream_codec_release_chunk_0056c620(codec_handle, ptr_from_va(header_va));
}

void __cdecl audio_stream_codec_destroy_0056b3b0(std::uint32_t codec_handle) {
    U object = 0u;
    U original = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &object, &original) != 0u) {
        report_stream_error(0x485u, stream_err_destroy_invalid_handle_005bdaa0);
        return;
    }

    audio_stream_codec_reset_0056c420(codec_handle);
    while (read_u32(object + 0x28u) == 1u) {
        if (file_current_thread_0055f780(0u) != 0) {
            file_pump_005366e0(0u);
        }
        file_sleep_0055f740(0u);
    }

    write_u32(object + 0x00u, 0u);
    heap_lock_destroy_005322d0(ptr_from_va(read_u32(object + 0x04u)));
    (void)close_00533da0(ptr_from_va(read_u32(object + 0x160u)), 0x64u);
}

void __cdecl audio_stream_codec_abort_node_0056c140(
    std::uint32_t codec_handle,
    std::uint32_t request_id) {
    U stream_va = 0u;
    U original = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &stream_va, &original) != 0u) {
        report_stream_error(0x6e0u, stream_err_cancelrequest_invalid_handle_005bdd30);
        return;
    }

    heap_enter_005322b0(ptr_from_va(read_u32(stream_va + 0x04u)));
    const U req = audio_stream_request_lookup_0056c3e0(stream_va, request_id);
    U skip_taps = 0u;
    U stream_read_40 = 0u;
    U start_ptr = 0u;
    U end_ptr = 0u;

    if (req == 0u) {
        skip_taps = 1u;
    } else {
        const U status = read_u32(req + 0x04u);
        if (status == 4u) {
            skip_taps = 1u;
        } else if (status == 1u) {
            skip_taps = 1u;
            audio_stream_request_unlink_0056bd10(stream_va, req);
        } else {
            write_u32(req + 0x04u, 4u);
            const U head = read_u32(stream_va + 0x4cu);
            stream_read_40 = read_u32(stream_va + 0x40u);
            start_ptr = (req == head) ? stream_read_40 : read_u32(req + 0x124u);
            const U next = read_u32(req + 0x0cu);
            end_ptr = (next != 0u && read_u32(next + 0x04u) != 1u)
                ? read_u32(next + 0x124u)
                : read_u32(stream_va + 0x44u);
        }
    }

    heap_leave_005322c0(ptr_from_va(read_u32(stream_va + 0x04u)));

    if (skip_taps != 0u) {
        return;
    }

    for (I i = 0; i < static_cast<I>(read_u32(stream_va + 0x1cu)); ++i) {
        const U tap = read_u32(stream_va + 0x18u) + static_cast<U>(i) * 0x10u;
        if (static_cast<I>(read_u32(tap + 0x08u)) <= 0) {
            continue;
        }
        const U tap_cur = read_u32(tap + 0x0cu);
        if (audio_stream_ring_contains_0056bce0(stream_read_40, start_ptr, tap_cur) != 0u) {
            const U tag_mask = read_u32(tap + 0x04u) << 24u;
            U cur = start_ptr;
            if (cur != end_ptr) {
                do {
                    if (read_u32(cur) == 0xffffffffu) {
                        cur = read_u32(stream_va + 0x20u);
                    } else {
                        const U word4 = read_u32(cur + 0x04u);
                        const U chunk_size = word4 & 0x00ffffffu;
                        if ((word4 & 0xff000000u) == tag_mask) {
                            heap_enter_005322b0(ptr_from_va(read_u32(stream_va + 0x04u)));
                            write_u32(tap + 0x08u, read_u32(tap + 0x08u) - chunk_size);
                            heap_leave_005322c0(ptr_from_va(read_u32(stream_va + 0x04u)));
                            audio_stream_consume_bytes_0056c380(stream_va, chunk_size);
                            write_u32(cur + 0x00u, 0xfffffffeu);
                            write_u32(cur + 0x04u, chunk_size);
                        }
                        cur += chunk_size;
                    }
                } while (cur != end_ptr);
            }
        } else if (audio_stream_ring_contains_0056bce0(start_ptr, end_ptr, tap_cur) != 0u) {
            do {
                const U chunk = audio_stream_get_0056c540(tap);
                audio_stream_codec_release_chunk_0056c620(tap, ptr_from_va(chunk));
                if (static_cast<I>(read_u32(tap + 0x08u)) <= 0) {
                    break;
                }
            } while (audio_stream_ring_contains_0056bce0(start_ptr, end_ptr, read_u32(tap + 0x0cu)) != 0u);
        }
    }
}

void __cdecl audio_stream_codec_reset_0056c420(std::uint32_t codec_handle) {
    U object = 0u;
    U original = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &object, &original) != 0u) {
        report_stream_error(0x775u, stream_err_kill_invalid_handle_005bdd60);
        return;
    }

    U tail = read_u32(object + 0x54u);
    if (tail == 0u) {
        return;
    }

    for (;;) {
        const U status = read_u32(tail + 0x04u);
        if (status != 1u && status != 2u) {
            break;
        }
        audio_stream_codec_abort_node_0056c140(codec_handle, read_u32(tail + 0x00u));
        tail = read_u32(object + 0x54u);
    }

    while (read_u32(object + 0x4cu) != read_u32(object + 0x50u)) {
        audio_stream_request_unlink_0056bd10(object, read_u32(object + 0x4cu));
    }

    write_u32(read_u32(object + 0x50u) + 0x04u, 4u);

    const I num_taps = static_cast<I>(read_u32(object + 0x1cu));
    for (I i = 0; i < num_taps; ++i) {
        const U tap = read_u32(object + 0x18u) + static_cast<U>(i) * 0x10u;
        write_u32(tap + 0x08u, 0u);
    }

    audio_stream_consume_bytes_0056c380(object, read_u32(object + 0x3cu));

    U cur = read_u32(object + 0x40u);
    if (cur != read_u32(object + 0x44u)) {
        do {
            if (read_u32(cur + 0x00u) == 0xffffffffu) {
                cur = read_u32(object + 0x20u);
            } else {
                const U size = read_u32(cur + 0x04u) & 0x00ffffffu;
                write_u32(cur + 0x00u, 0xfffffffeu);
                write_u32(cur + 0x04u, size);
                cur += size;
            }
        } while (cur != read_u32(object + 0x44u));
    }

    if (read_u32(object + 0x28u) == 2u) {
        write_u32(object + 0x28u, 0u);
    }
}

void __cdecl audio_stream_codec_release_chunk_0056c620(
    std::uint32_t codec_handle,
    void* chunk_header) {
    U object = 0u;
    U original = 0u;
    if (audio_stream_handle_validate_0056b380(codec_handle, &object, &original) != 0u) {
        report_stream_error(0x839u, stream_err_release_invalid_handle_005bde1c);
        return;
    }

    const U chunk_va = static_cast<U>(reinterpret_cast<std::uintptr_t>(chunk_header));
    if (chunk_va < read_u32(object + 0x20u) || chunk_va > read_u32(object + 0x24u) - 8u) {
        report_stream_error(0x840u, stream_err_release_wrong_stream_005bddac);
        return;
    }

    if (read_u32(chunk_va + 0x00u) == 0xfffffffeu) {
        report_stream_error(0x846u, stream_err_release_already_released_005bdde8);
        return;
    }

    write_u32(chunk_va + 0x00u, 0xfffffffeu);
    const U chunk_size = read_u32(chunk_va + 0x04u);
    audio_stream_consume_bytes_0056c380(object, chunk_size);

    heap_enter_005322b0(ptr_from_va(read_u32(object + 0x04u)));
    const U state28 = read_u32(object + 0x28u);
    if (state28 == 2u) {
        write_u32(object + 0x28u, 1u);
    }
    heap_leave_005322c0(ptr_from_va(read_u32(object + 0x04u)));

    if (state28 == 2u) {
        const U offset = (read_u32(object + 0x38u) != 0u)
            ? read_u32(object + 0x30u)
            : read_u32(object + 0x2cu);
        audio_stream_codec_refill_0056baf0(ptr_from_va(object), offset);
    }
}

} // namespace porsche
