#include "porsche/exit_registry.hpp"
#include <cstdint>

namespace porsche {
std::uint32_t* exit_registry_next_006c1530=nullptr;
std::uint32_t* exit_registry_base_006c1534=nullptr;

void __cdecl exit_registry_lock_enter_005a2535(){exit_registry_lock_api_005a4ba4(0x0d);}
void __cdecl exit_registry_lock_leave_005a253e(){exit_registry_unlock_api_005a4c05(0x0d);}

void __cdecl exit_registry_initialize_005a2412(){
    exit_registry_base_006c1534=static_cast<std::uint32_t*>(exit_registry_malloc_005a3be5(0x80));
    if(!exit_registry_base_006c1534){
        // Original 005a2e22 is __amsg_exit(0x18), a terminal CRT boundary.
        exit_registry_fatal_005a2e22(0x18);
        return;
    }
    exit_registry_base_006c1534[0]=0;
    exit_registry_next_006c1530=exit_registry_base_006c1534;
}

void* __cdecl exit_registry_append_005a2382(void(__cdecl* callback)()){
    exit_registry_lock_enter_005a2535();
    const auto base=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(exit_registry_base_006c1534));
    auto next=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(exit_registry_next_006c1530));
    const auto capacity=exit_registry_allocation_size_005a8161(exit_registry_base_006c1534);
    const auto required=static_cast<std::uint32_t>(next-base+4u);
    void* result=callback;
    bool allocation_failed=false;
    if(capacity<required){
        const auto old_capacity=exit_registry_allocation_size_005a8161(exit_registry_base_006c1534);
        auto* grown=static_cast<std::uint32_t*>(exit_registry_reallocate_005a8029(
            exit_registry_base_006c1534,old_capacity+0x10u));
        if(!grown){
            result=nullptr;
            allocation_failed=true;
        }else{
            const auto grown_address=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(grown));
            next=grown_address+(((next-base)>>2u)<<2u);
            exit_registry_base_006c1534=grown;
            exit_registry_next_006c1530=reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(next));
        }
    }
    if(!allocation_failed){
        *exit_registry_next_006c1530=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(callback));
        ++exit_registry_next_006c1530;
    }
    exit_registry_lock_leave_005a253e();
    return result;
}

std::int32_t __cdecl exit_registry_register_005a2400(void(__cdecl* callback)()){
    return exit_registry_append_005a2382(callback)?0:-1;
}

void __cdecl application_callback_registry_insert_005a2400(void(__cdecl* callback)()){
    (void)exit_registry_register_005a2400(callback);
}
}
