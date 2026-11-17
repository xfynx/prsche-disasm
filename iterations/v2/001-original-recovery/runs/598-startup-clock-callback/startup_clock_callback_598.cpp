// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a4700..004a4759, 90 bytes, sha256 85a22a84d0758c82e74af76b08e70eac46414be4b8e9aff443c64955812c2a3f.
// Original 00560140..00560176, 55 bytes, sha256 b45f2346092ef605f5a05368779fdea8df5a7e1efe25c74682033e7a5b446cc4.
#include "startup_clock_callback_598.hpp"
#include <cstdint>

namespace porsche {

std::uint32_t startup_clock_word_006559e0 = 0u;
std::uint32_t startup_clock_initialized_00655a04 = 0u;
std::uint32_t startup_clock_word_006559e8 = 0u;
std::uint32_t startup_clock_word_006559ec = 0u;
std::uint32_t startup_clock_word_006559f0 = 0u;
std::uint32_t startup_clock_word_00655a00 = 0u;
std::uint32_t startup_clock_word_006559f4 = 0u;
std::uint32_t startup_clock_word_006559fc = 0u;
std::uint32_t frame_reset_source_005e99b8 = 0u;

void __cdecl clock_worker_register_callback_00560140(ClockWorkerCallback callback) {
    for (std::uint32_t i = 0u; i < 8u; ++i) {
        if (clock_worker_callbacks_006b7c20[i] == callback) {
            return;
        }
    }
    for (std::uint32_t i = 0u; i < 8u; ++i) {
        if (clock_worker_callbacks_006b7c20[i] == nullptr) {
            clock_worker_callbacks_006b7c20[i] = callback;
            return;
        }
    }
}

void __cdecl startup_sequence_call_004a4700() {
    frame_pump_word_00655a08 = 0u;
    startup_clock_word_006559e0 = 0u;
    if (startup_clock_initialized_00655a04 == 0u) {
        startup_clock_initialized_00655a04 = 1u;
        clock_worker_register_callback_00560140(
            reinterpret_cast<ClockWorkerCallback>(static_cast<std::uintptr_t>(0x004a45d0u)));
        startup_clock_word_006559e8 = 0u;
        startup_clock_word_006559ec = 0u;
        startup_clock_word_006559f0 = 0u;
        startup_clock_word_00655a00 = 0u;
        startup_clock_word_006559f4 = 0u;
        startup_clock_word_006559fc = 0u;
        frame_reset_source_005e99b8 = 0u;
    }
}

} // namespace porsche
