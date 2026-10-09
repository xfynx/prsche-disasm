#pragma once
#include <cstdint>
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_state.hpp"

namespace porsche {
// Porsche.exe 0x53ac20..0x53ad23 registration prefix only.
// The original window procedure 0x53aba0 remains an explicit boundary.
struct OriginalWndClassA {
    std::uint32_t style;
    void* procedure;
    std::int32_t class_extra;
    std::int32_t window_extra;
    void* instance;
    void* icon;
    void* cursor;
    void* background;
    const char* menu_name;
    const char* class_name;
};
static_assert(sizeof(OriginalWndClassA)==40,"original x86 WNDCLASSA");
extern void* class_lock_0069e59c;
extern std::uint32_t class_refcount_0069e594;
extern const char** class_name_override_006afcc0;

void* __cdecl window_lock_create_005321f0();
void* __stdcall window_module_handle(const char*);
void* __stdcall window_load_icon(void*,const char*);
void* __stdcall window_load_cursor(void*,const char*);
void* __stdcall window_stock_object(std::int32_t);
std::uint16_t __stdcall window_register_class(const OriginalWndClassA*);
std::uint32_t __stdcall window_last_error();
void __cdecl window_register_diagnostic(const char*,std::uint32_t);
std::int32_t __stdcall window_procedure_0053aba0(void*,std::uint32_t,std::uint32_t,std::int32_t);

// Returns whether the execution reaches 0x53ad23; on registration failure
// the original returns zero from the entire 0x53ac20 function.
bool __cdecl window_register_prefix_0053ac20();

extern std::uint32_t window_handlers_registered_0069e598;
extern void* window_input_lock_0069e564;
extern std::uint32_t window_input_capacity_0069e560;
extern std::uint32_t window_input_read_0069e0d8;
extern std::uint32_t window_input_write_0069e568;
extern std::uint32_t& window_running_006b7c14;
extern std::uint32_t& window_width_006b77b4;
extern std::uint32_t& window_height_006b77b8;
extern std::uint8_t& window_fullscreen_006b7c01;
extern void* window_thread_handle_0069e574;
extern void*& window_hwnd_006b7bf8;
extern std::uint32_t window_worker_state_006bd9e0[7];
extern std::uint32_t window_saved_parameter_0069e57c;
extern std::uint32_t window_saved_parameter_0069e580;

std::uint32_t __stdcall window_handler_register_0053a800(std::uint32_t,std::uint32_t);
void __cdecl window_resize_0053bec0(std::uint32_t,std::uint32_t);
std::uint32_t __cdecl window_worker_0053b8d0();
void __cdecl window_worker_thread_entry();
std::uint32_t __cdecl window_thread_start_0055f420(void*,std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t*);
std::uint32_t __cdecl window_timed_callback_005366e0(std::uint32_t);
void __cdecl window_idle_0055f740(std::uint32_t);
void __cdecl window_prepare_0053bcb0();
void __cdecl window_thread_wait_0055fb30(void*);
void* __stdcall window_set_foreground(void*);
std::uint32_t __stdcall window_system_parameters(std::uint32_t,std::uint32_t,void*,std::uint32_t);
std::uint32_t __cdecl window_init_0053ac20(std::uint32_t width,std::uint32_t height,std::uint32_t fullscreen);
}
