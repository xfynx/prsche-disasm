// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Four original bodies244B; six exact sparse state spans41B.
#include "audio_stream_worker_stop_513.hpp"
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
#include <cstring>
namespace porsche {
AudioStreamLimits513 audio_stream_limits_006b7ca4{};
AudioStreamCursor513 audio_stream_cursor_006b7cb0{};
AudioStreamCapture513 audio_stream_capture_006aefb8{};
std::uint8_t audio_stream_backend_format_006b4862=0;
std::uint32_t audio_stream_backend_buffer_006b4864=0;
std::uint32_t audio_stream_encoded_scratch_006b17dc=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
}
void __cdecl audio_stream_encoded_release_005977f0(){
    const U scratch=audio_stream_encoded_scratch_006b17dc;
    if(scratch!=0){
        (void)audio_backend_pool_release_0058ac30(scratch);
        audio_stream_encoded_scratch_006b17dc=0;
    }
}
I __cdecl audio_stream_capture_release_0058f530(){
    const U object=audio_stream_capture_006aefb8.object;
    if(object!=0)reinterpret_cast<U(__stdcall*)(U)>(word(word(object)+8u))(object);
    audio_stream_capture_006aefb8.object=0;audio_stream_capture_006aefb8.buffer=0;
    return 0;
}
void __cdecl audio_stream_backend_stop_0058ad60(){
    if(audio_stream_backend_format_006b4862==0x40)audio_stream_encoded_release_005977f0();
    (void)audio_backend_pool_release_0058ac30(audio_stream_backend_buffer_006b4864);
    (void)audio_stream_capture_release_0058f530();
}
void __cdecl audio_stream_dispatch_005619b0(){
    U capacity=audio_stream_limits_006b7ca4.capacity;
    U stride=audio_stream_cursor_006b7cb0.stride;
    U cursor=audio_stream_cursor_006b7cb0.cursor;
    for(;;){
        const U needed=audio_stream_cursor_006b7cb0.queued+stride*2u;
        if(needed>capacity)return;
        const U payload=cursor+0x1cu;
        const I length=audio_stream_capture_read_0058acf0(payload);
        if(length<0)return;
        const U format=audio_stream_cursor_006b7cb0.format;
        const U size=static_cast<U>(length)+0x1cu;
        store(cursor,format);
        store(cursor+4u,audio_stream_limits_006b7ca4.channels);
        const U queued=audio_stream_cursor_006b7cb0.queued;
        store(cursor+8u,static_cast<U>(length));
        const U begin=audio_stream_output_buffer_006b7ca0;
        store(cursor+0xcu,payload);
        cursor=audio_stream_cursor_006b7cb0.cursor;
        cursor+=size;
        capacity=audio_stream_limits_006b7ca4.capacity;
        audio_stream_cursor_006b7cb0.queued=queued+size;
        stride=audio_stream_cursor_006b7cb0.stride;
        audio_stream_cursor_006b7cb0.cursor=cursor;
        if(cursor+stride>begin+capacity){
            cursor=begin;audio_stream_cursor_006b7cb0.cursor=cursor;
        }
    }
}
}
