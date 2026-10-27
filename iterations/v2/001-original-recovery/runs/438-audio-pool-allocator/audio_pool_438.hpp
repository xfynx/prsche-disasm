#pragma once
#include "audio_canonical_434.hpp"

namespace porsche {
// Original0058aa60 callers consume the second pointed word; EAX is unused.
void __cdecl audio_backend_pool_clamp_0058aa60(
    const std::uint32_t* offset, std::uint32_t* available);
// application_audio_backend_allocate_0058aae0(uint32)->uint32 is canonical in
// application_audio_device.hpp, included through audio_canonical_434.hpp.
std::int32_t __cdecl audio_backend_pool_release_0058ac30(std::uint32_t address);
}
