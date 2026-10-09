#include "porsche/application_pool.hpp"
#include "porsche/disk_open.hpp"
#include "porsche/file_device.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/heap.hpp"

namespace porsche {
void* free_operation_arena_006a5c54=nullptr;
void* application_pool_lock_006a5c78=nullptr;
std::uint32_t application_pool_shutdown_state_006a5c74=0;

// 00557380 is only a cdecl forwarding wrapper; CRT registration is external.
void __cdecl thread_exit_register_00557380(void(__cdecl* callback)()) {
    application_callback_registry_insert_005a2400(callback);
}

// 00591820's initial-start path. The repeated-init release path at 005918c0
// is outside this startup slice and remains the named shutdown boundary.
void __cdecl disk_slots_init_00591820(std::int32_t requested) {
    if(!disk_slot_mutex_006af07c)
        disk_slot_mutex_006af07c=heap_lock_create_005321f0();
    if(physical_files_006af084)
        application_pool_disk_slots_release_005918c0();
    heap_enter_005322b0(disk_slot_mutex_006af07c);
    if(!requested)requested=0x40;
    std::uint32_t bytes=static_cast<std::uint32_t>(requested)<<5;
    physical_files_006af084=static_cast<PhysicalFile*>(file_object_allocate_0056e5f0(&bytes));
    physical_count_006af080=requested;
    if(physical_files_006af084) {
        heap_fill_0053c290(physical_files_006af084,0,bytes);
        heap_fill_0053c290(disk_mutexes_006aeffc,0,0x80);
    }
    heap_leave_005322c0(disk_slot_mutex_006af07c);
}

// 005679f0 startup body. The list nodes are 0x30-byte entries in the rounded
// allocation; 005806e0 prepends each node, producing the original free-list.
std::int32_t __cdecl application_pool_initialize_005679f0(
    std::uint32_t disk_slots,std::uint32_t,std::int32_t operation_slots) {
    if(devices_006a5c7c)return 1;
    const auto disk_count=disk_slots ? disk_slots : 0x40u;
    const auto operation_count=operation_slots ? operation_slots : 0x40;
    disk_slots_init_00591820(static_cast<std::int32_t>(disk_count));
    io_init_00580630(&free_operations_006a5c58,nullptr,0);
    io_init_00580630(&free_auxiliary_006a5c38,nullptr,0);
    std::uint32_t device_bytes=0xe00;
    devices_006a5c7c=static_cast<FileDevice*>(file_object_allocate_0056e5f0(&device_bytes));
    heap_fill_0053c290(devices_006a5c7c,0,device_bytes);
    std::uint32_t operation_bytes=static_cast<std::uint32_t>(operation_count)*0x30u;
    free_operation_arena_006a5c54=file_object_allocate_0056e5f0(&operation_bytes);
    heap_fill_0053c290(free_operation_arena_006a5c54,0,operation_bytes);
    auto* operation=static_cast<std::uint8_t*>(free_operation_arena_006a5c54);
    for(std::uint32_t i=0;i<operation_bytes/0x30u;++i)
        io_prepend_005806e0(&free_operations_006a5c58,
            reinterpret_cast<IoNode*>(operation+i*0x30u));
    application_pool_lock_006a5c78=heap_lock_create_005321f0();
    application_pool_shutdown_state_006a5c74=0xffffffffu;
    thread_exit_register_00557380(application_pool_shutdown_005678f0);
    return 1;
}
}
