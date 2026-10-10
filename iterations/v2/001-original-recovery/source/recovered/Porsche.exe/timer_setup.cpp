#include "porsche/timer_setup.hpp"

#include "porsche/clock_worker.hpp"
#include "porsche/file_events.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/object_update.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_create.hpp"

#include <cstdint>

namespace porsche {

std::uint32_t timer_setup_interval_006a5bf8 = 0;
std::uint32_t timer_setup_fraction_006a5c00 = 0;
std::uint32_t timer_setup_clock_006a5c04 = 0;
std::uint32_t timer_setup_period_006a5c08 = 0;
std::uint32_t timer_setup_event_id_006a5c10 = 0;
std::uint32_t timer_setup_correction_count_006a5c1c = 0;
std::uint32_t timer_setup_saved_clock_006a5c20 = 0;
ThreadRecord timer_setup_thread_record_006b7c60{};

namespace {
constexpr std::uint32_t kTimerScale = 0x03e80000;
constexpr std::uint32_t kTimerLimit = 0x00010000;

void report_timer_error(const char* message, std::uint32_t id,
    const char* source) {
    diagnostic_file_005deb74_set(source);
    application_diagnostic_line_005deb78 = id;
    timer_diagnostic_boundary(message);
}

std::uint32_t signed_less(std::uint32_t left, std::uint32_t right) noexcept {
    return static_cast<std::int32_t>(left) < static_cast<std::int32_t>(right);
}
} // namespace

void __stdcall timer_producer_00564eb0(std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t) {
    const std::uint32_t phase = timer_setup_interval_006a5bf8 +
        timer_setup_fraction_006a5c00;
    std::uint32_t clock = timer_setup_clock_006a5c04 +
        static_cast<std::uint32_t>(static_cast<std::int32_t>(phase) >> 16);
    timer_setup_fraction_006a5c00 = phase & 0xffffu;
    timer_setup_clock_006a5c04 = clock;

    if (clock_worker_active_006a5c0c != 0) {
        const std::uint32_t now = platform_get_tick_count();
        std::uint32_t delta = clock - now - 1u;
        std::uint32_t delay = delta;
        if (!signed_less(delta, 1u)) {
            // Original signed JGE takes this path for delta >= 1.
        } else if (!signed_less(delta, 0xfffffc18u)) {
            // Original signed JGE also skips correction for delta >= -1000.
            delay = 1;
        } else {
            clock = platform_get_tick_count() + 1u;
            timer_setup_clock_006a5c04 = clock;
            ++timer_setup_correction_count_006a5c1c;
            delay = 1;
        }

        const std::uint32_t event_id = timer_set_event_boundary(
            delay, timer_setup_period_006a5c08,
            timer_producer_00564eb0, 0, 0);
        timer_setup_event_id_006a5c10 = event_id;
        if (event_id == 0) {
            timer_rate_005deb48 = 0;
            clock_worker_active_006a5c0c = 0;
            (void)timer_end_period_boundary(timer_setup_period_006a5c08);
        }
    }

    if (clock_worker_event_006a5bfc != nullptr &&
        timer_setup_saved_clock_006a5c20 == 0) {
        (void)file_event_signal_0055fb30(clock_worker_event_006a5bfc);
    }
    timer_auxiliary_wait_boundary();
}

void __cdecl timer_cleanup_00564fa0() {
    if (clock_worker_active_006a5c0c != 0) {
        timer_rate_005deb48 = 0;
        clock_worker_active_006a5c0c = 0;
        if (timer_setup_event_id_006a5c10 != 0)
            (void)timer_kill_event_boundary(timer_setup_event_id_006a5c10);
        (void)timer_end_period_boundary(timer_setup_period_006a5c08);
        if (clock_worker_event_006a5bfc != nullptr)
            (void)file_event_signal_0055fb30(clock_worker_event_006a5bfc);

        if (timer_setup_event_id_006a5c10 != 0 &&
            clock_worker_event_006a5bfc != nullptr) {
            do {
                window_idle_0055f740(1);
            } while (timer_setup_event_id_006a5c10 != 0 &&
                clock_worker_event_006a5bfc != nullptr);
        }
    }
    timer_setup_fraction_006a5c00 = 0;
    timer_setup_saved_clock_006a5c20 = 0;
    timer_setup_period_006a5c08 = 0;
    timer_setup_event_id_006a5c10 = 0;
}

void __cdecl timer_setup_00565030(std::uint32_t requested_interval) {
    timer_cleanup_00564fa0();

    std::uint32_t interval = requested_interval;
    const char* source = "\\real\\pc\\inittmr.c";
    if (interval == 0) {
        interval = 100;
    } else if (interval < 1 || interval > 10000) {
        diagnostic_file_005deb74_set(source);
        application_diagnostic_line_005deb78 = 0x106;
        timer_diagnostic_boundary(
            "TIMER_init - BAD TIMER FREQUENCY SPECIFIED %d\n", interval);
        interval = 100;
    }

    timer_setup_fraction_006a5c00 = 0;
    timer_setup_interval_006a5bf8 = kTimerScale / interval;
    clock_worker_iterations_006b7c7c = 0;
    clock_worker_carry_006b7c44 = 0;

    std::uint32_t caps[2]{};
    if (timer_get_device_caps_boundary(caps, sizeof(caps)) != 0) {
        report_timer_error("TIMER_init - MULTIMEDIA TIMER NOT FOUND.\n", 0x114,
            source);
        timer_rate_005deb48 = 0;
        clock_worker_active_006a5c0c = 0;
        return;
    }

    caps[0] = 1;
    caps[1] = 1;
    timer_setup_period_006a5c08 = 1;
    if (timer_setup_interval_006a5bf8 < kTimerLimit) {
        report_timer_error("TIMER_init - MULTIMEDIA TIMER CANNOT SUPPORT THIS FREQUENCY.\n", 0x122,
            "\\real\\pc\\inittmr.c");
        timer_rate_005deb48 = 0;
        clock_worker_active_006a5c0c = 0;
        return;
    }

    if (window_thread_start_0055f420(
            reinterpret_cast<void*>(clock_worker_00565270), 0, 2,
            0xffffffffu, reinterpret_cast<std::uint32_t*>(
                &timer_setup_thread_record_006b7c60)) == 0) {
        report_timer_error("TIMER_init - FAILED TO CREATE TIMER THREAD.\n", 0x12b,
            "\\real\\pc\\inittmr.c");
        timer_rate_005deb48 = 0;
        clock_worker_active_006a5c0c = 0;
        return;
    }

    if (timer_begin_period_boundary(timer_setup_period_006a5c08) != 0) {
        timer_rate_005deb48 = 0;
        clock_worker_active_006a5c0c = 0;
        (void)file_event_signal_0055fb30(clock_worker_event_006a5bfc);
        report_timer_error("TIMER_init - FAILED TO INITIALIZE MULTIMEDIA TIMER.\n", 0x134,
            "\\real\\pc\\inittmr.c");
        return;
    }

    thread_exit_register_00557380(timer_cleanup_00564fa0);
    timer_rate_005deb48 = interval;
    clock_worker_active_006a5c0c = interval;

    if (interval != 0 && timer_setup_event_id_006a5c10 == 0) {
        const std::uint32_t saved = timer_setup_saved_clock_006a5c20;
        timer_setup_saved_clock_006a5c20 = 1;
        timer_setup_clock_006a5c04 = platform_get_tick_count();
        timer_producer_00564eb0(0, 0, 0, 0, 0);
        timer_setup_saved_clock_006a5c20 = saved;
    }

    const std::uint32_t iterations = clock_worker_iterations_006b7c7c;
    const std::uint32_t deadline = platform_get_tick_count() +
        timer_rate_005deb48 * 5u;
    std::uint32_t tick = platform_get_tick_count();
    while (signed_less(tick, deadline) &&
        iterations == clock_worker_iterations_006b7c7c) {
        window_idle_0055f740(1);
        tick = platform_get_tick_count();
    }
    if (iterations == clock_worker_iterations_006b7c7c)
        timer_cleanup_00564fa0();
    if (timer_rate_005deb48 == 0)
        report_timer_error("TIMER_init - FAILED TO INITIALIZE WINDOWS MULTIMEDIA TIMER, TRY RE-RUNNING.\n", 0x157,
            "\\real\\pc\\inittmr.c");
}

} // namespace porsche
