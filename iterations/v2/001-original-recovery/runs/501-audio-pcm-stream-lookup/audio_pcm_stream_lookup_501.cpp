// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0059c130(60B),0059ca50(245B). Canonical stream slot pointers64B.
#include "audio_pcm_stream_lookup_501.hpp"
#include <cstring>
namespace porsche {
std::uint32_t audio_stream_slots_006b7cc0[16]{};
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U value;std::memcpy(&value,reinterpret_cast<const void*>(p),4);return value;}
void store(U p,U value){std::memcpy(reinterpret_cast<void*>(p),&value,4);}
U byte(U p){return *reinterpret_cast<const B*>(p);}
}
I __cdecl audio_pcm_stream_find_0059c130(I owner){
    for(U index=0;index<16;++index){
        const U record=audio_stream_slots_006b7cc0[index];
        if(record!=0&&audio_backend_find_channel_00589d20(word(record))==owner)return static_cast<I>(index);
    }
    return -1;
}
I __cdecl audio_pcm_stream_process_0059ca50(U object,U count,U,U output,U){
    const U prior=word(object+0x1c);
    if(prior!=0){
        audio_stream_acknowledge_005618c0(word(object+0x18),byte(object+0x21),prior);
        store(object+0x1c,0);
    }
    U remaining=count;
    // The original uses its saved output argument stack slot as the length
    // out-parameter; preserve that slot's initial value before the first call.
    U acquired_length=output;
    while(static_cast<I>(remaining)>0){
        if(static_cast<I>(word(object+0x14))>=static_cast<I>(word(object+0x10))){
            const U data=audio_stream_acquire_00561800(word(object+0x18),byte(object+0x21),&acquired_length);
            store(object+0xc,data);
            if(data==0){
                const U processed=word(object+0x1c);
                if(processed!=0)application_audio_backend_configure_0058fef0(output,remaining*4u);
                return static_cast<I>(processed);
            }
            store(object+0x14,0);store(object+0x10,acquired_length);
        }
        const U position=word(object+0x14);
        U block=word(object+0x10)-position;
        if(static_cast<I>(remaining)<static_cast<I>(block))block=remaining;
        const U wide=byte(object+0x20),data=word(object+0xc);
        if(wide!=0)reinterpret_cast<void(__cdecl*)(U,U,U)>(audio_mixer_decode_s16_006b17d8)(block,data+position*2u,output);
        else audio_pcm_decode_u8_0059a520(block,data+position,output);
        const U processed=word(object+0x1c);
        remaining-=block;store(object+0x14,position+block);
        output+=block*4u;store(object+0x1c,processed+block);
    }
    return static_cast<I>(word(object+0x1c));
}
}
