// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "route_keyframe_samples_875.hpp"
#include <cstring>

extern float _DAT_005b24a8;
namespace porsche {
extern void* track_road_data_00628bc0;
static_assert(sizeof(RouteKeyframe875) == 0x30 && sizeof(RouteCursor875) == 0x10);
using I = std::int32_t;
using U = std::uint32_t;

void __fastcall route_select_key_0045a540(RouteCursor875* cursor, void*, I index) {
    cursor->current = index;
    const I next = static_cast<I>(static_cast<U>(index) + 1u);
    cursor->next = next < cursor->count ? next : 0;
}

namespace {
I forward_distance(I from, I to, I length) {
    I delta = static_cast<I>(static_cast<U>(to) - static_cast<U>(from));
    const I half = length / 2;
    if (delta > 0 && delta > half)
        delta = static_cast<I>(static_cast<U>(delta) - static_cast<U>(length));
    else if (delta < 0 && delta < -half)
        delta = static_cast<I>(static_cast<U>(delta) + static_cast<U>(length));
    return delta < 0 ? static_cast<I>(static_cast<U>(delta) + static_cast<U>(length)) : delta;
}

// Returns the signed FILD operands in the same order as the x87 leaf below.
__declspec(noinline) bool __cdecl key_distances(RouteCursor875* cursor, I position, I* values) {
    auto in_interval = [&] {
        return cursor->keys[cursor->current].position <= position &&
               position < cursor->keys[cursor->next].position;
    };
    if (!in_interval()) {
        route_select_key_0045a540(cursor, nullptr, 0);
        while (cursor->current < cursor->count - 1 && !in_interval())
            route_select_key_0045a540(cursor, nullptr, cursor->current + 1);
    }
    const auto from = cursor->keys[cursor->current].position;
    const auto to = cursor->keys[cursor->next].position;
    if (cursor->current == cursor->next || from == to) return false;
    I length;
    std::memcpy(&length, track_road_data_00628bc0, sizeof length);
    values[0] = forward_distance(from, position, length);
    values[1] = forward_distance(from, to, length);
    return true;
}
}

__declspec(naked) double __fastcall route_key_weight_0045a560(RouteCursor875*, void*, I) {
    __asm {
        sub esp, 8
        mov eax, esp
        push eax
        push dword ptr [esp+16]
        push ecx
        call key_distances
        add esp, 12
        test al, al
        jz same_key
        fild dword ptr [esp]
        fild dword ptr [esp+4]
        fdivp st(1), st
        fsubr _DAT_005b24a8
        jmp finished
    same_key:
        fld _DAT_005b24a8
    finished:
        add esp, 8
        ret 4
    }
}

namespace {
// EDX selects the component. Keep the unrounded sum in ST0.
__declspec(naked) double __fastcall interpolate(RouteCursor875*, unsigned, float) {
    __asm {
        mov eax, [ecx]
        add eax, edx
        imul edx, [ecx+12], 48
        imul ecx, [ecx+8], 48
        fld _DAT_005b24a8
        fsub dword ptr [esp+4]
        fmul dword ptr [eax+edx]
        fld dword ptr [esp+4]
        fmul dword ptr [eax+ecx]
        faddp st(1), st
        ret 4
    }
}
}

__declspec(naked) double __fastcall route_key_sample_0045a940(RouteCursor875*, void*, float) {
    __asm {
        mov edx, 32
        jmp interpolate
    }
}

__declspec(naked) float __fastcall scene_route_first_sample_0045cfd0(void*, void*) {
    __asm {
        push esi
        mov esi, ecx
        push dword ptr [esi+50h]
        mov ecx, [esi+48h]
        call route_key_weight_0045a560
        sub esp, 4
        fstp dword ptr [esp]
        mov ecx, [esi+48h]
        call route_key_sample_0045a940
        pop esi
        ret
    }
}

__declspec(naked) double __fastcall route_key_sample_0045a8e0(RouteCursor875*, void*, float) {
    __asm {
        mov edx, 24
        jmp interpolate
    }
}

__declspec(naked) float __fastcall scene_route_second_sample_0045d000(void*, void*) {
    __asm {
        push esi
        mov esi, ecx
        push dword ptr [esi+50h]
        mov ecx, [esi+48h]
        call route_key_weight_0045a560
        sub esp, 4
        fstp dword ptr [esp]
        mov ecx, [esi+48h]
        call route_key_sample_0045a8e0
        pop esi
        ret
    }
}
} // namespace porsche
