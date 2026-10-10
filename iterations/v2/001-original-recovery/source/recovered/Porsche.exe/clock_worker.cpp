#include "porsche/clock_worker.hpp"

#include "porsche/file_device.hpp"
#include "porsche/file_events.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/object_update.hpp"
#include "porsche/window_runtime.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

ClockWorkerCallback clock_worker_callbacks_006b7c20[8]{};
std::uint32_t clock_worker_carry_006b7c44 = 0;
std::uint32_t clock_worker_iterations_006b7c7c = 0;
void* clock_worker_event_006a5bfc = nullptr;
std::uint32_t clock_worker_active_006a5c0c = 0;

namespace {
std::int32_t signed_bits(std::uint32_t bits) noexcept {
    std::int32_t value{};
    std::memcpy(&value, &bits, sizeof(value));
    return value;
}
} // namespace

std::uint32_t __cdecl clock_worker_00565270() {
    std::uint32_t previous_tick = platform_get_tick_count();
    std::uint32_t accumulator = 0;

    clock_worker_event_006a5bfc = file_auto_event_0055fb20();
    (void)file_worker_wait_0055fb90(clock_worker_event_006a5bfc);

    while (clock_worker_active_006a5c0c != 0) {
        ++clock_worker_iterations_006b7c7c;
        ++current_tick_006b7c40;

        const std::uint32_t tick = platform_get_tick_count();
        const std::uint32_t delta = tick - previous_tick;
        previous_tick = tick;
        accumulator += delta * 1193u;

        // The original uses CMP accumulator, 0xffff / signed JLE, then SAR 16
        // and masks the low word only on the carry branch.
        if (signed_bits(accumulator) > 0xffff) {
            clock_worker_carry_006b7c44 += accumulator >> 16;
            accumulator &= 0xffffu;
        }

        for (std::size_t index = 0; index < 8; ++index) {
            const auto callback = clock_worker_callbacks_006b7c20[index];
            if (callback != nullptr)
                callback();
        }

        (void)file_worker_wait_0055fb90(clock_worker_event_006a5bfc);
    }

    (void)file_close_event_0055fc10(clock_worker_event_006a5bfc);
    clock_worker_event_006a5bfc = nullptr;
    timer_rate_005deb48 = 0;
    return 0;
}

} // namespace porsche
