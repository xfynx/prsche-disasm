#pragma once
#include <cstdint>

namespace porsche {
extern const std::uint32_t audio_copy_min_005c1694;
std::uint32_t __cdecl audio_resource_copy_0058e310(
    std::uint32_t source, std::int32_t format, std::int32_t start,
    std::int32_t end, std::uint32_t count, void* destination, std::int32_t bits);
}
