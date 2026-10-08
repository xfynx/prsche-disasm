#pragma once

#include "porsche/files.hpp"

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// These are explicit Win32 import boundaries, not recovered game algorithms.
using DiskSetLastError = void (__stdcall*)(std::uint32_t);
using DiskReadFile = std::uint32_t (__stdcall*)(void*,void*,std::uint32_t,std::uint32_t*,void*);
using DiskGetLastError = std::uint32_t (__stdcall*)();
using DiskSetFilePointer = std::uint32_t (__stdcall*)(void*,std::int32_t,std::int32_t*,std::uint32_t);
using DiskCloseHandle = std::uint32_t (__stdcall*)(void*);
using DiskUnmapView = std::uint32_t (__stdcall*)(void*);
using DiskFreeSpace = std::uint32_t (__stdcall*)(const char*,std::uint32_t*,std::uint32_t*,std::uint32_t*,std::uint32_t*);

extern DiskSetLastError platform_disk_set_last_error;
extern DiskReadFile platform_disk_read_file;
extern DiskGetLastError platform_disk_get_last_error;
extern DiskSetFilePointer platform_disk_set_file_pointer;
extern DiskCloseHandle platform_disk_close_handle;
extern DiskUnmapView platform_disk_unmap_view;
extern DiskFreeSpace platform_disk_free_space;

// 0x006aeffc..0x006af07b is cleared as 0x80 bytes by 0x591820.
extern void* disk_mutexes_006aeffc[32];

std::uint32_t __cdecl file_sleep_0055f740(std::uint32_t);

std::uint32_t __cdecl file_backend_info_00591ce0(void*,void*,void*,std::uint32_t*,void*);
std::uint32_t __cdecl file_backend_read_00591df0(void*,void*,std::uint32_t);
std::uint32_t __cdecl file_backend_seek_00592140(void*,std::uint32_t);
std::uint32_t __cdecl file_physical_close_00592290(void*);
}
