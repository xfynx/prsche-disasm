// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original 00569a70..00569a8b (28B, __cdecl, ret 0; returns first empty heap slot 3..16 in EAX).
std::uint32_t __cdecl application_heap_slot_00569a70();

} // namespace porsche
