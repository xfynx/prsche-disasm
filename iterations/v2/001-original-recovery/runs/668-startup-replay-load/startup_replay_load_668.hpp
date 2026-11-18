// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/startup_sequence.hpp"

namespace porsche {

// Owned BSS globals in Porsche.exe .data virtual tail.
extern std::uint32_t replay_state_005e99fc;
extern std::uint32_t replay_snapshot_005e9a20[application_state_word_count];
extern std::uint32_t replay_tail_word_005ed844;
extern std::uint32_t replay_saved_word_00606a80;
extern std::uint32_t replay_mode_flag_00606858;
extern char replay_filename_00699f34[128];

// Owned read-only string literals in Porsche.exe .data (single ref each in 004146f0).
extern const char replay_msg_file_loaded_005cc698[16];
extern const char replay_msg_default_loaded_005cc6a8[24];
extern const char replay_msg_no_replay_005cc6c0[26];
extern const char replay_msg_loading_default_005cc6dc[31];

// Original 004146f0..0041480b (284B, __cdecl, ret 0).
void __cdecl replay_load_004146f0();

// Canonical definition provided here for porsche/startup_sequence.hpp:
// - startup_sequence_call_00413cf0 (00413cf0..00413e93, 420B, __cdecl, ret 0)

} // namespace porsche
