#pragma once

#include <cstdint>
#include "porsche/window_position.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {

// Original 006a64a0 is read by 00573980 and written as 0/1 by the lock-
// protected body at 00575730. Its higher-level meaning is not established.
extern std::uint32_t window_support_opaque_value_006a64a0;

// Typed OS boundaries used by the recovered original wrapper. The Win32
// functions are reached through the original IAT in Porsche.exe.
std::uint32_t __stdcall window_support_send_notify_message_a(
    void* hwnd,std::uint32_t message,std::uint32_t wparam,std::int32_t lparam);
std::uint32_t __stdcall window_support_post_message_a(
    void* hwnd,std::uint32_t message,std::uint32_t wparam,std::int32_t lparam);
std::uint32_t __stdcall window_support_get_last_error();

}
