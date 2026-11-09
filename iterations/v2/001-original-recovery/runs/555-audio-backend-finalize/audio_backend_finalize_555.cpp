// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Three original bodies/511B. Static instructions retain wrap/divide/copy order.
#include "audio_backend_finalize_555.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 integer/stack semantics require MSVC x86
#endif
namespace porsche {
AudioBackendPanStorage555 audio_backend_pan_storage_006b181f{};
using U=std::uint32_t;using I=std::int32_t;

// 0058e0e0/424B SHA256 3ad31abd141594cd19182fca945af162f4c691689765cab2cac9afa21945de73
__declspec(naked) void __cdecl application_audio_backend_finalize_0058e0e0() {
    __asm {
        sub esp, 8 // 0058e0e0
        push ebx // 0058e0e3
        push ebp // 0058e0e4
        push esi // 0058e0e5
        push edi // 0058e0e6
        xor ebp, ebp // 0058e0e7
    L0058e0e9:
        mov edx, dword ptr [application_audio_device_state_006b48c0+0x2c] // 0058e0e9
        mov esi, ebp // 0058e0ef
        shl esi, 8 // 0058e0f1
        cmp dl, 1 // 0058e0f4
        jne L0058e106 // 0058e0f7
        mov byte ptr [ebp*4 + audio_backend_pan_storage_006b181f+1], 0x7f // 0058e0f9
        jmp L0058e273 // 0058e101
    L0058e106:
        and edx, 0xff // 0058e106
        jle L0058e127 // 0058e10c
        mov ecx, edx // 0058e10e
        xor eax, eax // 0058e110
        mov ebx, ecx // 0058e112
        lea edi, [ebp*4 + audio_backend_pan_storage_006b181f+1] // 0058e114
        shr ecx, 2 // 0058e11b
        rep stosd // 0058e11e
        mov ecx, ebx // 0058e120
        and ecx, 3 // 0058e122
        rep stosb // 0058e125
    L0058e127:
        lea ebx, [edx*8 + application_audio_device_state_006b48c0+0x3c] // 0058e127
        xor eax, eax // 0058e12e
        mov ax, word ptr [ebx] // 0058e130
        cmp esi, eax // 0058e133
        jg L0058e18f // 0058e135
        sub eax, esi // 0058e137
        mov edi, eax // 0058e139
        xor eax, eax // 0058e13b
        mov ax, word ptr [ebx + edx*2 - 2] // 0058e13d
        sub esi, eax // 0058e142
        add esi, 0x10000 // 0058e144
        mov eax, esi // 0058e14a
        shl eax, 7 // 0058e14c
        sub eax, esi // 0058e14f
        lea ebx, [esi + edi] // 0058e151
        cdq // 0058e154
        idiv ebx // 0058e155
        push eax // 0058e157
        call audio_backend_pan_curve_0058e0b0 // 0058e158
        mov byte ptr [ebp*4 + audio_backend_pan_storage_006b181f+1], al // 0058e15d
        mov eax, edi // 0058e164
        shl eax, 7 // 0058e166
        sub eax, edi // 0058e169
        cdq // 0058e16b
        idiv ebx // 0058e16c
        push eax // 0058e16e
        call audio_backend_pan_curve_0058e0b0 // 0058e16f
        mov ecx, dword ptr [application_audio_device_state_006b48c0+0x2c] // 0058e174
        add esp, 8 // 0058e17a
        and ecx, 0xff // 0058e17d
        mov byte ptr [ecx + ebp*4 + audio_backend_pan_storage_006b181f], al // 0058e183
        jmp L0058e273 // 0058e18a
    L0058e18f:
        xor ecx, ecx // 0058e18f
        mov cx, word ptr [ebx + edx*2 - 2] // 0058e191
        cmp esi, ecx // 0058e196
        jl L0058e1ea // 0058e198
        sub eax, esi // 0058e19a
        sub esi, ecx // 0058e19c
        add eax, 0x10000 // 0058e19e
        mov edi, eax // 0058e1a3
        mov eax, esi // 0058e1a5
        shl eax, 7 // 0058e1a7
        sub eax, esi // 0058e1aa
        lea ebx, [esi + edi] // 0058e1ac
        cdq // 0058e1af
        idiv ebx // 0058e1b0
        push eax // 0058e1b2
        call audio_backend_pan_curve_0058e0b0 // 0058e1b3
        mov byte ptr [ebp*4 + audio_backend_pan_storage_006b181f+1], al // 0058e1b8
        mov eax, edi // 0058e1bf
        shl eax, 7 // 0058e1c1
        sub eax, edi // 0058e1c4
        cdq // 0058e1c6
        idiv ebx // 0058e1c7
        push eax // 0058e1c9
        call audio_backend_pan_curve_0058e0b0 // 0058e1ca
        mov edx, dword ptr [application_audio_device_state_006b48c0+0x2c] // 0058e1cf
        add esp, 8 // 0058e1d5
        and edx, 0xff // 0058e1d8
        mov byte ptr [edx + ebp*4 + audio_backend_pan_storage_006b181f], al // 0058e1de
        jmp L0058e273 // 0058e1e5
    L0058e1ea:
        test edx, edx // 0058e1ea
        mov dword ptr [esp + 0x10], 0 // 0058e1ec
        jle L0058e273 // 0058e1f4
        mov dword ptr [esp + 0x14], ebx // 0058e1f6
    L0058e1fa:
        xor ecx, ecx // 0058e1fa
        mov cx, word ptr [ebx] // 0058e1fc
        cmp esi, ecx // 0058e1ff
        jl L0058e253 // 0058e201
        xor eax, eax // 0058e203
        mov ax, word ptr [ebx + 2] // 0058e205
        cmp esi, eax // 0058e209
        jg L0058e253 // 0058e20b
        mov edi, esi // 0058e20d
        sub eax, esi // 0058e20f
        sub edi, ecx // 0058e211
        mov ecx, eax // 0058e213
        shl eax, 7 // 0058e215
        sub eax, ecx // 0058e218
        lea ebx, [ecx + edi] // 0058e21a
        cdq // 0058e21d
        idiv ebx // 0058e21e
        push eax // 0058e220
        call audio_backend_pan_curve_0058e0b0 // 0058e221
        mov ecx, dword ptr [esp + 0x14] // 0058e226
        mov byte ptr [ecx + ebp*4 + audio_backend_pan_storage_006b181f+1], al // 0058e22a
        mov eax, edi // 0058e231
        shl eax, 7 // 0058e233
        sub eax, edi // 0058e236
        cdq // 0058e238
        idiv ebx // 0058e239
        push eax // 0058e23b
        call audio_backend_pan_curve_0058e0b0 // 0058e23c
        mov edx, dword ptr [esp + 0x18] // 0058e241
        mov ebx, dword ptr [esp + 0x1c] // 0058e245
        add esp, 8 // 0058e249
        mov byte ptr [edx + ebp*4 + audio_backend_pan_storage_006b181f+2], al // 0058e24c
    L0058e253:
        mov eax, dword ptr [esp + 0x10] // 0058e253
        mov ecx, dword ptr [application_audio_device_state_006b48c0+0x2c] // 0058e257
        inc eax // 0058e25d
        and ecx, 0xff // 0058e25e
        add ebx, 2 // 0058e264
        cmp eax, ecx // 0058e267
        mov dword ptr [esp + 0x10], eax // 0058e269
        mov dword ptr [esp + 0x14], ebx // 0058e26d
        jl L0058e1fa // 0058e271
    L0058e273:
        inc ebp // 0058e273
        cmp ebp, 0x100 // 0058e274
        jl L0058e0e9 // 0058e27a
        pop edi // 0058e280
        pop esi // 0058e281
        pop ebp // 0058e282
        pop ebx // 0058e283
        add esp, 8 // 0058e284
        ret // 0058e287
    }
}

// 0058e0b0/36B SHA256 89366562bec7068e3c7121ce851aef7c8b9ab9ba50c913f3e59f1d241506e998
__declspec(naked) I __cdecl audio_backend_pan_curve_0058e0b0(I) {
    __asm {
        push esi // 0058e0b0
        mov esi, dword ptr [esp + 8] // 0058e0b1
        mov ecx, esi // 0058e0b5
        mov eax, 0x81020409 // 0058e0b7
        imul ecx, esi // 0058e0bc
        imul ecx // 0058e0bf
        add edx, ecx // 0058e0c1
        sar edx, 6 // 0058e0c3
        mov eax, edx // 0058e0c6
        shr eax, 0x1f // 0058e0c8
        add edx, eax // 0058e0cb
        lea eax, [esi + esi] // 0058e0cd
        sub eax, edx // 0058e0d0
        pop esi // 0058e0d2
        ret // 0058e0d3
    }
}

// 0058e290/51B SHA256 b4bdc7ed0db1aaf6870fe6cc72b774aa3e5ea4026ecb46a8bd5e68254141dfa3
__declspec(naked) void __cdecl audio_backend_pan_copy_0058e290(I,U) {
    __asm {
        mov eax, dword ptr [esp + 4] // 0058e290
        mov ecx, dword ptr [application_audio_device_state_006b48c0+0x2c] // 0058e294
        sar eax, 8 // 0058e29a
        and ecx, 0xff // 0058e29d
        jle L0058e2c2 // 0058e2a3
        push esi // 0058e2a5
        lea esi, [eax*4 + audio_backend_pan_storage_006b181f+1] // 0058e2a6
        mov eax, ecx // 0058e2ad
        push edi // 0058e2af
        mov edi, dword ptr [esp + 0x10] // 0058e2b0
        shr ecx, 2 // 0058e2b4
        rep movsd // 0058e2b7
        mov ecx, eax // 0058e2b9
        and ecx, 3 // 0058e2bb
        rep movsb // 0058e2be
        pop edi // 0058e2c0
        pop esi // 0058e2c1
    L0058e2c2:
        ret // 0058e2c2
    }
}
}
