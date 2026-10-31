// Original Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0059bce0..0059bd1d /62B. DWORD loads/stores can be unaligned. Preserve
// wrapping addressing, captured paired reads and backwards overlap order.
#include "audio_sample_converter_476.hpp"
#include <cstring>
namespace porsche {
namespace {
using U=std::uint32_t;
U read(U address){U value;std::memcpy(&value,reinterpret_cast<const void*>(address),4);return value;}
void write(U address,U value){std::memcpy(reinterpret_cast<void*>(address),&value,4);}
}
void __cdecl audio_mixer_convert_block_0059bce0(U count,U source,U destination) {
    const U second=source+count*2u;
    U remaining=count;
    for(;;) {
        const U left=read(source+remaining*2u-4u);
        const U right=read(second+remaining*2u-4u);
        write(destination+remaining*4u-8u,(left<<16)|(right&0xffffu));
        write(destination+remaining*4u-4u,(left&0xffff0000u)|(right>>16));
        // Signed SUB/JG tests the mathematical signed pre-SUB value >2,
        // including overflow; unsigned arithmetic alone must not drive this loop.
        const bool repeat=static_cast<std::int32_t>(remaining)>2;
        remaining-=2u;
        if(!repeat) break;
    }
}
}
