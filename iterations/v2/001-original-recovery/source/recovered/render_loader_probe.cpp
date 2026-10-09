#include "porsche/render_loader.hpp"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

namespace {
int mode,missing,has_module,about_kind,major,proc_index;
std::string calls;
std::uint32_t about_word;
void record(const std::string& part){calls+=part+';';}
std::string hex(const void* data,std::size_t size) {
    constexpr char digits[]="0123456789abcdef";
    std::string result;result.reserve(size*2);
    const auto* bytes=static_cast<const unsigned char*>(data);
    for(std::size_t i=0;i<size;++i){result+=digits[bytes[i]>>4];result+=digits[bytes[i]&15];}
    return result;
}
}
namespace porsche {
std::uint32_t __cdecl render_win_load_library_005b2050(const char* name) {
    record(std::string("load|")+name);
    return (mode==1 || (mode==2 && std::strcmp(name,"dx7z")==0))
        ? (std::strcmp(name,"dx7z")==0?0x22220000:0x11110000):0;
}
std::uint32_t __cdecl render_win_get_proc_005b205c(std::uint32_t module,const char* name) {
    record("getproc|"+std::to_string(module)+"|"+name);
    const int current=proc_index++;
    return current==missing?0:0x03600000+static_cast<std::uint32_t>(current)*0x10;
}
void __cdecl render_win_free_library_005b2088(std::uint32_t module){record("free|"+std::to_string(module));}
std::uint32_t __cdecl render_win_get_module_005b2138(const char* name) {
    record(std::string("module|")+name);return has_module?0x33330000:0;
}
void __cdecl render_win_disable_thread_calls_005b21b4(std::uint32_t module) {
    record("disable|"+std::to_string(module));
}
std::uint32_t __cdecl render_win_last_error_005b213c(){record("lasterror");return 5;}
void __cdecl render_loader_format_005a0fbf(char* out,const char* format,...) {
    va_list args;va_start(args,format);
    std::vsprintf(out,format,args);va_end(args);
    record(std::string("format|")+format+"|"+out);
}
void __cdecl render_loader_report_00565340(const char* message) {
    record(std::string("report|")+message);
}
void __cdecl render_loader_directx_00574eb0(std::uint32_t result[2],const char* dll) {
    record(std::string("directx|")+dll);result[0]=0;result[1]=static_cast<std::uint32_t>(major);
}
void __cdecl render_loader_reset_00594f00(std::uint32_t token) {
    record("reset|"+std::to_string(token));
}
void __cdecl render_loader_set_state_006bd97c(std::uint32_t,std::uint32_t key,std::uint32_t value) {
    record("setstate|"+std::to_string(key)+"|"+std::to_string(value));
}
const std::uint32_t* __cdecl render_loader_about_006bd934(std::uint32_t) {
    record("about");
    about_word=about_kind==1?0x33444658:about_kind==2?0x33444632:0x11223344;
    return about_kind?&about_word:nullptr;
}
}
int main() {
    using namespace porsche;
    std::uint32_t token;
    while(std::cin>>mode>>missing>>has_module>>about_kind>>major>>token) {
        proc_index=0;calls.clear();
        for(auto& value:render_thrash_exports_006bd910)value=0xcccccccc;
        render_library_handle_0069e5e8=0x9999;
        render_cleanup_token_0069e5ec=token;
        render_driver_name_006a64b4=0x7777;
        render_error_flag_005deb70=0x88;
        render_error_file_005deb74=0x6666;
        render_error_line_005deb78=0x5555;
        const auto ret=render_load_thrash_00574fa0(mode==0?nullptr:"dx7");
        std::cout<<"{\"ret\":"<<ret<<",\"exports\":\""
                 <<hex(render_thrash_exports_006bd910,sizeof(render_thrash_exports_006bd910))
                 <<"\",\"handle\":"<<render_library_handle_0069e5e8
                 <<",\"driver\":"<<(render_driver_name_006a64b4==0x7777?0x7777:0x03200000)
                 <<",\"err_flag\":"<<render_error_flag_005deb70
                 <<",\"err_file\":"<<render_error_file_005deb74
                 <<",\"err_line\":"<<render_error_line_005deb78
                 <<",\"calls\":\""<<hex(calls.data(),calls.size())<<"\"}\n";
    }
}
