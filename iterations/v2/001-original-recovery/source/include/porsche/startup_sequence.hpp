#pragma once

#include <cstdint>

namespace porsche {

// Original entry 004b67b0..004b68e6 (311 bytes). It runs the ordered engine
// service sequence and transfers control to 004691c0 at the end.
void __cdecl startup_sequence_004b67b0();

// Existing Run095 boundary, repeated here to keep this standalone target
// independent of unrelated member-function declarations in its header.
void __cdecl splash_progress_004a4a70(std::int32_t phase);

// The two fields are independent original DWORDs, not part of the application
// state arena. 004b67b0 writes both to zero between the phase-2 and service
// initialization calls.
extern std::uint32_t startup_sequence_word_00606ac0;
extern std::uint32_t startup_sequence_word_00606ac4;

// Opaque engine/service callees. Signatures reflect only the observed call
// site ABI and arguments; their algorithms remain outside this recovery.
void __fastcall startup_sequence_service_00536080(void* receiver,
                                                   void* unused_edx);
void __cdecl startup_sequence_call_0044dfb0();
void __cdecl startup_sequence_call_0056a490();
void __cdecl startup_sequence_call_00516950();
void __cdecl startup_sequence_call_00413cf0();
void __cdecl startup_sequence_call_00427a60();
void __cdecl startup_sequence_call_004a4700();
void __cdecl startup_sequence_call_004b0d70();
void __cdecl startup_sequence_call_004affd0();
void __cdecl startup_sequence_call_00468fb0();
void __cdecl startup_sequence_call_00471b70();
void __cdecl startup_sequence_call_004a8cd0();
void __cdecl startup_sequence_call_00414db0();
void __cdecl startup_sequence_call_004690d0();
void __cdecl startup_sequence_call_00434a90();
void __cdecl startup_sequence_call_00424460();
void __cdecl startup_sequence_call_00415dc0();
void __cdecl startup_sequence_call_004b0fa0();
void __cdecl startup_sequence_call_004121b0();
std::uint32_t __cdecl startup_sequence_value_00569a90();
void __cdecl startup_sequence_report_005a177b(std::uint32_t format_va,
                                               std::uint32_t value);
void __cdecl startup_sequence_call_0048cdf0();
void __cdecl startup_sequence_text_0044df10(std::uint32_t text_va);
void __cdecl startup_sequence_transfer_004691c0();

} // namespace porsche
