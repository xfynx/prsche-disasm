#pragma once

#include "porsche/file_threads.hpp"
#include "porsche/thread_wait.hpp"

#include <cstdint>

namespace porsche {

using AuxiliaryEventCallback = void (__cdecl*)();

// Exact BSS state accessed by the original 0053bfe0/0053c0f0/0053c1d0 code.
extern AuxiliaryEventCallback auxiliary_event_callbacks_0069e5b4[8];
extern void* auxiliary_event_lock_0069e5d4;
extern std::uint32_t auxiliary_event_stopping_0069e5d8;
extern ThreadRecord auxiliary_event_thread_006bd9c0;

// The event HANDLE at 0069e5dc is owned by Run122's auxiliary_wait module.

void __cdecl auxiliary_event_callback_add_0053bfe0(AuxiliaryEventCallback);
void __cdecl auxiliary_event_lifecycle_start_0053c060();
void __cdecl auxiliary_event_worker_0053c0f0();
void __cdecl auxiliary_event_lifecycle_stop_0053c170();
void __cdecl auxiliary_event_callback_remove_0053c1d0(AuxiliaryEventCallback);

} // namespace porsche
