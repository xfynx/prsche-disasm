#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 005366e0 is the timed-callback consumer, despite its many UI callers.
using TimedCallback = std::uint32_t (__cdecl *)(std::uint32_t, std::uint32_t);
struct TimedCallbackSlot {
    TimedCallback callback;             // 0069dd20 + 16*n
    std::uint32_t period;               // +4
    std::uint32_t next_tick;            // +8
    std::uint32_t active;               // +12
};
static_assert(sizeof(TimedCallbackSlot) == 16, "original x86 callback slot");
extern TimedCallbackSlot timed_callbacks_0069dd20[16];
extern std::uint32_t last_callback_tick_0069de24;
extern std::uint32_t current_tick_006b7c40;
std::uint32_t __cdecl timed_callbacks_005366e0(std::uint32_t argument);
std::uint32_t __cdecl startup_noop_005367b0(std::uint32_t, std::uint32_t, std::uint32_t);

struct WindowRect { std::int32_t left, top, right, bottom; };
extern std::uint32_t window_style_005dea88;
extern std::uint8_t window_style_flag_005dead4;
extern std::uint32_t window_override_0069e5b0;
extern std::int32_t window_override_x_006bda00;
extern std::int32_t window_override_y_006bda04;
extern const char* window_class_name_0069e5a8;
extern void* window_instance_006b7794;
extern std::uint32_t window_create_state_005de024;
extern std::uint32_t window_channels_initialized_0069e5a0;

// Exact Win32 and unrecovered callee boundaries of 0053bb00.
std::int32_t __stdcall window_get_system_metrics(std::int32_t);
std::uint32_t __stdcall window_adjust_rect(WindowRect*, std::uint32_t, std::int32_t, std::uint32_t);
void* __stdcall window_create_ex(std::uint32_t,const char*,const char*,std::uint32_t,
    std::int32_t,std::int32_t,std::int32_t,std::int32_t,void*,void*,void*,void*);
void* __stdcall window_set_cursor(void*);
std::int32_t __stdcall window_show_cursor(std::int32_t);
void __cdecl window_channel_005739b0(std::uint32_t,std::uint32_t);
void* __cdecl window_create_0053bb00(void* configuration);
}
