#pragma once
#include <cstdint>
#include "porsche/window_create.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {
using WindowMessageRect = WindowWorkerRect;

// Native/Win32 and game-service boundaries observed at the original call sites.
std::uint32_t __stdcall window_message_get_client_rect(void*, WindowMessageRect*);
std::uint32_t __stdcall window_message_client_to_screen(void*, WindowMessageRect*);
std::uint32_t __cdecl window_message_enqueue_0053a9e0(std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t __cdecl window_message_mouse_event_005728b0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t __stdcall window_message_begin_paint(void*,void*);
std::uint32_t __stdcall window_message_end_paint(void*,void*);
std::uint32_t __cdecl window_message_pump_005322b0(std::uint32_t);
std::uint32_t __cdecl window_message_dispatch_005322c0(std::uint32_t);
bool window_message_has_resize_notification_005df9b8();
std::uint32_t __cdecl window_message_resize_notification_005df9b8();
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t);
extern std::uint8_t window_virtual_key_state_005de028[256];
extern void*& window_paint_lock_006a57d8;

// Recovered original registered callbacks, each with six stdcall arguments/RET 18.
std::uint32_t __stdcall window_message_0053b360(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_message_0053b3d0(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_message_0053b6b0(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_message_0053b710(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_message_0053b770(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_message_0053b7d0(void*,void*,std::uint32_t,std::uint32_t,std::int32_t,std::int32_t*);

// Resize helpers used by window creation and WM_SIZE. All use stdcall/cdecl as
// indicated by the original call sites.
std::uint32_t __cdecl window_message_resize_0053bd40(std::int32_t,std::int32_t,std::int32_t,std::int32_t,std::int32_t,std::int32_t,std::int32_t,std::int32_t);
void __cdecl window_message_center_0053bec0(std::int32_t,std::int32_t);
}
