#pragma once
#include <cstdint>
namespace porsche {
void* __fastcall render_driver_buffer_ctor_00537700(void* self,void*);
std::uint32_t __fastcall render_driver_buffer_apply_00537760(void* self,void*);
std::uint32_t __cdecl render_buffer_state_00540480(std::uint32_t key,std::uint32_t value);
std::uint32_t __cdecl render_buffer_state_alias_005404e0(std::uint32_t key,std::uint32_t value);
// Actual fourteen-call flush algorithm, callback table and112B records deferred.
void __cdecl render_resource_flush_states_00535b00();
}
