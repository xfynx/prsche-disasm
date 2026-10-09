#include "porsche/window_keys.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/startup_input.hpp"
#include <cstdint>
#include <iostream>

namespace porsche {
OriginalWindowConfiguration fixture_config{};
std::uint32_t& window_running_006b7c14=fixture_config.running_006b7c14;
std::uint32_t& window_width_006b77b4=fixture_config.width_006b77b4;
std::uint32_t& window_height_006b77b8=fixture_config.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=fixture_config.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=fixture_config.hwnd_006b7bf8;
std::uint32_t window_input_capacity_0069e560=0;
std::uint32_t window_channels_initialized_0069e5a0=0;
std::uint32_t worker_accelerator_006bd9dc=0;
std::uint8_t window_virtual_key_state_005de028[256]{};
struct Event {std::uint32_t code,a,b,c,d;};
Event events[64]{};std::uint32_t event_count;
std::int16_t async_result;std::int32_t def_result,next_result;
void* set_hook_result;std::uint32_t hotkey_result;
std::uint8_t key_map[128]{};
void record(std::uint32_t code,std::uint32_t a=0,std::uint32_t b=0,std::uint32_t c=0,std::uint32_t d=0){events[event_count++]={code,a,b,c,d};}
std::int16_t __stdcall window_keys_get_async_key_state(std::uint32_t key){record(5,key);return async_result;}
void* __stdcall window_keys_set_keyboard_hook(std::uint32_t id,WindowKeyboardHookCallback cb,void* module,std::uint32_t tid){
  const auto address=cb==window_keyboard_hook_0053b150?0x53b150u:static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(cb));
  record(1,id,address,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(module)),tid);return set_hook_result;
}
std::int32_t __stdcall window_keys_unhook_windows_hook(void* hook){record(2,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hook)));return 1;}
std::int32_t __stdcall window_keys_show_cursor(std::int32_t show){record(3,static_cast<std::uint32_t>(show));return 0;}
std::int32_t __stdcall window_keys_def_window_proc(void* hwnd,std::uint32_t msg,std::uint32_t wp,std::int32_t lp){
  record(4,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)),msg,wp,static_cast<std::uint32_t>(lp));return def_result;
}
std::int32_t __stdcall window_keys_call_next_hook(void* hook,std::int32_t code,std::uint32_t wp,std::int32_t lp){
  record(6,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hook)),static_cast<std::uint32_t>(code),wp,static_cast<std::uint32_t>(lp));return next_result;
}
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t scan){return key_map[scan&0x7fu];}
std::uint32_t __cdecl window_message_enqueue_0053a9e0(std::uint32_t a,std::uint32_t b,std::uint32_t c){record(8,a,b,c);return 0;}
std::uint32_t __cdecl fixture_hotkey(std::uint32_t modifier,std::uint32_t command){record(7,modifier,command);return hotkey_result;}
}

static std::uint32_t wordptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
int main(){
  unsigned mode;
  while(std::cin>>mode){
    using namespace porsche;
    fixture_config={};window_hwnd_006b7bf8=reinterpret_cast<void*>(0x1234u);
    window_input_capacity_0069e560=32;window_channels_initialized_0069e5a0=0;worker_accelerator_006bd9dc=0;
    window_keyboard_hook_handle_0069e584=nullptr;window_keyboard_hook_enabled_0069e588=0;
    window_keyboard_hook_filter_0069e58c=0;window_hotkey_dispatch_0069e590=nullptr;
    window_activation_seen_0069e5ac=0;window_key_virtual_code_006bd9fc=0xdeadbeefu;
    for(unsigned i=0;i<256;++i)window_virtual_key_state_005de028[i]=static_cast<std::uint8_t>(i^0x55u);
    for(unsigned i=0;i<128;++i)key_map[i]=static_cast<std::uint8_t>(i*3u+7u);
    event_count=0;async_result=0;def_result=-17;next_result=-23;set_hook_result=reinterpret_cast<void*>(0x55667788u);hotkey_result=1;
    std::uint32_t result=0xabcdef01u;
    std::int32_t output=static_cast<std::int32_t>(0xabcdef01u);
    if(mode==0){
      std::uint32_t message,key;std::cin>>message>>key;
      result=window_worker_accelerator_0053b530(message,key);
    } else if(mode==1){
      unsigned has_config,match_hwnd,message,wp,lp,capacity,map_enabled,worker_accel;
      std::cin>>has_config>>match_hwnd>>message>>wp>>lp>>capacity>>map_enabled>>worker_accel;
      window_input_capacity_0069e560=capacity;window_channels_initialized_0069e5a0=map_enabled?0x5df934u:0;
      worker_accelerator_006bd9dc=worker_accel;
      void* hwnd=match_hwnd?window_hwnd_006b7bf8:reinterpret_cast<void*>(0x9999u);
      result=window_key_down_0053b450(has_config?&fixture_config:nullptr,hwnd,message,wp,static_cast<std::int32_t>(lp),nullptr);
    } else if(mode==2){
      unsigned has_config,match_hwnd,wp,active,hook_enabled,has_hook,hook_result;
      std::cin>>has_config>>match_hwnd>>wp>>active>>hook_enabled>>has_hook>>hook_result>>def_result;
      window_activation_seen_0069e5ac=active;window_keyboard_hook_enabled_0069e588=hook_enabled;
      window_keyboard_hook_handle_0069e584=has_hook?reinterpret_cast<void*>(0x44445555u):nullptr;
      set_hook_result=hook_result?reinterpret_cast<void*>(0x55667788u):nullptr;
      void* hwnd=match_hwnd?window_hwnd_006b7bf8:reinterpret_cast<void*>(0x9999u);
      result=window_key_activation_0053b050(has_config?&fixture_config:nullptr,hwnd,6,wp,0x12345678,&output);
    } else {
      std::uint32_t code,key,lp,running,filter,cb_enabled,cb_result,next;std::int32_t async;
      unsigned has_hook;
      std::cin>>code>>key>>lp>>running>>filter>>async>>cb_enabled>>cb_result>>next>>has_hook;
      window_running_006b7c14=running;window_keyboard_hook_filter_0069e58c=filter;
      async_result=static_cast<std::int16_t>(async);hotkey_result=cb_result;next_result=static_cast<std::int32_t>(next);
      window_keyboard_hook_handle_0069e584=has_hook?reinterpret_cast<void*>(0x44445555u):nullptr;
      window_hotkey_dispatch_0069e590=cb_enabled?fixture_hotkey:nullptr;
      result=static_cast<std::uint32_t>(window_keyboard_hook_0053b150(static_cast<std::int32_t>(code),key,static_cast<std::int32_t>(lp)));
    }
    std::cout<<result<<' '<<static_cast<std::uint32_t>(output)<<' '<<window_key_virtual_code_006bd9fc<<' '<<window_activation_seen_0069e5ac<<' '
      <<wordptr(window_keyboard_hook_handle_0069e584)<<' '<<window_keyboard_hook_enabled_0069e588<<' '
      <<window_running_006b7c14<<' '<<window_input_capacity_0069e560<<' '<<window_channels_initialized_0069e5a0<<' '
      <<event_count;
    for(unsigned i=0;i<event_count;++i)std::cout<<' '<<events[i].code<<' '<<events[i].a<<' '<<events[i].b<<' '<<events[i].c<<' '<<events[i].d;
    for(auto key:window_virtual_key_state_005de028)std::cout<<' '<<static_cast<unsigned>(key);
    std::cout<<'\n';
  }
}
