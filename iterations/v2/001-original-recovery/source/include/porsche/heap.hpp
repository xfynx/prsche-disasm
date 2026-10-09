#pragma once
#include "porsche/fe_stream.hpp"
#include "porsche/shared_runtime_globals.hpp"

namespace porsche {
struct HeapBlock {
    std::uint16_t magic, flags;
    std::int32_t bytes;
    HeapBlock *next, *previous;
};
struct HeapFreeBlock { HeapBlock block; HeapBlock *free_next, *free_previous; };
struct OriginalHeap {
    char name[8];
    void *low, *high;
    HeapFreeBlock sentinel;
    std::uint32_t quantum, arena_alignment, suffix, flags;
    void* lock;
    void* callback;
};
static_assert(sizeof(HeapBlock)==16 && sizeof(HeapFreeBlock)==24 && sizeof(OriginalHeap)==64);
static_assert(offsetof(OriginalHeap, quantum)==0x28 && offsetof(OriginalHeap, lock)==0x38);
extern OriginalHeap* heaps_006b4f20[16];
extern std::int32_t (__cdecl* allocation_failure_0069cb00)(const char*, std::int32_t, std::uint32_t);
extern std::uint32_t copy_flag_005deb18, copy_flag_005deb10, copy_flag_005deb30;

std::int32_t __cdecl heap_extra_00531c60(const char*, std::uint32_t);
std::int32_t __cdecl heap_block_005320b0(HeapBlock*, const char*, std::int32_t, std::int32_t,
                                      std::uint16_t, HeapBlock*, HeapBlock*);
std::int32_t __cdecl heap_suffix_00556620(std::uint32_t);
const char* __cdecl heap_name_00556650(void*);
std::int32_t __cdecl heap_init_005697f0(std::uint32_t, const char*, void*, std::int32_t,
    std::uint32_t, std::uint32_t, std::int32_t, std::int32_t, std::uint32_t,
    std::int32_t, std::int32_t, void*);
void* __cdecl heap_word_0056e2c0(void*, std::uint32_t, std::int32_t);
std::uint64_t __cdecl heap_copy_005b0000(void*, const void*, std::uint32_t);
void __cdecl heap_copy_dispatch_005323e0(void*, const void*, std::uint32_t);

// Unrecovered OS/CRT and optimized-copy boundaries; no substitute in the library.
void __cdecl heap_enter_005322b0(void*);
void __cdecl heap_leave_005322c0(void*);
void* __cdecl heap_lock_create_005321f0();
void __cdecl heap_format_005a0fbf(char*, const char*, const char*);
void __cdecl heap_fill_0053c290(void*, std::uint32_t, std::uint32_t);
void __cdecl heap_copy_005b0100(void*, const void*, std::uint32_t);
void __cdecl heap_copy_005b02c0(void*, const void*, std::uint32_t);
void __cdecl heap_copy_005b0480(void*, const void*, std::uint32_t);
}
