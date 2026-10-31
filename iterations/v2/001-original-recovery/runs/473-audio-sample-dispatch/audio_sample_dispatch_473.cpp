// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_sample_dispatch_473.hpp"
#include <cstring>
namespace porsche {
std::uint32_t audio_voice_completion_counter_006aeff0=0;
std::uint16_t audio_mixer_block_stride_006b16ac=0;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U p){U x;std::memcpy(&x,reinterpret_cast<const void*>(p),4);return x;}
U device_word(U offset){U x;std::memcpy(&x,application_audio_device_state_006b48c0.data()+offset,4);return x;}
U device_rate(){std::uint16_t x;std::memcpy(&x,application_audio_device_state_006b48c0.data()+0x1a,2);return x;}
U mixer_separate(){return (audio_release_format_006b16a4>>16)&255u;}
}
void __cdecl audio_voice_check_finished_0058f650(){
    const U tick=++audio_voice_completion_counter_006aeff0;
    if((tick&3u)!=0)return;
    U index=application_audio_device_state_006b48c0[0x1d];
    while(static_cast<I>(index)<audio_backend_channel_count_006b49a4){
        const U record=audio_backend_voice_table_006b489c+index*248u;
        const U callback=word(record+0xf4);
        if(callback!=0 && reinterpret_cast<I(__cdecl*)(U)>(callback)(record+0x2c)!=0)
            (void)audio_backend_stop_voice_0058a8b0(index);
        ++index;
    }
}
void __cdecl audio_mixer_render_chunks_00598940(U* buffers,U samples){
    U outputs[4]; // Only active original slots are copied; others remain opaque.
    for(U i=0;i<audio_release_channel_count_006b16a5;++i)outputs[i]=buffers[i];
    if(mixer_separate()!=0){
        U temporary[2];temporary[0]=audio_release_storage_006b174c.optional;
        while(static_cast<I>(samples)>0){
            const U block=static_cast<I>(samples)>256?256:samples;
            temporary[1]=audio_release_storage_006b174c.optional+block*2;
            audio_mixer_process_block_00598760(block,temporary);
            audio_mixer_convert_block_0059bce0(block,temporary[0],outputs[0]);
            outputs[0]+=block<<(audio_release_channel_count_006b16a5&31u);
            samples-=256u;
        }
    }else{
        while(static_cast<I>(samples)>0){
            const U block=static_cast<I>(samples)>256?256:samples;
            audio_mixer_process_block_00598760(block,outputs);
            const U stride=audio_mixer_block_stride_006b16ac;
            const U count=audio_release_channel_count_006b16a5;
            for(U i=0;i<count;++i)outputs[i]+=stride;
            samples-=256u;
        }
    }
}
void __cdecl audio_thread_mix_render_0058fbc0(U* buffers,U samples){
    U outputs[4];
    const U initial_count=application_audio_device_state_006b48c0[0x1c];
    for(U i=0;i<initial_count;++i)outputs[i]=buffers[i];
    auto& stream=audio_ds_stream_006ad77c.raw;
    while(static_cast<I>(samples)>0){
        U available=stream[11];
        if(static_cast<I>(available)<=0){
            ++stream[12];
            reinterpret_cast<void(__cdecl*)()>(device_word(0xec))();
            const U ticks=stream[12];
            const I product=static_cast<I>(device_rate()*ticks);
            available=(static_cast<U>(product/100)-stream[13])&0x0ffffff0u;
            stream[13]+=available;
            if(static_cast<I>(ticks)>30000){stream[12]=0;stream[13]=0;}
        }
        const U block=static_cast<I>(available)<static_cast<I>(samples)?available:samples;
        stream[11]=available-block;samples-=block;
        audio_mixer_render_chunks_00598940(outputs,block);
        if(application_audio_device_state_006b48c0[0x24]!=0){
            const U count=application_audio_device_state_006b48c0[0x1c];
            for(U i=0;i<count;++i)outputs[i]+=block*2;
        }else outputs[0]+=block<<(application_audio_device_state_006b48c0[0x1c]&31u);
    }
    if(audio_backend_flag_summary_006b4885!=0)audio_voice_check_finished_0058f650();
}
}
