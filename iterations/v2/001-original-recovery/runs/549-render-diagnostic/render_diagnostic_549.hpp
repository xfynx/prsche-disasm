#pragma once
#include "../345-diagnostic-devices/diagnostic_devices.hpp"
#include <cstdint>
namespace porsche {
// Original0055ec50, cdecl channel/format plus untouched raw x86 varargs.
// Existing546 frontier keeps this name; this is a diagnostic channel consumer.
void __cdecl render_texture_diagnostic_0055ec50(std::uint32_t channel,const char* format,...);
}
