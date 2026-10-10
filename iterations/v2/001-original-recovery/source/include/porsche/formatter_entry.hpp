#pragma once

#include <cstdint>

namespace porsche {

// Four DWORD descriptor built by original 005a0fbf at EBP-20h.
struct FormatterDescriptor005a0fbf {
    char* cursor;                 // +00: current write cursor
    std::int32_t remaining;       // +04: decremented after the core returns
    char* base;                   // +08: caller's destination
    std::uint32_t flags;          // +0c: initialized to 42h
};
static_assert(sizeof(FormatterDescriptor005a0fbf) == 16);

// Explicit unrecovered boundaries: the wrapper's algorithm is recovered;
// formatting and cleanup effects belong to these callees.
std::int32_t __cdecl formatter_core_005a4371(
    FormatterDescriptor005a0fbf* descriptor, const char* format,
    const std::uint32_t* raw_arguments);
void __cdecl formatter_cleanup_005a4259(
    std::uint32_t zero, FormatterDescriptor005a0fbf* descriptor);

// Canonical original caller ABI and a testable x86 raw-va adapter.
std::int32_t __cdecl formatter_entry_005a0fbf(
    char* output, const char* format, ...);
std::int32_t __cdecl formatter_entry_raw_005a0fbf(
    char* output, const char* format, const std::uint32_t* raw_arguments);

} // namespace porsche
