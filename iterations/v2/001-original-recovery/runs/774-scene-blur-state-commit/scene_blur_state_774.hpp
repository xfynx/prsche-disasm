// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run774: scene blur state setters & commit cluster:
//   00537a30..00537a38 (  9B) scene_blur_state_quality_00537a30
//   00537a40..00537a49 ( 10B) scene_blur_state_one_00537a40
//   00537a70..00537a7c ( 13B) scene_blur_state_flag_00537a70
//   00536470..00536505 (150B) scene_blur_state_commit_00536470
#pragma once

#include <cstdint>

namespace porsche {

// Matches caller declarations in runs/738-scene-blur-stage-child/scene_blur_stage_child_738.hpp.
void __fastcall scene_blur_state_quality_00537a30(
    void* self, void* unused_edx, std::uint32_t value);

void __fastcall scene_blur_state_one_00537a40(
    void* self, void* unused_edx, std::uint32_t value);

void __fastcall scene_blur_state_flag_00537a70(
    void* self, void* unused_edx, std::uint32_t value);

void __fastcall scene_blur_state_commit_00536470(
    void* self, void* unused_edx, const void* state_28_bytes);

} // namespace porsche
