#include "porsche/application_main.hpp"

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// These DWORDs lie in the zero-filled virtual tail of .data, beyond raw bytes.
// Original consumers: 004b6d8d/9f, 004b6ee8, 004b6f01/0c/1d/23.
// Names retain addresses: the storage evidence does not establish game meaning.
std::uint32_t global_00606a88 = 0;
std::uint32_t global_00606874 = 0;
std::uint32_t global_005e99f4 = 0;
} // namespace porsche
