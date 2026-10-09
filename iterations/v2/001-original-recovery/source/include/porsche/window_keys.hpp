#pragma once
#include <cstdint>
#include "porsche/window_messages.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {
using WindowKeyboardHookCallback=std::int32_t(__stdcall*)(std::int32_t,std::uint32_t,std::int32_t);
using WindowHotkeyDispatch=std::uint32_t(__cdecl*)(std::uint32_t,std::uint32_t);

// State observed in the original keyboard-hook consumers; each VA has one owner.
extern void* window_keyboard_hook_handle_0069e584;
extern std::uint32_t window_keyboard_hook_enabled_0069e588;
extern std::uint32_t window_keyboard_hook_filter_0069e58c;
extern WindowHotkeyDispatch window_hotkey_dispatch_0069e590;
extern std::uint32_t window_activation_seen_0069e5ac;
extern std::uint32_t window_key_virtual_code_006bd9fc;

// Win32/input-engine boundaries; implementations are supplied by platform binding.
std::int16_t __stdcall window_keys_get_async_key_state(std::uint32_t);
void* __stdcall window_keys_set_keyboard_hook(std::uint32_t,WindowKeyboardHookCallback,void*,std::uint32_t);
std::int32_t __stdcall window_keys_unhook_windows_hook(void*);
std::int32_t __stdcall window_keys_show_cursor(std::int32_t);
std::int32_t __stdcall window_keys_def_window_proc(void*,std::uint32_t,std::uint32_t,std::int32_t);
std::int32_t __stdcall window_keys_call_next_hook(void*,std::int32_t,std::uint32_t,std::int32_t);

std::uint32_t __stdcall window_key_activation_0053b050(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::int32_t __stdcall window_keyboard_hook_0053b150(std::int32_t,std::uint32_t,std::int32_t);
std::uint32_t __stdcall window_key_down_0053b450(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
}
