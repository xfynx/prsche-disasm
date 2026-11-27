// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00459260..00459504; affine kernels at 00459510/560/5b0 are composed below.
#include "scene_records_reset_871.hpp"
#include <cstring>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error This recovery requires the original x86 x87 operations.
#endif

extern float _DAT_005b253c;

namespace porsche {
extern void* scene_stage_58b80_00627e08;
extern std::uint32_t second_session_random_state_005ceae0;
extern std::uint32_t second_session_random_multiplier_005ceae4;
void* __cdecl scene_flare_table_get_0045dd80();
float __cdecl rand_unit_005561d0();

namespace {
using U = std::uint32_t;
using I = std::int32_t;
using B = unsigned char;
U word(const void* p, U off) { U v; std::memcpy(&v, static_cast<const B*>(p)+off, 4); return v; }
void put(void* p, U off, U v) { std::memcpy(static_cast<B*>(p)+off, &v, 4); }
void* pointer(const void* p, U off) { return reinterpret_cast<void*>(word(p,off)); }
float real(const void* p,U off) { float v; std::memcpy(&v,static_cast<const B*>(p)+off,4); return v; }
void put_real(void* p,U off,float v) { std::memcpy(static_cast<B*>(p)+off,&v,4); }

// FCOMP's C3 bit treats unordered as equal, so NaNs retain the cached count.
bool same_or_unordered(float a,float b) {
    unsigned short status;
    __asm { fld a }
    __asm { fcomp b }
    __asm { fnstsw status }
    return (status & 0x4000u) != 0;
}

I rounded_count(float sample,float scale) {
    const float half=0.5f;
    float intermediate;
    I result;
    __asm { fld sample }
    __asm { fmul scale }
    __asm { fsub half }
    __asm { fstp intermediate }
    __asm { fld intermediate }
    __asm { fistp result }
    return result;
}

// ECX and EDX point to the scale and base. Leave the unrounded result in ST0.
__declspec(naked) double __fastcall affine_sample(const float*, const float*) {
    __asm {
        mov eax, second_session_random_multiplier_005ceae4
        imul eax, second_session_random_state_005ceae0
        fld dword ptr [ecx]
        mov ecx, eax
        and ecx, 0ffffh
        mov second_session_random_state_005ceae0, ecx
        shr eax, 8
        and eax, 0ffffh
        push eax
        fild dword ptr [esp]
        add esp, 4
        fmulp st(1), st(0)
        fmul _DAT_005b253c
        fadd dword ptr [edx]
        ret
    }
}
} // namespace

__declspec(naked) double __fastcall scene_record_sample_00459510(void*, void*) {
    __asm {
        lea edx, [ecx + 8604h]
        add ecx, 860ch
        jmp affine_sample
    }
}

__declspec(naked) double __fastcall scene_record_sample_00459560(void*, void*) {
    __asm {
        lea edx, [ecx + 8610h]
        add ecx, 8618h
        jmp affine_sample
    }
}

__declspec(naked) double __fastcall scene_record_sample_004595b0(void*, void*) {
    __asm {
        lea edx, [ecx + 861ch]
        add ecx, 8628h
        jmp affine_sample
    }
}

namespace {
void reset_record(void* record,float sample) {
    std::memset(static_cast<B*>(record)+0x83a0,0,401);
    for(U i=0;i<8;++i) {
        const float random=rand_unit_005561d0();
        // rand_unit is dyadic and exact. __ftol truncates after multiplication.
        const I delay=static_cast<I>(static_cast<double>(random)*1000.0);
        put(record,0x8534+4*i,static_cast<U>(delay));
        put(record,0x855c+12*i,0);
        put(record,0x8558+12*i,0);
        put(record,0x8554+12*i,0);
    }
    put(record,0x85b4,0);
    if(!same_or_unordered(real(record,0),sample)) {
        put_real(record,0,sample);
        const I count=rounded_count(sample,real(record,0x862c));
        put(record,8,count<3 ? 0u : static_cast<U>(count));
    }
    put(record,0x8600,0);
    put(record,4,word(record,8));
    for(I i=0;i<static_cast<I>(word(record,4));++i) {
        *(static_cast<B*>(record)+0x83a0+i)=1;
        auto* destination = static_cast<B*>(record) + 12 + 48*i;
        // Store each ST0 result to binary32 before the next RNG update.
        __asm {
            mov ecx, record
            call scene_record_sample_00459510
            mov eax, destination
            fstp dword ptr [eax]
            mov ecx, record
            call scene_record_sample_00459560
            mov eax, destination
            fstp dword ptr [eax+4]
            mov ecx, record
            call scene_record_sample_004595b0
            mov eax, destination
            fstp dword ptr [eax+8]
        }
    }
}
}

void __cdecl session_scene_records_reset_00459260() {
    void* const stage=scene_stage_58b80_00627e08;
    put(stage,0,0);
    const float first=scene_route_first_sample_0045cfd0(scene_flare_table_get_0045dd80(),nullptr);
    const float second=scene_route_second_sample_0045d000(scene_flare_table_get_0045dd80(),nullptr);
    reset_record(pointer(stage,4),first);
    reset_record(pointer(stage,8),second);
    scene_record_emitter_reset_004581a0(pointer(stage,12),nullptr,second,first);
}
}
