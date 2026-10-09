#include "porsche/render_driver_calls.hpp"
#include <cstdint>
#include <iostream>

namespace porsche {
std::uint32_t render_thrash_exports_006bd910[43]{};
namespace { std::uint32_t about[16]{}; std::uint32_t modes[32][10]{};
std::uint32_t about_calls{},about_proc{},apply_calls{},applied[4]{}; }
const std::uint32_t* __cdecl render_loader_about_006bd934(std::uint32_t proc) {
    ++about_calls; about_proc=proc; return about;
}
void __cdecl render_driver_apply_005728b0(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t zero) {
    ++apply_calls;applied[0]=a;applied[1]=b;applied[2]=c;applied[3]=zero;
}
}

int main() {
    using namespace porsche;
    unsigned op,count;
    std::uint32_t args[6],limits[3];
    while(std::cin>>op>>args[0]>>args[1]>>args[2]>>args[3]>>args[4]>>args[5]
                  >>limits[0]>>limits[1]>>limits[2]>>count) {
        for(auto& row:modes)for(auto& x:row)x=0;
        about_calls=about_proc=apply_calls=0;
        for(auto& x:applied)x=0;
        about[0x3c/4]=count;
        about[0x40/4]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(modes));
        for(unsigned i=0;i<count;++i)for(unsigned j=0;j<10;++j)std::cin>>modes[i+1][j];
        render_thrash_exports_006bd910[(0x006bd934-0x006bd910)/4]=0x13572468;
        if(op==1) {
            auto result=render_display_video_mode_005376c0(args[0],args[1],args[2],args[3],args[4]);
            std::cout<<"R "<<result<<' '<<about_calls<<' '<<about_proc<<'\n';
        } else {
            render_driver_limit_a_006a6448=limits[0];
            render_driver_limit_b_006a6444=limits[1];
            render_driver_limit_c_006a6440=limits[2];
            render_display_video_base_00537600(args[0],args[1],args[2],args[3],args[4],args[5]);
            std::cout<<"R "<<render_driver_requested_c_0069e094<<' '
              <<render_driver_requested_a_0069e08c<<' '<<render_driver_requested_b_0069e090<<' '
              <<render_driver_requested_d_0069e070<<' '<<render_driver_requested_e_0069e074<<' '
              <<render_driver_requested_f_0069e06c<<' '<<render_driver_bounds_a_006a643c<<' '
              <<render_driver_bounds_b_006a6438<<' '<<render_driver_bounds_c_006a6430<<' '
              <<render_driver_bounds_d_006a6434<<' '<<applied[0]<<' '<<applied[1]<<' '
              <<applied[2]<<' '<<applied[3]<<' '<<apply_calls<<'\n';
        }
    }
}
