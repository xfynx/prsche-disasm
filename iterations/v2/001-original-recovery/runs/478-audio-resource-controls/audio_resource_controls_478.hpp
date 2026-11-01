#pragma once
#include <cstdint>
namespace porsche {
// Physical adjacent original cells 00656aa8/00656aac. The gap at ab0 is unowned.
extern void* audio_channel_banks_00656aa8[2];
extern std::uint32_t audio_resource_query_root_00656ab4;
void __cdecl frame_services_boundary_004ad510();
std::uint32_t __cdecl splash_progress_resource_begin_004ad670();
std::uint32_t __cdecl splash_progress_resource_end_004ad6c0();
std::int32_t __cdecl audio_channel_stop_00565d60(std::uint32_t);
}
