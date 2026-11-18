// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/formatter_text.hpp"
#include "porsche/frame_services.hpp"
#include "porsche/object_update.hpp"
#include "porsche/window_worker.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.hpp"
#include "../556-application-audio-lifecycle/application_audio_lifecycle_556.hpp"
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../607-frame-audio-stream-ramp/frame_audio_stream_ramp_607.hpp"
#include "../637-audio-stream-channel-status/audio_stream_channel_status_637.hpp"
#include "../638-render-seed-prng/render_seed_prng_638.hpp"

namespace porsche {

// Owned .data tag strings uniquely referenced by 004ad9c0 (13 bytes total).
extern const char audio_service_tag_vic_005d1bd4[4];
extern const char audio_service_tag_win_005d1bd8[4];
extern const char audio_service_tag_lose_005d1bdc[5];

// Canonical Run564 audio resource/stream declarations matching audio_callback_resource_564.cpp.
void __cdecl audio_service_play_004ad8b0();
std::uint32_t __cdecl audio_resource_locate_005666f0(
    std::uint32_t source, std::uint32_t name, std::uint32_t index,
    std::uint32_t out1, std::uint32_t out2);
std::int32_t __cdecl audio_service_stream_start_00567720(
    std::uint32_t channel, std::uint32_t mode,
    std::uint32_t data, std::uint32_t size);

// Recovered functions (1902 code bytes total).
std::uint64_t __cdecl audio_u32_mul64_00590d80(std::uint32_t lhs, std::uint32_t rhs);
std::uint32_t __cdecl audio_u64_div32_00590df0(
    std::uint32_t lo, std::uint32_t hi, std::uint32_t divisor);
std::uint32_t __cdecl audio_service_stream_lookup_00590e20(std::int32_t stream_handle);
std::uint32_t __cdecl audio_stream_slot_total_005616b0(std::uint32_t index);
std::int32_t __cdecl audio_service_slot_info_00566a40(
    std::int32_t slot, std::uint32_t* out_info);
std::int32_t __cdecl audio_service_stream_info_00566910(
    std::int32_t stream_handle, std::uint32_t* out_info);
void __cdecl audio_service_split_004ad950(void* object);

// Canonical application_audio_service_callback_004ad9c0 is declared in
// ../556-application-audio-lifecycle/application_audio_lifecycle_556.hpp.

} // namespace porsche
