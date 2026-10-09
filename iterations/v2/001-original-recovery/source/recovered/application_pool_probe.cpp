#include "porsche/application_pool.hpp"
#include "porsche/disk_open.hpp"
#include "porsche/file_device.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr std::uint32_t arena_va[3]={0x03600000,0x03610000,0x03620000};
alignas(16) std::uint8_t arena_bytes[3][0x2000];
std::uint32_t requested_page=4096,alloc_index=0,lock_index=0;
std::vector<std::string> calls;
std::uint32_t canonical(const void* p) {
    if(p==porsche::disk_mutexes_006aeffc)return 0x006aeffc;
    const auto address=reinterpret_cast<std::uintptr_t>(p);
    for(std::uint32_t i=0;i<3;++i) {
        const auto first=reinterpret_cast<std::uintptr_t>(arena_bytes[i]);
        if(address>=first && address<first+sizeof(arena_bytes[i]))
            return arena_va[i]+static_cast<std::uint32_t>(address-first);
    }
    return static_cast<std::uint32_t>(address);
}
void event(std::string s){calls.emplace_back(std::move(s));}
std::string list_state(const porsche::IoList& list) {
    auto key=canonical(reinterpret_cast<const void*>(list.key));
    if(list.key==porsche::io_default_key_00580670)key=0x00580670;
    return "["+std::to_string(list.count)+","+std::to_string(list.flags)+","+
        std::to_string(canonical(list.head))+","+std::to_string(canonical(list.tail))+","+
        std::to_string(key)+","+std::to_string(list.argument)+","+
        std::to_string(canonical(list.lock))+"]";
}
std::string hex(const std::uint8_t* p,std::size_t n) {
    static constexpr char digits[]="0123456789abcdef";
    std::string out;out.resize(n*2);
    for(std::size_t i=0;i<n;++i){out[i*2]=digits[p[i]>>4];out[i*2+1]=digits[p[i]&15];}
    return out;
}
std::string arena_snapshot(std::size_t index) {
    std::array<std::uint8_t,0x2000> copy{};
    std::memcpy(copy.data(),arena_bytes[index],copy.size());
    if(index==2)for(std::size_t offset=0;offset+4<=copy.size();offset+=0x30) {
        std::uint32_t link;std::memcpy(&link,copy.data()+offset,4);
        if(link) {auto* p=reinterpret_cast<void*>(static_cast<std::uintptr_t>(link));link=canonical(p);std::memcpy(copy.data()+offset,&link,4);}
    }
    return hex(copy.data(),copy.size());
}
}

namespace porsche {
// Standalone fixture storage. The integrated production globals are owned by files.cpp.
std::int32_t physical_count_006af080=0;
PhysicalFile* physical_files_006af084=nullptr;
FileDevice* devices_006a5c7c=nullptr;
IoList free_operations_006a5c58{},free_auxiliary_006a5c38{};
void* disk_slot_mutex_006af07c=nullptr;
void* disk_mutexes_006aeffc[32]{};
const char* diagnostic_file_005deb74=nullptr;
std::uint32_t diagnostic_line_005deb78=0;
void (__cdecl* diagnostic_handler_005debf0)(const char*)=nullptr;
void __cdecl application_pool_disk_slots_release_005918c0(){}
void __cdecl application_pool_shutdown_005678f0(){}
void __cdecl application_callback_registry_insert_005a2400(void(__cdecl* callback)()) {
    const auto id=callback==application_pool_shutdown_005678f0?0x005678f0u:canonical(reinterpret_cast<void*>(callback));
    event("[\"callback_register\","+std::to_string(id)+"]");
}
std::uint32_t __cdecl io_lock_00580ea0(IoList*){return 0;}
void __cdecl io_unlock_00580ec0(IoList*,std::uint32_t){}
std::uint32_t __cdecl operation_key_005684c0(IoNode* p,std::uint32_t){return canonical(p);}
void __cdecl file_worker_00568530(std::uint32_t){}
void* __cdecl file_auto_event_0055fb20(){return nullptr;}
void* __cdecl file_manual_event_0055fc20(){return nullptr;}
void* __cdecl file_wait_event_0055fc60(void* p){return p;}
std::uint32_t __cdecl file_reset_event_0055fc40(void*){return 1;}
std::int32_t __cdecl file_thread_start_0055f5f0(FileWorker,std::uint32_t,std::uint32_t,std::uint32_t,std::int32_t,void*){return 0;}
std::uint32_t __cdecl io_remove_00580930(IoList*,IoNode*){return 0;}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t fill,std::uint32_t bytes) {
    event("[\"fill\","+std::to_string(canonical(p))+","+std::to_string(fill)+","+std::to_string(bytes)+"]");
    if(p)std::memset(p,static_cast<int>(fill),bytes);
}
void* __cdecl heap_lock_create_005321f0() {
    const auto p=static_cast<void*>(reinterpret_cast<void*>(0x03700000+lock_index*0x100));
    event("[\"lock_create\","+std::to_string(canonical(p))+ "]");++lock_index;return p;
}
void __cdecl heap_enter_005322b0(void* p){event("[\"enter\","+std::to_string(canonical(p))+"]");}
void __cdecl heap_leave_005322c0(void* p){event("[\"leave\","+std::to_string(canonical(p))+"]");}
void __stdcall platform_system_info(void* out) {
    auto* words=static_cast<std::uint32_t*>(out);words[1]=requested_page;
}
void* __stdcall platform_virtual_alloc(void*,std::uint32_t bytes,std::uint32_t type,std::uint32_t protection) {
    void* p=alloc_index<3?static_cast<void*>(arena_bytes[alloc_index]):nullptr;
    event("[\"alloc\","+std::to_string(bytes)+","+std::to_string(type)+","+
          std::to_string(protection)+","+std::to_string(canonical(p))+"]");
    ++alloc_index;return p;
}
std::uint32_t __stdcall platform_virtual_free(void*,std::uint32_t,std::uint32_t){return 1;}
}

