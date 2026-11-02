// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_pcm_3dnow_498.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original 3DNow arithmetic requires MSVC x86
#endif
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
#pragma warning(push)
// MMX state intentionally spans these private calls until the public FEMMS.
#pragma warning(disable:4799)
// MM0 is live across private primitives; integer C++ control does not touch MMX.
// No foreign call occurs before FEMMS. These are fixed arithmetic operations,
// never whole-function assembly or loops. Raw emits preserve the AMD opcodes.
void gain(U bits){__asm {
    movd mm0,bits
    movq mm1,mm0
    psllq mm0,20h
    por mm0,mm1
}}
void finish(){__asm {
    _emit 0fh
    _emit 0eh
}}
void accumulate_one(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    movd mm1,[eax]
    _emit 0fh
    _emit 0fh
    _emit 0c8h
    _emit 0b4h
    movd mm2,[edx]
    _emit 0fh
    _emit 0fh
    _emit 0cah
    _emit 09eh
    movd [edx],mm1
}}
// All four source pairs/products precede the first destination read/store.
// Destination pairs are added/stored in order, retaining overlapping buffers.
void accumulate_eight(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    movq mm1,[eax]
    movq mm2,[eax+8]
    movq mm3,[eax+10h]
    movq mm4,[eax+18h]
    _emit 0fh
    _emit 0fh
    _emit 0c8h
    _emit 0b4h
    _emit 0fh
    _emit 0fh
    _emit 0d0h
    _emit 0b4h
    _emit 0fh
    _emit 0fh
    _emit 0d8h
    _emit 0b4h
    _emit 0fh
    _emit 0fh
    _emit 0e0h
    _emit 0b4h
    _emit 0fh
    _emit 0fh
    _emit 00ah
    _emit 09eh
    movq [edx],mm1
    _emit 0fh
    _emit 0fh
    _emit 052h
    _emit 008h
    _emit 09eh
    movq [edx+8],mm2
    _emit 0fh
    _emit 0fh
    _emit 05ah
    _emit 010h
    _emit 09eh
    movq [edx+10h],mm3
    _emit 0fh
    _emit 0fh
    _emit 062h
    _emit 018h
    _emit 09eh
    movq [edx+18h],mm4
}}
void decode_one(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    movd mm1,[eax]
    pslld mm1,10h
    psrad mm1,10h
    _emit 0fh
    _emit 0fh
    _emit 0c9h
    _emit 00dh
    movd [edx],mm1
}}
void decode_eight(U source,U destination){__asm {
    mov eax,source
    mov edx,destination
    movq mm1,[eax]
    movq mm3,[eax+8]
    movq mm2,mm1
    movq mm4,mm3
    punpcklwd mm1,mm0
    punpckhwd mm2,mm0
    punpcklwd mm3,mm0
    punpckhwd mm4,mm0
    pslld mm1,10h
    pslld mm2,10h
    pslld mm3,10h
    pslld mm4,10h
    psrad mm1,10h
    psrad mm2,10h
    psrad mm3,10h
    psrad mm4,10h
    _emit 0fh
    _emit 0fh
    _emit 0c9h
    _emit 00dh
    _emit 0fh
    _emit 0fh
    _emit 0d2h
    _emit 00dh
    _emit 0fh
    _emit 0fh
    _emit 0dbh
    _emit 00dh
    _emit 0fh
    _emit 0fh
    _emit 0e4h
    _emit 00dh
    movq [edx],mm1
    movq [edx+8],mm2
    movq [edx+10h],mm3
    movq [edx+18h],mm4
}}
#pragma warning(pop)
}
void __cdecl audio_mixer_accumulate_3dnow_0059bc40(U count,U gain_bits,U source,U destination){
    gain(gain_bits);
    U remaining=count;
    while((remaining&7u)!=0){
        const U offset=(remaining-1u)*4u;
        accumulate_one(source+offset,destination+offset);
        --remaining;
        if(remaining==0){finish();return;}
    }
    do{
        const U offset=(remaining-8u)*4u;
        accumulate_eight(source+offset,destination+offset);
        remaining-=8u;
    }while(static_cast<I>(remaining)>0);
    finish();
}
void __cdecl audio_mixer_decode_s16_3dnow_0059bb90(U count,U source,U destination){
    U remaining=count;
    while((remaining&7u)!=0){
        const U index=remaining-1u;
        decode_one(source+index*2u,destination+index*4u);
        --remaining;
        if(remaining==0){finish();return;}
    }
    do{
        const U index=remaining-8u;
        decode_eight(source+index*2u,destination+index*4u);
        remaining-=8u;
    }while(static_cast<I>(remaining)>0);
    finish();
}
}
