// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Omitted original0058f880..0058f8d6,87B, both exits RET4.
#include "audio_thread_worker_460.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error The original import-cell binding requires MSVC x86
#endif
#pragma comment(linker,"/alternatename:?audio_thread_sleep_005b220c@porsche@@3P6GXI@ZA=__imp__Sleep@4")
#pragma comment(linker,"/include:__imp__Sleep@4")
namespace porsche {
AudioThreadCallbacks460 audio_thread_callbacks_006b4a3c{};
volatile std::uint32_t& audio_thread_before_006b4a3c=audio_thread_callbacks_006b4a3c.before;
volatile std::uint32_t& audio_thread_after_006b4a40=audio_thread_callbacks_006b4a3c.after;
std::uint32_t __stdcall audio_thread_worker_0058f880(void*) {
    if(audio_thread_requested_006b4881!=0) {
        const auto sleep=audio_thread_sleep_005b220c;
        do {
            const auto before=audio_thread_before_006b4a3c;
            if(before!=0)reinterpret_cast<void(__cdecl*)()>(before)();
            audio_thread_mix_0058f8e0();
            const auto after=audio_thread_after_006b4a40;
            if(after!=0)reinterpret_cast<void(__cdecl*)()>(after)();
            sleep(static_cast<std::uint32_t>(application_audio_device_state_006b48c0[0x21]));
        } while(audio_thread_requested_006b4881!=0);
    }
    audio_thread_running_006b4880=0;
    return 0;
}
}
