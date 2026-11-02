// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Eight original bodies /582B. New loader-zero DWORD6a5b2c only; lists/flag,
// thread lock, scheduler, heap and list providers retain canonical ownership.
#include "network_callback_drain_488.hpp"
#include "porsche/network_transport.hpp"
#include "porsche/network_workers_members.hpp"
#include "porsche/event_lifecycle.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/fe_stream.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;
U read(const void* p,U at=0){U v;std::memcpy(&v,static_cast<const std::uint8_t*>(p)+at,4);return v;}
void write(void* p,U at,U v){std::memcpy(static_cast<std::uint8_t*>(p)+at,&v,4);}
void* pointer(U v){return reinterpret_cast<void*>(v);}
using NodeCallback=U(__cdecl*)(void*);
}
U network_callbacks_pending_006a5b2c=0;

void __cdecl network_callbacks_stop_00560380(){
    if(network_callbacks_initialized_006a5b28!=0){
        network_callbacks_drain_005603b0();
        network_worker_queue_dispose_005806c0(&network_callbacks_list_006b7d20);
        network_worker_queue_dispose_005806c0(&network_callbacks_list_006b7d00);
    }
}
void __cdecl network_callbacks_drain_005603b0(){
    if(network_callbacks_initialized_006a5b28==0)return;
    void* node=network_route_at_00580b20(&network_callbacks_list_006b7d20,0);
    while(node){network_callback_dispatch_00560490(node);node=network_route_at_00580b20(&network_callbacks_list_006b7d20,0);}
    node=network_route_at_00580b20(&network_callbacks_list_006b7d00,0);
    while(node){network_callback_dispatch_00560490(node);node=network_route_at_00580b20(&network_callbacks_list_006b7d00,0);}
}
U __cdecl network_callback_dispatch_00560490(void* node){
    U result=0;
    if(node&&read(node,0x14)!=0&&read(node,8)!=0){
        const auto call=reinterpret_cast<NodeCallback>(read(pointer(read(node,8)),0x14));
        result=call(node);
        if(result!=0&&read(pointer(read(node,8)),0x10)!=0){
            const U previous=network_callbacks_pending_006a5b2c;
            if(previous!=0){
                network_callbacks_pending_006a5b2c=previous-1u;
                if(network_callbacks_pending_006a5b2c==0){
                    heap_enter_005322b0(thread_start_lock_006a57d8);
                    auxiliary_event_callback_remove_0053c1d0(network_callback_poll_005602f0);
                    heap_leave_005322c0(thread_start_lock_006a57d8);
                }
            }
        }
        if(read(node,0x34)!=0)network_callback_queue_release_00586e40(node);
    }
    if(file_current_thread_0055f780(0)!=0)timed_callbacks_005366e0(0);
    return result;
}
void __cdecl network_callback_queue_release_00586e40(void* node){
    void* queue=pointer(read(node,0x34));
    if(queue){network_worker_queue_dispose_005806c0(static_cast<IoList*>(queue));free_00531f90(queue);write(node,0x34,0);}
}
void __cdecl network_callback_poll_005602f0(){
    network_callback_enumerate_locked_00580e60(&network_callbacks_list_006b7d20,network_callback_visit_00560310,0);
}
U __cdecl network_callback_visit_00560310(void* node,U){
    const U call=read(pointer(read(node,8)),0x10);
    if(call!=0&&read(node,0x28)!=0)reinterpret_cast<NodeCallback>(call)(node);
    return 1;
}
U __cdecl network_callback_enumerate_locked_00580e60(IoList* list,NetworkCallbackVisit488 predicate,U opaque){
    heap_enter_005322b0(list->lock);
    const U result=network_callback_enumerate_00580dc0(list,predicate,opaque);
    heap_leave_005322c0(list->lock);
    return result;
}
U __cdecl network_callback_enumerate_00580dc0(IoList* list,NetworkCallbackVisit488 predicate,U opaque){
    void* const lock=list->lock;
    heap_enter_005322b0(lock);
    const U original_flag=list->flags&1u;
    list->flags&=~1u;
    heap_leave_005322c0(lock);
    U visited=0;
    void* node=list->head;
    while(node){
        const U captured_flags=list->flags;
        if(captured_flags&1u)break;
        if(predicate(node,opaque)==0)list->flags=captured_flags|1u;
        ++visited;
        node=pointer(read(node));
    }
    heap_enter_005322b0(lock);
    const U flags=list->flags;
    const U result=(flags&1u)?visited:0xffffffffu;
    list->flags=flags|original_flag;
    heap_leave_005322c0(lock);
    return result;
}
}
