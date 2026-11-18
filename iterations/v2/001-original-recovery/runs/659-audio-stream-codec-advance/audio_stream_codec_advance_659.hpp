// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"
#include "../656-audio-stream-codec-refill/audio_stream_codec_refill_656.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056b860, 0056ba20, and 0056ba80 (114 bytes total).
extern const char stream_err_unable_to_close_005bdbfc[40];
extern const char stream_err_unable_to_open_005bdc24[39];
extern const char stream_err_unable_to_open_file_005bdc4c[35];

// Recovered functions (audio_stream_codec_advance_0056b860 is canonically
// declared in ../656-audio-stream-codec-refill/audio_stream_codec_refill_656.hpp).
void __cdecl audio_stream_codec_open_done_0056ba20(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec);
void __cdecl audio_stream_codec_close_done_0056ba80(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec);

} // namespace porsche
