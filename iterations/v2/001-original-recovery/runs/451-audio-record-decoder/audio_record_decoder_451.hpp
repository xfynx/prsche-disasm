#pragma once
#include <cstdint>
namespace porsche {
extern const std::uint32_t audio_record_default_005e3498[2];
std::int32_t __cdecl audio_integer_read_0059bd90(const void* bytes,std::uint32_t count);
std::int32_t __cdecl audio_token_read_00599760(void* state);
std::int32_t __cdecl audio_group_decode_00599100(std::uint32_t* cursor,void* record);
}
