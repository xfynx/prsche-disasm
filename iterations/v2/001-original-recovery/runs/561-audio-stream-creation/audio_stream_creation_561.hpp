#pragma once
#include "../559-audio-stream-service/audio_stream_service_559.hpp"
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
namespace porsche {
struct AudioStreamServiceStorage561 {std::uint32_t slots[16];std::int8_t index_map[16];};
static_assert(sizeof(AudioStreamServiceStorage561)==80);
static_assert(offsetof(AudioStreamServiceStorage561,index_map)==64);
extern AudioStreamServiceStorage561 audio_stream_service_storage_006b7740;
using AudioStreamServiceCallback561=void(__cdecl*)();
std::int32_t __cdecl audio_stream_service_reset_00567740(std::uint32_t);
std::uint32_t __cdecl audio_stream_service_lookup_00566d60(std::int32_t);
std::uint32_t __cdecl audio_stream_service_count_005673b0();
std::uint32_t __cdecl audio_stream_service_shutdown_00566d40();
void __cdecl audio_stream_service_register_0058ff50(AudioStreamServiceCallback561);
void __cdecl audio_stream_service_unregister_0058ff70(AudioStreamServiceCallback561);
// Real unowned codec algorithms and callback bodies; no game fixture provider.
std::uint32_t __cdecl audio_stream_codec_create_0056aff0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl audio_stream_codec_frames_0056c840(std::uint32_t);
std::int32_t __cdecl audio_stream_codec_set_005912e0(std::uint32_t,std::int32_t);
void __cdecl audio_stream_codec_reset_0056c420(std::uint32_t);
void __cdecl audio_stream_codec_destroy_0056b3b0(std::uint32_t);
void __cdecl audio_stream_service_release_00566e10(std::uint32_t);
void __cdecl audio_stream_service_consumed_00566e40(std::uint32_t,std::uint32_t);
void __cdecl audio_stream_service_tick_00567270();
}
