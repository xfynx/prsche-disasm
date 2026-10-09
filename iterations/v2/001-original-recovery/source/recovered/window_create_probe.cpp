#include "porsche/window_create.hpp"
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> calls;
bool register_success;
bool worker_success;
void add(const std::string& s){calls.push_back(s);}
}
namespace porsche {
// Standalone fixture state; production definitions belong to window_runtime.cpp.
const char* window_class_name_0069e5a8=nullptr;
void* window_instance_006b7794=nullptr;
void* __cdecl window_lock_create_005321f0(){add("[\"lock\"]");return reinterpret_cast<void*>(0x2220000);}
void* __stdcall window_module_handle(const char*){add("[\"module\"]");return reinterpret_cast<void*>(0x1234000);}
void* __stdcall window_load_icon(void* instance,const char* resource){
    add("[\"icon\","+std::to_string(reinterpret_cast<std::uintptr_t>(instance))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(resource))+"]");return reinterpret_cast<void*>(0x1235000);
}
void* __stdcall window_load_cursor(void* instance,const char* resource){
    add("[\"cursor\","+std::to_string(reinterpret_cast<std::uintptr_t>(instance))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(resource))+"]");return reinterpret_cast<void*>(0x1236000);
}
void* __stdcall window_stock_object(std::int32_t index){
    add("[\"stock\","+std::to_string(index)+"]");return reinterpret_cast<void*>(0x1237000);
}
std::uint16_t __stdcall window_register_class(const OriginalWndClassA* cls){
    add("[\"register\","+std::to_string(cls->style)+",\"wndproc\","+
        std::to_string(cls->class_extra)+","+std::to_string(cls->window_extra)+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(cls->instance))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(cls->icon))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(cls->cursor))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(cls->background))+",\""+
        cls->menu_name+"\",\""+cls->class_name+"\"]");
    return register_success?1:0;
}
std::uint32_t __stdcall window_last_error(){add("[\"last_error\"]");return 0xdead;}
void __cdecl window_register_diagnostic(const char* format,std::uint32_t error){
    add("[\"diagnostic\",\""+std::string(format)+"\","+std::to_string(error)+"]");
}
std::int32_t __stdcall window_procedure_0053aba0(void*,std::uint32_t,std::uint32_t,std::int32_t){return 0;}
// Unused boundaries from the linked 0053bb00 object.
std::int32_t __stdcall window_get_system_metrics(std::int32_t){return 0;}
std::uint32_t __stdcall window_adjust_rect(WindowRect*,std::uint32_t,std::int32_t,std::uint32_t){return 0;}
void* __stdcall window_create_ex(std::uint32_t,const char*,const char*,std::uint32_t,
    std::int32_t,std::int32_t,std::int32_t,std::int32_t,void*,void*,void*,void*){return nullptr;}
