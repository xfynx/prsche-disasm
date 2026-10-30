#include "audio_device_lifecycle_455.hpp"
#include <windows.h>
namespace porsche {
void __stdcall audio_platform_sleep_455(std::uint32_t milliseconds) { ::Sleep(milliseconds); }
}
