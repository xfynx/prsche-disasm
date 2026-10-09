#include "porsche/render_event_route.hpp"
#include "porsche/mouse_input.hpp"
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
    mouse_input_consumer_005728b0(x_word,y_word,mode_flags,down);
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
