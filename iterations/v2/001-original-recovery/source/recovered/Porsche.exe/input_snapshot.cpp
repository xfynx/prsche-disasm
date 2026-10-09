#include "porsche/input_snapshot.hpp"

#include "porsche/heap.hpp"
#include "porsche/input_buffer.hpp"
#include "porsche/input_state.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_event_translation.hpp"

#include <cstdlib>
#include <cstring>

namespace porsche {

InputSnapshotStorage input_snapshot_storage_006a57f0{};
InputSnapshotDiagnosticBoundary input_snapshot_diagnostic_boundary = nullptr;

std::uint8_t* input_snapshot_keyboard_bytes_006a5a14() noexcept {
    return input_snapshot_storage_006a57f0.keyboard_return_view_006a5a10 + 4;
}

void* input_snapshot_keyboard_return_006a5a10() noexcept {
    return input_snapshot_storage_006a57f0.keyboard_return_view_006a5a10;
}

std::uint8_t* input_snapshot_capabilities_006a57f0() noexcept {
    return input_snapshot_storage_006a57f0.capabilities_006a57f0;
}

void* __cdecl input_snapshot_getstate_0055feb0(std::int32_t selector) {
    if (selector == 2) {
        if (startup_direct_input_006a5b14 &&
            input_caps_0056fdb0(
                static_cast<InputBufferDevice*>(startup_keyboard_device_006a5b18),
                input_snapshot_capabilities_006a57f0()) == 0) {
            return input_snapshot_capabilities_006a57f0();
        }
    } else {
        if (selector != 6) {
            diagnostic_file_005deb74_set("\\real\\patch3\\pc\\key.c");
            application_diagnostic_line_005deb78 = 0x1bb;
            if (!input_snapshot_diagnostic_boundary) std::abort();
            input_snapshot_diagnostic_boundary(
                "[KEY] - Invalid getstate (%d)\n", selector);
            return nullptr;
        }
        if (startup_direct_input_006a5b14) {
            const auto result = input_poll_read_0056fce0(
                static_cast<InputDevice*>(startup_keyboard_device_006a5b18),
                input_snapshot_keyboard_bytes_006a5a14(), 0x100);
            if (result != 0)
                heap_fill_0053c290(input_snapshot_keyboard_bytes_006a5a14(), 0, 0x100);
            return input_snapshot_keyboard_return_006a5a10();
        }
    }
    return nullptr;
}

const std::uint8_t* __cdecl window_event_key_state_0055feb0(std::uint32_t selector) {
    std::int32_t signed_selector;
    static_assert(sizeof(signed_selector) == sizeof(selector));
    std::memcpy(&signed_selector, &selector, sizeof(selector));
    return static_cast<const std::uint8_t*>(input_snapshot_getstate_0055feb0(signed_selector));
}

} // namespace porsche
