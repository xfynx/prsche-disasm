// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full0058fcd0(209B) and0058f6c0(213B), no new original storage.
#include "audio_mixer_control_466.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original data-pointer and callback transport requires MSVC x86
#endif
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
U read(U address){U value;std::memcpy(&value,reinterpret_cast<void*>(address),4);return value;}
}
void __cdecl audio_thread_mix_refresh_0058fcd0() {
    auto& s=audio_ds_stream_006ad77c.raw;
    U produced=s[0];
    if(produced>0x11000000u){produced-=0x10000000u;s[0]=produced;s[1]-=0x10000000u;}
    U difference=produced-s[1];const U ring=s[14];
    if(static_cast<I>(difference)>=static_cast<I>(ring)){produced-=ring;difference-=ring;s[0]=produced;}
    if(static_cast<I>(difference)<0){
        if(produced!=0){
            const U margin=(s[5]-difference+15u)&0x000ffff0u;s[5]=margin;
            if(static_cast<I>(margin)>static_cast<I>(s[6]))s[5]=s[6];
            s[10]=0;
        }
        return;
    }
    const U stable=s[10]+1u;s[10]=stable;
    U minimum=s[9];
    if(static_cast<I>(difference)<static_cast<I>(minimum)){minimum=difference;s[9]=minimum;}
    if(static_cast<I>(stable)>=3000 && static_cast<I>(stable)%10==0){
        if(static_cast<I>(minimum)>16)s[5]=(s[5]-1u)&0x000ffff0u;
        s[9]=ring;
    }
}
void __cdecl audio_thread_mix_voices_0058f6c0() {
    U index=application_audio_device_state_006b48c0[0x1d];
    if(static_cast<I>(index)>=static_cast<I>(audio_backend_channel_count_006b49a4))return;
    U offset=index*248u;U table=audio_backend_voice_table_006b489c;
    do {
        const U object_cell=table+offset+0xc4u;
        if(read(object_cell)!=0){
            const U data_cell=table+offset+0xbcu;
            const U callback_cell=table+offset+0xecu;
            U request;
            do {
                using Query=I(__cdecl*)(U);
                request=static_cast<U>(reinterpret_cast<Query>(read(callback_cell))(read(data_cell)));
                const I limited=static_cast<I>(request)>256?256:static_cast<I>(request);
                const U object=read(object_cell);
                using Process=I(__cdecl*)(U,I,U,U,U);
                const auto result=reinterpret_cast<Process>(read(object+4u))(object,limited,audio_device_aligned_buffers_006b4890[0],audio_device_aligned_buffers_006b4890[1],0);
                if(result<0){(void)audio_backend_stop_voice_0058a8b0(index);break;}
            }while(static_cast<I>(request-256u)>0);
            table=audio_backend_voice_table_006b489c;
        }
        ++index;offset+=248u;
    }while(static_cast<I>(index)<static_cast<I>(audio_backend_channel_count_006b49a4));
}
}
