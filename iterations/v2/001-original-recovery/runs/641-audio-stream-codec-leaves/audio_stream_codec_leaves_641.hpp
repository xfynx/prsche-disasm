// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../565-audio-stream-codec-lifecycle/audio_codec_access_565.hpp"
#include "../568-audio-greedy-transition/audio_greedy_transition_568.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"

namespace porsche {

// Read-only .rdata string owned by 0056c540 (36 bytes including NUL).
extern const char stream_err_get_invalid_handle_005bdd88[36];

std::uint32_t __cdecl audio_stream_ring_contains_0056bce0(
    std::uint32_t start,
    std::uint32_t end,
    std::uint32_t ptr);
void __cdecl audio_stream_request_unlink_0056bd10(
    std::uint32_t stream,
    std::uint32_t node);
void __cdecl audio_stream_consume_bytes_0056c380(
    std::uint32_t stream,
    std::uint32_t delta);
std::uint32_t __cdecl audio_stream_request_lookup_0056c3e0(
    std::uint32_t stream,
    std::uint32_t req_id);
std::uint32_t __cdecl audio_stream_get_0056c540(std::uint32_t handle);

} // namespace porsche
