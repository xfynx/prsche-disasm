#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include "porsche/window_create.hpp"
#include "porsche/window_channels.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/render_event_route.hpp"

#include <cstdint>

static_assert(sizeof(void*) == 4, "Win32 window bindings require x86");
static_assert(sizeof(porsche::WindowRect) == sizeof(RECT));
static_assert(sizeof(porsche::WindowWorkerRect) == sizeof(RECT));
static_assert(sizeof(porsche::WindowMessageRect) == sizeof(RECT));
static_assert(sizeof(porsche::WindowPositionRect) == sizeof(RECT));
static_assert(sizeof(porsche::WindowPositionPoint) == sizeof(POINT));
static_assert(sizeof(porsche::WindowWorkerMessage) == sizeof(MSG));
static_assert(sizeof(porsche::OriginalWndClassA) == sizeof(WNDCLASSA));

namespace porsche {
namespace {
BOOL adjust_rect(RECT* rect, DWORD style, BOOL has_menu, DWORD exstyle) {
    return ::AdjustWindowRectEx(rect, style, has_menu, exstyle);
}
BOOL get_client_rect(HWND hwnd, RECT* rect) {
    return ::GetClientRect(hwnd, rect);
}
BOOL client_to_screen(HWND hwnd, POINT* point) {
    return ::ClientToScreen(hwnd, point);
}
int show_cursor(BOOL visible) {
    return ::ShowCursor(visible);
}
HCURSOR set_cursor(HCURSOR cursor) {
    return ::SetCursor(cursor);
}
BOOL set_foreground_window(HWND hwnd) {
    return ::SetForegroundWindow(hwnd);
}
BOOL system_parameters(UINT action, UINT parameter, PVOID data, UINT flags) {
    return ::SystemParametersInfoA(action, parameter, data, flags);
}
}

// window_channels.hpp: USER32 imports used by the recovered 005739b0 body.
std::int16_t __stdcall window_channels_get_key_state(std::int32_t virtual_key) {
    return ::GetKeyState(virtual_key);
}
void __stdcall window_channels_keybd_event(std::uint8_t virtual_key,
    std::uint8_t scan_code, std::uint32_t flags, std::uint32_t extra_info) {
    ::keybd_event(virtual_key, scan_code, flags, static_cast<ULONG_PTR>(extra_info));
}

// window_create.hpp: exact x86 wrappers for the calls made by 0053bb00.
std::int32_t __stdcall window_get_system_metrics(std::int32_t index) {
    return ::GetSystemMetrics(index);
}
std::uint32_t __stdcall window_adjust_rect(WindowRect* rect, std::uint32_t style,
                                           std::int32_t has_menu, std::uint32_t exstyle) {
    return static_cast<std::uint32_t>(adjust_rect(reinterpret_cast<RECT*>(rect),
        style, has_menu, exstyle));
}
void* __stdcall window_create_ex(std::uint32_t exstyle, const char* class_name,
    const char* window_name, std::uint32_t style, std::int32_t x, std::int32_t y,
    std::int32_t width, std::int32_t height, void* parent, void* menu,
    void* instance, void* parameter) {
    return ::CreateWindowExA(exstyle, class_name, window_name, style, x, y,
        width, height, static_cast<HWND>(parent), static_cast<HMENU>(menu),
        static_cast<HINSTANCE>(instance), parameter);
}
void* __stdcall window_set_cursor(void* cursor) {
    return set_cursor(static_cast<HCURSOR>(cursor));
}
std::int32_t __stdcall window_show_cursor(std::int32_t visible) {
    return show_cursor(visible);
}
std::uint32_t __stdcall window_system_parameters(std::uint32_t action,
    std::uint32_t parameter, void* data, std::uint32_t flags) {
    return static_cast<std::uint32_t>(system_parameters(action, parameter, data, flags));
}
void* __stdcall window_set_foreground(void* hwnd) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(
        set_foreground_window(static_cast<HWND>(hwnd))));
}

