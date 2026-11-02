// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete 00468110..0046821a (267B). Dispatch table is control flow, not state.
#include "render_pixel_489.hpp"
namespace porsche {
namespace {
using U=std::uint32_t;using Q=std::uint64_t;
U scale5(U component){
    const U weighted=component*255u+16u;
    const U high=static_cast<U>((static_cast<Q>(weighted)*0x08421085u)>>32);
    return (((weighted-high)>>1)+high)>>4;
}
U scale6(U component){
    const U weighted=component*255u+31u;
    const U high=static_cast<U>((static_cast<Q>(weighted)*0x04104105u)>>32);
    return (((weighted-high)>>1)+high)>>5;
}
}
U __cdecl render_pixel_convert_00468110(U pixel,U format){
    U red,green;
    switch(format){
    case 3:case 11:
        if(pixel==0)return 0;
        red=scale5((pixel>>10)&31u);
        green=scale5((pixel>>5)&31u);
        break;
    case 4:
        if(pixel==0)return 0;
        red=scale5((pixel>>11)&31u);
        green=scale6((pixel>>5)&63u);
        break;
    case 5:case 6:return pixel|0xff000000u;
    default:return pixel;
    }
    U packed=((red|0xffffff00u)<<8)|green;
    return (packed<<8)|scale5(pixel&31u);
}
bool __cdecl render_display_compare_pixel_00468110(U pixel,U format){
    return (render_pixel_convert_00468110(pixel,format)&0xffu)!=0;
}
}
