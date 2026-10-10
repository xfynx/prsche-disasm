#pragma once

#include <cstdint>

namespace porsche {

// Original BSS handle cell at 0069e5dc. The 0053c0f0 worker writes the
// event HANDLE here; 0053c15d clears it when that worker exits.
extern void* auxiliary_wait_event_0069e5dc;

// Porsche.exe 0053c270: signal the shared event if one has been published.
void __cdecl auxiliary_wait_signal_0053c270();

} // namespace porsche