// window_create.hpp: exact class-registration and module/resource calls.
void* __stdcall window_module_handle(const char* module_name) {
    return ::GetModuleHandleA(module_name);
}
void* __stdcall window_load_icon(void* instance, const char* resource_name) {
    return ::LoadIconA(static_cast<HINSTANCE>(instance), resource_name);
}
void* __stdcall window_load_cursor(void* instance, const char* resource_name) {
    return ::LoadCursorA(static_cast<HINSTANCE>(instance), resource_name);
}
void* __stdcall window_stock_object(std::int32_t object) {
    return ::GetStockObject(object);
}
std::uint16_t __stdcall window_register_class(const OriginalWndClassA* window_class) {
    return ::RegisterClassA(reinterpret_cast<const WNDCLASSA*>(window_class));
}
std::uint32_t __stdcall window_last_error() {
    return ::GetLastError();
}

// window_worker.hpp: message-loop and foreground/activation API bindings.
std::uint32_t __stdcall window_worker_get_client_rect(void* hwnd,
                                                       WindowWorkerRect* rect) {
    return static_cast<std::uint32_t>(get_client_rect(static_cast<HWND>(hwnd),
        reinterpret_cast<RECT*>(rect)));
}
std::uint32_t __stdcall window_worker_client_to_screen(void* hwnd,
                                                        WindowWorkerRect* rect) {
    return static_cast<std::uint32_t>(client_to_screen(static_cast<HWND>(hwnd),
        reinterpret_cast<POINT*>(rect)));
}
std::int32_t __stdcall window_worker_get_message(WindowWorkerMessage* message,
    void* hwnd, std::uint32_t minimum, std::uint32_t maximum) {
    return ::GetMessageA(reinterpret_cast<MSG*>(message), static_cast<HWND>(hwnd),
        minimum, maximum);
}
std::uint32_t __stdcall window_worker_translate_message(const WindowWorkerMessage* message) {
    return static_cast<std::uint32_t>(::TranslateMessage(
        reinterpret_cast<const MSG*>(message)));
}
std::int32_t __stdcall window_worker_dispatch_message(const WindowWorkerMessage* message) {
    return static_cast<std::int32_t>(::DispatchMessageA(
        reinterpret_cast<const MSG*>(message)));
}
std::int32_t __stdcall window_worker_is_iconic(void* hwnd) {
    return ::IsIconic(static_cast<HWND>(hwnd));
}
std::int32_t __stdcall window_worker_show_cursor(std::int32_t visible) {
    return show_cursor(visible);
}
void* __stdcall window_worker_get_foreground_window() {
    return ::GetForegroundWindow();
}
void* __stdcall window_worker_set_foreground_window(void* hwnd) {
    // Existing adapter declares void* although USER32 returns BOOL. Preserve
    // the original 32-bit EAX value used by consumers as an integer result.
    const auto result = set_foreground_window(static_cast<HWND>(hwnd));
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(result));
}
void* __stdcall window_worker_set_active_window(void* hwnd) {
    return ::SetActiveWindow(static_cast<HWND>(hwnd));
}
std::uint32_t __stdcall window_worker_destroy_window(void* hwnd) {
    return static_cast<std::uint32_t>(::DestroyWindow(static_cast<HWND>(hwnd)));
}

// window_handlers.hpp.
void __stdcall window_handler_post_quit_message(std::uint32_t exit_code) {
    ::PostQuitMessage(static_cast<int>(exit_code));
}

// window_messages.hpp. BeginPaint's HDC is returned in the declared 32-bit
// adapter result; EndPaint retains the native BOOL result.
std::uint32_t __stdcall window_message_get_client_rect(void* hwnd,
                                                        WindowMessageRect* rect) {
    return static_cast<std::uint32_t>(get_client_rect(static_cast<HWND>(hwnd),
        reinterpret_cast<RECT*>(rect)));
}
std::uint32_t __stdcall window_message_client_to_screen(void* hwnd,
                                                         WindowMessageRect* rect) {
    return static_cast<std::uint32_t>(client_to_screen(static_cast<HWND>(hwnd),
        reinterpret_cast<POINT*>(rect)));
}
std::uint32_t __stdcall window_message_begin_paint(void* hwnd, void* paint) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        ::BeginPaint(static_cast<HWND>(hwnd), static_cast<PAINTSTRUCT*>(paint))));
}
std::uint32_t __stdcall window_message_end_paint(void* hwnd, void* paint) {
    return static_cast<std::uint32_t>(::EndPaint(static_cast<HWND>(hwnd),
        static_cast<const PAINTSTRUCT*>(paint)));
}

