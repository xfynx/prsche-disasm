#pragma once
#include "../485-network-callback-lifecycle/network_callback_lifecycle_485.hpp"
#include <cstdint>
namespace porsche {
extern std::uint32_t network_callbacks_pending_006a5b2c;
using NetworkCallbackVisit488=std::uint32_t (__cdecl*)(void*,std::uint32_t);
void __cdecl network_callbacks_stop_00560380();
void __cdecl network_callbacks_drain_005603b0();
std::uint32_t __cdecl network_callback_dispatch_00560490(void*);
void __cdecl network_callback_queue_release_00586e40(void*);
void __cdecl network_callback_poll_005602f0();
std::uint32_t __cdecl network_callback_visit_00560310(void*,std::uint32_t);
std::uint32_t __cdecl network_callback_enumerate_locked_00580e60(IoList*,NetworkCallbackVisit488,std::uint32_t);
std::uint32_t __cdecl network_callback_enumerate_00580dc0(IoList*,NetworkCallbackVisit488,std::uint32_t);
}
