// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Four original bodies /194B. Exact x87 instructions preserve accumulator
// precision, rounding, exception/status and stack semantics at /Od and /O2.
#include "audio_filter_kernel_461.hpp"
#include <cstring>
extern float _DAT_005b24a8; // canonical Run221 original readonly1.0, not new storage.
namespace porsche {
namespace {
using U=std::uint32_t;
U read(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
void write(U address,U value){std::memcpy(reinterpret_cast<void*>(address),&value,4);}
}
void __cdecl audio_release_filter_initialize_0059a170(U object) {
    write(object+4u,reinterpret_cast<U>(&audio_filter_callback_0059a0f0));
    write(object+0x0cu,0);
    write(object+0x18u,reinterpret_cast<U>(&audio_filter_kernel_0059c170));
}
__declspec(naked) void __cdecl audio_release_filter_set_0059a150(U,U) {
    __asm {
        fld dword ptr [esp+8]
        mov eax,dword ptr [esp+4]
        fstp dword ptr [eax+14h]
        fld dword ptr [_DAT_005b24a8]
        fsub dword ptr [esp+8]
        fstp dword ptr [eax+10h]
        ret
    }
}
std::int32_t __cdecl audio_filter_callback_0059a0f0(U object,U count,U input,U output) {
    const U upstream=read(object);
    if(upstream!=0) {
        std::int16_t mode;
        std::memcpy(&mode,reinterpret_cast<const void*>(object+0x0au),2);
        using Callback=std::int32_t(__cdecl*)(U,U,U,U,std::int32_t);
        const auto result=reinterpret_cast<Callback>(read(upstream+4u))(upstream,count,output,input,mode);
        if(result<=0) return result;
    }
    const U bytes=count*4u;
    // Original forward REP MOVSD, including source/destination overlap.
    for(U offset=0;offset<bytes;offset+=4u) write(output+offset,read(input+offset));
    using Kernel=void(__cdecl*)(U,U,U);
    reinterpret_cast<Kernel>(read(object+0x18u))(object+0x0cu,count,output);
    return static_cast<std::int32_t>(count);
}
__declspec(naked) void __cdecl audio_filter_kernel_0059c170(U,U,U) {
    __asm {
        push ebp
        mov ebp,esp
        push ecx
        push esi
        push edi
        mov ecx,dword ptr [ebp+0ch]
        mov edi,dword ptr [ebp+8]
        shl ecx,2
        mov esi,dword ptr [ebp+10h]
        add esi,ecx
        neg ecx
        fld dword ptr [edi]
    sample:
        fmul dword ptr [edi+4]
        fld dword ptr [edi+8]
        fmul dword ptr [ecx+esi]
        faddp st(1),st(0)
        fst dword ptr [ecx+esi]
        add ecx,4
        jl sample
        fstp dword ptr [edi]
        pop edi
        pop esi
        pop ecx
        leave
        ret
    }
}
}
