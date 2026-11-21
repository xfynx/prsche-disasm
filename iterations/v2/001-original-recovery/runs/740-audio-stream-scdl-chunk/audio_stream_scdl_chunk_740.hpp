// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/file_device.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.hpp"
#include "../733-audio-stream-service-tick/audio_stream_service_tick_733.hpp"

namespace porsche {

// Recovered functions (3 bodies, 910 code bytes total; 00567060 matches audio_stream_service_tick_733.hpp).
std::int32_t __cdecl audio_stream_slot_push_chunk_005615c0(
    std::uint32_t index,
    const void* items);
std::uint32_t __cdecl audio_stream_deinterleave_chunk_00566b40(
    void* data,
    std::uint32_t chunk_len,
    std::uint32_t channels,
    std::uint32_t codec_mode);
std::int32_t __cdecl audio_stream_service_chunk_scdl_00567060(
    void* stream,
    void* chunk);

} // namespace porsche
