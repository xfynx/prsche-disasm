#pragma once
#include <cstdint>

namespace porsche {
extern void* startup_direct_input_006a5b14;
extern void* startup_keyboard_device_006a5b18;
extern std::uint32_t startup_input_initialized_006a5b1c;
extern std::uint32_t startup_input_cleanup_registered_006a5b20;
extern void* startup_input_key_callback_005df6a4;

// Shared original state owned by the window input/message module.
extern std::uint32_t worker_accelerator_006bd9dc;
extern std::uint32_t window_input_capacity_0069e560;
extern std::uint32_t window_input_read_0069e0d8;
extern std::uint32_t window_input_write_0069e568;
extern void* class_lock_0069e59c;
extern void*& window_hwnd_006b7bf8;

std::uint32_t __cdecl startup_input_initialize_0055fcf0();
void __cdecl startup_input_release_0055fe00();
void __cdecl startup_input_exit_cleanup_0055fe40();
std::uint32_t __cdecl startup_input_set_key_state_0055fe50(std::uint32_t,
                                                            void*);
void* __cdecl startup_window_handle_00557460();

void* __stdcall startup_input_get_module_handle();
std::int32_t __stdcall startup_input_direct_input_create(void*,std::uint32_t,
                                                          void**,void*);
void __cdecl thread_exit_register_00557380(void(__cdecl*)());
void* __cdecl heap_lock_create_005321f0();
}
