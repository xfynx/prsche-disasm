// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005756d0..005756da (11B), 005756e0..00575726 (71B),
// 00575730..0057576c (61B), 00575770..005757c3 (84B), 005757d0..005757e6 (23B).
#include "render_window_callbacks_631.hpp"

#include <cstdint>
#include <cstring>

#include "../549-render-diagnostic/render_diagnostic_549.hpp"
#include "../628-render-window-initialize/render_window_initialize_628.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_input_bindings.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_support.hpp"

namespace porsche {

alignas(4) extern const std::uint8_t render_window_ddraw2_iid_005bef50[16] = {
    0xe0u, 0xf3u, 0xa6u, 0xb3u, 0x43u, 0x2bu, 0xcfu, 0x11u,
    0xa2u, 0xdeu, 0x00u, 0xaau, 0x00u, 0xb9u, 0x33u, 0x56u,
};

void __cdecl render_window_callback_005756d0() {
    (void)timed_callbacks_005366e0(0u);
}

std::uint32_t __stdcall render_window_callback_005756e0(std::uint32_t arg) {
    auto* const storage = reinterpret_cast<std::uint8_t*>(&window_configuration_storage_006b77a0);
    if (arg != 0u) {
        using QueryInterfaceFn = std::uint32_t(__stdcall*)(void*, const void*, void**);
        void* const self = reinterpret_cast<void*>(static_cast<std::uintptr_t>(arg));
        void* const* vtable = nullptr;
        std::memcpy(&vtable, self, sizeof(vtable));
        const auto query_interface = reinterpret_cast<QueryInterfaceFn>(vtable[0]);
        const std::uint32_t hr = query_interface(
            self,
            render_window_ddraw2_iid_005bef50,
            reinterpret_cast<void**>(storage));
        if (hr != 0u) {
            return hr;
        }
        std::uint32_t counter = 0u;
        std::memcpy(&counter, storage + 0x470u, sizeof(counter));
        ++counter;
        std::memcpy(storage + 0x470u, &counter, sizeof(counter));
        return 0u;
    }

    using ReleaseFn = std::uint32_t(__stdcall*)(void*);
    void* obj = nullptr;
    std::memcpy(&obj, storage, sizeof(obj));
    void* const* vtable = nullptr;
    std::memcpy(&vtable, obj, sizeof(vtable));
    const auto release = reinterpret_cast<ReleaseFn>(vtable[2]);
    (void)release(obj);

    std::uint32_t counter = 0u;
    std::memcpy(&counter, storage + 0x470u, sizeof(counter));
    void* const null_obj = nullptr;
    std::memcpy(storage, &null_obj, sizeof(null_obj));
    ++counter;
    std::memcpy(storage + 0x470u, &counter, sizeof(counter));
    return counter;
}

void __stdcall render_window_callback_00575730(std::uint32_t arg) {
    if (arg != 0u) {
        heap_enter_005322b0(thread_start_lock_006a57d8);
        window_support_opaque_value_006a64a0 = 1u;
        return;
    }
    window_support_opaque_value_006a64a0 = 0u;
    heap_leave_005322c0(thread_start_lock_006a57d8);
}

void __stdcall render_window_callback_00575770(std::uint32_t arg0, std::uint32_t arg1) {
    const char* const text = reinterpret_cast<const char*>(static_cast<std::uintptr_t>(arg1));
    switch (arg0) {
    case 0u:
        diagnostic_handler_005debf0(text);
        break;
    case 2u:
        render_texture_diagnostic_0055ec50(2u, text);
        break;
    case 1u:
    default:
        render_texture_diagnostic_0055ec50(6u, text);
        break;
    }
}

void __stdcall render_window_callback_005757d0(std::uint32_t arg0, std::uint32_t arg1) {
    (void)arg1;
    if (arg0 == 2u && window_resize_notification_pointer_005df9b8 != nullptr) {
        window_resize_notification_pointer_005df9b8();
    }
}

} // namespace porsche
