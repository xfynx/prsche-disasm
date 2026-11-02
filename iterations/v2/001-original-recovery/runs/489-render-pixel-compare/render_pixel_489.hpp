#pragma once
#include <cstdint>
namespace porsche {
// Original full EAX conversion; known constructor consumes only AL via TEST.
std::uint32_t __cdecl render_pixel_convert_00468110(std::uint32_t pixel,std::uint32_t format);
// Existing constructor contract: truth of the original consumed AL.
bool __cdecl render_display_compare_pixel_00468110(std::uint32_t pixel,std::uint32_t format);
}
