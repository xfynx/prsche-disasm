#pragma once

#include <cstdint>
#include "porsche/clock_worker.hpp"
#include "porsche/frame_pump.hpp"
#include "porsche/startup_sequence.hpp"

namespace porsche {

// Loader-zero .data DWORDs owned by 004a4700.
extern std::uint32_t startup_clock_word_006559e0;
extern std::uint32_t startup_clock_initialized_00655a04;
extern std::uint32_t startup_clock_word_006559e8;
extern std::uint32_t startup_clock_word_006559ec;
extern std::uint32_t startup_clock_word_006559f0;
extern std::uint32_t startup_clock_word_00655a00;
extern std::uint32_t startup_clock_word_006559f4;
extern std::uint32_t startup_clock_word_006559fc;
extern std::uint32_t frame_reset_source_005e99b8;

// Original entry 00560140..00560176 (55 bytes).
void __cdecl clock_worker_register_callback_00560140(ClockWorkerCallback callback);

} // namespace porsche
