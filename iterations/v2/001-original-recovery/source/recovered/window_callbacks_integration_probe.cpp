#include "porsche/window_callback_bindings.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_keys.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_worker.hpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* window_configuration_address_006b77a0=&window_configuration_storage_006b77a0;
void*& worker_configuration_006b77a0=window_configuration_address_006b77a0;
std::uint32_t& window_running_006b7c14=window_configuration_storage_006b77a0.running_006b7c14;
std::uint32_t& window_width_006b77b4=window_configuration_storage_006b77a0.width_006b77b4;
std::uint32_t& window_height_006b77b8=window_configuration_storage_006b77a0.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=window_configuration_storage_006b77a0.fullscreen_006b7c01;
std::int32_t& window_pos_x_006b7c08=window_configuration_storage_006b77a0.pos_x_006b7c08;
std::int32_t& window_pos_y_006b7c0c=window_configuration_storage_006b77a0.pos_y_006b7c0c;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;
void* class_lock_0069e59c=reinterpret_cast<void*>(0x7777u);
std::uint32_t worker_message_state_0069e578=0;
std::uint32_t window_input_capacity_0069e560=8;
std::uint32_t window_input_read_0069e0d8=0,window_input_write_0069e568=0;
std::uint32_t window_channels_initialized_0069e5a0=0;
std::uint32_t worker_accelerator_006bd9dc=0;
std::uint32_t window_saved_parameter_0069e57c=0,window_saved_parameter_0069e580=0;
void* window_paint_lock_006a57d8=reinterpret_cast<void*>(0x8888u);

struct Event {std::uint32_t id,a,b,c,d;};
std::vector<Event> events;
std::int32_t default_result=-77;
void record(std::uint32_t id,std::uint32_t a=0,std::uint32_t b=0,
    std::uint32_t c=0,std::uint32_t d=0){events.push_back({id,a,b,c,d});}
void __cdecl window_handler_sort_005a112b(void* base,std::uint32_t count,
    std::uint32_t width,std::int32_t (__cdecl* compare)(const void*,const void*)) {
    record(2,count,width);
    if(width==sizeof(WindowHandlerEntry)) {
        auto* entries=static_cast<WindowHandlerEntry*>(base);
        std::sort(entries,entries+count,[&](const auto& a,const auto& b){return compare(&a,&b)<0;});
    }
}
void* __cdecl window_lock_create_005321f0(){record(20);return reinterpret_cast<void*>(0x7777u);}
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t arg){record(1,arg);return 0;}
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t arg){record(3,arg);return 0;}
void __stdcall window_handler_post_quit_message(std::uint32_t code){record(4,code);}
std::uint32_t __stdcall window_system_parameters(std::uint32_t action,std::uint32_t value,void*,std::uint32_t flags){record(21,action,value,flags);return 1;}
std::int32_t __stdcall window_default_procedure(void* hwnd,std::uint32_t msg,std::uint32_t wp,std::int32_t lp){
    record(5,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)),msg,wp,static_cast<std::uint32_t>(lp));return default_result;
}
std::int16_t __stdcall window_keys_get_async_key_state(std::uint32_t vk){record(22,vk);return 0;}
void* __stdcall window_keys_set_keyboard_hook(std::uint32_t kind,WindowKeyboardHookCallback cb,void* module,std::uint32_t tid){
    const auto guest=cb==window_keyboard_hook_0053b150?0x53b150u:0u;
    record(6,kind,guest,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(module)),tid);
    return reinterpret_cast<void*>(0x5555u);
}
std::int32_t __stdcall window_keys_unhook_windows_hook(void* hook){record(7,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hook)));return 1;}
std::int32_t __stdcall window_keys_show_cursor(std::int32_t show){record(8,static_cast<std::uint32_t>(show));return 0;}
std::int32_t __stdcall window_keys_def_window_proc(void* hwnd,std::uint32_t msg,std::uint32_t wp,std::int32_t lp){
    record(5,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)),msg,wp,static_cast<std::uint32_t>(lp));return default_result;
}
std::int32_t __stdcall window_keys_call_next_hook(void* hook,std::int32_t code,std::uint32_t wp,std::int32_t lp){
    record(23,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hook)),static_cast<std::uint32_t>(code),wp,static_cast<std::uint32_t>(lp));return -1;
}
std::uint32_t __stdcall window_message_get_client_rect(void* hwnd,WindowMessageRect* rect){
    record(9,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)));
    *rect={0,0,640,480};return 1;
}
std::uint32_t __stdcall window_message_client_to_screen(void* hwnd,WindowMessageRect* rect){
    record(10,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)));
    rect->left=10;rect->top=20;return 1;
}
std::uint32_t __cdecl window_message_enqueue_0053a9e0(std::uint32_t a,std::uint32_t b,std::uint32_t c){record(13,a,b,c);return 0;}
std::uint32_t __cdecl window_message_mouse_event_005728b0(std::uint32_t x,std::uint32_t y,std::uint32_t flags,std::uint32_t down){record(14,x,y,flags,down);return 0;}
std::uint32_t __stdcall window_message_begin_paint(void* hwnd,void*){record(15,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)));return 1;}
std::uint32_t __stdcall window_message_end_paint(void* hwnd,void*){record(16,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)));return 1;}
std::uint32_t __cdecl window_message_pump_005322b0(std::uint32_t arg){record(1,arg);return 0;}
std::uint32_t __cdecl window_message_dispatch_005322c0(std::uint32_t arg){record(3,arg);return 0;}
bool window_message_has_resize_notification_005df9b8(){record(11);return false;}
std::uint32_t __cdecl window_message_resize_notification_005df9b8(){record(12);return 0;}
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t key){return static_cast<std::uint8_t>(key);}
void* __stdcall window_worker_set_foreground_window(void* hwnd){record(17,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)));return hwnd;}

