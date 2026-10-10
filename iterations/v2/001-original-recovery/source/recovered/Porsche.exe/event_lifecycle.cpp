#include "porsche/event_lifecycle.hpp"

#include "porsche/auxiliary_wait.hpp"
#include "porsche/file_device.hpp"
#include "porsche/file_events.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_create.hpp"

namespace porsche {

AuxiliaryEventCallback auxiliary_event_callbacks_0069e5b4[8]{};
void* auxiliary_event_lock_0069e5d4 = nullptr;
std::uint32_t auxiliary_event_stopping_0069e5d8 = 0;
ThreadRecord auxiliary_event_thread_006bd9c0{};

void __cdecl auxiliary_event_callback_add_0053bfe0(
    AuxiliaryEventCallback callback) {
    if (auxiliary_event_lock_0069e5d4 == nullptr)
        auxiliary_event_lifecycle_start_0053c060();

    heap_enter_005322b0(auxiliary_event_lock_0069e5d4);
    std::int32_t first_empty = -1;
    for (std::int32_t i = 0; i < 8; ++i) {
        const AuxiliaryEventCallback current = auxiliary_event_callbacks_0069e5b4[i];
        if (current == nullptr) {
            if (first_empty < 0) first_empty = i;
        } else if (current == callback) {
            heap_leave_005322c0(auxiliary_event_lock_0069e5d4);
            return;
        }
    }
    if (first_empty >= 0)
        auxiliary_event_callbacks_0069e5b4[first_empty] = callback;
    heap_leave_005322c0(auxiliary_event_lock_0069e5d4);
}

void __cdecl auxiliary_event_lifecycle_start_0053c060() {
    thread_exit_register_00557380(auxiliary_event_lifecycle_stop_0053c170);
    auxiliary_event_lock_0069e5d4 = heap_lock_create_005321f0();
    auxiliary_event_stopping_0069e5d8 = 0;
    heap_enter_005322b0(auxiliary_event_lock_0069e5d4);
    if (window_thread_start_0055f420(
            reinterpret_cast<void*>(auxiliary_event_worker_0053c0f0),
            0, 1, 0xffffffffu,
            reinterpret_cast<std::uint32_t*>(&auxiliary_event_thread_006bd9c0)) == 0) {
        heap_lock_destroy_005322d0(auxiliary_event_lock_0069e5d4);
        auxiliary_event_lock_0069e5d4 = nullptr;
        diagnostic_file_005deb74_set("\\real\\pc\\lowtimer.c");
        application_diagnostic_line_005deb78 = 0x4b;
        diagnostic_handler_005debf0(
            "wininittimer - FAILED TO CREATE SECONDARY TIMER`S THREAD.\n");
        return;
    }
    heap_leave_005322c0(auxiliary_event_lock_0069e5d4);
}

void __cdecl auxiliary_event_worker_0053c0f0() {
    auxiliary_wait_event_0069e5dc = file_auto_event_0055fb20();
    if (auxiliary_event_stopping_0069e5d8 == 0) {
        do {
            (void)file_worker_wait_0055fb90(auxiliary_wait_event_0069e5dc);
            heap_enter_005322b0(auxiliary_event_lock_0069e5d4);
            for (AuxiliaryEventCallback callback : auxiliary_event_callbacks_0069e5b4) {
                // 0053c127 jumps out of the pass at its first null slot.
                if (callback == nullptr) break;
                callback();
            }
            heap_leave_005322c0(auxiliary_event_lock_0069e5d4);
        } while (auxiliary_event_stopping_0069e5d8 == 0);
    }
    (void)file_close_event_0055fc10(auxiliary_wait_event_0069e5dc);
    auxiliary_wait_event_0069e5dc = nullptr;
}

void __cdecl auxiliary_event_lifecycle_stop_0053c170() {
    if (auxiliary_event_lock_0069e5d4 == nullptr) return;

    auxiliary_event_stopping_0069e5d8 = 1;
    (void)file_event_signal_0055fb30(auxiliary_wait_event_0069e5dc);
    if (!file_current_thread_0055f780(
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
                &auxiliary_event_thread_006bd9c0)))) {
        (void)thread_wait_0055fa10(
            &auxiliary_event_thread_006bd9c0, 0);
    }
    heap_lock_destroy_005322d0(auxiliary_event_lock_0069e5d4);
    auxiliary_event_lock_0069e5d4 = nullptr;
}

void __cdecl auxiliary_event_callback_remove_0053c1d0(
    AuxiliaryEventCallback callback) {
    if (auxiliary_event_lock_0069e5d4 == nullptr) return;

    heap_enter_005322b0(auxiliary_event_lock_0069e5d4);
    std::uint32_t index = 0;
    while (index < 8 && auxiliary_event_callbacks_0069e5b4[index] != callback)
        ++index;
    if (index < 8 && auxiliary_event_callbacks_0069e5b4[index] == callback) {
        while (index < 7) {
            auxiliary_event_callbacks_0069e5b4[index] =
                auxiliary_event_callbacks_0069e5b4[index + 1];
            ++index;
        }
        auxiliary_event_callbacks_0069e5b4[7] = nullptr;
    }
    heap_leave_005322c0(auxiliary_event_lock_0069e5d4);

    for (AuxiliaryEventCallback current : auxiliary_event_callbacks_0069e5b4) {
        if (current != nullptr) return;
    }
    auxiliary_event_lifecycle_stop_0053c170();
}

} // namespace porsche
