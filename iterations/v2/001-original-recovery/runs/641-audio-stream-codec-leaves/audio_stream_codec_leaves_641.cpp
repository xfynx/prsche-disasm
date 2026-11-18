// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056bce0..0056bd08, 41 bytes, sha256 c3a26795b666ad068eda385f9d795553845f366f46eaa79f930cf957ba1283eb.
// Original 0056bd10..0056bd62, 83 bytes, sha256 867cc6c575eb1bb7ae917cbe740c6a96548a9ee058d30781613ff61560384c24.
// Original 0056c380..0056c3d9, 90 bytes, sha256 a7b103ac2d05ff7acb0d14f4cf06f8f6a5f5c094d705214f59651c68c91fa607.
// Original 0056c3e0..0056c419, 58 bytes, sha256 864a69b605fcddba20caafb61bce75060d67a1213e7f6a321a2107e0408287d9.
// Original 0056c540..0056c61c, 221 bytes, sha256 289e2fe4a2e4cad9c6fd74fcfdb28d2aceb733e22a89ebbb6dee17e778cce541.
#include "audio_stream_codec_leaves_641.hpp"

#include <cstring>

namespace porsche {

const char stream_err_get_invalid_handle_005bdd88[36] = "STREAM_get - invalid stream handle\n";

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

} // namespace

std::uint32_t __cdecl audio_stream_ring_contains_0056bce0(
    std::uint32_t start,
    std::uint32_t end,
    std::uint32_t ptr) {
    if (start <= end) {
        return (ptr >= start && ptr < end) ? 1u : 0u;
    }
    return (ptr >= start || ptr < end) ? 1u : 0u;
}

void __cdecl audio_stream_request_unlink_0056bd10(
    std::uint32_t stream,
    std::uint32_t node) {
    const U head = read_u32(stream + 0x4cu);
    const U next = read_u32(node + 0x0cu);
    if (node == head) {
        write_u32(stream + 0x4cu, next);
    } else {
        const U prev = read_u32(node + 0x08u);
        write_u32(prev + 0x0cu, next);
    }

    const U tail = read_u32(stream + 0x54u);
    const U prev = read_u32(node + 0x08u);
    if (node == tail) {
        write_u32(stream + 0x54u, prev);
    } else {
        write_u32(next + 0x08u, prev);
    }

    const U active = read_u32(stream + 0x50u);
    if (node == active) {
        const U cursor = (next != 0u) ? next : read_u32(node + 0x08u);
        write_u32(stream + 0x50u, cursor);
    }

    const U free_head = read_u32(stream + 0x58u);
    write_u32(node + 0x04u, 0u);
    write_u32(node + 0x0cu, free_head);
    write_u32(stream + 0x58u, node);
}

void __cdecl audio_stream_consume_bytes_0056c380(
    std::uint32_t stream,
    std::uint32_t delta) {
    void* const lock = ptr_from_va(read_u32(stream + 0x04u));
    heap_enter_005322b0(lock);
    const U prev_avail = read_u32(stream + 0x3cu);
    const U next_avail = prev_avail - delta;
    write_u32(stream + 0x3cu, next_avail);
    heap_leave_005322c0(lock);

    const I threshold = static_cast<I>(read_u32(stream + 0x34u));
    if (static_cast<I>(prev_avail) >= threshold && static_cast<I>(next_avail) < threshold) {
        const U state28 = read_u32(stream + 0x28u);
        write_u32(stream + 0x38u, 1u);
        if (state28 == 1u) {
            const U group = read_u32(stream + 0x30u);
            const U op_id = read_u32(stream + 0x168u);
            file_operation_set_group_005681b0(op_id, group);
        }
    }
}

std::uint32_t __cdecl audio_stream_request_lookup_0056c3e0(
    std::uint32_t stream,
    std::uint32_t req_id) {
    const U idx = req_id & 0xffu;
    const I count = static_cast<I>(read_u32(stream + 0x0cu));
    if (static_cast<I>(idx) >= count) {
        return 0u;
    }
    const U req = read_u32(stream + 0x08u) + idx * 0x128u;
    if (read_u32(req) != req_id) {
        return 0u;
    }
    return (read_u32(req + 0x04u) != 0u) ? req : 0u;
}

std::uint32_t __cdecl audio_stream_get_0056c540(std::uint32_t handle) {
    U object = 0u;
    if (audio_stream_handle_validate_0056b380(handle, &object, &handle) != 0u) {
        diagnostic_file_005deb74_set(stream_source_file_005bd978);
        diagnostic_line_005deb78 = 0x7e5u;
        diagnostic_handler_005debf0(stream_err_get_invalid_handle_005bdd88);
        return 0u;
    }

    const U tap = handle;
    if (read_u32(tap + 0x08u) == 0u) {
        return 0u;
    }

    const U chunk = read_u32(tap + 0x0cu);
    const U chunk_size = read_u32(chunk + 0x04u) & 0x00ffffffu;
    write_u32(chunk + 0x04u, chunk_size);

    heap_enter_005322b0(ptr_from_va(read_u32(object + 0x04u)));
    const I remaining = static_cast<I>(read_u32(tap + 0x08u) - chunk_size);
    write_u32(tap + 0x08u, static_cast<U>(remaining));
    heap_leave_005322c0(ptr_from_va(read_u32(object + 0x04u)));

    if (remaining > 0) {
        U cur = chunk + chunk_size;
        U word4 = read_u32(cur + 0x04u);
        const U tag_mask = read_u32(tap + 0x04u) << 24u;
        while ((word4 & 0xff000000u) != tag_mask) {
            if (read_u32(cur) == 0xffffffffu) {
                cur = read_u32(object + 0x20u);
            } else {
                cur += (word4 & 0x00ffffffu);
            }
            word4 = read_u32(cur + 0x04u);
        }
        write_u32(tap + 0x0cu, cur);
    }

    return chunk;
}

} // namespace porsche
