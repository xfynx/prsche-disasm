#include "porsche/file_worker.hpp"
#include <cstring>
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// BSS initial value. 00568530..005688cc, dispatch cells 005688d0..005688fb.
std::uint32_t file_shutdown_006a5c80=0;
void __cdecl file_worker_00568530(std::uint32_t index) {
    auto* device=devices_006a5c7c+index;
    device->initialized=1;file_worker_signal_0055fc30(device->completed_event);
    while(!file_shutdown_006a5c80) {
        const auto token=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
        auto* operation=reinterpret_cast<FileOperation*>(io_pop_00580790(&device->queued));
        device->current=operation;
        if(operation && static_cast<std::int32_t>(operation->group)>static_cast<std::int32_t>(device->field6c)) {
            io_sorted_00580850(&device->queued,reinterpret_cast<IoNode*>(operation));
            device->current=nullptr;operation=nullptr;
        }
        if(device->initialized)io_unlock_00580ec0(&device->queued,token);
        if(!device->current)file_worker_wait_0055fb90(device->queued_event);
        else {
            if(!(operation->flags&2u)) {
                auto* handle=reinterpret_cast<void*>(operation->handle);
                switch(operation->type) {
                case 0: {
                    const auto mode=operation->offset;
                    std::uint32_t flags,extra=0;
                    if(mode&1u) {flags=5;extra=1;}
                    else {flags=(mode&2u) ? 0x13u : 3u;if(mode&4u)flags|=0x20u;}
                    if(mode&8u)flags|=0x800u;
                    if(mode&0x10u)flags|=0x100u;
                    if(mode&0x20u)flags|=0x200u;
                    auto* result=file_backend_open_00568900(static_cast<const char*>(operation->buffer),flags,extra);
                    operation->handle=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(result));
                    if(result)operation->status=1;
                    else {operation->field14=file_last_error_0055fce0();operation->status=-2;}
                    break;
                }
                case 1:operation->status=1;break;
                case 2:
                case 3: {
                    const bool reading=operation->type==2;
                    if(file_backend_seek_00592140(handle,operation->offset)) {
                        operation->count=reading ? file_backend_read_00591df0(handle,operation->buffer,operation->count)
                                                          : file_backend_write_00591fa0(handle,operation->buffer,operation->count);
                        operation->status=1;
                    }
                    operation->field14=file_last_error_0055fce0();
                    if(operation->field14)operation->status=-2;
                    break;
                }
                case 4: {
                    std::uint32_t size;
                    if(file_backend_info_00591ce0(handle,nullptr,nullptr,&size,nullptr)) {
                        operation->status=1;operation->offset=size;
                    } else {operation->offset=0;operation->status=-2;operation->field14=file_last_error_0055fce0();}
                    break;
                }
                case 5:
                    operation->status=file_backend_005924d0(handle,operation->count) ? 1 : -2;
                    if(operation->status==-2)operation->field14=file_last_error_0055fce0();
                    break;
                case 6: {
                    auto* result=file_backend_open_00568900(static_cast<const char*>(operation->buffer),5,1);
                    operation->handle=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(result));
                    if(result) {file_physical_close_00592290(result);operation->offset=1;}
                    else operation->offset=0;
                    operation->status=1;break;
                }
                case 7:
                    if(file_backend_00591980(operation->buffer))operation->status=1;
                    else {operation->status=-2;operation->field14=file_last_error_0055fce0();}
                    break;
                case 8:operation->status=1;operation->field14=0;break;
                case 9:
                    if(operation->buffer) {
                        auto* bytes=static_cast<unsigned char*>(operation->buffer);
                        auto* result=file_backend_open_00568900(reinterpret_cast<const char*>(bytes+0x14),0x805,1);
                        const auto raw=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(result));
                        std::memcpy(bytes+0xc,&raw,4);
                        if(result) {
                            operation->status=1;
                            const auto value=file_backend_00592490(result);std::memcpy(bytes+0x10,&value,4);
                        } else {operation->status=-2;operation->field14=file_last_error_0055fce0();}
                    }
                    break;
                case 10:
                    io_locked_remove_005808f0(&free_auxiliary_006a5c38,static_cast<IoNode*>(operation->buffer));
                    operation->status=1;break;
                default:
                    diagnostic_file_005deb74_set("\\real\\pc\\nfile.c");diagnostic_line_005deb78=0x1f8;
                    reinterpret_cast<void(__cdecl*)(const char*,...)>(diagnostic_handler_005debf0)(
                        "FILE_devicethread - UNKNOWN TYPE OF OPERATION %d.\n",operation->type);
                    break;
                }
            }
            const auto completion_token=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
            io_prepend_005806e0(&device->completed,reinterpret_cast<IoNode*>(operation));
            device->current=nullptr;
            if(device->initialized)io_unlock_00580ec0(&device->queued,completion_token);
            if(operation->callback) {
                operation->flags|=8u;
                const auto status=(operation->flags&2u) ? -1 : static_cast<std::int32_t>(operation->status);
                operation->callback(operation->id,status,operation->context);
            }
            file_worker_signal_0055fc30(device->completed_event);
        }
    }
    device->initialized=0;
}
}
