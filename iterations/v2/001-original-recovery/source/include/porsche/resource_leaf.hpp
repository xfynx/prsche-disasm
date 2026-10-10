#pragma once

#include <cstdint>

namespace porsche {

// Global argument consumed by the original FILESYS atomic dispatcher.
extern std::uint32_t resource_leaf_group_005df770;

using ResourceLeafAtomicCallback = std::int32_t (__cdecl*)(
    std::uint32_t group, void* context);

// Unrecovered boundaries. The production bindings must resolve these to the
// original filesystem route/dispatcher/callback implementations.
std::int32_t __cdecl resource_leaf_atomic_dispatch_00568d50(
    ResourceLeafAtomicCallback callback, std::uint32_t device,
    std::uint32_t group, void* context);
std::int32_t __cdecl resource_leaf_callback_00561be0(
    std::uint32_t group, void* context);

std::int32_t __cdecl resource_leaf_00561ba0(const char* path);

} // namespace porsche
