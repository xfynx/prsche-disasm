#pragma once
#include <cstdint>

namespace porsche {
extern std::uint32_t exit_shutdown_mode_word_006afce0;
extern std::uint32_t exit_shutdown_started_006afce4;
extern std::uint32_t exit_shutdown_process_state_006afce8;

void __cdecl exit_shutdown_execute_005a2490(std::uint32_t code,std::int32_t skip_exit_callbacks,
    std::uint32_t return_after_callbacks);
void __cdecl exit_shutdown_walk_range_005a2547(void(__cdecl** begin)(),void(__cdecl** end)());

// Unrecovered OS and static callback bodies are explicit boundaries.
void* __cdecl exit_shutdown_get_current_process();
std::int32_t __cdecl exit_shutdown_terminate_process(void* process,std::uint32_t code);
void __cdecl exit_shutdown_exit_process(std::uint32_t code);
void __cdecl exit_shutdown_static_callback_005a36d6();
void __cdecl exit_shutdown_static_callback_005ac147();
}
