#pragma once
#include <cstdint>

namespace porsche {

// 0053aa60 consumes the ring created by 0053a9e0. The input translation
// remains a typed engine boundary at 00560080.
std::uint32_t __cdecl window_event_dequeue_0053aa60();
std::uint32_t __cdecl window_event_translate_00560080(std::uint32_t payload,
                                                       std::uint32_t type);

extern std::uint8_t window_event_ring_0069e4e0[32 * 4];

}
