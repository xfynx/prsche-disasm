// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Originals0058f8e0(15B),0058f8f0(708B). All storage is canonical reuse.
#include "audio_thread_mix_463.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original opaque frame and IDIV transport require MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
namespace {
template<class T> T get(const void* p){T x;std::memcpy(&x,p,sizeof x);return x;}
template<class T> void put(void* p,T x){std::memcpy(p,&x,sizeof x);}
U address(const void* p){return reinterpret_cast<U>(p);}
template<class F> F method(U object,U offset){return reinterpret_cast<F>(get<U>(reinterpret_cast<void*>(get<U>(reinterpret_cast<void*>(object))+offset)));}
U channels(){return get<U>(application_audio_device_state_006b48c0.data()+0x1c);}
U shift(U value,U count){return value<<(count&31u);}
U divide(I numerator,I denominator){
    U result;
    __asm {
        mov eax,numerator
        cdq
        idiv denominator
        mov result,eax
    }
    return result;
}
}
// Original allocated0x2c bytes above four saved registers. The adapter retains
// every opaque local; GetStatus/Lock failure outputs are never zero-filled.
extern "C" void __cdecl audio_thread_mixer_core_463(B* frame){
    if(audio_ds_device_006ad760==0)return;
    using Status=I(__stdcall*)(U,U*);
    U object=audio_ds_buffers_006ad768[0];
    (void)method<Status>(object,0x24)(object,reinterpret_cast<U*>(frame+0x1c));
    const B status=frame[0x1c];
    if((status&2u)!=0 || static_cast<I>(audio_ds_mix_guard_006aeff4)>100){
        object=audio_ds_buffers_006ad768[0];
        using Stop=I(__stdcall*)(U);(void)method<Stop>(object,0x50)(object);
        audio_ds_mix_guard_006aeff4=0;return;
    }
    object=audio_ds_buffers_006ad768[0];
    if((status&1u)==0){
        using Play=I(__stdcall*)(U,U,U,U);(void)method<Play>(object,0x30)(object,0,0,1);
        audio_ds_mix_guard_006aeff4=0;return;
    }
    using Position=I(__stdcall*)(U,U*,U*);
    if(method<Position>(object,0x10)(object,nullptr,&audio_ds_stream_006ad77c.raw[2])!=0)return;
    U position=static_cast<U>(static_cast<I>(audio_ds_stream_006ad77c.raw[2])>>1);
    U channel_word=channels();
    if(application_audio_device_state_006b48c0[0x24]==0)
        position=divide(static_cast<I>(position),static_cast<I>(channel_word&255u));
    const U previous=audio_ds_stream_006ad77c.raw[3];
    const U ring=audio_ds_stream_006ad77c.raw[14];
    position&=0x00fffff0u;audio_ds_stream_006ad77c.raw[2]=position;
    const U advance=static_cast<I>(position)>=static_cast<I>(previous)?position-previous:ring-previous+position;
    audio_ds_stream_006ad77c.raw[1]+=advance;
    if(position==previous)++audio_ds_mix_guard_006aeff4;else audio_ds_mix_guard_006aeff4=0;
    U cursor=audio_ds_stream_006ad77c.raw[4];
    for(;;){
        U end=(audio_ds_stream_006ad77c.raw[5]+position)&0x000ffff0u;put(frame+0x14,end);
        if(static_cast<I>(end)>=static_cast<I>(ring)){end-=ring;put(frame+0x14,end);}
        U first,second;
        if(static_cast<I>(end)>=static_cast<I>(cursor)){first=end-cursor;second=0;}
        else {first=ring-cursor;second=end;}
        put(frame+0x24,first);put(frame+0x28,second);
        if(static_cast<I>(first+second)<static_cast<I>(ring-16u))break;
        audio_ds_stream_006ad77c.raw[5]+=16;
    }
    if(audio_ds_hardware_006ad778==0){
        audio_thread_mix_refresh_0058fcd0();
        cursor=audio_ds_stream_006ad77c.raw[4];position=audio_ds_stream_006ad77c.raw[2];channel_word=channels();
    }
    audio_ds_stream_006ad77c.raw[3]=position;
    put(frame+0x10,address(frame+0x24));put(frame+0x18,U{2});
    do {
        const U count=get<U>(reinterpret_cast<void*>(get<U>(frame+0x10)));
        if(count!=0){
            audio_ds_stream_006ad77c.raw[0]+=count;
            using Lock=I(__stdcall*)(U,U,U,U*,U*,U*,U*,U);
            if(application_audio_device_state_006b48c0[0x24]!=0){
                for(U index=0;index<(channel_word&255u);++index){
                    if(index!=0)cursor=audio_ds_stream_006ad77c.raw[4];
                    object=audio_ds_buffers_006ad768[index];
                    (void)method<Lock>(object,0x2c)(object,cursor*2u,count*2u,reinterpret_cast<U*>(frame+0x2c+index*4),reinterpret_cast<U*>(frame+0x20),nullptr,nullptr,0);
                    channel_word=channels();
                }
            }else{
                object=audio_ds_buffers_006ad768[0];
                (void)method<Lock>(object,0x2c)(object,shift(cursor,channel_word),shift(count,channel_word),reinterpret_cast<U*>(frame+0x2c),reinterpret_cast<U*>(frame+0x20),nullptr,nullptr,0);
            }
            audio_thread_mix_render_0058fbc0(reinterpret_cast<U*>(frame+0x2c),count);
            using Unlock=I(__stdcall*)(U,U,U,U,U);
            if(application_audio_device_state_006b48c0[0x24]!=0){
                channel_word=channels();
                for(U index=0;index<(channel_word&255u);++index){
                    object=audio_ds_buffers_006ad768[index];
                    (void)method<Unlock>(object,0x4c)(object,get<U>(frame+0x2c+index*4),count*2u,0,0);
                    channel_word=channels();
                }
            }else{
                object=audio_ds_buffers_006ad768[0];
                (void)method<Unlock>(object,0x4c)(object,get<U>(frame+0x2c),shift(count,application_audio_device_state_006b48c0[0x1c]),0,0);
                channel_word=channels();
            }
            audio_ds_stream_006ad77c.raw[4]=0;cursor=0;
        }
        put(frame+0x10,get<U>(frame+0x10)+4);put(frame+0x18,get<U>(frame+0x18)-1);
    }while(get<U>(frame+0x18)!=0);
    audio_ds_stream_006ad77c.raw[4]=get<U>(frame+0x14);
    if(audio_backend_flag_summary_006b4884!=0)audio_thread_mix_voices_0058f6c0();
}
__declspec(naked) void __cdecl audio_thread_mixer_0058f8f0(){
    __asm {
        sub esp,2ch
        push esi
        push ebx
        push ebp
        push edi
        mov eax,esp
        push eax
        call audio_thread_mixer_core_463
        add esp,4
        pop edi
        pop ebp
        pop ebx
        pop esi
        add esp,2ch
        ret
    }
}
// Preserve the original15B wrapper's lock/mixer/tail-leave ordering.
__declspec(naked) void __cdecl audio_thread_mix_0058f8e0(){
    __asm {
        call audio_backend_enter_0058e2f0
        call audio_thread_mixer_0058f8f0
        jmp audio_backend_leave_0058e300
    }
}
}
