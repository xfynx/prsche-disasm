// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"
#include "../641-audio-stream-codec-leaves/audio_stream_codec_leaves_641.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056baf0 and 0056be40 (143 bytes total).
extern const char stream_err_unable_to_read_005bdc70[39];
extern const char stream_err_invalid_chunk_005bdc98[66];
extern const char stream_err_abort_tap_005bdcdc[38];

// Recovered functions.
void __cdecl audio_stream_codec_refill_0056baf0(
    void* codec,
    std::uint32_t offset);
void __cdecl audio_stream_codec_read_done_0056bd70(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec);
std::int32_t __cdecl audio_stream_codec_process_ring_0056be40(void* codec);
std::int32_t __cdecl audio_stream_codec_match_tap_0056c000(
    const void* codec,
    const std::uint32_t* chunk_header);

// Unrecovered child called by 0056bd70 at 0056bde5 and 0056be25.
void __cdecl audio_stream_codec_advance_0056b860(
    void* codec,
    std::uint32_t offset);

} // namespace porsche
