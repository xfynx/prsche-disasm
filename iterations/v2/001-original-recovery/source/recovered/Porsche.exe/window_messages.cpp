#include "porsche/window_messages.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {
namespace {
std::uint8_t& key_state(std::uint32_t vk) {
    return window_virtual_key_state_005de028[vk&0xffu];
}
}
std::uint8_t window_virtual_key_state_005de028[256]{};

// 0053b360..0053b3c8. The pointer callback at 005df9b8 is an original
// zero-argument cdecl boundary; the binary index resolves its target 005654d0.
std::uint32_t __stdcall window_message_0053b360(void* config,void* hwnd,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*) {
    if(!config || hwnd!=window_hwnd_006b7bf8)
        return 0;
    auto* bytes=static_cast<std::uint8_t*>(config);
    if(bytes[0x461])return 0;
    auto* target_hwnd=*reinterpret_cast<void**>(bytes+0x458);
    WindowMessageRect rect{};
    window_message_get_client_rect(target_hwnd,&rect);
    window_message_client_to_screen(target_hwnd,&rect);
    *reinterpret_cast<std::int32_t*>(bytes+0x468)=rect.left;
    *reinterpret_cast<std::int32_t*>(bytes+0x46c)=rect.top;
    if(window_message_has_resize_notification_005df9b8())
        window_message_resize_notification_005df9b8();
    return 0;
}

// 0053b3d0..0053b43e. The queue consumer 0053a9e0 remains a typed boundary.
std::uint32_t __stdcall window_message_0053b3d0(void* config,void* hwnd,std::uint32_t,
    std::uint32_t wparam,std::int32_t lparam,std::int32_t*) {
    if(!config || hwnd!=window_hwnd_006b7bf8)return 1;
    const auto packed=static_cast<std::uint32_t>(lparam);
    auto count=packed&0xffffu;
    if(count>window_input_capacity_0069e560)count=window_input_capacity_0069e560;
    if(!count)return 1;
    const auto character=(packed>>16)&0x7fu;
    const auto down=(packed>>24)&1u;
    for(std::uint32_t i=0;i<count;++i)
        window_message_enqueue_0053a9e0(wparam,character,down);
    return 1;
}

// 0053b6b0..0053b707 key-up state transition; the scan-code translation table
// at 0069e5a0 is shared original data and may be absent (identity mapping).
std::uint32_t __stdcall window_message_0053b6b0(void* config,void* hwnd,std::uint32_t,
    std::uint32_t,std::int32_t lparam,std::int32_t*) {
    if(!config || hwnd!=window_hwnd_006b7bf8)return 0;
    auto key=(static_cast<std::uint32_t>(lparam)>>16)&0x7f;
    key=window_message_translate_key_0069e5a0(key);
    if(key==0x2a || key==0x36) {
        key_state(0x5e)=0;key_state(0x52)=0;
    } else key_state(key)=0;
    return 0;
}

namespace {
std::uint32_t mouse(void* config,void* hwnd,std::uint32_t wparam,std::int32_t lparam,bool down) {
    if(config && hwnd==window_hwnd_006b7bf8) {
        const auto buttons=static_cast<std::uint8_t>(wparam);
        const std::uint32_t flags=((buttons&1)?1u:0u)|((buttons&2)?2u:0u)|((buttons&0x10)?4u:0u);
        const auto coords=static_cast<std::uint32_t>(lparam);
        window_message_mouse_event_005728b0(coords&0xffffu,coords>>16,flags,down?1u:0u);
    }
    return 0;
}
}
// 0053b710..0053b760 and 0053b770..0053b7c0.
std::uint32_t __stdcall window_message_0053b710(void* c,void* h,std::uint32_t,
    std::uint32_t w,std::int32_t l,std::int32_t*) { return mouse(c,h,w,l,true); }
std::uint32_t __stdcall window_message_0053b770(void* c,void* h,std::uint32_t,
    std::uint32_t w,std::int32_t l,std::int32_t*) { return mouse(c,h,w,l,false); }

// 0053b7d0..0053b86d WM_PAINT; BeginPaint/EndPaint and pump calls are typed OS/game boundaries.
std::uint32_t __stdcall window_message_0053b7d0(void* config,void* hwnd,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t* result) {
    if(config && hwnd==window_hwnd_006b7bf8 && hwnd) {
        const auto fullscreen=static_cast<std::uint8_t*>(config)[0x461];
        if(fullscreen)window_worker_set_foreground_window(hwnd);
        std::uint8_t paint[0x40]{};
        window_message_pump_005322b0(static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(window_paint_lock_006a57d8)));
        window_message_begin_paint(hwnd,paint);
        window_message_end_paint(hwnd,paint);
        window_message_dispatch_005322c0(static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(window_paint_lock_006a57d8)));
        if(!fullscreen && window_message_has_resize_notification_005df9b8())
            window_message_resize_notification_005df9b8();
        *result=1;
        return 1;
    }
    return 1;
}
}
