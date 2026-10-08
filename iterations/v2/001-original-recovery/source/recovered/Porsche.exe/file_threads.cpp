#include "porsche/file_threads.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
void *main_thread_006a57d0=nullptr,*thread_start_lock_006a57d8=nullptr,*thread_table_lock_006a57ec=nullptr;
std::uint32_t main_thread_id_006a57d4=0,threads_initialized_006a57dc=0,thread_exit_registered_006a57e0=0,thread_serial_005df6a0=1;
ThreadEntry* thread_entries_006a57e4=nullptr;
std::int32_t thread_capacity_006a57e8=0;
// 0055f2b0: signed bounds and serial match; close before clearing all three words.
void __cdecl thread_unregister_0055f2b0(std::int32_t slot,std::uint32_t serial){
    heap_enter_005322b0(thread_table_lock_006a57ec);
    if(slot>=0 && slot<thread_capacity_006a57e8){
        auto* entry=thread_entries_006a57e4+slot;
        if(entry->serial==serial){platform_close_handle(entry->handle);entry->serial=0;entry->id=0;entry->handle=nullptr;}
    }
    heap_leave_005322c0(thread_table_lock_006a57ec);
}
// 0055f3b0: page rounding changes capacity; EAX is low MUL word, not capacity.
std::uint32_t __cdecl thread_table_init_0055f3b0(std::uint32_t count){
    if(!thread_table_lock_006a57ec)thread_table_lock_006a57ec=heap_lock_create_005321f0();
    auto result=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thread_entries_006a57e4));
    if(!thread_entries_006a57e4){
        auto size=count*12u;
        thread_entries_006a57e4=static_cast<ThreadEntry*>(file_object_allocate_0056e5f0(&size));
        result=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thread_entries_006a57e4));
        if(thread_entries_006a57e4){
            heap_fill_0053c290(thread_entries_006a57e4,0,size);
            thread_capacity_006a57e8=static_cast<std::int32_t>(size/12u);result=size*0xaaaaaaabu;
        }
    }
    return result;
}
// 0055f320: original API evaluation order and failure state are retained.
void __cdecl thread_init_0055f320(std::uint32_t count){
    if(!threads_initialized_006a57dc){
        threads_initialized_006a57dc=1;thread_table_init_0055f3b0(count ? count : 100u);
        main_thread_id_006a57d4=platform_current_thread_id();
        auto* target=platform_current_process();auto* source_thread=platform_current_thread();auto* source=platform_current_process();
        platform_duplicate_handle(source,source_thread,target,&main_thread_006a57d0,0,0,2);
        thread_start_lock_006a57d8=heap_lock_create_005321f0();
        if(!thread_exit_registered_006a57e0){thread_exit_registered_006a57e0=1;thread_exit_register_00557380(thread_shutdown_0055f1c0);}
    }
}
// 0055f560: first empty serial slot; serial wraps without skipping zero.
std::uint32_t __cdecl thread_register_0055f560(ThreadRecord* record,void* handle,std::uint32_t id){
    std::uint32_t result=0;heap_enter_005322b0(thread_table_lock_006a57ec);
    for(std::int32_t slot=0;slot<thread_capacity_006a57e8;++slot){
        auto* entry=thread_entries_006a57e4+slot;
        if(!entry->serial){
            record->serial=thread_serial_005df6a0;record->slot=static_cast<std::uint32_t>(slot);record->id=id;
            entry->serial=thread_serial_005df6a0++;entry->handle=handle;record->handle=handle;entry->id=id;result=1;break;
        }
    }
    heap_leave_005322c0(thread_table_lock_006a57ec);return result;
}
void* __cdecl thread_handle_0055f730(ThreadRecord* record){return record->handle;}
std::uint32_t __cdecl thread_id_0055f7e0(ThreadRecord* record){return record->id;}
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t identity){
    const auto current=platform_current_thread_id();
    if(!threads_initialized_006a57dc)thread_init_0055f320(0);
    if(!identity)return current==main_thread_id_006a57d4 ? 1 : 0;
    if(identity==0xffffffffu)return 1;
    return current==thread_id_0055f7e0(reinterpret_cast<ThreadRecord*>(identity)) ? 1 : 0;
}
// 0055f8b0, seven table cells at 0055f95c.
std::uint32_t __cdecl thread_priority_0055f8b0(std::uintptr_t identity,std::uint32_t priority){
    if(!threads_initialized_006a57dc)thread_init_0055f320(0);
    auto* handle=main_thread_006a57d0;
    if(identity)handle=identity==0xffffffffu ? platform_current_thread() : thread_handle_0055f730(reinterpret_cast<ThreadRecord*>(identity));
    if(!handle)return 0;
    std::int32_t value=0;
    switch(priority){case 1:value=1;break;case 2:value=2;break;case 3:value=15;break;
        case 0xffffffffu:value=-1;break;case 0xfffffffeu:value=-2;break;case 0xfffffffdu:value=-15;break;default:break;}
    return platform_thread_priority(handle,value);
}
// 0055f4f0..0055f552: copy payload before handshake, cache slot/serial before callback.
std::uint32_t __stdcall thread_bootstrap_0055f4f0(void* argument){
    auto* input=static_cast<ThreadLaunch*>(argument);const ThreadLaunch copy=*input;input->handshake=nullptr;
    const auto slot=copy.record->slot,serial=copy.record->serial;
    if(copy.no_argument)copy.no_argument();else copy.worker(copy.argument);
    thread_unregister_0055f2b0(static_cast<std::int32_t>(slot),serial);return 0;
}
// 0055f5f0..0055f6c7: suspended thread, registration/priority/resume then handshake.
std::int32_t __cdecl file_thread_start_0055f5f0(FileWorker worker,std::uint32_t argument,std::uint32_t stack,
                                              std::uint32_t priority,std::int32_t,void* output){
    if(!threads_initialized_006a57dc)thread_init_0055f320(0);
    heap_enter_005322b0(thread_start_lock_006a57d8);
    auto* record=static_cast<ThreadRecord*>(output);
    ThreadLaunch launch;launch.record=record;launch.no_argument=nullptr;launch.worker=worker;launch.argument=argument;
    std::uint32_t id;auto* handle=platform_create_thread(nullptr,stack,thread_bootstrap_0055f4f0,&launch,4,&id);
    launch.handshake=handle;
    if(handle){
        record->stack=stack;record->priority=priority;record->flags=0;
        thread_register_0055f560(record,handle,id);thread_priority_0055f8b0(reinterpret_cast<std::uintptr_t>(record),priority);
        platform_resume_thread(handle);
        while(launch.handshake)platform_sleep(1,1);
    }
    heap_leave_005322c0(thread_start_lock_006a57d8);
    return static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(handle));
}
}
