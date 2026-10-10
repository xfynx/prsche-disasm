#include "porsche/resource_leaf.hpp"

#include "porsche/files.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {
namespace {
struct ResourceLeafContext {
    const char* path;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
    std::uint32_t callback_diagnostic_flag;
};
static_assert(offsetof(ResourceLeafContext, path) == 0x00);
static_assert(offsetof(ResourceLeafContext, callback_diagnostic_flag) == 0x0c);
static_assert(sizeof(ResourceLeafContext) == 0x10);
} // namespace

std::int32_t __cdecl resource_leaf_00561ba0(const char* path) {
    ResourceLeafContext context;
    context.path = path;
    // Original initializes local +0x0c to one; bytes +0x04/+0x08 remain
    // opaque stack values and are intentionally not invented here.
    context.callback_diagnostic_flag = 1;

    const std::uint32_t device = file_device_name_00568e90(path);
    return resource_leaf_atomic_dispatch_00568d50(
        resource_leaf_callback_00561be0, device,
        resource_leaf_group_005df770, &context);
}

} // namespace porsche
