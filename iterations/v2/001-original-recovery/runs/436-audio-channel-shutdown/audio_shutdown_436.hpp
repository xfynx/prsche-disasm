#pragma once

#include "audio_canonical_434.hpp"
#include "porsche/application_services_next.hpp"

namespace porsche {
// Controlled only by fixtures until their own original bodies are recovered.
std::int32_t __cdecl application_audio_validate_channel_00590070(std::int32_t index);
std::int32_t __cdecl application_audio_release_group_00565990(
    std::int32_t index, std::uint32_t header_word);
// Canonical signed-return body and the existing void consumer facade are declared
// by application_audio_lifecycle.hpp and application_services_next.hpp.
} // namespace porsche