int main() {
    std::uint32_t disk_slots,operation_slots,page,preinitialized;
    while(std::cin>>disk_slots>>operation_slots>>page>>preinitialized) {
        std::memset(arena_bytes,0,sizeof(arena_bytes));std::memset(porsche::disk_mutexes_006aeffc,0,sizeof(porsche::disk_mutexes_006aeffc));
        calls.clear();alloc_index=0;lock_index=0;requested_page=page;
        porsche::file_page_size_006a6418=page;
        porsche::disk_slot_mutex_006af07c=nullptr;
        porsche::physical_count_006af080=0;porsche::physical_files_006af084=nullptr;
        porsche::devices_006a5c7c=preinitialized?reinterpret_cast<porsche::FileDevice*>(arena_bytes[0]):nullptr;
        porsche::free_operation_arena_006a5c54=nullptr;porsche::application_pool_lock_006a5c78=nullptr;
        porsche::application_pool_shutdown_state_006a5c74=0;
        porsche::free_operations_006a5c58={};porsche::free_auxiliary_006a5c38={};
        const auto result=porsche::application_pool_initialize_005679f0(disk_slots,0,static_cast<std::int32_t>(operation_slots));
        std::cout<<"{\"return\":"<<result<<",\"page\":"<<porsche::file_page_size_006a6418
                 <<",\"devices\":"<<canonical(porsche::devices_006a5c7c)
                 <<",\"physical\":"<<canonical(porsche::physical_files_006af084)
                 <<",\"physical_count\":"<<porsche::physical_count_006af080
                 <<",\"operation_arena\":"<<canonical(porsche::free_operation_arena_006a5c54)
                 <<",\"disk_lock\":"<<canonical(porsche::disk_slot_mutex_006af07c)
                 <<",\"pool_lock\":"<<canonical(porsche::application_pool_lock_006a5c78)
                 <<",\"shutdown_state\":"<<porsche::application_pool_shutdown_state_006a5c74
                 <<",\"disk_mutexes\":\""<<hex(reinterpret_cast<std::uint8_t*>(porsche::disk_mutexes_006aeffc),0x80)
                 <<"\",\"free_operations\":"<<list_state(porsche::free_operations_006a5c58)
                 <<",\"free_auxiliary\":"<<list_state(porsche::free_auxiliary_006a5c38)
                 <<",\"arenas\":[\""<<arena_snapshot(0)<<"\",\""<<arena_snapshot(1)
                 <<"\",\""<<arena_snapshot(2)<<"\"],\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];
        std::cout<<"]}\n";
    }
}
