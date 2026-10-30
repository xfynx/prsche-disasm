// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full0058f1f0(38B),005983b0(163B),00598020(122B). No new platform APIs.
#include "audio_release_chain_458.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 compare and COM transport require MSVC x86
#endif
extern float _DAT_005b24a8; // Accepted221 original scalar, exactly1.0f.
namespace porsche {
AudioReleaseStorage458 audio_release_storage_006b174c{};
std::uint32_t audio_release_format_006b16a4=0;
std::uint8_t& audio_release_channel_count_006b16a5=
    reinterpret_cast<std::uint8_t*>(&audio_release_format_006b16a4)[1];
namespace {
using U=std::uint32_t;
U word(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
void free_and_clear(U& slot) {
    const U address=slot;
    if(address!=0){(void)audio_backend_pool_release_0058ac30(address);slot=0;}
}
// Original FCOMP sets C0 on both less-than and unordered. Keep its FNSTSW
// interpretation and floating exception/status behavior, rather than use SSE.
bool below_or_unordered(U factor_bits) {
    unsigned short status;
    __asm {
        fld dword ptr factor_bits
        fcomp dword ptr _DAT_005b24a8
        fnstsw ax
        mov status,ax
    }
    return (status&0x100u)!=0;
}
}
void __cdecl audio_release_filters_00598020(U factor_bits) {
    for(U index=0;index<audio_release_channel_count_006b16a5;++index) {
        auto& slot=audio_release_storage_006b174c.filter[index];
        if(below_or_unordered(factor_bits)) {
            U object=slot;
            if(object==0) {
                slot=application_audio_backend_allocate_0058aae0(0x1c);
                audio_release_filter_initialize_0059a170(slot);
                object=slot; // Original reloads the global after the child.
                const U zero=0;
                std::memcpy(reinterpret_cast<void*>(object),&zero,4);
            }
            audio_release_filter_set_0059a150(object,factor_bits);
        } else free_and_clear(slot);
    }
}
void __cdecl audio_release_mixer_005983b0() {
    auto& state=audio_release_storage_006b174c;
    free_and_clear(state.optional);
    free_and_clear(state.table);
    for(U index=0;index<2;++index)free_and_clear(state.raw[index]);
    for(U index=0;index<audio_release_channel_count_006b16a5;++index)
        free_and_clear(state.channel_raw[index]);
    audio_release_filters_00598020(0x40000000u);
}
std::int32_t __cdecl audio_device_release_ds_0058f1f0() {
    audio_release_property_0058eba0();
    if(const U device=audio_ds_device_006ad760) {
        using Release=U(__stdcall*)(U);
        reinterpret_cast<Release>(word(word(device)+8))(device);
        audio_ds_device_006ad760=0;
    }
    audio_release_mixer_005983b0();
    return 0;
}
}
