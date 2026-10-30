#pragma once
#include "porsche/application_audio_device.hpp"
namespace porsche {
std::int32_t __cdecl application_audio_validate_channel_00590070(std::int32_t index);
std::int32_t __cdecl application_audio_release_group_00565990(std::int32_t index,std::uint32_t count);
std::int32_t __cdecl audio_group_release_item_00590000(std::int32_t group,std::int32_t item,std::uint32_t* scratch);
std::uint32_t __cdecl audio_group_select_00590170(std::uint32_t header,std::int32_t item);
std::int32_t __cdecl audio_group_release_resources_00590b50(std::uint32_t item,std::uint32_t* scratch);
// Original child bodies stay unresolved production dependencies, not substitutes.
std::int32_t __cdecl audio_group_decode_00599100(std::uint32_t* cursor,void* record);
void __cdecl audio_group_process_005996d0(void* record,std::uint32_t* scratch);
}
