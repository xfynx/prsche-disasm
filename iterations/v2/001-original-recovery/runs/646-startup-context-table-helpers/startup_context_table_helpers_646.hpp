// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_alloc.hpp"
#include "porsche/context_effects.hpp"
#include "frame_service_290.hpp"

namespace porsche {

// 4-byte loader-zero .data pointer cell at original VA 0x00628bac..0x00628baf.
extern void* startup_context_table_00628bac;

// Original 0044b830..0044b8b7 (136B, __thiscall, ret 8):
// Searches the two-DWORD-keyed tree whose sentinel header pointer sits at
// *(void**)tree, writes the matched node (or sentinel on miss) to *out_node,
// and returns out_node.
void** __fastcall startup_context_tree_find_0044b830(
    void* tree, void* unused_edx, void** out_node, const std::uint32_t* key_pair);

// Original 0044d320..0044d374 (85B, __thiscall, ret 8):
// Queries *(void**)((uint8_t*)self + 0x08) via 0044b830 for (key0, key1) and
// returns *(void**)((uint8_t*)node + 0x18) on match or nullptr on sentinel miss.
void* __fastcall startup_context_table_lookup_0044d320(
    void* self, void* unused_edx, std::uint32_t key0, std::uint32_t key1);

// Original 0047f040..0047f189 (330B, __cdecl, ret 0):
// Lazily allocates startup_context_table_00628bac (0xcc bytes) and its vector
// field at +0xa4 (0x0c bytes), reserving capacity from
// (*(frame_service_root_00628960 + 0x10) + 0x88) via 004211d0.
void __cdecl startup_context_table_init_0047f040();

} // namespace porsche
