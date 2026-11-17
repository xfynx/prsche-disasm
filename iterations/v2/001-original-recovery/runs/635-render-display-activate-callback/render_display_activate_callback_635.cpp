// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005360d0..005360d5 (6B) and 004b0ee0..004b0f99 (186B).
#include "render_display_activate_callback_635.hpp"

#include "../570-startup-service-bindings/startup_service_570.hpp"
#include "porsche/frame_pump.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_window.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_procedure.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer layout");

std::uint8_t __fastcall startup_service_active_get_005360d0(void* self) {
    (void)self;
    return startup_service_active_0069dd1e;
}

std::uint32_t __stdcall render_display_activate_callback_004b0ee0(
    void* configuration,
    void* hwnd,
    std::uint32_t message,
    std::uint32_t wparam,
    std::int32_t lparam,
    std::int32_t* result) {
    if (configuration != nullptr && startup_window_handle_00557460() == hwnd && hwnd != nullptr) {
        if (wparam != 0u) {
            frame_pump_byte_006573e0 = 0u;
            while (render_window_show_cursor(0) >= 0) {
            }
        } else if (frame_pump_byte_006573e0 == 0u) {
            if (game_setup_movie_service_0069ed0c != nullptr) {
                void* frame_object = nullptr;
                std::memcpy(
                    &frame_object,
                    static_cast<const std::uint8_t*>(game_setup_movie_service_0069ed0c) + 4u,
                    sizeof(frame_object));
                if (frame_object != nullptr) {
                    frame_pump_storage_bytes_006573b8()[0x2bu] =
                        startup_service_active_get_005360d0(frame_object);
                    frame_pump_boundary_005360a0(frame_object, 0u);
                }
            }
            frame_pump_byte_006573e0 = 1u;
            frame_pump_byte_006573e1 = 1u;
            frame_pump_byte_006573e2 = 0u;
        }
    }

    *result = 0;

    WindowHandler previous_handler = nullptr;
    std::memcpy(
        &previous_handler,
        frame_pump_storage_bytes_006573b8() + 0x24u,
        sizeof(previous_handler));
    if (previous_handler != nullptr) {
        return previous_handler(configuration, hwnd, message, wparam, lparam, result);
    }
    return 0u;
}

} // namespace porsche
