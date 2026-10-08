#include "porsche/file_device.hpp"
#include "porsche/fe_stream.hpp"
#include <windows.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
using namespace porsche;
constexpr std::uintptr_t IO=0x03100000, HEAP=0x03000000, BUF=0x03200000, ARENA=0x20000;
unsigned char *io,*heap,*buffer; std::vector<std::string> calls; std::vector<unsigned char> filedata; bool present,readfail; std::uint32_t fixture_device;
std::size_t object_used;
std::string expected_name="fe.txt";
std::string hx(const void* p,std::size_t n) { static const char d[]="0123456789abcdef"; auto*b=(const unsigned char*)p; std::string r; r.reserve(n*2); for(size_t i=0;i<n;++i)r+=d[b[i]>>4],r+=d[b[i]&15]; return r; }
std::vector<unsigned char> unhex(const std::string&s) { std::vector<unsigned char>r; if(s=="-"||s.size()%2)return r; for(size_t i=0;i<s.size();i+=2)r.push_back((unsigned char)std::stoul(s.substr(i,2),nullptr,16)); return r; }
std::string j(const std::string&s) { std::string r="\""; for(unsigned char c:s){if(c=='"'||c=='\\')r+='\\'; if(c>=32)r+=(char)c;} return r+'"'; }
std::vector<std::string> split(const std::string&s,char c){std::vector<std::string>r;std::istringstream i(s);std::string x;while(std::getline(i,x,c))r.push_back(x);return r;}
void rec(const std::string&s){calls.push_back(s);} std::string nhex(const char*p){return p?hx(p,std::strlen(p)+1):"";}
std::string io_snapshot(){std::vector<unsigned char>x(io,io+0x5000);auto put=[&](std::size_t p,std::uint32_t v){std::memcpy(x.data()+p,&v,4);};for(int i=0;i<4;++i){auto b=0x100+i*0x70;std::uint32_t key;std::memcpy(&key,x.data()+b+0x34,4);if(key)put(b+0x34,0x005684c0);}auto*ops=(FileOperation*)(io+0x2000);for(int i=0;i<16;++i){auto b=0x2000+i*48;put(b+0x1c,ops[i].context && (std::uintptr_t)ops[i].context!=0xccccccccu ? 0x2200200 : (std::uint32_t)(std::uintptr_t)ops[i].context);put(b+0x20,ops[i].callback==file_chunk_complete_00533cd0 ? 0x00533cd0 : (std::uint32_t)(std::uintptr_t)ops[i].callback);}return hx(x.data(),x.size());}
void __cdecl missing(const char* name,std::int32_t code) { rec("[\"missing\",\""+nhex(name)+"\","+std::to_string(code)+"]"); }
void append_completed(FileDevice*d,FileOperation*o){o->next=nullptr; if(!d->completed.head)d->completed.head=(IoNode*)o;else d->completed.tail->next=(IoNode*)o;d->completed.tail=(IoNode*)o;++d->completed.count;d->completed.flags|=1;}
void signal_device(FileDevice*d){ while(d->queued.head){auto*o=(FileOperation*)d->queued.head; d->queued.head=o->next;if(--d->queued.count==0)d->queued.tail=nullptr;o->next=nullptr; o->status=1;
        if(o->type==0){auto*n=(char*)o->buffer; if(present&&n&&std::strcmp(n,expected_name.c_str())==0)o->handle=(std::uint32_t)~0u;else{o->status=0;o->handle=0;}}
        else if(o->type==1) { /* operation_complete owns the physical close */ }
        else if(o->type==2){auto n=o->offset<filedata.size()?std::min<std::size_t>(o->count,filedata.size()-o->offset):0;if(readfail||!present){n=0;o->status=0;} if(n)std::memcpy(o->buffer,filedata.data()+o->offset,n);o->count=(std::uint32_t)n;}
        else if(o->type==4)o->offset=(std::uint32_t)filedata.size(); append_completed(d,o); }
}
void reset_list(IoList&l,void*lock){std::memset(&l,0,sizeof(l));l.lock=lock;}
}

