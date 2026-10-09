#include "porsche/file_threads.hpp"
#include "porsche/window_threads.hpp"
#include "porsche/thread_shutdown.hpp"
#include "porsche/heap_locks.hpp"
#include <windows.h>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace {
void (__cdecl* registered_exit)() = nullptr;
std::uint32_t registration_count = 0;
struct Context {
    void* gate;
    void* done;
    std::uint32_t argument, id;
};
Context context{};
void __cdecl work(std::uint32_t argument) {
    using namespace porsche;
    file_worker_wait_0055fb90(context.gate);
    context.argument = argument;
    context.id = platform_current_thread_id();
    file_event_signal_0055fb30(context.done);
}
void __cdecl no_argument_work() { work(0x11223344); }
}

namespace porsche {
// Fixture-only CRT boundaries. Original init actually registers its callback;
// the fixture invokes that exact callback after joining both native workers.
void __cdecl thread_exit_register_00557380(void (__cdecl* callback)()) {
    if (registered_exit) std::abort();
    registered_exit = callback;
    ++registration_count;
}
void __cdecl heap_fill_0053c290(void* output, std::uint32_t value, std::uint32_t bytes) {
    std::memset(output, static_cast<int>(value), bytes);
}
}

int main() {
    using namespace porsche;
    bool passed = true;
    const auto parent_id = platform_current_thread_id();
    for (std::uint32_t variant = 0; variant != 2; ++variant) {
        context = {};
        context.gate = file_auto_event_0055fb20();
        context.done = file_auto_event_0055fb20();
        if (!context.gate || !context.done) return 2;
        ThreadRecord record{};
        const auto raw = variant == 0
            ? static_cast<std::uint32_t>(file_thread_start_0055f5f0(
                work, 0x55667788, 0, 0, -1, &record))
            : window_thread_start_0055f420(reinterpret_cast<void*>(no_argument_work),
                0, 0, 0xffffffffu, reinterpret_cast<std::uint32_t*>(&record));
        auto* thread = reinterpret_cast<void*>(static_cast<std::uintptr_t>(raw));
        passed &= thread != nullptr && record.handle == thread && record.id != parent_id;
        passed &= record.stack == 0 && record.priority == 0 && record.flags == 0;
        passed &= threads_initialized_006a57dc == 1 && main_thread_id_006a57d4 == parent_id;
        void* join_handle = nullptr;
        if (!thread || !platform_duplicate_handle(platform_current_process(), thread,
            platform_current_process(), &join_handle, 0, 0, 2)) return 3;
        // Gate keeps the original trampoline from unregistering/closing its
        // handle before the fixture has duplicated it for joining.
        file_event_signal_0055fb30(context.gate);
        passed &= file_wait_many_0055fb60(1, &context.done, 5000) == context.done;
        if (::WaitForSingleObject(join_handle, 5000) != WAIT_OBJECT_0) return 4;
        passed &= context.argument == (variant == 0 ? 0x55667788u : 0x11223344u);
        passed &= context.id == record.id;
        const auto& entry = thread_entries_006a57e4[record.slot];
        passed &= entry.serial == 0 && entry.handle == nullptr && entry.id == 0;
        passed &= platform_close_handle(join_handle) != 0;
        passed &= file_close_event_0055fc10(context.gate) != 0;
        passed &= file_close_event_0055fc10(context.done) != 0;
    }
    passed &= registration_count == 1 && registered_exit == thread_shutdown_0055f1c0;
    if (registered_exit) registered_exit();
    passed &= threads_initialized_006a57dc == 0;
    passed &= thread_entries_006a57e4 == nullptr && thread_capacity_006a57e8 == 0;
    passed &= thread_table_lock_006a57ec == nullptr;
    std::cout << std::boolalpha << "{\"original_thread_init\":true,"
        "\"file_and_window_thread_start\":true,\"original_trampoline_and_unregister\":true,"
        "\"original_thread_shutdown\":true,\"real_win32_threads_events_pages_locks\":true,"
        "\"fixture_crt_boundaries\":[\"exit_registration\",\"fill\"],"
        "\"fixture_passed\":" << passed << ",\"game_launch_verified\":false}\n";
    return passed ? 0 : 1;
}
