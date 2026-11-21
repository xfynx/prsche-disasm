// Test-only call subsequence, compiled at both /Od and /O2 by shared runner.
// Explicit core input substitutes only the four opaque original stack bytes.
#include "scene_stage_stack_core_721.hpp"
#include "scene_stage_reset_716.hpp"
extern "C" __declspec(noinline) void __cdecl scene_stage_chain_721(unsigned char* bytes) {
    porsche::scene_stage_stack_core_004552b0(bytes);
    porsche::scene_stage_reset_0043ed00();
    porsche::scene_stage_reset_00455f60();
}
