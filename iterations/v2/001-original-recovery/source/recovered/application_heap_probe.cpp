#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/application_heap.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

namespace {
std::uint32_t page_size,allocation_result,free_result;
std::uint32_t object_result,lock_number,node_number;
std::uint8_t nodes[401][16];
std::string calls;
void call(const char* name,std::uint32_t a=0,std::uint32_t b=0,std::uint32_t c=0){
    if(!calls.empty())calls+=',';
    calls+="[\""+std::string(name)+"\","+std::to_string(a)+","+
           std::to_string(b)+","+std::to_string(c)+"]";
}
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
}
namespace porsche {
std::uint32_t __cdecl application_system_page_size(){call("page");return page_size;}
void* __cdecl application_virtual_alloc(void* address,std::uint32_t bytes,
    std::uint32_t kind,std::uint32_t protection){call("alloc",bytes,kind,protection);return allocation_result?reinterpret_cast<void*>(0x03600200):nullptr;}
std::uint32_t __cdecl application_virtual_free(void* address,std::uint32_t bytes,
    std::uint32_t kind){call("free",ptr(address),bytes,kind);return free_result;}
void __cdecl application_os_start(std::uint32_t a){call("os",a);}
void __cdecl application_fill(void* p,std::uint32_t value,std::uint32_t bytes){call("fill",value,bytes);std::memset(p,static_cast<int>(value),bytes);}
void* __cdecl application_lock_create(){call("lock_create",lock_number);return reinterpret_cast<void*>(0x03600300+4*lock_number++);}
void __cdecl application_lock_enter(void* p){call("lock_enter",ptr(p));}
void __cdecl application_lock_leave(void* p){call("lock_leave",ptr(p));}
void __cdecl application_heap_commit(void* p,std::uint32_t bytes){call("commit",ptr(p),bytes);}
std::int32_t __cdecl application_object_start(std::uint32_t bytes,const char*,std::uint32_t slot,std::uint32_t one,std::uint32_t eight){call("object",bytes,slot,one);return static_cast<std::int32_t>(object_result);}
void __cdecl application_memory_diagnostic(std::uint32_t amount){call("diagnostic",amount);}
void __cdecl application_secondary_start(){call("secondary");}
void __cdecl application_queue_kind(std::uint32_t a,std::uint32_t b){call("queue_kind",a,b);}
void __cdecl application_printf_start(std::uint32_t a,const char*){call("printf",a);}
void __cdecl application_heap_kind(std::uint32_t a,std::uint32_t b){call("heap_kind",a,b);}
void __cdecl application_heap_finish(std::uint32_t a,std::uint32_t b,std::uint32_t c){call("finish",a,b,c);}
void* __cdecl application_queue_allocate(std::uint32_t source,std::uint32_t bytes,void* heap){call("queue_alloc",source,bytes,ptr(heap));return nodes[node_number++];}
}
int main(){
    std::uint32_t op,input,cached,os_page,success;
    while(std::cin>>op>>input>>cached>>os_page>>success){
        calls.clear();page_size=os_page;allocation_result=success;free_result=success;
        porsche::application_page_size_006af3f8=cached;
        lock_number=0;node_number=0;object_result=success;
        std::uint32_t value=input,result=0;
        if(op==0)result=ptr(porsche::application_page_alloc_0059ed40(&value));
        else if(op==1)result=porsche::application_page_release_0059ed90(reinterpret_cast<void*>(input));
        else if(op==2){
            porsche::application_object_heap_006af3fc=0;
            porsche::application_diagnostic_source_005deb74=0;
            porsche::application_diagnostic_line_005deb78=0;
            porsche::startup_heap_0059e9d0(input,cached,os_page,0x1234);
            result=ptr(porsche::application_primary_arena_006af3b4);
            value=static_cast<std::uint32_t>(porsche::application_object_heap_006af3fc);
        }else if(op==3){
            std::memset(porsche::application_heap_records,0,sizeof(porsche::application_heap_records));
            *reinterpret_cast<void**>(porsche::application_heap_records)=reinterpret_cast<void*>(0x03600300);
            *reinterpret_cast<void**>(porsche::application_heap_records+4)=reinterpret_cast<void*>(0x03600500);
            porsche::application_queue_indices[0]=reinterpret_cast<void*>(0x03600400);
            porsche::startup_queue_0059edb0(input,0);
            result=node_number;
            value=ptr(*reinterpret_cast<void**>(porsche::application_heap_records+4))==0x03600500?0:node_number;
        }else return 3;
        std::cout<<"{\"value\":"<<value<<",\"page\":"<<porsche::application_page_size_006af3f8
                 <<",\"result\":"<<result<<",\"calls\":["<<calls<<"]";
        if(op==2){
            std::cout<<",\"state\":["<<static_cast<unsigned>(porsche::application_heap_initialized_006af3f4)
                     <<","<<porsche::application_diagnostic_source_005deb74
                     <<","<<porsche::application_diagnostic_line_005deb78;
            for(std::size_t i=0;i<16;++i)
                std::cout<<","<<ptr(*reinterpret_cast<void**>(porsche::application_heap_records+i*0x8c));
            std::cout<<"]";
        }else if(op==3){
            std::cout<<",\"chain\":[";
            auto* node=*reinterpret_cast<void**>(porsche::application_heap_records+4);
            for(std::uint32_t i=0;i<node_number;++i){
                if(i)std::cout<<",";
                std::uint32_t index=0;
                while(index<node_number && node!=nodes[index])++index;
                std::cout<<index;
                node=*reinterpret_cast<void**>(static_cast<std::uint8_t*>(node)+4);
            }
            std::cout<<"]";
        }
        std::cout<<"}\n";
    }
}
