// Original Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_pcm_kernels_490.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 x87/SSE kernels require MSVC x86
#endif
namespace porsche {
const float audio_mixer_pcm16_bias_005c1800=12582912.0f;
// The three unrolled kernels retain their complete original instruction order,
// including backwards residuals, block loads before stores and count<=0 prefix
// accesses. Naked entries preserve the extra original saved ECX register.
__declspec(naked) void __cdecl audio_mixer_accumulate_scalar_0059ba70(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t){__asm {
    push ebp
    mov ebp,esp
    push ecx
    push esi
    push edi
    mov ecx,[ebp+8]
    mov esi,[ebp+10h]
    mov edi,[ebp+14h]
    fld dword ptr [ebp+0ch]
scalar_tail:
    test ecx,3
    je scalar_block
scalar_one:
    fld dword ptr [esi+ecx*4-4]
    fmul st(0),st(1)
    fadd dword ptr [edi+ecx*4-4]
    fstp dword ptr [edi+ecx*4-4]
    sub ecx,1
    je scalar_end
    jmp scalar_tail
scalar_block:
    fld dword ptr [esi+ecx*4-10h]
    fmul st(0),st(1)
    fld dword ptr [esi+ecx*4-0ch]
    fmul st(0),st(2)
    fld dword ptr [esi+ecx*4-8]
    fmul st(0),st(3)
    fld dword ptr [esi+ecx*4-4]
    fmul st(0),st(4)
    fxch st(3)
    fadd dword ptr [edi+ecx*4-10h]
    fxch st(2)
    fadd dword ptr [edi+ecx*4-0ch]
    fxch st(1)
    fadd dword ptr [edi+ecx*4-8]
    fxch st(3)
    fadd dword ptr [edi+ecx*4-4]
    fxch st(2)
    fstp dword ptr [edi+ecx*4-10h]
    fstp dword ptr [edi+ecx*4-0ch]
    fstp dword ptr [edi+ecx*4-4]
    fstp dword ptr [edi+ecx*4-8]
    sub ecx,4
    jg scalar_block
scalar_end:
    fstp st(0)
    pop edi
    pop esi
    pop ecx
    leave
    ret
}}
// Frozen486 COFF name says "x87"; original0059baf0 actually uses SSE.
__declspec(naked) void __cdecl audio_mixer_accumulate_x87_0059baf0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t){__asm {
    push ebp
    mov ebp,esp
    push ecx
    push esi
    push edi
    mov ecx,[ebp+8]
    mov esi,[ebp+10h]
    mov edi,[ebp+14h]
    movss xmm0,dword ptr [ebp+0ch]
    shufps xmm0,xmm0,0
sse_tail:
    test ecx,0fh
    je sse_alignment
sse_one:
    movss xmm1,dword ptr [esi+ecx*4-4]
    mulss xmm1,xmm0
    addss xmm1,dword ptr [edi+ecx*4-4]
    movss dword ptr [edi+ecx*4-4],xmm1
    sub ecx,1
    je sse_end
    jmp sse_tail
sse_alignment:
    test esi,0fh
    jne sse_one
    test edi,0fh
    jne sse_one
sse_block:
    movaps xmm1,xmmword ptr [esi+ecx*4-40h]
    movaps xmm2,xmmword ptr [esi+ecx*4-30h]
    movaps xmm3,xmmword ptr [esi+ecx*4-20h]
    movaps xmm4,xmmword ptr [esi+ecx*4-10h]
    mulps xmm1,xmm0
    mulps xmm2,xmm0
    mulps xmm3,xmm0
    mulps xmm4,xmm0
    addps xmm1,xmmword ptr [edi+ecx*4-40h]
    addps xmm2,xmmword ptr [edi+ecx*4-30h]
    addps xmm3,xmmword ptr [edi+ecx*4-20h]
    addps xmm4,xmmword ptr [edi+ecx*4-10h]
    movaps xmmword ptr [edi+ecx*4-40h],xmm1
    movaps xmmword ptr [edi+ecx*4-30h],xmm2
    movaps xmmword ptr [edi+ecx*4-20h],xmm3
    movaps xmmword ptr [edi+ecx*4-10h],xmm4
    sub ecx,10h
    jg sse_block
sse_end:
    pop edi
    pop esi
    pop ecx
    leave
    ret
}}
__declspec(naked) void __cdecl audio_mixer_decode_s16_x87_0059b9f0(std::uint32_t,std::uint32_t,std::uint32_t){__asm {
    push ebp
    mov ebp,esp
    push ecx
    push esi
    push edi
    mov ecx,[ebp+8]
    mov esi,[ebp+0ch]
    mov edi,[ebp+10h]
decode_tail:
    test ecx,7
    je decode_block
    fild word ptr [esi+ecx*2-2]
    fstp dword ptr [edi+ecx*4-4]
    sub ecx,1
    je decode_end
    jmp decode_tail
decode_block:
    fild word ptr [esi+ecx*2-10h]
    fild word ptr [esi+ecx*2-0eh]
    fild word ptr [esi+ecx*2-0ch]
    fild word ptr [esi+ecx*2-0ah]
    fild word ptr [esi+ecx*2-8]
    fild word ptr [esi+ecx*2-6]
    fild word ptr [esi+ecx*2-4]
    fild word ptr [esi+ecx*2-2]
    fxch st(7)
    fstp dword ptr [edi+ecx*4-20h]
    fstp dword ptr [edi+ecx*4-8]
    fstp dword ptr [edi+ecx*4-0ch]
    fstp dword ptr [edi+ecx*4-10h]
    fstp dword ptr [edi+ecx*4-14h]
    fstp dword ptr [edi+ecx*4-18h]
    fstp dword ptr [edi+ecx*4-1ch]
    fstp dword ptr [edi+ecx*4-4]
    sub ecx,8
    jg decode_block
decode_end:
    pop edi
    pop esi
    pop ecx
    leave
    ret
}}
namespace {
using U=std::uint32_t;using I=std::int32_t;
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
