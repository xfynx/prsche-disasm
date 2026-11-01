// Original Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_mixer_ramp_stop_479.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 instruction boundaries require MSVC x86
#endif
namespace porsche {
std::uint32_t audio_mixer_stopped_hook_006b16a8=0;
// Exact raw original FLOAT32 words, decoded in original-evidence.json.
const float audio_mixer_gain_scale_005b246c=0x1.8p0f;
const float audio_mixer_gain_floor_005b2738=0x1.47ae14p-8f;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address){U x;std::memcpy(&x,reinterpret_cast<const void*>(address),4);return x;}
void store(U address,U x){std::memcpy(reinterpret_cast<void*>(address),&x,4);}
U lanes(){return audio_release_channel_count_006b16a5;}
U float_count(I count){U value;__asm {
    fild dword ptr count
    fstp dword ptr value
    }return value;}
U delta(U target,U current,U divisor){U value;__asm {
    fld dword ptr target
    fsub dword ptr current
    fdiv dword ptr divisor
    fstp dword ptr value
    }return value;}
U advance(U address,U step){U value;__asm {
    mov ecx,address
    fld dword ptr step
    fadd dword ptr [ecx]
    fst dword ptr value
    fstp dword ptr [ecx]
    }return value;}
void advance_volume(U address,U step){__asm {
    mov ecx,address
    fld dword ptr step
    fadd dword ptr [ecx]
    fstp dword ptr [ecx]
    }}
void target(U destination,U gain,U factor){unsigned short status;__asm {
    mov ecx,destination
    fld dword ptr gain
    fmul dword ptr factor
    fst dword ptr [ecx]
    fcomp audio_mixer_gain_floor_005b2738
    fnstsw ax
    mov status,ax
    }if(status&0x100u)store(destination,0);}
}
void __cdecl audio_mixer_refresh_gain_005980a0(U record){__asm {
    mov eax,record
    fld dword ptr [eax+0ch]
    fmul dword ptr [eax+4]
    fmul audio_mixer_gain_scale_005b246c
    fstp dword ptr [eax+8]
    }}
U __cdecl audio_mixer_ramp_voice_005980c0(U record,U count){
    if(static_cast<I>(count)>32)count=32;
    auto& state=audio_release_storage_006b174c;
    const U object=word(record+0x34);
    const I result=reinterpret_cast<I(__cdecl*)(U,U,U,U,U)>(word(object+4))(object,count,state.aligned[0],state.aligned[1],0);
    if(result<=0){
        store(record+0xc,word(record+0x10));
        const U captured_count=lanes();
        for(U lane=0;lane<captured_count;++lane)store(record+0x14+lane*4,word(record+0x24+lane*4));
        return 0;
    }
    const U divisor=float_count(static_cast<I>(count));
    const U volume_delta=delta(word(record+0x10),word(record+0xc),divisor);
    for(U lane=0;lane<lanes();++lane){
        const U cell=record+0x14+lane*4;
        const U lane_delta=delta(word(cell+0x10),word(cell),divisor);
        for(U sample=0;static_cast<I>(sample)<static_cast<I>(count);++sample){
            const U factor=advance(cell,lane_delta);
            reinterpret_cast<void(__cdecl*)(U,U,U,U)>(audio_mixer_accumulate_006b17d4)(1,factor,state.aligned[1]+sample*4,state.channel_aligned[lane]+sample*4);
            if(lane==lanes()-1u){
                advance_volume(record+0xc,volume_delta);
                audio_mixer_refresh_gain_005980a0(record);
                if(const U hook=audio_mixer_voice_hook_006b16b4)
                    reinterpret_cast<void(__cdecl*)(U,U,U,U)>(hook)(record,1,state.aligned[1]+sample*4,sample);
            }
        }
        store(cell,word(cell+0x10));
    }
    store(record+0xc,word(record+0x10));
    return count;
}
void __cdecl audio_mixer_target_slot_00598700(U index,U gain_bits,const U* factors){
    const U record=audio_release_storage_006b174c.table+index*0x50u;
    const U captured_count=lanes();
    reinterpret_cast<std::uint8_t*>(record)[1]=1;store(record+0x10,gain_bits);
    for(U lane=0;lane<captured_count;++lane)target(record+0x24+lane*4,gain_bits,factors[lane]);
}
void __cdecl audio_mixer_detach_slot_00598690(U index){
    const U record=audio_release_storage_006b174c.table+index*0x50u;
    const U zero[4]={0,0,0,0};
    audio_mixer_target_slot_00598700(index,0,zero);
    (void)audio_mixer_ramp_voice_005980c0(record,256);
    U object=word(record+0x34);
    do{const U next=word(object);(void)audio_backend_pool_release_0058ac30(object);object=next;}while(object!=0);
    store(record+0x34,0);reinterpret_cast<std::uint8_t*>(record)[0]=0;
}
void __cdecl audio_mixer_stop_slot_00598670(U index){
    audio_mixer_detach_slot_00598690(index);
    reinterpret_cast<void(__cdecl*)(U)>(audio_mixer_stopped_hook_006b16a8)(index);
}
}
