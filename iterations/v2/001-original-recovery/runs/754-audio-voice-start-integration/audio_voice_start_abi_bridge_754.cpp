// The existing callers declare mutable pointer arguments. The recovered
// Run751 body reads these inputs and uses const pointers; Win32 cdecl passes
// both declarations identically, but MSVC gives them distinct C++ symbols.
#include "../751-audio-voice-start/audio_voice_start_751.hpp"

namespace porsche {

std::int32_t __cdecl audio_stream_voice_start_005612a0(
    std::uint32_t stream_slot,
    void* header,
    void* params,
    void* descriptor) {
    return audio_stream_voice_start_005612a0(
        stream_slot,
        static_cast<const void*>(header),
        static_cast<const void*>(params),
        static_cast<const void*>(descriptor));
}

} // namespace porsche
