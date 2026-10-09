#pragma once

#include "porsche/heap.hpp"
#include <cstdint>

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Neutral source names for three BSS DWORDs referenced by 0056a490 only.
// 006af114 is pointer-shaped at the original free call; no further semantics
// are assigned to the adjacent words at 006af118 and 006af11c.
extern void* startup_service_pointer_006af114;
extern std::uint32_t startup_service_word_006af118;
extern std::uint32_t startup_service_word_006af11c;

// 0056a490: no-argument release/reset routine; the original caller is 004b67b0.
void __cdecl startup_service_release_0056a490();

}
