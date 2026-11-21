#pragma once

#include <cstdint>

namespace porsche {

// Owned storage cells. Neither VA has a canonical owner in
// source/recovered/functions.json or in any accepted run source; these two
// roots are written only by the bodies recovered in this packet (and read by
// their matching release leaves 0043eda0 / 00455ff0).
extern void* scene_stage_root_006115c0;
extern void* scene_stage_root_00627dfc;

// Original VAs 0043ed00 / 00455f60 (cdecl void(), RET 0). Both bodies store
// (entry_ECX >> 24) & 0xff into the byte at offset 8 of a freshly allocated
// 0x0c-byte holder. The sole caller 00468fb0 leaves ECX = 0 (proved from the
// tail of 004552b0), so the production byte is 0; the snapshot keeps the exact
// machine behavior for arbitrary entry ECX.
void __cdecl scene_stage_reset_0043ed00();
void __cdecl scene_stage_reset_00455f60();

} // namespace porsche
