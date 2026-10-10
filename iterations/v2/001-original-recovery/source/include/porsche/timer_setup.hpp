#pragma once

#include "porsche/file_threads.hpp"

#include <cstdint>

namespace porsche {

using MultimediaTimerCallback = void (__stdcall *)(std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t);

// Exact unique timer state written by 00565030/00564fa0/00564eb0.
extern std::uint32_t timer_setup_interval_006a5bf8;
extern std::uint32_t timer_setup_fraction_006a5c00;
extern std::uint32_t timer_setup_clock_006a5c04;
extern std::uint32_t timer_setup_period_006a5c08;
extern std::uint32_t timer_setup_event_id_006a5c10;
extern std::uint32_t timer_setup_correction_count_006a5c1c;
extern std::uint32_t timer_setup_saved_clock_006a5c20;
// 00565030 passes this persistent 28-byte record to 0055f420 at 006b7c60.
extern ThreadRecord timer_setup_thread_record_006b7c60;

// Platform/game boundaries reached by the bounded timer setup cluster.
std::uint32_t __stdcall timer_get_device_caps_boundary(void* caps, std::uint32_t size);
std::uint32_t __stdcall timer_begin_period_boundary(std::uint32_t period);
std::uint32_t __stdcall timer_kill_event_boundary(std::uint32_t event_id);
std::uint32_t __stdcall timer_set_event_boundary(std::uint32_t delay,
    std::uint32_t resolution, MultimediaTimerCallback callback,
    std::uint32_t user, std::uint32_t flags);
std::uint32_t __stdcall timer_end_period_boundary(std::uint32_t period);
void __cdecl timer_diagnostic_boundary(const char* message, ...);
void __cdecl timer_auxiliary_wait_boundary();

// 00564eb0 is passed directly to WinMM timeSetEvent and also called by setup.
void __stdcall timer_producer_00564eb0(std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t);
void __cdecl timer_cleanup_00564fa0();
void __cdecl timer_setup_00565030(std::uint32_t interval);

} // namespace porsche
