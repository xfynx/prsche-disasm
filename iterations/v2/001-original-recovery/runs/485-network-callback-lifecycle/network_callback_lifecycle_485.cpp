// Original Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00560340 /61B and00561110 /101B. New original state60B; existing canonical
// audio/device state owns byte6b49a0 and DWORD table6b49b0.
#include "network_callback_lifecycle_485.hpp"
#include "porsche/application_audio_device.hpp"
#include "porsche/file_device.hpp"
#include "porsche/file_threads.hpp"
#include "audio_canonical_434.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
U callback(U index){U value;std::memcpy(&value,application_audio_device_state_006b48c0.data()+0xf0+index*4u,4);return value;}
void callback(U index,U value){std::memcpy(application_audio_device_state_006b48c0.data()+0xf0+index*4u,&value,4);}
I signed_count(std::uint8_t value){return static_cast<std::int8_t>(value);}
}
std::uint32_t network_callbacks_initialized_006a5b28=0;
IoList network_callbacks_list_006b7d00{};
IoList network_callbacks_list_006b7d20{};
std::uint8_t& network_lifecycle_callback_count_006b49a0=application_audio_device_state_006b48c0[0xe0];

void __cdecl network_callbacks_start_00560340(){
    if(network_callbacks_initialized_006a5b28==0){
        io_init_00580630(&network_callbacks_list_006b7d20,nullptr,0);
        io_init_00580630(&network_callbacks_list_006b7d00,nullptr,0);
        thread_exit_register_00557380(network_callbacks_stop_00560380);
        network_callbacks_initialized_006a5b28=1;
    }
}

void __cdecl network_lifecycle_unregister_00561110(U value){
    audio_backend_lock_005896d0();
    const std::uint8_t captured=network_lifecycle_callback_count_006b49a0;
    const I count=signed_count(captured);
    I index=0;
    if(count>0){
        while(callback(static_cast<U>(index))!=value){
            ++index;
            if(index>=count){audio_backend_unlock_005896f0();return;}
        }
        const auto reduced=static_cast<std::uint8_t>(captured-1u);
        network_lifecycle_callback_count_006b49a0=reduced;
        if(index<signed_count(reduced)){
            do {
                const U next=callback(static_cast<U>(index)+1u);
                ++index;
                callback(static_cast<U>(index)-1u,next);
            } while(index<signed_count(network_lifecycle_callback_count_006b49a0));
        }
    }
    audio_backend_unlock_005896f0();
}
}
