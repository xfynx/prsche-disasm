#pragma once
#include "porsche/application_audio_device.hpp"
namespace porsche {
// Original initialized/applied channel contract permits at most4 buffers.
extern std::uint32_t audio_ds_buffers_006ad768[4];
// One physical15-DWORD span,006ad77c..006ad7b7. Names do not infer semantics.
struct AudioDirectSoundStreamState462 {std::uint32_t raw[15];};
static_assert(sizeof(AudioDirectSoundStreamState462)==60);
extern AudioDirectSoundStreamState462 audio_ds_stream_006ad77c;
extern std::uint32_t audio_ds_property_settings_006aefe4[3];
extern std::int8_t audio_ds_notify_kind_006b4886;
extern std::uint32_t audio_ds_mix_guard_006aeff4;
// View of the accepted device block, never another original DWORD.
extern std::uint32_t& audio_ds_notify_value_006b4a08;
}
