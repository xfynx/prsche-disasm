#include "cpu_features_446.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original flags/register transport requires MSVC x86
#endif
namespace porsche {
// Porsche.exe ddd748fdbe6d..., 0059a4d0..0059a4ec (29 bytes).
// PUSHFD/POPFD and inherited register state have no portable C++ equivalent.
__declspec(naked) std::uint32_t __cdecl cpu_id_toggle_0059a4d0() {
    __asm {
        push ecx
        pushfd
        push ebp
        mov ebp,esp
        sub esp,20h
        pushfd
        pop eax
        mov ecx,eax
        xor eax,200000h
        push eax
        popfd
        pushfd
        pop eax
        xor eax,ecx
        mov esp,ebp
        pop ebp
        popfd
        pop ecx
        ret
    }
}
// 0059a4ed..0059a510 (36 bytes). EAX/GPRs restored, ECX input inherited.
__declspec(naked) void __cdecl cpu_query_0059a4ed(std::uint32_t*,std::uint32_t) {
    __asm {
        push ebp
        mov ebp,esp
        push eax
        push ebx
        push ecx
        push edx
        push esi
        push edi
        mov eax,[ebp+0ch]
        cpuid
        mov esi,[ebp+8]
        mov [esi],eax
        mov [esi+4],ebx
        mov [esi+8],ecx
        mov [esi+0ch],edx
        pop edi
        pop esi
        pop edx
        pop ecx
        pop ebx
        pop eax
        leave
        ret
    }
}
static void query(std::uint32_t* output,std::uint32_t leaf) {
    // Original005970ad establishes ECX=output; the helper restores it for
    // subsequent queries. Explicit transport prevents compiler subleaf choices.
    __asm {
        mov ecx,output
        push leaf
        push ecx
        call cpu_query_0059a4ed
        add esp,8
    }
}
// Modern internal adapter, not an additional original body. The uninitialized
// OS bytes are read by machine loads, never as indeterminate C++ scalar values.
extern "C" std::uint32_t __cdecl cpu_features_core_446(void* version,std::uint32_t* output) {
    std::uint32_t platform,minor;
    __asm {
        mov eax,version
        mov edx,[eax+10h]
        mov platform,edx
        mov edx,[eax+8]
        mov minor,edx
    }
    const bool suppress=platform==1 && minor==0;
    std::uint32_t mask=1;
    if(cpu_id_toggle_0059a4d0()==0) return mask;
    query(output,0);
    if(output[0]<1u) return mask;
    query(output,1);
    if((output[3]&0x02000000u)!=0 && !suppress) mask=3;
    query(output,0x80000001u);
    if((output[3]&0x80000000u)!=0) mask|=4u;
    return mask;
}
// Original00597070..00597110, 161B. Keep its 164B stack allocation so opaque
// failed/partial GetVersionExA output remains caller-stack state. The C++ core
// replaces the original branch logic; it does not initialize opaque bytes.
__declspec(naked) std::uint32_t __cdecl audio_backend_cpu_features_00597070() {
    __asm {
        sub esp,0a4h
        push esi
        push edi
        lea eax,[esp+18h]
        mov dword ptr [eax],94h
        push eax
        call cpu_platform_version_446
        lea eax,[esp+8]
        push eax
        lea eax,[esp+1ch]
        push eax
        call cpu_features_core_446
        add esp,8
        pop edi
        pop esi
        add esp,0a4h
        ret
    }
}
}
