// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_lifecycle.hpp"
#include "porsche/application_state.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/frame_services.hpp"
#include "porsche/object_update.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../607-frame-audio-stream-ramp/frame_audio_stream_ramp_607.hpp"
#include "../637-audio-stream-channel-status/audio_stream_channel_status_637.hpp"
#include "../638-render-seed-prng/render_seed_prng_638.hpp"
#include "../640-pattern-match/audio_transition_pattern_match_640.hpp"

namespace porsche {

// 5-byte .data format string at original VA 0x005d1c1c..0x005d1c20 ("*-%s\0").
extern char audio_transition_wildcard_fmt_005d1c1c[5];

// 4-byte loader-zero .data word at original VA 0x0065b928..0x0065b92b.
extern std::uint32_t audio_transition_word_0065b928;

// Canonical Run564 audio resource/stream declarations matching audio_callback_resource_564.obj.
std::uint32_t __cdecl audio_resource_locate_005666f0(
    std::uint32_t source, std::uint32_t name, std::uint32_t index,
    std::uint32_t out1, std::uint32_t out2);
std::int32_t __cdecl audio_service_stream_start_00567720(
    std::uint32_t channel, std::uint32_t mode,
    std::uint32_t data, std::uint32_t size);

} // namespace porsche
