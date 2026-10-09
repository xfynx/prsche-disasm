#pragma once
#include <cstdint>
#include "porsche/window_create.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/window_runtime.hpp"

namespace porsche {
struct WindowWorkerRect { std::int32_t left, top, right, bottom; };
struct WindowWorkerMessage {
    void* hwnd;
    std::uint32_t message;
    std::uint32_t wparam;
    std::int32_t lparam;
    std::uint32_t time;
    std::int32_t x, y;
};
static_assert(sizeof(WindowWorkerMessage)==28,"original x86 MSG");

// Mutable original state consumed by 0053b8d0. These are test identities for
// the original VAs; they are not fixed-address globals in the native probe.
extern std::uint32_t worker_message_state_0069e578;
extern std::int32_t& window_pos_x_006b7c08;
extern std::int32_t& window_pos_y_006b7c0c;
extern std::uint32_t worker_callback_0069e5a4;
extern std::uint32_t worker_accelerator_006bd9dc;

// Original Win32 calls and not-yet-recovered game helpers are explicit probe
// boundaries. Signatures follow the x86 call sites and USER32 imports.
std::uint32_t __cdecl window_worker_wait_0055fb20();
std::uint32_t __cdecl window_worker_wait_0055fb90(std::uint32_t);
std::uint32_t __cdecl window_worker_wait_0055fc10(std::uint32_t);
std::uint32_t __stdcall window_worker_get_client_rect(void*,WindowWorkerRect*);
std::uint32_t __stdcall window_worker_client_to_screen(void*,WindowWorkerRect*);
std::int32_t __stdcall window_worker_get_message(WindowWorkerMessage*,void*,std::uint32_t,std::uint32_t);
std::uint32_t __stdcall window_worker_translate_message(const WindowWorkerMessage*);
std::int32_t __stdcall window_worker_dispatch_message(const WindowWorkerMessage*);
std::int32_t __stdcall window_worker_is_iconic(void*);
std::int32_t __stdcall window_worker_show_cursor(std::int32_t);
void* __stdcall window_worker_get_foreground_window();
void* __stdcall window_worker_set_foreground_window(void*);
void* __stdcall window_worker_set_active_window(void*);
std::uint32_t __cdecl window_worker_game_pump_005322b0(std::uint32_t);
std::uint32_t __cdecl window_worker_game_dispatch_005322c0(std::uint32_t);
std::uint32_t __cdecl window_worker_accelerator_0053b530(std::uint32_t,std::uint32_t);
std::uint32_t __cdecl window_worker_activation_00565560();
std::uint32_t __cdecl window_worker_focus_00573980();
void __cdecl window_worker_callback();
std::uint32_t __cdecl window_worker_idle_callback(std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t __stdcall window_worker_destroy_window(void*);
std::uint32_t __cdecl window_worker_prepare_exit_00558350(void*);
std::uint32_t __cdecl window_worker_0053b8d0(void* configuration);
}
