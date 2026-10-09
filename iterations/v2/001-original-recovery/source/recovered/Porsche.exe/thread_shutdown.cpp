#include "porsche/thread_shutdown.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"

namespace porsche {
// 0055f200..0055f2a0. Keep the signed ESI/CMP/JL loop and reload capacity
// after each unregister. The unregister helper recursively acquires this CS.
void __cdecl thread_table_cleanup_0055f200() {
    auto* const lock=thread_table_lock_006a57ec;
    if(!lock)return;
    heap_enter_005322b0(lock);
    std::int32_t slot=0;
    if(thread_capacity_006a57e8>0) {
        while(slot<thread_capacity_006a57e8) {
            auto* const entries=thread_entries_006a57e4;
            if(entries[slot].handle)
                thread_unregister_0055f2b0(slot,entries[slot].serial);
            ++slot;
        }
    }
    auto* const entries=thread_entries_006a57e4;
    if(entries) {
        file_object_free_0056e640(entries);
        thread_entries_006a57e4=nullptr;
        thread_capacity_006a57e8=0;
    }
    heap_leave_005322c0(thread_table_lock_006a57ec);
    auto* const table_lock=thread_table_lock_006a57ec;
    thread_table_lock_006a57ec=nullptr;
    heap_lock_destroy_005322d0(table_lock);
}

// 0055f1c0..0055f1f1. Only the initialization flag, table state, main
// handle and start lock effects present in the original are touched.
void __cdecl thread_shutdown_0055f1c0() {
    if(!threads_initialized_006a57dc)return;
    threads_initialized_006a57dc=0;
    thread_table_cleanup_0055f200();
    platform_close_handle(main_thread_006a57d0);
    heap_lock_destroy_005322d0(thread_start_lock_006a57d8);
}
}
