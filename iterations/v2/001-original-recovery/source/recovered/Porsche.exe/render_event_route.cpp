#include "porsche/render_event_route.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_state.hpp"
#include <algorithm>
#include <cstdint>

namespace porsche {
std::uint32_t render_event_dispatch_gate_005deaac;
std::uint32_t render_event_callback_pointer_005debec=0x005367b0;

void __cdecl render_event_set_cursor_position_0053a970(
    void* configuration,std::int32_t x,std::int32_t y) {
    auto* bytes=static_cast<std::uint8_t*>(configuration);
    auto hwnd=*reinterpret_cast<void**>(bytes+0x458);
    WindowPositionPoint point{x,y};
    if(window_position_client_to_screen(hwnd,&point)) {
        render_event_set_cursor_pos(point.x,point.y);
        render_event_set_cursor(nullptr);
        return;
    }
    render_event_set_cursor_pos(x,y);
    render_event_set_cursor(nullptr);
}

std::uint32_t __cdecl render_event_default_callback_005367b0(std::uint32_t) {
    return 0;
}

void __cdecl render_event_route_005728b0(
    std::uint32_t x_word,std::uint32_t y_word,std::uint32_t mode_flags,
    std::uint32_t down) {
    if(!render_event_dispatch_gate_005deaac || !class_lock_0069e59c)return;
    const auto x=static_cast<std::int32_t>(x_word);
    const auto y=static_cast<std::int32_t>(y_word);
    const auto low_x=static_cast<std::int32_t>(render_driver_bounds_a_006a643c);
    const auto high_x=static_cast<std::int32_t>(render_driver_bounds_c_006a6430);
    const auto low_y=static_cast<std::int32_t>(render_driver_bounds_b_006a6438);
    const auto high_y=static_cast<std::int32_t>(render_driver_bounds_d_006a6434);
    const auto clamp=[](std::int32_t value,std::int32_t low,std::int32_t high) {
        return std::min(std::max(value,low),high);
    };
    const auto adjusted_x=clamp(x,low_x,high_x);
    const auto adjusted_y=clamp(y,low_y,high_y);

    heap_enter_005322b0(class_lock_0069e59c);
    render_driver_limit_c_006a6440=mode_flags;
    if(adjusted_x!=x || adjusted_y!=y)
        render_event_set_cursor_position_0053a970(
            &window_configuration_storage_006b77a0,adjusted_x,adjusted_y);
    if(adjusted_x!=static_cast<std::int32_t>(render_driver_limit_a_006a6448) ||
       adjusted_y!=static_cast<std::int32_t>(render_driver_limit_b_006a6444)) {
        render_driver_limit_a_006a6448=static_cast<std::uint32_t>(adjusted_x);
        render_driver_limit_b_006a6444=static_cast<std::uint32_t>(adjusted_y);
    }
    heap_leave_005322c0(class_lock_0069e59c);
    if(down && render_event_callback_pointer_005debec) {
        if(render_event_callback_pointer_005debec==0x005367b0)
            render_event_default_callback_005367b0(mode_flags);
        else render_event_invoke_callback_005debec(
            render_event_callback_pointer_005debec,mode_flags);
    }
}

// Shared by WM button routes and the renderer's 00537600 mode-change bridge.
std::uint32_t __cdecl window_message_mouse_event_005728b0(
    std::uint32_t x,std::uint32_t y,std::uint32_t flags,std::uint32_t down) {
    render_event_route_005728b0(x,y,flags,down);
    return 0;
}

// Run056's four-word cdecl boundary resolves to this same recovered consumer.
void __cdecl render_driver_apply_005728b0(std::uint32_t x,std::uint32_t y,
                                          std::uint32_t flags,std::uint32_t down) {
    window_message_mouse_event_005728b0(x,y,flags,down);
}
}
