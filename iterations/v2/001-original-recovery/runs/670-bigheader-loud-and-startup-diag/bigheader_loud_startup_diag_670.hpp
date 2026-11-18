// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/resource_dispatch.hpp"
#include "porsche/resource_leaf.hpp"
#include "../353-diagnostic-mono/diagnostic_mono.hpp"
#include "../390-diagnostic-terminal/diagnostic_terminal.hpp"
#include "../661-bigheader-and-audio-probe-configure/bigheader_audio_configure_661.hpp"

namespace porsche {

// Original 005620c0..005620fe (63B, __cdecl, ret 0).
void* __cdecl file_load_bigheader_005620c0(
    const char* path, std::uint32_t flags);

// Original 0059dea0..0059df6d (206B, __cdecl, ret 0).
void* __cdecl resource_load_bigheader_0059dea0(
    const char* name, std::uint32_t flags);

// Original 0059fd90..0059fdbd (46B, __cdecl, ret 0).
void __cdecl startup_diagnostic_format_0059fd90(
    const char* format, ...);

} // namespace porsche
