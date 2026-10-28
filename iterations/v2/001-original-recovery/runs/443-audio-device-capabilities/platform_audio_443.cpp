#include "audio_capabilities_443.hpp"
// Exact x86 Win32 ABI declarations; import libraries bind these real OS exports.
// No mock DirectSound or COM implementation belongs in this production TU.
extern "C" std::int32_t __stdcall DirectSoundCreate(const void*,std::uint32_t*,void*);
extern "C" void* __stdcall GetForegroundWindow();
extern "C" void* __stdcall GetDesktopWindow();
namespace porsche {
std::int32_t __stdcall audio_direct_sound_create_00597f70(
    const void* guid,std::uint32_t* object,void* outer) {
    return ::DirectSoundCreate(guid,object,outer);
}
void* __stdcall audio_platform_foreground_window() { return ::GetForegroundWindow(); }
void* __stdcall audio_platform_desktop_window() { return ::GetDesktopWindow(); }
}
