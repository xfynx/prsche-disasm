#pragma once
#include "porsche/application_audio_device.hpp"
namespace porsche {
// Exact original touched span: count0 last-column byte, then 256 four-byte rows.
struct AudioBackendPanStorage555 {std::uint8_t before;std::uint8_t table[1024];};
static_assert(sizeof(AudioBackendPanStorage555)==1025);
static_assert(offsetof(AudioBackendPanStorage555,table)==1);
extern AudioBackendPanStorage555 audio_backend_pan_storage_006b181f;
std::int32_t __cdecl audio_backend_pan_curve_0058e0b0(std::int32_t);
void __cdecl audio_backend_pan_copy_0058e290(std::int32_t,std::uint32_t);
}
