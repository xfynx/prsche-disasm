#include "porsche/heap.hpp"
#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
using namespace porsche;
unsigned char* arena = nullptr;
std::size_t arena_size = 0;
std::vector<std::string> calls;
std::string hex(const void* p, std::size_t n) {
    static const char d[]="0123456789abcdef"; const auto* b=(const unsigned char*)p; std::string s;
    s.reserve(n*2); for (std::size_t i=0;i<n;++i) { s+=d[b[i]>>4]; s+=d[b[i]&15]; } return s;
}
std::string json(const std::string& s) {
    std::string r="\""; for (unsigned char c:s) { if(c=='\\'||c=='\"') r+='\\',r+=char(c); else if(c>=32) r+=char(c); } return r+'\"';
}
std::vector<unsigned char> unhex(const std::string& s) {
    std::vector<unsigned char> r; if(s.size()%2) return r;
    for(std::size_t i=0;i<s.size();i+=2) r.push_back((unsigned char)std::stoul(s.substr(i,2),nullptr,16)); return r;
}
long long off(const void* p) { return p ? (long long)((const unsigned char*)p-arena) : -1; }
std::vector<std::string> split(const std::string& s,char sep) { std::vector<std::string> r; std::istringstream in(s); std::string x; while(std::getline(in,x,sep)) r.push_back(x); if(!s.empty() && s.back()==sep)r.emplace_back(); return r; }
void record(const std::string& s) { calls.push_back(s); }
int failure_mode=0, failure_count=0;
std::int32_t __cdecl failure(const char* name,std::int32_t size,std::uint32_t flags) {
    record("[\"failure\","+json(name?hex(name,std::strlen(name)):"null")+","+std::to_string(size)+","+std::to_string(flags)+"]");
    return failure_mode==1 && failure_count++==0 ? 1 : 0;
}
}

namespace porsche {
void __cdecl heap_enter_005322b0(void* p) { record("[\"enter\","+std::to_string(off(p))+"]"); }
void __cdecl heap_leave_005322c0(void* p) { record("[\"leave\","+std::to_string(off(p))+"]"); }
void* __cdecl heap_lock_create_005321f0() { record("[\"create\"]"); return (void*)0x02001000; }
void __cdecl heap_format_005a0fbf(char* out,const char* fmt,const char* arg) {
    std::sprintf(out,fmt,arg); record("[\"format\","+json(fmt)+","+json(arg?arg:"")+"]");
}
void __cdecl heap_fill_0053c290(void* p,std::uint32_t value,std::uint32_t size) {
    std::memset(p,(int)value,size); record("[\"fill\","+std::to_string(off(p))+","+std::to_string(value)+","+std::to_string(size)+"]");
}
void __cdecl heap_copy_005b0100(void* d,const void* s,std::uint32_t n) { record("[\"copy100\","+std::to_string(off(d))+","+std::to_string(off(s))+","+std::to_string(n)+"]"); heap_copy_005b0000(d,s,n); }
void __cdecl heap_copy_005b02c0(void* d,const void* s,std::uint32_t n) { record("[\"copy2c0\","+std::to_string(off(d))+","+std::to_string(off(s))+","+std::to_string(n)+"]"); heap_copy_005b0000(d,s,n); }
void __cdecl heap_copy_005b0480(void* d,const void* s,std::uint32_t n) { record("[\"copy480\","+std::to_string(off(d))+","+std::to_string(off(s))+","+std::to_string(n)+"]"); heap_copy_005b0000(d,s,n); }
}

