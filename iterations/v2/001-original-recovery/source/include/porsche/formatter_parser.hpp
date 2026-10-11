#pragma once

#include "porsche/formatter_original.hpp"

namespace porsche {

// Entry at Porsche.exe:005a4371. Callback and cleanup bodies outside this
// packet remain explicit typed boundaries; the descriptor tail stays opaque.
int __cdecl formatter_parser_005a4371(
    FormatterOriginalDescriptor32* descriptor, const unsigned char* format,
    std::uint32_t* raw_va);

using FormatterFloatBoundary = void (__cdecl *)(const void*, char*, int, int, int);
using FormatterTextBoundary = void (__cdecl *)(char*);
using FormatterUnsigned64Boundary = std::uint64_t (__stdcall *)(std::uint64_t, std::uint64_t);
using FormatterLengthBoundary = int (__cdecl *)(const char*);

extern FormatterFloatBoundary formatter_float_boundary_005e5788;
extern FormatterTextBoundary formatter_float_post_005e5794;
extern FormatterTextBoundary formatter_float_post_005e578c;
extern FormatterUnsigned64Boundary formatter_unsigned_divide_boundary_005a67b0;
extern FormatterUnsigned64Boundary formatter_unsigned_remainder_boundary_005a6820;
extern FormatterLengthBoundary formatter_length_boundary_005a6730;
extern const char* formatter_null_narrow_005e57a0;
extern const unsigned short* formatter_null_wide_005e57a4;
// Original mutable pointer cell at 005e52d0. Runtime formatting tests the
// high bit in class_table[unsigned_byte * 2 + 1] for state-0 lead bytes.
extern const std::uint8_t* formatter_ctype_table_005e52d0;

// 005abf5e: original wide/multibyte encoder boundary.
int __cdecl formatter_wide_encode_boundary_005abf5e(char* destination,
                                                     std::uint32_t stack_value);

} // namespace porsche
