// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/fe_stream.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../565-audio-stream-codec-lifecycle/audio_codec_access_565.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"
#include "../641-audio-stream-codec-leaves/audio_stream_codec_leaves_641.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056b3b0, 0056c140, 0056c420, and 0056c620 (272 bytes total).
extern const char stream_err_destroy_invalid_handle_005bdaa0[40];
extern const char stream_err_cancelrequest_invalid_handle_005bdd30[46];
extern const char stream_err_kill_invalid_handle_005bdd60[37];
extern const char stream_err_release_wrong_stream_005bddac[60];
extern const char stream_err_release_already_released_005bdde8[50];
extern const char stream_err_release_invalid_handle_005bde1c[40];

// Recovered functions (00566e10, 0056b3b0, and 0056c420 are declared in audio_stream_creation_561.hpp).
void __cdecl audio_stream_codec_abort_node_0056c140(
    std::uint32_t codec_handle,
    std::uint32_t request_id);
void __cdecl audio_stream_codec_release_chunk_0056c620(
    std::uint32_t codec_handle,
    void* chunk_header);

// Unrecovered child called by 0056c620 at 0056c702 and 0056c711.
void __cdecl audio_stream_codec_refill_0056baf0(
    void* codec,
    std::uint32_t offset);

} // namespace porsche
