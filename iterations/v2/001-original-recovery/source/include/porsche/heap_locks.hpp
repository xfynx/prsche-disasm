#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0x005321f0..0x005322f6: 32-byte pool cells, first 24 bytes are a Win32
// CRITICAL_SECTION, word +0x18 is the free-list link, +0x1c is the FREE tag.
struct HeapLockCell {
    std::uint8_t critical_section[24];
    HeapLockCell* next;
    std::uint32_t free_tag;
};
static_assert(sizeof(HeapLockCell)==32);
extern HeapLockCell* heap_lock_free_0069cb04;
extern std::uint32_t heap_lock_pool_count_005de000;

void __cdecl heap_lock_pool_grow_00532250();
void __cdecl heap_lock_destroy_005322d0(void*);

// Typed OS boundaries; native probe records these Win32 calls in order.
void __stdcall platform_initialize_critical_section(void*);
void __stdcall platform_enter_critical_section(void*);
void __stdcall platform_leave_critical_section(void*);
void __stdcall platform_delete_critical_section(void*);
}
