#include "porsche/file_events.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_worker.hpp"

#include <cstdint>

namespace porsche {

// 006a57d8 has one original pointer cell. The paint path and thread-start
// path are two recovered names for the file-thread start lock.
void*& window_paint_lock_006a57d8 = thread_start_lock_006a57d8;

// The original bootstrap CALL at 0055f51d supplies no arguments and ignores
// EAX. Keep that machine-level callback ABI exact; the recovered worker body
// also returns its original EAX value for direct comparison probes.
void __cdecl window_worker_thread_entry() {
    (void)window_worker_0053b8d0();
}

void* __cdecl window_lock_create_005321f0() {
    return heap_lock_create_005321f0();
}

std::uint32_t __cdecl window_message_pump_005322b0(std::uint32_t lock) {
    heap_enter_005322b0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
    return 0; // Original callers ignore EAX; the recovered callee is void.
}
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t lock) {
    heap_enter_005322b0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
    return 0; // Original callers ignore EAX; the recovered callee is void.
}
std::uint32_t __cdecl window_message_dispatch_005322c0(std::uint32_t lock) {
    heap_leave_005322c0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
    return 0; // Original callers ignore EAX; the recovered callee is void.
}
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t lock) {
    heap_leave_005322c0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
    return 0; // Original callers ignore EAX; the recovered callee is void.
}

std::uint32_t __cdecl window_timed_callback_005366e0(std::uint32_t argument) {
    return timed_callbacks_005366e0(argument);
}
std::uint32_t __cdecl window_position_timed_005366e0(std::uint32_t argument) {
    return timed_callbacks_005366e0(argument);
}

void __cdecl window_idle_0055f740(std::uint32_t milliseconds) {
    (void)file_sleep_0055f740(milliseconds);
}
std::uint32_t __cdecl window_position_idle_0055f740(std::uint32_t milliseconds) {
    return file_sleep_0055f740(milliseconds);
}

void __cdecl window_prepare_0053bcb0() {
    window_position_cleanup_0053bcb0();
}
void __cdecl window_resize_0053bec0(std::uint32_t width, std::uint32_t height) {
    window_position_center_0053bec0(static_cast<std::int32_t>(width),
                                    static_cast<std::int32_t>(height));
}

void __cdecl window_thread_wait_0055fb30(void* event) {
    (void)file_event_signal_0055fb30(event);
}
std::uint32_t __cdecl window_worker_wait_0055fb20() {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        file_auto_event_0055fb20()));
}
std::uint32_t __cdecl window_worker_wait_0055fb90(std::uint32_t event) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        file_worker_wait_0055fb90(reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(event)))));
}
std::uint32_t __cdecl window_worker_wait_0055fc10(std::uint32_t event) {
    return file_close_event_0055fc10(reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(event)));
}

}
