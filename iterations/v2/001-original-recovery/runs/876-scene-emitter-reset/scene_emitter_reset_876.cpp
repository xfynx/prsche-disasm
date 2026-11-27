// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "scene_emitter_reset_876.hpp"
#include "../821-scene-stage-58b80-ctor/scene_stage_58b80_ctor_821.hpp"
#include <cstdint>
#include <cstring>

extern float _DAT_005b24a8;
namespace porsche {
std::int64_t __cdecl audio_stream_ftol_005a0f98();

void __fastcall scene_emitter_place_004583f0(void* self, void*, unsigned index) {
    auto* object = static_cast<unsigned char*>(self);
    auto* coords = object + index * 0x30u + 0x0cu;
    const double half = 0.5;
    float first_offset;
    // The first offset is stored to a float before drawing the next random value.
    __asm {
        call rand_unit_005561d0
        mov eax, object
        fmul dword ptr [eax+6768h]
        fld dword ptr [eax+6768h]
        fmul qword ptr [half]
        fsubp st(1),st
        fstp first_offset
        call rand_unit_005561d0
        mov eax, object
        fmul dword ptr [eax+676ch]
    }
    for (unsigned axis = 0; axis < 3; ++axis) {
        __asm {
            mov eax, object
            mov edx, coords
            mov ecx, axis
            fld st(0)
            fmul dword ptr [eax+ecx*4+6770h]
            fadd dword ptr [eax+ecx*4+6788h]
            fstp dword ptr [edx+ecx*4]
        }
    }
    __asm { fstp st(0) }
    for (unsigned axis = 0; axis < 3; ++axis) {
        __asm {
            mov eax, object
            mov edx, coords
            mov ecx, axis
            fld first_offset
            fmul dword ptr [eax+ecx*4+677ch]
            fadd dword ptr [edx+ecx*4]
            fstp dword ptr [edx+ecx*4]
        }
    }
}

void __fastcall scene_record_emitter_reset_004581a0(void* self, void*, float second, float first) {
    auto* object = static_cast<unsigned char*>(self);
    std::memset(object + 0x67b4, 0, 48);
    scene_splt_zero_tables_004580e0(self, nullptr);

    const float half = 0.5f, count_scale = 150.0f;
    float scaled;
    std::int32_t rounded;
    // These branches use FCOM status bits for equal and unordered comparisons.
    __asm {
        fld second
        fadd first
        fcom _DAT_005b24a8
        fnstsw ax
        test ah,41h
        jnz gate
        fstp st(0)
        fld _DAT_005b24a8
    gate:
        mov edx, object
        fld second
        fcomp half
        fnstsw ax
        test ah,41h
        jz clear_gate
        fld first
        fcomp half
        fnstsw ax
        test ah,1
        jnz clear_gate
        mov byte ptr [edx+66fah],1
        jmp check_value
    clear_gate:
        mov byte ptr [edx+66fah],0
    check_value:
        fcom dword ptr [edx]
        fnstsw ax
        test ah,40h
        jnz keep_count
        fst dword ptr [edx]
        fmul count_scale
        fstp scaled
        fld scaled
        fistp rounded
        fild rounded
        fmul dword ptr [edx+67b0h]
        call audio_stream_ftol_005a0f98
        mov edx,object
        mov [edx+8],eax
        jmp set_active
    keep_count:
        fstp st(0)
    set_active:
    }
    std::memcpy(object+4, object+8, 4);
    for (std::int32_t i=0;;++i) {
        std::int32_t count;
        std::memcpy(&count,object+4,4);
        if (i>=count) break;
        object[0x4200+i]=1;
        scene_emitter_place_004583f0(object,nullptr,static_cast<unsigned>(i));
    }
}
} // namespace porsche
