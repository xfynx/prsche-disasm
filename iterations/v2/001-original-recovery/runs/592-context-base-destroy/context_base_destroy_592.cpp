// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00525ec0..00525f3b, 124 bytes, sha256 8c3fc02650c45d6a5a6290e2d0c2780d0a5f0eacdcf6df97db96cf5df900fb54.
#include "context_base_destroy_592.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/application_alloc.hpp"

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 naked function required for 00525ec0 EAX preservation.
#endif

namespace porsche {

__declspec(naked) std::uint32_t __fastcall application_context_base_destroy_00525ec0(
    ApplicationSetupContext*, void*) {
    __asm {
        push edi
        mov edi, dword ptr [ecx + 4]
        test edi, edi
        mov dword ptr [ecx], 005bb028h
        je done_destroy
        mov eax, dword ptr [edi + 4]
        test eax, eax
        je clear_sentinel
        mov eax, dword ptr [edi]
        push esi
        mov esi, dword ptr [eax + 4]
        test esi, esi
        je reset_sentinel
        push ebx
    loop_nodes:
        mov ecx, dword ptr [esi + 0ch]
        push ecx
        mov ecx, edi
        call application_context_unlink_005262e0
        mov ebx, dword ptr [esi + 8]
        push 0
        lea ecx, [esi + 10h]
        call application_context_release_node_004e4560
        push 1
        push esi
        call application_context_notify_node_004d7da0
        add esp, 8
        mov esi, ebx
        test ebx, ebx
        jne loop_nodes
        pop ebx
    reset_sentinel:
        mov eax, dword ptr [edi]
        pop esi
        mov dword ptr [eax + 8], eax
        mov edx, dword ptr [edi]
        mov dword ptr [edx + 4], 0
        mov eax, dword ptr [edi]
        mov dword ptr [eax + 0ch], eax
        mov dword ptr [edi + 4], 0
    clear_sentinel:
        mov eax, dword ptr [edi]
        push 0
        push 20h
        push eax
        call application_context_clear_004237d0
        push edi
        call application_release_0059f050
        add esp, 10h
    done_destroy:
        pop edi
        ret
    }
}

} // namespace porsche
