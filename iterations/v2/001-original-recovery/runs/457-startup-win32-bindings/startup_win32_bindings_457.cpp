#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "porsche/application_instance.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_window.hpp"
#include "porsche/window_create.hpp"
#include "audio_capabilities_443.hpp"

static_assert(sizeof(void*)==4,"Original Win32 transport requires x86");
namespace porsche {
// Modern ABI adapters for original IAT calls; no original algorithm or state.
void* __cdecl application_instance_find_window(const char* cls,const char* title) {
    return ::FindWindowA(cls,title);
}
std::int32_t __cdecl application_instance_show_window(void* window,std::int32_t command) {
    return ::ShowWindow(static_cast<HWND>(window),command);
}
std::int32_t __cdecl application_instance_set_foreground_window(void* window) {
    return ::SetForegroundWindow(static_cast<HWND>(window));
}
std::uint32_t __cdecl render_get_desktop_005b2274() {
    return reinterpret_cast<std::uint32_t>(audio_platform_desktop_window());
}
std::uint32_t __cdecl render_get_window_dc_005b226c(std::uint32_t window) {
    return reinterpret_cast<std::uint32_t>(::GetWindowDC(reinterpret_cast<HWND>(window)));
}
std::int32_t __cdecl render_get_device_caps_005b2044(std::uint32_t dc,std::int32_t index) {
    return ::GetDeviceCaps(reinterpret_cast<HDC>(dc),index);
}
void __cdecl render_release_dc_005b2268(std::uint32_t window,std::uint32_t dc) {
    // Original 0046786d ignores the SDK's int return.
    ::ReleaseDC(reinterpret_cast<HWND>(window),reinterpret_cast<HDC>(dc));
}
void __cdecl render_message_box_005b2270(std::uint32_t window,const char* text,const char* title,std::uint32_t flags) {
    // Both original constructor callsites ignore MessageBoxA's int return.
    ::MessageBoxA(reinterpret_cast<HWND>(window),text,title,flags);
}
std::int32_t __stdcall render_window_show_cursor(std::int32_t show) {
    return window_show_cursor(show);
}
}
