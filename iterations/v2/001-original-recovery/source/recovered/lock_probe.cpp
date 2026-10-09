#include "porsche/heap_locks.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/files.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t ARENA=0x03600000;
std::uint8_t* arena;
std::vector<std::string> calls;
bool allocation_fail;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void log(const char* name, std::uint32_t arg){calls.emplace_back(std::string("[\"")+name+"\","+std::to_string(arg)+"]");}
std::string hex(const void* p,std::size_t n){const char* d="0123456789abcdef";const auto* b=static_cast<const std::uint8_t*>(p);std::string s;for(std::size_t i=0;i<n;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}
}
namespace porsche {
std::uint32_t threads_initialized_006a57dc=0;
void __cdecl thread_init_0055f320(std::uint32_t count){log("thread_init",count);threads_initialized_006a57dc=1;}
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t* bytes){auto request=*bytes;*bytes=(*bytes+4095u)&~4095u;calls.emplace_back("[\"allocate\","+std::to_string(request)+","+std::to_string(*bytes)+","+std::to_string(allocation_fail?0:ARENA+0x100)+"]");return allocation_fail?nullptr:arena+0x100;}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t count){calls.emplace_back("[\"fill\","+std::to_string(ptr(p))+","+std::to_string(value)+","+std::to_string(count)+"]");std::memset(p,value&255,count);}
void __stdcall platform_initialize_critical_section(void* p){log("initialize",ptr(p));}
void __stdcall platform_enter_critical_section(void* p){log("enter",ptr(p));}
void __stdcall platform_leave_critical_section(void* p){log("leave",ptr(p));}
void __stdcall platform_delete_critical_section(void* p){log("delete",ptr(p));}
}
int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(ARENA),0x10000,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    if(!arena)return 2;
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream input(line);int mode,initialized,failed;std::uint32_t count;input>>mode>>initialized>>failed>>count;
        if(!input)return 3;
        std::memset(arena,0xcc,0x10000);calls.clear();allocation_fail=failed!=0;
        porsche::threads_initialized_006a57dc=initialized;
        porsche::heap_lock_pool_count_005de000=count;
        porsche::heap_lock_free_0069cb04=nullptr;
        auto* first=reinterpret_cast<porsche::HeapLockCell*>(arena+0x200);
        if(mode==1 || mode==3 || mode==6 || mode==7){first->next=mode==7?reinterpret_cast<porsche::HeapLockCell*>(arena+0x300):nullptr;first->free_tag=0x46524545u;porsche::heap_lock_free_0069cb04=first;}
        void* result=nullptr;
        if(mode<=1 || mode==7)result=porsche::heap_lock_create_005321f0();
        else if(mode==2){porsche::heap_enter_005322b0(first);porsche::heap_leave_005322c0(first);}
        else if(mode==3)porsche::heap_lock_destroy_005322d0(first);
        else if(mode==4)porsche::heap_lock_destroy_005322d0(nullptr);
        else if(mode==5 || mode==6)porsche::heap_lock_pool_grow_00532250();
        else return 4;
        std::cout<<"{\"return\":"<<ptr(result)<<",\"head\":"<<ptr(porsche::heap_lock_free_0069cb04)
                 <<",\"count\":"<<porsche::heap_lock_pool_count_005de000<<",\"initialized\":"<<porsche::threads_initialized_006a57dc
                 <<",\"arena\":\""<<hex(arena,0x1100)<<"\",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];
        std::cout<<"]}\n";
    }
}
