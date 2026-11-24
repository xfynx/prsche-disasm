// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00569a70..00569a8b (28B, __cdecl, ret 0).
#include "heap_slot_815.hpp"

#include "porsche/heap.hpp"

namespace porsche {

std::uint32_t __cdecl application_heap_slot_00569a70() {
    for (std::uint32_t index = 3u; index < 16u; ++index) {
        if (heaps_006b4f20[index] == nullptr) {
            return index;
        }
    }
    return 16u;
}

} // namespace porsche
