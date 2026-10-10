#pragma once

#include "porsche/resource_leaf.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {

struct ResourceAtomicContext {
    const char* path;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
    std::uint32_t callback_diagnostic_flag;
};
static_assert(offsetof(ResourceAtomicContext, path) == 0x00);
static_assert(offsetof(ResourceAtomicContext, callback_diagnostic_flag) == 0x0c);
static_assert(sizeof(ResourceAtomicContext) == 0x10);

} // namespace porsche
