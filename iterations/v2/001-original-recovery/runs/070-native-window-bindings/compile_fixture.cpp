#include "porsche/window_create.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/render_event_route.hpp"
#include <cstdint>
#include <type_traits>

using namespace porsche;
static_assert(std::is_same_v<decltype(&window_create_ex),
    void* (__stdcall*)(std::uint32_t,const char*,const char*,std::uint32_t,
        std::int32_t,std::int32_t,std::int32_t,std::int32_t,void*,void*,void*,void*)>);
static_assert(std::is_same_v<decltype(&window_register_class),
    std::uint16_t (__stdcall*)(const OriginalWndClassA*)>);
static_assert(std::is_same_v<decltype(&window_worker_get_message),
    std::int32_t (__stdcall*)(WindowWorkerMessage*,void*,std::uint32_t,std::uint32_t)>);
static_assert(std::is_same_v<decltype(&window_worker_dispatch_message),
    std::int32_t (__stdcall*)(const WindowWorkerMessage*)>);
static_assert(std::is_same_v<decltype(&window_keys_set_keyboard_hook),
    void* (__stdcall*)(std::uint32_t,WindowKeyboardHookCallback,void*,std::uint32_t)>);
static_assert(std::is_same_v<decltype(&window_message_begin_paint),
    std::uint32_t (__stdcall*)(void*,void*)>);
static_assert(std::is_same_v<decltype(&window_position_set_window_pos),
    std::uint32_t (__stdcall*)(void*,void*,std::int32_t,std::int32_t,
        std::int32_t,std::int32_t,std::uint32_t)>);
static_assert(std::is_same_v<decltype(&render_event_set_cursor_pos),
    std::int32_t (__stdcall*)(std::int32_t,std::int32_t)>);

int main() {
    using AnyFunction = void (*)();
    const AnyFunction bindings[]={
        reinterpret_cast<AnyFunction>(&window_get_system_metrics),
        reinterpret_cast<AnyFunction>(&window_adjust_rect),
        reinterpret_cast<AnyFunction>(&window_create_ex),
        reinterpret_cast<AnyFunction>(&window_set_cursor),
        reinterpret_cast<AnyFunction>(&window_show_cursor),
        reinterpret_cast<AnyFunction>(&window_system_parameters),
        reinterpret_cast<AnyFunction>(&window_set_foreground),
        reinterpret_cast<AnyFunction>(&window_module_handle),
        reinterpret_cast<AnyFunction>(&window_load_icon),
        reinterpret_cast<AnyFunction>(&window_load_cursor),
        reinterpret_cast<AnyFunction>(&window_stock_object),
        reinterpret_cast<AnyFunction>(&window_register_class),
        reinterpret_cast<AnyFunction>(&window_last_error),
        reinterpret_cast<AnyFunction>(&window_worker_get_client_rect),
        reinterpret_cast<AnyFunction>(&window_worker_client_to_screen),
        reinterpret_cast<AnyFunction>(&window_worker_get_message),
        reinterpret_cast<AnyFunction>(&window_worker_translate_message),
        reinterpret_cast<AnyFunction>(&window_worker_dispatch_message),
        reinterpret_cast<AnyFunction>(&window_worker_is_iconic),
        reinterpret_cast<AnyFunction>(&window_worker_show_cursor),
        reinterpret_cast<AnyFunction>(&window_worker_get_foreground_window),
        reinterpret_cast<AnyFunction>(&window_worker_set_foreground_window),
        reinterpret_cast<AnyFunction>(&window_worker_set_active_window),
        reinterpret_cast<AnyFunction>(&window_worker_destroy_window),
        reinterpret_cast<AnyFunction>(&window_handler_post_quit_message),
        reinterpret_cast<AnyFunction>(&window_message_get_client_rect),
        reinterpret_cast<AnyFunction>(&window_message_client_to_screen),
        reinterpret_cast<AnyFunction>(&window_message_begin_paint),
        reinterpret_cast<AnyFunction>(&window_message_end_paint),
        reinterpret_cast<AnyFunction>(&window_keys_get_async_key_state),
        reinterpret_cast<AnyFunction>(&window_keys_set_keyboard_hook),
        reinterpret_cast<AnyFunction>(&window_keys_unhook_windows_hook),
        reinterpret_cast<AnyFunction>(&window_keys_show_cursor),
        reinterpret_cast<AnyFunction>(&window_keys_def_window_proc),
        reinterpret_cast<AnyFunction>(&window_keys_call_next_hook),
        reinterpret_cast<AnyFunction>(&window_position_get_system_metrics),
        reinterpret_cast<AnyFunction>(&window_position_get_client_rect),
        reinterpret_cast<AnyFunction>(&window_position_get_window_long),
        reinterpret_cast<AnyFunction>(&window_position_adjust_window_rect_ex),
        reinterpret_cast<AnyFunction>(&window_position_system_parameters),
        reinterpret_cast<AnyFunction>(&window_position_set_window_pos),
        reinterpret_cast<AnyFunction>(&window_position_client_to_screen),
        reinterpret_cast<AnyFunction>(&window_position_unregister_class),
        reinterpret_cast<AnyFunction>(&window_default_procedure),
        reinterpret_cast<AnyFunction>(&render_event_set_cursor_pos),
        reinterpret_cast<AnyFunction>(&render_event_set_cursor),
    };
    return bindings[0] == nullptr;
}