void* __stdcall window_set_cursor(void*){return nullptr;}
std::int32_t __stdcall window_show_cursor(std::int32_t){return 0;}
void __cdecl window_channel_005739b0(std::uint32_t,std::uint32_t){}
std::uint32_t __stdcall window_handler_register_0053a800(std::uint32_t message,std::uint32_t handler){
    add("[\"handler\","+std::to_string(message)+","+std::to_string(handler)+"]");
    return 1;
}
void __cdecl window_resize_0053bec0(std::uint32_t width,std::uint32_t height){
    add("[\"resize\","+std::to_string(width)+","+std::to_string(height)+"]");
}
std::uint32_t __cdecl window_worker_0053b8d0(void*){return 0;}
std::uint32_t __cdecl window_thread_start_0055f420(void* worker,std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t* state){
    add("[\"thread_start\",\"worker\","+std::to_string(a)+","+std::to_string(b)+","+
        std::to_string(c)+"]");
    if(worker!=reinterpret_cast<void*>(&window_worker_0053b8d0))return 0;
    if(!worker_success)return 0;
    for(std::uint32_t i=0;i<7;++i)state[i]=0x100+i;
    window_thread_handle_0069e574=reinterpret_cast<void*>(0x1238000);
    window_hwnd_006b7bf8=reinterpret_cast<void*>(0x1230000);
    return 1;
}
std::uint32_t __cdecl window_timed_callback_005366e0(std::uint32_t arg){
    add("[\"tick\","+std::to_string(arg)+"]");return 0;
}
void __cdecl window_idle_0055f740(std::uint32_t arg){add("[\"idle\","+std::to_string(arg)+"]");}
void __cdecl window_prepare_0053bcb0(){add("[\"prepare\"]");}
void __cdecl window_thread_wait_0055fb30(void* thread){
    add("[\"wait\","+std::to_string(reinterpret_cast<std::uintptr_t>(thread))+"]");
    window_thread_handle_0069e574=nullptr;
}
void* __stdcall window_set_foreground(void* hwnd){
    add("[\"foreground\","+std::to_string(reinterpret_cast<std::uintptr_t>(hwnd))+"]");return hwnd;
}
std::uint32_t __stdcall window_system_parameters(std::uint32_t action,std::uint32_t value,void* output,std::uint32_t flags){
    add("[\"spi\","+std::to_string(action)+","+std::to_string(value)+","+
        std::to_string(output?1:0)+","+std::to_string(flags)+"]");
    if(output)*static_cast<std::uint32_t*>(output)=action==0x10?1:0;
    return 1;
}
}
int main(int argc,char**){
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream in(line);std::uint32_t previous,lock,name,success;
        in>>previous>>lock>>name>>success;if(!in)return 2;
        std::uint32_t handlers=0,prior_hwnd=0,thread_success=0,fullscreen=0,width=640,height=480;
        if(argc>1){in>>handlers>>prior_hwnd>>thread_success>>fullscreen>>width>>height;if(!in)return 3;}
        calls.clear();register_success=success!=0;
        worker_success=thread_success!=0;
        porsche::class_lock_0069e59c=lock?reinterpret_cast<void*>(0x2220000):nullptr;
        porsche::class_refcount_0069e594=previous;
        static const char* override_name="Override";
        porsche::class_name_override_006afcc0=name==2?&override_name:nullptr;
        porsche::window_class_name_0069e5a8=name==1?"Porsche":nullptr;
        porsche::window_instance_006b7794=nullptr;
        porsche::class_error_file_005deb74=0;
        porsche::class_error_line_005deb78=0;
        porsche::window_handlers_registered_0069e598=handlers;
        porsche::window_input_lock_0069e564=nullptr;
        porsche::window_input_capacity_0069e560=0;
        porsche::window_input_read_0069e0d8=0;
        porsche::window_input_write_0069e568=0;
        porsche::window_running_006b7c14=0;
        porsche::window_width_006b77b4=0;
        porsche::window_height_006b77b8=0;
        porsche::window_fullscreen_006b7c01=0;
        porsche::window_thread_handle_0069e574=nullptr;
        porsche::window_hwnd_006b7bf8=prior_hwnd?reinterpret_cast<void*>(0x1230000):nullptr;
        porsche::window_saved_parameter_0069e57c=0;
        porsche::window_saved_parameter_0069e580=0;
        for(auto& value:porsche::window_worker_state_006bd9e0)value=0;
        std::uint32_t result=argc>1?porsche::window_init_0053ac20(width,height,fullscreen):
            static_cast<std::uint32_t>(porsche::window_register_prefix_0053ac20());
        std::cout<<"{\"result\":"<<result<<",\"refcount\":"<<porsche::class_refcount_0069e594
                 <<",\"lock\":"<<reinterpret_cast<std::uintptr_t>(porsche::class_lock_0069e59c)
                 <<",\"instance\":"<<reinterpret_cast<std::uintptr_t>(porsche::window_instance_006b7794)
                 <<",\"name\":\""<<(porsche::window_class_name_0069e5a8?porsche::window_class_name_0069e5a8:"")
                 <<"\",\"error_file\":"<<porsche::class_error_file_005deb74
                 <<",\"error_line\":"<<porsche::class_error_line_005deb78;
        if(argc>1){
            std::cout<<",\"handlers\":"<<porsche::window_handlers_registered_0069e598
                     <<",\"input_lock\":"<<reinterpret_cast<std::uintptr_t>(porsche::window_input_lock_0069e564)
                     <<",\"input_capacity\":"<<porsche::window_input_capacity_0069e560
                     <<",\"running\":"<<porsche::window_running_006b7c14
                     <<",\"width\":"<<porsche::window_width_006b77b4
                     <<",\"height\":"<<porsche::window_height_006b77b8
                     <<",\"fullscreen\":"<<static_cast<unsigned>(porsche::window_fullscreen_006b7c01)
                     <<",\"thread\":"<<reinterpret_cast<std::uintptr_t>(porsche::window_thread_handle_0069e574)
                     <<",\"hwnd\":"<<reinterpret_cast<std::uintptr_t>(porsche::window_hwnd_006b7bf8)
                     <<",\"saved\":["<<porsche::window_saved_parameter_0069e57c<<","<<porsche::window_saved_parameter_0069e580
                     <<"],\"worker_state\":[";
            for(std::uint32_t i=0;i<7;++i){if(i)std::cout<<',';std::cout<<porsche::window_worker_state_006bd9e0[i];}
            std::cout<<"]";
        }
        std::cout<<",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i){if(i)std::cout<<',';std::cout<<calls[i];}
        std::cout<<"]}\n";
    }
}
