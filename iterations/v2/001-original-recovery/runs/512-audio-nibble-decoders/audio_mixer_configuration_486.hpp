#pragma once
#include "../462-audio-directsound-initialize/audio_directsound_initialize_462.hpp"
#include "../473-audio-sample-dispatch/audio_sample_dispatch_473.hpp"
#include "../479-audio-mixer-ramp-stop/audio_mixer_ramp_stop_479.hpp"
namespace porsche {
extern std::uint32_t audio_mixer_rate_006b16a0;
extern std::uint32_t audio_mixer_constructors_006b16bc[15];
extern std::uint32_t audio_mixer_object_sizes_006b1704[15];
extern std::uint32_t audio_mixer_decode_s16_006b17d8;
extern float audio_mixer_pcm8_lookup_006b00c0[256];
extern float audio_mixer_nibble_lookup_006b04c0[208];
extern const float audio_mixer_pcm8_scale_005b26b0;
void __cdecl audio_mixer_insert_node_00596cd0(std::uint32_t* head,std::uint32_t node);
void __cdecl audio_mixer_select_kernels_00598460();
void __cdecl audio_mixer_initialize_output_0059a3d0(std::uint32_t object);
void __cdecl audio_mixer_register_adpcm_0059b8a0();
void __cdecl audio_mixer_initialize_nibble_table_0059b8d0();
void __cdecl audio_mixer_register_nibble_0059b910();
void __cdecl audio_mixer_register_pcm16_0059b960();
void __cdecl audio_mixer_register_pcm8_0059b9a0();
void __cdecl audio_mixer_initialize_pcm8_table_0059c1b0();

// Actual5984d0/59a3e0 consumers push mutable parameter block then object,
// clean8 bytes and ignore return. These genuine constructor bodies remain open.
void __cdecl audio_mixer_construct_pcm_00597c10(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_pcm_loop_0059cc30(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_pcm_stream_0059cb50(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_nibble_00597dc0(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_nibble_loop_0059c9f0(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_nibble_stream_0059c610(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_adpcm_00597f20(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_adpcm_stream_0059c360(std::uint32_t,std::uint32_t*);
void __cdecl audio_mixer_construct_resampler_0059b830(std::uint32_t,std::uint32_t*);
// Actual475/479 consumers transport raw FLOAT32 factor bits as cdecl4.
void __cdecl audio_mixer_accumulate_scalar_0059ba70(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl audio_mixer_accumulate_x87_0059baf0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl audio_mixer_accumulate_3dnow_0059bc40(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
// Actual597b96/597bd4 consumers: cdecl3(count,S16 source,F32 destination).
void __cdecl audio_mixer_decode_s16_x87_0059b9f0(std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl audio_mixer_decode_s16_3dnow_0059bb90(std::uint32_t,std::uint32_t,std::uint32_t);
// Actual475 final-chain consumer supplies cdecl5; the original ignores arg5.
std::int32_t __cdecl audio_mixer_output_pcm16_0059a350(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
}
