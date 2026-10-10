#pragma once

#include <cstdint>

namespace porsche {

using ClockWorkerCallback = void (__cdecl *)();

// Newly assigned exact storage owners from the original BSS references.
extern ClockWorkerCallback clock_worker_callbacks_006b7c20[8];
extern std::uint32_t clock_worker_carry_006b7c44;
extern std::uint32_t clock_worker_iterations_006b7c7c;
extern void* clock_worker_event_006a5bfc;
extern std::uint32_t clock_worker_active_006a5c0c;

// 00565270 reads no stack arguments. Run110 records the caller's thread
// bootstrap setup separately; this declaration follows the indexed entry ABI.
std::uint32_t __cdecl clock_worker_00565270();

} // namespace porsche
