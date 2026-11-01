#pragma once
#include "porsche/files.hpp"
#include "porsche/network_lifecycle.hpp"
#include <cstdint>
namespace porsche {
extern std::uint32_t network_callbacks_initialized_006a5b28;
extern IoList network_callbacks_list_006b7d00;
extern IoList network_callbacks_list_006b7d20;
extern std::uint8_t& network_lifecycle_callback_count_006b49a0;
void __cdecl network_callbacks_start_00560340();
// Original address-taken38B callback. Its drain/resource graph remains open;
// this exact native function pointer is transported, never raw guest VA560380.
void __cdecl network_callbacks_stop_00560380();
}
