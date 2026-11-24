// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run827: CSceneElem (005cf908, 005c4a10) and CCameraElem (005cf928, 005c4940) RTTI graphs.
#include "scene_rtti_descriptors_827.hpp"

namespace porsche {
namespace {

const RttiBaseDescriptor scene_elem_base_005c48f0{
    &rtti_scene_elem_desc_005cf908.prefix, 0u, {0, -1, 0}, 0u};
const RttiBaseDescriptor camera_elem_base_005c4908{
    &rtti_camera_elem_desc_005cf928.prefix, 1u, {0, -1, 0}, 0u};

const RttiBaseDescriptor* const scene_elem_bases_005c49f4[1] = {
    &scene_elem_base_005c48f0};
const RttiBaseDescriptor* const camera_elem_bases_005c4920[2] = {
    &camera_elem_base_005c4908, &scene_elem_base_005c48f0};

const RttiHierarchy scene_elem_hierarchy_005c4a00{
    0u, 0u, 1u, scene_elem_bases_005c49f4};
const RttiHierarchy camera_elem_hierarchy_005c4930{
    0u, 0u, 2u, camera_elem_bases_005c4920};

} // namespace

// Each name array ends at its proven original NUL; cached_name starts null in .data.
RttiTypeDescriptor<17> rtti_scene_elem_desc_005cf908{
    {&rtti_type_info_table_005c18f8.destructor, nullptr}, ".?AVCSceneElem@@"};
RttiTypeDescriptor<18> rtti_camera_elem_desc_005cf928{
    {&rtti_type_info_table_005c18f8.destructor, nullptr}, ".?AVCCameraElem@@"};

const RttiCompleteObjectLocator rtti_scene_elem_locator_005c4a10{
    0u, 0u, 0u, &rtti_scene_elem_desc_005cf908.prefix, &scene_elem_hierarchy_005c4a00};
const RttiCompleteObjectLocator rtti_camera_elem_locator_005c4940{
    0u, 0u, 0u, &rtti_camera_elem_desc_005cf928.prefix, &camera_elem_hierarchy_005c4930};

} // namespace porsche
