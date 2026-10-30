#pragma once
#include <cstdint>
namespace porsche {
void __cdecl audio_release_filter_initialize_0059a170(std::uint32_t object);
void __cdecl audio_release_filter_set_0059a150(std::uint32_t object,std::uint32_t factor_bits);
std::int32_t __cdecl audio_filter_callback_0059a0f0(std::uint32_t object,
    std::uint32_t count,std::uint32_t input,std::uint32_t output);
// The original retains its x87 accumulator across FST output stores and
// preserves ECX/EAX/EDX in addition to the ordinary nonvolatile registers.
void __cdecl audio_filter_kernel_0059c170(std::uint32_t state,
    std::uint32_t count,std::uint32_t output);
}
