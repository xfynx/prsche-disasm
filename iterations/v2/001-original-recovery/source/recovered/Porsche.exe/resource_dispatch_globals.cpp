#include "porsche/resource_leaf.hpp"

#include <cstdint>

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// scripts/research/inspect-pe-range.py --binary Porsche.exe --address
// 0x005df770 --size 4 --words reads file-backed bytes 64 00 00 00 in the
// original PE. Preserve that initialized DWORD rather than treating it as BSS.
std::uint32_t resource_leaf_group_005df770 = 0x00000064;

} // namespace porsche
