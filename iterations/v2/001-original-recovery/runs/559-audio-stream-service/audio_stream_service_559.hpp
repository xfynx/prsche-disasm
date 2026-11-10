#pragma once
#include "../556-application-audio-lifecycle/application_audio_lifecycle_556.hpp"
#include "../508-audio-stream-producer-lifecycle/audio_stream_producer_lifecycle_508.hpp"
namespace porsche {
std::uint32_t __cdecl audio_stream_record_bytes_005611d0(std::uint32_t);
std::uint32_t __cdecl audio_stream_storage_bytes_005611e0(std::uint32_t);
std::uint32_t __cdecl audio_stream_service_bytes_005678a0(std::uint32_t,std::uint32_t);
std::uint32_t __cdecl audio_stream_codec_bytes_0056afc0(std::uint32_t,std::uint32_t,std::uint32_t);
// Original five-argument begin forwards all five plus two explicit zero words.
// The seven-argument creator remains a real unresolved algorithm/provider.
std::int32_t __cdecl application_audio_stream_create_005673d0(std::uint8_t*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
}
