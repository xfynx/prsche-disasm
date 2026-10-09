#include "porsche/exit_shutdown.hpp"
#include "porsche/exit_registry.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t arena_base=0x03600000;
constexpr std::size_t arena_size=0x10000;
std::uint8_t* arena=nullptr;
std::vector<std::string> calls;
bool terminal=false;
bool mutate_base=false;
std::uint32_t address(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void record(std::string value){calls.emplace_back(std::move(value));}
std::string call_list(){std::string out;for(std::size_t i=0;i<calls.size();++i){if(i)out+=',';out+=calls[i];}return out;}
std::string hex(const std::uint8_t* p,std::size_t n){static constexpr char d[]="0123456789abcdef";std::string s(n*2,'0');for(std::size_t i=0;i<n;++i){s[i*2]=d[p[i]>>4];s[i*2+1]=d[p[i]&15];}return s;}
void dynamic_callback(std::uint32_t id){
    record("[\"callback\","+std::to_string(0x02200200u+id*0x10u)+"]");
    if(mutate_base && id==4)porsche::exit_registry_base_006c1534+=2;
}
void __cdecl callback1(){dynamic_callback(1);}void __cdecl callback2(){dynamic_callback(2);}
void __cdecl callback3(){dynamic_callback(3);}void __cdecl callback4(){dynamic_callback(4);}
void(__cdecl* callback_for(std::uint32_t id))(){switch(id){case 1:return callback1;case 2:return callback2;case 3:return callback3;default:return callback4;}}
void normalize(std::uint8_t* bytes,std::uint32_t offset,std::uint32_t value){std::memcpy(bytes+offset,&value,4);}
}

namespace porsche {
void* __cdecl exit_registry_malloc_005a3be5(std::uint32_t){return nullptr;}
void __cdecl exit_registry_fatal_005a2e22(std::uint32_t){}
std::uint32_t __cdecl exit_registry_allocation_size_005a8161(const void*){return 0;}
void* __cdecl exit_registry_reallocate_005a8029(void*,std::uint32_t){return nullptr;}
void __cdecl exit_registry_lock_api_005a4ba4(std::uint32_t id){record("[\"lock\","+std::to_string(id)+"]");}
void __cdecl exit_registry_unlock_api_005a4c05(std::uint32_t id){record("[\"unlock\","+std::to_string(id)+"]");}
void* __cdecl exit_shutdown_get_current_process(){record("[\"get_current_process\"]");return reinterpret_cast<void*>(static_cast<std::uintptr_t>(0xffffffffu));}
std::int32_t __cdecl exit_shutdown_terminate_process(void* process,std::uint32_t code){record("[\"terminate_process\","+std::to_string(address(process))+","+std::to_string(code)+"]");return 0;}
void __cdecl exit_shutdown_exit_process(std::uint32_t code){record("[\"exit_process\","+std::to_string(code)+"]");terminal=true;}
void __cdecl exit_shutdown_static_callback_005a36d6(){record("[\"callback\",5912278]");}
void __cdecl exit_shutdown_static_callback_005ac147(){record("[\"callback\",5947719]");}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(arena_base),arena_size,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;
    std::uint32_t process_state,skip_callbacks,return_after,code,count,null_index;
    while(std::cin>>process_state>>skip_callbacks>>return_after>>code>>count>>null_index){
        if(count>4)return 4;
        std::memset(arena,0xcc,arena_size);calls.clear();terminal=false;
        mutate_base=static_cast<std::int32_t>(null_index)==-2;
        auto* base=reinterpret_cast<std::uint32_t*>(arena+0x4000);base[0]=0;
        porsche::exit_registry_base_006c1534=base;porsche::exit_registry_next_006c1530=base;
        for(std::uint32_t i=0;i<count;++i){
            const auto id=i+1;auto fn=(static_cast<std::int32_t>(id)==null_index)?nullptr:callback_for(id);
            *porsche::exit_registry_next_006c1530++=address(reinterpret_cast<const void*>(fn));
        }
        porsche::exit_shutdown_process_state_006afce8=process_state;
        porsche::exit_shutdown_started_006afce4=0x12345678;
        porsche::exit_shutdown_mode_word_006afce0=0xabcd1200;
        porsche::exit_shutdown_execute_005a2490(code,static_cast<std::int32_t>(skip_callbacks),return_after);
        std::vector<std::uint8_t> snapshot(arena,arena+arena_size);
        for(std::uint32_t i=0;i<count;++i){
            const auto id=i+1;auto fn=(static_cast<std::int32_t>(id)==null_index)?nullptr:callback_for(id);
            const auto offset=0x4000+i*4;
            if(fn)normalize(snapshot.data(),offset,0x02200200u+id*0x10u);
        }
        std::cout<<"{\"terminal\":"<<(terminal?"true":"false")<<",\"base\":"<<address(porsche::exit_registry_base_006c1534)
          <<",\"next\":"<<address(porsche::exit_registry_next_006c1530)<<",\"exit_state\":"<<porsche::exit_shutdown_process_state_006afce8
          <<",\"started\":"<<porsche::exit_shutdown_started_006afce4<<",\"mode\":"<<porsche::exit_shutdown_mode_word_006afce0
          <<",\"arena\":\""<<hex(snapshot.data(),snapshot.size())<<"\",\"calls\":["<<call_list()<<"]}\n";
    }
    return 0;
}
