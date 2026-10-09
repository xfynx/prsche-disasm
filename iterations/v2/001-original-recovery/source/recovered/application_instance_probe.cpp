#include "porsche/application_instance.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace {
std::uint32_t last_error=0;
std::uint32_t mutex_result=0x03604000;
std::uint32_t found_window=0x03605000;
bool terminal=false;
std::vector<std::string> calls;
std::uint32_t addr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
std::string quote(const char* value){if(!value)return "null";return "\""+std::string(value)+"\"";}
std::string list(){std::string s;for(std::size_t i=0;i<calls.size();++i){if(i)s+=',';s+=calls[i];}return s;}
}

namespace porsche {
const char* window_class_name_0069e5a8=nullptr;
const char** class_name_override_006afcc0=nullptr;
void* __cdecl application_instance_create_mutex(void*,std::uint32_t initial_owner,const char* name){
    calls.emplace_back("[\"create_mutex\",0,"+std::to_string(initial_owner)+","+quote(name)+"]");
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(mutex_result));
}
std::uint32_t __cdecl application_instance_get_last_error(){calls.emplace_back("[\"get_last_error\"]");return last_error;}
void* __cdecl application_instance_find_window(const char* cls,const char* title){
    calls.emplace_back("[\"find_window\","+quote(cls)+","+quote(title)+"]");
    return found_window?reinterpret_cast<void*>(static_cast<std::uintptr_t>(found_window)):nullptr;
}
std::int32_t __cdecl application_instance_show_window(void* window,std::int32_t command){
    calls.emplace_back("[\"show_window\","+std::to_string(addr(window))+","+std::to_string(command)+"]");return 1;
}
std::int32_t __cdecl application_instance_set_foreground_window(void* window){
    calls.emplace_back("[\"foreground\","+std::to_string(addr(window))+"]");return 1;
}
void __cdecl application_instance_exit_005a246e(std::uint32_t code){
    calls.emplace_back("[\"exit_boundary_005a246e\","+std::to_string(code)+"]");terminal=true;
}
}

int main(){
    std::uint32_t global_name,argument_name,override_name,mutex,last,window,exit_flag;
    while(std::cin>>global_name>>argument_name>>override_name>>mutex>>last>>window>>exit_flag){
        calls.clear();terminal=false;mutex_result=mutex;last_error=last;found_window=window;
        porsche::application_instance_mutex_006a5c28=nullptr;
        porsche::application_instance_exit_requested_005df9bc=exit_flag;
        static const char porsche_name[]="Porsche";
        static const char alternate_name[]="Other";
        static const char override_value[]="Override";
        auto choose=[](std::uint32_t id,const char* a,const char* b,const char* c){
            return id==1?a:(id==2?b:(id==3?c:nullptr));
        };
        porsche::window_class_name_0069e5a8=choose(global_name,porsche_name,alternate_name,override_value);
        const char* override_ptr=choose(override_name,porsche_name,alternate_name,override_value);
        porsche::class_name_override_006afcc0=override_name?&override_ptr:nullptr;
        const char* arg=choose(argument_name,porsche_name,alternate_name,override_value);
        const auto result=porsche::application_instance_check_005655f0(arg);
        std::cout<<"{\"terminal\":"<<(terminal?"true":"false");
        if(!terminal)std::cout<<",\"return\":"<<result;
        std::cout<<",\"name\":"<<quote(porsche::window_class_name_0069e5a8)
          <<",\"mutex\":"<<addr(porsche::application_instance_mutex_006a5c28)
          <<",\"calls\":["<<list()<<"]}\n";
    }
}
