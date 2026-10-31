#pragma once
#include "porsche/application_audio_device.hpp"
#include "porsche/clock_worker.hpp"
#include "porsche/window_scheduler.hpp"
#include "porsche/window_support.hpp"
namespace porsche {
extern std::uint32_t audio_prepare_registered_006a5c34;
void __cdecl application_audio_prepare_00565950();
void __cdecl application_audio_wait_0053c380(std::int32_t interval);
// Same-address link alias for the accepted network caller's cdecl1void view.
void __cdecl network_lifecycle_wait_0053c380(std::int32_t interval);
std::uint32_t __cdecl audio_probe_clock_0053c2e0();
std::uint32_t __cdecl audio_probe_scheduler_callback_00565930(
    std::uint32_t argument,std::uint32_t elapsed);
// Original single RET: leaves incoming register/flag state untouched.
void __cdecl audio_probe_noop_00565940();
void __cdecl audio_probe_callbacks_0058ffd0();
}
