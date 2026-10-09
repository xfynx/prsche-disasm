#include "porsche/window_create.hpp"
#include "porsche/window_worker.hpp"
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>

namespace {
std::uint32_t get_message_calls;
bool create_config_ok;
}
namespace porsche {
const char* window_class_name_0069e5a8=nullptr;
void* window_instance_006b7794=nullptr;
std::uint32_t window_style_005dea88=0;
std::uint8_t window_style_flag_005dead4=0;
std::uint32_t window_override_0069e5b0=0;
std::int32_t window_override_x_006bda00=0,window_override_y_006bda04=0;
std::uint32_t window_create_state_005de024=0;
std::uint32_t window_channels_initialized_0069e5a0=1;

void* __cdecl window_lock_create_005321f0(){return reinterpret_cast<void*>(0x2220000);}
void* __stdcall window_module_handle(const char*){return reinterpret_cast<void*>(0x1234000);}
void* __stdcall window_load_icon(void*,const char*){return reinterpret_cast<void*>(0x1235000);}
void* __stdcall window_load_cursor(void*,const char*){return reinterpret_cast<void*>(0x1236000);}
void* __stdcall window_stock_object(std::int32_t){return reinterpret_cast<void*>(0x1237000);}
std::uint16_t __stdcall window_register_class(const OriginalWndClassA*){return 1;}
std::uint32_t __stdcall window_last_error(){return 0;}
void __cdecl window_register_diagnostic(const char*,std::uint32_t){}
std::int32_t __stdcall window_default_procedure(void*,std::uint32_t,std::uint32_t,std::int32_t){return 0;}
std::int32_t __stdcall window_procedure_0053aba0(void*,std::uint32_t,std::uint32_t,std::int32_t){return 0;}

void* __cdecl window_create_0053bb00(void* config){
    create_config_ok=config==&window_configuration_storage_006b77a0 &&
        config==window_configuration_address_006b77a0 && config==worker_configuration_006b77a0;
    return reinterpret_cast<void*>(0x1230000);
}
std::uint32_t __cdecl window_worker_wait_0055fb20(){return 0;}
std::uint32_t __cdecl window_worker_wait_0055fb90(std::uint32_t){return 0;}
std::uint32_t __cdecl window_worker_wait_0055fc10(std::uint32_t){return 0;}
std::uint32_t __stdcall window_worker_get_client_rect(void*,WindowWorkerRect* r){*r={1,2,640,480};return 1;}
std::uint32_t __stdcall window_worker_client_to_screen(void*,WindowWorkerRect* r){*r={37,48,0,0};return 1;}
std::int32_t __stdcall window_worker_get_message(WindowWorkerMessage* m,void*,std::uint32_t,std::uint32_t){
    ++get_message_calls;m->hwnd=reinterpret_cast<void*>(0x1230000);m->message=0x100;m->wparam=65;return 1;
}
std::uint32_t __stdcall window_worker_translate_message(const WindowWorkerMessage*){return 1;}
std::int32_t __stdcall window_worker_dispatch_message(const WindowWorkerMessage*){worker_message_state_0069e578=1;return 1;}
std::int32_t __stdcall window_worker_is_iconic(void*){return 0;}
std::int32_t __stdcall window_worker_show_cursor(std::int32_t){return 0;}
void* __stdcall window_worker_get_foreground_window(){return nullptr;}
void* __stdcall window_worker_set_foreground_window(void*){return nullptr;}
void* __stdcall window_worker_set_active_window(void*){return nullptr;}
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t){return 0;}
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t){return 0;}
std::uint32_t __cdecl window_worker_accelerator_0053b530(std::uint32_t,std::uint32_t){return 0;}
std::uint32_t __cdecl window_worker_activation_00565560(){return 0;}
std::uint32_t __cdecl window_worker_focus_00573980(){return 0;}
void __cdecl window_worker_callback(){}
std::uint32_t __cdecl window_worker_idle_callback(std::uint32_t,std::uint32_t,std::uint32_t){return 0;}
std::uint32_t __stdcall window_worker_destroy_window(void*){return 23;}
std::uint32_t __cdecl window_worker_prepare_exit_00558350(void*){return 0;}
}

