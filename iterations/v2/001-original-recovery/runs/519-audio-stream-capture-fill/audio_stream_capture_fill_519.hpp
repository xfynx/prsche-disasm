#pragma once
#include "../513-audio-stream-worker-stop/audio_stream_worker_stop_513.hpp"
namespace porsche {
struct AudioCaptureCounters519{std::uint32_t ring,chunk,produced,consumed,last,shift;};
static_assert(sizeof(AudioCaptureCounters519)==24&&offsetof(AudioCaptureCounters519,shift)==20,"original physical counters");
extern AudioCaptureCounters519 audio_capture_counters_006aefc0;
extern std::uint16_t audio_stream_capture_units_006b4860;
std::int32_t __cdecl audio_stream_capture_poll_0058f410(std::uint32_t destination);
std::uint32_t __cdecl audio_stream_copy_forward_00598a50(std::uint32_t destination,std::uint32_t source,std::uint32_t bytes);
void __cdecl audio_stream_transform_00597660(std::uint32_t input,std::uint32_t output);
}
