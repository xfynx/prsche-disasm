// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original005693e0..00569414, 53 bytes. Three loader-zero DWORDs only.
#include "frame_interface_release_585.hpp"

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 naked function and stdcall virtual release required.
#endif

namespace porsche {
std::uint32_t frame_interface_final_flag_006a5ca0;
std::uint32_t frame_interface_second_006a5ca4;
std::uint32_t frame_interface_first_006a5ca8;

__declspec(naked) std::uint32_t __cdecl frame_pump_boundary_005693e0() {
    __asm {
        mov eax, frame_interface_first_006a5ca8
        push esi
        xor esi, esi
        cmp eax, esi
        je second_slot
        mov ecx, dword ptr [eax]
        push eax
        call dword ptr [ecx + 8]
        mov frame_interface_first_006a5ca8, esi
    second_slot:
        mov eax, frame_interface_second_006a5ca4
        cmp eax, esi
        je finish
        mov edx, dword ptr [eax]
        push eax
        call dword ptr [edx + 8]
        mov frame_interface_second_006a5ca4, esi
    finish:
        mov frame_interface_final_flag_006a5ca0, esi
        pop esi
        ret
    }
}
}
