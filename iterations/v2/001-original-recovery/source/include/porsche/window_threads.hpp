#pragma once
#include <cstdint>
#include "porsche/file_threads.hpp"

namespace porsche {
// Keep the raw ABI declaration shared with window_create.hpp. Argument 4 is
// present in callers' cdecl frames but is not read by this machine-code body;
// argument 5 points to the caller's 28-byte ThreadRecord.
std::uint32_t __cdecl window_thread_start_0055f420(
    void* callback, std::uint32_t stack_and_priority, std::uint32_t priority,
    std::uint32_t unused4, std::uint32_t* output);
}
