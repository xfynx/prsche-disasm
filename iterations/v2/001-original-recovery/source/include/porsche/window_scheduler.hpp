#pragma once

#include <cstdint>

#include "porsche/window_runtime.hpp"

namespace porsche {

// Unique original scalar at 0069de20, used while a schedule registration scans slots.
extern std::uint32_t window_scheduler_depth_0069de20;

// 00565340's address is held at 005debf0. Its diagnostic body remains an
// explicit game boundary; the address of the original message is preserved.
void __cdecl window_scheduler_diagnostic_00565340(const char* original_message);

// Original cdecl entries that write/delete the shared 0069dd20 callback table.
std::uint32_t __cdecl window_scheduler_register_005365e0(
    TimedCallback callback, std::uint32_t period, std::uint32_t initial_delay);
TimedCallbackSlot* __cdecl window_scheduler_remove_005366a0(TimedCallback callback);

}
