#pragma once

#include "porsche/startup_sequence.hpp"
#include "porsche/render_startup.hpp"
#include "../572-startup-service-lifecycle/startup_lifecycle_572.hpp"

namespace porsche {

// Original 00468100..00468107 (8 bytes, Porsche.exe
// ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39).
// Reads [ECX + 0x74] into ECX and tail-jumps to 00536050.
void __fastcall render_display_transfer_end_00468100(void*, void*);

} // namespace porsche