namespace porsche {
std::int32_t __cdecl compare_005ae3c0(const char*a,const char*b){while(*a&&*b){auto x=(unsigned char)*a++,y=(unsigned char)*b++;if(x>='A'&&x<='Z')x+=32;if(y>='A'&&y<='Z')y+=32;if(x!=y)return x-y;}return (unsigned char)*a-(unsigned char)*b;}
void __cdecl callback_004119e0(std::int32_t){} void __cdecl callback_00411a80(std::int32_t){} void __cdecl callback_00411b40(std::int32_t){}
void __cdecl heap_enter_005322b0(void*p){rec("[\"enter\","+std::to_string((std::uintptr_t)p)+"]");}
void __cdecl heap_leave_005322c0(void*p){rec("[\"leave\","+std::to_string((std::uintptr_t)p)+"]");}
void* __cdecl heap_lock_create_005321f0(){rec("[\"create\"]");return nullptr;}
void __cdecl heap_format_005a0fbf(char*out,const char*fmt,const char*arg){std::sprintf(out,fmt,arg);rec("[\"heap_format\",\""+hx(fmt,std::strlen(fmt)+1)+"\",\""+hx(arg,std::strlen(arg)+1)+"\"]");}
void __cdecl heap_fill_0053c290(void*p,std::uint32_t v,std::uint32_t n){std::memset(p,(int)v,n);rec("[\"fill\","+std::to_string((std::uintptr_t)p)+","+std::to_string(v)+","+std::to_string(n)+"]");}
void __cdecl heap_copy_005b0100(void*d,const void*s,std::uint32_t n){heap_copy_005b0000(d,s,n);} void __cdecl heap_copy_005b02c0(void*d,const void*s,std::uint32_t n){heap_copy_005b0000(d,s,n);} void __cdecl heap_copy_005b0480(void*d,const void*s,std::uint32_t n){heap_copy_005b0000(d,s,n);}
void __cdecl file_event_signal_0055fb30(void*e){rec("[\"signal\","+std::to_string((std::uintptr_t)e)+"]");for(int i=0;i<4;++i)if(devices_006a5c7c[i].queued_event==e)signal_device(devices_006a5c7c+i);}
void __stdcall platform_system_info(void* info) { std::memset(info,0,36);static_cast<std::uint32_t*>(info)[1]=4096;rec("[\"system_info\",4096]"); }
void* __stdcall platform_virtual_alloc(void* requested,std::uint32_t size,std::uint32_t type,std::uint32_t protect) {
    object_used=(object_used+4095)&~4095u;void* result=size ? io+0x5000+object_used : nullptr;
    if(size){std::memset(result,0,size);object_used+=size;}
    rec("[\"virtual_alloc\","+std::to_string((std::uintptr_t)requested)+","+std::to_string(size)+","+std::to_string(type)+","+std::to_string(protect)+","+std::to_string((std::uintptr_t)result)+"]");return result;
}
std::uint32_t __stdcall platform_virtual_free(void* p,std::uint32_t size,std::uint32_t type) { rec("[\"virtual_free\","+std::to_string((std::uintptr_t)p)+","+std::to_string(size)+","+std::to_string(type)+"]");return 1; }
std::uint32_t __cdecl file_device_name_00568e90(const char*n){rec("[\"route\",\""+nhex(n)+"\"]");return fixture_device;}
void __cdecl file_start_device_00568390(std::uint32_t i){devices_006a5c7c[i].initialized=1;}
std::uint32_t __cdecl file_physical_close_00592290(void*p){rec("[\"physical_close\","+std::to_string((std::uintptr_t)p)+"]");if(p==(void*)(std::uintptr_t)~0u)physical_files_006af084[0].active=0;return 1;}
std::int32_t __cdecl file_exists_00561b80(const char*p){rec("[\"exists\",\""+nhex(p)+"\"]");return present&&std::strcmp(p,expected_name.c_str())==0;}
void __cdecl file_format_005a0fbf(char*out,const char*fmt,const char*a,const char*b){std::sprintf(out,fmt,a,b);rec("[\"format\",\""+hx(fmt,std::strlen(fmt)+1)+"\",\""+hx(a,std::strlen(a)+1)+"\",\""+hx(b,std::strlen(b)+1)+"\"]");}
void __cdecl file_set_last_error(std::uint32_t n){rec("[\"last_error\","+std::to_string(n)+"]");}
void __cdecl file_diagnostic_00565340(const char*m){rec("[\"diagnostic\","+std::to_string(diagnostic_line_005deb78)+",\""+hx(m,std::strlen(m)+1)+"\"]");}
std::int32_t __cdecl file_wait_00567f70(std::uint32_t id){rec("[\"wait\","+std::to_string(id)+"]");auto&d=devices_006a5c7c[id&31];for(auto*n=d.completed.head;n;n=n->next)if(((FileOperation*)n)->id==id)return ((FileOperation*)n)->status;return -3;}
}

