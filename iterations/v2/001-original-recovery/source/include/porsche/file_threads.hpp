#pragma once
#include "porsche/file_events.hpp"
namespace porsche {
struct ThreadRecord {
    void* handle;std::uint32_t stack,priority,flags,id,serial,slot;
};
struct ThreadEntry {std::uint32_t serial;void* handle;std::uint32_t id;};
struct ThreadLaunch {
    void* volatile handshake;ThreadRecord* record;void(__cdecl* no_argument)();
    FileWorker worker;std::uint32_t argument;
};
static_assert(sizeof(ThreadRecord)==28 && sizeof(ThreadEntry)==12 && sizeof(ThreadLaunch)==20);
extern void *main_thread_006a57d0,*thread_start_lock_006a57d8,*thread_table_lock_006a57ec;
extern std::uint32_t main_thread_id_006a57d4,threads_initialized_006a57dc,thread_exit_registered_006a57e0,thread_serial_005df6a0;
extern ThreadEntry* thread_entries_006a57e4;
extern std::int32_t thread_capacity_006a57e8;
using ThreadBootstrap=std::uint32_t(__stdcall*)(void*);
std::uint32_t __stdcall platform_current_thread_id();
void* __stdcall platform_current_process();
void* __stdcall platform_current_thread();
std::uint32_t __stdcall platform_duplicate_handle(void*,void*,void*,void**,std::uint32_t,std::int32_t,std::uint32_t);
void* __stdcall platform_create_thread(void*,std::uint32_t,ThreadBootstrap,void*,std::uint32_t,std::uint32_t*);
std::uint32_t __stdcall platform_resume_thread(void*);
std::uint32_t __stdcall platform_thread_priority(void*,std::int32_t);
void __cdecl thread_exit_register_00557380(void(__cdecl*)());
void __cdecl thread_shutdown_0055f1c0(); // Still unrecovered exit callback.
void __cdecl thread_unregister_0055f2b0(std::int32_t,std::uint32_t);
void __cdecl thread_init_0055f320(std::uint32_t);
std::uint32_t __cdecl thread_table_init_0055f3b0(std::uint32_t);
std::uint32_t __stdcall thread_bootstrap_0055f4f0(void*);
std::uint32_t __cdecl thread_register_0055f560(ThreadRecord*,void*,std::uint32_t);
void* __cdecl thread_handle_0055f730(ThreadRecord*);
std::uint32_t __cdecl thread_id_0055f7e0(ThreadRecord*);
std::uint32_t __cdecl thread_priority_0055f8b0(std::uintptr_t,std::uint32_t);
}
