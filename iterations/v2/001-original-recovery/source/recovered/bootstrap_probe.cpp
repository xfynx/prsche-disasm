#include "porsche/file_threads.hpp"
#include "porsche/heap_locks.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace {
constexpr std::uintptr_t POOL=0x03600000,TABLE=0x03700000,POOL2=0x03800000;
std::uint8_t *pool,*table,*pool2;
std::vector<std::string> calls;
std::vector<std::string> states;
std::uint32_t fail_mask,allocation_number;
bool preexisting_pool;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void record(std::string call){
    calls.emplace_back(std::move(call));
    using namespace porsche;
    states.emplace_back("["+std::to_string(ptr(main_thread_006a57d0))+","+std::to_string(main_thread_id_006a57d4)+","+std::to_string(ptr(thread_start_lock_006a57d8))+","+std::to_string(threads_initialized_006a57dc)+","+std::to_string(thread_exit_registered_006a57e0)+","+std::to_string(ptr(thread_entries_006a57e4))+","+std::to_string(thread_capacity_006a57e8)+","+std::to_string(ptr(thread_table_lock_006a57ec))+","+std::to_string(thread_serial_005df6a0)+","+std::to_string(ptr(heap_lock_free_0069cb04))+","+std::to_string(heap_lock_pool_count_005de000)+","+std::to_string(file_page_size_006a6418)+"]");
}
void call1(const char* name,std::uint32_t arg){record(std::string("[\"")+name+"\","+std::to_string(arg)+"]");}
std::string hex(const void* p,std::size_t count){const char* d="0123456789abcdef";const auto* b=static_cast<const std::uint8_t*>(p);std::string s;s.reserve(count*2);for(std::size_t i=0;i<count;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}
}
namespace porsche {
void __stdcall platform_system_info(void* p){record("[\"system_info\"]");std::memset(p,0,36);static_cast<std::uint32_t*>(p)[1]=4096;}
void* __stdcall platform_virtual_alloc(void* base,std::uint32_t bytes,std::uint32_t flags,std::uint32_t protection){
    const auto index=allocation_number++;
    void* result=(fail_mask&(1u<<index))?nullptr:static_cast<void*>(preexisting_pool?(index==0?table:pool2):(index==0?pool:index==1?table:pool2));
    record("[\"virtual_alloc\","+std::to_string(ptr(base))+","+std::to_string(bytes)+","+std::to_string(flags)+","+std::to_string(protection)+","+std::to_string(ptr(result))+"]");
    if(result && bytes<=0x10000)std::memset(result,0,bytes);
    return result;
}
std::uint32_t __stdcall platform_virtual_free(void*,std::uint32_t,std::uint32_t){return 1;}
void __stdcall platform_initialize_critical_section(void* p){call1("initialize",ptr(p));}
void __stdcall platform_enter_critical_section(void* p){call1("enter",ptr(p));}
void __stdcall platform_leave_critical_section(void* p){call1("leave",ptr(p));}
void __stdcall platform_delete_critical_section(void* p){call1("delete",ptr(p));}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t size){record("[\"fill\","+std::to_string(ptr(p))+","+std::to_string(value)+","+std::to_string(size)+"]");std::memset(p,value&255,size);}
std::uint32_t __stdcall platform_current_thread_id(){record("[\"thread_id\"]");return 0x1234;}
void* __stdcall platform_current_process(){record("[\"process\"]");return reinterpret_cast<void*>(0x4001000);}
void* __stdcall platform_current_thread(){record("[\"thread\"]");return reinterpret_cast<void*>(0x4002000);}
std::uint32_t __stdcall platform_duplicate_handle(void* source,void* original,void* target,void** output,std::uint32_t access,std::int32_t inherit,std::uint32_t options){
    record("[\"duplicate\","+std::to_string(ptr(source))+","+std::to_string(ptr(original))+","+std::to_string(ptr(target))+","+std::to_string(output==&main_thread_006a57d0?0x6a57d0:ptr(output))+","+std::to_string(access)+","+std::to_string(inherit)+","+std::to_string(options)+"]");
    *output=reinterpret_cast<void*>(0x4003000);return 1;
}
void __cdecl thread_shutdown_0055f1c0(){}
void __cdecl thread_exit_register_00557380(void(__cdecl* callback)()){call1("exit_register",callback==thread_shutdown_0055f1c0?0x55f1c0:ptr(reinterpret_cast<void*>(callback)));}
// Other references in the file_threads object are outside this fixture.
std::uint32_t __stdcall platform_close_handle(void*){return 1;}
void* __stdcall platform_create_thread(void*,std::uint32_t,ThreadBootstrap,void*,std::uint32_t,std::uint32_t*){return nullptr;}
std::uint32_t __stdcall platform_resume_thread(void*){return 1;}
std::uint32_t __stdcall platform_thread_priority(void*,std::int32_t){return 1;}
std::uint32_t __stdcall platform_sleep(std::uint32_t,std::int32_t){return 0;}
}
int main(){
    pool=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(POOL),0x10000,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    table=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(TABLE),0x10000,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    pool2=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(POOL2),0x10000,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    if(!pool||!table||!pool2)return 2;
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream in(line);std::uint32_t count,initialized,mask,prepool,pretable,registered,repeats;
        in>>count>>initialized>>mask>>prepool>>pretable>>registered>>repeats;if(!in)return 3;
        std::memset(pool,0xcc,0x10000);std::memset(table,0xcc,0x10000);std::memset(pool2,0xcc,0x10000);
        calls.clear();states.clear();fail_mask=mask;allocation_number=0;preexisting_pool=prepool!=0;
        porsche::threads_initialized_006a57dc=initialized;porsche::thread_exit_registered_006a57e0=registered;
        porsche::main_thread_006a57d0=nullptr;porsche::main_thread_id_006a57d4=0;
        porsche::thread_start_lock_006a57d8=nullptr;porsche::thread_table_lock_006a57ec=nullptr;
        porsche::thread_entries_006a57e4=pretable?reinterpret_cast<porsche::ThreadEntry*>(table):nullptr;
        porsche::thread_capacity_006a57e8=0;porsche::thread_serial_005df6a0=1;
        porsche::heap_lock_pool_count_005de000=32;porsche::heap_lock_free_0069cb04=prepool?reinterpret_cast<porsche::HeapLockCell*>(pool+0x200):nullptr;
        porsche::file_page_size_006a6418=0;
        if(prepool){std::uint32_t*cell=reinterpret_cast<std::uint32_t*>(pool+0x200);cell[6]=0;cell[7]=0x46524545;}
        for(std::uint32_t i=0;i<repeats;++i)porsche::thread_init_0055f320(count);
        std::cout<<"{\"globals\":["<<ptr(porsche::main_thread_006a57d0)<<","<<porsche::main_thread_id_006a57d4<<","<<ptr(porsche::thread_start_lock_006a57d8)<<","<<porsche::threads_initialized_006a57dc<<","<<porsche::thread_exit_registered_006a57e0<<","<<ptr(porsche::thread_entries_006a57e4)<<","<<porsche::thread_capacity_006a57e8<<","<<ptr(porsche::thread_table_lock_006a57ec)<<","<<porsche::thread_serial_005df6a0<<","<<ptr(porsche::heap_lock_free_0069cb04)<<","<<porsche::heap_lock_pool_count_005de000<<","<<porsche::file_page_size_006a6418<<"],\"arena\":\"";
        std::cout<<hex(pool,0x1100)<<hex(table,0x1100)<<hex(pool2,0x1100)<<"\",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];
        std::cout<<"],\"states\":[";for(std::size_t i=0;i<states.size();++i)std::cout<<(i?",":"")<<states[i];
        std::cout<<"]}\n";
    }
}
