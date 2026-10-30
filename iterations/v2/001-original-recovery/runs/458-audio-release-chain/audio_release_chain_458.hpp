#pragma once
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
#include "../443-audio-device-capabilities/audio_capabilities_443.hpp"
#include <cstddef>
namespace porsche {
// One physical original span, not independent copies of neighboring arrays.
// Original producers and accepted442 establish at most4 lanes after apply.
struct AudioReleaseStorage458 {
    std::uint32_t raw[2],aligned[2];
    std::uint32_t channel_raw[4],channel_aligned[4];
    std::uint32_t optional;
    std::uint32_t channel_word[4],filter[4];
    std::uint8_t opaque_006b17a0[48];
    std::uint32_t table;
};
static_assert(sizeof(AudioReleaseStorage458)==136);
static_assert(offsetof(AudioReleaseStorage458,optional)==0x30);
static_assert(offsetof(AudioReleaseStorage458,filter)==0x44);
static_assert(offsetof(AudioReleaseStorage458,table)==0x84);
extern AudioReleaseStorage458 audio_release_storage_006b174c;
extern std::uint32_t audio_release_format_006b16a4;
extern std::uint8_t& audio_release_channel_count_006b16a5;
std::int32_t __cdecl audio_device_release_ds_0058f1f0();
void __cdecl audio_release_mixer_005983b0();
// A raw32 float stack argument; preserve all bits at the typed child boundary.
void __cdecl audio_release_filters_00598020(std::uint32_t factor_bits);
// Still-unrecovered original children on the below1/unordered branch.
void __cdecl audio_release_filter_initialize_0059a170(std::uint32_t object);
void __cdecl audio_release_filter_set_0059a150(std::uint32_t object,std::uint32_t factor_bits);
}
