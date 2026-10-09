#include "porsche/window_threads.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t arena_base=0x03600000;
constexpr std::size_t arena_size=0x20000;
std::uint8_t* arena;
std::uint32_t created_handle,sleep_target,sleep_count,lock_count,allocation_failure;
porsche::ThreadLaunch* pending_launch;
std::vector<std::string> calls;
std::uint32_t number(const std::string& text){return static_cast<std::uint32_t>(std::stoul(text,nullptr,0));}
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void event(const std::string& row){calls.push_back(row);}
std::string json_calls(){std::string out;for(std::size_t i=0;i<calls.size();++i){if(i)out+=',';out+=calls[i];}return out;}
std::string hex(const std::uint8_t* p,std::size_t n){
    static constexpr char digits[]="0123456789abcdef";std::string out(n*2,'0');
    for(std::size_t i=0;i<n;++i){out[2*i]=digits[p[i]>>4];out[2*i+1]=digits[p[i]&15];}return out;
}
void __cdecl window_worker_callback_fixture(){}
}

namespace porsche {
void __cdecl thread_shutdown_0055f1c0(){}
void __cdecl heap_enter_005322b0(void* lock){event("[\"enter\","+std::to_string(ptr(lock))+"]");}
void __cdecl heap_leave_005322c0(void* lock){event("[\"leave\","+std::to_string(ptr(lock))+"]");}
void* __cdecl heap_lock_create_005321f0(){
    const auto lock=static_cast<void*>(reinterpret_cast<void*>(0x2001000u+lock_count++*16u));
    event("[\"lock_create\","+std::to_string(ptr(lock))+"]");return lock;
}
void __cdecl heap_fill_0053c290(void* dst,std::uint32_t value,std::uint32_t bytes){
    event("[\"fill\","+std::to_string(ptr(dst))+","+std::to_string(value)+","+std::to_string(bytes)+"]");
    if(dst)std::memset(dst,static_cast<int>(value&0xff),bytes);
}
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t* size){
    const auto requested=*size;*size=(requested+4095u)&~4095u;
    void* result=allocation_failure?nullptr:arena+0x1000;
    event("[\"allocate\","+std::to_string(requested)+","+std::to_string(*size)+","+std::to_string(ptr(result))+ "]");
    return result;
}
std::uint32_t __stdcall platform_current_thread_id(){event("[\"current_id\"]");return 0x1234;}
void* __stdcall platform_current_process(){event("[\"current_process\"]");return reinterpret_cast<void*>(0x4001000);}
void* __stdcall platform_current_thread(){event("[\"current_thread\"]");return reinterpret_cast<void*>(0x4002000);}
std::uint32_t __stdcall platform_duplicate_handle(void* source,void* source_handle,void* target,void** out,
                                                  std::uint32_t access,std::int32_t inherit,std::uint32_t options){
    const auto out_va=out==&main_thread_006a57d0?0x6a57d0u:ptr(out);
    event("[\"duplicate\","+std::to_string(ptr(source))+","+std::to_string(ptr(source_handle))+","+
          std::to_string(ptr(target))+","+std::to_string(out_va)+","+std::to_string(access)+","+
          std::to_string(static_cast<std::uint32_t>(inherit))+","+std::to_string(options)+"]");
    *out=reinterpret_cast<void*>(0x4003000);return 1;
}
void* __stdcall platform_create_thread(void* security,std::uint32_t stack,ThreadBootstrap bootstrap,void* argument,
                                       std::uint32_t flags,std::uint32_t* id){
    pending_launch=static_cast<ThreadLaunch*>(argument);
    const auto callback=pending_launch->no_argument==window_worker_callback_fixture?0x53b8d0u:ptr(reinterpret_cast<void*>(pending_launch->no_argument));
    const auto worker=pending_launch->worker?0x2200e10u:0u;
    event("[\"create_thread\","+std::to_string(ptr(security))+","+std::to_string(stack)+","+
          std::to_string(bootstrap==thread_bootstrap_0055f4f0?0x55f4f0u:ptr(reinterpret_cast<void*>(bootstrap)))+","+
          std::to_string(ptr(pending_launch->record))+","+std::to_string(callback)+","+
          std::to_string(worker)+","+std::to_string(pending_launch->argument)+","+std::to_string(flags)+"]");
    *id=0x56781234;return reinterpret_cast<void*>(static_cast<std::uintptr_t>(created_handle));
}
std::uint32_t __stdcall platform_resume_thread(void* handle){
    event("[\"resume\","+std::to_string(ptr(handle))+"]");
    if(!sleep_target&&pending_launch)pending_launch->handshake=nullptr;return 1;
}
std::uint32_t __stdcall platform_thread_priority(void* handle,std::int32_t priority){
    event("[\"priority\","+std::to_string(ptr(handle))+","+std::to_string(priority)+"]");return 1;
}
std::uint32_t __stdcall platform_close_handle(void* handle){event("[\"close\","+std::to_string(ptr(handle))+"]");return 1;}
std::uint32_t __stdcall platform_sleep(std::uint32_t ms,std::int32_t alertable){
    event("[\"sleep\","+std::to_string(ms)+","+std::to_string(static_cast<std::uint32_t>(alertable))+"]");
    if(++sleep_count>=sleep_target&&pending_launch)pending_launch->handshake=nullptr;return 0;
}
void __cdecl thread_exit_register_00557380(void(__cdecl* callback)()){
    const auto value=callback==thread_shutdown_0055f1c0?0x55f1c0u:ptr(reinterpret_cast<void*>(callback));
    event("[\"exit_register\","+std::to_string(value)+"]");
}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(arena_base),arena_size,
        MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;
    std::uint32_t initialized,capacity,occupied,stack,unused3,unused4,record_seed,serial;
    while(std::cin>>initialized>>capacity>>occupied>>stack>>unused3>>unused4>>created_handle>>sleep_target>>record_seed>>serial){
        std::memset(arena,0xcc,arena_size);calls.clear();sleep_count=lock_count=0;pending_launch=nullptr;allocation_failure=0;
        auto* record=reinterpret_cast<porsche::ThreadRecord*>(arena+0x200);
        auto* table=reinterpret_cast<porsche::ThreadEntry*>(arena+0x1000);
        auto* record_words=reinterpret_cast<std::uint32_t*>(record);
        for(std::uint32_t i=0;i<7;++i)record_words[i]=record_seed+i*0x101u;
        for(std::uint32_t i=0;i<8;++i){table[i].serial=(occupied&(1u<<i))?0x7000u+i:0;table[i].handle=reinterpret_cast<void*>(0x4005000u+i*0x100u);table[i].id=0x6000u+i;}
        porsche::main_thread_006a57d0=nullptr;porsche::main_thread_id_006a57d4=0;
        porsche::thread_start_lock_006a57d8=initialized?reinterpret_cast<void*>(0x2001000):nullptr;
        porsche::threads_initialized_006a57dc=initialized;porsche::thread_exit_registered_006a57e0=0;
        porsche::thread_entries_006a57e4=initialized?table:nullptr;
        porsche::thread_capacity_006a57e8=initialized?static_cast<std::int32_t>(capacity):0;
        porsche::thread_table_lock_006a57ec=initialized?reinterpret_cast<void*>(0x2002000):nullptr;
        porsche::thread_serial_005df6a0=serial;
        const auto result=porsche::window_thread_start_0055f420(
            reinterpret_cast<void*>(&window_worker_callback_fixture),stack,unused3,unused4,
            reinterpret_cast<std::uint32_t*>(record));
        const auto globals="["+std::to_string(ptr(porsche::main_thread_006a57d0))+","+
            std::to_string(porsche::main_thread_id_006a57d4)+","+std::to_string(ptr(porsche::thread_start_lock_006a57d8))+","+
            std::to_string(porsche::threads_initialized_006a57dc)+","+std::to_string(porsche::thread_exit_registered_006a57e0)+","+
            std::to_string(ptr(porsche::thread_entries_006a57e4))+","+std::to_string(static_cast<std::uint32_t>(porsche::thread_capacity_006a57e8))+","+
            std::to_string(ptr(porsche::thread_table_lock_006a57ec))+","+std::to_string(porsche::thread_serial_005df6a0)+"]";
        std::cout<<"{\"return\":"<<static_cast<std::uint32_t>(result)<<",\"globals\":"<<globals
                 <<",\"arena\":\""<<hex(arena,arena_size)<<"\",\"calls\":["<<json_calls()<<"]}\n";
    }
    return 0;
}
