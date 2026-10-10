#include "porsche/thread_wait.hpp"

#include "porsche/file_events.hpp"
#include "porsche/heap.hpp"

#include <cstdint>

namespace porsche {
namespace {

// Equivalent to the original 0055f9b0/0055f980 membership test. It uses the
// existing thread-table owner and returns the record's table cell only when
// its signed slot is in bounds and the stored serial matches.
ThreadEntry* matching_thread_entry(ThreadRecord* record) {
    const std::int32_t slot = static_cast<std::int32_t>(record->slot);
    if (slot < 0 || slot >= thread_capacity_006a57e8)
        return nullptr;

    heap_enter_005322b0(thread_table_lock_006a57ec);
    ThreadEntry* entries = thread_entries_006a57e4;
    ThreadEntry* entry = entries + slot;
    if (entry->serial != record->serial)
        entry = nullptr;
    heap_leave_005322c0(thread_table_lock_006a57ec);
    return entry;
}

bool thread_record_has_exited(ThreadRecord* record) {
    ThreadEntry* const entry = matching_thread_entry(record);
    // The original 0055f980 reads the selected cell after its lock is left.
    return entry == nullptr || entry->serial != record->serial;
}

std::uint32_t original_rate_over_100(std::uint32_t rate) noexcept {
    // Match IMUL 0x51eb851f; SAR EDX,5; SHR sign correction; ADD EDX,EAX.
    const std::int64_t product = static_cast<std::int64_t>(
        static_cast<std::int32_t>(rate)) * 0x51eb851fll;
    const std::uint32_t high = static_cast<std::uint32_t>(
        static_cast<std::uint64_t>(product) >> 32);
    std::uint32_t shifted = high >> 5;
    if ((high & 0x80000000u) != 0)
        shifted |= 0xf8000000u;
    shifted += shifted >> 31;
    return shifted;
}

} // namespace

std::uint32_t __cdecl thread_wait_0055fa10(ThreadRecord* record,
    std::uint32_t timeout_ticks) {
    void* const handle = thread_handle_0055f730(record);
    if (handle == nullptr)
        return 0;

    if (timeout_ticks != 0) {
        (void)file_timed_event_0055fbb0(handle, timeout_ticks);
        return thread_record_has_exited(record) ? 1u : 0u;
    }

    while (!thread_record_has_exited(record)) {
        const std::uint32_t poll_ticks = original_rate_over_100(
            timer_rate_005deb48);
        (void)file_timed_event_0055fbb0(handle, poll_ticks);
    }
    return 1;
}

} // namespace porsche
