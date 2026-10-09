// Native platform smoke fixture, NOT a replacement app_main or game executable.
// Executes recovered class-registration prefix, complete CreateWindow consumer,
// comparator/search and WndProc with real Win32 APIs. Other game code is unlinked.
#include <windows.h>
#include "porsche/window_create.hpp"
#include "porsche/window_procedure.hpp"
#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace porsche {
static std::uint8_t configuration[0x474];
void* window_configuration_address_006b77a0=configuration;
static CRITICAL_SECTION registration_lock;
static std::uint32_t default_messages;
void* __cdecl window_lock_create_005321f0() {
    InitializeCriticalSection(&registration_lock);return &registration_lock;
}
void* __stdcall window_module_handle(const char* name) {return GetModuleHandleA(name);}
void* __stdcall window_load_icon(void* instance,const char* name) {return LoadIconA(static_cast<HINSTANCE>(instance),name);}
void* __stdcall window_load_cursor(void* instance,const char* name) {return LoadCursorA(static_cast<HINSTANCE>(instance),name);}
void* __stdcall window_stock_object(std::int32_t index) {return GetStockObject(index);}
std::uint16_t __stdcall window_register_class(const OriginalWndClassA* cls) {
    static_assert(sizeof(WNDCLASSA)==sizeof(OriginalWndClassA));
    WNDCLASSA native;std::memcpy(&native,cls,sizeof(native));return RegisterClassA(&native);
}
std::uint32_t __stdcall window_last_error() {return GetLastError();}
void __cdecl window_register_diagnostic(const char* text,std::uint32_t error) {
    std::fprintf(stderr,text,error);std::fputc('\n',stderr);
}
std::int32_t __stdcall window_get_system_metrics(std::int32_t index) {return GetSystemMetrics(index);}
std::uint32_t __stdcall window_adjust_rect(WindowRect* rect,std::uint32_t style,std::int32_t menu,std::uint32_t exstyle) {
    static_assert(sizeof(WindowRect)==sizeof(RECT));
    RECT native;std::memcpy(&native,rect,sizeof(native));
    const auto result=AdjustWindowRectEx(&native,style,menu,exstyle);
    std::memcpy(rect,&native,sizeof(native));return result;
}
void* __stdcall window_create_ex(std::uint32_t exstyle,const char* cls,const char* title,std::uint32_t style,
    std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height,void* parent,void* menu,void* instance,void* parameter) {
    return CreateWindowExA(exstyle,cls,title,style,x,y,width,height,static_cast<HWND>(parent),
        static_cast<HMENU>(menu),static_cast<HINSTANCE>(instance),parameter);
}
void* __stdcall window_set_cursor(void* cursor) {return SetCursor(static_cast<HCURSOR>(cursor));}
std::int32_t __stdcall window_show_cursor(std::int32_t show) {return ShowCursor(show);}
void __cdecl window_channel_005739b0(std::uint32_t,std::uint32_t) {
    // Fixture precondition: channels already initialized. Never replace this
    // unrecovered game's consumer with a silent successful stub.
    std::abort();
}
std::int32_t __stdcall window_default_procedure(void* hwnd,std::uint32_t message,std::uint32_t wp,std::int32_t lp) {
    ++default_messages;return DefWindowProcA(static_cast<HWND>(hwnd),message,wp,lp);
}
}

int main() {
    using namespace porsche;
    // Explicit fixture inputs, not a claim about the full game's live state.
    // 640x480 originates in 575820's zero-resolution branch; name "Porsche"
    // originates in 4a5c30 -> 5655f0. Positioned/channels-ready are test inputs.
    window_class_name_0069e5a8="Porsche";
    window_channels_initialized_0069e5a0=1;
    auto write=[](std::size_t offset,std::uint32_t value){std::memcpy(configuration+offset,&value,4);};
    write(0x14,640);write(0x18,480);write(0x458,1);write(0x468,80);write(0x46c,80);
    if(!window_register_prefix_0053ac20())return 2;
    auto hwnd=static_cast<HWND>(window_create_0053bb00(configuration));
    if(!hwnd) {std::fprintf(stderr,"CreateWindowExA failed: %lu\n",GetLastError());return 3;}
    RECT client{};GetClientRect(hwnd,&client);
    WNDCLASSA registered{};
    const bool procedure_ok=GetClassInfoA(static_cast<HINSTANCE>(window_instance_006b7794),"Porsche",&registered)
        && registered.lpfnWndProc==reinterpret_cast<WNDPROC>(&window_procedure_0053aba0);
    const bool visible=IsWindowVisible(hwnd)!=0;
    const auto start=GetTickCount();
    while(IsWindow(hwnd) && GetTickCount()-start<300) {
        MSG message;
        while(PeekMessageA(&message,nullptr,0,0,PM_REMOVE)) {TranslateMessage(&message);DispatchMessageA(&message);}
        Sleep(1);
    }
    DestroyWindow(hwnd);
    const bool destroyed=IsWindow(hwnd)==0;
    UnregisterClassA("Porsche",static_cast<HINSTANCE>(window_instance_006b7794));
    DeleteCriticalSection(&registration_lock);
    const bool success=procedure_ok && visible && client.right==640 && client.bottom==480 && default_messages && destroyed;
    std::printf("{\"native_window_created\":true,\"registered_original_wndproc\":%s,\"visible\":%s,\"client_width\":%ld,\"client_height\":%ld,\"default_messages\":%u,\"destroyed\":%s,\"game_launch_verified\":false,\"fixture_passed\":%s}\n",
        procedure_ok?"true":"false",visible?"true":"false",client.right,client.bottom,default_messages,destroyed?"true":"false",success?"true":"false");
    return success?0:4;
}
