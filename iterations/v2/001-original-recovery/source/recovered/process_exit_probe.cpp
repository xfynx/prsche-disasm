#include "porsche/process_exit.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/exit_shutdown.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t arena_base=0x03600000;
constexpr std::size_t arena_size=0x10000;
std::uint8_t* arena=nullptr;
std::vector<std::string> events;
struct terminal_signal {};
void event(std::string value){events.emplace_back(std::move(value));}
std::uint32_t address(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void dynamic_callback(std::uint32_t id){event("[\"callback\","+std::to_string(id)+"]");}
void __cdecl callback1(){dynamic_callback(1);} void __cdecl callback2(){dynamic_callback(2);}
void __cdecl callback3(){dynamic_callback(3);} void __cdecl callback4(){dynamic_callback(4);}
void(__cdecl* callback_for(std::uint32_t id))(){switch(id){case 1:return callback1;case 2:return callback2;case 3:return callback3;default:return callback4;}}
std::string event_list(){std::string s;for(std::size_t i=0;i<events.size();++i){if(i)s+=',';s+=events[i];}return s;}
}

namespace porsche {
void* __cdecl exit_registry_malloc_005a3be5(std::uint32_t){return nullptr;}
void __cdecl exit_registry_fatal_005a2e22(std::uint32_t){}
std::uint32_t __cdecl exit_registry_allocation_size_005a8161(const void*){return 0;}
void* __cdecl exit_registry_reallocate_005a8029(void*,std::uint32_t){return nullptr;}
void __cdecl exit_registry_lock_api_005a4ba4(std::uint32_t id){event("[\"lock\","+std::to_string(id)+"]");}
void __cdecl exit_registry_unlock_api_005a4c05(std::uint32_t id){event("[\"unlock\","+std::to_string(id)+"]");}
void* __cdecl exit_shutdown_get_current_process(){event("[\"get_current_process\"]");return reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x12345678));}
std::int32_t __cdecl exit_shutdown_terminate_process(void* process,std::uint32_t code){event("[\"terminate_process\","+std::to_string(address(process))+","+std::to_string(code)+"]");return 0;}
void __cdecl exit_shutdown_exit_process(std::uint32_t code){event("[\"exit_process\","+std::to_string(code)+"]");throw terminal_signal{};}
void __cdecl exit_shutdown_static_callback_005a36d6(){event("[\"callback\",5912278]");}
void __cdecl exit_shutdown_static_callback_005ac147(){event("[\"callback\",5947719]");}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(arena_base),arena_size,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    if(!arena)return 3;
    std::uint32_t process_state,code,count;std::int32_t null_index;
    while(std::cin>>process_state>>code>>count>>null_index){
        if(count>4)return 4;
        std::uint32_t callback_ids[4]{};for(std::uint32_t i=0;i<count;++i)if(!(std::cin>>callback_ids[i])||callback_ids[i]<1||callback_ids[i]>4)return 5;
        std::memset(arena,0xcc,arena_size);events.clear();
        auto* base=reinterpret_cast<std::uint32_t*>(arena+0x4000);base[0]=0;
        porsche::exit_registry_base_006c1534=base;porsche::exit_registry_next_006c1530=base;
        for(std::uint32_t i=0;i<count;++i){
            const auto id=callback_ids[i];auto fn=(static_cast<std::int32_t>(id)==null_index)?nullptr:callback_for(id);
            *porsche::exit_registry_next_006c1530++=address(reinterpret_cast<const void*>(fn));
        }
        porsche::exit_shutdown_process_state_006afce8=process_state;
        porsche::exit_shutdown_started_006afce4=0x12345678;
        porsche::exit_shutdown_mode_word_006afce0=0xabcd1200;
        bool terminal=false;
        try{porsche::process_exit_005a246e(code);}catch(const terminal_signal&){terminal=true;}
        std::cout<<"{\"terminal\":"<<(terminal?"true":"false")<<",\"base\":"<<address(base)
          <<",\"next\":"<<address(porsche::exit_registry_next_006c1530)<<",\"process_state\":"<<porsche::exit_shutdown_process_state_006afce8
          <<",\"started\":"<<porsche::exit_shutdown_started_006afce4<<",\"mode\":"<<porsche::exit_shutdown_mode_word_006afce0
          <<",\"events\":["<<event_list()<<"]}\n";
    }
}
