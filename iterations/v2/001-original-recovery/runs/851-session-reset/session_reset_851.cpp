// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#include "session_reset_851.hpp"
#include "frame_loop_clusters_400.hpp"

namespace porsche {

std::uint32_t session_random_state_005d1028 = 0xf874af01u;
std::uint32_t session_random_multiplier_005d102c = 1u;
std::uint32_t session_random_product_00655a0c = 0u;
std::uint32_t session_random_word_00655a10 = 0u;
std::uint32_t second_session_random_state_005ceae0 = 0xf874af01u;
std::uint32_t second_session_random_multiplier_005ceae4 = 1u;
std::uint32_t session_reset_word_005e67b0 = 0u;

void __cdecl frame_reset_service_004a4780(std::uint32_t value) {
    std::uint32_t state = 0x3ade68b1u;
    session_random_multiplier_005d102c = 0x075bcd15u;
    session_random_state_005d1028 = state;
    session_random_word_00655a10 = 0u;

    const std::uint32_t steps = value % 500u;
    if (steps != 0u) {
        for (std::uint32_t step = 0; step < steps; ++step) {
            const std::uint32_t product = state * 0x075bcd15u;
            session_random_product_00655a0c = product;
            state = product & 0xffffu;
        }
        session_random_state_005d1028 = state;
    }
}

void __cdecl frame_reset_service_0044fd00(std::uint32_t value) {
    std::uint32_t state = 0x3ade68b1u;
    second_session_random_multiplier_005ceae4 = 0x075bcd15u;
    second_session_random_state_005ceae0 = state;

    const std::uint32_t steps = value % 500u;
    if (steps != 0u) {
        for (std::uint32_t step = 0; step < steps; ++step) {
            // 0044fd28..0044fd3e reduces -13035 * state modulo 2^16.
            state = (state * 0xcd15u) & 0xffffu;
        }
        second_session_random_state_005ceae0 = state;
    }
}

void __cdecl frame_reset_service_004069d0() {
    session_reset_word_005e67b0 = 0u;
}

} // namespace porsche
