#include "porsche/auxiliary_wait.hpp"
#include "porsche/timer_setup.hpp"

#include <windows.h>
#include <mmsystem.h>

namespace porsche {

std::uint32_t __stdcall timer_get_device_caps_boundary(void* caps,
                                                        std::uint32_t size) {
    return static_cast<std::uint32_t>(timeGetDevCaps(
        static_cast<LPTIMECAPS>(caps), static_cast<UINT>(size)));
}

std::uint32_t __stdcall timer_begin_period_boundary(std::uint32_t period) {
    return static_cast<std::uint32_t>(timeBeginPeriod(static_cast<UINT>(period)));
}

std::uint32_t __stdcall timer_kill_event_boundary(std::uint32_t event_id) {
    return static_cast<std::uint32_t>(timeKillEvent(static_cast<UINT>(event_id)));
}

std::uint32_t __stdcall timer_set_event_boundary(std::uint32_t delay,
    std::uint32_t resolution, MultimediaTimerCallback callback,
    std::uint32_t user, std::uint32_t flags) {
    return static_cast<std::uint32_t>(timeSetEvent(
        static_cast<UINT>(delay), static_cast<UINT>(resolution),
        reinterpret_cast<LPTIMECALLBACK>(callback),
        static_cast<DWORD_PTR>(user), static_cast<UINT>(flags)));
}

std::uint32_t __stdcall timer_end_period_boundary(std::uint32_t period) {
    return static_cast<std::uint32_t>(timeEndPeriod(static_cast<UINT>(period)));
}

// The timer callback's tail calls the observed 0053c270 signal routine.
void __cdecl timer_auxiliary_wait_boundary() {
    auxiliary_wait_signal_0053c270();
}

} // namespace porsche
