#include "porsche/file_device.hpp"
namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0056e5f0..0056e639: retain LEA wrap, signed IDIV and low IMUL word.
std::uint32_t file_page_size_006a6418;
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t* size) {
    if(!file_page_size_006a6418) {
        std::uint32_t system_info[9];
        platform_system_info(system_info);
        file_page_size_006a6418=system_info[1];
    }
    const auto page=file_page_size_006a6418;
    const auto numerator=static_cast<std::int32_t>(*size+page-1);
    const auto quotient=numerator/static_cast<std::int32_t>(page);
    *size=static_cast<std::uint32_t>(quotient)*page;
    return platform_virtual_alloc(nullptr,*size,0x3000,4);
}
// 0056e640..0056e652: VirtualFree EAX is returned without modification.
std::uint32_t __cdecl file_object_free_0056e640(void* pointer) {
    return platform_virtual_free(pointer,0,0x8000);
}
}
