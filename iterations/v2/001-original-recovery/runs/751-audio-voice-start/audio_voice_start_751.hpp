#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"

namespace porsche {

// Existing canonical owners: Run501, Run434, Run719, Run608, Run610 and Run439.
extern std::uint32_t audio_stream_slots_006b7cc0[16];
extern std::uint32_t& audio_backend_channels_006b4a00;
void __cdecl audio_backend_lock_005896d0();
void __cdecl audio_backend_unlock_005896f0();
std::uint32_t __cdecl audio_group_step_0058a970(std::uint32_t* out, const void* record);
void __cdecl audio_voice_recompute_gain_00589df0(std::uint32_t voice_slot);
void __cdecl audio_voice_recompute_send_00589d70(std::uint32_t bus, std::uint32_t voice_slot);
void __cdecl audio_backend_voice_finalize_00589c00(std::uint32_t voice_slot);

// Complete original 00561180..005611c3.
std::int32_t __cdecl audio_voice_loudest_channel_00561180(
    std::uint32_t voice_slot,
    std::int32_t channel_count);

// Typed backend boundaries proved from the original call sites. Their bodies
// remain outside Run751.
void __cdecl audio_backend_candidate_range_0058a4b0(
    std::uint32_t candidate,
    std::uint32_t* first,
    std::uint32_t* last);
std::int32_t __cdecl audio_backend_allocate_voice_005898f0(
    std::int32_t channel_count,
    std::uint32_t priority,
    std::uint32_t* handle,
    std::uint32_t first,
    std::uint32_t last);
void __cdecl audio_voice_recompute_pitch_00589f40(std::uint32_t voice_slot);
std::int32_t __cdecl audio_voice_backend_start_005897c0(
    std::uint32_t stream_slot,
    std::uint32_t voice_slot,
    std::uint32_t candidate,
    std::uint32_t descriptor_0e,
    std::uint32_t descriptor_12,
    std::uint32_t descriptor_14,
    const void* header,
    const void* params_0c,
    const void* params_14);

// Complete original 005612a0..005615b6.
std::int32_t __cdecl audio_stream_voice_start_005612a0(
    std::uint32_t stream_slot,
    const void* header,
    const void* params,
    const void* descriptor);

} // namespace porsche
