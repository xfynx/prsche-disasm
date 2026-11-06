// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original0055ec50..0055ecc3,116B/RET0;no new data owner.
#include "render_diagnostic_549.hpp"
#include "../353-diagnostic-mono/diagnostic_mono.hpp"
#include "porsche/application_heap.hpp"
#include <cstdarg>
namespace porsche {
void __cdecl render_texture_diagnostic_0055ec50(std::uint32_t channel,const char* format,...){
    if(!application_diagnostic_started_006a57cc)application_secondary_start();
    if(!(application_diagnostic_channels_005df4a0[channel].flags&1))return;
    char buffer[2048];
    std::va_list arguments;va_start(arguments,format);
    static_assert(sizeof(arguments)==sizeof(void*),"Original x86 raw varargs");
    (void)application_diagnostic_mono_vsprintf_005a299e(buffer,format,reinterpret_cast<const std::uint32_t*>(arguments));
    va_end(arguments);
    for(std::uint32_t i=0;i<8;++i){
        if(!(application_diagnostic_devices_005e1c8c[i].flags&1))continue;
        const auto callback=application_diagnostic_devices_005e1c8c[i].callback;
        if(callback)reinterpret_cast<void (__cdecl*)(std::uint32_t,const char*)>(callback)(channel,buffer);
    }
}
}
