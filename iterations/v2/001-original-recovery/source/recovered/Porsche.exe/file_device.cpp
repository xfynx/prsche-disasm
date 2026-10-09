#include "porsche/file_device.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
std::uint32_t __cdecl io_default_key_00580670(IoNode* node,std::uint32_t) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(node));
}
// 00580630 / 00580680: owned lock versus shared lock and default pointer key.
void __cdecl io_init_00580630(IoList* list,IoKey key,std::uint32_t argument) {
    list->lock=heap_lock_create_005321f0();list->count=0;list->flags=2;
    list->head=list->tail=nullptr;list->key=key ? key : io_default_key_00580670;
    list->argument=argument;
}
void __cdecl io_borrow_00580680(IoList* list,IoKey key,std::uint32_t argument,IoList* source) {
    list->lock=source->lock;list->count=0;list->flags=0;
    list->head=list->tail=nullptr;list->key=key ? key : io_default_key_00580670;
    list->argument=argument;
}
// 00568390..005684b2: worker starts before wait/reset; lock ownership is retained.
void __cdecl file_start_device_00568390(std::uint32_t index) {
    auto* device=devices_006a5c7c+index;
    if(!device->initialized) {
        const auto token=io_lock_00580ea0(&free_operations_006a5c58);
        device->current=nullptr;io_init_00580630(&device->queued,operation_key_005684c0,0);
        io_borrow_00580680(&device->completed,nullptr,0,&device->queued);
        device->queued_event=file_auto_event_0055fb20();
        device->completed_event=file_manual_event_0055fc20();
        device->lock=heap_lock_create_005321f0();device->serial=1;device->field6c=0xff;
        if(file_thread_start_0055f5f0(file_worker_00568530,index,0,1,-1,device->thread)) {
            file_wait_event_0055fc60(device->completed_event);
            file_reset_event_0055fc40(device->completed_event);
            io_unlock_00580ec0(&free_operations_006a5c58,token);return;
        }
        diagnostic_file_005deb74_set("\\real\\pc\\nfile.c");diagnostic_line_005deb78=0xb4;
        diagnostic_handler_005debf0("FILE_startdevice - FAILED TO START THREAD FOR FILE SYSTEM DEVICE.\n");
        io_unlock_00580ec0(&free_operations_006a5c58,token);
    }
}
}
