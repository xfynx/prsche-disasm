#pragma once
#include <cstdint>

namespace porsche {
// Research ownership candidates only; this packet is not on the game graph.
extern void* scene_stage_tree_root_00627df0;
extern void* scene_stage_group_root_006221d8;
extern std::uint32_t scene_stage_matrix_00624de8[256][8];

void* __fastcall scene_stage_tree_ctor_00455830(
    void* self, void* unused_edx, unsigned char* first, unsigned char* second);
void __fastcall scene_stage_tree_load_00455570(void* slot, void* unused_edx);
void* __fastcall scene_stage_tree_ctor_004558b0(
    void* self, void* unused_edx, unsigned char* first, unsigned char* second);
void* __fastcall scene_stage_group_ctor_0059f070(void* self, void* unused_edx);

// Explicit image of original four never-written stack bytes E-0x24..E-0x21.
// This is not a production void004552b0 provider. It returns ECX=0, as original.
void __cdecl scene_stage_stack_core_004552b0(unsigned char* original_stack_bytes);
}