std::uint32_t __cdecl fixture_hotkey(std::uint32_t,std::uint32_t){return 1;}
}

namespace {
void emit_events(const std::vector<porsche::Event>& list) {
    std::cout<<'[';
    for(std::size_t i=0;i<list.size();++i){const auto& e=list[i];if(i)std::cout<<',';
        std::cout<<'['<<e.id<<','<<e.a<<','<<e.b<<','<<e.c<<','<<e.d<<']';}
    std::cout<<']';
}
std::uint32_t guest_va(porsche::WindowHandler handler){
    std::size_t count=0;const auto* bindings=porsche::window_callback_relocations(&count);
    for(std::size_t i=0;i<count;++i)if(bindings[i].native_callback==handler)return bindings[i].original_va;
    return 0;
}
}

int main() {
    using namespace porsche;
    std::size_t registrations=0;
    if(!(std::cin>>registrations) || registrations>128)return 2;
    std::vector<std::uint32_t> pairs(registrations*2);
    for(auto& x:pairs)if(!(std::cin>>x))return 3;
    std::size_t dispatch_count=0;if(!(std::cin>>dispatch_count) || dispatch_count>64)return 4;
    struct Dispatch {std::uint32_t message,wparam,lparam;};
    std::vector<Dispatch> dispatches(dispatch_count);
    for(auto& d:dispatches)if(!(std::cin>>d.message>>d.wparam>>d.lparam))return 5;

    window_configuration_storage_006b77a0={};
    window_configuration_address_006b77a0=&window_configuration_storage_006b77a0;
    window_hwnd_006b7bf8=reinterpret_cast<void*>(0x1234u);
    window_running_006b7c14=1;window_fullscreen_006b7c01=0;
    window_input_capacity_0069e560=8;window_channels_initialized_0069e5a0=0;
    worker_accelerator_006bd9dc=0;worker_message_state_0069e578=0;
    window_keyboard_hook_enabled_0069e588=1;window_activation_seen_0069e5ac=0;
    window_keyboard_hook_handle_0069e584=nullptr;window_keyboard_hook_filter_0069e58c=0;
    window_hotkey_dispatch_0069e590=fixture_hotkey;
    window_saved_parameter_0069e57c=window_saved_parameter_0069e580=0;
    window_handler_count_0069e570=0;
    for(auto& entry:window_handlers_0069e0e0)entry={0, nullptr};
    for(unsigned i=0;i<256;++i)window_virtual_key_state_005de028[i]=0;

    std::vector<WindowHandlerEntry> converted(registrations);
    std::uint32_t unresolved=0;
    if(!window_callback_relocate_table(pairs.data(),registrations,converted.data(),converted.size(),&unresolved)){
        std::cout<<"{\"error\":\"unresolved callback\",\"va\":"<<unresolved<<"}\n";return 0;
    }
    events.clear();
    for(std::size_t i=0;i<registrations;++i) {
        const auto callback=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(converted[i].handler));
        window_handler_register_0053a800(converted[i].message,callback);
    }
    const auto registration_events=events;events.clear();
    std::cout<<"{\"registrations\":[";
    for(std::size_t i=0;i<window_handler_count_0069e570;++i){if(i)std::cout<<',';
        const auto& entry=window_handlers_0069e0e0[i];
        std::cout<<'['<<entry.message<<','<<guest_va(entry.handler)<<']';}
    std::cout<<"],\"registration_events\":";emit_events(registration_events);
    std::cout<<",\"dispatches\":[";
    for(std::size_t i=0;i<dispatch_count;++i){if(i)std::cout<<',';
        const auto d=dispatches[i];events.clear();
        const auto result=window_procedure_0053aba0(window_hwnd_006b7bf8,d.message,d.wparam,static_cast<std::int32_t>(d.lparam));
        std::cout<<"{\"message\":"<<d.message<<",\"result\":"<<result<<",\"events\":";emit_events(events);
        std::cout<<",\"state\":["<<window_running_006b7c14<<','<<worker_message_state_0069e578<<','
          <<window_pos_x_006b7c08<<','<<window_pos_y_006b7c0c<<','<<window_activation_seen_0069e5ac<<','
          <<static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(window_keyboard_hook_handle_0069e584));
        for(auto key:window_virtual_key_state_005de028)std::cout<<','<<static_cast<unsigned>(key);
        std::cout<<"]}";
    }
    std::cout<<"]}\n";
}