int main(){using namespace porsche;std::vector<std::pair<std::uint32_t*,std::uint32_t>> initial;for(auto*d=fe_definitions_005d1e40;d->opcode;++d)if(d->target)initial.push_back({d->target,*d->target});std::string line;while(std::getline(std::cin,line)){auto f=split(line,'|');if(f.size()<8)return 2;auto*oldio=io?io:(unsigned char*)VirtualAlloc((void*)IO,ARENA,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);auto*oldh=heap?heap:(unsigned char*)VirtualAlloc((void*)HEAP,ARENA,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);auto*oldb=buffer?buffer:(unsigned char*)VirtualAlloc((void*)BUF,ARENA,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);if(!oldio||!oldh||!oldb)return 3;io=oldio;heap=oldh;buffer=oldb;std::memset(io,0xcc,ARENA);std::memset(heap,0xcc,ARENA);std::memset(buffer,0xcc,ARENA);filedata=unhex(f[1]);present=f[1]!="-";readfail=f[7]!="0";const std::uint32_t off=std::stoul(f[2]),cnt=std::min<std::uint32_t>(std::stoul(f[3]),32768),group=std::stoul(f[4]);auto dev=std::stoul(f[5]);fixture_device=dev;auto serial=std::stoul(f[6])&0xffffff;calls.clear();object_used=0; file_page_size_006a6418=0; expected_name="fe.txt"; file_roots_enabled_006af370=0; missing_file_006afbe4=missing; if(f[0]=="O"){file_roots_enabled_006af370=off!=0;std::strcpy(file_root_006af168,"root/");std::strcpy(file_fallback_006af26c,off==4?"":"fallback/");expected_name=off==0?"fe.txt":off==1?"root/fe.txt":off==2?"fallback/fe.txt":"missing";}
        devices_006a5c7c=(FileDevice*)(io+0x100);std::memset(devices_006a5c7c,0,4*sizeof(FileDevice));for(int i=0;i<4;++i){devices_006a5c7c[i].initialized=1;devices_006a5c7c[i].queued_event=devices_006a5c7c+i;devices_006a5c7c[i].serial=(i==(int)dev)?serial:1;reset_list(devices_006a5c7c[i].queued,nullptr);reset_list(devices_006a5c7c[i].completed,nullptr);devices_006a5c7c[i].queued.key=operation_key_005684c0;devices_006a5c7c[i].queued.argument=0;}
        auto*ops=(FileOperation*)(io+0x2000);reset_list(free_operations_006a5c58,nullptr);reset_list(free_auxiliary_006a5c38,nullptr);free_operations_006a5c58.head=(IoNode*)ops;free_operations_006a5c58.tail=(IoNode*)(ops+15);free_operations_006a5c58.count=16;for(int i=0;i<15;++i)ops[i].next=(IoNode*)&ops[i+1];ops[15].next=nullptr;for(int i=0;i<16;++i)ops[i].flags=0;
        physical_files_006af084=(PhysicalFile*)(io+0x4000);physical_count_006af080=1;std::memset(physical_files_006af084,0,sizeof(PhysicalFile));physical_files_006af084->active=1;physical_files_006af084->device=(std::uint8_t)dev;physical_files_006af084->os_handle=~0u;
        heap_init_005697f0(0,"heap",heap,65536,8,64,0,0,0,0,0,nullptr);std::vector<std::int64_t>ret;std::memset(buffer,0xcc,cnt+16);void*h=nullptr;if(f[0]=="D"){bool ok=file_open_00533b90("fe.txt",1,group,&h);if(ok){ret.push_back(read_00533bf0(h,off,buffer,cnt,group));ret.push_back(size_00533de0(h,group));ret.push_back(close_00533da0(h,group));}}
        if(f[0]=="O") { h=(void*)0x11223344; ret.push_back(open_0059e040("fe.txt",1,group,&h)); ret.push_back((std::uintptr_t)h); if(ret[0]) ret.push_back(close_00533da0(h,group)); }
        if(f[0]=="Q") {
            auto* list=&devices_006a5c7c[0].queued; const auto nodes=filedata.size()/5;
            for(std::size_t i=0;i<nodes;++i) { std::memcpy(&ops[i].id,filedata.data()+i*5,4); ops[i].group=filedata[i*5+4]; ops[i].next=nullptr;ret.push_back(operation_key_005684c0((IoNode*)(ops+i),0));
                if(off)io_append_00580730(list,(IoNode*)(ops+i));else io_sorted_00580850(list,(IoNode*)(ops+i)); }
            ret.push_back((std::uintptr_t)io_find_00580ad0(list,nullptr,0));
            if(nodes) {ret.push_back((std::uintptr_t)io_find_00580ad0(list,operation_matches_00567bf0,ops[0].id));ret.push_back((std::uintptr_t)io_take_00580c10(list,operation_matches_00567bf0,ops[nodes/2].id));ret.push_back(io_remove_00580930(list,(IoNode*)(ops+nodes-1)));}
            ret.push_back(io_remove_00580930(list,(IoNode*)(ops+15)));io_append_00580730(list,nullptr);io_sorted_00580850(list,nullptr);
            for(auto* node=io_pop_00580790(list);node;node=io_pop_00580790(list))ret.push_back((std::uintptr_t)node);
            ret.push_back((std::uintptr_t)io_pop_00580790(list));ret.push_back((std::uintptr_t)io_take_00580c10(list,nullptr,0));
        }
        std::string streamhex,globals,actions;std::vector<int>lengths;if(f[0]=="F"){for(auto&p:initial)*p.first=p.second;std::memset(fe_action_state_005e9130,0,sizeof(fe_action_state_005e9130));auto*s=fe_build_004b6660(0,nullptr);auto*p=s;while(*p&&lengths.size()<4096){auto n=fe_record_words_004b4cd0(p);lengths.push_back(n);p+=n;}streamhex=hx(s,(p-s+1)*4);for(auto*p0=s;*p0;p0+=fe_record_words_004b4cd0(p0))fe_apply_004b4b80(p0);for(auto&p0:initial){if(!globals.empty())globals+=",";globals+=std::to_string(*p0.first);}actions=hx(fe_action_state_005e9130,sizeof(fe_action_state_005e9130));}std::cout<<"{\"returns\":[";for(size_t i=0;i<ret.size();++i)std::cout<<(i?",":"")<<ret[i];std::cout<<"],\"buffer\":\""<<hx(buffer,cnt+16)<<"\",\"io\":\""<<io_snapshot()<<"\",\"objects\":\""<<hx(io+0x5000,object_used)<<"\",\"free_operations\":\""<<hx(&free_operations_006a5c58,sizeof(IoList))<<"\",\"free_auxiliary\":\""<<hx(&free_auxiliary_006a5c38,sizeof(IoList))<<"\",\"heap\":\""<<hx(heap,65536)<<"\",\"calls\":[";for(size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"],\"stream\":\""<<streamhex<<"\",\"globals\":\""<<globals<<"\",\"actions\":\""<<actions<<"\",\"lengths\":[";for(size_t i=0;i<lengths.size();++i)std::cout<<(i?",":"")<<lengths[i];std::cout<<"]}\n";
    }return 0;}
