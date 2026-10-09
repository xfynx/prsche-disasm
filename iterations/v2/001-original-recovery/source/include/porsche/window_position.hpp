#pragma once
#include <cstdint>
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"

namespace porsche {
struct WindowPositionRect { std::int32_t left,top,right,bottom; };
struct WindowPositionPoint { std::int32_t x,y; };
// Boundaries visible in the positioning / class-cleanup consumers.
std::int32_t __stdcall window_position_get_system_metrics(std::int32_t);
std::uint32_t __stdcall window_position_get_client_rect(void*,WindowPositionRect*);
std::int32_t __stdcall window_position_get_window_long(void*,std::int32_t);
std::uint32_t __stdcall window_position_adjust_window_rect_ex(WindowPositionRect*,std::uint32_t,
    std::int32_t,std::uint32_t);
std::uint32_t __stdcall window_position_system_parameters(std::uint32_t,std::uint32_t,void*,std::uint32_t);
std::uint32_t __stdcall window_position_set_window_pos(void*,void*,std::int32_t,std::int32_t,
    std::int32_t,std::int32_t,std::uint32_t);
std::uint32_t __stdcall window_position_client_to_screen(void*,WindowPositionPoint*);
std::uint32_t __cdecl window_position_remove_0053a8e0(std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t);
std::uint32_t __stdcall window_position_unregister_class(const char*,void*);
std::uint32_t __cdecl window_position_idle_0055f740(std::uint32_t);
std::uint32_t __cdecl window_position_timed_005366e0(std::uint32_t);

void __cdecl window_position_cleanup_0053bcb0();
void __cdecl window_position_resize_0053bd40(std::int32_t x,std::int32_t y,
    std::int32_t width,std::int32_t height);
void __cdecl window_position_center_0053bec0(std::int32_t width,std::int32_t height);
}
