#include "porsche/window_keys.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/startup_input.hpp"

namespace porsche {
void* window_keyboard_hook_handle_0069e584=nullptr;
std::uint32_t window_keyboard_hook_enabled_0069e588=0;
std::uint32_t window_keyboard_hook_filter_0069e58c=0;
WindowHotkeyDispatch window_hotkey_dispatch_0069e590=nullptr;
std::uint32_t window_activation_seen_0069e5ac=0;
std::uint32_t window_key_virtual_code_006bd9fc=0;

// 0053b530..0053b5f1. These two compact original tables are data in the
// executable (0x53b654 and the jump table at 0x53b5f4). Unsupported messages,
// out-of-range keys, and entries with class 23 return zero.
std::uint32_t __cdecl window_worker_accelerator_0053b530(std::uint32_t message,std::uint32_t key) {
    if(message!=0x100 && message!=0x104)return 0;
    if(key<0x21 || key>0x7b)return 0;
    constexpr std::uint8_t classes[0x5b]={
        0,1,2,3,4,5,6,7,23,23,23,23,8,9,
        23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,
        23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,
        23,23,23,23,23,23,23,23,23,23,23,23,23,8,2,7,1,4,10,6,3,5,0,
        23,23,23,23,23,23,11,12,13,14,15,16,17,18,19,20,21,22
    };
    constexpr std::uint32_t results[24]={
        0x4900,0x5100,0x4f00,0x4700,0x4b00,0x4800,0x4d00,0x5000,
        0x5200,0x5300,0x4c00,0x3b00,0x3c00,0x3d00,0x3e00,0x3f00,
        0x4000,0x4100,0x4200,0x4300,0x4400,0x8700,0x8800,0
    };
    return results[classes[key-0x21]];
}

// 0053b050..0053b14c: WM_ACTIVATE. Win32 services are typed platform
// boundaries; the callback state and ordering below follow the original.
std::uint32_t __stdcall window_key_activation_0053b050(void* config,void* hwnd,
    std::uint32_t message,std::uint32_t wparam,std::int32_t lparam,std::int32_t* result) {
    if(!config || hwnd!=window_hwnd_006b7bf8)return 1;
    const auto activation=wparam&0xffffu;
    const auto minimized=wparam>>16;
    if(activation && minimized==0) {
        const auto def=window_keys_def_window_proc(hwnd,message,wparam,lparam);
        window_activation_seen_0069e5ac=1;
        *result=def;
        if(window_keyboard_hook_enabled_0069e588 && !window_keyboard_hook_handle_0069e584) {
            window_keyboard_hook_handle_0069e584=window_keys_set_keyboard_hook(
                2,window_keyboard_hook_0053b150,nullptr,0);
        }
        return 1;
    }
    if(window_activation_seen_0069e5ac)
        window_activation_seen_0069e5ac=0;
    if(window_keyboard_hook_enabled_0069e588 && window_keyboard_hook_handle_0069e584) {
        window_keys_unhook_windows_hook(window_keyboard_hook_handle_0069e584);
        window_keyboard_hook_handle_0069e584=nullptr;
    }
    window_keys_show_cursor(1);
    for(std::uint32_t i=0;i<0x80;++i)window_virtual_key_state_005de028[i]=0;
    *result=window_keys_def_window_proc(hwnd,message,wparam,lparam);
    return 1;
}

// 0053b150..0053b226: WH_KEYBOARD callback. Optional game hotkey dispatch
// remains a typed cdecl boundary; an absent callback follows the original
// handled path for a recognized key.
std::int32_t __stdcall window_keyboard_hook_0053b150(std::int32_t code,
    std::uint32_t key,std::int32_t lparam) {
    const auto next=[&]() {
        return window_keys_call_next_hook(window_keyboard_hook_handle_0069e584,
            code,key,lparam);
    };
    if(code!=0 || !window_running_006b7c14)return next();
    const auto vk=key;
    std::uint32_t modifier=0,command=0;
    bool recognized=false;
    if(window_keyboard_hook_filter_0069e58c &&
       (static_cast<std::uint32_t>(lparam)&0x20000000u)) {
        if(vk==9) { modifier=0x38;command=0xf;recognized=true; }
        else if(vk==0x1b) { modifier=0x38;command=1;recognized=true; }
        else if(window_keys_get_async_key_state(0x11)<0 && vk==0x20) {
            modifier=0x38;command=0x39;recognized=true;
        }
    } else if(window_keys_get_async_key_state(0x11)<0) {
        if(vk==0x1b) { modifier=0x1d;command=1;recognized=true; }
    } else if(vk==0x5b || vk==0x5c || vk==0x5d || vk==0x2c) {
        modifier=0;command=vk;recognized=true;
    }
    if(!recognized)return next();
    if(window_hotkey_dispatch_0069e590 &&
       !window_hotkey_dispatch_0069e590(modifier,command))return next();
    return 1;
}

// 0053b450..0053b52c: WM_KEYDOWN/WM_SYSKEYDOWN. The source table at
// 0069e5a0 is consumed through its existing typed translation boundary.
std::uint32_t __stdcall window_key_down_0053b450(void* config,void* hwnd,
    std::uint32_t message,std::uint32_t wparam,std::int32_t lparam,std::int32_t*) {
    if(!config || hwnd!=window_hwnd_006b7bf8)return 1;
    const auto packed=static_cast<std::uint32_t>(lparam);
    auto repeat_count=packed&0xffffu;
    if(repeat_count>window_input_capacity_0069e560)
        repeat_count=window_input_capacity_0069e560;
    auto key=(packed>>16)&0x7fu;
    if(window_channels_initialized_0069e5a0)
        key=window_message_translate_key_0069e5a0(key);
    window_key_virtual_code_006bd9fc=key;
    window_virtual_key_state_005de028[key]=1;
    const auto extended=(packed>>24)&1u;
    const auto accelerator=worker_accelerator_006bd9dc;
    if(accelerator) {
        for(auto i=0u;i<repeat_count;++i)
            window_message_enqueue_0053a9e0(0,key,extended);
        return 1;
    }
    const auto shortcut=window_worker_accelerator_0053b530(message,wparam);
    if(!shortcut)return 0;
    for(auto i=0u;i<repeat_count;++i)
        window_message_enqueue_0053a9e0(shortcut,key,extended);
    return 1;
}
}
