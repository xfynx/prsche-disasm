#pragma once

#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Owned .data strings (005d0738..005d078d, only referenced by 0048cdf0).
extern char network_sync_abort_str_005d0738[7];
extern char network_sync_wait_low2_str_005d0740[17];
extern char network_sync_wait_low1_str_005d0754[17];
extern char network_sync_wait_high2_str_005d0768[18];
extern char network_sync_wait_high1_str_005d077c[18];

std::uint32_t __cdecl startup_input_poll_key_0055ff60();
void __fastcall application_network_message_short_0048d350(
    void* receiver, void* edx_unused, std::uint32_t message,
    std::uint32_t first, std::uint32_t second, std::uint32_t fourth);
bool __fastcall network_sync_barrier_0048cdf0(void* self, void* edx_unused);

// Canonical __cdecl frontier entry points declared in application_main.hpp and startup_sequence.hpp.
void __cdecl application_main_function_0048cdf0();
void __cdecl startup_sequence_call_0048cdf0();
} // namespace porsche
