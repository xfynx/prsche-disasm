#pragma once
#include "porsche/file_worker.hpp"
namespace porsche {
// Thread identity/callback pump remain open; sleep wrapper preserves the OS result.
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t);
std::uint32_t __cdecl file_pump_005366e0(std::uint32_t);
std::uint32_t __cdecl file_sleep_0055f740(std::uint32_t);
}