// window_keys.hpp.
std::int16_t __stdcall window_keys_get_async_key_state(std::uint32_t key) {
    return ::GetAsyncKeyState(static_cast<int>(key));
}
void* __stdcall window_keys_set_keyboard_hook(std::uint32_t hook_id,
    WindowKeyboardHookCallback callback, void* module, std::uint32_t thread_id) {
    return ::SetWindowsHookExA(static_cast<int>(hook_id),
        reinterpret_cast<HOOKPROC>(callback), static_cast<HINSTANCE>(module), thread_id);
}
std::int32_t __stdcall window_keys_unhook_windows_hook(void* hook) {
    return ::UnhookWindowsHookEx(static_cast<HHOOK>(hook));
}
std::int32_t __stdcall window_keys_show_cursor(std::int32_t visible) {
    return show_cursor(visible);
}
std::int32_t __stdcall window_keys_def_window_proc(void* hwnd, std::uint32_t message,
    std::uint32_t wparam, std::int32_t lparam) {
    return static_cast<std::int32_t>(::DefWindowProcA(static_cast<HWND>(hwnd),
        message, wparam, lparam));
}
std::int32_t __stdcall window_keys_call_next_hook(void* hook, std::int32_t code,
    std::uint32_t wparam, std::int32_t lparam) {
    return static_cast<std::int32_t>(::CallNextHookEx(static_cast<HHOOK>(hook),
        code, wparam, lparam));
}

// window_procedure.hpp exposes the original default procedure as a platform edge.
std::int32_t __stdcall window_default_procedure(void* hwnd, std::uint32_t message,
    std::uint32_t wparam, std::int32_t lparam) {
    return static_cast<std::int32_t>(::DefWindowProcA(static_cast<HWND>(hwnd),
        message, wparam, lparam));
}

// window_position.hpp.
std::int32_t __stdcall window_position_get_system_metrics(std::int32_t index) {
    return ::GetSystemMetrics(index);
}
std::uint32_t __stdcall window_position_get_client_rect(void* hwnd,
                                                         WindowPositionRect* rect) {
    return static_cast<std::uint32_t>(get_client_rect(static_cast<HWND>(hwnd),
        reinterpret_cast<RECT*>(rect)));
}
std::int32_t __stdcall window_position_get_window_long(void* hwnd, std::int32_t index) {
    return ::GetWindowLongA(static_cast<HWND>(hwnd), index);
}
std::uint32_t __stdcall window_position_adjust_window_rect_ex(WindowPositionRect* rect,
    std::uint32_t style, std::int32_t has_menu, std::uint32_t exstyle) {
    return static_cast<std::uint32_t>(adjust_rect(reinterpret_cast<RECT*>(rect),
        style, has_menu, exstyle));
}
std::uint32_t __stdcall window_position_system_parameters(std::uint32_t action,
    std::uint32_t parameter, void* data, std::uint32_t flags) {
    return static_cast<std::uint32_t>(system_parameters(action, parameter, data, flags));
}
std::uint32_t __stdcall window_position_set_window_pos(void* hwnd, void* insert_after,
    std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height,
    std::uint32_t flags) {
    return static_cast<std::uint32_t>(::SetWindowPos(static_cast<HWND>(hwnd),
        static_cast<HWND>(insert_after), x, y, width, height, flags));
}
std::uint32_t __stdcall window_position_client_to_screen(void* hwnd,
                                                          WindowPositionPoint* point) {
    return static_cast<std::uint32_t>(client_to_screen(static_cast<HWND>(hwnd),
        reinterpret_cast<POINT*>(point)));
}
std::uint32_t __stdcall window_position_unregister_class(const char* class_name,
                                                          void* instance) {
    return static_cast<std::uint32_t>(::UnregisterClassA(class_name,
        static_cast<HINSTANCE>(instance)));
}

// render_event_route.hpp.
std::int32_t __stdcall render_event_set_cursor_pos(std::int32_t x, std::int32_t y) {
    return ::SetCursorPos(x, y);
}
void* __stdcall render_event_set_cursor(void* cursor) {
    return set_cursor(static_cast<HCURSOR>(cursor));
}

}
