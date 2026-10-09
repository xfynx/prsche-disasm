#include "porsche/heap_locks.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/files.hpp"
#include <cstdint>

namespace porsche {
HeapLockCell* heap_lock_free_0069cb04=nullptr;
std::uint32_t heap_lock_pool_count_005de000=32;

// 00532250: caller-supplied byte count can be rounded by the allocator.
void __cdecl heap_lock_pool_grow_00532250(){
    std::uint32_t bytes=heap_lock_pool_count_005de000<<5;
    auto* previous=heap_lock_free_0069cb04;
    auto* cells=static_cast<HeapLockCell*>(file_object_allocate_0056e5f0(&bytes));
    heap_lock_free_0069cb04=cells;
    if(!cells)return;
    const auto count=bytes>>5;
    heap_lock_pool_count_005de000=count;
    auto* cell=cells;
    for(std::int32_t i=0;i<static_cast<std::int32_t>(count);++i){
        cell->next=previous;
        cell->free_tag=0x46524545u;
        previous=cell;
        cell=reinterpret_cast<HeapLockCell*>(reinterpret_cast<std::uint8_t*>(cell)+32);
    }
    heap_lock_free_0069cb04=previous;
}

// 005321f0: preserve bootstrap, free-list removal, fill and OS call order.
void* __cdecl heap_lock_create_005321f0(){
    if(!threads_initialized_006a57dc)thread_init_0055f320(0);
    auto* cell=heap_lock_free_0069cb04;
    if(!cell){
        heap_lock_pool_grow_00532250();
        cell=heap_lock_free_0069cb04;
        if(!cell)return nullptr;
    }
    heap_lock_free_0069cb04=cell->next;
    heap_fill_0053c290(cell,0,24);
    platform_initialize_critical_section(cell);
    return cell;
}

void __cdecl heap_enter_005322b0(void* lock){platform_enter_critical_section(lock);}
void __cdecl heap_leave_005322c0(void* lock){platform_leave_critical_section(lock);}

// 005322d0: null is ignored; DeleteCriticalSection precedes pool relinking.
void __cdecl heap_lock_destroy_005322d0(void* lock){
    if(!lock)return;
    auto* cell=static_cast<HeapLockCell*>(lock);
    platform_delete_critical_section(cell);
    cell->free_tag=0x46524545u;
    cell->next=heap_lock_free_0069cb04;
    heap_lock_free_0069cb04=cell;
}
}
