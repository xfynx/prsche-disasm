#pragma once

#include <cstdint>

namespace porsche {

// Complete path predicate at 0059dd00; its file/device effects stay behind
// the original typed boundaries declared below and in files.hpp.
std::int32_t __cdecl resource_predicate_0059dd00(const char* path);

// Unrecovered resource-device path used only while file roots are disabled.
std::int32_t __cdecl resource_predicate_unrooted_00561ba0(const char* path);

} // namespace porsche
