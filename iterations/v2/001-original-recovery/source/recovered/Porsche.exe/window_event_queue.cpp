#include "porsche/window_event_queue.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/heap.hpp"

namespace porsche {

// Original ring storage at 0069e4e0. Each slot is four bytes; enqueue writes
// bytes 0/1 as byte fields and bytes 2/3 as a signed 16-bit field.
std::uint8_t window_event_ring_0069e4e0[32 * 4]{};

std::uint32_t __cdecl window_message_enqueue_0053a9e0(std::uint32_t value16,
                                                       std::uint32_t payload,
                                                       std::uint32_t type) {
    void* const lock = window_input_lock_0069e564;
    const std::uint32_t slot = window_input_write_0069e568;
    heap_enter_005322b0(lock);

    const std::uint32_t offset = slot * 4;
    const auto value = static_cast<std::uint16_t>(value16);
    window_event_ring_0069e4e0[offset + 2] = static_cast<std::uint8_t>(value);
    window_event_ring_0069e4e0[offset + 3] = static_cast<std::uint8_t>(value >> 8);
    const std::uint32_t current_write = window_input_write_0069e568;
    const std::uint32_t current_offset = current_write * 4;
    window_event_ring_0069e4e0[current_offset + 1] = static_cast<std::uint8_t>(payload);
    window_event_ring_0069e4e0[current_offset] = static_cast<std::uint8_t>(type);

    const auto capacity = static_cast<std::int32_t>(window_input_capacity_0069e560);
    const auto next = static_cast<std::int32_t>(window_input_write_0069e568 + 1);
    const auto write = static_cast<std::uint32_t>(next % capacity);
    const auto read = window_input_read_0069e0d8;
    window_input_write_0069e568 = write;
    if (read == write)
        window_input_read_0069e0d8 = static_cast<std::uint32_t>(
            (static_cast<std::int32_t>(read + 1)) % capacity);

    heap_leave_005322c0(lock);
    // Original leaves EAX as a side effect of its lock-leave boundary; it does
    // not establish a useful queue status value.
    return 0;
}

std::uint32_t __cdecl window_event_dequeue_0053aa60() {
    void* const lock = window_input_lock_0069e564;
    heap_enter_005322b0(lock);

    std::uint32_t payload = 0;
    std::int32_t translated = 0;
    for (;;) {
        const std::uint32_t read = window_input_read_0069e0d8;
        const std::uint32_t write = window_input_write_0069e568;
        if (read == write || translated != 0)
            break;

        const std::uint32_t offset = read * 4;
        const std::uint32_t type = window_event_ring_0069e4e0[offset];
        payload = window_event_ring_0069e4e0[offset + 1];
        const auto stored = static_cast<std::int16_t>(
            static_cast<std::uint16_t>(window_event_ring_0069e4e0[offset + 2]) |
            (static_cast<std::uint16_t>(window_event_ring_0069e4e0[offset + 3]) << 8));
        translated = stored;
        if (stored == 0)
            translated = static_cast<std::int32_t>(
                window_event_translate_00560080(payload, type));

        const auto capacity = static_cast<std::int32_t>(window_input_capacity_0069e560);
        const auto next = static_cast<std::int32_t>(window_input_read_0069e0d8 + 1);
        window_input_read_0069e0d8 = static_cast<std::uint32_t>(next % capacity);
    }

    heap_leave_005322c0(lock);
    return (payload << 16) | static_cast<std::uint32_t>(translated);
}

}
