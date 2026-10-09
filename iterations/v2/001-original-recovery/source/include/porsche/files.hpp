#pragma once
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/heap.hpp"
namespace porsche {
struct IoNode { IoNode* next; };
using IoPredicate=std::int32_t (__cdecl*)(IoNode*,std::uint32_t);
using IoKey=std::uint32_t (__cdecl*)(IoNode*,std::uint32_t);
struct IoList { std::int32_t count; std::uint32_t flags; IoNode *head,*tail; IoKey key; std::uint32_t argument; void* lock; };
using FileCompletion=void (__cdecl*)(std::uint32_t,std::int32_t,void*);
struct FileOperation {
    IoNode* next; std::uint32_t id,type,flags; std::int8_t status; std::uint8_t group; std::uint16_t padding;
    std::uint32_t field14,handle; void* context; FileCompletion callback; std::uint32_t offset,count; void* buffer;
};
struct FileDevice {
    std::uint32_t initialized,thread[7]; FileOperation* current;
    IoList queued,completed; void *queued_event,*lock,*completed_event; std::uint32_t serial,field6c;
};
struct PhysicalFile { std::uint8_t active,device,padding[2]; std::uint32_t os_handle,mode,block_size,mapping,view,field18,size; };
using FileReader=std::uint32_t (__cdecl*)(void*,std::uint32_t,void*,std::int32_t,std::uint32_t,void*);
struct FileReadState {
    std::uint32_t group; void* handle; std::uint32_t offset; std::int32_t remaining; std::uint32_t total;
    std::int32_t chunk; unsigned char* buffer; FileReader reader; std::uint32_t pending;
};
static_assert(sizeof(IoList)==28 && sizeof(FileOperation)==48 && sizeof(FileDevice)==0x70);
static_assert(sizeof(PhysicalFile)==32 && sizeof(FileReadState)==36);
extern FileDevice* devices_006a5c7c;
extern IoList free_operations_006a5c58, free_auxiliary_006a5c38;
extern PhysicalFile* physical_files_006af084;
extern std::int32_t physical_count_006af080;
extern char file_root_006af168[260],file_fallback_006af26c[260],file_roots_enabled_006af370;
extern void (__cdecl* missing_file_006afbe4)(const char*,std::int32_t);

void __cdecl io_append_00580730(IoList*,IoNode*);
IoNode* __cdecl io_pop_00580790(IoList*);
void __cdecl io_sorted_00580850(IoList*,IoNode*);
std::uint32_t __cdecl io_remove_00580930(IoList*,IoNode*);
IoNode* __cdecl io_find_00580ad0(IoList*,IoPredicate,std::uint32_t);
IoNode* __cdecl io_take_00580c10(IoList*,IoPredicate,std::uint32_t);
std::uint32_t __cdecl io_lock_00580ea0(IoList*);
void __cdecl io_unlock_00580ec0(IoList*,std::uint32_t);
std::int32_t __cdecl operation_matches_00567bf0(IoNode*,std::uint32_t);
std::uint32_t __cdecl operation_key_005684c0(IoNode*,std::uint32_t);
FileOperation* __cdecl operation_find_00567b80(FileDevice*,std::uint32_t,std::int32_t*);
std::int32_t __cdecl operation_status_00567af0(std::uint32_t);
std::uint32_t __cdecl operation_complete_00567df0(std::uint32_t);
void __cdecl operation_callback_005680c0(std::uint32_t,FileCompletion);
FileOperation* __cdecl operation_allocate_005682a0(std::uint32_t,std::uint8_t,void*,std::uint32_t);
std::uint32_t __cdecl operation_queue_00568200(FileOperation*);
void __cdecl operation_name_005684e0(FileOperation*,const char*);
std::uint32_t __cdecl request_open_00568aa0(const char*,std::uint32_t,std::uint32_t,void*);
std::uint32_t __cdecl request_close_00568ae0(void*,std::uint32_t,void*);
std::uint32_t __cdecl request_read_00568b10(void*,std::uint32_t,void*,std::int32_t,std::uint32_t,void*);
std::uint32_t __cdecl request_size_00568b90(void*,std::uint32_t,void*);
std::uint32_t __cdecl handle_device_005925d0(void*);
bool __cdecl file_open_00533b90(const char*,std::uint32_t,std::uint32_t,void**);
std::uint32_t __cdecl file_chunks_00533c20(void*,std::uint32_t,void*,std::int32_t,std::uint32_t,FileReader);
void __cdecl file_chunk_complete_00533cd0(std::uint32_t,std::int32_t,void*);

// Disk/thread/platform bindings and diagnostics remain open; page wrappers are recovered.
std::int32_t __cdecl file_exists_00561b80(const char*);
std::uint32_t __cdecl file_device_name_00568e90(const char*);
void __cdecl file_start_device_00568390(std::uint32_t);
std::int32_t __cdecl file_wait_00567f70(std::uint32_t);
std::uint32_t __cdecl file_event_signal_0055fb30(void*);
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t*);
std::uint32_t __cdecl file_object_free_0056e640(void*);
std::uint32_t __cdecl file_physical_close_00592290(void*);
void __cdecl file_format_005a0fbf(char*,const char*,const char*,const char*);
extern void (__cdecl* diagnostic_handler_005debf0)(const char*);
void __cdecl file_diagnostic_00565340(const char*);
void __cdecl file_set_last_error(std::uint32_t);
}
