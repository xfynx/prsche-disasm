// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run706 typed children of the integrated Run704 scene bodies. Exported symbols
// match the accepted caller declarations in runs/700, 701 and 702 exactly; no
// owned cell is redefined here.
#pragma once

#include <cstdint>

namespace porsche {

// ---- Exact accepted-caller externs (signatures must not change) --------------
// runs/700-scene-reset-leaf-chain/scene_stage_reset_700.hpp
void* __fastcall scene_stage_58b80_ctor_00458c90(void* self, void* unused_edx);
// runs/702-entry-fe-scene-route-transfer-leaves/entry_fe_scene_leaves_702.hpp
std::uint32_t __fastcall scene_elem_kind_00469b50(void* object, void* unused_edx);
void* __fastcall scene_root_constructor_0044fb40(void* self, void* unused_edx,
                                                 void* root);
void* __cdecl scene_slot_object_004211d0(std::uint32_t size, std::uint32_t zero);
void* __fastcall scene_stage_constructor_004522b0(void* self, void* unused_edx);
void __cdecl scene_route_dispatch_00475c80(std::uint32_t value);

// Read-only RTTI data cells: typed extern data, never constructed here.
extern const std::uint8_t rtti_scene_elem_005cf908[8u];
extern const std::uint8_t rtti_camera_elem_005cf928[8u];

} // namespace porsche
