#pragma once
#include "porsche/render_driver_calls.hpp"
#include "porsche/window_position.hpp"
#include <cstdint>

namespace porsche {
extern std::uint32_t render_event_dispatch_gate_005deaac;
extern std::uint32_t render_event_callback_pointer_005debec;

// Direct Win32 edges used by the original 0053a970 cursor-position helper.
std::int32_t __stdcall render_event_set_cursor_pos(std::int32_t x,std::int32_t y);
void* __stdcall render_event_set_cursor(void* cursor);
// Dynamic callback-pointer bridge; original default target 005367b0 is a no-op.
void __cdecl render_event_invoke_callback_005debec(std::uint32_t callback,
                                                    std::uint32_t mode_flags);
std::uint32_t __cdecl render_event_default_callback_005367b0(std::uint32_t mode_flags);

void __cdecl render_event_set_cursor_position_0053a970(
    void* window_configuration,std::int32_t x,std::int32_t y);
void __cdecl render_event_route_005728b0(std::uint32_t x,std::uint32_t y,
                                        std::uint32_t mode_flags,std::uint32_t down);
}
