// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../400-frame-loop-clusters/frame_loop_clusters_400.hpp"
#include "../668-startup-replay-load/startup_replay_load_668.hpp"
#include "porsche/application_services_next.hpp"

namespace porsche {

// Original 00413ea0..00413fc7 (296B, __cdecl, ret 0; void). FE entry-region
// reset leaf on the app_main path (caller porsche::app_main_004b6a50):
// - mode 0/1 (global_005e99f4): clears the 0x6400-dword replay scratch
//   005ed848..00606847, clears fe_loop_word_005e99f8 / replay_state_005e99fc,
//   and copies application state word 0065741c into replay_mode_flag_00606858.
// - mode >= 2: clears replay_state_005e99fc and the fe-loop words
//   00606860..00606870 (00606864 = 2), probes entry_fe_call_0046d960(); on a
//   non-zero probe it refills every audio source object word +0x10e4 from
//   entry_fe_call_0046d890() (state word 006573e8 == 9 skips straight to the
//   0xa/0x14 epilogue, otherwise it walks application_audio_source_storage_005e8bfc
//   cells 1..count), on a zero probe it stores 0xa and issues the (0, 0xa)
//   entry_fe_call_004659e0(0, 0xa) call; every path copies word 0065741c into
//   replay_mode_flag_00606858 and clears 005e9a00/00606854/005e9a04.
// - any other mode (negative): clears 005e9a00/005e9a04 only.
void __cdecl application_main_function_00413ea0();

// Callees unlocked by this batch; still unrecovered in the game link.
// 0046d960 (ret EAX int, __cdecl), 0046d890 (ret EAX uint, __cdecl),
// 00413960 (one pushed dword, __cdecl), 004659e0 (two pushed dwords,
// __cdecl, both call sites push 0 then 0xa).
std::int32_t __cdecl entry_fe_call_0046d960();
std::uint32_t __cdecl entry_fe_call_0046d890();
void __cdecl entry_fe_call_00413960(std::uint32_t value);
void __cdecl entry_fe_call_004659e0(std::uint32_t first, std::uint32_t second);

// Owned zero-initialized .bss cells first defined here (no prior owner in the
// manifest closure; neighbors 005e99f4/005e99fc/005e9a20/005ed844 belong to
// application_main/Run668).
extern std::uint32_t fe_loop_word_005e99f8;
extern std::uint32_t fe_loop_word_005e9a00;
extern std::uint32_t fe_loop_word_005e9a04;
extern std::uint32_t fe_loop_word_00606850;
extern std::uint32_t fe_loop_word_00606854;
extern std::uint32_t fe_loop_word_00606860;
extern std::uint32_t fe_loop_word_00606864;
extern std::uint32_t fe_loop_word_00606868;
extern std::uint32_t fe_loop_word_0060686c;
extern std::uint32_t fe_loop_word_00606870;

// Replay scratch cleared by the STOSD.REP at 00413fa0: 0x6400 dwords from
// 005ed848 up to (excluding) 00606848. Run668 owns the adjacent word
// 005ed844; unrecovered 00413fd0/00414660 read parts of the same buffer.
extern std::uint32_t fe_replay_scratch_005ed848[0x6400];

} // namespace porsche
