#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_scheduler.hpp"
#include "porsche/window_shutdown.hpp"

#include <cstdint>
#include <iostream>

namespace porsche {
TimedCallbackSlot timed_callbacks_0069dd20[16]{};
std::uint32_t last_callback_tick_0069de24 = 0;
std::uint32_t current_tick_006b7c40 = 0;
std::uint32_t diagnostic_count = 0;
std::uint32_t diagnostic_message = 0;

std::uint32_t boundary_events[4]{};
std::uint32_t boundary_values[4]{};
std::uint32_t boundary_event_count = 0;
std::uint32_t mutate_mode_after_close = 0xffffffffu;
std::uint32_t terminal_exit_code = 0xffffffffu;
std::uint32_t terminal_exit_count = 0;

void __cdecl window_scheduler_diagnostic_00565340(const char*) {}

std::uint32_t __stdcall window_shutdown_close_handle_006bd92c(void* handle) {
    boundary_events[boundary_event_count] = 1;
    boundary_values[boundary_event_count++] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle));
    if (mutate_mode_after_close != 0xffffffffu)
        window_shutdown_mode_005de630 = static_cast<std::uint8_t>(mutate_mode_after_close);
    return 1;
}

void __stdcall window_shutdown_display_callback_006bd9b0(std::uint32_t mode) {
    boundary_events[boundary_event_count] = 2;
    boundary_values[boundary_event_count++] = mode;
}

void __cdecl application_instance_exit_005a246e(std::uint32_t code) {
    boundary_events[boundary_event_count] = 3;
    boundary_values[boundary_event_count++] = code;
    terminal_exit_code = code;
    ++terminal_exit_count;
}
}

int main() {
    for (;;) {
        std::uint32_t mode, handle, mutate, fill_scalar, fill_vector, context, elapsed;
        if (!(std::cin >> mode >> handle >> mutate >> fill_scalar >> fill_vector >> context >> elapsed)) break;
        porsche::window_shutdown_handle_0069dd18 = reinterpret_cast<void*>(static_cast<std::uintptr_t>(handle));
        porsche::window_shutdown_state_005de64c = 0x11111111;
        porsche::window_shutdown_state_005de67c = 0x22222222;
        porsche::window_shutdown_state_005de6ac = 0x33333333;
        porsche::window_shutdown_source_005de65c = 0;
        porsche::window_shutdown_source_005de65d = 0;
        porsche::mutate_mode_after_close = mutate;
        porsche::boundary_event_count = 0;
        porsche::terminal_exit_code = 0xffffffffu;
        porsche::terminal_exit_count = 0;
        for (auto& value : porsche::window_shutdown_config_005de620) {
            std::cin >> value;
        }
        porsche::window_shutdown_mode_005de630 = static_cast<std::uint8_t>(mode);
        for (auto& slot : porsche::timed_callbacks_0069dd20) {
            std::uint32_t callback_bits;
            std::cin >> callback_bits >> slot.period >> slot.next_tick >> slot.active;
            if (callback_bits == 0x0053bae0u)
                slot.callback = &porsche::window_shutdown_callback_0053bae0;
            else
                slot.callback = reinterpret_cast<porsche::TimedCallback>(static_cast<std::uintptr_t>(callback_bits));
        }
        (void)fill_scalar;
        (void)fill_vector; // Original 0053c290 selects scalar/MMX/SSE by these state words.
        const auto result = porsche::window_shutdown_callback_0053bae0(context, elapsed);
        std::cout << result << ' ' << porsche::terminal_exit_code << ' '
            << porsche::terminal_exit_count << ' ' << porsche::boundary_event_count;
        for (std::uint32_t i = 0; i < porsche::boundary_event_count; ++i)
            std::cout << ' ' << porsche::boundary_events[i] << ' ' << porsche::boundary_values[i];
        std::cout << ' ' << static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
            porsche::window_shutdown_handle_0069dd18))
            << ' ' << static_cast<std::uint32_t>(porsche::window_shutdown_mode_005de630)
            << ' ' << porsche::window_shutdown_state_005de64c
            << ' ' << porsche::window_shutdown_state_005de67c
            << ' ' << porsche::window_shutdown_state_005de6ac;
        for (const auto value : porsche::window_shutdown_config_005de620)
            std::cout << ' ' << value;
        for (const auto& slot : porsche::timed_callbacks_0069dd20) {
            auto bits = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(slot.callback));
            if (bits == static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
                    &porsche::window_shutdown_callback_0053bae0))) bits = 0x0053bae0u;
            std::cout << ' ' << bits << ' ' << slot.period << ' ' << slot.next_tick << ' ' << slot.active;
        }
        std::cout << '\n';
    }
}
