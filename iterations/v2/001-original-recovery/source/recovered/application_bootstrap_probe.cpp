#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/application_heap.hpp"
#include "porsche/application_heap_init.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/heap.hpp"
#include <windows.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t arena_address=0x03600000;
constexpr std::uint32_t arena_bytes=0x10000;
std::string calls;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void event(const std::string& s){if(!calls.empty())calls+=',';calls+=s;}
template<class... T> void numbers(const char* kind,T... values){
    std::ostringstream out;out<<"[\""<<kind<<"\"";((out<<','<<values),...);out<<']';event(out.str());
}
std::string snapshot(){
    const auto* p=reinterpret_cast<const unsigned char*>(arena_address);
    static const char hex[]="0123456789abcdef";
    std::string s; s.resize(arena_bytes*2);
    for(std::uint32_t i=0;i<arena_bytes;++i){s[i*2]=hex[p[i]>>4];s[i*2+1]=hex[p[i]&15];}
    return s;
}
void reset(){
    std::memset(porsche::heaps_006b4f20,0,sizeof(porsche::heaps_006b4f20));
    std::memset(porsche::application_other_arenas_006af3b8,0,sizeof(porsche::application_other_arenas_006af3b8));
    porsche::application_default_arena_005deb98=nullptr;
    porsche::application_primary_arena_006af3b4=nullptr;
    porsche::application_page_size_006af3f8=0x1000;
    porsche::application_heap_initialized_006af3f4=0;
    porsche::application_object_heap_006af3fc=0;
    porsche::copy_flag_005deb1c=0;porsche::copy_flag_005deb18=0;
    porsche::copy_flag_005deb10=1;porsche::copy_flag_005deb30=0;
}
}
namespace porsche {
std::uint32_t __cdecl application_system_page_size(){numbers("page",0x1000);return 0x1000;}
void* __cdecl application_virtual_alloc(void*,std::uint32_t bytes,std::uint32_t flags,std::uint32_t protect){
    numbers("alloc",bytes,flags,protect);
    return VirtualAlloc(reinterpret_cast<void*>(arena_address),bytes,flags,protect);
}
std::uint32_t __cdecl application_virtual_free(void* p,std::uint32_t bytes,std::uint32_t flags){
    return VirtualFree(p,bytes,flags)?1u:0u;
}
// Link-only placeholders for the unentered remainder of 0059e9d0/0059edb0.
void __cdecl application_os_start(std::uint32_t){}
void __cdecl application_fill(void*,std::uint32_t,std::uint32_t){}
void* __cdecl application_lock_create(){return reinterpret_cast<void*>(0x00700000);}
void __cdecl application_lock_enter(void*){}
void __cdecl application_lock_leave(void*){}
void __cdecl application_memory_diagnostic(std::uint32_t){}
void __cdecl application_secondary_start(){}
void __cdecl application_queue_kind(std::uint32_t,std::uint32_t){}
void __cdecl application_printf_start(std::uint32_t,const char*){}
void __cdecl application_heap_kind(std::uint32_t,std::uint32_t){}
void __cdecl application_heap_finish(std::uint32_t,std::uint32_t,std::uint32_t){}
void* __cdecl application_queue_allocate(std::uint32_t,std::uint32_t,void*){return nullptr;}
void __cdecl heap_enter_005322b0(void* p){numbers("enter",ptr(p));}
void __cdecl heap_leave_005322c0(void* p){numbers("leave",ptr(p));}
void* __cdecl heap_lock_create_005321f0(){numbers("lock_create");return reinterpret_cast<void*>(0x00700000);}
void __cdecl heap_format_005a0fbf(char* out,const char* fmt,const char* name){
    event(std::string("[\"format\",\"")+fmt+"\",\""+name+"\"]");std::snprintf(out,256,fmt,name);
}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t size){
    numbers("fill",ptr(p)-static_cast<std::uint32_t>(arena_address),value,size);
    std::memset(p,static_cast<int>(value),size);
}
void __cdecl heap_copy_005b0100(void* d,const void* s,std::uint32_t n){std::memcpy(d,s,n);}
void __cdecl heap_copy_005b02c0(void* d,const void* s,std::uint32_t n){std::memcpy(d,s,n);}
void __cdecl heap_copy_005b0480(void* d,const void* s,std::uint32_t n){std::memcpy(d,s,n);}
}
int main(){
    std::string line;
    while(std::getline(std::cin,line)){
        calls.clear();reset();
        std::uint32_t bytes=arena_bytes;
        auto* allocated=porsche::application_page_alloc_0059ed40(&bytes);
        if(!allocated){std::cerr<<"fixed arena VirtualAlloc failed\n";return 2;}
        porsche::application_primary_arena_006af3b4=allocated;
        porsche::application_heap_commit(allocated,bytes);
        // 0059e9d0 installs this active heap index before its clients run.
        porsche::application_object_heap_006af3fc=0;
        std::vector<std::uint32_t> pointers;
        std::vector<std::uint32_t> returns;
        std::vector<std::string> states{snapshot()};
        std::istringstream ops(line);std::string op;
        while(std::getline(ops,op,';')){
            if(op.empty())continue;
            const auto comma=op.find(',');
            if(comma==std::string::npos)return 3;
            const auto kind=op.substr(0,comma);const auto value=static_cast<std::uint32_t>(std::stoul(op.substr(comma+1)));
            if(kind=="A"){
                void* p=porsche::startup_network_allocate_0059ef90(value);
                pointers.push_back(ptr(p));returns.push_back(p?ptr(p)-static_cast<std::uint32_t>(arena_address):0xffffffffu);
            }else if(kind=="F"){
                const auto index=value;if(index>=pointers.size())return 4;
                const auto result=porsche::application_release_0059f050(reinterpret_cast<void*>(pointers[index]));
                returns.push_back(result);
            }else return 5;
            states.push_back(snapshot());
        }
        std::cout<<"{\"returns\":[";
        for(std::size_t i=0;i<returns.size();++i){if(i)std::cout<<',';std::cout<<returns[i];}
        std::cout<<"],\"heaps\":[";
        for(unsigned i=0;i<16;++i){if(i)std::cout<<',';std::cout<<ptr(porsche::heaps_006b4f20[i]);}
        std::cout<<"],\"default\":"<<ptr(porsche::application_default_arena_005deb98)
                 <<",\"primary\":"<<ptr(porsche::application_primary_arena_006af3b4)
                 <<",\"page\":"<<porsche::application_page_size_006af3f8
                 <<",\"object_heap\":"<<porsche::application_object_heap_006af3fc
                 <<",\"calls\":["<<calls<<"],\"states\":[";
        for(std::size_t i=0;i<states.size();++i){if(i)std::cout<<',';std::cout<<'"'<<states[i]<<'"';}
        std::cout<<"]}\n";
        porsche::application_page_release_0059ed90(allocated);
    }
}
