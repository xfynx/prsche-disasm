#pragma once
#include "porsche/file_worker.hpp"
namespace porsche {
// Retained thread identity, callback pump and sleep boundaries.
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t);
std::uint32_t __cdecl file_pump_005366e0(std::uint32_t);
void __cdecl file_sleep_0055f740(std::uint32_t);
}
