// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Ten original bodies869B. Native pointer bindings reference real open providers.
#include "audio_mixer_configuration_486.hpp"
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 table construction requires MSVC x86
#endif
namespace porsche {
std::uint32_t audio_mixer_rate_006b16a0=0;
std::uint32_t audio_mixer_constructors_006b16bc[15]{};
std::uint32_t audio_mixer_object_sizes_006b1704[15]{};
std::uint32_t audio_mixer_decode_s16_006b17d8=0;
float audio_mixer_pcm8_lookup_006b00c0[256]{};
float audio_mixer_nibble_lookup_006b04c0[208]{};
const float audio_mixer_pcm8_scale_005b26b0=256.0f;
namespace {
using U=std::uint32_t;using I=std::int32_t;
U word(U address){U x;std::memcpy(&x,reinterpret_cast<const void*>(address),4);return x;}
void store(U address,U value){std::memcpy(reinterpret_cast<void*>(address),&value,4);}
I priority(U address){std::int16_t x;std::memcpy(&x,reinterpret_cast<const void*>(address+8),2);return x;}
template<class F>U address(F function){return reinterpret_cast<U>(function);}
U lanes(){return audio_release_channel_count_006b16a5;}
}
void __cdecl audio_mixer_insert_node_00596cd0(U* head,U node){
    U previous=0,current=*head;
    if(current!=0){
        const I incoming=priority(node);
        while(priority(current)<incoming){previous=current;current=word(current);if(current==0)break;}
    }
    store(node,current);
    if(previous==0)*head=node;else store(previous,node);
}
void __cdecl audio_mixer_select_kernels_00598460(){
    const auto flags=application_audio_device_state_006b48c0[0xe3];
    if(flags&4u){
        audio_mixer_accumulate_006b17d4=address(&audio_mixer_accumulate_3dnow_0059bc40);
        audio_mixer_decode_s16_006b17d8=address(&audio_mixer_decode_s16_3dnow_0059bb90);
    }else{
        audio_mixer_accumulate_006b17d4=(flags&2u)?address(&audio_mixer_accumulate_x87_0059baf0):address(&audio_mixer_accumulate_scalar_0059ba70);
        audio_mixer_decode_s16_006b17d8=address(&audio_mixer_decode_s16_x87_0059b9f0);
    }
    audio_mixer_block_stride_006b16ac=0x200;
    if((audio_release_format_006b16a4&0x00ff0000u)!=0)
        audio_mixer_block_stride_006b16ac=static_cast<std::uint16_t>(lanes()<<9);
}
void __cdecl audio_mixer_initialize_output_0059a3d0(U object){store(object+4,address(&audio_mixer_output_pcm16_0059a350));}
void __cdecl audio_mixer_register_adpcm_0059b8a0(){
    audio_mixer_constructors_006b16bc[9]=address(&audio_mixer_construct_adpcm_00597f20);
    audio_mixer_constructors_006b16bc[11]=address(&audio_mixer_construct_adpcm_stream_0059c360);
    audio_mixer_object_sizes_006b1704[9]=0xd58;audio_mixer_object_sizes_006b1704[11]=0xd64;
}
void __cdecl audio_mixer_initialize_nibble_table_0059b8d0(){
    U offset=0;
    for(U shift=0;shift<13;++shift)for(U nibble=0;nibble<16;++nibble){
        const I value=(static_cast<I>(nibble<<28)>>16)>>shift;
        float* output=audio_mixer_nibble_lookup_006b04c0+offset++;
        __asm {
            fild dword ptr value
            mov eax,output
            fstp dword ptr [eax]
        }
    }
}
void __cdecl audio_mixer_register_nibble_0059b910(){
    audio_mixer_initialize_nibble_table_0059b8d0();
    audio_mixer_constructors_006b16bc[6]=address(&audio_mixer_construct_nibble_00597dc0);
    audio_mixer_constructors_006b16bc[7]=address(&audio_mixer_construct_nibble_loop_0059c9f0);
    audio_mixer_constructors_006b16bc[8]=address(&audio_mixer_construct_nibble_stream_0059c610);
    audio_mixer_object_sizes_006b1704[6]=0xa0;audio_mixer_object_sizes_006b1704[7]=0x128;audio_mixer_object_sizes_006b1704[8]=0xa8;
}
void __cdecl audio_mixer_register_pcm16_0059b960(){
    audio_mixer_constructors_006b16bc[3]=address(&audio_mixer_construct_pcm_00597c10);
    audio_mixer_object_sizes_006b1704[3]=0x1c;
    audio_mixer_constructors_006b16bc[4]=address(&audio_mixer_construct_pcm_loop_0059cc30);
    audio_mixer_object_sizes_006b1704[4]=0x20;
    audio_mixer_constructors_006b16bc[5]=address(&audio_mixer_construct_pcm_stream_0059cb50);
    audio_mixer_object_sizes_006b1704[5]=0x24;
}
void __cdecl audio_mixer_register_pcm8_0059b9a0(){
    audio_mixer_initialize_pcm8_table_0059c1b0();
    audio_mixer_constructors_006b16bc[0]=address(&audio_mixer_construct_pcm_00597c10);
    audio_mixer_constructors_006b16bc[1]=address(&audio_mixer_construct_pcm_loop_0059cc30);
    audio_mixer_constructors_006b16bc[2]=address(&audio_mixer_construct_pcm_stream_0059cb50);
    audio_mixer_object_sizes_006b1704[0]=0x1c;audio_mixer_object_sizes_006b1704[1]=0x20;audio_mixer_object_sizes_006b1704[2]=0x24;
}
void __cdecl audio_mixer_initialize_pcm8_table_0059c1b0(){
    for(I value=-128;value<=127;++value){
        float* output=audio_mixer_pcm8_lookup_006b00c0+(static_cast<U>(value)&255u);
        __asm {
            fild dword ptr value
            fmul audio_mixer_pcm8_scale_005b26b0
            mov eax,output
            fstp dword ptr [eax]
        }
    }
}
void __cdecl audio_ds_mixer_initialize_00598230(const AudioMixerConfig462* config){
    audio_mixer_rate_006b16a0=config->rate;
    std::memcpy(&audio_release_format_006b16a4,&config->bits,4); // Includes material opaque byte+7.
    audio_mixer_stopped_hook_006b16a8=address(config->callback);
    auto& state=audio_release_storage_006b174c;
    for(U i=0;i<2;++i){
        state.raw[i]=application_audio_backend_allocate_0058aae0(0x2420);
        state.aligned[i]=state.raw[i]+8;
        while(state.aligned[i]&63u)state.aligned[i]+=4;
    }
    if((audio_release_format_006b16a4&0x00ff0000u)!=0)state.optional=application_audio_backend_allocate_0058aae0(0x400);
    for(U lane=0;lane<lanes();++lane){
        const U raw=application_audio_backend_allocate_0058aae0(0x440);
        state.channel_raw[lane]=raw;state.channel_aligned[lane]=raw;
        while(state.channel_aligned[lane]&63u)state.channel_aligned[lane]+=4;
    }
    const U allocation=application_audio_backend_allocate_0058aae0((audio_release_format_006b16a4&255u)*0x50u);
    state.table=allocation;
    const U bytes=(audio_release_format_006b16a4&255u)*0x50u;
    for(U offset=0;offset<bytes;offset+=4)store(allocation+offset,0);
    audio_mixer_register_pcm8_0059b9a0();audio_mixer_register_pcm16_0059b960();audio_mixer_register_nibble_0059b910();audio_mixer_register_adpcm_0059b8a0();
    audio_mixer_constructors_006b16bc[14]=address(&audio_mixer_construct_resampler_0059b830);
    audio_mixer_object_sizes_006b1704[14]=0x370;
    audio_mixer_select_kernels_00598460();
    for(U lane=0;lane<lanes();++lane){
        state.channel_word[lane]=0;
        const U object=reinterpret_cast<U>(state.opaque_006b17a0)+lane*12;
        audio_mixer_initialize_output_0059a3d0(object);
        const std::uint16_t zero=0;std::memcpy(reinterpret_cast<void*>(object+8),&zero,2);
        audio_mixer_insert_node_00596cd0(&state.channel_word[lane],object);
        for(U offset=0;offset<0x400;offset+=4)store(state.channel_aligned[lane]+offset,0);
    }
}
}
