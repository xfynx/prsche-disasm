// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Six startup helpers /156B.004a66b0 parent remains explicitly deferred.
#include "audio_probe_startup_464.hpp"
#include <cstring>
#pragma comment(linker,"/alternatename:?network_lifecycle_wait_0053c380@porsche@@YAXH@Z=?application_audio_wait_0053c380@porsche@@YAXH@Z")
namespace porsche {
std::uint32_t audio_prepare_registered_006a5c34=0;
namespace {
using U=std::uint32_t;
void field(std::size_t offset,U value) {
    std::memcpy(application_audio_device_state_006b48c0.data()+offset,&value,4);
}
U field(std::size_t offset) {
    U value;std::memcpy(&value,application_audio_device_state_006b48c0.data()+offset,4);return value;
}
std::int32_t callback_count() {
    return static_cast<std::int8_t>(application_audio_device_state_006b48c0[0xe1]);
}
}
void __cdecl application_audio_prepare_00565950() {
    const auto registered=audio_prepare_registered_006a5c34;
    field(0x74,reinterpret_cast<U>(&window_worker_focus_00573980));
    field(0x78,reinterpret_cast<U>(&audio_probe_noop_00565940));
    if(registered==0) {
        (void)window_scheduler_register_005365e0(audio_probe_scheduler_callback_00565930,0,1);
        audio_prepare_registered_006a5c34=1;
    }
}
U __cdecl audio_probe_clock_0053c2e0() {
    return clock_worker_iterations_006b7c7c;
}
void __cdecl application_audio_wait_0053c380(std::int32_t interval) {
    const U target=audio_probe_clock_0053c2e0()+static_cast<U>(interval);
    U now=audio_probe_clock_0053c2e0();
    while(static_cast<std::int32_t>(now-target)<0) {
        (void)timed_callbacks_005366e0(0);
        now=audio_probe_clock_0053c2e0();
    }
}
U __cdecl audio_probe_scheduler_callback_00565930(U,U) {
    audio_probe_callbacks_0058ffd0();
    return 0;
}
__declspec(naked) void __cdecl audio_probe_noop_00565940() {
    __asm ret
}
void __cdecl audio_probe_callbacks_0058ffd0() {
    if(callback_count()<=0) return;
    std::int32_t index=0;
    do {
        reinterpret_cast<void(__cdecl*)()>(field(0x108+static_cast<U>(index)*4u))();
        ++index;
    } while(index<callback_count());
}
}
