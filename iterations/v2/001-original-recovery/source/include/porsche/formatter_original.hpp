#pragma once

#include <cstdint>

namespace porsche {

// Recovered formatter output descriptor prefix. The original wrapper reserves
// 32 bytes; only these first four DWORDs are understood here. Keep the tail
// opaque and preserve it across helper calls.
struct FormatterOriginalDescriptor32 {
    char* cursor;
    std::int32_t remaining;
    char* base;
    std::uint32_t flags;
    std::uint8_t opaque_tail[16];
};
static_assert(sizeof(FormatterOriginalDescriptor32) == 32);

// External cleanup boundary at 005a4259, called only when output capacity is
// exhausted. Its effects are not part of this helper packet.
std::int32_t __cdecl formatter_original_cleanup_boundary_005a4259(
    std::uint32_t emitted_character, FormatterOriginalDescriptor32* descriptor);

// Exact bounded helpers called by 005a4371.
std::uint32_t* __cdecl formatter_original_emit_005a4ab2(
    std::int32_t character, FormatterOriginalDescriptor32* descriptor,
    std::int32_t* emitted_count);
void __cdecl formatter_original_repeat_005a4ae7(
    std::int32_t character, std::int32_t repeat,
    FormatterOriginalDescriptor32* descriptor, std::int32_t* emitted_count);
void __cdecl formatter_original_span_005a4b18(
    const std::uint8_t* bytes, std::int32_t length,
    FormatterOriginalDescriptor32* descriptor, std::int32_t* emitted_count);
std::uint32_t __cdecl formatter_original_next_u32_005a4b50(
    std::uint32_t** raw_va);
std::uint64_t __cdecl formatter_original_next_u64_005a4b5d(
    std::uint32_t** raw_va);
std::uint16_t __cdecl formatter_original_next_u16_005a4b6d(
    std::uint32_t** raw_va);

} // namespace porsche
