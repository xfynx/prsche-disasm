// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "../451-audio-record-decoder/audio_record_decoder_451.hpp"
#include "../519-audio-stream-capture-fill/audio_stream_capture_fill_519.hpp"

namespace porsche {

// Recovered functions (4 bodies, 1123 code bytes total).
std::uint32_t __cdecl audio_stream_info_init_00561900(void* info);
std::int32_t __cdecl audio_stream_header_byte_rate_00590ef0(const void* header);
std::uint32_t __cdecl audio_stream_header_parse_00590f70(
    const void* data,
    void* header,
    void* info,
    std::uint32_t* out_flags);
std::uint32_t __cdecl audio_stream_codec_from_format_00599720(
    std::uint32_t format_tag,
    std::uint32_t bits_per_sample);

} // namespace porsche
