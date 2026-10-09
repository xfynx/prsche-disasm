#include "porsche/window_exit_cleanup.hpp"

#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_worker.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {
std::uint32_t __cdecl window_worker_prepare_exit_00558350(void* configuration) {
    window_exit_cleanup_00558350(configuration);
    return 0; // The original worker ignores this void callee's EAX.
}
void __cdecl window_exit_cleanup_00558350(void* configuration) {
    auto* const state = static_cast<std::uint8_t*>(configuration ? configuration
        : static_cast<void*>(&window_configuration_storage_006b77a0));
    auto load = [state](std::size_t offset) {
        return *reinterpret_cast<std::uint32_t*>(state + offset);
    };
    auto store_zero = [state](std::size_t offset) {
        *reinterpret_cast<std::uint32_t*>(state + offset) = 0;
    };

    if (load(0) == 0) return;

    heap_enter_005322b0(thread_start_lock_006a57d8);
    window_exit_object_cleanup_00557990(state);

    const auto object = load(0);
    const auto vtable = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(object));
    using ExitMethod = void (__stdcall *)(void*);
    const auto exit_method = *reinterpret_cast<ExitMethod*>(
        static_cast<std::uintptr_t>(vtable + 8));
    exit_method(reinterpret_cast<void*>(static_cast<std::uintptr_t>(object)));

    const auto allocation = load(0x10);
    if (allocation != 0)
        free_00531f90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(allocation)));

    store_zero(0x10);
    store_zero(4);
    store_zero(0x24);
    store_zero(0);
    heap_leave_005322c0(thread_start_lock_006a57d8);
}
} // namespace porsche
