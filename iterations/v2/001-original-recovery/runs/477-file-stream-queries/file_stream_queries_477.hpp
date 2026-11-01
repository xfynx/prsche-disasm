#pragma once
#include "porsche/file_disk.hpp"
#include "porsche/file_worker.hpp"
namespace porsche {
using DiskWriteFile=std::uint32_t (__stdcall*)(void*,const void*,std::uint32_t,std::uint32_t*,void*);
using DiskSetEndOfFile=std::uint32_t (__stdcall*)(void*);
// Platform transport, not new original storage. Defaults call the exact SDK APIs.
extern DiskWriteFile platform_disk_write_file;
extern DiskSetEndOfFile platform_disk_set_end_of_file;
}
