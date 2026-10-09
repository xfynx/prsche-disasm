#pragma once

#include <cstdint>

namespace porsche {

// State with no other recovered native owner yet. These names map one-to-one
// to the original addresses used by the cleanup cluster.
extern void* window_shutdown_handle_0069dd18;
extern std::uint8_t& window_shutdown_mode_005de630;
extern std::uint32_t& window_shutdown_state_005de64c;
extern std::uint32_t window_shutdown_state_005de67c;
extern std::uint32_t window_shutdown_state_005de6ac;
extern std::uint32_t window_shutdown_config_005de620[12];
extern std::uint8_t window_shutdown_source_005de65c;
extern std::uint8_t window_shutdown_source_005de65d;

// Exact typed indirect-call boundaries used by 00534430.
std::uint32_t __stdcall window_shutdown_close_handle_006bd92c(void* handle);
void __stdcall window_shutdown_display_callback_006bd9b0(std::uint32_t mode);

void __cdecl window_shutdown_runtime_state_00534430();
std::uint32_t __cdecl window_shutdown_prepare_00534550();
void __cdecl window_shutdown_process_exit_00557370();

// 0053bae0 is called from the timer table as TimedCallback(context, elapsed),
// but the original body ignores both stack arguments.
std::uint32_t __cdecl window_shutdown_callback_0053bae0(
    std::uint32_t callback_context, std::uint32_t elapsed);

}
