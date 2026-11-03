// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Eight originals397B; sparse006b7ca0 DWORD is the only new state.
#include "audio_stream_producer_lifecycle_508.hpp"
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
#include <cstring>
namespace porsche {
std::uint32_t audio_stream_output_buffer_006b7ca0=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
I signed_half(U p){std::int16_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
bool initialized(){return application_audio_device_state_006b48c0[0xdc]!=0;}
}
U __cdecl audio_stream_prefix_bytes_00589790(){return 0;}
I __cdecl audio_stream_attach_005897a0(U,U){return 0;}
void __cdecl audio_stream_detach_005897b0(U){}
void __cdecl audio_stream_cancel_range_00561720(U,U,U){}
I __cdecl audio_stream_construct_00561200(U release,U consumed,U buffer,U bytes){
    if(!initialized())return -10;
    U index=0;
    while(index<16&&audio_stream_slots_006b7cc0[index]!=0)++index;
    if(index==16)return -9;
    if(audio_stream_attach_005897a0(index,buffer)<0)return -6;
    const U record=buffer+audio_stream_prefix_bytes_00589790();
    const U prefix=audio_stream_prefix_bytes_00589790();
    audio_stream_slots_006b7cc0[index]=record;
    const auto capacity=static_cast<std::uint16_t>((bytes-prefix-96u)/24u);
    std::memcpy(reinterpret_cast<void*>(record+0x18),&capacity,2);
    store(record+0x28,buffer);store(record+0x2c,release);store(record+0x30,consumed);
    store(record,0xffffffffu);
    return static_cast<I>(index);
}
void __cdecl network_lifecycle_device_cancel_00561730(U index){
    if(!initialized())return;
    U record=audio_stream_slots_006b7cc0[index];
    audio_backend_lock_005896d0();
    (void)audio_channel_stop_00565d60(word(record));
    audio_stream_cancel_range_00561720(index,0,0x7fffffffu);
    const U release=word(record+0x2c);
    if(release!=0&&signed_half(record+0x1c)>=0){
        const U previous=record+(static_cast<U>(signed_half(record+0x1c))+3u)*24u;
        reinterpret_cast<void(__cdecl*)(U)>(release)(word(previous+8u));
    }
    store(record,0xffffffffu);
    U count=*reinterpret_cast<const std::uint8_t*>(record+0x36);
    if(static_cast<I>(count)>0){
        record+=0x38;
        do{
            const U voice=word(record);
            if(voice!=0)(void)audio_backend_pool_release_0058ac30(voice);
            record+=4u;--count;
        }while(count!=0);
    }
    audio_backend_unlock_005896f0();
}
void __cdecl network_lifecycle_device_release_005617d0(U index){
    if(!initialized())return;
    audio_stream_detach_005897b0(index);
    audio_stream_slots_006b7cc0[index]=0;
}
void __cdecl network_lifecycle_device_stop_00561b50(){
    if(audio_stream_output_buffer_006b7ca0==0)return;
    network_lifecycle_unregister_00561110(reinterpret_cast<U>(&audio_stream_dispatch_005619b0));
    audio_stream_backend_stop_0058ad60();
    audio_stream_output_buffer_006b7ca0=0;
}
}
