#include "porsche/window_threads.hpp"
#include "porsche/heap.hpp"

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0055f420..0055f4ee. Shared registry, trampoline and globals are the
// recovered 0055f320/4f0/560/8b0 implementations from file_threads.cpp.
std::uint32_t __cdecl window_thread_start_0055f420(
    void* callback_raw, std::uint32_t stack_and_priority,
    std::uint32_t priority, std::uint32_t unused4, std::uint32_t* output_raw) {
    (void)unused4;
    auto callback=reinterpret_cast<void (__cdecl*)()>(callback_raw);
    auto* output=reinterpret_cast<ThreadRecord*>(output_raw);
    if (!threads_initialized_006a57dc) thread_init_0055f320(0);
    heap_enter_005322b0(thread_start_lock_006a57d8);

    ThreadLaunch launch;
    launch.record = output;
    launch.no_argument = callback;
    launch.worker = nullptr;
    launch.argument = 0;

    std::uint32_t id;
    auto* handle = platform_create_thread(nullptr, stack_and_priority,
        thread_bootstrap_0055f4f0, &launch, 4, &id);
    launch.handshake = handle;
    if (handle) {
        output->stack = stack_and_priority;
        output->priority = priority;
        output->flags = 0;
        thread_register_0055f560(output, handle, id);
        thread_priority_0055f8b0(reinterpret_cast<std::uintptr_t>(output),
                                  priority);
        platform_resume_thread(handle);
        while (launch.handshake) platform_sleep(1, 1);
    }

    heap_leave_005322c0(thread_start_lock_006a57d8);
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle));
}
}
