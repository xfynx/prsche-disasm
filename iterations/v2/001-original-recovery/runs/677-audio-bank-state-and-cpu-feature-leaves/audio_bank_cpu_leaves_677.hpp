// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"

namespace porsche {

// Original 00565b30..00565b52 (35B, __cdecl, ret 0).
std::int32_t __cdecl audio_bank_get_size_00565b30(std::int32_t bank_index);

// Original 00565ad0..00565b20 (81B, __cdecl, ret 0).
std::int32_t __cdecl audio_bank_copy_00565ad0(void* dst_buffer, std::int32_t bank_index);

// Original 00590140..00590168 (41B, __cdecl, ret 0).
std::int32_t __cdecl audio_bank_find_free_slot_00590140();

// Original 00574e50..00574e6a (27B, __cdecl, ret 0).
std::uint32_t __cdecl cpu_check_cpuid_support_00574e50();

// Original 00574e6b..00574e88 (30B, __cdecl, ret 0).
void __cdecl cpu_query_cpuid_00574e6b(std::uint32_t* out_regs, std::uint32_t leaf);

// Original 00574e89..00574eaa (34B, __cdecl, ret 0).
std::uint32_t __cdecl cpu_check_div_flags_00574e89();

} // namespace porsche
