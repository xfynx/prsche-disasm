#include "porsche/window_handlers.hpp"
#include "porsche/window_runtime.hpp"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace {
std::uint32_t quit_calls, pump_calls, dispatch_calls, spi_calls;
std::uint32_t spi_values[2];
}
namespace porsche {
// Fixture only: unique bounded startup keys, no wraparound ordering.
void __cdecl window_handler_sort_005a112b(void* rows,std::uint32_t count,
    std::uint32_t bytes,std::int32_t (__cdecl* compare)(const void*,const void*)) {
    std::qsort(rows,count,bytes,compare);
}
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* class_lock_0069e59c;
std::uint32_t& window_running_006b7c14=window_configuration_storage_006b77a0.running_006b7c14;
std::uint32_t& window_width_006b77b4=window_configuration_storage_006b77a0.width_006b77b4;
std::uint32_t& window_height_006b77b8=window_configuration_storage_006b77a0.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=window_configuration_storage_006b77a0.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;
std::uint32_t window_saved_parameter_0069e57c,window_saved_parameter_0069e580;
std::uint32_t worker_message_state_0069e578;
void* window_configuration_address_006b77a0=&window_configuration_storage_006b77a0;
void*& worker_configuration_006b77a0=window_configuration_address_006b77a0;
void* __cdecl window_lock_create_005321f0(){return reinterpret_cast<void*>(0x22220000);}
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t){++pump_calls;return 0;}
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t){++dispatch_calls;return 0;}
void __stdcall window_handler_post_quit_message(std::uint32_t){++quit_calls;}
std::int32_t __stdcall window_default_procedure(void*,std::uint32_t,std::uint32_t,std::int32_t){return 0;}
std::uint32_t __stdcall window_system_parameters(std::uint32_t action,std::uint32_t,void* out,std::uint32_t) {
    ++spi_calls;
    if(action==0x10 || action==0x54) {
        const auto index=action==0x10?0u:1u;
        *static_cast<std::uint32_t*>(out)=spi_values[index];
    }
    return 1;
}
}

int main(){
    using namespace porsche;
    std::uint32_t mode,a,b,c,d,e,f;
    while(std::cin>>mode>>a>>b>>c>>d>>e>>f){
        quit_calls=pump_calls=dispatch_calls=spi_calls=0;
        if(mode==0){
            const auto count=a,key=b,value=c,lock=d;
            if(count>128)return 2;
            std::memset(window_handlers_0069e0e0,0xcc,sizeof(window_handlers_0069e0e0));
            window_handler_count_0069e570=count;
            for(std::uint32_t i=0;i<count;++i)
                window_handlers_0069e0e0[i]={10u+10u*i,reinterpret_cast<WindowHandler>(0x1000u+i)};
            class_lock_0069e59c=lock?reinterpret_cast<void*>(0x22220000):nullptr;
            const auto result=window_handler_register_0053a800(key,value);
            std::cout<<result<<' '<<window_handler_count_0069e570<<' '<<(class_lock_0069e59c!=nullptr)<<' '
                <<pump_calls<<' '<<dispatch_calls;
            for(std::uint32_t i=0;i<window_handler_count_0069e570;++i)
                std::cout<<' '<<window_handlers_0069e0e0[i].message<<':'
                    <<reinterpret_cast<std::uintptr_t>(window_handlers_0069e0e0[i].handler);
            std::cout<<'\n';
            continue;
        }
        auto& config=window_configuration_storage_006b77a0;
        std::memset(&config,0,sizeof(config));
        config.fullscreen_006b7c01=static_cast<std::uint8_t>(c);
        config.hwnd_006b7bf8=reinterpret_cast<void*>(static_cast<std::uintptr_t>(e));
        const bool has_config=a!=0;
        window_hwnd_006b7bf8=reinterpret_cast<void*>(0x1234);
        window_running_006b7c14=d;
        worker_message_state_0069e578=0;
        window_saved_parameter_0069e57c=window_saved_parameter_0069e580=0;
        spi_values[0]=f&1u;spi_values[1]=(f>>1)&1u;
        std::int32_t out=static_cast<std::int32_t>(0x76543210);
        auto* cfg=has_config?reinterpret_cast<void*>(&config):nullptr;
        auto* hwnd=b?reinterpret_cast<void*>(0x1234):reinterpret_cast<void*>(0x5678);
        const auto wp=d;
        std::uint32_t result=0;
        switch(mode){
        case 1: result=window_handler_0053b040(cfg,hwnd,0,wp,0,&out);break;
        case 2: result=window_handler_0053b230(cfg,hwnd,0,wp,0,&out);break;
        case 3: result=window_handler_0053b260(cfg,hwnd,0,wp,0,&out);break;
        case 4: result=window_handler_0053b290(cfg,hwnd,0,wp,0,&out);break;
        case 5: result=window_handler_0053b2a0(cfg,hwnd,0,wp,0,&out);break;
        case 6: result=window_handler_0053b2e0(cfg,hwnd,0,wp,0,&out);break;
        case 7: result=window_handler_0053b870(cfg,hwnd,0,wp,0,&out);break;
        case 8: result=window_handler_0053b8b0(cfg,hwnd,0,wp,0,&out);break;
        default:return 3;
        }
        std::cout<<result<<' '<<static_cast<std::uint32_t>(out)<<' '
            <<window_running_006b7c14<<' '<<worker_message_state_0069e578<<' '
            <<quit_calls<<' '<<spi_calls<<' '<<window_saved_parameter_0069e57c<<' '
            <<window_saved_parameter_0069e580<<' '<<pump_calls<<' '<<dispatch_calls<<'\n';
    }
}
