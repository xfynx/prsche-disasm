#pragma once
#include "../455-audio-device-lifecycle/audio_device_lifecycle_455.hpp"
namespace porsche {
// One physical original8B block, immediately after the canonical device span.
// Volatile views preserve the observed callback-cell loads at every call site.
struct AudioThreadCallbacks460 { volatile std::uint32_t before,after; };
static_assert(sizeof(AudioThreadCallbacks460)==8);
extern AudioThreadCallbacks460 audio_thread_callbacks_006b4a3c;
extern volatile std::uint32_t& audio_thread_before_006b4a3c;
extern volatile std::uint32_t& audio_thread_after_006b4a40;
using AudioThreadSleep460=void(__stdcall*)(std::uint32_t);
// Link-time alias of the real SDK-owned IAT cell, never a copied global.
extern AudioThreadSleep460 audio_thread_sleep_005b220c;
// Original0058f8e0 is unrecovered; this caller uses only its effects.
void __cdecl audio_thread_mix_0058f8e0();
}
