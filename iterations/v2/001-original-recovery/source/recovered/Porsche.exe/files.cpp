#include "porsche/files.hpp"
#include <cstring>
#include <algorithm>
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Native service wrappers retain original queue/completion and 0x2000 chunking.
namespace porsche {
FileDevice* devices_006a5c7c;
IoList free_operations_006a5c58,free_auxiliary_006a5c38;
PhysicalFile* physical_files_006af084;
std::int32_t physical_count_006af080;
char file_root_006af168[260],file_fallback_006af26c[260],file_roots_enabled_006af370;
void (__cdecl* missing_file_006afbe4)(const char*,std::int32_t);
const char* diagnostic_file_005deb74;
std::uint32_t diagnostic_line_005deb78;
void (__cdecl* diagnostic_handler_005debf0)(const char*)=file_diagnostic_00565340;
static void error(std::uint32_t line,const char* message) {
    diagnostic_file_005deb74="\\real\\pc\\nfile.c";diagnostic_line_005deb78=line;
    diagnostic_handler_005debf0(message);
}
static std::uint32_t number(const void* p) { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p)); }
static void* pointer(std::uint32_t p) { return reinterpret_cast<void*>(static_cast<std::uintptr_t>(p)); }
// 00567bf0, 005684c0: supplementary callbacks, missed by automatic function analysis.
std::int32_t __cdecl operation_matches_00567bf0(IoNode* node,std::uint32_t id) {
    return reinterpret_cast<FileOperation*>(node)->id==id;
}
std::uint32_t __cdecl operation_key_005684c0(IoNode* node,std::uint32_t) {
    const auto* op=reinterpret_cast<FileOperation*>(node);
    return ((static_cast<std::int32_t>(op->id)>>5)&0xffffffu)|(static_cast<std::uint32_t>(op->group)<<24);
}
// 00567b80
FileOperation* __cdecl operation_find_00567b80(FileDevice* device,std::uint32_t id,std::int32_t* pending) {
    *pending=0;
    if (!device->initialized) return nullptr;
    if (device->current && device->current->id==id) { *pending=-1;return device->current; }
    auto* op=reinterpret_cast<FileOperation*>(io_find_00580ad0(&device->queued,operation_matches_00567bf0,id));
    if (op) { *pending=1;return op; }
    return reinterpret_cast<FileOperation*>(io_find_00580ad0(&device->completed,operation_matches_00567bf0,id));
}
// 00567af0
std::int32_t __cdecl operation_status_00567af0(std::uint32_t id) {
    auto* device=devices_006a5c7c+(id&31);
    const auto lock=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
    std::int32_t pending;auto* op=operation_find_00567b80(device,id,&pending);
    auto status=pending ? 0 : !op ? -3 : (op->flags&2) ? -1 : static_cast<std::int32_t>(op->status);
    if(device->initialized) io_unlock_00580ec0(&device->queued,lock);
    return status;
}
// 005682a0
FileOperation* __cdecl operation_allocate_005682a0(std::uint32_t type,std::uint8_t group,void* context,std::uint32_t index) {
    auto* op=reinterpret_cast<FileOperation*>(io_pop_00580790(&free_operations_006a5c58));
    auto* device=devices_006a5c7c+index;
    if(!op) { error(0xd1,"FILE_allocateop - NO FREE OPS LEFT TO ALLOCATE.\n");return nullptr; }
    if(!device->initialized) file_start_device_00568390(index);
    op->group=group;op->type=type;op->status=0;op->flags &= 0xfffffff0;
    op->field14=0;op->handle=0;op->context=context;op->callback=nullptr;
    op->offset=0;op->count=0;op->buffer=nullptr;
    const auto lock=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
    const auto next=(device->serial+1)&0xffffff;
    op->id=(device->serial<<5)|index;device->serial=next ? next : 1;
    if(device->initialized) io_unlock_00580ec0(&device->queued,lock);
    return op;
}
// 00568200
std::uint32_t __cdecl operation_queue_00568200(FileOperation* op) {
    auto* device=devices_006a5c7c+(op->id&31);
    if(!device) error(0xf9,"FILE_queueop - ATTEMPT TO QUEUE FILEOP ON NON-EXISTANT DEVICE.\n");
    io_sorted_00580850(&device->queued,reinterpret_cast<IoNode*>(op));
    file_event_signal_0055fb30(device->queued_event);return op->id;
}
// 005684e0: zero-filled initial BSS byte, also referenced by FE runtime.
char file_null_name_005e8e50[1]={0};
void __cdecl operation_name_005684e0(FileOperation* op,const char* name) {
    if(!name) name=file_null_name_005e8e50;
    const auto bytes=static_cast<std::uint32_t>(std::strlen(name)+1);
    auto size=bytes;
    op->flags |= 1;op->buffer=file_object_allocate_0056e5f0(&size);
    heap_copy_dispatch_005323e0(op->buffer,name,bytes);
}
// 00568aa0/00568ae0/00568b10/00568b90
std::uint32_t __cdecl request_open_00568aa0(const char* name,std::uint32_t mode,std::uint32_t group,void* context) {
    auto* op=operation_allocate_005682a0(0,static_cast<std::uint8_t>(group),context,file_device_name_00568e90(name));
    operation_name_005684e0(op,name);op->offset=mode;return operation_queue_00568200(op);
}
std::uint32_t __cdecl request_close_00568ae0(void* handle,std::uint32_t group,void* context) {
    auto* op=operation_allocate_005682a0(1,static_cast<std::uint8_t>(group),context,handle_device_005925d0(handle));
    op->handle=number(handle);return operation_queue_00568200(op);
}
std::uint32_t __cdecl request_read_00568b10(void* handle,std::uint32_t offset,void* buffer,std::int32_t count,std::uint32_t group,void* context) {
    auto* op=operation_allocate_005682a0(2,static_cast<std::uint8_t>(group),context,handle_device_005925d0(handle));
    op->handle=number(handle);op->offset=offset;op->count=static_cast<std::uint32_t>(count);op->buffer=buffer;
    return operation_queue_00568200(op);
}
std::uint32_t __cdecl request_size_00568b90(void* handle,std::uint32_t group,void* context) {
    auto* op=operation_allocate_005682a0(4,static_cast<std::uint8_t>(group),context,handle_device_005925d0(handle));
    op->handle=number(handle);return operation_queue_00568200(op);
}
// 005925d0
std::uint32_t __cdecl handle_device_005925d0(void* handle) {
    const auto value=number(handle);const auto index=static_cast<std::int32_t>(~value);
    if(physical_files_006af084 && static_cast<std::int32_t>(value)<0 && index<physical_count_006af080) {
        const auto* file=physical_files_006af084+static_cast<std::uint32_t>(index);
        if(file->active) return file->device;
    }
    file_set_last_error(6);return 0;
}
// 00567df0
std::uint32_t __cdecl operation_complete_00567df0(std::uint32_t id) {
    auto* device=devices_006a5c7c+(id&31);
    auto* op=reinterpret_cast<FileOperation*>(io_take_00580c10(&device->completed,operation_matches_00567bf0,id));
    if(!op) error(0x3ce,"FILESYS_completeop - OPERATION NOT FOUND IN COMPLETED LIST.\n");
    std::uint32_t result=0;
    switch(op->type) {
    case 0:
        if(!(op->flags&2) || !op->handle) result=op->handle;
        else file_physical_close_00592290(pointer(op->handle));
        break;
    case 1:result=file_physical_close_00592290(pointer(op->handle));break;
    case 2:case 3:result=op->count;break;
    case 4:case 6:result=op->offset;break;
    case 8:break;
    case 9: {
        auto* auxiliary=static_cast<std::uint32_t*>(op->buffer);
        if(auxiliary) {
            if(!(op->flags&2) && op->status==1) { io_append_00580730(&free_auxiliary_006a5c38,reinterpret_cast<IoNode*>(auxiliary));result=auxiliary[1]; }
            else { if(auxiliary[3]) file_physical_close_00592290(pointer(auxiliary[3]));file_object_free_0056e640(auxiliary); }
        }
        break;
    }
    case 10: {
        auto* auxiliary=static_cast<std::uint32_t*>(op->buffer);
        if(auxiliary) { file_physical_close_00592290(pointer(auxiliary[3]));file_object_free_0056e640(auxiliary);result=1; }
        break;
    }
    default:result=op->status==1;break;
    }
    if(op->flags&1) file_object_free_0056e640(op->buffer);
    op->id=0;io_append_00580730(&free_operations_006a5c58,reinterpret_cast<IoNode*>(op));return result;
}
// 005680c0
void __cdecl operation_callback_005680c0(std::uint32_t id,FileCompletion callback) {
    auto* device=devices_006a5c7c+(id&31);
    if(!callback) error(0x4b8,"FILESYS_callbackop - can not specify a NULL callback.\n");
    const auto lock=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
    std::int32_t pending;auto* op=operation_find_00567b80(device,id,&pending);
    if(!op) error(0x4cb,"FILESYS_callbackop - UNKNOWN FILEOP.\n");
    else {
        op->flags |= 4;
        if(!pending) { op->flags |= 8;op->callback=nullptr;callback(op->id,op->status,op->context); }
        else op->callback=callback;
    }
    if(device->initialized) io_unlock_00580ec0(&device->queued,lock);
}
// 00533b90
bool __cdecl file_open_00533b90(const char* name,std::uint32_t mode,std::uint32_t group,void** handle) {
    const auto id=request_open_00568aa0(name,mode,group,nullptr);
    if(!id) { *handle=nullptr;return false; }
    file_wait_00567f70(id);const auto status=operation_status_00567af0(id);
    *handle=pointer(operation_complete_00567df0(id));return status==1;
}
// 0059e040
bool __cdecl open_0059e040(const char* name,std::uint32_t mode,std::uint32_t group,void** handle) {
    char path[260];
    if(!file_roots_enabled_006af370) std::strcpy(path,name);
    else {
        file_format_005a0fbf(path,"%s%s",file_root_006af168,name);
        if(!file_exists_00561b80(path)) {
            if(!*file_fallback_006af26c) { if(missing_file_006afbe4) missing_file_006afbe4(name,-2);return false; }
            file_format_005a0fbf(path,"%s%s",file_fallback_006af26c,name);
            if(!file_exists_00561b80(path)) { if(missing_file_006afbe4) missing_file_006afbe4(name,-2);return false; }
        }
    }
    return file_open_00533b90(path,mode,group,handle);
}
// 00533c20, 00533cd0
std::uint32_t __cdecl file_chunks_00533c20(void* handle,std::uint32_t offset,void* buffer,
    std::int32_t count,std::uint32_t group,FileReader reader) {
    FileReadState state{group,handle,offset,count,0,std::min(count,0x2000),static_cast<unsigned char*>(buffer),reader,0};
    state.pending=reader(handle,offset,buffer,state.chunk,group,&state);
    if(state.pending) {
        operation_callback_005680c0(state.pending,file_chunk_complete_00533cd0);
        while(state.remaining || state.pending) file_wait_00567f70(state.pending);
    }
    return state.total;
}
void __cdecl file_chunk_complete_00533cd0(std::uint32_t id,std::int32_t status,void* context) {
    auto* state=static_cast<FileReadState*>(context);
    const auto count=operation_complete_00567df0(id);state->pending=0;
    if(status==1) {
        state->offset+=count;state->total+=count;state->buffer+=count;
        if(static_cast<std::int32_t>(count)<state->chunk) state->remaining=0;
        else state->remaining-=count;
        if(state->remaining>0) {
            state->chunk=std::min(state->remaining,0x2000);
            state->pending=state->reader(state->handle,state->offset,state->buffer,state->chunk,state->group,state);
            if(state->pending) { operation_callback_005680c0(state->pending,file_chunk_complete_00533cd0);return; }
        }
    }
    state->remaining=0;
}
// 00533bf0/00533da0/00533de0
std::uint32_t __cdecl read_00533bf0(void* handle,std::uint32_t offset,void* buffer,std::uint32_t count,std::uint32_t group) {
    return file_chunks_00533c20(handle,offset,buffer,static_cast<std::int32_t>(count),group,request_read_00568b10);
}
std::uint32_t __cdecl close_00533da0(void* handle,std::uint32_t group) {
    const auto id=request_close_00568ae0(handle,group,nullptr);
    if(!id) return 0;file_wait_00567f70(id);return operation_complete_00567df0(id);
}
std::int32_t __cdecl size_00533de0(void* handle,std::uint32_t group) {
    const auto id=request_size_00568b90(handle,group,nullptr);
    if(!id) return 0;file_wait_00567f70(id);return static_cast<std::int32_t>(operation_complete_00567df0(id));
}
}