int main(){
    using namespace porsche;
    auto& config=window_configuration_storage_006b77a0;
    std::memset(&config,0xa5,sizeof(config));
    window_configuration_address_006b77a0=&config;
    config.width_006b77b4=800;config.height_006b77b8=600;
    config.hwnd_006b7bf8=reinterpret_cast<void*>(0x4444);
    config.fullscreen_006b7c01=0;config.pos_x_006b7c08=11;config.pos_y_006b7c0c=22;
    config.running_006b7c14=0;*reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::byte*>(&config)+0x10)=1;
    bool addresses=&window_width_006b77b4==&config.width_006b77b4 &&
        &window_height_006b77b8==&config.height_006b77b8 &&
        &window_hwnd_006b7bf8==&config.hwnd_006b7bf8 &&
        &window_fullscreen_006b7c01==&config.fullscreen_006b7c01 &&
        &window_pos_x_006b7c08==&config.pos_x_006b7c08 &&
        &window_pos_y_006b7c0c==&config.pos_y_006b7c0c &&
        &window_running_006b7c14==&config.running_006b7c14 &&
        worker_configuration_006b77a0==window_configuration_address_006b77a0;
    bool values=window_width_006b77b4==800 && window_height_006b77b8==600 &&
        window_hwnd_006b7bf8==reinterpret_cast<void*>(0x4444) &&
        window_fullscreen_006b7c01==0 && window_pos_x_006b7c08==11 &&
        window_pos_y_006b7c0c==22 && window_running_006b7c14==0;
    window_width_006b77b4=1024;window_height_006b77b8=768;
    window_hwnd_006b7bf8=reinterpret_cast<void*>(0x5555);window_fullscreen_006b7c01=1;
    window_pos_x_006b7c08=-5;window_pos_y_006b7c0c=9;window_running_006b7c14=7;
    bool reverse=config.width_006b77b4==1024 && config.height_006b77b8==768 &&
        config.hwnd_006b7bf8==reinterpret_cast<void*>(0x5555) && config.fullscreen_006b7c01==1 &&
        config.pos_x_006b7c08==-5 && config.pos_y_006b7c0c==9 && config.running_006b7c14==7;
    OriginalWindowConfiguration alternate{};
    worker_configuration_006b77a0=&alternate;
    bool pointer_alias=window_configuration_address_006b77a0==&alternate;
    worker_configuration_006b77a0=&config;
    config.fullscreen_006b7c01=0;config.hwnd_006b7bf8=nullptr;window_override_0069e5b0=0;
    window_worker_0053b8d0(nullptr);
    bool worker_shared=create_config_ok && get_message_calls==1 &&
        window_pos_x_006b7c08==37 && window_pos_y_006b7c0c==48 &&
        config.pos_x_006b7c08==37 && config.pos_y_006b7c0c==48 &&
        window_running_006b7c14==1 && config.running_006b7c14==1 && !window_hwnd_006b7bf8;
    const bool opaque_preserved=config.opaque_0000[0]==std::byte{0xa5} &&
        config.opaque_001c[0]==std::byte{0xa5} && config.opaque_045c[0]==std::byte{0xa5} &&
        config.opaque_0462[0]==std::byte{0xa5} && config.opaque_0470[0]==std::byte{0xa5};
    std::cout<<"{\"addresses\":"<<addresses<<",\"config_to_globals\":"<<values
        <<",\"globals_to_config\":"<<reverse<<",\"pointer_alias\":"<<pointer_alias
        <<",\"worker_shared\":"<<worker_shared<<",\"opaque_preserved\":"<<opaque_preserved<<"}\n";
    return addresses&&values&&reverse&&pointer_alias&&worker_shared&&opaque_preserved?0:1;
}
