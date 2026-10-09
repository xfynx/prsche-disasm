#include "porsche/application_alloc.hpp"
#include "porsche/application_heap.hpp"
#include "porsche/fe_stream.hpp"

namespace porsche {
// 00531f70..00531f87: active table entry delegates all three arguments.
void* __cdecl application_allocator_entry_00531f70(const char* source,
    std::uint32_t bytes,std::uint32_t heap_index){
    return allocate_00531ca0(source,static_cast<std::int32_t>(bytes),heap_index);
}

// 0059ef90..0059efb5: operator new, using object heap 006af3fc.
void* __cdecl startup_network_allocate_0059ef90(std::uint32_t bytes){
    return application_allocator_entry_00531f70("new",bytes?bytes:1,
        static_cast<std::uint32_t>(application_object_heap_006af3fc));
}

// 0059efc0..0059efe4: same source and an explicit heap index.
void* __cdecl application_allocate_in_heap_0059efc0(std::uint32_t bytes,std::uint32_t heap_index){
    return application_allocator_entry_00531f70("new",bytes?bytes:1,heap_index);
}

// 0059eff0..0059f010 and 0059f020..0059f044: operator new[].
void* __cdecl application_allocate_array_0059eff0(std::uint32_t bytes){
    return application_allocator_entry_00531f70("new[]",bytes?bytes:1,0);
}
void* __cdecl application_allocate_array_in_heap_0059f020(std::uint32_t bytes,std::uint32_t heap_index){
    return application_allocator_entry_00531f70("new[]",bytes?bytes:1,heap_index);
}

// 0059f050..0059f062: null is returned directly; active table +8 is
// 00531f90, the already recovered FE heap free.
std::uint32_t __cdecl application_release_0059f050(void* address){
    return address?free_00531f90(address):0;
}
}
