#pragma once
#include "porsche/application_audio_lifecycle.hpp"
#include "porsche/application_services_next.hpp"
#include "porsche/window_scheduler.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
namespace porsche {
extern std::uint32_t application_audio_selected_channel_00655d30;
// Actual children remain real unresolved providers. No fixture enters the game.
std::uint32_t __cdecl application_audio_stream_estimate_005678c0(std::uint32_t,std::uint32_t);
std::int32_t __cdecl application_audio_stream_descriptor_00561960(std::uint8_t*);
std::int32_t __cdecl application_audio_stream_begin_00567660(std::uint8_t*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::int32_t __cdecl application_audio_stream_stop_00567690(std::uint32_t);
std::uint32_t __cdecl application_audio_service_callback_004ad9c0(std::uint32_t,std::uint32_t);
}
