// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_context_base.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/context_move.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/game_setup.hpp"
#include "startup_sequence_resource_table_649.hpp"

namespace porsche {

// Owned read-only .data format strings (each referenced only by 004dd4a0 in references.jsonl).
// 005d998c..005d9999 (14B): "%sinPC-av.mad\0"
extern const char game_setup_movie_mad_fmt_005d998c[14];
// 005d999c..005d99a9 (14B): "%sporsche.fsh\0"
extern const char game_setup_porsche_fsh_fmt_005d999c[14];

// Loader-zero .data BSS empty name cell defined in files.cpp at VA 005e8e50.
extern char file_null_name_005e8e50[1];

// Original 00472860..004729a0 (321B, __thiscall, ret 8):
// Inserts byte range [first, last) into a 12-byte context string [begin, current, end],
// growing via 004211d0 and releasing old storage (>0x100 via 0059ecd0, else pool freelist).
void* __fastcall context_string_insert_00472860(
    void* self, void* edx_unused, const char* first, const char* last);

// Original 0059e440..0059e64d (526B, __cdecl, ret 0, AL=bool):
// Resolves path (or primary root / fallback root / missing_file_006afbe4 + 005e8e50)
// into 12-byte string object; companion returns the exact AL boolean.
bool __cdecl game_setup_resource_open_result_0059e440(const char* path, void* object);

// Canonical void/cdecl entry points game_setup_resource_open_0059e440 and
// game_setup_movie_004dd4a0 are declared in porsche/game_setup.hpp.

} // namespace porsche
