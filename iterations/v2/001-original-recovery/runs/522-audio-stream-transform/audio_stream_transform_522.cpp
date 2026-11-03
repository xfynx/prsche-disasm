// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00597660(390B),005a0f98(39B),00597120(87B);8B readonly, no mutable state.
#include "audio_stream_transform_522.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original x87 state and integer-return transport require MSVC x86
#endif
namespace porsche {
const float audio_stream_s16_scale_005b3e10=0x1.0p-15f;
const float audio_stream_coefficient_scale_005b3880=128.0f;
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
I sample(U p){std::int16_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),2);return v;}
// Eighteen original FP operations, no loop/count/control logic. FLOAT32
// stores and live extended intermediates must not become SSE/float expressions.
void filter_one(I value,U normalized,U output,U scratch){__asm {
    mov eax,scratch
    mov ecx,normalized
    mov edx,output
    fild value
    fmul audio_stream_s16_scale_005b3e10
    fstp dword ptr [ecx]
    fld dword ptr [ecx]
    fmul dword ptr [eax+3e88h]
    fld dword ptr [eax+3e84h]
    fmul dword ptr [eax+3e9ch]
    fsubp st(1),st(0)
    fstp dword ptr [eax+3e98h]
    fld dword ptr [eax+3e94h]
    fmul dword ptr [eax+3e9ch]
    fld dword ptr [eax+3e8ch]
    fmul dword ptr [eax+3ea0h]
    fsubp st(1),st(0)
    fld dword ptr [eax+3e90h]
    fmul dword ptr [eax+3ea4h]
    fsubp st(1),st(0)
    fstp dword ptr [edx]
}}
void multiply_one(U first,U second,U output){__asm {
    mov eax,first
    mov ecx,second
    mov edx,output
    fld dword ptr [eax]
    fmul dword ptr [ecx]
    fstp dword ptr [edx]
}}
void sum_product(U first,U second,U output){__asm {
    mov eax,first
    mov ecx,second
    mov edx,output
    fld dword ptr [eax]
    fmul dword ptr [ecx]
    fadd dword ptr [edx]
    fstp dword ptr [edx]
}}
std::int64_t scaled_integer(U input,const float* scale){
    __asm {
        mov eax,input
        mov edx,scale
        fld dword ptr [eax]
        fmul dword ptr [edx]
    }
    return audio_stream_ftol_005a0f98();
}
}
std::int64_t __cdecl audio_stream_ftol_005a0f98(){
    std::uint16_t saved,chop;
    std::int64_t result;
    __asm fstcw saved
    __asm fwait
    chop=static_cast<std::uint16_t>(saved|0x0c00u);
    __asm fldcw chop
    __asm fistp qword ptr result
    __asm fldcw saved
    return result;
}
void __cdecl audio_stream_correlate_00597120(U input,I count,I order,U output){
    if(order<0)return;
    U left=static_cast<U>(count),lags=static_cast<U>(order)+1u,lag=0;
    do{
        store(output,0);
        if(static_cast<I>(left)>0){
            for(U index=0;index<left;++index)sum_product(input+index*4u,input+(lag+index)*4u,output);
        }
        --left;++lag;output+=4u;
    }while(--lags!=0);
}
void __cdecl audio_stream_transform_00597660(U input,U output){
    U scratch=audio_stream_encoded_scratch_006b17dc;
    for(U index=0;index<160;++index){
        const U normalized=scratch+0x140u+index*4u,filtered=scratch+0x10e0u+index*4u;
        filter_one(sample(input+index*2u),normalized,filtered,scratch);
        store(scratch+0x3e9c,word(scratch+0x3e98));
        store(scratch+0x3ea4,word(scratch+0x3ea0));
        store(scratch+0x3ea0,word(filtered));
    }
    alignas(4) B frame[96]; // Stage outputs, opaque until their proved writes.
    const U local=reinterpret_cast<U>(frame);
    audio_stream_metric_00597360(scratch+0xfa0,local);
    scratch=audio_stream_encoded_scratch_006b17dc;
    const U window=scratch+0x2ee0;
    for(U index=0;index<240;++index)multiply_one(scratch+index*4u,scratch+0x1f40+index*4u,window+index*4u);
    audio_stream_correlate_00597120(window,240,10,local+8u);
    audio_stream_coefficients_00597180(local+8u,10,local+52u,local+4u);
    const auto first=static_cast<std::uint16_t>(scaled_integer(local,&audio_mixer_pcm8_scale_005b26b0));
    std::memcpy(reinterpret_cast<void*>(output),&first,2);
    reinterpret_cast<B*>(output)[2]=static_cast<B>(scaled_integer(local+4u,&audio_mixer_pcm8_scale_005b26b0));
    for(U index=0;index<10;++index)reinterpret_cast<B*>(output)[index+3u]=static_cast<B>(scaled_integer(local+56u+index*4u,&audio_stream_coefficient_scale_005b3880));
    // Packing deliberately does not write byte13.
    scratch=audio_stream_encoded_scratch_006b17dc;
    (void)audio_stream_copy_forward_00598a50(scratch,scratch+0x280,320);
    (void)audio_stream_copy_forward_00598a50(scratch+0xfa0,scratch+0x1220,320);
}
}
