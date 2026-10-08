#include "porsche/file_wait.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00567f70..0056804c. Thread/pump/event boundaries retain original order.
std::int32_t __cdecl file_wait_00567f70(std::uint32_t id) {
    auto* device=devices_006a5c7c+(id&31u);
    if(!id || !device->initialized)return -3;
    for(;;) {
        const auto token=device->initialized ? io_lock_00580ea0(&device->queued) : 0;
        std::int32_t pending;
        auto* operation=operation_find_00567b80(device,id,&pending);
        pending&=operation!=nullptr ? 1 : 0;
        if(device->initialized)io_unlock_00580ec0(&device->queued,token);
        if(!pending)break;
        if(file_current_thread_0055f780(0)) {
            file_pump_005366e0(0);file_sleep_0055f740(1);
        } else {
            // Original re-reads global devices after the thread identity call.
            auto* event=devices_006a5c7c[id&31u].completed_event;
            file_wait_event_0055fc60(event);file_reset_event_0055fc40(event);
        }
    }
    return operation_status_00567af0(id);
}
}
