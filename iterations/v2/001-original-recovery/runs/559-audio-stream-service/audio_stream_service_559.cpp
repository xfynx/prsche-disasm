// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Seven original bodies258B; exact wrap/store/call order. No new data/state.
#include "audio_stream_service_559.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact x86 register/stack/wrapping semantics require MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
// 00561960/80B SHA256 e4865868127cb1cdb1990a8ac1e0e90fa68a5c6dbfb93692ee7ccf56ca3f9125
__declspec(naked) I __cdecl application_audio_stream_descriptor_00561960(B*){
    __asm {
        mov eax, dword ptr [esp + 4] // 00561960
        mov ecx, 0x1000 // 00561964
        mov dl, 0x7f // 00561969
        mov word ptr [eax + 0xc], cx // 0056196b
        mov word ptr [eax + 0xe], cx // 0056196f
        mov word ptr [eax + 0x10], cx // 00561973
        xor ecx, ecx // 00561977
        mov dword ptr [eax], 0xffffffff // 00561979
        mov byte ptr [eax + 4], 0xff // 0056197f
        mov byte ptr [eax + 5], 0x3c // 00561983
        mov word ptr [eax + 0x12], 0xffff // 00561987
        mov word ptr [eax + 0x14], cx // 0056198d
        mov byte ptr [eax + 6], dl // 00561991
        mov byte ptr [eax + 7], 0x40 // 00561994
        mov byte ptr [eax + 8], dl // 00561998
        mov byte ptr [eax + 9], 0x40 // 0056199b
        mov byte ptr [eax + 0xa], dl // 0056199f
        mov byte ptr [eax + 0xb], cl // 005619a2
        mov word ptr [eax + 0x18], cx // 005619a5
        mov word ptr [eax + 0x1a], cx // 005619a9
        xor eax, eax // 005619ad
        ret // 005619af
    }
}
// 005611d0/12B SHA256 f743a69ff175ee52f9e10ae69b168f265181f08adc86ae15a2a164b8722f23fb
__declspec(naked) U __cdecl audio_stream_record_bytes_005611d0(U){
    __asm {
        mov eax, dword ptr [esp + 4] // 005611d0
        lea eax, [eax + eax*2 + 0xc] // 005611d4
        shl eax, 3 // 005611d8
        ret // 005611db
    }
}
// 005611e0/25B SHA256 b898b25efdd4252f6b6dafd6f32b3546d7a19d2df5a78758407787fea1600668
__declspec(naked) U __cdecl audio_stream_storage_bytes_005611e0(U){
    __asm {
        mov eax, dword ptr [esp + 4] // 005611e0
        push esi // 005611e4
        push eax // 005611e5
        call audio_stream_record_bytes_005611d0 // 005611e6
        add esp, 4 // 005611eb
        mov esi, eax // 005611ee
        call audio_stream_prefix_bytes_00589790 // 005611f0
        add eax, esi // 005611f5
        pop esi // 005611f7
        ret // 005611f8
    }
}
// 005678a0/31B SHA256 0bc774ae1dbe0ebd62598e13ad1c3e7ee1ab679fbecc5eea6362bf25951e7988
__declspec(naked) U __cdecl audio_stream_service_bytes_005678a0(U,U){
    __asm {
        mov eax, dword ptr [esp + 8] // 005678a0
        push eax // 005678a4
        call audio_stream_storage_bytes_005611e0 // 005678a5
        mov ecx, dword ptr [esp + 8] // 005678aa
        add esp, 4 // 005678ae
        lea edx, [ecx + ecx*4] // 005678b1
        lea ecx, [ecx + edx*2] // 005678b4
        lea eax, [eax + ecx*4 + 0xf8] // 005678b7
        ret // 005678be
    }
}
// 005678c0/38B SHA256 5f8f874e8ea07d6c336a4294ae6fea3574b08905b26e47a0d70f340249fa75c3
__declspec(naked) U __cdecl application_audio_stream_estimate_005678c0(U,U){
    __asm {
        mov eax, dword ptr [esp + 8] // 005678c0
        push esi // 005678c4
        mov esi, dword ptr [esp + 8] // 005678c5
        push edi // 005678c9
        push eax // 005678ca
        push esi // 005678cb
        call audio_stream_service_bytes_005678a0 // 005678cc
        push 1 // 005678d1
        inc esi // 005678d3
        push 1 // 005678d4
        push esi // 005678d6
        mov edi, eax // 005678d7
        call audio_stream_codec_bytes_0056afc0 // 005678d9
        add esp, 0x14 // 005678de
        add eax, edi // 005678e1
        pop edi // 005678e3
        pop esi // 005678e4
        ret // 005678e5
    }
}
// 0056afc0/34B SHA256 982f28dc2a4a77cd5d2d464c1fdbbf5d3214039e4c5b1953f29bd57380c5637c
__declspec(naked) U __cdecl audio_stream_codec_bytes_0056afc0(U,U,U){
    __asm {
        mov eax, dword ptr [esp + 0xc] // 0056afc0
        lea ecx, [eax + 0x19] // 0056afc4
        mov eax, dword ptr [esp + 4] // 0056afc7
        shl ecx, 4 // 0056afcb
        lea edx, [eax + eax*8] // 0056afce
        lea eax, [eax + edx*4] // 0056afd1
        lea ecx, [ecx + eax*8] // 0056afd4
        mov eax, dword ptr [esp + 8] // 0056afd7
        lea edx, [eax + eax*2] // 0056afdb
        lea eax, [ecx + edx*4] // 0056afde
        ret // 0056afe1
    }
}
// 00567660/38B SHA256 72965ab59dae4a11d68c2e9475d5557b3a9282d1f8fb206dd66d29da1433ce97
__declspec(naked) I __cdecl application_audio_stream_begin_00567660(B*,U,U,U,U){
    __asm {
        mov eax, dword ptr [esp + 0x14] // 00567660
        mov ecx, dword ptr [esp + 0x10] // 00567664
        mov edx, dword ptr [esp + 0xc] // 00567668
        push 0 // 0056766c
        push 0 // 0056766e
        push eax // 00567670
        mov eax, dword ptr [esp + 0x14] // 00567671
        push ecx // 00567675
        mov ecx, dword ptr [esp + 0x14] // 00567676
        push edx // 0056767a
        push eax // 0056767b
        push ecx // 0056767c
        call application_audio_stream_create_005673d0 // 0056767d
        add esp, 0x1c // 00567682
        ret // 00567685
    }
}
}
