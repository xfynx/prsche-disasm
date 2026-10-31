// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_property_apply_471.hpp"
#include "../443-audio-device-capabilities/audio_capabilities_443.hpp"
#include "../462-audio-directsound-initialize/audio_directsound_state_462.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 conversion requires MSVC x86
#endif
namespace porsche {
// Raw readonly DWORDs: the last mantissa bit of005c169c is significant.
const std::uint32_t audio_property_scale_005c169c=0x33800001u;
const std::uint32_t audio_property_scale_005c16a0=0x36c80000u;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address){U x;std::memcpy(&x,reinterpret_cast<const void*>(address),4);return x;}
using Set=I(__stdcall*)(U,const void*,U,U,U,const void*,U);
I set_property(U object,U id,const void* data){
    const auto method=reinterpret_cast<Set>(word(word(object)+0x10));
    return method(object,audio_property_set_guid_005c17d8,id,0,0,data,4);
}
}
I __cdecl audio_ds_apply_property_0058e780(U mode,U parameter3,U parameter4){
    const auto available=audio_ds_property_available_006ad779;
    U preset=9,mix=0x3f800000u;
    audio_ds_property_settings_006aefe4[0]=mode;
    audio_ds_property_settings_006aefe4[1]=parameter3;
    audio_ds_property_settings_006aefe4[2]=parameter4;
    if(available==0)return -1;
    if(mode==0 || mode==1){parameter3=0xffffffffu;parameter4=0xffffffffu;mix=0;preset=1;}
    else if(mode==2)preset=1;
    else switch(mode){
    case 3:preset=11;break;case 5:preset=4;break;case 10:preset=2;break;
    case 13:preset=19;break;case 15:preset=15;break;case 17:preset=17;break;
    case 20:preset=16;break;case 23:preset=20;break;case 25:preset=12;break;
    case 27:preset=14;break;case 30:preset=0;break;case 32:preset=5;break;
    case 33:preset=3;break;case 34:preset=18;break;case 35:preset=21;break;
    case 36:preset=8;break;case 37:preset=13;break;case 38:preset=6;break;
    case 40:preset=7;break;case 50:preset=9;break;case 55:preset=10;break;
    case 60:preset=22;break;case 70:preset=24;break;case 73:preset=23;break;
    case 76:preset=25;break;
    default:if(static_cast<I>(mode)>=100 && static_cast<I>(mode)<=120)preset=10;
    }
    if(set_property(audio_ds_property_006aefdc,1,&preset)!=0)return -1;
    if(set_property(audio_ds_property_006aefdc,2,&mix)!=0)return -1;
    if(parameter3!=0xffffffffu){
        const I signed3=static_cast<I>(parameter3);float value3;
        __asm {
            fild signed3
            fmul dword ptr [audio_property_scale_005c16a0]
            fstp value3
        }
        if(set_property(audio_ds_property_006aefdc,3,&value3)!=0)return -1;
    }
    if(parameter4!=0xffffffffu){
        const I signed4=static_cast<I>(parameter4);float value4;
        __asm {
            fild signed4
            fmul dword ptr [audio_property_scale_005c169c]
            fstp value4
        }
        if(set_property(audio_ds_property_006aefdc,4,&value4)!=0)return -1;
    }
    return 0;
}
}
