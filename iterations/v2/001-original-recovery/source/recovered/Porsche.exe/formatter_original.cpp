#include "porsche/formatter_original.hpp"

#include <cstring>

namespace porsche {

std::uint32_t* __cdecl formatter_original_emit_005a4ab2(
    std::int32_t character, FormatterOriginalDescriptor32* descriptor,
    std::int32_t* emitted_count) {
    // The original DEC/JS checks the sign bit after a wrapping DWORD decrement.
    const auto remaining = static_cast<std::uint32_t>(descriptor->remaining) - 1u;
    std::memcpy(&descriptor->remaining, &remaining, sizeof(remaining));
    std::uint32_t eax;
    if ((remaining & 0x80000000u) == 0) {
        *descriptor->cursor++ = static_cast<char>(character);
        eax = static_cast<std::uint8_t>(character);
    } else {
        eax = static_cast<std::uint32_t>(formatter_original_cleanup_boundary_005a4259(
            static_cast<std::uint32_t>(character), descriptor));
    }
    if (eax == 0xffffffffu) {
        *emitted_count = -1;
    } else {
        std::uint32_t count_bits;
        std::memcpy(&count_bits, emitted_count, sizeof(count_bits));
        ++count_bits; // Original INC wraps the 32-bit counter.
        std::memcpy(emitted_count, &count_bits, sizeof(count_bits));
    }
    return reinterpret_cast<std::uint32_t*>(emitted_count);
}

void __cdecl formatter_original_repeat_005a4ae7(
    std::int32_t character, std::int32_t repeat,
    FormatterOriginalDescriptor32* descriptor, std::int32_t* emitted_count) {
    // Original loop is signed: non-positive repeat emits no bytes.
    for (std::int32_t remaining = repeat; remaining > 0; --remaining) {
        formatter_original_emit_005a4ab2(character, descriptor, emitted_count);
        if (*emitted_count == -1) break;
    }
}

void __cdecl formatter_original_span_005a4b18(
    const std::uint8_t* bytes, std::int32_t length,
    FormatterOriginalDescriptor32* descriptor, std::int32_t* emitted_count) {
    for (std::int32_t remaining = length; remaining > 0; --remaining) {
        const auto character = static_cast<std::int8_t>(*bytes++);
        formatter_original_emit_005a4ab2(character, descriptor, emitted_count);
        if (*emitted_count == -1) break;
    }
}

std::uint32_t __cdecl formatter_original_next_u32_005a4b50(
    std::uint32_t** raw_va) {
    const auto* value = (*raw_va)++;
    return *value;
}

std::uint64_t __cdecl formatter_original_next_u64_005a4b5d(
    std::uint32_t** raw_va) {
    std::uint32_t* const old_cursor = *raw_va;
    *raw_va = old_cursor + 2;
    const std::uint32_t low = old_cursor[0];
    const std::uint32_t high = old_cursor[1];
    return (static_cast<std::uint64_t>(high) << 32) | low;
}

std::uint16_t __cdecl formatter_original_next_u16_005a4b6d(
    std::uint32_t** raw_va) {
    std::uint32_t* const old_cursor = *raw_va;
    *raw_va = old_cursor + 1;
    return static_cast<std::uint16_t>(*old_cursor);
}

} // namespace porsche
