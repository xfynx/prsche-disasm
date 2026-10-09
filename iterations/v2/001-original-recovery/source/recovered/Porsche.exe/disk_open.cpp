#include "porsche/disk_open.hpp"
#include <windows.h>
#include <cstring>

namespace porsche {
namespace {
void* __stdcall os_create_file(const char* path,std::uint32_t access,std::uint32_t share,void* security,
                               std::uint32_t disposition,std::uint32_t attributes,void* template_file) {
    return ::CreateFileA(path,access,share,reinterpret_cast<LPSECURITY_ATTRIBUTES>(security),
                         disposition,attributes,template_file);
}
std::uint32_t __stdcall os_file_size(void* file,std::uint32_t* high) {
    return ::GetFileSize(file,reinterpret_cast<LPDWORD>(high));
}
void* __stdcall os_create_mapping(void* file,void* security,std::uint32_t protection,
                                  std::uint32_t high,std::uint32_t low,const char* name) {
    return ::CreateFileMappingA(file,reinterpret_cast<LPSECURITY_ATTRIBUTES>(security),
                                protection,high,low,name);
}
void* __stdcall os_map_view(void* mapping,std::uint32_t access,std::uint32_t high,
                            std::uint32_t low,std::uint32_t count) {
    return ::MapViewOfFile(mapping,access,high,low,count);
}
}
DiskCreateFile platform_disk_create_file=os_create_file;
DiskGetFileSize platform_disk_get_file_size=os_file_size;
DiskCreateMapping platform_disk_create_mapping=os_create_mapping;
DiskMapView platform_disk_map_view=os_map_view;
void* disk_slot_mutex_006af07c;

std::int32_t __cdecl disk_slot_allocate_00591c50() {
    if (!physical_files_006af084) disk_slots_init_00591820(0);
    heap_enter_005322b0(disk_slot_mutex_006af07c);
    std::int32_t index=0;
    if (physical_count_006af080>0) {
        while (physical_files_006af084[index].active) {
            ++index;
            if (index>=physical_count_006af080) {
                heap_leave_005322c0(disk_slot_mutex_006af07c);
                return index;
            }
        }
        if (index<physical_count_006af080) {
            heap_fill_0053c290(&physical_files_006af084[index],0,0x20);
            physical_files_006af084[index].active=1;
        }
    }
    heap_leave_005322c0(disk_slot_mutex_006af07c);
    return index;
}

std::uint32_t __cdecl disk_physical_open_005919a0(const char* path,std::uint32_t flags,
                                                   std::uint32_t requested_block,void** encoded) {
    const auto index=disk_slot_allocate_00591c50();
    *encoded=nullptr;
    platform_disk_set_last_error(0);
    if (index<0 || index>=physical_count_006af080) return 0;

    const std::uint32_t access=((flags&1)?0x80000000u:0) | ((flags&2)?0x40000000u:0);
    const std::uint32_t share=((flags&4)?1u:0u) | ((flags&8)?2u:0u);
    const std::uint32_t disposition=(flags&0x10) ? ((flags&0x20)?2u:1u) : ((flags&0x20)?5u:3u);
    std::uint32_t attributes=(flags&0x100)?0x20000080u:0x80u;
    if (flags&0x200) attributes|=0x08000000u;
    if (flags&0x400) attributes|=0x80000000u;

    auto& slot=physical_files_006af084[index];
    slot.mode=flags;
    slot.device=disk_path_device_00591760(path);
    auto& device_mutex=disk_mutexes_006aeffc[slot.device];
    if (!device_mutex) device_mutex=heap_lock_create_005321f0();
    heap_enter_005322b0(device_mutex);
    char root[4]={0x20,0x3a,0x5c,0};
    root[0]=static_cast<char>(slot.device+0x40u);
    std::uint32_t sectors=0,bytes_per_sector=0,available=0,total=0;
    if (!platform_disk_free_space(root,&sectors,&bytes_per_sector,&available,&total)) bytes_per_sector=0x800;
    void* handle=platform_disk_create_file(path,access,share,nullptr,disposition,attributes,nullptr);
    slot.os_handle=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle));
    if (slot.os_handle==0xffffffffu) {
        slot.active=0;
        heap_leave_005322c0(device_mutex);
        return 0;
    }
    if (!requested_block || !bytes_per_sector) slot.block_size=0x4000;
    else if (requested_block>bytes_per_sector)
        slot.block_size=static_cast<std::uint32_t>(((requested_block-1u)+bytes_per_sector)/bytes_per_sector)*bytes_per_sector;
    else slot.block_size=bytes_per_sector;
    slot.size=platform_disk_get_file_size(handle,nullptr);
    if (!(flags&0x800)) {
        slot.mode &= ~0x800u;
        slot.mapping=0xffffffffu;
        slot.view=0;
    } else {
        const auto protection=(flags&2)?0x08000004u:0x08000002u;
        const auto view_access=(flags&2)?2u:4u;
        void* mapping=platform_disk_create_mapping(handle,nullptr,protection,0,0,nullptr);
        slot.mapping=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(mapping));
        if (mapping) {
            void* view=platform_disk_map_view(mapping,view_access,0,0,slot.size);
            slot.view=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(view));
        }
        if (!slot.view) slot.mode &= ~0x800u;
    }
    *encoded=reinterpret_cast<void*>(static_cast<std::uintptr_t>(~static_cast<std::uint32_t>(index)));
    heap_leave_005322c0(device_mutex);
    return 1;
}
}
