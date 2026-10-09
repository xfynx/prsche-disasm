#include "porsche/application_heap_init.hpp"
#include "porsche/application_heap.hpp"
#include "porsche/heap.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

namespace {
std::uint32_t allocation_result,os_page;
std::string calls;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void event(const std::string& kind,const std::string& name,std::uint32_t a,std::uint32_t b,
           std::uint32_t c,std::uint32_t d,std::uint32_t e,std::uint32_t f){
    if(!calls.empty())calls+=',';
    calls+="[\""+kind+"\",\""+name+"\","+std::to_string(a)+","+std::to_string(b)+","+
        std::to_string(c)+","+std::to_string(d)+","+std::to_string(e)+","+std::to_string(f)+"]";
}
}
namespace porsche {
OriginalHeap* heaps_006b4f20[16]{};
std::uint32_t __cdecl application_system_page_size(){event("page","",0,0,0,0,0,0);return os_page;}
void* __cdecl application_virtual_alloc(void*,std::uint32_t bytes,std::uint32_t kind,std::uint32_t protection){
    event("alloc","",bytes,kind,protection,0,0,0);
    return allocation_result?reinterpret_cast<void*>(0x03600200):nullptr;
}
std::uint32_t __cdecl application_virtual_free(void*,std::uint32_t,std::uint32_t){return 1;}
std::int32_t __cdecl heap_init_005697f0(std::uint32_t index,const char* name,void* arena,
    std::int32_t bytes,std::uint32_t quantum,std::uint32_t alignment,std::int32_t,
    std::int32_t,std::uint32_t,std::int32_t,std::int32_t locked,void* callback){
    event("heap_init",name,index,ptr(arena),static_cast<std::uint32_t>(bytes),
          quantum,alignment,(locked?1u:0u)|(callback?2u:0u));
    if(index<16)heaps_006b4f20[index]=reinterpret_cast<OriginalHeap*>(0x03600400+index*0x40);
    return 1;
}
void __cdecl application_os_start(std::uint32_t){}
void __cdecl application_fill(void*,std::uint32_t,std::uint32_t){}
void* __cdecl application_lock_create(){return nullptr;}
void __cdecl application_lock_enter(void*){}
void __cdecl application_lock_leave(void*){}
void __cdecl application_memory_diagnostic(std::uint32_t){}
void __cdecl application_secondary_start(){}
void __cdecl application_queue_kind(std::uint32_t,std::uint32_t){}
void __cdecl application_printf_start(std::uint32_t,const char*){}
void __cdecl application_heap_kind(std::uint32_t,std::uint32_t){}
void __cdecl application_heap_finish(std::uint32_t,std::uint32_t,std::uint32_t){}
void* __cdecl application_queue_allocate(std::uint32_t,std::uint32_t,void*){return nullptr;}
}
int main(){
    std::uint32_t op,bytes,page,success,occupied,queue_slot,locked,quantum;
    while(std::cin>>op>>bytes>>page>>success>>occupied>>queue_slot>>locked>>quantum){
        calls.clear();os_page=4096;allocation_result=success;
        std::memset(porsche::heaps_006b4f20,0,sizeof(porsche::heaps_006b4f20));
        std::memset(porsche::application_queue_indices,0,sizeof(porsche::application_queue_indices));
        std::memset(porsche::application_other_arenas_006af3b8,0,sizeof(porsche::application_other_arenas_006af3b8));
        porsche::application_page_size_006af3f8=page;
        porsche::application_default_arena_005deb98=occupied&&op==0?reinterpret_cast<void*>(0x03600900):nullptr;
        for(std::uint32_t i=0;i<occupied&&op==1;++i)
            porsche::heaps_006b4f20[3+i]=reinterpret_cast<porsche::OriginalHeap*>(0x03600400+(3+i)*0x40);
        std::uint32_t returned=0,index=0;
        if(op==0)porsche::application_heap_commit(reinterpret_cast<void*>(0x03600200),bytes);
        else if(op==1){
            returned=static_cast<std::uint32_t>(porsche::application_object_start(bytes,"objectHeap",queue_slot,locked,quantum));
            index=3+occupied;
        }else return 3;
        std::cout<<"{\"return\":"<<returned<<",\"page\":"<<porsche::application_page_size_006af3f8
                 <<",\"default\":"<<ptr(porsche::application_default_arena_005deb98)
                 <<",\"heap0\":"<<ptr(porsche::heaps_006b4f20[0])
                 <<",\"heap1\":"<<ptr(porsche::heaps_006b4f20[1])
                 <<",\"heap_at\":"<<ptr(porsche::heaps_006b4f20[index])
                 <<",\"arena_at\":"<<ptr(porsche::application_other_arenas_006af3b8[index?index-1:0])
                 <<",\"queue_slot\":"<<ptr(porsche::application_queue_indices[1])
                 <<",\"calls\":["<<calls<<"]}\n";
    }
}
