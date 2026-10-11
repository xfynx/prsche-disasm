#include "porsche/formatter_runtime.hpp"

#include <cstring>

namespace porsche {
namespace {

struct Words64 { std::uint32_t lo, hi; };

Words64 words(std::uint64_t value) noexcept {
    return {static_cast<std::uint32_t>(value),
            static_cast<std::uint32_t>(value >> 32)};
}

std::uint64_t combine(std::uint32_t lo, std::uint32_t hi) noexcept {
    return (static_cast<std::uint64_t>(hi) << 32) | lo;
}

struct DivResult { std::uint32_t quotient, remainder; };
DivResult divide_step(std::uint32_t lo, std::uint32_t hi,
                      std::uint32_t divisor) noexcept {
    DivResult result{};
    __asm {
        mov eax, lo
        mov edx, hi
        div divisor
        lea ecx, result
        mov [ecx], eax
        mov [ecx+4], edx
    }
    return result;
}

} // namespace

std::uint64_t __stdcall formatter_unsigned_divide_005a67b0(
    std::uint64_t dividend, std::uint64_t divisor) {
    auto n = words(dividend);
    const auto d = words(divisor);
    if (d.hi == 0) {
        // The original performs two 32-bit DIVs, first producing quotient-high.
        const auto high_step = divide_step(n.hi, 0, d.lo);
        const auto low_step = divide_step(n.lo, high_step.remainder, d.lo);
        return combine(low_step.quotient, high_step.quotient);
    }

    auto normalized_n = n;
    auto normalized_d = d;
    while (normalized_d.hi != 0) {
        normalized_d.lo = (normalized_d.lo >> 1) | (normalized_d.hi << 31);
        normalized_d.hi >>= 1;
        normalized_n.lo = (normalized_n.lo >> 1) | (normalized_n.hi << 31);
        normalized_n.hi >>= 1;
    }
    auto estimate = divide_step(normalized_n.lo, normalized_n.hi,
                                normalized_d.lo).quotient;

    // Recreate MUL high*estimate followed by MUL low*estimate and ADD/compare.
    const auto high_mul = static_cast<std::uint64_t>(estimate) * d.hi;
    const auto low_mul = static_cast<std::uint64_t>(estimate) * d.lo;
    const auto product_hi = static_cast<std::uint32_t>(low_mul >> 32) +
                            static_cast<std::uint32_t>(high_mul);
    const bool carry = product_hi < static_cast<std::uint32_t>(low_mul >> 32);
    if (carry || product_hi > n.hi ||
        (product_hi == n.hi && static_cast<std::uint32_t>(low_mul) > n.lo)) {
        --estimate;
    }
    return estimate;
}

std::uint64_t __stdcall formatter_unsigned_remainder_005a6820(
    std::uint64_t dividend, std::uint64_t divisor) {
    const auto n = words(dividend);
    const auto d = words(divisor);
    if (d.hi == 0) {
        const auto high_step = divide_step(n.hi, 0, d.lo);
        const auto low_step = divide_step(n.lo, high_step.remainder, d.lo);
        return low_step.remainder;
    }

    auto normalized_n = n;
    auto normalized_d = d;
    while (normalized_d.hi != 0) {
        normalized_d.lo = (normalized_d.lo >> 1) | (normalized_d.hi << 31);
        normalized_d.hi >>= 1;
        normalized_n.lo = (normalized_n.lo >> 1) | (normalized_n.hi << 31);
        normalized_n.hi >>= 1;
    }
    auto estimate = divide_step(normalized_n.lo, normalized_n.hi,
                                normalized_d.lo).quotient;

    const auto high_mul = static_cast<std::uint64_t>(estimate) * d.hi;
    const auto low_mul = static_cast<std::uint64_t>(estimate) * d.lo;
    auto product_lo = static_cast<std::uint32_t>(low_mul);
    auto product_hi = static_cast<std::uint32_t>(low_mul >> 32) +
                      static_cast<std::uint32_t>(high_mul);
    const bool carry = product_hi < static_cast<std::uint32_t>(low_mul >> 32);
    if (carry || product_hi > n.hi ||
        (product_hi == n.hi && product_lo > n.lo)) {
        const auto old_lo = product_lo;
        product_lo -= d.lo;
        product_hi -= d.hi + static_cast<std::uint32_t>(product_lo > old_lo);
    }
    const auto rem_lo = n.lo - product_lo;
    const auto borrow = n.lo < product_lo;
    const auto rem_hi = n.hi - product_hi - static_cast<std::uint32_t>(borrow);
    return combine(rem_lo, rem_hi);
}

std::uint32_t __cdecl formatter_strlen_005a6730(const char* text) {
    const auto* cursor = reinterpret_cast<const unsigned char*>(text);
    while ((reinterpret_cast<std::uintptr_t>(cursor) & 3u) != 0) {
        if (*cursor == 0) return static_cast<std::uint32_t>(cursor -
            reinterpret_cast<const unsigned char*>(text));
        ++cursor;
    }
    for (;;) {
        std::uint32_t value;
        std::memcpy(&value, cursor, sizeof(value));
        const auto probe = ((~value) ^ (value + 0x7efefeffu)) & 0x81010100u;
        cursor += 4;
        if (probe == 0) continue;
        const auto* word = cursor - 4;
        for (std::uint32_t i = 0; i != 4; ++i) {
            if (word[i] == 0) return static_cast<std::uint32_t>(word + i -
                reinterpret_cast<const unsigned char*>(text));
        }
    }
}

} // namespace porsche
