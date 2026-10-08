#include "porsche/file_events.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original initial data word at 005deb48 is zero; source consumers default to 100.
std::uint32_t timer_rate_005deb48=0;
// 0055fb20/0055fc20: manual-reset selection, initially not signaled, no name/security.
void* __cdecl file_auto_event_0055fb20(){return platform_create_event(nullptr,0,0,nullptr);}
void* __cdecl file_manual_event_0055fc20(){return platform_create_event(nullptr,1,0,nullptr);}
std::uint32_t __cdecl file_event_signal_0055fb30(void* event){return platform_set_event(event);}
std::uint32_t __cdecl file_worker_signal_0055fc30(void* event){return platform_set_event(event);}
std::uint32_t __cdecl file_reset_event_0055fc40(void* event){return platform_reset_event(event);}
std::uint32_t __cdecl file_close_event_0055fc10(void* event){return platform_close_handle(event);}
std::uint32_t __cdecl file_signal_close_0055fc80(void* event){platform_set_event(event);return platform_close_handle(event);}
std::uint32_t __cdecl file_last_error_0055fce0(){return platform_last_error();}
std::uint32_t __cdecl file_sleep_0055f740(std::uint32_t milliseconds){return platform_sleep(milliseconds,1);}
// 0055fb60: Win32 wait-any, non-alertable; signed range check of returned index.
void* __cdecl file_wait_many_0055fb60(std::uint32_t count,void* const* handles,std::uint32_t timeout){
    const auto result=platform_wait_events(count,handles,0,timeout,0);
    const auto index=static_cast<std::int32_t>(result);
    if(index>=0 && index<static_cast<std::int32_t>(count))return handles[result];
    return nullptr;
}
void* __cdecl file_worker_wait_0055fb90(void* event){return file_wait_many_0055fb60(1,&event,0xffffffffu);}
void* __cdecl file_wait_event_0055fc60(void* event){return file_wait_many_0055fb60(1,&event,0xffffffffu);}
std::uint32_t __cdecl file_try_event_0055fb40(void* event){return file_wait_many_0055fb60(1,&event,0)==event ? 1u : 0u;}
// 0055fbb0: LEA/SHL low-word multiply by 1000, signed IDIV, no clamping.
std::uint32_t __cdecl file_timed_event_0055fbb0(void* event,std::uint32_t ticks){
    const auto rate=static_cast<std::int32_t>(timer_rate_005deb48 ? timer_rate_005deb48 : 100u);
    const auto numerator=static_cast<std::int32_t>(ticks*1000u);
    const auto timeout=static_cast<std::uint32_t>(numerator/rate);
    return file_wait_many_0055fb60(1,&event,timeout)==event ? 1u : 0u;
}
void* __cdecl file_wait_many_infinite_0055fbf0(std::uint32_t count,void* const* handles){return file_wait_many_0055fb60(count,handles,0xffffffffu);}
}
