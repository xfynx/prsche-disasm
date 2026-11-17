// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00566d80..00566e02 (131 bytes, sha256 3e88637509337eaac214314428172a1c6ea781e4a9cd1757071abd8d6be0c5e7)
// and 00566e40..00566e9e (95 bytes, sha256 f7d3672e95dbf6fe7ea4e521874e9fc8fa2607145be2be9a412041c947d06970).
#include "audio_stream_service_consumed_623.hpp"

#include <cstring>

namespace porsche {

void __cdecl audio_stream_service_compact_00566d80(std::uint32_t handle_word) {
    auto* entry = reinterpret_cast<std::uint8_t*>(
        audio_stream_service_storage_006b7740.slots[handle_word & 0xffu]);
    std::int32_t write_idx = 0;
    if (static_cast<std::int8_t>(entry[0x16u]) > 0) {
        std::uint8_t* dst = nullptr;
        std::memcpy(&dst, entry, sizeof(dst));
        const std::uint8_t* src = dst;
        for (std::int32_t read_idx = 0;
             read_idx < static_cast<std::int32_t>(static_cast<std::int8_t>(entry[0x16u]));
             ++read_idx) {
            std::uint32_t rec_id = 0u;
            std::memcpy(&rec_id, src + 4u, sizeof(rec_id));
            if (rec_id != handle_word) {
                if (static_cast<std::int32_t>(static_cast<std::int8_t>(entry[0x17u])) == read_idx) {
                    entry[0x17u] = static_cast<std::uint8_t>(write_idx);
                }
                if (dst != src) {
                    std::memmove(dst, src, 0x2cu);
                }
                ++write_idx;
                dst += 0x2cu;
            }
            src += 0x2cu;
        }
    }
    entry[0x16u] = static_cast<std::uint8_t>(entry[0x16u] - 1u);
    if (static_cast<std::int8_t>(entry[0x17u]) > static_cast<std::int8_t>(entry[0x16u])) {
        entry[0x17u] = static_cast<std::uint8_t>(entry[0x17u] - 1u);
    }
}

void __cdecl audio_stream_service_consumed_00566e40(
    std::uint32_t service_id, std::uint32_t consumed_bytes) {
    const std::int32_t idx =
        static_cast<std::int32_t>(audio_stream_service_storage_006b7740.index_map[service_id]);
    const auto* entry = reinterpret_cast<const std::uint8_t*>(
        audio_stream_service_storage_006b7740.slots[idx]);
    std::uint8_t* state = nullptr;
    std::memcpy(&state, entry, sizeof(state));

    std::uint32_t carry = 0u;
    std::uint32_t amount = consumed_bytes;
    for (;;) {
        std::uint32_t remaining = 0u;
        std::memcpy(&remaining, state + 0x1cu, sizeof(remaining));
        if (amount > remaining) {
            carry = amount - remaining;
            amount = amount - carry;
        }
        std::uint32_t offset = 0u;
        std::memcpy(&offset, state + 0x14u, sizeof(offset));
        offset += amount;
        std::memcpy(state + 0x14u, &offset, sizeof(offset));

        std::uint32_t rem_after = 0u;
        std::memcpy(&rem_after, state + 0x1cu, sizeof(rem_after));
        rem_after -= amount;
        std::memcpy(state + 0x1cu, &rem_after, sizeof(rem_after));

        std::uint32_t limit = 0u;
        std::memcpy(&limit, state + 0x18u, sizeof(limit));
        std::uint32_t cur_offset = 0u;
        std::memcpy(&cur_offset, state + 0x14u, sizeof(cur_offset));
        if (cur_offset >= limit) {
            std::uint32_t handle_word = 0u;
            std::memcpy(&handle_word, state + 0x04u, sizeof(handle_word));
            audio_stream_service_compact_00566d80(handle_word);
        }
        if (carry == 0u) {
            break;
        }
        amount = carry;
        carry = 0u;
    }
}

} // namespace porsche
