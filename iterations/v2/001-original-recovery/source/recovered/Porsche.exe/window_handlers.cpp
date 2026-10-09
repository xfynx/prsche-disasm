#include "porsche/window_handlers.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_worker.hpp"
#include <cstddef>
#include <cstdint>

namespace porsche {
// 0053a800..0053a8db. Original qsort is an unresolved typed boundary.
std::uint32_t __stdcall window_handler_register_0053a800(std::uint32_t message,std::uint32_t handler_value) {
    if(!class_lock_0069e59c)class_lock_0069e59c=window_lock_create_005321f0();
    window_worker_game_pump_005322b0(static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(class_lock_0069e59c)));

    const WindowHandler handler=reinterpret_cast<WindowHandler>(
        static_cast<std::uintptr_t>(handler_value));
    auto* entry=static_cast<WindowHandlerEntry*>(original_binary_search_005a2f23(
        &message,window_handlers_0069e0e0,window_handler_count_0069e570,
        sizeof(WindowHandlerEntry),window_message_compare_0053a7f0));
    std::uint32_t result=0;
    if(entry) {
        if(!handler_value) {
            entry->message=0x7fffffffu;
            window_handler_sort_005a112b(window_handlers_0069e0e0,
                window_handler_count_0069e570,sizeof(WindowHandlerEntry),
                window_message_compare_0053a7f0);
            --window_handler_count_0069e570;
            result=1;
        } else {
            entry->handler=handler;
            result=1;
        }
    } else if(handler_value && window_handler_count_0069e570<128) {
        auto& appended=window_handlers_0069e0e0[window_handler_count_0069e570++];
        appended.message=message;
        appended.handler=handler;
        window_handler_sort_005a112b(window_handlers_0069e0e0,
                window_handler_count_0069e570,sizeof(WindowHandlerEntry),
                window_message_compare_0053a7f0);
        result=1;
    }
    window_worker_game_dispatch_005322c0(static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(class_lock_0069e59c)));
    return result;
}

// 0053b040..0053b04d
std::uint32_t __stdcall window_handler_0053b040(void*,void*,std::uint32_t,
    std::uint32_t wparam,std::int32_t,std::int32_t*) {
    window_running_006b7c14=wparam;
    return 0;
}

// 0053b230..0053b252
std::uint32_t __stdcall window_handler_0053b230(void* configuration,void* hwnd,
    std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*) {
    if(configuration && hwnd==window_hwnd_006b7bf8)
        window_handler_post_quit_message(0);
    return 1;
}

// 0053b260..0053b287
std::uint32_t __stdcall window_handler_0053b260(void* configuration,void* hwnd,
    std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*) {
    if(configuration && hwnd==window_hwnd_006b7bf8)worker_message_state_0069e578=1;
    return 1;
}

// 0053b290..0053b292
std::uint32_t __stdcall window_handler_0053b290(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*) {
    return 0;
}

// 0053b2a0..0053b2d1
std::uint32_t __stdcall window_handler_0053b2a0(void* configuration,void*,
    std::uint32_t,std::uint32_t wparam,std::int32_t,std::int32_t*) {
    if(wparam==0xf060 || wparam==0xf020 || wparam==0xf030 || wparam==0xf120)
        return 0;
    return static_cast<const std::uint8_t*>(configuration)[0x461];
}

// 0053b2e0..0053b354
std::uint32_t __stdcall window_handler_0053b2e0(void* configuration,void* hwnd,
    std::uint32_t,std::uint32_t,std::int32_t,std::int32_t* result) {
    if(configuration && hwnd==window_hwnd_006b7bf8 &&
       static_cast<const std::uint8_t*>(configuration)[0x461]) {
        window_system_parameters(0x10,0,&window_saved_parameter_0069e57c,0);
        window_system_parameters(0x54,0,&window_saved_parameter_0069e580,0);
        if(window_saved_parameter_0069e57c)
            window_system_parameters(0x11,0,nullptr,2);
        if(window_saved_parameter_0069e580)
            window_system_parameters(0x56,0,nullptr,2);
    }
    *result=0;
    return 0;
}

// 0053b870..0053b8a2
std::uint32_t __stdcall window_handler_0053b870(void* configuration,void* hwnd,
    std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*) {
    if(!configuration || hwnd!=window_hwnd_006b7bf8)return 0;
    const auto* config=static_cast<const std::uint8_t*>(configuration);
    const auto configured_hwnd=*reinterpret_cast<const std::uint32_t*>(config+0x458);
    return configured_hwnd==static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(hwnd)) && config[0x461]!=0;
}

// 0053b8b0..0053b8bf
std::uint32_t __stdcall window_handler_0053b8b0(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t* result) {
    *result=static_cast<std::int32_t>(0x424d5144u);
    return 1;
}
}
