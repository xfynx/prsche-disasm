#pragma once
#include "porsche/file_disk.hpp"

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
using DiskCreateFile = void* (__stdcall*)(const char*,std::uint32_t,std::uint32_t,void*,std::uint32_t,std::uint32_t,void*);
using DiskGetFileSize = std::uint32_t (__stdcall*)(void*,std::uint32_t*);
using DiskCreateMapping = void* (__stdcall*)(void*,void*,std::uint32_t,std::uint32_t,std::uint32_t,const char*);
using DiskMapView = void* (__stdcall*)(void*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
extern DiskCreateFile platform_disk_create_file;
extern DiskGetFileSize platform_disk_get_file_size;
extern DiskCreateMapping platform_disk_create_mapping;
extern DiskMapView platform_disk_map_view;

extern void* disk_slot_mutex_006af07c;
// 0x591820 and 0x591760 remain typed original boundaries.
void __cdecl disk_slots_init_00591820(std::int32_t requested);
std::uint8_t __cdecl disk_path_device_00591760(const char* path);
std::int32_t __cdecl disk_slot_allocate_00591c50();
std::uint32_t __cdecl disk_physical_open_005919a0(const char* path,std::uint32_t flags,
                                                    std::uint32_t requested_block,void** encoded);
}
