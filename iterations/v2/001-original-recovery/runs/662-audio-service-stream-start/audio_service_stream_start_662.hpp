// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../565-audio-stream-codec-lifecycle/audio_codec_access_565.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"
#include "../656-audio-stream-codec-refill/audio_stream_codec_refill_656.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056b690 and 0056c040 (83 bytes total).
extern const char stream_err_queuefile_invalid_005bdbd0[42];
extern const char stream_err_queuemem_invalid_005bdd04[41];

// Loader-zero .data BSS counter owned by 0056b790 (4 bytes).
extern std::uint32_t audio_stream_request_serial_006a5df0;

// Recovered functions (955 code bytes total).
void* __cdecl audio_stream_codec_alloc_request_0056b790(void* codec);
void __cdecl audio_stream_codec_enqueue_request_0056b800(void* codec, void* req);
std::uint32_t __cdecl audio_stream_codec_queue_file_0056b690(
    std::uint32_t codec_handle,
    const char* path,
    std::uint32_t offset,
    std::uint32_t tag);
std::uint32_t __cdecl audio_stream_codec_queue_memory_0056c040(
    std::uint32_t codec_handle,
    const void* data,
    std::uint32_t size,
    std::uint32_t tag);
std::int32_t __cdecl audio_service_stream_start_00567550(
    std::uint32_t channel_tag,
    std::uint32_t stream_flags,
    std::uint32_t arg2,
    std::uint32_t offset_or_size,
    std::uint32_t arg4);

} // namespace porsche
