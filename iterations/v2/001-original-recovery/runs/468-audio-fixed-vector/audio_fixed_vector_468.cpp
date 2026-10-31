// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Exact257-WORD data and scalars, not regenerated trigonometry.
#include "audio_fixed_vector_468.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 intermediate semantics require MSVC x86
#endif
#pragma section(".orig$fc",read)
__declspec(allocate(".orig$fc")) float _DAT_005b253c=1.0f/65536.0f;
__declspec(allocate(".orig$fc")) float _DAT_005b2624=-1.0f;
namespace porsche {
alignas(4) std::uint16_t audio_sine_quarter_005e3924[257]={
#include "quarter-values.inc"
};
std::int32_t __cdecl audio_fixed_sine_0059b630(std::uint32_t phase){
    const auto index=phase&255u;const auto quadrant=(phase>>8)&3u;
    if(quadrant==0)return audio_sine_quarter_005e3924[index];
    if(quadrant==1)return audio_sine_quarter_005e3924[256u-index];
    if(quadrant==2)return -static_cast<std::int32_t>(audio_sine_quarter_005e3924[index]);
    return -static_cast<std::int32_t>(audio_sine_quarter_005e3924[256u-index]);
}
void __cdecl audio_ds_spatial_vector_00597f80(std::uint32_t heading,std::uint32_t elevation,std::uint32_t* output){
    using I=std::int32_t;using U=std::uint32_t;
    const U inverse=1024u-(static_cast<U>(static_cast<I>(elevation)>>6)&1023u);
    const I pitch_sine=audio_fixed_sine_0059b630(inverse);
    const I pitch_cosine=audio_fixed_sine_0059b630(inverse+256u);
    const U direction=static_cast<U>(static_cast<I>(heading)>>6);
    const I heading_sine=audio_fixed_sine_0059b630(direction);
    float pitch_single;
    __asm {
        fild pitch_cosine
        fstp pitch_single
        fild heading_sine
        fmul pitch_single
        fmul dword ptr [_DAT_005b253c]
        mov eax,output
        fstp dword ptr [eax]
        fild pitch_sine
        fmul dword ptr [_DAT_005b2624]
        fstp dword ptr [eax+4]
    }
    // The last lookup follows the first two output writes in the original.
    // Preserve this order even if output aliases the writable quarter table.
    const I heading_cosine=audio_fixed_sine_0059b630(direction+256u);
    __asm {
        fild heading_cosine
        fmul pitch_single
        fmul dword ptr [_DAT_005b253c]
        mov eax,output
        fstp dword ptr [eax+8]
    }
}
}
