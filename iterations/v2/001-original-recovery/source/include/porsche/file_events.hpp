#pragma once
#include "porsche/file_wait.hpp"
namespace porsche {
extern std::uint32_t timer_rate_005deb48;
void* __stdcall platform_create_event(void*,std::int32_t,std::int32_t,const char*);
std::uint32_t __stdcall platform_set_event(void*);
std::uint32_t __stdcall platform_reset_event(void*);
std::uint32_t __stdcall platform_wait_events(std::uint32_t,void* const*,std::int32_t,std::uint32_t,std::int32_t);
std::uint32_t __stdcall platform_close_handle(void*);
std::uint32_t __stdcall platform_last_error();
std::uint32_t __stdcall platform_sleep(std::uint32_t,std::int32_t);
std::uint32_t __cdecl file_try_event_0055fb40(void*);
void* __cdecl file_wait_many_0055fb60(std::uint32_t,void* const*,std::uint32_t);
std::uint32_t __cdecl file_timed_event_0055fbb0(void*,std::uint32_t);
void* __cdecl file_wait_many_infinite_0055fbf0(std::uint32_t,void* const*);
std::uint32_t __cdecl file_close_event_0055fc10(void*);
std::uint32_t __cdecl file_signal_close_0055fc80(void*);
}
