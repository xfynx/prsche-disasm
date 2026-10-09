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
struct Allocation {std::uint32_t address,size;};
std::vector<Allocation> allocations;
std::vector<std::string> calls;
std::uint32_t growth_index=0;
bool fail_realloc=false,initial_alloc=false,terminal=false;
std::uint32_t address(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void record(std::string value){calls.emplace_back(std::move(value));}
std::string call_list(){std::string out;for(std::size_t i=0;i<calls.size();++i){if(i)out+=',';out+=calls[i];}return out;}
std::string hex(const std::uint8_t* p,std::size_t n){
    static constexpr char digits[]="0123456789abcdef";std::string out(n*2,'0');
    for(std::size_t i=0;i<n;++i){out[i*2]=digits[p[i]>>4];out[i*2+1]=digits[p[i]&15];}return out;
}
std::uint32_t allocation_size(std::uint32_t ptr){for(auto it=allocations.rbegin();it!=allocations.rend();++it)if(it->address==ptr)return it->size;return 0;}
}

namespace porsche {
void* __cdecl exit_registry_malloc_005a3be5(std::uint32_t bytes){
    record("[\"malloc_005a3be5\","+std::to_string(bytes)+"]");
    if(!initial_alloc)return nullptr;
    const auto result=static_cast<std::uint32_t>(arena_base+0x4000);
    allocations.push_back({result,bytes});return reinterpret_cast<void*>(static_cast<std::uintptr_t>(result));
}
void __cdecl exit_registry_fatal_005a2e22(std::uint32_t message_id){
    record("[\"amsg_exit_005a2e22\","+std::to_string(message_id)+"]");terminal=true;
}
std::uint32_t __cdecl exit_registry_allocation_size_005a8161(const void* allocation){
    const auto ptr=address(allocation),size=allocation_size(ptr);
    record("[\"allocation_size_005a8161\","+std::to_string(ptr)+","+std::to_string(size)+"]");return size;
}
void* __cdecl exit_registry_reallocate_005a8029(void* allocation,std::uint32_t bytes){
    const auto old=address(allocation);record("[\"reallocate_005a8029\","+std::to_string(old)+","+std::to_string(bytes)+"]");
    if(fail_realloc)return nullptr;
    const auto next=static_cast<std::uint32_t>(arena_base+0x5000+growth_index++*0x1000);
    const auto old_size=allocation_size(old);std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(next)),allocation,old_size);
    allocations.push_back({next,bytes});return reinterpret_cast<void*>(static_cast<std::uintptr_t>(next));
}
void __cdecl exit_registry_lock_api_005a4ba4(std::uint32_t id){record("[\"lock_005a4ba4\","+std::to_string(id)+"]");}
void __cdecl exit_registry_unlock_api_005a4c05(std::uint32_t id){record("[\"unlock_005a4c05\","+std::to_string(id)+"]");}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(arena_base),arena_size,
        MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;
    std::uint32_t init_ok,realloc_fails,count,null_index;
    while(std::cin>>init_ok>>realloc_fails>>count>>null_index){
        if(count>64)return 4;
        std::memset(arena,0xcc,arena_size);allocations.clear();calls.clear();growth_index=0;
        initial_alloc=init_ok!=0;fail_realloc=realloc_fails!=0;terminal=false;
        porsche::exit_registry_base_006c1534=nullptr;porsche::exit_registry_next_006c1530=nullptr;
        porsche::exit_registry_initialize_005a2412();std::vector<std::int32_t> results;
        if(!terminal){
            for(std::uint32_t i=0;i<count;++i){
                const auto id=i+1;const auto raw=(static_cast<std::int32_t>(id)==null_index)?0u:0x03500000u+id*0x100u;
                auto callback=reinterpret_cast<void(__cdecl*)()>(static_cast<std::uintptr_t>(raw));
                results.push_back(porsche::exit_registry_register_005a2400(callback));
                if(terminal)break;
            }
        }
        std::cout<<"{\"terminal\":"<<(terminal?"true":"false")<<",\"base\":"<<address(porsche::exit_registry_base_006c1534)
          <<",\"next\":"<<address(porsche::exit_registry_next_006c1530)<<",\"results\":[";
        for(std::size_t i=0;i<results.size();++i){if(i)std::cout<<',';std::cout<<results[i];}
        std::cout<<"],\"arena\":\""<<hex(arena,arena_size)<<"\",\"calls\":["<<call_list()<<"]}\n";
    }
    return 0;
}
