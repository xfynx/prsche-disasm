#pragma once

#include "porsche/formatter_original.hpp"
#include "porsche/formatter_cleanup.hpp"

#include <cstdint>

namespace porsche {

// Original005a0fbf reserves32 bytes and initializes only the four prefix DWORDs.
using FormatterDescriptor005a0fbf = FormatterOriginalDescriptor32;

// Canonical parser binding is provided by formatter_parser_entry_bridge.cpp.
// Cleanup uses the shared32-byte descriptor and its recovered body.
std::int32_t __cdecl formatter_core_005a4371(
    FormatterDescriptor005a0fbf* descriptor, const char* format,
    const std::uint32_t* raw_arguments);

// Canonical original caller ABI and a testable x86 raw-va adapter.
std::int32_t __cdecl formatter_entry_005a0fbf(
    char* output, const char* format, ...);
std::int32_t __cdecl formatter_entry_raw_005a0fbf(
    char* output, const char* format, const std::uint32_t* raw_arguments);

} // namespace porsche
