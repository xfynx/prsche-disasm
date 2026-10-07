#include "porsche/heap.hpp"
#include <cstring>

// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original block/ring layout, unsigned address arithmetic and split thresholds.
namespace porsche {
OriginalHeap* heaps_006b4f20[16];
std::int32_t (__cdecl* allocation_failure_0069cb00)(const char*, std::int32_t, std::uint32_t);
std::uint32_t copy_flag_005deb1c, copy_flag_005deb18, copy_flag_005deb30;
std::uint32_t copy_flag_005deb10=1; // Original initialized PE data; the other flags are zero.

static std::uint32_t address(const void* p) { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p)); }
template<class T> static T* at(std::uint32_t p) { return reinterpret_cast<T*>(static_cast<std::uintptr_t>(p)); }
static HeapFreeBlock* links(HeapBlock* b) { return reinterpret_cast<HeapFreeBlock*>(b); }
static void unlink(HeapBlock* b) {
    auto* f=links(b);
    b->magic=0; b->flags &= 0xbfff;
    links(f->free_previous)->free_next=f->free_next;
    links(f->free_next)->free_previous=f->free_previous;
}
static void insert(OriginalHeap* heap, HeapBlock* b) {
    auto* first=&heap->sentinel.block;
    auto* previous=first;
    auto* next=first;
    const auto midpoint=address(heap->sentinel.free_next)+
        ((address(heap->sentinel.free_previous)-address(heap->sentinel.free_next))>>1);
    if (midpoint<address(b)) {
        do { previous=links(previous)->free_previous; } while (address(b)<address(previous));
        next=links(previous)->free_next;
    } else {
        do { next=links(next)->free_next; } while (address(next)<address(b));
        previous=links(next)->free_previous;
    }
    b->flags |= 0x4000;
    links(b)->free_next=next; links(b)->free_previous=previous;
    b->bytes=static_cast<std::int32_t>(address(b->next)-address(b)-16);
    links(previous)->free_next=b; links(next)->free_previous=b;
    b->magic=0x4246;
}

