// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0058acf0(112B),0058f410(284B),00598a50(31B),26B new sparse state.
#include "audio_stream_capture_fill_519.hpp"
#include <cstring>
namespace porsche {
AudioCaptureCounters519 audio_capture_counters_006aefc0{};
std::uint16_t audio_stream_capture_units_006b4860=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
template<class F>F method(U object,U offset){return reinterpret_cast<F>(word(word(object)+offset));}
}
U __cdecl audio_stream_copy_forward_00598a50(U destination,U source,U bytes){
    const U words=bytes>>2u;
    for(U index=0;index<words;++index)store(destination+index*4u,word(source+index*4u));
    const U start=words*4u;
    for(U index=0;index<(bytes&3u);++index)*reinterpret_cast<B*>(destination+start+index)=*reinterpret_cast<const B*>(source+start+index);
    return bytes;
}
I __cdecl audio_stream_capture_poll_0058f410(U destination){
    U frame[4]; // Original16B out-only slots: opaque until successful COM writes.
    U object=audio_stream_capture_006aefb8.buffer;
    using Position=I(__stdcall*)(U,U*,U*);
    if(method<Position>(object,0x10)(object,frame+3,frame)!=0)return -1;
    const U shift=audio_capture_counters_006aefc0.shift;
    const U current=frame[0]>>(shift&31u);
    const U previous=audio_capture_counters_006aefc0.last;
    const U ring=audio_capture_counters_006aefc0.ring;
    frame[0]=current;
    const U advance=current>=previous?current-previous:ring-previous+current;
    const U produced=audio_capture_counters_006aefc0.produced+advance;
    const U chunk=audio_capture_counters_006aefc0.chunk;
    audio_capture_counters_006aefc0.last=current;
    const U consumed=audio_capture_counters_006aefc0.consumed;
    audio_capture_counters_006aefc0.produced=produced;
    if(produced-consumed<chunk)return -1;
    const U bytes=chunk<<(shift&31u);
    object=audio_stream_capture_006aefb8.buffer;
    const U offset=(consumed%ring)<<(shift&31u);
    using Lock=I(__stdcall*)(U,U,U,U*,U*,U*,U*,U);
    if(method<Lock>(object,0x20)(object,offset,bytes,frame+1,frame+2,nullptr,nullptr,0)!=0)return -1;
    const U copy_bytes=audio_capture_counters_006aefc0.chunk<<(audio_capture_counters_006aefc0.shift&31u);
    (void)audio_stream_copy_forward_00598a50(destination,frame[1],copy_bytes);
    const U locked_bytes=frame[2];
    object=audio_stream_capture_006aefb8.buffer;
    using Unlock=I(__stdcall*)(U,U,U,U,U);
    if(method<Unlock>(object,0x2c)(object,frame[1],locked_bytes,0,0)!=0)return -1;
    const U completed=audio_capture_counters_006aefc0.chunk;
    const U before=audio_capture_counters_006aefc0.consumed;
    audio_capture_counters_006aefc0.consumed=before+completed;
    return 0;
}
I __cdecl audio_stream_capture_read_0058acf0(U destination){
    if(audio_stream_capture_poll_0058f410(audio_stream_backend_buffer_006b4864)<0)return -1;
    const B format=audio_stream_backend_format_006b4862;
    if(format==8){
        // Original DWORD load AND FFFF: BYTE62 and opaque BYTE63 are immaterial.
        const U bytes=static_cast<U>(audio_stream_capture_units_006b4860)*2u;
        (void)audio_stream_copy_forward_00598a50(destination,audio_stream_backend_buffer_006b4864,bytes);
        return static_cast<I>(bytes);
    }
    if(format==0x40){
        audio_stream_transform_00597660(audio_stream_backend_buffer_006b4864,destination);
        return 14;
    }
    return static_cast<I>(destination);
}
}
