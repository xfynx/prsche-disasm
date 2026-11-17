// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_context_base.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/context_services.hpp"
#include "porsche/render_objects.hpp"
#include "porsche/render_startup.hpp"

namespace porsche {

// Original entry 0044b1d0..0044b246 (119 bytes, __fastcall ECX=self, stack args flag_ptr, unused_arg, RET 8).
void* __fastcall render_display_tree_ctor_0044b1d0(
    void* self, void* unused_edx, const std::uint8_t* flag_ptr, const void* unused_arg);

// Original entry 00466380..004664f3 (372 bytes, __fastcall ECX=self, RET 0).
void* __fastcall render_display_member_raw_00466380(void* self, void* unused_edx);

// render_display_member_00466380(void* member) is declared in porsche/render_objects.hpp.

} // namespace porsche
