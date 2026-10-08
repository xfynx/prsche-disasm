#include "porsche/file_disk.hpp"
#include "porsche/file_events.hpp"
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> calls;
std::uint32_t read_mode,read_bytes,read_error,seek_result,free_result,free_sectors,free_bytes,free_available,read_attempts;
std::array<unsigned char,128> mapped;
std::array<unsigned char,128> output;

std::uint32_t number(const std::string& value) { return static_cast<std::uint32_t>(std::stoul(value,nullptr,0)); }
std::vector<std::string> split(const std::string& value) { std::vector<std::string> parts; std::istringstream in(value); std::string part; while (std::getline(in,part,'|')) parts.push_back(part); return parts; }
std::string hex(const void* address,std::size_t size) { static constexpr char digits[]="0123456789abcdef"; const auto* bytes=static_cast<const unsigned char*>(address); std::string result; result.reserve(size*2); for (std::size_t i=0;i<size;++i) { result+=digits[bytes[i]>>4]; result+=digits[bytes[i]&15]; } return result; }
void record(const std::string& call) { calls.push_back(call); }
}

namespace porsche {
PhysicalFile* physical_files_006af084;
std::int32_t physical_count_006af080;
void __cdecl heap_enter_005322b0(void* mutex) { record("[\"enter\","+std::to_string(reinterpret_cast<std::uintptr_t>(mutex))+"]"); }
void __cdecl heap_leave_005322c0(void* mutex) { record("[\"leave\","+std::to_string(reinterpret_cast<std::uintptr_t>(mutex))+"]"); }
void __cdecl heap_copy_dispatch_005323e0(void* destination,const void* source,std::uint32_t count) {
    std::memcpy(destination,source,count);
}
std::uint32_t __stdcall fake_sleep(std::uint32_t milliseconds,std::int32_t) { record("[\"sleep\","+std::to_string(milliseconds)+"]"); return 0; }
void __stdcall fake_set_last_error(std::uint32_t value) { record("[\"set_last_error\","+std::to_string(value)+"]"); }
std::uint32_t __stdcall fake_read_file(void* handle,void* buffer,std::uint32_t count,std::uint32_t* read,void*) {
    record("[\"read\","+std::to_string(reinterpret_cast<std::uintptr_t>(handle))+","+std::to_string(count)+"]");
    ++read_attempts;
    if (read_mode==0 || (read_mode==2 && read_attempts==1)) return 0;
    *read=read_bytes<count ? read_bytes : count;
    for (std::uint32_t i=0;i<*read;++i) static_cast<unsigned char*>(buffer)[i]=static_cast<unsigned char>(0xa0u+i);
    return 1;
}
std::uint32_t __stdcall fake_get_last_error() { record("[\"get_last_error\"]"); return read_error; }
std::uint32_t __stdcall fake_set_file_pointer(void* handle,std::int32_t offset,std::int32_t*,std::uint32_t method) {
    record("[\"set_file_pointer\","+std::to_string(reinterpret_cast<std::uintptr_t>(handle))+","+std::to_string(offset)+","+std::to_string(method)+"]"); return seek_result;
}
std::uint32_t __stdcall fake_close_handle(void* handle) { record("[\"close\","+std::to_string(reinterpret_cast<std::uintptr_t>(handle))+"]"); return 1; }
std::uint32_t __stdcall fake_unmap_view(void* view) {
    const auto value=view==mapped.data() ? 0x03401000u : static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(view));
    record("[\"unmap\","+std::to_string(value)+"]"); return 1;
}
std::uint32_t __stdcall fake_free_space(const char* root,std::uint32_t* sectors,std::uint32_t* bytes,std::uint32_t* available,std::uint32_t*) {
    record("[\"free_space\",\""+hex(root,4)+"\"]"); *sectors=free_sectors; *bytes=free_bytes; *available=free_available; return free_result;
}
void* __stdcall platform_create_event(void*,std::int32_t,std::int32_t,const char*) { return nullptr; }
std::uint32_t __stdcall platform_set_event(void*) { return 0; }
std::uint32_t __stdcall platform_reset_event(void*) { return 0; }
std::uint32_t __stdcall platform_wait_events(std::uint32_t,void* const*,std::int32_t,std::uint32_t,std::int32_t) { return 0xffffffffu; }
std::uint32_t __stdcall platform_close_handle(void*) { return 0; }
std::uint32_t __stdcall platform_last_error() { return 0; }
std::uint32_t __stdcall platform_sleep(std::uint32_t milliseconds,std::int32_t alertable) { return fake_sleep(milliseconds,alertable); }
}

int main() {
    using namespace porsche;
    std::string line;
    while (std::getline(std::cin,line)) {
        const auto fields=split(line);
        if (fields.size()!=13) return 2;
        const auto operation=number(fields[0]),valid=number(fields[1]),mapped_view=number(fields[2]);
        PhysicalFile storage;
        std::memset(&storage,0xcc,sizeof(storage));
        physical_files_006af084=&storage; physical_count_006af080=1;
        storage.active=valid?1:0; storage.device=3; storage.padding[0]=0; storage.os_handle=0x12345000; storage.mode=0x11223344;
        storage.block_size=number(fields[5]); storage.mapping=mapped_view?0x23456000:0xffffffffu;
        for (std::size_t i=0;i<mapped.size();++i) mapped[i]=static_cast<unsigned char>(0x40u+i);
        storage.view=mapped_view?static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(mapped.data())):0;
        storage.field18=number(fields[3]); storage.size=number(fields[4]);
        std::memset(output.data(),0xcc,output.size()); calls.clear(); read_attempts=0;
        read_mode=number(fields[7]); read_bytes=number(fields[8]); read_error=number(fields[9]); seek_result=number(fields[10]);
        free_result=number(fields[11]); free_sectors=4; free_bytes=512; free_available=0x101;
        disk_mutexes_006aeffc[3]=reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x02001000));
        platform_disk_set_last_error=fake_set_last_error; platform_disk_read_file=fake_read_file; platform_disk_get_last_error=fake_get_last_error;
        platform_disk_set_file_pointer=fake_set_file_pointer; platform_disk_close_handle=fake_close_handle; platform_disk_unmap_view=fake_unmap_view; platform_disk_free_space=fake_free_space;
        const auto handle=reinterpret_cast<void*>(static_cast<std::uintptr_t>(valid==2 ? 0xfffffffeu : (valid ? 0xffffffffu : 0)));
        std::uint32_t mode=0xaaaaaaaa,block=0xbbbbbbbb,size=0xcccccccc,free_bytes_out=0xdddddddd;
        std::uint32_t result=0;
        if (operation==0) result=file_backend_read_00591df0(handle,output.data(),number(fields[6]));
        else if (operation==1) result=file_backend_seek_00592140(handle,number(fields[6]));
        else if (operation==2) result=file_physical_close_00592290(handle);
        else if (operation==3) result=file_backend_info_00591ce0(handle,&mode,&block,&size,number(fields[12])?&free_bytes_out:nullptr);
        else return 2;
        auto normalized=storage;
        if (mapped_view) normalized.view=0x03401000;
        std::cout<<"{\"return\":"<<result<<",\"file\":\""<<hex(&normalized,sizeof(normalized))<<"\",\"buffer\":\""<<hex(output.data(),output.size())<<"\",\"outputs\":["<<mode<<","<<block<<","<<size<<","<<free_bytes_out<<"],\"calls\":[";
        for (std::size_t i=0;i<calls.size();++i) std::cout<<(i ? "," : "")<<calls[i];
        std::cout<<"]}\n";
    }
    return 0;
}
