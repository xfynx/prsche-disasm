#include "porsche/window_support.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_state.hpp"

#include <array>
#include <cstdint>
#include <iostream>

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
std::uint32_t& window_running_006b7c14=
    window_configuration_storage_006b77a0.running_006b7c14;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;

namespace {
struct Event { std::uint32_t kind,hwnd,a,b,c; };
Event events[2]{};
std::uint32_t event_count=0,send_result=0,post_result=0,last_error=0;
void record(std::uint32_t kind,void* hwnd,std::uint32_t a,std::uint32_t b,std::uint32_t c) {
    if(event_count<2)events[event_count]={kind,
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)),a,b,c};
    ++event_count;
}
void reset_events() { event_count=0;events[0]={};events[1]={}; }
std::uint32_t word(const void* p) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}
void emit(std::uint32_t result) {
    std::cout<<result<<' '<<window_running_006b7c14<<' '<<word(window_hwnd_006b7bf8)
             <<' '<<window_support_opaque_value_006a64a0<<' '<<event_count;
    for(std::uint32_t i=0;i<event_count && i<2;++i)
        std::cout<<' '<<events[i].kind<<' '<<events[i].hwnd<<' '<<events[i].a
                 <<' '<<events[i].b<<' '<<events[i].c;
    std::cout<<'\n';
}
}

std::uint32_t __stdcall window_support_send_notify_message_a(
    void* hwnd,std::uint32_t message,std::uint32_t wparam,std::int32_t lparam) {
    record(1,hwnd,message,wparam,static_cast<std::uint32_t>(lparam));return send_result;
}
std::uint32_t __stdcall window_support_post_message_a(
    void* hwnd,std::uint32_t message,std::uint32_t wparam,std::int32_t lparam) {
    record(2,hwnd,message,wparam,static_cast<std::uint32_t>(lparam));return post_result;
}
std::uint32_t __stdcall window_support_get_last_error() { record(3,nullptr,0,0,0);return last_error; }
}

using namespace porsche;

int main() {
    char operation=0;
    while(std::cin>>operation) {
        window_configuration_storage_006b77a0={};
        window_support_opaque_value_006a64a0=0;
        reset_events();send_result=post_result=last_error=0;
        if(operation=='p') {
            std::uint32_t hwnd=0,a=0,b=0,c=0,d=0;
            std::cin>>hwnd>>a>>b>>c>>d>>send_result>>post_result>>last_error;
            window_hwnd_006b7bf8=reinterpret_cast<void*>(static_cast<std::uintptr_t>(hwnd));
            const auto result=porsche::window_position_remove_0053a8e0(a,b,c,d);
            emit(result);
        } else if(operation=='a') {
            std::uint32_t running=0,hwnd=0;std::cin>>running>>hwnd;
            window_running_006b7c14=running;
            window_hwnd_006b7bf8=reinterpret_cast<void*>(static_cast<std::uintptr_t>(hwnd));
            emit(porsche::window_worker_activation_00565560());
        } else if(operation=='g') {
            std::cin>>window_support_opaque_value_006a64a0;
            emit(porsche::window_worker_focus_00573980());
        } else return 2;
    }
}
