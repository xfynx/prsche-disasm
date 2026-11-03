#pragma once
#include "../508-audio-stream-producer-lifecycle/audio_stream_producer_lifecycle_508.hpp"
#include <cstddef>
namespace porsche {
struct AudioStreamLimits513{std::uint32_t capacity,channels;};
struct AudioStreamCursor513{std::uint32_t cursor,stride,queued,format;};
struct AudioStreamCapture513{std::uint32_t object,buffer;};
static_assert(sizeof(AudioStreamLimits513)==8&&sizeof(AudioStreamCursor513)==16&&sizeof(AudioStreamCapture513)==8,"original narrow state spans");
static_assert(offsetof(AudioStreamCursor513,format)==12,"physical metadata aliases");
extern AudioStreamLimits513 audio_stream_limits_006b7ca4;
extern AudioStreamCursor513 audio_stream_cursor_006b7cb0;
extern AudioStreamCapture513 audio_stream_capture_006aefb8;
extern std::uint8_t audio_stream_backend_format_006b4862;
extern std::uint32_t audio_stream_backend_buffer_006b4864;
extern std::uint32_t audio_stream_encoded_scratch_006b17dc;
void __cdecl audio_stream_encoded_release_005977f0();
std::int32_t __cdecl audio_stream_capture_release_0058f530();
// Actual5619d5 cdecl1 destination, signed used length/error. Body remains open.
std::int32_t __cdecl audio_stream_capture_read_0058acf0(std::uint32_t destination);
}
