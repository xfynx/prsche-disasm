// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// rand005a17c9/34B and seed005a17bc/13B. Canonical thread state owns +14.
#include "audio_random_553.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include <cstring>
namespace porsche {
std::int32_t __cdecl audio_resampler_rand_005a17c9(){
    auto* thread=static_cast<std::uint8_t*>(formatter_crt_thread_005a545c());
    std::uint32_t state;std::memcpy(&state,thread+0x14,4);
    state=state*0x343fdu+0x269ec3u;
    std::memcpy(thread+0x14,&state,4);
    return static_cast<std::int32_t>((state>>16)&0x7fffu);
}
void __cdecl audio_resampler_seed_005a17bc(std::uint32_t seed){
    auto* thread=static_cast<std::uint8_t*>(formatter_crt_thread_005a545c());
    std::memcpy(thread+0x14,&seed,4);
}
}
