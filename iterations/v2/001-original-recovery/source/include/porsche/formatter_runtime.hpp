#pragma once

#include <cstdint>

namespace porsche {

// Original Porsche.exe CRT-shaped helpers. The two 64-bit helpers use the
// x86 stdcall ABI (four argument dwords, RET 10h); divide-by-zero is outside
// the defined comparison domain because the original executes DIV.
std::uint64_t __stdcall formatter_unsigned_divide_005a67b0(
    std::uint64_t dividend, std::uint64_t divisor);
std::uint64_t __stdcall formatter_unsigned_remainder_005a6820(
    std::uint64_t dividend, std::uint64_t divisor);

// Original byte-string length leaf, cdecl; caller removes the pointer arg.
std::uint32_t __cdecl formatter_strlen_005a6730(const char* text);

} // namespace porsche
