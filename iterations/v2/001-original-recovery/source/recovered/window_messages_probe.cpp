#include "porsche/window_messages.hpp"
#include "porsche/window_state.hpp"
#include <cstdint>
#include <iostream>

namespace porsche {
OriginalWindowConfiguration fixture_config{};
std::uint32_t& window_running_006b7c14=fixture_config.running_006b7c14;
std::uint32_t& window_width_006b77b4=fixture_config.width_006b77b4;
std::uint32_t& window_height_006b77b8=fixture_config.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=fixture_config.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=fixture_config.hwnd_006b7bf8;
std::uint32_t window_input_capacity_0069e560=32;
void* window_paint_lock_006a57d8=reinterpret_cast<void*>(0x12345678u);
std::uint32_t getrect_calls,screen_calls,resize_calls,enqueue_calls,mouse_calls,begin_calls,end_calls,pump_calls,dispatch_calls;
std::uint32_t translated_key=0xffu,notifier_present;
std::uint32_t last_a,last_b,last_c,last_d;
std::uint32_t __stdcall window_message_get_client_rect(void*,WindowMessageRect* r) {++getrect_calls;r->left=11;r->top=13;r->right=411;r->bottom=313;return 1;}
std::uint32_t __stdcall window_message_client_to_screen(void*,WindowMessageRect* r) {++screen_calls;r->left+=101;r->top+=103;return 1;}
std::uint32_t __cdecl window_message_enqueue_0053a9e0(std::uint32_t a,std::uint32_t b,std::uint32_t c) {++enqueue_calls;last_a=a;last_b=b;last_c=c;return 0;}
std::uint32_t __cdecl window_message_mouse_event_005728b0(std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d) {++mouse_calls;last_a=a;last_b=b;last_c=c;last_d=d;return 0;}
std::uint32_t __stdcall window_message_begin_paint(void*,void*) {++begin_calls;return 0;}
std::uint32_t __stdcall window_message_end_paint(void*,void*) {++end_calls;return 1;}
std::uint32_t __cdecl window_message_pump_005322b0(std::uint32_t) {++pump_calls;return 0;}
std::uint32_t __cdecl window_message_dispatch_005322c0(std::uint32_t) {++dispatch_calls;return 0;}
bool window_message_has_resize_notification_005df9b8() {return notifier_present!=0;}
std::uint32_t __cdecl window_message_resize_notification_005df9b8() {++resize_calls;return 0;}
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t key) {return static_cast<std::uint8_t>(translated_key==0xff?key:translated_key);}
void* __stdcall window_worker_set_foreground_window(void*) {return nullptr;}
}

int main() {
    unsigned mode,fullscreen,match,wparam,lparam,count,translate,notify;
    while(std::cin>>mode>>fullscreen>>match>>wparam>>lparam>>count>>translate>>notify) {
        using namespace porsche;
        fixture_config={};std::uint32_t out=0x77777777u;
        window_hwnd_006b7bf8=reinterpret_cast<void*>(0x1234u);
        fixture_config.hwnd_006b7bf8=reinterpret_cast<void*>(0x1234u);
        fixture_config.fullscreen_006b7c01=static_cast<std::uint8_t>(fullscreen);
        auto* hwnd=reinterpret_cast<void*>(match?0x1234u:0x5678u);
        getrect_calls=screen_calls=resize_calls=enqueue_calls=mouse_calls=begin_calls=end_calls=pump_calls=dispatch_calls=0;
        last_a=last_b=last_c=last_d=0;translated_key=translate;notifier_present=notify;
        window_input_capacity_0069e560=count;
        for(auto& key:window_virtual_key_state_005de028)key=0x7f;
        std::uint32_t result=0;
        switch(mode) {
            case 1: result=window_message_0053b360(&fixture_config,hwnd,0,0,0,reinterpret_cast<std::int32_t*>(&out));break;
            case 2: result=window_message_0053b3d0(&fixture_config,hwnd,0,wparam,static_cast<std::int32_t>(lparam),reinterpret_cast<std::int32_t*>(&out));break;
            case 3: result=window_message_0053b6b0(&fixture_config,hwnd,0,wparam,static_cast<std::int32_t>(lparam),reinterpret_cast<std::int32_t*>(&out));break;
            case 4: result=window_message_0053b710(&fixture_config,hwnd,0,wparam,static_cast<std::int32_t>(lparam),reinterpret_cast<std::int32_t*>(&out));break;
            case 5: result=window_message_0053b770(&fixture_config,hwnd,0,wparam,static_cast<std::int32_t>(lparam),reinterpret_cast<std::int32_t*>(&out));break;
            case 6: result=window_message_0053b7d0(&fixture_config,hwnd,0,wparam,static_cast<std::int32_t>(lparam),reinterpret_cast<std::int32_t*>(&out));break;
        }
        std::cout<<result<<' '<<out<<' '<<fixture_config.pos_x_006b7c08<<' '<<fixture_config.pos_y_006b7c0c<<' '
          <<getrect_calls<<' '<<screen_calls<<' '<<resize_calls<<' '<<enqueue_calls<<' '<<mouse_calls<<' '<<begin_calls<<' '<<end_calls<<' '
          <<pump_calls<<' '<<dispatch_calls<<' '<<static_cast<unsigned>(window_virtual_key_state_005de028[translate==0xff?((lparam>>16)&0x7f):translate])<<' '
          <<last_a<<' '<<last_b<<' '<<last_c<<' '<<last_d<<'\n';
    }
}
