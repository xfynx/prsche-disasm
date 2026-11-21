// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00455830..004558a6 and004558b0..00455926, each119B, thiscall RET8.
#include "scene_tree_constructors_731.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/heap.hpp"
#include <cstring>
namespace {
void* get(void* base, unsigned off) {
    void* v; std::memcpy(&v, static_cast<unsigned char*>(base)+off,4); return v;
}
void put(void* base, unsigned off, void* v) {
    std::memcpy(static_cast<unsigned char*>(base)+off,&v,4);
}
void* construct(void* self, std::uint8_t* first, unsigned pool_offset, unsigned kind) {
    put(self,0,nullptr);
    auto* ctx=static_cast<unsigned char*>(porsche::application_context_heap_state_005e4fe8());
    void* lock_slot=ctx+0x28;
    porsche::heap_enter_005322b0(get(lock_slot,0));
    if(get(ctx,pool_offset)==nullptr) porsche::application_context_new_head_0059eeb0(kind,0);
    void* node=get(ctx,pool_offset);
    put(ctx,pool_offset,get(node,4));
    porsche::heap_leave_005322c0(get(lock_slot,0));
    put(self,0,node);
    put(self,4,nullptr);
    static_cast<unsigned char*>(self)[8]=*first;
    static_cast<unsigned char*>(node)[0]=0;
    put(get(self,0),4,nullptr);
    void* current=get(self,0); put(current,8,current);
    current=get(self,0); put(current,12,current);
    return self;
}
}
namespace porsche {
void* __fastcall scene_stage_tree_ctor_00455830(void* self, void*, std::uint8_t* first, std::uint8_t*) {
    return construct(self,first,0x78u,0x11u);
}
void* __fastcall scene_stage_tree_ctor_004558b0(void* self, void*, std::uint8_t* first, std::uint8_t*) {
    return construct(self,first,0x3cu,2u);
}
}
