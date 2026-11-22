// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../733-audio-stream-service-tick/audio_stream_service_tick_733.hpp"
#include "../744-audio-stream-header-parse/audio_stream_header_parse_744.hpp"

namespace porsche {

// Original 00566ea0..00567011, 370 bytes.
std::int32_t __cdecl audio_stream_service_chunk_schl_00566ea0(
    std::uint32_t slot_index,
    void* chunk);

} // namespace porsche
