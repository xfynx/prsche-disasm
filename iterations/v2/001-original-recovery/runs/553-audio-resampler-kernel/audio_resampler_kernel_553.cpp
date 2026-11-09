// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original678B LPC/noise-pulse synthesis; exact x87/order/spills and aliasing.
#include "audio_resampler_kernel_553.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 semantics require MSVC x86
#endif
namespace porsche {
const std::uint64_t audio_resampler_scalar_005c17d0=0x3f70000000000000ull;
const std::uint64_t audio_resampler_scalar_005b4ba8=0x3f80000000000000ull;
const std::uint64_t audio_resampler_scalar_005b24c0=0x0000000000000000ull;
const std::uint64_t audio_resampler_scalar_005b27b8=0x4008000000000000ull;
const std::uint64_t audio_resampler_scalar_005c17c8=0x406e000000000000ull;
const std::uint64_t audio_resampler_scalar_005c17c0=0x3f7999999999999aull;
const std::uint64_t audio_resampler_scalar_005c17b8=0x3f00002000400080ull;
const std::uint64_t audio_resampler_scalar_005b2750=0x3ff0000000000000ull;
const std::uint64_t audio_resampler_scalar_005b4690=0xbff0000000000000ull;
const std::uint32_t audio_resampler_scalar_005c1698=0x46fffe00u;
// Packet: u16 period/256,u8 gain/256,10 signed coefficient bytes/128.
// State: old period/gain,coefficients,10 history values and countdown+c0.
// Descending ten-stage lattice preserves live80-bit values and qword spills.
__declspec(naked) void __cdecl audio_resampler_decode_00597810(std::uint32_t,std::uint32_t,std::uint32_t){
    __asm {
        push ebp
        mov ebp, esp
        and esp, 0fffffff8h
        sub esp, 0144h
        mov edx, dword ptr [ebp + 8]
        xor eax, eax
        xor ecx, ecx
        push ebx
        mov ax, word ptr [edx]
        mov cl, byte ptr [edx + 2]
        mov dword ptr [esp + 4], eax
        push esi
        fild dword ptr [esp + 8]
        mov dword ptr [esp + 8], ecx
        push edi
        mov dword ptr [esp + 048h], 0
        mov dword ptr [esp + 04ch], 0
        fmul qword ptr [audio_resampler_scalar_005c17d0]
        xor eax, eax
        lea ecx, [esp + 050h]
        fstp qword ptr [esp + 018h]
        fild dword ptr [esp + 0ch]
        fmul qword ptr [audio_resampler_scalar_005c17d0]
    L597862:
        movsx esi, byte ptr [edx + eax + 3]
        mov dword ptr [esp + 0ch], esi
        inc eax
        fild dword ptr [esp + 0ch]
        add ecx, 8
        cmp eax, 0ah
        fmul qword ptr [audio_resampler_scalar_005b4ba8]
        fstp qword ptr [ecx - 8]
        jl L597862
        fld qword ptr [esp + 018h]
        fcomp qword ptr [audio_resampler_scalar_005b24c0]
        fnstsw ax
        test ah, 040h
        je L59789a
        fld qword ptr [audio_resampler_scalar_005b27b8]
        jmp L59789e
    L59789a:
        fld qword ptr [esp + 018h]
    L59789e:
        fld qword ptr [audio_resampler_scalar_005c17c8]
        fdiv st(0),st(1)
        mov ebx, dword ptr [ebp + 010h]
        lea edi, [esp + 0100h]
        mov edx, dword ptr [ebx]
        mov eax, dword ptr [ebx + 4]
        mov ecx, dword ptr [ebx + 8]
        mov dword ptr [esp + 010h], edx
        mov edx, dword ptr [ebx + 0ch]
        mov dword ptr [esp + 014h], eax
        mov dword ptr [esp + 024h], edx
        lea edx, [ebx + 018h]
        mov dword ptr [esp + 020h], ecx
        mov ecx, 014h
        mov esi, edx
        mov dword ptr [esp + 044h], edx
        rep movsd
        fsqrt
        fdivr st(0),st(2)
        fstp qword ptr [esp + 030h]
        fstp st(0)
        fstp st(0)
        fld qword ptr [ebx]
        fcomp qword ptr [audio_resampler_scalar_005b24c0]
        fnstsw ax
        test ah, 040h
        jne L59794c
        fld qword ptr [esp + 018h]
        fcomp qword ptr [audio_resampler_scalar_005b24c0]
        fnstsw ax
        test ah, 040h
        jne L59794c
        fld qword ptr [esp + 018h]
        fsub qword ptr [ebx]
        mov ecx, edx
        xor eax, eax
        fmul qword ptr [audio_resampler_scalar_005c17c0]
        fstp qword ptr [esp + 028h]
        fld qword ptr [esp + 030h]
        fsub qword ptr [ebx + 8]
        fmul qword ptr [audio_resampler_scalar_005c17c0]
        fstp qword ptr [esp + 038h]
    L59792c:
        fld qword ptr [esp + eax + 050h]
        fsub qword ptr [ecx]
        add eax, 8
        add ecx, 8
        cmp eax, 048h
        fmul qword ptr [audio_resampler_scalar_005c17c0]
        fstp qword ptr [esp + eax + 0a0h]
        jle L59792c
        jmp L59797c
    L59794c:
        mov ecx, 014h
        xor eax, eax
        lea edi, [esp + 0a8h]
        mov dword ptr [esp + 028h], 0
        mov dword ptr [esp + 02ch], 0
        mov dword ptr [esp + 038h], 0
        mov dword ptr [esp + 03ch], 0
        rep stosd
    L59797c:
        fld qword ptr [esp + 010h]
        fcomp qword ptr [audio_resampler_scalar_005b24c0]
        fnstsw ax
        test ah, 040h
        je L597997
        mov dword ptr [ebx + 0c0h], 0
    L597997:
        mov esi, dword ptr [ebp + 0ch]
        mov edi, 0a0h
    L59799f:
        fld qword ptr [esp + 010h]
        fcomp qword ptr [audio_resampler_scalar_005b24c0]
        fnstsw ax
        test ah, 040h
        je L5979c9
        call audio_resampler_rand_005a17c9
        mov dword ptr [esp + 0ch], eax
        fild dword ptr [esp + 0ch]
        fmul qword ptr [audio_resampler_scalar_005c17b8]
        fmul qword ptr [esp + 020h]
        jmp L5979ef
    L5979c9:
        mov eax, dword ptr [ebx + 0c0h]
        test eax, eax
        jne L5979e2
        fld qword ptr [esp + 020h]
        fld qword ptr [esp + 010h]
        call audio_stream_ftol_005a0f98
        jmp L5979e9
    L5979e2:
        fld qword ptr [audio_resampler_scalar_005b24c0]
        dec eax
    L5979e9:
        mov dword ptr [ebx + 0c0h], eax
    L5979ef:
        lea ecx, [ebx + 0b8h]
        xor eax, eax
    L5979f7:
        fld qword ptr [ecx - 8]
        fld qword ptr [esp + eax + 0148h]
        fld st(0)
        fadd qword ptr [esp + eax + 0f0h]
        sub eax, 8
        add ecx, -8
        cmp eax, -048h
        fstp qword ptr [esp + eax + 0150h]
        fld st(0)
        fmul st(0),st(2)
        fsubp st(3),st(0)
        fmul st(0),st(2)
        fadd st(0),st(1)
        fstp qword ptr [ecx + 8]
        fstp st(0)
        jge L5979f7
        fcom qword ptr [audio_resampler_scalar_005b2750]
        fst qword ptr [ebx + 068h]
        fnstsw ax
        test ah, 041h
        jne L597a45
        fstp st(0)
        fld qword ptr [audio_resampler_scalar_005b2750]
        jmp L597a5a
    L597a45:
        fcom qword ptr [audio_resampler_scalar_005b4690]
        fnstsw ax
        test ah, 1
        je L597a5a
        fstp st(0)
        fld qword ptr [audio_resampler_scalar_005b4690]
    L597a5a:
        fmul dword ptr [audio_resampler_scalar_005c1698]
        add esi, 4
        dec edi
        fstp dword ptr [esi - 4]
        fld qword ptr [esp + 028h]
        fadd qword ptr [esp + 010h]
        fstp qword ptr [esp + 010h]
        fld qword ptr [esp + 038h]
        fadd qword ptr [esp + 020h]
        fstp qword ptr [esp + 020h]
        jne L59799f
        mov eax, dword ptr [esp + 018h]
        mov ecx, dword ptr [esp + 01ch]
        mov edx, dword ptr [esp + 030h]
        mov edi, dword ptr [esp + 044h]
        mov dword ptr [ebx], eax
        mov eax, dword ptr [esp + 034h]
        mov dword ptr [ebx + 4], ecx
        mov dword ptr [ebx + 8], edx
        mov ecx, 014h
        lea esi, [esp + 050h]
        mov dword ptr [ebx + 0ch], eax
        rep movsd
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret
    }
}
}
