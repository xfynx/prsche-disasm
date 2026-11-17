// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0053a780..0053a7e4 (101B), 0053bf20..0053bf4d (46B), 004b0eb0..004b0ed6 (39B).
#include "render_display_finish_init_632.hpp"

#include "porsche/frame_pump.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/render_display.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_procedure.hpp"
#include "../628-render-window-initialize/render_window_initialize_628.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer layout");
static_assert(sizeof(WindowHandlerEntry) == 8, "original 8-byte handler entry");

std::uint32_t __stdcall window_handler_find_0053a780(std::uint32_t message) {
    if (class_lock_0069e59c == nullptr) {
        class_lock_0069e59c = heap_lock_create_005321f0();
    }
    heap_enter_005322b0(class_lock_0069e59c);

    WindowHandlerEntry key_pair{};
    key_pair.message = message;
    auto* const entry = static_cast<WindowHandlerEntry*>(original_binary_search_005a2f23(
        &key_pair,
        window_handlers_0069e0e0,
        window_handler_count_0069e570,
        sizeof(WindowHandlerEntry),
        &window_message_compare_0053a7f0));

    const std::uint32_t handler = entry != nullptr
        ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(entry->handler))
        : 0u;
    heap_leave_005322c0(class_lock_0069e59c);
    return handler;
}

void __cdecl window_keyboard_hook_disable_0053bf20() {
    if (window_fullscreen_006b7c01 != 0u && window_keyboard_hook_handle_0069e584 != nullptr) {
        (void)window_keys_unhook_windows_hook(window_keyboard_hook_handle_0069e584);
        window_keyboard_hook_handle_0069e584 = nullptr;
        window_keyboard_hook_enabled_0069e588 = 0u;
    }
}

void __cdecl render_display_finish_init_004b0eb0() {
    window_keyboard_hook_disable_0053bf20();

    std::uint8_t* const previous_handler_slot = frame_pump_storage_bytes_006573b8() + 0x24u;
    std::uint32_t previous_handler = 0u;
    std::memcpy(&previous_handler, previous_handler_slot, sizeof(previous_handler));
    if (previous_handler == 0u) {
        previous_handler = window_handler_find_0053a780(0x1cu);
        std::memcpy(previous_handler_slot, &previous_handler, sizeof(previous_handler));
        (void)window_handler_register_0053a800(
            0x1cu,
            static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(&render_display_activate_callback_004b0ee0)));
    }
}

} // namespace porsche
