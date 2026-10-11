#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_parser.hpp"

namespace porsche {

std::int32_t __cdecl formatter_core_005a4371(
    FormatterDescriptor005a0fbf* descriptor, const char* format,
    const std::uint32_t* raw_arguments) {
    return formatter_parser_005a4371(
        descriptor, reinterpret_cast<const unsigned char*>(format),
        const_cast<std::uint32_t*>(raw_arguments));
}

} // namespace porsche
