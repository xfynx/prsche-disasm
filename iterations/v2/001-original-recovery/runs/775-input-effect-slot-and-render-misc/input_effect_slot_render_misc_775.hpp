// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../680-input-ff-slot-and-render-leaves/input_ff_slot_render_680.hpp"
#include "../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp"
#include "../701-view-teardown-route-family/view_teardown_route_family_701.hpp"
#include "../742-scene-stage-group-ctor/scene_stage_group_742.hpp"
#include "../752-input-effect-cleanup/input_effect_cleanup_752.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/input_state.hpp"
#include "porsche/render_startup.hpp"

namespace porsche {

// Original 005331a0..005331eb (76B, __cdecl, ret 0; void).
// Declared in ../752-input-effect-cleanup/input_effect_cleanup_752.hpp.
void __cdecl input_slot_effect_cleanup_005331a0(std::int32_t slot_index);

// Original 00465df0..00465e15 (38B, __cdecl, ret 0; void).
// Declared in porsche/render_startup.hpp.
void __cdecl render_misc_00465df0();

} // namespace porsche
