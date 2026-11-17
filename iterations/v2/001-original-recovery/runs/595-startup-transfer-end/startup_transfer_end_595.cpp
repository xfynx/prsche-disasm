// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004691c0..004691ca, 11 bytes, sha256 611feffed93f6a3f80fa1c77d856e92f5bade0bf69e5531b2a4189e907913d90.
// Original 00468100..00468107, 8 bytes, sha256 c7eb9fa091e6c7322d0fb94ea902913506561139a707ee74638bd57af08357e4.
#include "startup_transfer_end_595.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/render_startup.hpp"
#include "../572-startup-service-lifecycle/startup_lifecycle_572.hpp"

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 naked functions required for 00468100/004691c0 tail-jump transfer.
#endif

namespace porsche {

__declspec(naked) void __fastcall render_display_transfer_end_00468100(void*, void*) {
    __asm {
        mov ecx, dword ptr [ecx + 74h]
        jmp startup_lifecycle_end_raw_00536050
    }
}

__declspec(naked) void __cdecl startup_sequence_transfer_004691c0() {
    __asm {
        mov ecx, render_display_00628130
        jmp render_display_transfer_end_00468100
    }
}

} // namespace porsche
