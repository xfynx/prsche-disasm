#pragma once
#include "porsche/application_audio_device.hpp"
#include "porsche/frame_services.hpp"
#include "../435-audio-stop-voice/audio_stop_435.hpp"
#include "../452-audio-record-resources/audio_record_resources_452.hpp"
#include "../455-audio-device-lifecycle/audio_device_lifecycle_455.hpp"
#include "../460-audio-thread-worker/audio_thread_worker_460.hpp"
#include "../462-audio-directsound-initialize/audio_directsound_state_462.hpp"
#include "../380-pixel-helpers/pixel_helpers.hpp"
namespace porsche {
extern std::uint8_t audio_period_sparse_006b4887[1];
extern std::uint8_t audio_period_sparse_006b4a44[10];
extern std::uint8_t audio_period_sparse_006b4a50[14];
extern std::uint8_t audio_period_sparse_006b4a60[14];
extern std::uint8_t audio_period_sparse_006b4a70[14];
extern std::uint8_t audio_period_sparse_006b4a80[14];
extern std::uint8_t audio_period_sparse_006b4a90[14];
extern std::uint8_t audio_period_sparse_006b4aa0[14];
extern std::uint8_t audio_period_sparse_006b4ab0[14];
extern std::uint8_t audio_period_sparse_006b4ac0[14];
extern std::uint8_t audio_period_sparse_006b4ad0[14];
extern std::uint8_t audio_period_sparse_006b4ae0[14];
extern std::uint8_t audio_period_sparse_006b4af0[14];
extern std::uint8_t audio_period_sparse_006b4b00[14];
extern std::uint8_t audio_period_sparse_006b4b10[14];
extern volatile std::uint8_t* const audio_period_value_views_558[32];
extern volatile std::uint8_t* const audio_period_byte4_views_558[32];
extern volatile std::uint8_t* const audio_period_byte5_views_558[32];
extern volatile std::uint8_t* const audio_period_arg4_views_558[32];
extern volatile std::uint8_t* const audio_period_arg5_views_558[32];
extern volatile std::uint8_t* const audio_period_notify_views_558[32];
// Genuine unresolved algorithm providers, never fixture stubs in game.
void __cdecl audio_period_callback_005901b0(std::int32_t,std::uint32_t);
std::int32_t __cdecl audio_period_channel_notify_005902a0(std::uint32_t,std::uint32_t,std::int32_t);
std::int32_t __cdecl audio_period_callback_set_00590250(std::uint32_t);
std::int32_t __cdecl audio_period_value_accept_00590290(std::uint32_t,std::uint32_t);
}
