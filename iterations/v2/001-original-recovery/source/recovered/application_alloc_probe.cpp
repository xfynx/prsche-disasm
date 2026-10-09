#include "porsche/application_alloc.hpp"
#include "porsche/fe_stream.hpp"
#include <cstdint>
#include <iostream>
#include <string>

namespace {
std::uint32_t outcome;
std::string calls;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void record(const char* kind,const char* source,std::uint32_t a,std::uint32_t b){
    if(!calls.empty())calls+=',';
    calls+="[\""+std::string(kind)+"\",\""+source+"\","+std::to_string(a)+","+std::to_string(b)+"]";
}
}
namespace porsche {
// The production definition belongs to Run025; the isolated fixture supplies it.
std::int32_t application_object_heap_006af3fc=0;
void* __cdecl allocate_00531ca0(const char* source,std::int32_t bytes,std::uint32_t heap_index){
    record("alloc",source,static_cast<std::uint32_t>(bytes),heap_index);
    return outcome?reinterpret_cast<void*>(0x03600200):nullptr;
}
std::uint32_t __cdecl free_00531f90(void* address){
    record("free","",ptr(address),0);return outcome;
}
}
int main(){
    std::uint32_t op,bytes,heap,result;
    while(std::cin>>op>>bytes>>heap>>result){
        outcome=result;calls.clear();porsche::application_object_heap_006af3fc=static_cast<std::int32_t>(heap);
        std::uint32_t returned=0;
        switch(op){
        case 0:returned=ptr(porsche::application_allocator_entry_00531f70("new",bytes,heap));break;
        case 1:returned=ptr(porsche::startup_network_allocate_0059ef90(bytes));break;
        case 2:returned=ptr(porsche::application_allocate_in_heap_0059efc0(bytes,heap));break;
        case 3:returned=ptr(porsche::application_allocate_array_0059eff0(bytes));break;
        case 4:returned=ptr(porsche::application_allocate_array_in_heap_0059f020(bytes,heap));break;
        case 5:returned=porsche::application_release_0059f050(reinterpret_cast<void*>(bytes));break;
        default:return 3;
        }
        std::cout<<"{\"return\":"<<returned<<",\"calls\":["<<calls<<"]}\n";
    }
}
