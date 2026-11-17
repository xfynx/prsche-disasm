// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005757f0..00575809 (26B), 00575810..00575818 (9B), 00575820..0057592d (270B).
#include "render_window_initialize_628.hpp"

#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_scheduler.hpp"
#include "../528-render-library-lifecycle/render_library_lifecycle_528.hpp"
#include "../626-diagnostic-abort-handler/diagnostic_abort_handler_626.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 callback table layout");

RenderWindowCallbackEntry render_window_callbacks_005e1960[8] = {
    reinterpret_cast<RenderWindowCallbackEntry>(&render_window_callback_005756d0),
    reinterpret_cast<RenderWindowCallbackEntry>(&startup_window_handle_00557460),
    reinterpret_cast<RenderWindowCallbackEntry>(&window_handler_register_0053a800),
    reinterpret_cast<RenderWindowCallbackEntry>(&window_handler_find_0053a780),
    reinterpret_cast<RenderWindowCallbackEntry>(&render_window_callback_005756e0),
    reinterpret_cast<RenderWindowCallbackEntry>(&render_window_callback_00575730),
    reinterpret_cast<RenderWindowCallbackEntry>(&render_window_callback_00575770),
    reinterpret_cast<RenderWindowCallbackEntry>(&render_window_callback_005757d0),
};

std::uint32_t render_window_exit_registered_006a64bc = 0u;

namespace {

using ThrashSetState = std::uint32_t(__stdcall*)(std::uint32_t key, std::uint32_t value);
using ThrashInit = std::uint32_t(__stdcall*)();

std::uint32_t thrash_set_state(std::uint32_t key, std::uint32_t value) {
    return reinterpret_cast<ThrashSetState>(render_thrash_exports_006bd910[27])(key, value);
}

} // namespace

std::uint32_t __cdecl render_window_abort_cleanup_005757f0() {
    (void)render_initialize_shutdown_00575930(1u);
    diagnostic_abort_cleanup_005deb8c = 0u;
    return 1u;
}

void __cdecl render_window_exit_cleanup_00575810() {
    (void)render_initialize_shutdown_00575930(1u);
}

std::uint32_t __cdecl render_initialize_window_00575820(std::uint32_t first) {
    if (render_display_texture_width_005deac8 == 0u) {
        render_display_texture_width_005deac8 = 0x280u;
    }
    if (render_display_texture_height_005deacc == 0u) {
        render_display_texture_height_005deacc = 0x1e0u;
    }
    if (thread_start_lock_006a57d8 == nullptr) {
        thread_start_lock_006a57d8 = heap_lock_create_005321f0();
    }
    if (first != 0u && window_hwnd_006b7bf8 != nullptr) {
        window_prepare_0053bcb0();
    }
    if (window_hwnd_006b7bf8 == nullptr) {
        if (window_init_0053ac20(
                render_display_texture_width_005deac8,
                render_display_texture_height_005deacc,
                first == 0u ? 1u : 0u) == 0u) {
            return render_library_started_006a64b8;
        }
    }

    (void)thrash_set_state(0x12u, first);
    (void)thrash_set_state(
        0x19u,
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(startup_window_handle_00557460())));
    (void)thrash_set_state(
        0x13u,
        static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(render_window_callbacks_005e1960)));

    render_library_started_006a64b8 =
        reinterpret_cast<ThrashInit>(render_thrash_exports_006bd910[19])();
    if (render_library_started_006a64b8 == 0u) {
        window_prepare_0053bcb0();
        return render_library_started_006a64b8;
    }

    if (thrash_set_state(0x25u, 0u) != 0u) {
        (void)window_scheduler_register_005365e0(&render_library_disable_state_005756c0, 1u, 1u);
    }
    if (render_window_exit_registered_006a64bc == 0u) {
        thread_exit_register_00557380(&render_window_exit_cleanup_00575810);
        render_window_exit_registered_006a64bc = 1u;
    }

    const std::uint32_t started = render_library_started_006a64b8;
    diagnostic_abort_cleanup_005deb8c = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(&render_window_abort_cleanup_005757f0));
    return started;
}

} // namespace porsche
