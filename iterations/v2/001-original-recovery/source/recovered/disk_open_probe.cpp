#include "porsche/disk_open.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {
using namespace porsche;
PhysicalFile storage[2];
std::vector<std::string> calls;
std::uint32_t free_ok,sector,create_ok,file_size,map_ok,view_ok;
std::string hex(const void* p,std::size_t n) {
    const auto* b=static_cast<const unsigned char*>(p); std::string s; s.reserve(n*2);
    constexpr char digits[]="0123456789abcdef";
    for(std::size_t i=0;i<n;++i) { s+=digits[b[i]>>4]; s+=digits[b[i]&15]; }
    return s;
}
void record(const std::string& s) { calls.push_back(s); }
void* addr(std::uint32_t value) { return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value)); }
void __stdcall set_error(std::uint32_t value) { record("[\"error\","+std::to_string(value)+"]"); }
std::uint32_t __stdcall free_space(const char* root,std::uint32_t* sectors,std::uint32_t* bytes,
                                    std::uint32_t* available,std::uint32_t* total) {
    record("[\"free\",\""+hex(root,4)+"\"]");
    *sectors=4; *bytes=sector; *available=8; *total=16; return free_ok;
}
void* __stdcall create_file(const char* path,std::uint32_t access,std::uint32_t share,void*,
                            std::uint32_t disposition,std::uint32_t attrs,void*) {
    record("[\"create\",\""+hex(path,std::strlen(path)+1)+"\","+std::to_string(access)+","+
           std::to_string(share)+","+std::to_string(disposition)+","+std::to_string(attrs)+"]");
    return addr(create_ok ? 0x12345000u : 0xffffffffu);
}
std::uint32_t __stdcall get_size(void* handle,std::uint32_t*) {
    record("[\"size\","+std::to_string(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle)))+"]");
    return file_size;
}
void* __stdcall create_mapping(void* handle,void*,std::uint32_t protect,std::uint32_t high,
                               std::uint32_t low,const char*) {
    record("[\"mapping\","+std::to_string(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle)))+
           ","+std::to_string(protect)+","+std::to_string(high)+","+std::to_string(low)+"]");
    return map_ok ? addr(0x23456000u) : nullptr;
}
void* __stdcall map_view(void* mapping,std::uint32_t access,std::uint32_t high,std::uint32_t low,
                         std::uint32_t count) {
    record("[\"view\","+std::to_string(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(mapping)))+
           ","+std::to_string(access)+","+std::to_string(high)+","+std::to_string(low)+","+
           std::to_string(count)+"]");
    return view_ok ? addr(0x34567000u) : nullptr;
}
}
namespace porsche {
PhysicalFile* physical_files_006af084;
std::int32_t physical_count_006af080;
void* disk_mutexes_006aeffc[32];
DiskSetLastError platform_disk_set_last_error=set_error;
DiskFreeSpace platform_disk_free_space=free_space;
void __cdecl disk_slots_init_00591820(std::int32_t requested) {
    record("[\"init\","+std::to_string(requested)+"]");
    physical_files_006af084=storage; physical_count_006af080=2;
    disk_slot_mutex_006af07c=addr(0x02001000u);
}
std::uint8_t __cdecl disk_path_device_00591760(const char* path) {
    record("[\"path\",\""+hex(path,std::strlen(path)+1)+"\"]"); return 3;
}
void* __cdecl heap_lock_create_005321f0() { record("[\"newlock\"]"); return addr(0x02003000u); }
void __cdecl heap_enter_005322b0(void* lock) {
    record("[\"enter\","+std::to_string(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(lock)))+"]");
}
void __cdecl heap_leave_005322c0(void* lock) {
    record("[\"leave\","+std::to_string(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(lock)))+"]");
}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t count) {
    record("[\"fill\","+std::to_string(count)+"]"); std::memset(p,static_cast<int>(value&255),count);
}
}
int main() {
    using namespace porsche;
    platform_disk_create_file=create_file; platform_disk_get_file_size=get_size;
    platform_disk_create_mapping=create_mapping; platform_disk_map_view=map_view;
    std::uint32_t kind,pattern,flags,request,locked,init;
    while(std::cin>>kind>>pattern>>flags>>request>>free_ok>>sector>>create_ok>>file_size>>map_ok>>view_ok>>locked>>init) {
        calls.clear(); std::memset(storage,0xcc,sizeof(storage));
        storage[0].active=(pattern==1 || pattern==2)?1:0;
        storage[1].active=(pattern==2 || pattern==3)?1:0;
        physical_count_006af080=2;
        physical_files_006af084=init?nullptr:storage;
        disk_slot_mutex_006af07c=addr(0x02001000u);
        std::memset(disk_mutexes_006aeffc,0,sizeof(disk_mutexes_006aeffc));
        if(locked) disk_mutexes_006aeffc[3]=addr(0x02002000u);
        void* encoded=addr(0xaaaaaaaa);
        std::uint32_t result=kind==0 ? disk_physical_open_005919a0("C:\\sample.dat",flags,request,&encoded)
                                     : static_cast<std::uint32_t>(disk_slot_allocate_00591c50());
        const auto enc=kind==0 ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(encoded)) : 0;
        std::cout<<"{\"return\":"<<result<<",\"encoded\":"<<enc<<",\"files\":\""
                 <<hex(storage,sizeof(storage))<<"\",\"mutex\":"
                 <<static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(disk_mutexes_006aeffc[3]))
                 <<",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i) std::cout<<(i?",":"")<<calls[i];
        std::cout<<"]}\n";
    }
}
