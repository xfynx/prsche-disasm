#include "porsche/window_worker.hpp"
#include "porsche/window_runtime.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> calls;
bool create_ok=true;
std::uint32_t message_result=1;
int fullscreen_after_wait=-1;
std::int32_t client_left=0,client_top=0,client_right=640,client_bottom=480,screen_x=0,screen_y=0;
void* hwnd_value=reinterpret_cast<void*>(0x1230000);
void log(const std::string& s){calls.push_back(s);}
}
namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
std::uint32_t& window_running_006b7c14=window_configuration_storage_006b77a0.running_006b7c14;
std::uint32_t& window_width_006b77b4=window_configuration_storage_006b77a0.width_006b77b4;
std::uint32_t& window_height_006b77b8=window_configuration_storage_006b77a0.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=window_configuration_storage_006b77a0.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;
void* class_lock_0069e59c=reinterpret_cast<void*>(0x2220000);
void* window_thread_handle_0069e574=nullptr;
std::uint32_t window_saved_parameter_0069e57c=0,window_saved_parameter_0069e580=0;
void* window_configuration_address_006b77a0=&window_configuration_storage_006b77a0;
void*& worker_configuration_006b77a0=window_configuration_address_006b77a0;
void* __cdecl window_lock_create_005321f0(){log("[\"lock\"]");return reinterpret_cast<void*>(0x2220000);}
void* __stdcall window_module_handle(const char*){log("[\"module\"]");return reinterpret_cast<void*>(0x1234000);}
void* __stdcall window_load_icon(void*,const char*){log("[\"icon\"]");return reinterpret_cast<void*>(0x1235000);}
void* __stdcall window_load_cursor(void*,const char*){log("[\"cursor\"]");return reinterpret_cast<void*>(0x1236000);}
void* __stdcall window_stock_object(std::int32_t){log("[\"stock\"]");return reinterpret_cast<void*>(0x1237000);}
std::uint16_t __stdcall window_register_class(const OriginalWndClassA*){log("[\"register\"]");return 1;}
std::uint32_t __stdcall window_last_error(){return 0;}
void __cdecl window_register_diagnostic(const char*,std::uint32_t){}
std::int32_t __stdcall window_get_system_metrics(std::int32_t i){return i?480:640;}
std::uint32_t __stdcall window_adjust_rect(WindowRect*,std::uint32_t,std::int32_t,std::uint32_t){return 1;}
void* __stdcall window_create_ex(std::uint32_t,const char*,const char*,std::uint32_t,std::int32_t,std::int32_t,std::int32_t,std::int32_t,void*,void*,void*,void*) {
    log("[\"CreateWindowExA\"]");return create_ok?hwnd_value:nullptr;
}
void* __stdcall window_set_cursor(void*){log("[\"SetCursor\"]");return nullptr;}
std::int32_t __stdcall window_show_cursor(std::int32_t){log("[\"ShowCursor\"]");return 0;}
void __cdecl window_channel_005739b0(std::uint32_t,std::uint32_t){}
std::uint32_t __cdecl window_worker_wait_0055fb20(){log("[\"0055fb20\"]");return 77;}
std::uint32_t __cdecl window_worker_wait_0055fb90(std::uint32_t v){log("[\"0055fb90\","+std::to_string(v)+"]");if(fullscreen_after_wait>=0)window_fullscreen_006b7c01=static_cast<std::uint8_t>(fullscreen_after_wait);return 0;}
std::uint32_t __cdecl window_worker_wait_0055fc10(std::uint32_t v){log("[\"0055fc10\","+std::to_string(v)+"]");return 0;}
std::uint32_t __stdcall window_worker_get_client_rect(void*,WindowWorkerRect* r){log("[\"GetClientRect\"]");r->left=client_left;r->top=client_top;r->right=client_right;r->bottom=client_bottom;return 1;}
std::uint32_t __stdcall window_worker_client_to_screen(void*,WindowWorkerRect* p){log("[\"ClientToScreen\"]");p->left=screen_x;p->top=screen_y;return 1;}
std::int32_t __stdcall window_worker_get_message(WindowWorkerMessage* m,void*,std::uint32_t,std::uint32_t){log("[\"GetMessageA\"]");if(message_result){m->hwnd=hwnd_value;m->message=0x100;m->wparam=65;m->lparam=0;}return static_cast<std::int32_t>(message_result);}
std::uint32_t __stdcall window_worker_translate_message(const WindowWorkerMessage*){log("[\"TranslateMessage\"]");return 1;}
std::int32_t __stdcall window_worker_dispatch_message(const WindowWorkerMessage*){log("[\"DispatchMessageA\"]");worker_message_state_0069e578=1;return 0;}
std::int32_t __stdcall window_worker_is_iconic(void*){log("[\"IsIconic\"]");return 0;}
std::int32_t __stdcall window_worker_show_cursor(std::int32_t){log("[\"ShowCursor\"]");return 0;}
std::uint32_t __stdcall window_worker_destroy_window(void*){log("[\"DestroyWindow\"]");return 1;}
void* __stdcall window_worker_get_foreground_window(){return nullptr;}
void* __stdcall window_worker_set_foreground_window(void*){log("[\"SetForegroundWindow\"]");return nullptr;}
void* __stdcall window_worker_set_active_window(void*){log("[\"SetActiveWindow\"]");return nullptr;}
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t v){log("[\"005322b0\","+std::to_string(v)+"]");return 0;}
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t v){log("[\"005322c0\","+std::to_string(v)+"]");return 0;}
std::uint32_t __cdecl window_worker_accelerator_0053b530(std::uint32_t a,std::uint32_t b){log("[\"0053b530\","+std::to_string(a)+","+std::to_string(b)+"]");return 0;}
std::uint32_t __cdecl window_worker_activation_00565560(){return 0;}
std::uint32_t __cdecl window_worker_focus_00573980(){return 0;}
void __cdecl window_worker_callback(){log("[\"callback\"]");worker_message_state_0069e578=1;}
std::uint32_t __cdecl window_worker_idle_callback(std::uint32_t,std::uint32_t,std::uint32_t){log("[\"idle\"]");worker_message_state_0069e578=1;return 0;}
std::uint32_t __cdecl window_worker_prepare_exit_00558350(void*){log("[\"00558350\"]");return 0;}
}
int main(){
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream in(line);unsigned fs,create,override_exists,msg;int ox,oy,l,t,r,b,sx,sy,fs_after;
        in>>fs>>create>>override_exists>>ox>>oy>>l>>t>>r>>b>>sx>>sy>>msg>>fs_after;
        if(!in)return 2;
        calls.clear();create_ok=create!=0;message_result=msg;
        auto& cfg=porsche::window_configuration_storage_006b77a0;
        std::memset(&cfg,0,sizeof(cfg));cfg.fullscreen_006b7c01=static_cast<std::uint8_t>(fs);
        cfg.width_006b77b4=static_cast<std::uint32_t>(r);cfg.height_006b77b8=static_cast<std::uint32_t>(b);
        porsche::window_configuration_address_006b77a0=&cfg;
        porsche::worker_message_state_0069e578=0;
        porsche::window_override_0069e5b0=override_exists;
        porsche::window_override_x_006bda00=ox;porsche::window_override_y_006bda04=oy;
        porsche::window_hwnd_006b7bf8=nullptr;porsche::worker_callback_0069e5a4=1;
        porsche::worker_accelerator_006bd9dc=0;porsche::window_fullscreen_006b7c01=static_cast<std::uint8_t>(fs);
        fullscreen_after_wait=fs_after;
        porsche::window_channels_initialized_0069e5a0=1;
        porsche::window_class_name_0069e5a8="Class";
        porsche::window_instance_006b7794=reinterpret_cast<void*>(0x1234000);
        client_left=l;client_top=t;client_right=r;client_bottom=b;screen_x=sx;screen_y=sy;
        porsche::window_thread_handle_0069e574=nullptr;porsche::window_running_006b7c14=0;
        auto result=porsche::window_worker_0053b8d0(nullptr);
        std::cout<<"{\"result\":"<<result<<",\"hwnd\":"<<reinterpret_cast<std::uintptr_t>(porsche::window_hwnd_006b7bf8)
                 <<",\"pos\":["<<porsche::window_pos_x_006b7c08<<","<<porsche::window_pos_y_006b7c0c<<"],\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i){if(i)std::cout<<',';std::cout<<calls[i];}
        std::cout<<"]}\n";
    }
}
