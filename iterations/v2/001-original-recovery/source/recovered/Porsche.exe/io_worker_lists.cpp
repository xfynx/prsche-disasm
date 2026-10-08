#include "porsche/file_worker.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 005806e0..00580721; lock captured before mutation, including null node.
void __cdecl io_prepend_005806e0(IoList* list,IoNode* node) {
    auto* lock=list->lock;heap_enter_005322b0(lock);
    if(node) {
        auto* head=list->head;node->next=head;list->head=node;++list->count;
        if(!head)list->tail=node;
        list->flags|=1u;
    }
    heap_leave_005322c0(lock);
}
// 005808f0..00580928; unlock reads the list's current lock.
std::uint32_t __cdecl io_locked_remove_005808f0(IoList* list,IoNode* node) {
    std::uint32_t result=0;heap_enter_005322b0(list->lock);
    if(node)result=io_remove_00580930(list,node);
    heap_leave_005322c0(list->lock);return result;
}
}
