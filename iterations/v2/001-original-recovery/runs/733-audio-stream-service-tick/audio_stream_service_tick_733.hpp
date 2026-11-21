// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/network_lifecycle.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../565-audio-stream-codec-lifecycle/audio_codec_access_565.hpp"
#include "../629-audio-stream-codec-create/audio_stream_codec_create_629.hpp"
#include "../641-audio-stream-codec-leaves/audio_stream_codec_leaves_641.hpp"
#include "../653-audio-stream-codec-release/audio_stream_codec_release_653.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056c740 and 0056c790 (79 bytes total).
extern const char stream_err_gettable_invalid_handle_005bde44[41];
extern const char stream_err_state_invalid_handle_005bde70[38];

// Canonical Run667 provider reused by 005616d0 (declared identically to audio_service_callback_667.hpp).
std::uint32_t __cdecl audio_stream_slot_total_005616b0(std::uint32_t index);

// Recovered functions (11 bodies, 994 code bytes total; 00567270 is also declared in audio_stream_creation_561.hpp).
std::int32_t __cdecl audio_stream_slot_free_chunks_00561680(std::uint32_t index);
std::int32_t __cdecl audio_stream_slot_locked_total_005616d0(std::uint32_t index);
std::int32_t __cdecl audio_stream_service_chunk_sccl_00567020(void* stream, void* chunk);
std::int32_t __cdecl audio_stream_service_chunk_scel_00567140(void* stream, void* chunk);
std::int32_t __cdecl audio_stream_service_handle_chunk_00567170(
    std::uint32_t slot_index,
    void* chunk);
std::int32_t __cdecl audio_stream_service_check_refill_005671f0(void* stream);
void __cdecl audio_stream_service_tick_00567270();
std::uint32_t __cdecl audio_stream_codec_avail_0056c740(std::uint32_t codec_handle);
std::uint32_t __cdecl audio_stream_codec_state_0056c790(std::uint32_t codec_handle);
std::int32_t __cdecl audio_backend_channel_apply_00590e70(
    std::uint32_t handle,
    const void* params);
std::uint32_t __cdecl audio_voice_noop_00599710(
    std::uint32_t voice_slot,
    const void* params);

// Unrecovered child algorithms called by 00567270 and 00567170; typed boundaries only.
std::int32_t __cdecl audio_stream_voice_start_005612a0(
    std::uint32_t slot_index,
    void* header,
    void* params,
    void* descriptor);
std::int32_t __cdecl audio_stream_service_chunk_schl_00566ea0(
    std::uint32_t slot_index,
    void* chunk);
std::int32_t __cdecl audio_stream_service_chunk_scdl_00567060(
    void* stream,
    void* chunk);

} // namespace porsche
