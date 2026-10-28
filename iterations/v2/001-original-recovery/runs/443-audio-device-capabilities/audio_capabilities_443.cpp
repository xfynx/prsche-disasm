// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full0058e650(302B),0058f860(17B),0058ea90(258B),0058eba0(53B).
#include "audio_capabilities_443.hpp"
#include <cstring>
namespace porsche {
std::uint32_t audio_ds_device_006ad760=0,audio_ds_primary_006ad764=0;
std::uint8_t audio_ds_hardware_006ad778=0;
std::int8_t audio_ds_property_available_006ad779=0;
std::uint32_t audio_ds_property_006aefdc=0,audio_ds_temporary_006aefe0=0;
alignas(4) const std::uint8_t audio_property_interface_guid_005bfd40[16]={0x30,0xac,0xef,0x31,0x5c,0x51,0xd0,0x11,0xa9,0xaa,0x00,0xaa,0x00,0x61,0xbe,0x93};
alignas(4) const std::uint8_t audio_property_set_guid_005c17d8[16]={0xc1,0x6f,0x4e,0x4a,0x41,0xc3,0xd1,0x11,0xb7,0x3a,0x44,0x45,0x53,0x54,0x00,0x00};
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address) {U x;std::memcpy(&x,reinterpret_cast<const void*>(address),4);return x;}
template<class F> F method(U object,U offset) {return reinterpret_cast<F>(word(word(object)+offset));}
using Release=U(__stdcall*)(U);
using Create=I(__stdcall*)(U,const void*,U*,U);
void release(U object) {method<Release>(object,8)(object);}
}
std::uint32_t __cdecl audio_active_window_0058f860() {
    void* window=audio_platform_foreground_window();
    if(!window) window=audio_platform_desktop_window();
    return reinterpret_cast<std::uint32_t>(window);
}
void __cdecl audio_release_property_0058eba0() {
    if(const U property=audio_ds_property_006aefdc) {
        release(property);audio_ds_property_006aefdc=0;
    }
    if(const U temporary=audio_ds_temporary_006aefe0) {
        release(temporary);audio_ds_temporary_006aefe0=0;
    }
    audio_ds_property_available_006ad779=0;
}
void __cdecl audio_probe_property_0058ea90(U query_support) {
    audio_release_property_0058eba0();
    // All18 meaningful WAVEFORMATEX bytes are explicitly written by the original.
    const std::uint8_t wave[18]={1,0,1,0,0x11,0x2b,0,0,0x22,0x56,0,0,2,0,16,0,0,0};
    U descriptor[9]={};descriptor[0]=0x24;descriptor[1]=0x8014;descriptor[2]=0x80;
    descriptor[4]=reinterpret_cast<U>(wave);
    U device=audio_ds_device_006ad760;
    if(method<Create>(device,0xc)(device,descriptor,&audio_ds_temporary_006aefe0,0)!=0) return;
    using Query=I(__stdcall*)(U,const void*,U*);
    U temporary=audio_ds_temporary_006aefe0;
    if(method<Query>(temporary,0)(temporary,audio_property_interface_guid_005bfd40,&audio_ds_property_006aefdc)!=0) {
        temporary=audio_ds_temporary_006aefe0;
        release(temporary);audio_ds_temporary_006aefe0=0;return;
    }
    if(query_support!=0) {
        using Support=I(__stdcall*)(U,const void*,U,U*);
        const U property=audio_ds_property_006aefdc;
        U support; // Only read after the API success path, which must write it.
        if(method<Support>(property,0x14)(property,audio_property_set_guid_005c17d8,0,&support)==0 && (support&3u)==3u) {
            audio_ds_property_available_006ad779=1;return;
        }
    }
    if(audio_ds_property_available_006ad779==0) audio_release_property_0058eba0();
}
I __cdecl audio_probe_capabilities_0058e650(U* capacity,I* property_available) {
    *property_available=0;
    const I creation=audio_direct_sound_create_00597f70(nullptr,&audio_ds_device_006ad760,nullptr);
    if(creation!=0) {
        audio_ds_device_006ad760=0;
        if(static_cast<U>(creation)==0x8878000au) return -18;
        return static_cast<U>(creation)==0x88780078u?-10:-1;
    }
    using Cooperative=I(__stdcall*)(U,U,U);
    const auto cooperative=method<Cooperative>(audio_ds_device_006ad760,0x18);
    const U window=audio_active_window_0058f860();
    cooperative(audio_ds_device_006ad760,window,2); // Result ignored; vtable captured before window.
    struct Caps {U size;std::uint8_t opaque[92];};
    Caps caps;caps.size=0x60; // Original does not initialize the remaining92 bytes.
    using GetCaps=I(__stdcall*)(U,void*);
    U device=audio_ds_device_006ad760;
    I result=0;
    if(method<GetCaps>(device,0x10)(device,&caps)!=0) result=-1;
    else {
        U flags,maximum;
        std::memcpy(&flags,reinterpret_cast<const std::uint8_t*>(&caps)+4,4);
        std::memcpy(&maximum,reinterpret_cast<const std::uint8_t*>(&caps)+0x2c,4);
        const auto hardware=static_cast<std::uint8_t>((flags>>5)&1u);
        *capacity=maximum;
        audio_ds_hardware_006ad778=hardware;
        U descriptor[9]={};descriptor[0]=0x24;descriptor[1]=0x11;
        device=audio_ds_device_006ad760;
        if(method<Create>(device,0xc)(device,descriptor,&audio_ds_primary_006ad764,0)==0) {
            audio_probe_property_0058ea90(1);
            *property_available=audio_ds_property_available_006ad779;
            audio_release_property_0058eba0();
        }
    }
    if(const U current=audio_ds_device_006ad760) release(current);
    audio_ds_device_006ad760=0;
    return result;
}
} // namespace porsche
