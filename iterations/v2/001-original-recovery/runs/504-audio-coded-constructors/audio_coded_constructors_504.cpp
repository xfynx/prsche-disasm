// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_coded_constructors_504.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original x87 setup requires MSVC x86
#endif
namespace porsche {
std::uint32_t audio_adpcm_bit_masks_005e34a0[9]={0,1,3,7,15,31,63,127,255};
const float audio_adpcm_scale_005b2608=8.0f;
const float audio_adpcm_factor_scale_005b27b4=0.001f;
const float audio_adpcm_factor_bias_005c1804=1.04f;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U value;std::memcpy(&value,reinterpret_cast<const void*>(p),4);return value;}
void store(U p,U value){std::memcpy(reinterpret_cast<void*>(p),&value,4);}
void half(U p,std::uint16_t value){std::memcpy(reinterpret_cast<void*>(p),&value,2);}
void byte(U p,B value){*reinterpret_cast<B*>(p)=value;}
U parameter(const U* params,U index){return word(reinterpret_cast<U>(params)+index*4u);}
template<class T>U address(T fn){return reinterpret_cast<U>(fn);}
U decoder(U flags){
    if(flags&4u)return address(&audio_nibble_decode_3dnow_0059a730);
    if(flags&2u)return address(&audio_nibble_decode_sse_0059a660);
    return address(&audio_nibble_decode_x87_0059a5a0);
}
void scaled(U value,U destination){const unsigned long long integer=value;__asm {
    mov ecx,destination
    fild qword ptr integer
    fmul audio_adpcm_scale_005b2608
    fstp dword ptr [ecx]
}}
// Extended factor stays in ST0 through the63-step C++ recurrence. Only these
// fixed private primitives run while it is live; no foreign call or C++ FP math.
void push_factor(U value){const unsigned long long integer=value;__asm {
    fild qword ptr integer
    fmul audio_adpcm_factor_scale_005b27b4
    fadd audio_adpcm_factor_bias_005c1804
}}
void coefficient(U destination){__asm {
    mov ecx,destination
    fld st(0)
    fmul dword ptr [ecx-4]
    fstp dword ptr [ecx]
}}
void pop_factor(){__asm fstp st(0)}
}
U __cdecl audio_adpcm_read_bits_0059a8c0(U state,U bits){
    const U payload=word(state+4);
    const U mask=word(reinterpret_cast<U>(audio_adpcm_bit_masks_005e34a0)+bits*4u);
    U remaining=word(state+8);
    const U result=mask&payload;
    const U shifted=payload>>(bits&31u);
    remaining-=bits;
    store(state+8,remaining);store(state+4,shifted);
    if(static_cast<I>(remaining)<8){
        const U pointer=word(state);
        const U next=*reinterpret_cast<const B*>(pointer);
        const U combined=(next<<(remaining&31u))|shifted;
        store(state,pointer+1u);remaining+=8u;
        store(state+4,combined);store(state+8,remaining);
    }
    return result;
}
void __cdecl audio_adpcm_initialize_0059a800(U data,U state){
    const U first=*reinterpret_cast<const B*>(data);
    store(state+4,first);store(state+8,8);store(state,data+1u);
    (void)audio_adpcm_read_bits_0059a8c0(state,1);
    const U width=audio_adpcm_read_bits_0059a8c0(state,4);
    store(state+0xc,32u-width);
    const U initial=audio_adpcm_read_bits_0059a8c0(state,4)+1u;
    scaled(initial,state+0x10);
    const U factor=audio_adpcm_read_bits_0059a8c0(state,6);
    push_factor(factor);
    for(U i=0;i<63;++i)coefficient(state+0x14+i*4u);
    pop_factor();
    for(U i=0;i<12;++i){store(state+0x110+i*4u,0);store(state+0x140+i*4u,0);}
    for(U i=0;i<0x144;++i)store(state+0x170+i*4u,0);
}
U __cdecl audio_nibble_position_00597db0(U object){return word(object+0x28);}
U __cdecl audio_adpcm_position_00597e20(U object){return word(object+0xd54);}
void __cdecl audio_mixer_construct_adpcm_00597f20(U object,U* params){
    const U data=parameter(params,0);
    audio_adpcm_initialize_0059a800(data,object+0xc);
    const U limit=parameter(params,3);
    store(reinterpret_cast<U>(params)+0x1c,address(&audio_adpcm_position_00597e20));
    store(object+4,address(&audio_adpcm_process_00597e30));store(object+0xd4c,limit);
    store(object+0xd50,0);store(object+0xd54,0);
}
void __cdecl audio_mixer_construct_adpcm_stream_0059c360(U object,U* params){
    const U channel=parameter(params,5);
    store(object+4,address(&audio_adpcm_stream_process_0059c1e0));
    const I owner=audio_pcm_channel_owner_00589710(channel);
    const I index=audio_pcm_stream_find_0059c130(owner);
    store(object+0xd54,static_cast<U>(index));
    const U member=audio_pcm_channel_member_00589740(channel);
    byte(object+0xd60,static_cast<B>(member));
    store(object+0xd4c,0);store(object+0xd50,0);half(object+0xd5c,0);half(object+0xd5e,0);store(object+0xd58,0);
}
void __cdecl audio_mixer_construct_nibble_00597dc0(U object,U* params){
    const U data=parameter(params,0);
    store(reinterpret_cast<U>(params)+0x1c,address(&audio_nibble_position_00597db0));store(object+0x20,data);
    const U limit=parameter(params,3),flags=parameter(params,6);
    store(object+0x24,limit);store(object+4,address(&audio_nibble_process_00597c40));
    store(object+0x28,0);store(object+0x2c,0);store(object+0x10,0);store(object+0x14,0);
    store(object+0x9c,decoder(flags));
}
void __cdecl audio_mixer_construct_nibble_loop_0059c9f0(U object,U* params){
    const U data=parameter(params,0),start=parameter(params,1);
    store(object+0x20,data);
    const U limit=parameter(params,3);store(object+0x2c,start);
    const U end=parameter(params,2),flags=parameter(params,6);
    store(object+0x24,limit);store(object+0x30,end);store(object+4,address(&audio_nibble_loop_process_0059c890));
    store(object+0x28,0);store(object+0x34,0);store(object+0x10,0);store(object+0x14,0);store(object+0x38,decoder(flags));
}
void __cdecl audio_mixer_construct_nibble_stream_0059c610(U object,U* params){
    store(object+4,address(&audio_nibble_stream_process_0059c3c0));
    const U channel=parameter(params,5);
    const I owner=audio_pcm_channel_owner_00589710(channel);
    const I index=audio_pcm_stream_find_0059c130(owner);
    store(object+0x2c,static_cast<U>(index));
    const U member=audio_pcm_channel_member_00589740(channel),limit=parameter(params,3);
    byte(object+0x39,static_cast<B>(member));
    store(object+0x20,0);store(object+0x28,0);byte(object+0x38,0);store(object+0x30,0);store(object+0x10,0);store(object+0x14,0);
    const U flags=parameter(params,6);store(object+0x24,limit);store(object+0x34,decoder(flags));
}
void __cdecl audio_mixer_construct_resampler_0059b830(U object,U* params){
    const U channel=parameter(params,5);
    store(object+4,address(&audio_resampler_stream_process_0059b690));
    const I owner=audio_pcm_channel_owner_00589710(channel);
    const I index=audio_pcm_stream_find_0059c130(owner);
    store(object+0xe0,static_cast<U>(index));
    const U member=audio_pcm_channel_member_00589740(channel);
    byte(object+0xec,static_cast<B>(member));
    store(object+0xd8,0);store(object+0xdc,0);half(object+0xe8,0);half(object+0xea,0);store(object+0xe4,0);
    for(U i=0;i<0x32;++i)store(object+0x10+i*4u,0);
}
}
