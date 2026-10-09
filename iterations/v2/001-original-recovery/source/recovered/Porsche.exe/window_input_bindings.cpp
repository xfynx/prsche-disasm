#include "porsche/window_input_bindings.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_runtime.hpp"
#include <cstdlib>

namespace porsche {
std::uint32_t window_resize_count_006a5c2c = 0;
WindowResizeNotification window_resize_notification_pointer_005df9b8 =
    &window_resize_counter_005654d0;

// Complete original body: INC DWORD PTR [006a5c2c]; RET. EAX is unchanged
// and ignored by all indexed callers; the modern void signature says so.
void __cdecl window_resize_counter_005654d0() {
    ++window_resize_count_006a5c2c;
}
bool window_message_has_resize_notification_005df9b8() {
    return window_resize_notification_pointer_005df9b8 != nullptr;
}
std::uint32_t __cdecl window_message_resize_notification_005df9b8() {
    window_resize_notification_pointer_005df9b8();
    return 0; // Adapter result only; the original callers ignore EAX.
}

namespace {
// Only the 128 bytes consumed by (lParam >> 16) & 0x7f are represented.
// This is not a claim about the full original data object's extent.
constexpr std::uint8_t scan_translation_005df934[128] = {
#include "window_scan_translation.inc"
};
}
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t scan) {
    if(scan >= 128)std::abort(); // Outside the proven original caller domain.
    const auto table = window_channels_initialized_0069e5a0;
    if(table == 0)return static_cast<std::uint8_t>(scan);
    if(table != 0x005df934)std::abort(); // Unresolved guest data pointer.
    return scan_translation_005df934[scan];
}
}
