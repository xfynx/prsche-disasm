// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0056b380/45B, 0056b4c0/122B, 0056c840/80B, 005912e0/58B.
#include "audio_codec_access_565.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 pointer and ABI semantics required
#endif
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void put(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
const char greedy_message[]="STREAM_setgreedylevel - invalid stream handle\n";
const char frame_message[]="STREAM_buffersize - invalid stream handle\n";
}
U __cdecl audio_stream_handle_validate_0056b380(U handle,U* object,U* original){
    if(!handle)return 1;
    const U value=word(handle);
    if(word(value)!=0x4d525453u)return 1;
    std::memcpy(original,&handle,4);
    std::memcpy(object,&value,4);
    return 0;
}
void __cdecl audio_stream_greedy_set_0056b4c0(U handle,I level){
    U object,original;
    if(audio_stream_handle_validate_0056b380(handle,&object,&original)){
        class_error_file_005deb74=0x005bd978;class_error_line_005deb78=0x518;
        diagnostic_handler_005debf0(greedy_message);return;
    }
    const I previous=static_cast<I>(word(object+0x34));
    put(object+0x34,static_cast<U>(level));
    const I current=static_cast<I>(word(object+0x3c));
    const U next=current<level;
    if((current<previous)!=static_cast<bool>(next))audio_stream_greedy_transition_0056b540(handle,next);
}
I __cdecl audio_stream_codec_frames_0056c840(U handle){
    U object,original;
    if(audio_stream_handle_validate_0056b380(handle,&object,&original)){
        class_error_file_005deb74=0x005bd978;class_error_line_005deb78=0x931;
        diagnostic_handler_005debf0(frame_message);return 0;
    }
    return static_cast<I>(word(object+0x24)-word(object+0x20));
}
I __cdecl audio_stream_codec_set_005912e0(U index,I level){
    if(application_audio_device_state_006b48c0[0xdc]==0)return -10;
    const U object=audio_stream_service_lookup_00566d60(static_cast<I>(index));
    if(!object)return -8;
    audio_stream_greedy_set_0056b4c0(word(object+4),level);
    return 0;
}
}
