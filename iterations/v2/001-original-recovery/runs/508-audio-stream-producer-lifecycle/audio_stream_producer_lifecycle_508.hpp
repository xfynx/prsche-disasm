#pragma once
#include "../505-audio-stream-buffer-delivery/audio_stream_buffer_delivery_505.hpp"
#include "porsche/network_lifecycle.hpp"
namespace porsche {
extern std::uint32_t audio_stream_output_buffer_006b7ca0;
std::int32_t __cdecl audio_stream_construct_00561200(std::uint32_t release,std::uint32_t consumed,std::uint32_t buffer,std::uint32_t bytes);
std::uint32_t __cdecl audio_stream_prefix_bytes_00589790();
std::int32_t __cdecl audio_stream_attach_005897a0(std::uint32_t index,std::uint32_t buffer);
void __cdecl audio_stream_detach_005897b0(std::uint32_t index);
void __cdecl audio_stream_cancel_range_00561720(std::uint32_t index,std::uint32_t begin,std::uint32_t end);
// Real unrecovered backend effect and registered cdecl0 callback, respectively.
void __cdecl audio_stream_backend_stop_0058ad60();
void __cdecl audio_stream_dispatch_005619b0();
}
