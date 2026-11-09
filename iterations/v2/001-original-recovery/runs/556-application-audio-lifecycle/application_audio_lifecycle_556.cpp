// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 004ae010/228B,004ae2b0/88B,004ae310/163B. Existing478 object root is canonical.
#include "application_audio_lifecycle_556.hpp"
#include "porsche/fe_stream.hpp"
#include <cstring>
namespace porsche {
std::uint32_t application_audio_selected_channel_00655d30=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U value;std::memcpy(&value,reinterpret_cast<void*>(p),4);return value;}
void store(U p,U value){std::memcpy(reinterpret_cast<void*>(p),&value,4);}
// Reload the canonical root after every possible external effect. A callback
// may replace it; adding a null guard after those calls would change faults.
bool clear_current(){
    U object=audio_resource_query_root_00656ab4;if(!object)return false;
    if(word(object+0x78)){
        (void)window_scheduler_remove_005366a0(application_audio_service_callback_004ad9c0);
        object=audio_resource_query_root_00656ab4;store(object+0x78,0);object=audio_resource_query_root_00656ab4;
    }
    const U channel=word(object+0x70);
    if(static_cast<I>(channel)>=0){
        (void)application_audio_stream_stop_00567690(channel);
        object=audio_resource_query_root_00656ab4;store(object+0x70,0xffffffffu);object=audio_resource_query_root_00656ab4;
    }
    store(object+0x7c,0);return true;
}
}
void __cdecl application_audio_probe_prepare_004ae2b0(){(void)clear_current();}
void __cdecl application_audio_shutdown_device_004ae310(){
    if(!clear_current())return;
    U object=audio_resource_query_root_00656ab4;
    const U first=word(object+0x6c);if(first)(void)free_00531f90(reinterpret_cast<void*>(first));
    object=audio_resource_query_root_00656ab4;
    const U second=word(object+0x88);if(second)(void)free_00531f90(reinterpret_cast<void*>(second));
    object=audio_resource_query_root_00656ab4;(void)free_00531f90(reinterpret_cast<void*>(object));
    audio_resource_query_root_00656ab4=0;
}
void __cdecl application_audio_transition_configure_004ae010(U configuration,U){
    U object=audio_resource_query_root_00656ab4;if(!object)return;
    if(word(object+0x7c)==0){store(object+0x7c,1);object=audio_resource_query_root_00656ab4;}
    const I signed_configuration=static_cast<I>(configuration);
    store(object+0x84,static_cast<U>(signed_configuration/40));object=audio_resource_query_root_00656ab4;
    if(static_cast<I>(word(object+0x70))<0&&word(object+0x6c)!=0){
        const U units=static_cast<U>(signed_configuration/1024);
        const U estimated=application_audio_stream_estimate_005678c0(1,units);
        const U required=estimated+configuration;
        B descriptor[28]; // +0x16/+0x17 remain opaque; original child leaves them unwritten.
        (void)application_audio_stream_descriptor_00561960(descriptor);
        object=audio_resource_query_root_00656ab4;descriptor[8]=0;descriptor[10]=0;
        const I channel=application_audio_stream_begin_00567660(descriptor,1,units,word(object+0x6c),required);
        object=audio_resource_query_root_00656ab4;store(object+0x70,static_cast<U>(channel));object=audio_resource_query_root_00656ab4;
    }
    application_audio_selected_channel_00655d30=word(object+0x70);
    if(word(object+0x78)==0){
        (void)window_scheduler_register_005365e0(application_audio_service_callback_004ad9c0,0x19,0);
        object=audio_resource_query_root_00656ab4;store(object+0x78,1);
    }
}
}