// 00531c60
std::int32_t __cdecl heap_extra_00531c60(const char* name, std::uint32_t flags) {
    const auto* heap=heaps_006b4f20[flags&15];
    return static_cast<std::int32_t>(heap->suffix+
        (name && (heap->flags&0x100) ? static_cast<std::uint32_t>(std::strlen(name)+1) : 0));
}
// 0056e2c0: big-endian writes of 1..4 bytes; sizes >3 also write four.
void* __cdecl heap_word_0056e2c0(void* p, std::uint32_t value, std::int32_t size) {
    auto* bytes=static_cast<unsigned char*>(p);
    if (size<=0) return p;
    if (size>3) size=4;
    for (std::int32_t i=0;i<size;++i) bytes[i]=static_cast<unsigned char>(value>>((size-1-i)*8));
    return bytes+size;
}
// 005320b0
std::int32_t __cdecl heap_block_005320b0(HeapBlock* b, const char* name, std::int32_t size,
    std::int32_t suffix, std::uint16_t flags, HeapBlock* previous, HeapBlock* next) {
    b->magic=0x424d; b->flags=flags; b->bytes=size; b->next=next; b->previous=previous;
    auto end=address(b)+16+static_cast<std::uint32_t>(size);
    if (flags&0x200) heap_word_0056e2c0(at<void>(end),0x42454e44,4);
    if (flags&0x800) *at<std::uint32_t>(end+12)=0;
    end+=suffix;
    if (name && (flags&0x100)) {
        const auto count=std::strlen(name)+1;
        std::memcpy(at<void>(end),name,count);
        end+=static_cast<std::uint32_t>(std::strlen(at<char>(end))+1);
    }
    return static_cast<std::int32_t>(end-address(b));
}
// 00531ca0
void* __cdecl allocate_00531ca0(const char* name, std::int32_t size, std::uint32_t flags) {
    auto* heap=heaps_006b4f20[flags&15];
    auto* lock=heap->lock;
    for (;;) {
        if (lock) heap_enter_005322b0(lock);
        if (size<0) { if(lock) heap_leave_005322c0(lock); return nullptr; }
        const auto requested=size<8 ? 8 : size;
        const auto mask=heap->quantum-1;
        const auto total=(static_cast<std::uint32_t>(heap_extra_00531c60(name,flags))+mask+16+requested)&~mask;
        const auto needed=static_cast<std::int32_t>(total-16);
        auto* b=&heap->sentinel.block;
        if (!(flags&0x20)) {
            do { b=flags&0x10 ? links(b)->free_previous : links(b)->free_next; } while (b->bytes<needed);
            if (b->magic==0x4253) b=nullptr;
        } else {
            auto threshold=static_cast<std::int32_t>(total-17);
            if (threshold<0) threshold=0;
            HeapBlock* selected=nullptr;
            for (;;) {
                b=flags&0x10 ? links(b)->free_previous : links(b)->free_next;
                if (b->bytes<=threshold) continue;
                if (b->magic==0x4253) break;
                selected=b; threshold=b->bytes;
            }
            b=selected;
        }
        std::int32_t retry=0;
        void* result=nullptr;
        if (!b) {
            if (allocation_failure_0069cb00) retry=allocation_failure_0069cb00(name,size,flags);
        } else {
            unlink(b);
            if (b->bytes-needed>0x40) {
                auto* next=b->next;
                if (!(flags&0x10)) {
                    auto* tail=at<HeapBlock>(address(b)+total);
                    next->previous=tail;
                    heap_block_005320b0(tail,nullptr,0,0,0,b,next);
                    insert(heap,tail); b->next=tail;
                } else {
                    auto* tail=at<HeapBlock>(address(b)+(static_cast<std::uint32_t>(b->bytes-needed)&~mask));
                    next->previous=tail; tail->next=next; tail->previous=b;
                    heap_block_005320b0(b,nullptr,0,0,0,b->previous,tail);
                    insert(heap,b); b=tail;
                }
            }
            auto effective=flags|(heap->flags&0x700);
            if (!name) effective &= ~0x100u;
            heap_block_005320b0(b,name,size,static_cast<std::int32_t>(heap->suffix),
                static_cast<std::uint16_t>(effective),b->previous,b->next);
            result=at<void>(address(b)+16);
        }
        if (lock) heap_leave_005322c0(lock);
        if (retry!=1) return result;
    }
}
// 00531f90
std::uint32_t __cdecl free_00531f90(void* p) {
    if (!p) return 1;
    auto* b=at<HeapBlock>(address(p)-16);
    auto* heap=heaps_006b4f20[b->flags&15]; auto* lock=heap->lock;
    if (lock) heap_enter_005322b0(lock);
    auto* previous=b->previous; auto* next=b->next;
    if (previous->flags&0x4000) {
        unlink(previous);
        previous->next=next; next->previous=previous;
        previous->previous->next=previous;
        b=previous;
    }
    if (next->flags&0x4000) {
        unlink(next); b->next=next->next; next->next->previous=b;
    }
    insert(heap,b);
    if (lock) heap_leave_005322c0(lock);
    return 1;
}
// 00556620, 00556650
std::int32_t __cdecl heap_suffix_00556620(std::uint32_t flags) {
    return static_cast<std::int32_t>(heaps_006b4f20[flags&15]->suffix);
}
const char* __cdecl heap_name_00556650(void* p) {
    const auto* b=at<HeapBlock>(address(p)-16);
    return b->flags&0x100 ? at<char>(address(p)+b->bytes+heap_suffix_00556620(b->flags)) : nullptr;
}
// 005b0000: forward 4/2/1-byte loads and stores, including overlapping inputs.
std::uint64_t __cdecl heap_copy_005b0000(void* destination, const void* source, std::uint32_t size) {
    auto* d=static_cast<unsigned char*>(destination); auto* s=static_cast<const unsigned char*>(source);
    auto step=[&](std::uint32_t count) { std::uint32_t value=0; std::memcpy(&value,s,count); std::memcpy(d,&value,count); d+=count;s+=count;size-=count; };
    if (address(d)&3) {
        if ((address(d)&1) && static_cast<std::int32_t>(size)>0) step(1);
        if ((address(d)&2) && static_cast<std::int32_t>(size)>1) step(2);
        if ((address(d)&4) && static_cast<std::int32_t>(size)>3) step(4);
    }
    while (static_cast<std::int32_t>(size-32)>=0) for(int i=0;i<8;++i) step(4);
    while (static_cast<std::int32_t>(size-8)>=0) { step(4);step(4); }
    if (size>3) step(4);
    if (size>1) step(2);
    if (size) step(1);
    return (static_cast<std::uint64_t>(address(s))<<32)|address(d);
}
// 005323e0; optimized callees still external.
void __cdecl heap_copy_dispatch_005323e0(void* d,const void* s,std::uint32_t n) {
    if(copy_flag_005deb1c) heap_copy_005b0480(d,s,n);
    else if(copy_flag_005deb18) heap_copy_005b02c0(d,s,n);
    else if(copy_flag_005deb10 && copy_flag_005deb30) heap_copy_005b0100(d,s,n);
    else heap_copy_005b0000(d,s,n);
}
// 00569640
void* __cdecl resize_00569640(void* p,std::int32_t size) {
    auto* b=at<HeapBlock>(address(p)-16);
    auto* heap=heaps_006b4f20[b->flags&15]; auto* lock=heap->lock;
    if (lock) heap_enter_005322b0(lock);
    auto* next=b->next;
    if (next->flags&0x4000) { unlink(next); next=next->next; b->next=next; }
    auto request=size;
    if (request<8) { if (request==-1) request=0x40000000; else if(request>-1) request=8; }
    const auto extra=heap_extra_00531c60(heap_name_00556650(p),b->flags);
    const auto mask=heap->quantum-1;
    const auto available=static_cast<std::int32_t>(address(next)-address(b)-16);
    auto needed=static_cast<std::int32_t>(((mask+extra+16+request)&~mask)-16);
    if (available<needed) { needed=available; size=available-extra; }
    heap_copy_dispatch_005323e0(at<void>(address(p)+size),at<void>(address(p)+b->bytes),extra);
    b->bytes=size;
    if (available-needed>0x40) {
        auto* tail=at<HeapBlock>(address(p)+needed+16);
        heap_block_005320b0(tail,nullptr,0,0,0,b,next); insert(heap,tail);
        next->previous=tail; b->next=tail;
    }
    if (lock) heap_leave_005322c0(lock);
    return p;
}
// 005697f0
std::int32_t __cdecl heap_init_005697f0(std::uint32_t index,const char* name,void* memory,
    std::int32_t size,std::uint32_t quantum,std::uint32_t alignment,std::int32_t suffix,
    std::int32_t guard,std::uint32_t,std::int32_t named,std::int32_t locked,void* callback) {
    auto flags=index|(guard ? 0x200 : 0)|(named ? 0x100 : 0);
    auto* low=static_cast<HeapBlock*>(memory);
    auto* first=at<HeapBlock>(((address(memory)+alignment+0x7f+suffix)&~(alignment-1))-16);
    auto* high=at<HeapBlock>(address(memory)+size-suffix-0x30);
    char text[256];
    heap_format_005a0fbf(text,"%s LOW",name);
    heap_block_005320b0(low,text,0x40,suffix,static_cast<std::uint16_t>(flags|0x8000),nullptr,first);
    heap_block_005320b0(first,nullptr,static_cast<std::int32_t>(address(high)-address(first)-16),suffix,
        static_cast<std::uint16_t>(flags),low,high);
    heap_format_005a0fbf(text,"%s HIGH",name);
    heap_block_005320b0(high,text,0,suffix,static_cast<std::uint16_t>(flags|0x8010),first,nullptr);
    auto* heap=at<OriginalHeap>(address(memory)+16); heaps_006b4f20[index&15]=heap;
    heap_fill_0053c290(heap,0,0x40); std::memcpy(heap->name,name,std::strlen(name)+1);
    heap->sentinel.block.magic=0x4253; heap->sentinel.block.bytes=0x7fffffff;
    heap->low=low;heap->high=high;heap->quantum=quantum;heap->arena_alignment=alignment;
    heap->suffix=suffix;heap->flags=flags;heap->lock=nullptr;heap->callback=callback;
    heap->sentinel.free_next=&heap->sentinel.block; heap->sentinel.free_previous=&heap->sentinel.block;
    insert(heap,first);
    if (locked) heap->lock=heap_lock_create_005321f0();
    return first->bytes;
}
}
