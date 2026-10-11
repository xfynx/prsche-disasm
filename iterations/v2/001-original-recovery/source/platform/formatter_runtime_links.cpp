#include "porsche/formatter_parser.hpp"
#include "porsche/formatter_runtime.hpp"

#include <cstring>

namespace porsche {
namespace {
int __cdecl length_result_bits(const char* text) {
    const auto bits = formatter_strlen_005a6730(text);
    int result;
    static_assert(sizeof(result) == sizeof(bits));
    std::memcpy(&result, &bits, sizeof(result));
    return result;
}
} // namespace

// Native seams for original direct calls. These are not original data cells.
FormatterUnsigned64Boundary formatter_unsigned_divide_boundary_005a67b0 =
    formatter_unsigned_divide_005a67b0;
FormatterUnsigned64Boundary formatter_unsigned_remainder_boundary_005a6820 =
    formatter_unsigned_remainder_005a6820;
FormatterLengthBoundary formatter_length_boundary_005a6730 = length_result_bits;
} // namespace porsche
