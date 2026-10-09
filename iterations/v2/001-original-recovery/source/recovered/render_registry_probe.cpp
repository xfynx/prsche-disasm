#include "porsche/render_registry.hpp"
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace {
struct Scenario {
    int op,index,seed;
    std::uint32_t handle;
    int opens[3],create_status,close_status,queries[2];
    std::uint32_t data_size,data_seed,number;
} current;
std::string events;
std::uint32_t open_index,query_index;
struct Value {std::uint32_t type=0;std::vector<std::uint8_t> data;};
std::map<std::string,Value> store;

void record(const std::string& s){if(!events.empty())events+=';';events+=s;}
void put32(void* base,std::size_t offset,std::uint32_t value){std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,4);}
std::uint32_t get32(const void* base,std::size_t offset){std::uint32_t v;std::memcpy(&v,static_cast<const std::uint8_t*>(base)+offset,4);return v;}
std::string hex(const void* p,std::size_t size){constexpr char d[]="0123456789abcdef";std::string s;s.reserve(size*2);auto*b=static_cast<const std::uint8_t*>(p);for(std::size_t i=0;i<size;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}

std::int32_t __stdcall fake_open(std::uint32_t root,const char* path,std::uint32_t options,
    std::uint32_t access,std::uint32_t* output){
    const auto n=open_index++;
    const auto status=current.opens[n<2?n:2];
    record("open|"+std::to_string(root)+"|"+path+"|"+std::to_string(options)+"|"+
        std::to_string(access)+"|"+std::to_string(status));
    if(status==0)*output=0x51000000u+n;
    return status;
}
std::int32_t __stdcall fake_create(std::uint32_t root,const char* path,std::uint32_t* output){
    const auto status=current.create_status;
    record("create|"+std::to_string(root)+"|"+path+"|"+std::to_string(status));
    if(status==0)*output=0x52000000u;
    return status;
}
std::int32_t __stdcall fake_close(std::uint32_t key){
    record("close|"+std::to_string(key)+"|"+std::to_string(current.close_status));
    return current.close_status;
}
std::int32_t __stdcall fake_query(std::uint32_t key,const char* name,std::uint32_t* reserved,
    std::uint32_t* type,std::uint8_t* data,std::uint32_t* size){
    const auto cap=*size;const auto ix=query_index++;
    const auto status=current.queries[ix<2?ix:1];
    auto it=store.find(name);
    std::vector<std::uint8_t> payload;
    if(status==0){
        if(it!=store.end())payload=it->second.data;
        else if(current.op==3){payload.resize(4);std::memcpy(payload.data(),&current.number,4);}
        else {payload.resize(current.data_size);for(std::size_t i=0;i<payload.size();++i)payload[i]=static_cast<std::uint8_t>(current.data_seed+i);}
        *size=static_cast<std::uint32_t>(payload.size());
        if(data&&!payload.empty())std::memcpy(data,payload.data(),std::min<std::size_t>(cap,payload.size()));
        if(type)*type=it==store.end()?1:it->second.type;
    }
    record("query|"+std::to_string(key)+"|"+name+"|"+std::to_string(cap)+"|"+
        std::to_string(reserved!=nullptr)+"|"+std::to_string(type!=nullptr)+"|"+
        std::to_string(status)+"|"+std::to_string(*size)+"|"+hex(data,status==0?std::min<std::size_t>(*size,cap):0));
    return status;
}
std::int32_t __stdcall fake_set(std::uint32_t key,const char* name,std::uint32_t reserved,
    std::uint32_t type,const std::uint8_t* data,std::uint32_t size){
    store[name]={type,std::vector<std::uint8_t>(data,data+size)};
    record("set|"+std::to_string(key)+"|"+name+"|"+std::to_string(reserved)+"|"+
        std::to_string(type)+"|"+std::to_string(size)+"|"+hex(data,size));
    return 0;
}
const porsche::RenderRegistryApi fake_api{fake_open,fake_create,fake_close,fake_query,fake_set};
}

int main(){
    using namespace porsche;
    const char company[]="Electronic Arts",title[]="Need for Speed - Porsche Unleashed";
    while(std::cin>>current.op>>current.index>>current.seed>>current.handle>>
        current.opens[0]>>current.opens[1]>>current.opens[2]>>current.create_status>>
        current.close_status>>current.queries[0]>>current.queries[1]>>current.data_size>>
        current.data_seed>>current.number){
        alignas(4) std::uint8_t core[0x118];std::memset(core,current.seed&255,sizeof(core));
        put32(core,0,0x005b3fbc);put32(core,4,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(company)));
        put32(core,0x0c,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(title)));
        put32(core,0x114,current.handle);
        std::array<char,256> out;out.fill(static_cast<char>(current.seed&255));
        open_index=query_index=0;events.clear();store.clear();render_registry_bind_api(&fake_api);
        std::uint32_t result=0;
        auto* object=reinterpret_cast<RenderCore*>(core);
        if(current.op==0)result=render_registry_first_result_004b76f0(object);
        else if(current.op==1)render_registry_activate_004b7220(object);
        else if(current.op==2)render_registry_text_004b7240(object,current.index,out.data());
        else if(current.op==3)result=render_registry_choice_004b7340(object,current.index);
        else if(current.op==4)render_registry_defaults_004b7150(object);
        else if(current.op==5)render_core_first_004b76f0(object);
        put32(core,4,0x03200000);put32(core,0x0c,0x03200100);
        std::cout<<"{\"ret\":"<<result<<",\"core\":\""<<hex(core,sizeof(core))
                 <<"\",\"out\":\""<<hex(out.data(),out.size())<<"\",\"calls\":\""
                 <<hex(events.data(),events.size())<<"\"}\n";
    }
    render_registry_bind_api(nullptr);
}
