// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_pcm_cpp_492.hpp"
#include <cstring>
#include <xmmintrin.h>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original x87/SSE arithmetic requires MSVC x86
#endif
namespace porsche {
const float audio_mixer_pcm16_bias_005c1800=12582912.0f;
namespace {
using U=std::uint32_t;using I=std::int32_t;
// Private primitives retain gain in ST0 between calls. The public C++ loop
// balances this stack entry and makes no foreign calls while it is live.
void push_gain(U bits){__asm fld dword ptr bits}
void pop_gain(){__asm fstp st(0)}
void accumulate_one(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    fld dword ptr [eax]
    fmul st(0),st(1)
    fadd dword ptr [edx]
    fstp dword ptr [edx]
}}
// One four-lane arithmetic primitive, no branches or loop/address-count logic.
// Keep four live 80-bit products, all four adds before any output store, and
// the exact FXCH/store permutation; spilling to C++ float/double changes this.
void accumulate_four(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    fld dword ptr [eax]
    fmul st(0),st(1)
    fld dword ptr [eax+4]
    fmul st(0),st(2)
    fld dword ptr [eax+8]
    fmul st(0),st(3)
    fld dword ptr [eax+0ch]
    fmul st(0),st(4)
    fxch st(3)
    fadd dword ptr [edx]
    fxch st(2)
    fadd dword ptr [edx+4]
    fxch st(1)
    fadd dword ptr [edx+8]
    fxch st(3)
    fadd dword ptr [edx+0ch]
    fxch st(2)
    fstp dword ptr [edx]
    fstp dword ptr [edx+4]
    fstp dword ptr [edx+0ch]
    fstp dword ptr [edx+8]
}}
void decode_one(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    fild word ptr [eax]
    fstp dword ptr [edx]
}}
// Eight integer loads precede every output store. The eight-live x87 stack
// also preserves original masked overflow behavior with a nonempty input stack.
void decode_eight(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    fild word ptr [eax]
    fild word ptr [eax+2]
    fild word ptr [eax+4]
    fild word ptr [eax+6]
    fild word ptr [eax+8]
    fild word ptr [eax+0ah]
    fild word ptr [eax+0ch]
    fild word ptr [eax+0eh]
    fxch st(7)
    fstp dword ptr [edx]
    fstp dword ptr [edx+18h]
    fstp dword ptr [edx+14h]
    fstp dword ptr [edx+10h]
    fstp dword ptr [edx+0ch]
    fstp dword ptr [edx+8]
    fstp dword ptr [edx+4]
    fstp dword ptr [edx+1ch]
}}
void sse_one(U source,U destination,__m128 gain){
    const __m128 input=_mm_load_ss(reinterpret_cast<const float*>(source));
    const __m128 product=_mm_mul_ss(input,gain);
    const __m128 result=_mm_add_ss(product,_mm_load_ss(reinterpret_cast<const float*>(destination)));
    _mm_store_ss(reinterpret_cast<float*>(destination),result);
}
void sse_sixteen(U source,U destination,__m128 gain){
    auto* input=reinterpret_cast<const float*>(source);
    auto* output=reinterpret_cast<float*>(destination);
    __m128 a=_mm_load_ps(input),b=_mm_load_ps(input+4),c=_mm_load_ps(input+8),d=_mm_load_ps(input+12);
    a=_mm_mul_ps(a,gain);b=_mm_mul_ps(b,gain);c=_mm_mul_ps(c,gain);d=_mm_mul_ps(d,gain);
    a=_mm_add_ps(a,_mm_load_ps(output));b=_mm_add_ps(b,_mm_load_ps(output+4));c=_mm_add_ps(c,_mm_load_ps(output+8));d=_mm_add_ps(d,_mm_load_ps(output+12));
    _mm_store_ps(output,a);_mm_store_ps(output+4,b);_mm_store_ps(output+8,c);_mm_store_ps(output+12,d);
}
}
void __cdecl audio_mixer_accumulate_scalar_0059ba70(U count,U gain_bits,U source,U destination){
    push_gain(gain_bits);
    U remaining=count;
    while((remaining&3u)!=0){
        const U offset=(remaining-1u)*4u;
        accumulate_one(source+offset,destination+offset);
        --remaining;
        if(remaining==0){pop_gain();return;}
    }
    do{
        const U offset=(remaining-4u)*4u;
        accumulate_four(source+offset,destination+offset);
        remaining-=4u;
    }while(static_cast<I>(remaining)>0);
    pop_gain();
}
// Keep frozen486's legacy "x87" link name; this original provider uses SSE.
void __cdecl audio_mixer_accumulate_x87_0059baf0(U count,U gain_bits,U source,U destination){
    __m128 gain=_mm_load_ss(reinterpret_cast<const float*>(&gain_bits));
    gain=_mm_shuffle_ps(gain,gain,0);
    U remaining=count;
    for(;;){
        while((remaining&15u)!=0){
            const U offset=(remaining-1u)*4u;
            sse_one(source+offset,destination+offset,gain);
            --remaining;if(remaining==0)return;
        }
        if((source&15u)!=0||(destination&15u)!=0){
            const U offset=(remaining-1u)*4u;
            sse_one(source+offset,destination+offset,gain);
            --remaining;if(remaining==0)return;
            continue;
        }
        do{
            const U offset=(remaining-16u)*4u;
            sse_sixteen(source+offset,destination+offset,gain);
            remaining-=16u;
        }while(static_cast<I>(remaining)>0);
        return;
    }
}
void __cdecl audio_mixer_decode_s16_x87_0059b9f0(U count,U source,U destination){
    U remaining=count;
    while((remaining&7u)!=0){
        const U index=remaining-1u;
        decode_one(source+index*2u,destination+index*4u);
        --remaining;if(remaining==0)return;
    }
    do{
        const U index=remaining-8u;
        decode_eight(source+index*2u,destination+index*4u);
        remaining-=8u;
    }while(static_cast<I>(remaining)>0);
}
namespace {
U word(U p){U x;std::memcpy(&x,reinterpret_cast<const void*>(p),4);return x;}
U biased(U p){U result;__asm {
    mov ecx,p
    fld dword ptr [ecx]
    fadd audio_mixer_pcm16_bias_005c1800
    fstp dword ptr [ecx]
    mov eax,[ecx]
    mov result,eax
    }return result;}
}
I __cdecl audio_mixer_output_pcm16_0059a350(U object,U count,U input,U output,U){
    const U next=word(object);
    if(next!=0){
        std::int16_t priority;std::memcpy(&priority,reinterpret_cast<const void*>(object+0xa),2);
        const I result=reinterpret_cast<I(__cdecl*)(U,U,U,U,I)>(word(next+4))(next,count,output,input,priority);
        if(result<=0)return result;
    }
    const U end=input+count*4u;
    while(input<end){
        U sample=biased(input)&0xfffffu;
        if(sample>0x7fffu&&sample<0xf8000u)sample=sample<0x80000u?0x7fffu:0xffff8000u;
        const std::uint16_t result=static_cast<std::uint16_t>(sample);
        std::memcpy(reinterpret_cast<void*>(output),&result,2);
        input+=4;output+=2;
    }
    return static_cast<I>(count);
}
}
