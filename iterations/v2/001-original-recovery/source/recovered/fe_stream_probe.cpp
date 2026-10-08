// Verification-only services for unresolved original file/heap/CRT/callbacks.
#include "porsche/fe_stream.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
namespace {
using namespace porsche;
struct Allocation { std::string name; std::int32_t size; std::vector<char> data; char* pointer; };
std::vector<std::unique_ptr<Allocation>> allocations;
std::map<std::string,std::vector<char>> files;
std::vector<std::string> calls;
std::int32_t used=0;
std::uint32_t scratch[3][0x160*9+16];
std::string hex(const void* raw,std::size_t n) {
    const auto* p=static_cast<const unsigned char*>(raw); std::string out;
    static const char digits[]="0123456789abcdef";
    for (std::size_t i=0;i<n;++i) { out+=digits[p[i]>>4]; out+=digits[p[i]&15]; }
    return out;
}
std::vector<char> unhex(const std::string& value) {
    std::vector<char> out;
    for (std::size_t i=0;i<value.size();i+=2) out.push_back(static_cast<char>(std::stoul(value.substr(i,2),nullptr,16)));
    return out;
}
std::string quoted(const char* p) { return '"'+hex(p,std::strlen(p))+'"'; }
void callback(int index,std::int32_t value) { calls.push_back("[\"callback\","+std::to_string(index)+","+std::to_string(value)+"]"); }
}
namespace porsche {
std::uint32_t __cdecl callback_004119e0(std::int32_t v) { callback(2,v); return 0; }
std::uint32_t __cdecl callback_00411a80(std::int32_t v) { callback(5,v); return 0; }
std::uint32_t __cdecl callback_00411b40(std::int32_t v) { callback(1,v); return 0; }
std::int32_t __cdecl compare_005ae3c0(const char* a,const char* b) {
    auto lower=[](unsigned char c) { return c>='A' && c<='Z' ? c+32 : c; };
    while (*a && lower(static_cast<unsigned char>(*a))==lower(static_cast<unsigned char>(*b))) { ++a; ++b; }
    return lower(static_cast<unsigned char>(*a))-lower(static_cast<unsigned char>(*b));
}
bool __cdecl open_0059e040(const char* name,std::uint32_t mode,std::uint32_t group,void** handle) {
    calls.push_back("[\"open\","+quoted(name)+","+std::to_string(mode)+","+std::to_string(group)+"]");
    auto f=files.find(name); *handle=f==files.end() ? nullptr : &f->second;
    return *handle!=nullptr;
}
std::int32_t __cdecl size_00533de0(void* handle,std::uint32_t group) {
    auto* f=static_cast<std::vector<char>*>(handle);
    calls.push_back("[\"size\","+std::to_string(group)+"]"); return static_cast<std::int32_t>(f->size());
}
std::uint32_t __cdecl read_00533bf0(void* handle,std::uint32_t offset,void* dest,std::uint32_t size,std::uint32_t group) {
    calls.push_back("[\"read\","+std::to_string(offset)+","+std::to_string(size)+","+std::to_string(group)+"]");
    std::memcpy(dest,static_cast<std::vector<char>*>(handle)->data()+offset,size);
    return size;
}
std::uint32_t __cdecl close_00533da0(void*,std::uint32_t group) { calls.push_back("[\"close\","+std::to_string(group)+"]"); return 1; }
void* __cdecl allocate_00531ca0(const char* name,std::int32_t size,std::uint32_t flags) {
    calls.push_back("[\"allocate\","+quoted(name)+","+std::to_string(size)+","+std::to_string(flags)+"]");
    auto a=std::make_unique<Allocation>(); a->name=name; a->size=size;
    a->data.resize(static_cast<std::size_t>(size)+128,0); a->pointer=a->data.data()+16;
    if (flags==0x10) std::memset(a->pointer,0xcc,size);
    void* result=a->pointer; allocations.push_back(std::move(a)); return result;
}
std::uint32_t __cdecl free_00531f90(void* p) {
    auto it=std::find_if(allocations.begin(),allocations.end(),[p](const auto& a) { return a->pointer==p; });
    calls.push_back("[\"free\","+quoted((*it)->name.c_str())+"]");
    return 1;
}
void* __cdecl resize_00569640(void* p,std::int32_t size) {
    calls.push_back("[\"resize\","+std::to_string(size)+"]"); used=size; return p;
}
}
int main() {
    using namespace porsche;
    std::vector<FeDefinition> initial;
    std::vector<std::uint32_t> words;
    for (auto* d=fe_definitions_005d1e40;;++d) { initial.push_back(*d); words.push_back(d->target ? *d->target : 0); if (!d->opcode) break; }
    std::string line;
    while (std::getline(std::cin,line)) {
        std::vector<std::string> fields; std::istringstream input(line); std::string field;
        while (std::getline(input,field,'|')) fields.push_back(field);
        if (!line.empty() && line.back()=='|') fields.emplace_back();
        if (fields.size()<2) return 2;
        allocations.clear(); calls.clear(); files.clear(); used=0;
        std::fill(&scratch[0][0],&scratch[0][0]+3*(0x160*9+16),0xccccccccu);
        std::fill(fe_action_state_005e9130,fe_action_state_005e9130+0x21e,0);
        for (std::size_t i=0;i<initial.size();++i) { fe_definitions_005d1e40[i]=initial[i]; if (initial[i].target) *initial[i].target=words[i]; }
        if (fields[0]=="V") {
            auto text=unhex(fields[1]); text.push_back(0);
            std::cout<<"{\"value\":"<<fe_value_004b5250(text.data())<<"}\n"; continue;
        }
        if (fields[0]=="T") {
            auto text=unhex(fields[1]); const auto size=text.size(); text.resize(size+128,0);
            char* p=text.data(); char out[1024]; std::memset(out,0xcc,sizeof(out));
            const auto value=fe_read_token_004b51e0(&p,static_cast<char>(std::stoi(fields[2])),static_cast<std::int16_t>(std::stoi(fields[3])),out);
            std::cout<<"{\"offset\":"<<(p-text.data())<<",\"token\":\""<<hex(out,std::strlen(out))<<"\",\"count\":"<<(value&65535)
                     <<",\"high_pointer\":"<<((value>>16)==(reinterpret_cast<std::uintptr_t>(p)>>16) ? "true" : "false")<<"}\n"; continue;
        }
        if (fields.size()<4) return 2;
        if (fields[0]=="X") {
            FeDefinition custom[]={{0x10e,scratch[0],"STR"},{0x142,scratch[1],"VEC"},{0x21e,nullptr,"CAR"},
                {0x13a,scratch[0],"TEXT"},{0x147,scratch[1],"LIST"},{0x220,scratch[2],"FIELD"},
                {0x21f,scratch[2],"TYPE"},{0x14e,nullptr,"ACTION"},{7,&fe_enabled_0065b298,"FE"},
                {1,nullptr,"IMPORT"},{0,nullptr,nullptr}};
            std::copy(std::begin(custom),std::end(custom),fe_definitions_005d1e40);
        }
        if (fields[1]!="missing") files["fe.txt"]=unhex(fields[1]);
        if (fields[2]!="missing") files["addon.txt"]=unhex(fields[2]);
        if (fields[3]!="missing") files["nested.txt"]=unhex(fields[3]);
        std::vector<std::vector<char>> args;
        for (std::size_t i=4;i<fields.size();++i) {
            auto text=unhex(fields[i]); text.resize(text.size()+128,0); args.push_back(std::move(text));
        }
        std::vector<char*> argv; for (auto& a:args) argv.push_back(a.data());
        auto* stream=fe_build_004b6660(static_cast<std::int32_t>(argv.size()),argv.data());
        const auto enabled=fe_enabled_0065b298;
        std::vector<std::int32_t> lengths;
        for (auto* record=stream;*record;) {
            fe_apply_004b4b80(record); const auto length=fe_record_words_004b4cd0(record);
            if (length<=0 || lengths.size()>4096) return 3;
            lengths.push_back(length); record+=length;
        }
        std::cout<<"{\"stream\":\""<<hex(stream,used)<<"\",\"enabled\":"<<enabled<<",\"final_enabled\":"<<fe_enabled_0065b298<<",\"lengths\":[";
        for (std::size_t i=0;i<lengths.size();++i) { if (i) std::cout<<','; std::cout<<lengths[i]; }
        std::cout<<"],\"globals\":[";
        for (std::size_t i=0;i<initial.size();++i) { if (i) std::cout<<','; std::cout<<(initial[i].target ? *initial[i].target : 0); }
        std::cout<<"],\"scratch\":\""<<(fields[0]=="X" ? hex(scratch,sizeof(scratch)) : "")<<"\",\"actions\":\""
                 <<hex(fe_action_state_005e9130,sizeof(fe_action_state_005e9130))<<"\",\"calls\":[";
        for (std::size_t i=0;i<calls.size();++i) { if (i) std::cout<<','; std::cout<<calls[i]; }
        std::cout<<"],\"file_buffers\":["; bool first=true;
        for (const auto& a:allocations) if (a->name!="FE Data Stream") {
            if (!first) std::cout<<','; first=false;
            std::cout<<'['<<quoted(a->name.c_str())<<",\""<<hex(a->pointer,a->size)<<"\"]";
        }
        std::cout<<"]}\n";
    }
}
