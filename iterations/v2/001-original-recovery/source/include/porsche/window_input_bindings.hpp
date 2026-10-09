#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
extern std::uint32_t window_resize_count_006a5c2c;
using WindowResizeNotification = void(__cdecl*)();
extern WindowResizeNotification window_resize_notification_pointer_005df9b8;
void __cdecl window_resize_counter_005654d0();
}
