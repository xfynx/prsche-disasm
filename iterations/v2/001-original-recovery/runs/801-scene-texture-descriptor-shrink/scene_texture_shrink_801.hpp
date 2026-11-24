// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run801: scene texture descriptor shrink & shape create cluster:
//   005557d0..0055596e (415B) scene_texture_descriptor_shrink_005557d0
//   00574c70..00574e40 (465B) scene_texture_shape_create_00574c70
#pragma once

#include <cstdint>

namespace porsche {

// Matches exact typed child declaration in runs/799-scene-texture-descriptor-parse/scene_texture_descriptor_799.hpp.
void* __cdecl scene_texture_descriptor_shrink_005557d0(const void* descriptor);

void* __cdecl scene_texture_shape_create_00574c70(
    std::int32_t width, std::int32_t height,
    std::int32_t depth, std::uint32_t flags);

} // namespace porsche
