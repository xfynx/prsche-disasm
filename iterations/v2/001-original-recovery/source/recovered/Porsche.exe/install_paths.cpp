#include "porsche/install_paths.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/game_setup.hpp"
#include <cstdint>

namespace porsche {
namespace {
std::uint32_t address(const void* value) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
std::uint8_t read_byte(std::uint32_t at) {
    return *reinterpret_cast<const std::uint8_t*>(static_cast<std::uintptr_t>(at));
}
}

std::uint32_t __cdecl install_paths_size_00556640(const void* blob) {
    return *reinterpret_cast<const std::uint32_t*>(address(blob)-12u);
}

std::uint32_t __cdecl install_paths_load_004b6ff0() {
    auto* const blob=game_setup_resource_file_open_0059d8e0("install.txt",0);
    install_paths_blob_0065b29c=blob;
    std::uint32_t eax=install_paths_size_00556640(blob);
    std::uint32_t cursor=address(blob);
    const std::uint32_t limit=cursor+eax-2u;
    auto table_address=address(install_paths_table_0065b2a0);
    for(std::uint32_t i=0;i<60u;++i)
        *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(table_address+i*4u))=0;
    eax=0; // XOR EAX,EAX before REP STOSD in the original.
    if(cursor>=limit)return eax;

    std::uint32_t slot=0;
    for(;;){
        cursor+=3u;
        *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(table_address+slot*4u))=cursor;
        ++slot;
        eax=read_byte(cursor); // MOV AL,[ESI]
        if(eax!=0x0au && eax!=0x0du){
            for(;;){
                eax=read_byte(cursor+1u); // MOV AL,[ESI+1]
                ++cursor;
                if(eax==0x0au || eax==0x0du)break;
            }
        }
        if(cursor>=limit)break;
        *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cursor))=0;
        eax=read_byte(cursor+1u);
        ++cursor;
        while(eax==0x0au || eax==0x0du){
            eax=read_byte(cursor+1u);
            ++cursor;
        }
        if(cursor>=limit)break;
    }
    return eax;
}

std::uint32_t __cdecl install_paths_cleanup_004b7070() {
    auto* const blob=install_paths_blob_0065b29c;
    if(blob)return free_00531f90(blob);
    return 0;
}
}
