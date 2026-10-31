// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete0058ebe0..0058f1ee (1551B). Parent semantics only; three original
// children remain explicit typed dependencies. No live COM replacement here.
#include "audio_directsound_initialize_462.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87/COM transport requires MSVC x86
#endif
namespace porsche {
const std::uint8_t audio_ds_spatial_interface_guid_005bfd00[16]={0x86,0xfa,0x9a,0x27,0x81,0x49,0xce,0x11,0xa5,0x21,0,0x20,0xaf,0x0b,0xe5,0x60};
const std::uint8_t audio_ds_buffer_property_guid_005c17e8[16]={0xc0,0x6f,0x4e,0x4a,0x41,0xc3,0xd1,0x11,0xb7,0x3a,0x44,0x45,0x53,0x54,0,0};
const double audio_ds_spatial_scale_005b6bd8=1.0/65536.0;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
U read32(std::size_t offset){U value;std::memcpy(&value,application_audio_device_state_006b48c0.data()+offset,4);return value;}
U read16(std::size_t offset){std::uint16_t value;std::memcpy(&value,application_audio_device_state_006b48c0.data()+offset,2);return value;}
auto& byte(std::size_t offset){return application_audio_device_state_006b48c0[offset];}
template<class F>F method(U object,U offset){return reinterpret_cast<F>(word(word(object)+offset));}
using Create=I(__stdcall*)(U,const void*,U*,U);
using Query=I(__stdcall*)(U,const void*,U*);
using Lock=I(__stdcall*)(U,U,U,U*,U*,U*,U*,U);
using Unlock=I(__stdcall*)(U,U,U,U,U);
using Play=I(__stdcall*)(U,U,U,U);
using Position=I(__stdcall*)(U,U,U,U,U);
using SetProperty=I(__stdcall*)(U,const void*,U,U,U,const void*,U);
// The three magic-multiply divisions have nonnegative bounded inputs from
// uint16 sample rate. Their exact original quotients are ordinary /1000,/50,/10.
U aligned(U numerator,U divisor){return (numerator/divisor)&0x000ffff0u;}
void zero_forward(U address,U bytes){
    for(U i=0;i<(bytes>>2);++i){const U zero=0;std::memcpy(reinterpret_cast<void*>(address+i*4),&zero,4);}
    for(U i=bytes&~3u;i<bytes;++i)*reinterpret_cast<std::uint8_t*>(address+i)=0;
}
void scale_vector(U* bits){
    // Original scales all three x87 values, including the unused Y component.
    __asm {
        mov eax,bits
        fld dword ptr [eax]
        fmul qword ptr audio_ds_spatial_scale_005b6bd8
        fstp dword ptr [eax]
        fld dword ptr [eax+4]
        fmul qword ptr audio_ds_spatial_scale_005b6bd8
        fstp dword ptr [eax+4]
        fld dword ptr [eax+8]
        fmul qword ptr audio_ds_spatial_scale_005b6bd8
        fstp dword ptr [eax+8]
    }
}
void wave16(std::uint8_t* wave,U offset,std::uint16_t value){std::memcpy(wave+offset,&value,2);}
void wave32(std::uint8_t* wave,U offset,U value){std::memcpy(wave+offset,&value,4);}
bool lock_and_clear(U index,U bytes){
    U pointer,returned_bytes; // Read only on the successful API path.
    U object=audio_ds_buffers_006ad768[index];
    if(method<Lock>(object,0x2c)(object,0,bytes,&pointer,&returned_bytes,nullptr,nullptr,0)!=0)return false;
    const U clear_bytes=audio_ds_stream_006ad77c.raw[8];
    zero_forward(pointer,clear_bytes);object=audio_ds_buffers_006ad768[index];
    (void)method<Unlock>(object,0x4c)(object,pointer,clear_bytes,0,0);
    return true;
}
}
I __cdecl audio_device_initialize_ds_0058ebe0(){
    I result=-1;
    U alternate=byte(0x24),channels=byte(0x1c);
    for(;;){
        AudioMixerConfig462 config; // Original config byte+7 is opaque/unwritten.
        config.rate=read16(0x1a);config.bits=byte(0x1d);config.channels=static_cast<std::uint8_t>(channels);
        config.mono=static_cast<std::uint8_t>(alternate==0&&channels>1);config.callback=&audio_backend_voice_finalize_00589c00;
        audio_ds_mixer_initialize_00598230(&config);
        const U callback=audio_device_callback_006b4898;
        if(callback)reinterpret_cast<void(__cdecl*)(I,U)>(callback)(audio_ds_notify_kind_006b4886,audio_ds_notify_value_006b4a08);
        auto& s=audio_ds_stream_006ad77c.raw;
        const U rate=read16(0x1a);
        s[4]=0;s[2]=0;s[3]=0;s[5]=aligned(rate*20u,1000);s[7]=0;s[0]=0;s[10]=0;s[1]=aligned(rate,50);
        const I created=audio_direct_sound_create_00597f70(nullptr,&audio_ds_device_006ad760,nullptr);
        if(created!=0){
            result=static_cast<U>(created)==0x8878000au?-18:static_cast<U>(created)==0x88780078u?-10:-1;
            audio_ds_device_006ad760=0;(void)audio_device_release_ds_0058f1f0();return result;
        }
        using Cooperative=I(__stdcall*)(U,U,U);
        const auto cooperative=method<Cooperative>(audio_ds_device_006ad760,0x18);
        const U window=audio_active_window_0058f860();
        (void)cooperative(audio_ds_device_006ad760,window,2);
        U descriptor[9]{};descriptor[0]=0x24;descriptor[1]=1;
        if(audio_backend_flag_summary_006b4883||byte(0x24))descriptor[1]=0x11;
        U device=audio_ds_device_006ad760;
        if(method<Create>(device,0xc)(device,descriptor,&audio_ds_primary_006ad764,0)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
        std::uint8_t wave[18];
        const U primary_rate=read16(0x1a);
        wave16(wave,0,1);wave16(wave,2,2);wave32(wave,4,primary_rate);wave32(wave,8,primary_rate*4u);
        wave16(wave,12,4);wave16(wave,14,16);wave16(wave,16,0);
        using Format=I(__stdcall*)(U,const void*);
        U primary=audio_ds_primary_006ad764;(void)method<Format>(primary,0x38)(primary,wave);
        if(audio_backend_flag_summary_006b4883){
            audio_probe_property_0058ea90(byte(0x23));
            (void)audio_ds_apply_property_0058e780(audio_ds_property_settings_006aefe4[0],audio_ds_property_settings_006aefe4[1],audio_ds_property_settings_006aefe4[2]);
        }
        std::memset(descriptor,0,sizeof(descriptor));descriptor[0]=0x24;descriptor[1]=0x18000;
        const U secondary_rate=read16(0x1a);
        U bytes=aligned(secondary_rate*400u,1000)*2u;
        const U half=bytes>>1;s[8]=bytes;s[14]=half;
        if(byte(0x24)){
            descriptor[1]=0x18014;wave16(wave,2,1);wave32(wave,8,secondary_rate*2u);wave16(wave,12,2);
        }else{
            bytes*=byte(0x1c);s[8]=bytes;wave32(wave,8,(secondary_rate*byte(0x1c))*2u);
            wave16(wave,2,byte(0x1c));wave16(wave,12,static_cast<std::uint16_t>(byte(0x1c)*2u));
        }
        s[9]=half;s[6]=aligned(half*8u,10);s[12]=0;s[13]=0;s[11]=0;
        descriptor[2]=bytes;descriptor[4]=reinterpret_cast<U>(wave);
        wave16(wave,0,1);wave32(wave,4,secondary_rate);wave16(wave,14,16);wave16(wave,16,0);
        if(byte(0x24)){
            bool retry=false;
            for(U index=0;index<byte(0x1c);++index){
                device=audio_ds_device_006ad760;
                if(method<Create>(device,0xc)(device,descriptor,&audio_ds_buffers_006ad768[index],0)!=0){retry=true;break;}
                U spatial;
                U buffer=audio_ds_buffers_006ad768[index];
                if(method<Query>(buffer,0)(buffer,audio_ds_spatial_interface_guid_005bfd00,&spatial)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
                U xyz[3];const U angle=read16(0x4c+(byte(0x1c)*4u+index)*2u);
                audio_ds_spatial_vector_00597f80(angle,0,xyz);scale_vector(xyz);
                if(method<Position>(spatial,0x4c)(spatial,xyz[0],0,xyz[2],0)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
                if(audio_ds_property_available_006ad779){
                    U property;buffer=audio_ds_buffers_006ad768[index];
                    if(method<Query>(buffer,0)(buffer,audio_property_interface_guid_005bfd40,&property)!=0)property=0;
                    const U value=0;
                    // Original dereferences property even when QI failed and
                    // set it to0. Preserve that fault instead of adding a guard.
                    (void)method<SetProperty>(property,0x10)(property,audio_ds_buffer_property_guid_005c17e8,1,0,0,&value,4);
                }
            }
            if(retry){
                (void)audio_device_release_ds_0058f1f0();byte(0x24)=0;byte(0x05)=2;byte(0x1c)=2;
                alternate=0;channels=2;continue;
            }
            for(U index=0;index<byte(0x1c);++index)(void)lock_and_clear(index,s[8]);
            for(U index=0;index<byte(0x1c);++index){
                const U buffer=audio_ds_buffers_006ad768[index];
                if(method<Play>(buffer,0x30)(buffer,0,0,1)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
            }
            using Current=I(__stdcall*)(U,U);
            for(U index=0;index<byte(0x1c);++index){const U buffer=audio_ds_buffers_006ad768[index];(void)method<Current>(buffer,0x34)(buffer,0);}
            return 0;
        }
        device=audio_ds_device_006ad760;
        if(method<Create>(device,0xc)(device,descriptor,&audio_ds_buffers_006ad768[0],0)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
        (void)lock_and_clear(0,s[8]);
        const U buffer=audio_ds_buffers_006ad768[0];
        if(method<Play>(buffer,0x30)(buffer,0,0,1)!=0){(void)audio_device_release_ds_0058f1f0();return result;}
        return 0;
    }
}
}
