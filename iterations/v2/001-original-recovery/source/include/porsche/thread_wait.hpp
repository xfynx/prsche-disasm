#pragma once

#include "porsche/file_threads.hpp"

#include <cstdint>

namespace porsche {

// Porsche.exe 0055fa10: waits for a registered thread record to disappear.
// The second DWORD is a timed wait interval; zero selects repeated polling.
std::uint32_t __cdecl thread_wait_0055fa10(ThreadRecord*, std::uint32_t);

} // namespace porsche
