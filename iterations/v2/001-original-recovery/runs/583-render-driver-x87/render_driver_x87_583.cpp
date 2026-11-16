// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original00540500..00540546, 71 bytes. The parameter-slot write is observable.
#include "render_driver_x87_583.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_loader.hpp"
#include "../515-render-driver-constructors/render_driver_515.hpp"
#include "../522-audio-stream-transform/audio_stream_transform_522.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 argument slots and x87 operations required.
#endif

namespace porsche {
__declspec(naked) void __cdecl render_driver_x87_handler_00540500(std::uint32_t,
                                                               std::uint32_t) {
    __asm {
        mov eax, game_setup_movie_service_0069ed0c
        mov ecx, dword ptr [eax]
        mov edx, dword ptr [ecx + 4]
        mov ecx, dword ptr [esp + 8]
        mov eax, dword ptr [edx + 30h]
        add eax, ecx
        mov ecx, render_driver_context_0069e0d4
        mov dword ptr [esp + 8], eax
        test dword ptr [ecx + 117e4h], 20000h
        jz set_driver_state
        fild dword ptr [esp + 8]
        fmul audio_stream_s16_scale_005b3e10
        fstp dword ptr [ecx + 1180ch]
        ret
    set_driver_state:
        push eax
        mov eax, dword ptr [esp + 8]
        push eax
        call dword ptr [render_thrash_exports_006bd910 + 108]
        ret
    }
}
}
