// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run711: previously-unowned typed children of the integrated Run706/Run707
// callers. The exported symbols are the exact extern names/signatures declared
// by those accepted callers; no owned cell or accepted caller is redefined.
#pragma once

#include <cstdint>

namespace porsche {

// runs/706-scene-child-ctor-and-slot-binding/scene_children_706.cpp:
// __fastcall(self in ECX, unused_edx in EDX, uint zero on stack; RET 4).
void __fastcall scene_root_finish_0044fc30(void* self, void* unused_edx,
                                           std::uint32_t zero);

// runs/707-view-teardown-child-leaves/view_teardown_child_leaves_707.hpp:
// __fastcall(self in ECX; RET 0) tail-target of teardown_secondary_destroy_0059f1c0.
void __fastcall secondary_destroy_body_0053f120(void* self);

} // namespace porsche
