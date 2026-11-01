// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00591fa0 /408B and005924d0 /183B. Canonical physical-file/lock state reused.
#include "file_stream_queries_477.hpp"
#include <windows.h>
namespace porsche {
namespace {
using U=std::uint32_t;using I=std::int32_t;
void* pointer(U value){return reinterpret_cast<void*>(value);}
U number(const void* value){return reinterpret_cast<U>(value);}
U __stdcall os_write_file(void* handle,const void* buffer,U count,U* written,void* overlapped){
    return ::WriteFile(handle,buffer,count,reinterpret_cast<DWORD*>(written),reinterpret_cast<OVERLAPPED*>(overlapped));
}
U __stdcall os_set_end_of_file(void* handle){return ::SetEndOfFile(handle);}
bool valid(U slot){return physical_files_006af084&&static_cast<I>(slot)>=0&&static_cast<I>(slot)<physical_count_006af080&&physical_files_006af084[slot].active;}
}
DiskWriteFile platform_disk_write_file=os_write_file;
DiskSetEndOfFile platform_disk_set_end_of_file=os_set_end_of_file;

U __cdecl file_backend_write_00591fa0(void* encoded,void* buffer,U requested){
    U written=number(encoded);
    const U slot=~written;
    if(!valid(slot)){platform_disk_set_last_error(6);return 0;}
    const U device=physical_files_006af084[slot].device;
    heap_enter_005322b0(disk_mutexes_006aeffc[device]);
    platform_disk_set_last_error(0);
    auto* base=physical_files_006af084;
    auto& initial=base[slot];
    if(static_cast<I>(initial.field18)>static_cast<I>(initial.size)) initial.field18=initial.size;
    U chunk=initial.block_size;
    if(initial.view&&static_cast<I>(initial.field18+requested)>static_cast<I>(initial.size)) requested=initial.size-initial.field18;
    U transferred=0;
    U input=number(buffer);
    while(requested){
        if(chunk>requested) chunk=requested;
        auto& file=base[slot];
        if(file.view){
            heap_copy_dispatch_005323e0(pointer(file.view+file.field18),pointer(input),chunk);
            written=chunk;
            file_sleep_0055f740(0);
        } else if(!platform_disk_write_file(pointer(file.os_handle),pointer(input),chunk,&written,nullptr)){
            if(platform_disk_get_last_error()!=0x3e5u){transferred=0;break;}
            file_sleep_0055f740(1);
            base=physical_files_006af084;
            continue;
        }
        base=physical_files_006af084;
        auto& current=base[slot];
        const U position=current.field18+written;
        current.field18=position;
        transferred+=written;
        input+=written;
        requested=written<chunk?0:requested-written;
        if(static_cast<I>(position)>static_cast<I>(current.size)) current.size=position;
    }
    heap_leave_005322c0(disk_mutexes_006aeffc[device]);
    return transferred;
}

U __cdecl file_backend_005924d0(void* encoded,U offset){
    const U slot=~number(encoded);
    if(!valid(slot)){platform_disk_set_last_error(6);return 0;}
    const U device=physical_files_006af084[slot].device;
    heap_enter_005322b0(disk_mutexes_006aeffc[device]);
    platform_disk_set_last_error(0);
    U result=0;
    if(!physical_files_006af084[slot].view){
        result=platform_disk_set_end_of_file(pointer(physical_files_006af084[slot].os_handle));
        const U position=platform_disk_set_file_pointer(pointer(physical_files_006af084[slot].os_handle),static_cast<I>(offset),nullptr,0);
        physical_files_006af084[slot].field18=position;
    }
    heap_leave_005322c0(disk_mutexes_006aeffc[device]);
    return result;
}
}
