// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run827: typed scene/camera RTTI descriptors and hierarchy records:
//   005cf908 ( 25B .data payload)  rtti_scene_elem_desc_005cf908  (".?AVCSceneElem@@")
//   005cf928 ( 26B .data payload)  rtti_camera_elem_desc_005cf928 (".?AVCCameraElem@@")
//   005c4a10 / 005c4940 (148B .rdata COL/CHD/BCD graphs)
#pragma once

#include "porsche/rtti.hpp"

namespace porsche {

// Typed mutable RTTI TypeDescriptors corresponding to original VAs 0x005cf908 and 0x005cf928.
// bindings.cmake aliases ?rtti_scene_elem_005cf908@porsche@@3QBEB and
// ?rtti_camera_elem_005cf928@porsche@@3QBEB (declared in 702/706) to these symbols.
extern RttiTypeDescriptor<17> rtti_scene_elem_desc_005cf908;
extern RttiTypeDescriptor<18> rtti_camera_elem_desc_005cf928;

// CompleteObjectLocators at original .rdata VAs 0x005c4a10 (CSceneElem) and 0x005c4940 (CCameraElem).
extern const RttiCompleteObjectLocator rtti_scene_elem_locator_005c4a10;
extern const RttiCompleteObjectLocator rtti_camera_elem_locator_005c4940;

} // namespace porsche
