#include "porsche/file_events.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap_locks.hpp"
#include <windows.h>
#include <cstdint>
#include <iostream>

namespace {
struct Context {
    CRITICAL_SECTION lock;
    void* done;
    std::uint32_t value, worker_id;
};
std::uint32_t __stdcall fixture_worker(void* argument) {
    auto& context = *static_cast<Context*>(argument);
    porsche::platform_enter_critical_section(&context.lock);
    context.worker_id = porsche::platform_current_thread_id();
    context.value = 0x12345678;
    porsche::platform_leave_critical_section(&context.lock);
    porsche::file_event_signal_0055fb30(context.done);
    return 0;
}
}

int main() {
    using namespace porsche;
    bool events = true, pages = true, threads = true, locks = true;
    auto* automatic = file_auto_event_0055fb20();
    auto* manual = file_manual_event_0055fc20();
    if (!automatic || !manual) return 2;
    events &= file_try_event_0055fb40(automatic) == 0;
    events &= file_event_signal_0055fb30(automatic) != 0;
    events &= file_try_event_0055fb40(automatic) == 1;
    events &= file_try_event_0055fb40(automatic) == 0;
    events &= file_event_signal_0055fb30(manual) != 0;
    events &= file_try_event_0055fb40(manual) == 1;
    events &= file_try_event_0055fb40(manual) == 1;
    events &= file_reset_event_0055fc40(manual) != 0;
    events &= file_try_event_0055fb40(manual) == 0;
    void* waits[] = {automatic, manual};
    events &= file_wait_many_0055fb60(2, waits, 0) == nullptr;
    file_event_signal_0055fb30(manual);
    events &= file_wait_many_0055fb60(2, waits, 0) == manual;
    file_reset_event_0055fc40(manual);
    ::SetLastError(0x1234);
    events &= file_last_error_0055fce0() == 0x1234;

    std::uint32_t bytes = 129;
    auto* memory = static_cast<std::uint8_t*>(file_object_allocate_0056e5f0(&bytes));
    pages &= memory != nullptr && bytes >= 129 && bytes == file_page_size_006a6418;
    if (memory) {
        memory[0] = 0x12; memory[bytes - 1] = 0x34;
        pages &= memory[0] == 0x12 && memory[bytes - 1] == 0x34;
        pages &= file_object_free_0056e640(memory) != 0;
    }

    Context context{};
    context.done = manual;
    platform_initialize_critical_section(&context.lock);
    // The original lock consumers require recursive critical sections.
    platform_enter_critical_section(&context.lock);
    platform_enter_critical_section(&context.lock);
    platform_leave_critical_section(&context.lock);
    platform_leave_critical_section(&context.lock);
    std::uint32_t id = 0;
    auto* thread = platform_create_thread(nullptr, 0, fixture_worker, &context, 4, &id);
    threads &= thread != nullptr && id != 0 && id != platform_current_thread_id();
    if (thread) {
        threads &= platform_thread_priority(thread, 0) != 0;
        void* duplicate = nullptr;
        threads &= platform_duplicate_handle(platform_current_process(), thread,
            platform_current_process(), &duplicate, 0, 0, 2) != 0;
        threads &= platform_resume_thread(thread) == 1;
        events &= file_wait_many_0055fb60(1, &context.done, 5000) == context.done;
        // Join even on a failed event check: the fixture stack must outlive worker.
        threads &= ::WaitForSingleObject(thread, 5000) == WAIT_OBJECT_0;
        platform_enter_critical_section(&context.lock);
        locks &= context.value == 0x12345678 && context.worker_id == id;
        platform_leave_critical_section(&context.lock);
        if (duplicate) threads &= platform_close_handle(duplicate) != 0;
        threads &= platform_close_handle(thread) != 0;
    }
    platform_delete_critical_section(&context.lock);
    events &= file_close_event_0055fc10(automatic) != 0;
    events &= file_close_event_0055fc10(manual) != 0;
    const bool passed = events && pages && threads && locks;
    std::cout << std::boolalpha << "{\"real_win32_events\":" << events
        << ",\"original_page_wrappers\":" << pages
        << ",\"real_suspended_thread\":" << threads
        << ",\"recursive_locks_and_publication\":" << locks
        << ",\"fixture_passed\":" << passed
        << ",\"original_thread_startup_executed\":false,\"game_launch_verified\":false}\n";
    return passed ? 0 : 1;
}
