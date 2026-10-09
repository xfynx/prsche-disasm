#pragma once
#include "porsche/startup.hpp"
#include <cstdint>

namespace porsche {
// Exact entry at 004b6a50..004b6fe5. This implements the caller's control
// flow; unknown subsystem consumers remain typed boundaries below.
std::int32_t __cdecl app_main_004b6a50(std::int32_t argc,char** argv);

// Canonical globals owned by other recovered modules or pending arena wiring.
extern std::uint32_t global_006573e8;
extern std::uint32_t global_00657424,global_00657428,global_0065743c;
extern std::uint32_t global_006577d8,global_006577dc;
extern std::uint32_t global_00657a60;
extern std::uint8_t global_00657a64,global_00657e34;
extern std::uint32_t global_00606a88,global_00606874;
extern std::uint32_t global_005e99f4;
// Original consumers test the first byte and scan to NUL; no extent proved.
extern char global_00657a84[];

// 0053c290 is deliberately a boundary here: its original span starts at
// 006573e8 and covers 0x3e24 bytes of the FE arena, whose aliases are not yet
// unified in the host build.
void __cdecl application_main_fill_fe_arena_0053c290(std::uint32_t va,
    std::uint32_t value,std::uint32_t bytes);

// Unrecovered consumers, with argument shape taken from the call sites.
std::uint32_t __cdecl application_main_memory_dialog(const char* text,const char* title);
void __cdecl application_main_create_directory(std::uint32_t path_va);
void __cdecl application_main_setup_heaps(std::uint32_t bytes,std::uint32_t reserve);
void __cdecl application_main_log(const char* text);
std::int32_t __cdecl application_main_setup_context(void* context);
std::int32_t __cdecl application_main_game_setup(void* context,const char* name,
    std::uint32_t* stream,std::uint32_t zero);
void __cdecl application_main_setup_finish(void* context);
void __cdecl application_main_front_end_display(std::uint32_t* stream);
void __cdecl application_main_network_poll(std::uint32_t a,std::uint32_t b);
void __cdecl application_main_network_wait(std::uint32_t a,std::uint32_t b,std::uint8_t* state);
void __cdecl application_main_network_action(std::int32_t a,std::int32_t b);
void __cdecl application_main_function_0048dad0();
void __cdecl application_main_function_0048e6f0();
void __cdecl application_main_function_004dd600();
void __cdecl application_main_function_004b67b0();
void __cdecl application_main_function_004b68f0();
void __cdecl application_main_function_004a4a70(std::uint32_t zero);
void __cdecl application_main_function_004acb80();
void __cdecl application_main_function_004a88a0();
void __cdecl application_main_function_00471b60();
void __cdecl application_main_function_00414eb0();
void __cdecl application_main_function_004640b0();
void __cdecl application_main_function_00413ea0();
void __cdecl application_main_function_004a6e30();
void __cdecl application_main_function_0048cdf0();
void __cdecl application_main_function_00425780();
void __cdecl application_main_function_005366e0(std::uint32_t zero);
void __cdecl application_main_function_004152e0();
void __cdecl application_main_function_00412030();
void __cdecl application_main_function_004a6960();
void __cdecl application_main_function_00563d30();
void __cdecl application_main_function_004a54b0();
void __cdecl application_main_function_00467740();
void __cdecl application_main_function_004a54e0();
}
