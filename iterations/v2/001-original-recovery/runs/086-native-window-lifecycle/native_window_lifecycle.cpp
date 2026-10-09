#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "porsche/file_threads.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_input_bindings.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/render_event_route.hpp"
#include <cstdio>
#include <cstdlib>

namespace {
HANDLE finished;
DWORD WINAPI watchdog(void*) {
    if(::WaitForSingleObject(finished,15000)!=WAIT_OBJECT_0) {
        std::fprintf(stderr,"original window lifecycle timed out\n");
        std::fflush(stderr);
        ::ExitProcess(90);
    }
    return 0;
}
struct KeyboardToggles {
    int states[3];
    const BYTE keys[3]={VK_CAPITAL,VK_NUMLOCK,VK_SCROLL};
    KeyboardToggles() {
        for(int i=0;i<3;++i)states[i]=::GetKeyState(keys[i])&1;
    }
    ~KeyboardToggles() {
        for(int i=0;i<3;++i)if((::GetKeyState(keys[i])&1)!=states[i]) {
            ::keybd_event(keys[i],0,0,0);
            ::keybd_event(keys[i],0,KEYEVENTF_KEYUP,0);
        }
    }
};
}
int main() {
    KeyboardToggles restore_toggles;
    finished=::CreateEventA(nullptr,TRUE,FALSE,nullptr);
    HANDLE guard=::CreateThread(nullptr,0,watchdog,nullptr,0,nullptr);
    if(!finished || !guard)return 91;
    std::fprintf(stderr,"calling recovered window_init(640,480,0)\n");
    const auto init_result=porsche::window_init_0053ac20(640,480,0);
    HWND hwnd=static_cast<HWND>(porsche::window_hwnd_006b7bf8);
    RECT client{};
    const bool created=hwnd && ::IsWindow(hwnd) && init_result!=0;
    const bool visible=created && ::IsWindowVisible(hwnd)!=0;
    const bool sized=created && ::GetClientRect(hwnd,&client)!=0 &&
        client.right==640 && client.bottom==480;
    const bool procedure=created && ::GetWindowLongPtrA(hwnd,GWLP_WNDPROC)==
        reinterpret_cast<LONG_PTR>(&porsche::window_procedure_0053aba0);
    HANDLE worker=nullptr;
    HANDLE original_worker=reinterpret_cast<HANDLE>(
        static_cast<std::uintptr_t>(porsche::window_worker_state_006bd9e0[0]));
    const bool duplicated=::DuplicateHandle(::GetCurrentProcess(),original_worker,
        ::GetCurrentProcess(),&worker,SYNCHRONIZE,FALSE,0)!=0;
    DWORD_PTR paint_result=0;
    const bool painted=created && ::SendMessageTimeoutA(hwnd,WM_PAINT,0,0,
        SMTO_ABORTIFHUNG,2000,&paint_result)!=0;
    const auto resize_count=porsche::window_resize_count_006a5c2c;
    std::fprintf(stderr,"init=%u created=%d visible=%d sized=%d handlers=%u; original cleanup\n",
        init_result,created,visible,sized,porsche::window_handler_count_0069e570);
    porsche::window_position_cleanup_0053bcb0();
    const bool joined=duplicated && ::WaitForSingleObject(worker,3000)==WAIT_OBJECT_0;
    if(worker)::CloseHandle(worker);
    const bool destroyed=porsche::window_hwnd_006b7bf8==nullptr && !::IsWindow(hwnd);
    const bool unregistered=porsche::class_refcount_0069e594==0;
    ::SetEvent(finished);
    ::WaitForSingleObject(guard,2000);
    ::CloseHandle(guard);::CloseHandle(finished);
    const bool ok=created && visible && sized && procedure && painted &&
        resize_count>0 && joined && destroyed && unregistered &&
        porsche::window_handler_count_0069e570==27;
    std::printf("{\"created\":%s,\"visible\":%s,\"client_width\":%ld,\"client_height\":%ld,\"original_wndproc\":%s,\"registrations\":%u,\"resize_notifications\":%u,\"worker_joined\":%s,\"destroyed\":%s,\"class_released\":%s,\"game_launch_verified\":false,\"passed\":%s}\n",
        created?"true":"false",visible?"true":"false",client.right,client.bottom,
        procedure?"true":"false",porsche::window_handler_count_0069e570,
        resize_count,joined?"true":"false",destroyed?"true":"false",
        unregistered?"true":"false",ok?"true":"false");
    return ok?0:1;
}
