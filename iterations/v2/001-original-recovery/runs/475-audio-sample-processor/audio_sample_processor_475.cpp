// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete original00598760..00598937,472B. Original x86 cdecl2.
#include "audio_sample_processor_475.hpp"
#include "../382-rectangle/rectangle.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 comparison requires MSVC x86
#endif
namespace porsche {
std::uint32_t audio_mixer_voice_hook_006b16b4=0;
std::uint32_t audio_mixer_block_hook_006b16b8=0;
std::uint32_t audio_mixer_accumulate_006b17d4=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
U lane_count(){return audio_release_channel_count_006b16a5;}
U voice_count(){return audio_release_format_006b16a4&255u;}
// Original FLD/FST32/FCOMP skips ZF/C3 for both zero and unordered.
// The FST32 result (including quieted SNaN) is the raw callback argument.
bool audible(U address,U& factor){U bits=word(address),stored;unsigned short status;
    __asm {
        fld dword ptr bits
        fst dword ptr stored
        fcomp rectangle_zero_005b23f8
        fnstsw ax
        mov status,ax
    }
    factor=stored;return (status&0x4000u)==0;
}
I process(U object,U count,U input,U output){
    return reinterpret_cast<I(__cdecl*)(U,U,U,U,U)>(word(object+4))(object,count,input,output,0);
}
}
void __cdecl audio_mixer_process_block_00598760(U count,U* buffers){
    auto& state=audio_release_storage_006b174c;
    for(U index=0;index<voice_count();++index){
        const U record=state.table+index*0x50u;
        auto* bytes=reinterpret_cast<B*>(record);
        if(bytes[0]!=2)continue;
        U consumed=0,remaining=count;
        if(bytes[1]!=0){
            consumed=audio_mixer_ramp_voice_005980c0(record,count);
            remaining-=consumed;bytes[1]=0;
        }
        if(remaining==0)continue;
        const I result=process(word(record+0x34),remaining,state.aligned[0],state.aligned[1]);
        if(result<0){audio_mixer_stop_slot_00598670(index);continue;}
        if(result==0)continue;
        for(U lane=0;lane<lane_count();++lane){
            U factor;
            if(audible(record+0x14+lane*4,factor)){
                const U destination=state.channel_aligned[lane]+consumed*4u;
                reinterpret_cast<void(__cdecl*)(U,U,U,U)>(audio_mixer_accumulate_006b17d4)(remaining,factor,state.aligned[1],destination);
            }
        }
        if(const U hook=audio_mixer_voice_hook_006b16b4)
            reinterpret_cast<void(__cdecl*)(U,U,U,U)>(hook)(record,remaining,state.aligned[1],consumed);
    }
    if(const U hook=audio_mixer_block_hook_006b16b8)
        reinterpret_cast<void(__cdecl*)(U)>(hook)(count);
    for(U lane=0;lane<lane_count();++lane){
        const U filter=state.filter[lane];
        if(filter!=0){
            (void)process(filter,count,state.channel_aligned[lane],state.aligned[0]);
            (void)process(state.channel_word[lane],count,state.aligned[0],buffers[lane]);
        }else (void)process(state.channel_word[lane],count,state.channel_aligned[lane],buffers[lane]);
        application_audio_backend_configure_0058fef0(state.channel_aligned[lane],count*4u);
    }
}
}
