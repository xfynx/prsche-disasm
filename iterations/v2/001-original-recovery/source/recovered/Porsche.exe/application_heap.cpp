#include "porsche/application_heap.hpp"
#include <cstddef>

namespace porsche {
std::uint32_t application_page_size_006af3f8=0;
std::uint8_t application_heap_initialized_006af3f4=0;
void* application_primary_arena_006af3b4=nullptr;
std::int32_t application_object_heap_006af3fc=0;
std::uint32_t application_diagnostic_source_005deb74=0;
std::uint32_t application_diagnostic_line_005deb78=0;
std::uint8_t application_heap_records[0x8c0]{};
void* application_queue_indices[16]{};

namespace {
constexpr std::uint32_t record_stride=0x8c;
void*& record_pointer(std::size_t offset){return *reinterpret_cast<void**>(application_heap_records+offset);}
}

// 0059ed40..0059ed8a. The original reads SYSTEM_INFO.dwPageSize once, then
// rounds (requested + page - 1) with unsigned DIV, writing the rounded value
// before calling VirtualAlloc(NULL, rounded, MEM_COMMIT|MEM_RESERVE, READWRITE).
void* __cdecl application_page_alloc_0059ed40(std::uint32_t* bytes){
    auto page=application_page_size_006af3f8;
    if(!page){
        page=application_system_page_size();
        application_page_size_006af3f8=page;
    }
    const auto rounded=static_cast<std::uint32_t>(
        ((static_cast<std::uint32_t>(*bytes+page-1u))/page)*page);
    *bytes=rounded;
    return application_virtual_alloc(nullptr,rounded,0x3000,4);
}

// 0059ed90..0059eda2. The BOOL from VirtualFree is returned as EAX.
std::uint32_t __cdecl application_page_release_0059ed90(void* address){
    return application_virtual_free(address,0,0x8000);
}

// 0059e9d0..0059eb13. The FE allocator setup callees remain explicit
// boundaries. The fixed record layout and call order come from this body.
void __cdecl startup_heap_0059e9d0(std::uint32_t primary_bytes,
    std::uint32_t object_bytes,std::uint32_t third,std::uint32_t fourth){
    application_os_start(0);
    application_page_size_006af3f8=application_system_page_size();
    application_heap_initialized_006af3f4=1;
    application_fill(application_heap_records,0,0x8c0);
    for(std::size_t i=0;i<16;++i)
        record_pointer(i*record_stride)=application_lock_create();
    application_primary_arena_006af3b4=application_page_alloc_0059ed40(&primary_bytes);
    if(application_primary_arena_006af3b4){
        application_heap_commit(application_primary_arena_006af3b4,primary_bytes);
        if(object_bytes){
            application_object_heap_006af3fc=application_object_start(object_bytes,
                "objectHeap",0xffffffffu,1,8);
            if(application_object_heap_006af3fc==-1){
                application_diagnostic_source_005deb74=0x005e5034;
                application_diagnostic_line_005deb78=0xa0;
                application_memory_diagnostic((primary_bytes+object_bytes)>>20);
            }
        }else application_object_heap_006af3fc=0;
    }else{
        application_diagnostic_source_005deb74=0x005e5034;
        application_diagnostic_line_005deb78=0xa0;
        application_memory_diagnostic((primary_bytes+object_bytes)>>20);
    }
    application_secondary_start();
    application_queue_kind(0,0);
    application_queue_kind(1,0);
    application_queue_kind(2,1);
    application_printf_start(16,"NFSPrintf");
    application_heap_kind(2,1);
    application_heap_kind(16,1);
    application_heap_finish(third,0,fourth);
}

// 0059edb0..0059ee23. Startup uses slot zero. The original indexes the
// record and 16-entry table backwards for negative slot IDs.
void __cdecl startup_queue_0059edb0(std::uint32_t count,std::uint32_t slot){
    const auto index=static_cast<std::uint32_t>(-static_cast<std::int32_t>(slot));
    auto* record=application_heap_records+index*record_stride;
    void* lock=*reinterpret_cast<void**>(record);
    void* heap=application_queue_indices[index];
    application_lock_enter(lock);
    for(std::uint32_t i=0;i<count;++i){
        void* node=application_queue_allocate(0x005e5064,0x1000,heap);
        *reinterpret_cast<void**>(static_cast<std::uint8_t*>(node)+4)=
            *reinterpret_cast<void**>(record+4);
        *reinterpret_cast<void**>(record+4)=node;
    }
    application_lock_leave(lock);
}
}
