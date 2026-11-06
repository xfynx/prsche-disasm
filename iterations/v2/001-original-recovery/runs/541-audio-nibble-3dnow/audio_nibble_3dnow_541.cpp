// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0059a730..0059a7f8,201B/fullRET; no data owners. Emulated AMD proof only.
#include "audio_nibble_3dnow_541.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original3DNow arithmetic requires MSVC x86
#endif
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;using namespace nibble512;
U ptr(const void* p){return reinterpret_cast<U>(p);}
#pragma warning(push)
// Original MMX histories/coefficients span private integer calls until FEMMS.
#pragma warning(disable:4799)
void histories(U state){__asm {
 mov eax,state
 movd mm2,[eax+4]
 movd mm3,[eax+8]
}}
void coefficients(U first,U second){__asm {
 mov eax,first
 movd mm0,[eax]
 mov eax,second
 movd mm1,[eax]
}}
void even(U lookup){__asm {
 mov eax,lookup
 movq mm4,mm2
 _emit 0fh
 _emit 0fh
 _emit 0e0h
 _emit 0b4h
 movq mm5,mm3
 _emit 0fh
 _emit 0fh
 _emit 0e9h
 _emit 0b4h
 movd mm6,[eax]
 _emit 0fh
 _emit 0fh
 _emit 0e5h
 _emit 09eh
 _emit 0fh
 _emit 0fh
 _emit 0e6h
 _emit 09eh
 movq mm3,mm4
}}
void odd_pair(U lookup,U output){__asm {
 mov eax,lookup
 mov edx,output
 movq mm4,mm3
 _emit 0fh
 _emit 0fh
 _emit 0e0h
 _emit 0b4h
 movq mm5,mm2
 _emit 0fh
 _emit 0fh
 _emit 0e9h
 _emit 0b4h
 movd mm6,[eax]
 // Odd PFADD order is LUT first, then older product.
 _emit 0fh
 _emit 0fh
 _emit 0e6h
 _emit 09eh
 _emit 0fh
 _emit 0fh
 _emit 0e5h
 _emit 09eh
 movq mm2,mm4
 movd [edx],mm3
 movd [edx+4],mm2
}}
void save_histories(U state){__asm {
 mov eax,state
 movd [eax+4],mm2
 movd [eax+8],mm3
}}
void finish(){__asm {
 _emit 0fh
 _emit 0eh
}}
#pragma warning(pop)
}
void __cdecl audio_nibble_decode_3dnow_0059a730(U state){
    U input=read32(state+12u),output=read32(state+16u);histories(state);
    while(static_cast<I>(read32(state))>0){
        write32(state,read32(state)-28u);
        const U high=read8(input)>>4,window=ptr(audio_nibble_read_window_005e3b28);
        coefficients(window+high*4u,window+16u+high*4u);
        const U row=(read8(input)&15u)*64u;
        input+=15u;output+=112u;U index=0xfffffff2u;
        do{
            const U encoded=input+index,upper=read8(encoded)>>4;
            even(ptr(audio_mixer_nibble_lookup_006b04c0)+row+upper*4u);
            const U lower=read8(encoded)&15u;
            odd_pair(ptr(audio_mixer_nibble_lookup_006b04c0)+row+lower*4u,output+index*8u);
            ++index;
        }while(static_cast<I>(index)<0);
    }
    save_histories(state);write32(state+16u,output);finish();
}
}
