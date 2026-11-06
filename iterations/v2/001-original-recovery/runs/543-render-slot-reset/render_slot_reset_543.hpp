#pragma once
#include "../540-render-texture-cleanup-reader/render_texture_cleanup_540.hpp"
#include <cstdint>
namespace porsche {
extern std::uint32_t render_texture_slot_count_006a3a44;
extern std::uint32_t render_texture_dirty_006a3a48;
extern std::uint32_t render_texture_pending_006a3a58;
extern std::uint32_t render_texture_arena_006a3a5c;
extern std::uint32_t render_texture_heap_id_006a3a60;
extern std::uint32_t render_texture_epoch_006a3a64;
void __cdecl render_texture_invalidate_00555330();
void __cdecl render_texture_reset_00555390();
void __cdecl render_texture_arena_release_00555400();
}
