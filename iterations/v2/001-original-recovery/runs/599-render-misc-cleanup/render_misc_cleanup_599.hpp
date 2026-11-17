#pragma once

#include <cstdint>
#include "porsche/render_startup.hpp"

namespace porsche {

struct RenderCleanupNode_599 {
    RenderCleanupNode_599* next;
    std::uint32_t callback_va;
};
static_assert(sizeof(RenderCleanupNode_599) == 8, "original 8-byte cleanup node");

// Loader-zero .data objects at original VAs 0x00618e74..0x00618f73, 0x00619758, and 0x0069ebb0.
extern std::uint8_t render_identity_lut_00618e74[256];
extern std::uint8_t* render_identity_lut_ptr_00619758;
extern RenderCleanupNode_599* render_cleanup_head_0069ebb0;

// Original entry 0053f0b0..0053f112 (99 bytes).
void __cdecl render_cleanup_register_0053f0b0(std::uint32_t callback_va);

} // namespace porsche
