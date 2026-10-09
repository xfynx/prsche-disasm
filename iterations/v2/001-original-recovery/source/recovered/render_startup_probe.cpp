#include "porsche/render_startup.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> calls;
std::string registry_text,registry_resolution;
std::uint32_t choice;
std::string hex(const char* s) {
    constexpr char digits[]="0123456789abcdef"; std::string out;
    for (const unsigned char* p=reinterpret_cast<const unsigned char*>(s);*p;++p) {
        out+=digits[*p>>4];out+=digits[*p&15];
    }
    return out;
}
std::string hexbytes(const void* data,std::size_t count) {
    constexpr char digits[]="0123456789abcdef";std::string out;
    const auto* p=static_cast<const unsigned char*>(data);
    for(std::size_t i=0;i<count;++i){out+=digits[p[i]>>4];out+=digits[p[i]&15];}
    return out;
}
std::string unhex(const std::string& s) {
    if(s=="-")return {};
    std::string out;
    for(std::size_t i=0;i<s.size();i+=2)out+=static_cast<char>(std::stoul(s.substr(i,2),nullptr,16));
    return out;
}
std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> result;std::stringstream in(line);std::string item;
    while(std::getline(in,item,'|'))result.push_back(item);
    return result;
}
void record(const std::string& entry){calls.push_back(entry);}
struct CoreFixture: porsche::RenderCore { std::uint8_t tail[0x114]{}; void __thiscall first_00() override {record("[\"first\"]");} } core;
porsche::RenderDisplay display{};
int allocations;
void set_field(std::size_t offset,std::uint32_t value){std::memcpy(display.bytes+offset,&value,4);}
}
namespace porsche {
void* __cdecl render_allocate_0059ef90(std::uint32_t size){record("[\"alloc\","+std::to_string(size)+"]");return ++allocations==1?static_cast<void*>(&core):static_cast<void*>(&display);}
RenderCore* __cdecl render_construct_core_00467700(void*,const char* publisher,const char* title){
    record("[\"core_ctor\",\""+hex(publisher)+"\",\""+hex(title)+"\"]");return &core;
}
RenderDisplay* __cdecl render_construct_display_004677e0(void*,const char* name,std::uint32_t selected,
                                                            std::uint32_t zero,const char* resolution){
    record("[\"display_ctor\",\""+hex(name)+"\","+std::to_string(selected)+","+
           std::to_string(zero)+",\""+hex(resolution)+"\"]");
    set_field(0x74,0x11223344);set_field(0x7c,0x55667788);return &display;
}
void __cdecl render_registry_text_004b7240(RenderCore*,std::uint32_t index,char* out){
    record("[\"regtext\","+std::to_string(index)+"]");
    std::strcpy(out,index==0?registry_text.c_str():registry_resolution.c_str());
}
std::uint32_t __cdecl render_registry_choice_004b7340(RenderCore*,std::uint32_t index){
    record("[\"choice\","+std::to_string(index)+"]");return choice;
}
void __cdecl render_registry_activate_004b7220(RenderCore*){record("[\"activate\"]");}
void __cdecl render_format_005a0fbf(char* out,const char*,std::uint32_t width,std::uint32_t height){
    record("[\"format\","+std::to_string(width)+","+std::to_string(height)+"]");
    std::sprintf(out,"%dx%d",static_cast<std::int32_t>(width),static_cast<std::int32_t>(height));
}
void __cdecl render_display_apply_004b70d0(std::uint32_t field7c,std::uint32_t field74){
    record("[\"apply\","+std::to_string(field7c)+","+std::to_string(field74)+"]");
}
void __cdecl render_misc_00465df0(){record("[\"misc1\"]");}
void __cdecl render_misc_00449b40(){record("[\"misc2\"]");}
[[noreturn]] void __cdecl render_missing_setup_00467535(){std::abort();}
}
int main(){
    using namespace porsche;
    std::string line,display_name;
    while(std::getline(std::cin,line)){
        const auto f=split(line);if(f.size()!=9)return 2;
        const auto selector=unhex(f[0]);registry_text=unhex(f[1]);registry_resolution=unhex(f[2]);display_name=unhex(f[3]);
        render_selected_00657a58=static_cast<std::uint32_t>(std::stoul(f[4]));
        render_width_00657a48=static_cast<std::uint32_t>(std::stoul(f[5]));
        render_height_00657a4c=static_cast<std::uint32_t>(std::stoul(f[6]));
        const bool existing=std::stoul(f[7])!=0;choice=static_cast<std::uint32_t>(std::stoul(f[8]));
        if(selector.size()>=sizeof(render_selector_00657a38))return 3;
        std::memset(render_selector_00657a38,0,sizeof(render_selector_00657a38));
        std::memcpy(render_selector_00657a38,selector.c_str(),selector.size()+1);
        render_display_name_0065b304=display_name.c_str();
        render_core_0065b39c=nullptr;render_display_00628130=existing?&display:nullptr;
        std::memset(display.bytes,0,sizeof(display.bytes));
        set_field(0x74,0x11223344);set_field(0x7c,0x55667788);
        calls.clear();allocations=0;
        render_startup_00467470();
        std::cout<<"{\"core\":"<<(render_core_0065b39c!=nullptr)<<",\"display\":"
                 <<(render_display_00628130!=nullptr)<<",\"selector\":\""
                 <<hexbytes(render_selector_00657a38,sizeof(render_selector_00657a38))
                 <<"\",\"display_state\":\""<<hexbytes(display.bytes,sizeof(display.bytes))
                 <<"\",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];
        std::cout<<"]}\n";
    }
}
