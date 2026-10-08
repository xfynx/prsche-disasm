#include "porsche/file_disk.hpp"
#include "porsche/file_events.hpp"
#include <windows.h>
#include <cstdint>

namespace porsche {
namespace {
constexpr std::uint32_t kInvalidHandle=0xffffffffu;
constexpr std::uint32_t kErrorInvalidHandle=6;
constexpr std::uint32_t kErrorIoPending=0x3e5;

void __stdcall os_set_last_error(std::uint32_t value) { ::SetLastError(value); }
std::uint32_t __stdcall os_read_file(void* handle,void* buffer,std::uint32_t count,std::uint32_t* read,void* overlapped) {
    return ::ReadFile(handle,buffer,count,reinterpret_cast<DWORD*>(read),reinterpret_cast<LPOVERLAPPED>(overlapped));
}
std::uint32_t __stdcall os_get_last_error() { return ::GetLastError(); }
std::uint32_t __stdcall os_set_file_pointer(void* handle,std::int32_t offset,std::int32_t* high,std::uint32_t method) {
    return ::SetFilePointer(handle,offset,reinterpret_cast<LONG*>(high),method);
}
std::uint32_t __stdcall os_close_handle(void* handle) { return ::CloseHandle(handle); }
std::uint32_t __stdcall os_unmap_view(void* view) { return ::UnmapViewOfFile(view); }
std::uint32_t __stdcall os_free_space(const char* root,std::uint32_t* sectors,std::uint32_t* bytes,
                                      std::uint32_t* free_clusters,std::uint32_t* total_clusters) {
    return ::GetDiskFreeSpaceA(root,reinterpret_cast<DWORD*>(sectors),reinterpret_cast<DWORD*>(bytes),
                               reinterpret_cast<DWORD*>(free_clusters),reinterpret_cast<DWORD*>(total_clusters));
}

PhysicalFile* physical(void* encoded) {
    const auto raw=static_cast<std::int32_t>(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(encoded)));
    if (!physical_files_006af084 || raw>=0) return nullptr;
    const auto slot=~raw;
    if (slot<0 || slot>=physical_count_006af080) return nullptr;
    auto* file=physical_files_006af084+slot;
    return file->active ? file : nullptr;
}
void lock(PhysicalFile* file) { heap_enter_005322b0(disk_mutexes_006aeffc[file->device]); }
void unlock(PhysicalFile* file) { heap_leave_005322c0(disk_mutexes_006aeffc[file->device]); }
}

DiskSetLastError platform_disk_set_last_error=os_set_last_error;
DiskReadFile platform_disk_read_file=os_read_file;
DiskGetLastError platform_disk_get_last_error=os_get_last_error;
DiskSetFilePointer platform_disk_set_file_pointer=os_set_file_pointer;
DiskCloseHandle platform_disk_close_handle=os_close_handle;
DiskUnmapView platform_disk_unmap_view=os_unmap_view;
DiskFreeSpace platform_disk_free_space=os_free_space;
void* disk_mutexes_006aeffc[32];

// 00591ce0. The fourth argument is the size destination at +0x1c, not a generic info structure.
std::uint32_t __cdecl file_backend_info_00591ce0(void* encoded,void* mode,void* block_size,
                                                  std::uint32_t* size,void* free_bytes) {
    auto* file=physical(encoded);
    if (!file) { platform_disk_set_last_error(kErrorInvalidHandle); return 0; }
    lock(file); platform_disk_set_last_error(0);
    if (mode) *static_cast<std::uint32_t*>(mode)=file->mode;
    if (block_size) *static_cast<std::uint32_t*>(block_size)=file->block_size;
    if (size) *size=file->size;
    std::uint32_t result=1;
    if (free_bytes) {
        // 005c1710 is loaded as the immediate dword 005c3a20, then its low byte is overwritten.
        char root[4]={0x20,0x3a,0x5c,0};
        root[0]=static_cast<char>(file->device+0x40u);
        std::uint32_t sectors,bytes,available,total;
        if (!platform_disk_free_space(root,&sectors,&bytes,&available,&total)) result=0;
        else *static_cast<std::uint32_t*>(free_bytes)=bytes*available;
    }
    unlock(file);
    return result;
}

// 00591df0. ReadFile and SleepEx are recorded OS boundaries in disk_probe.
std::uint32_t __cdecl file_backend_read_00591df0(void* encoded,void* buffer,std::uint32_t requested) {
    auto* file=physical(encoded);
    if (!file) { platform_disk_set_last_error(kErrorInvalidHandle); return 0; }
    lock(file); platform_disk_set_last_error(0);
    if (static_cast<std::int32_t>(file->field18)>static_cast<std::int32_t>(file->size)) file->field18=file->size;
    if (static_cast<std::int32_t>(file->field18+requested)>static_cast<std::int32_t>(file->size)) requested=file->size-file->field18;
    std::uint32_t transferred=0;
    std::uint32_t chunk=file->block_size;
    auto* out=static_cast<unsigned char*>(buffer);
    file->padding[0]=1;
    while (requested && file->padding[0]) {
        if (chunk>requested) chunk=requested;
        std::uint32_t read=0;
        if (file->view) {
            heap_copy_dispatch_005323e0(out,reinterpret_cast<const unsigned char*>(static_cast<std::uintptr_t>(file->view))+file->field18,chunk);
            read=chunk;
            file_sleep_0055f740(0);
        } else if (!platform_disk_read_file(reinterpret_cast<void*>(static_cast<std::uintptr_t>(file->os_handle)),out,chunk,&read,nullptr)) {
            if (platform_disk_get_last_error()!=kErrorIoPending) { transferred=0; break; }
            file_sleep_0055f740(1);
            continue;
        }
        file->field18+=read;
        transferred+=read;
        out+=read;
        if (static_cast<std::int32_t>(file->field18)>static_cast<std::int32_t>(file->size)) file->field18=file->size;
        if (read<chunk) break;
        requested-=read;
    }
    file->padding[0]=0;
    unlock(file);
    return transferred;
}

// 00592140
std::uint32_t __cdecl file_backend_seek_00592140(void* encoded,std::uint32_t offset) {
    auto* file=physical(encoded);
    if (!file) { platform_disk_set_last_error(kErrorInvalidHandle); return 0; }
    lock(file); platform_disk_set_last_error(0);
    file->field18=offset;
    if (static_cast<std::int32_t>(offset)>static_cast<std::int32_t>(file->size)) file->field18=file->size;
    else if (static_cast<std::int32_t>(offset)<0) file->field18=0;
    if (!file->view) file->field18=platform_disk_set_file_pointer(
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(file->os_handle)),static_cast<std::int32_t>(file->field18),nullptr,0);
    unlock(file);
    return 1;
}

// 00592290
std::uint32_t __cdecl file_physical_close_00592290(void* encoded) {
    auto* file=physical(encoded);
    if (!file) { platform_disk_set_last_error(kErrorInvalidHandle); return 0; }
    lock(file); platform_disk_set_last_error(0);
    if (file->mapping!=kInvalidHandle) {
        platform_disk_unmap_view(reinterpret_cast<void*>(static_cast<std::uintptr_t>(file->view)));
        platform_disk_close_handle(reinterpret_cast<void*>(static_cast<std::uintptr_t>(file->mapping)));
    }
    if (file->os_handle!=kInvalidHandle) platform_disk_close_handle(reinterpret_cast<void*>(static_cast<std::uintptr_t>(file->os_handle)));
    unlock(file);
    file->active=0;
    return 1;
}
}