int main() {
    using namespace porsche; constexpr std::uintptr_t base=0x03000000; constexpr std::size_t reserve=0x20000;
    std::string line;
    while (std::getline(std::cin,line)) {
        auto f=split(line,'|'); if(f.size()<7) return 2;
        const auto quantum=(std::uint32_t)std::stoul(f[0]), align=(std::uint32_t)std::stoul(f[1]);
        const auto suffix=std::stoi(f[2]), guard=std::stoi(f[3]), named=std::stoi(f[4]), locked=std::stoi(f[5]); arena_size=(std::size_t)std::stoul(f[6]);
        if(!arena_size || arena_size>reserve) return 2;
        if(arena) VirtualFree(arena,0,MEM_RELEASE); arena=(unsigned char*)VirtualAlloc((void*)base,reserve,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE); if(!arena) return 3;
        std::memset(arena,0xcc,arena_size); calls.clear(); std::vector<void*> slots; std::vector<long long> results; std::vector<std::string> states;
        std::fill(std::begin(heaps_006b4f20),std::end(heaps_006b4f20),nullptr); allocation_failure_0069cb00=nullptr;
        copy_flag_005deb1c=copy_flag_005deb18=copy_flag_005deb30=0;copy_flag_005deb10=1;
        results.push_back(heap_init_005697f0(0,"heap",arena,(std::int32_t)arena_size,quantum,align,suffix,guard,0,named,locked,nullptr));
        states.push_back(hex(arena,arena_size));
        for(std::size_t i=7;i<f.size();++i) { auto a=split(f[i],','); if(a.empty()) continue;
            if(a[0]=="A" && a.size()>=4) { auto n=unhex(a[3]); n.push_back(0); const char* name=a[3]=="-"?nullptr:(const char*)n.data(); void* p=allocate_00531ca0(name,std::stoi(a[1]),std::stoul(a[2],nullptr,0)); slots.push_back(p); results.push_back(off(p)); }
            else if(a[0]=="F" && a.size()>=2) results.push_back(free_00531f90(slots.at(std::stoul(a[1]))));
            else if(a[0]=="R" && a.size()>=3) { void* p=resize_00569640(slots.at(std::stoul(a[1])),std::stoi(a[2])); slots[std::stoul(a[1])]=p; results.push_back(off(p)); }
            else if(a[0]=="W" && a.size()>=3) { auto b=unhex(a[2]); std::memcpy(slots.at(std::stoul(a[1])),b.data(),b.size()); results.push_back(0); }
            else if(a[0]=="B" && a.size()>=3) { auto b=unhex(a[2]); std::memcpy(arena+std::stoul(a[1]),b.data(),b.size()); results.push_back(0); }
            else if(a[0]=="C" && a.size()>=4) results.push_back((long long)heap_copy_005b0000(arena+std::stoul(a[1]),arena+std::stoul(a[2]),std::stoul(a[3])));
            else if(a[0]=="D" && a.size()>=4) { heap_copy_dispatch_005323e0(arena+std::stoul(a[1]),arena+std::stoul(a[2]),std::stoul(a[3])); results.push_back(0); }
            else if(a[0]=="H" && a.size()>=4) results.push_back(off(heap_word_0056e2c0(arena+std::stoul(a[1]),std::stoul(a[2]),std::stoi(a[3]))));
            else if(a[0]=="G" && a.size()>=2) { auto bits=std::stoul(a[1]);copy_flag_005deb1c=bits&1;copy_flag_005deb18=bits&2;copy_flag_005deb10=bits&4;copy_flag_005deb30=bits&8;results.push_back(0); }
            else if(a[0]=="O" && a.size()>=2) { failure_mode=std::stoi(a[1]);failure_count=0;allocation_failure_0069cb00=failure;results.push_back(0); }
            else if(a[0]=="J" && a.size()>=2) results.push_back(heap_init_005697f0(std::stoul(a[1]),"heap",arena,(std::int32_t)arena_size,quantum,align,suffix,guard,0,named,locked,nullptr));
            else return 2;
            states.push_back(hex(arena,arena_size));
        }
        std::cout<<"{\"returns\":["; for(std::size_t i=0;i<results.size();++i) std::cout<<(i?",":"")<<results[i]; std::cout<<"],\"arena\":\""<<hex(arena,arena_size)<<"\",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i) std::cout<<(i?",":"")<<calls[i]; std::cout<<"],\"states\":[";
        for(std::size_t i=0;i<states.size();++i) std::cout<<(i?",":"")<<json(states[i]);std::cout<<"]}\n"; std::cout.flush();
    }
    if(arena) VirtualFree(arena,0,MEM_RELEASE); return 0;
}
