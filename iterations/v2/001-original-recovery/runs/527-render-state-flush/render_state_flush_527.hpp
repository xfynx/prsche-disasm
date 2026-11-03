#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t render_state_flush_records_005de6bc[28];
extern std::uint32_t render_state_flush_callbacks_005de72c[7];
void __cdecl render_resource_flush_states_00535b00();
std::uint32_t __cdecl render_resource_option_state_00535a60(std::uint32_t key,std::uint32_t value);
// Full104B algorithm retains an unproved signed-stage physical-read domain.
std::uint32_t __cdecl render_resource_texture_state_00535a90(std::uint32_t key,std::uint32_t value);
}
