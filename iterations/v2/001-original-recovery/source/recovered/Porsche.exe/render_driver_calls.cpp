#include "porsche/render_driver_calls.hpp"
#include <cstddef>

namespace porsche {
std::uint32_t render_driver_requested_a_0069e08c;
std::uint32_t render_driver_requested_b_0069e090;
std::uint32_t render_driver_requested_c_0069e094;
std::uint32_t render_driver_requested_d_0069e070;
std::uint32_t render_driver_requested_e_0069e074;
std::uint32_t render_driver_requested_f_0069e06c;
std::uint32_t render_driver_bounds_a_006a643c;
std::uint32_t render_driver_bounds_b_006a6438;
std::uint32_t render_driver_bounds_c_006a6430;
std::uint32_t render_driver_bounds_d_006a6434;
std::uint32_t render_driver_limit_a_006a6448;
std::uint32_t render_driver_limit_b_006a6444;
std::uint32_t render_driver_limit_c_006a6440;

namespace {
constexpr std::size_t thrash_about_slot=(0x006bd934-0x006bd910)/4;
}

std::uint32_t __cdecl render_driver_compare_mode_00572990(
    const std::uint32_t record[10],std::uint32_t width,std::uint32_t height,
    std::uint32_t mode,std::uint32_t two,std::uint32_t one) {
    std::uint32_t score=10000;
    const std::uint32_t record_limit=one ? record[6] : record[5];
    if(record[0]==width && record[1]==height && record[4]!=0 &&
       static_cast<std::int32_t>(two)<=static_cast<std::int32_t>(record_limit)) {
        score=record[2]-mode;
        if(static_cast<std::int32_t>(score)<0) score=0u-score;
        if(static_cast<std::int32_t>(record[2])<9) {
            if(static_cast<std::int32_t>(mode)>8) score=10000;
            return score;
        }
        if(static_cast<std::int32_t>(mode)<9) score<<=2;
    }
    return score;
}

std::uint32_t __cdecl render_driver_select_mode_00572a00(
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t two,std::uint32_t one) {
    const std::uint32_t proc=render_thrash_exports_006bd910[thrash_about_slot];
    const std::uint32_t* about=render_loader_about_006bd934(proc);
    const std::int32_t count=static_cast<std::int32_t>(about[0x3c/4]);
    if(count<1) return 0;
    const auto* records=reinterpret_cast<const std::uint32_t*>(
        reinterpret_cast<const std::uint8_t*>(about)+0x40);
    std::uint32_t best_index=0;
    std::uint32_t best_score=10000;
    for(std::int32_t index=1;index<=count;++index) {
        const std::uint32_t* record=records+static_cast<std::size_t>(index)*10;
        const auto score=render_driver_compare_mode_00572990(
            record,width,height,mode,two,one);
        if(static_cast<std::int32_t>(score)<static_cast<std::int32_t>(best_score)) {
            best_index=static_cast<std::uint32_t>(index);
            best_score=score;
            if(score==0) return best_index;
        }
    }
    return best_index;
}

void __cdecl render_driver_apply_settings_005726f0(
    std::uint32_t a,std::uint32_t b,std::uint32_t d,std::uint32_t e) {
    render_driver_bounds_a_006a643c=a;
    render_driver_bounds_b_006a6438=b;
    render_driver_bounds_c_006a6430=d;
    render_driver_bounds_d_006a6434=e;
    render_driver_apply_005728b0(render_driver_limit_a_006a6448,
        render_driver_limit_b_006a6444,render_driver_limit_c_006a6440,0);
}

void __cdecl render_display_video_base_00537600(
    std::uint32_t a,std::uint32_t b,std::uint32_t c,
    std::uint32_t width,std::uint32_t height,std::uint32_t f) {
    render_driver_requested_c_0069e094=c;
    render_driver_requested_a_0069e08c=a;
    render_driver_requested_b_0069e090=b;
    render_driver_requested_d_0069e070=width;
    render_driver_requested_e_0069e074=height;
    render_driver_requested_f_0069e06c=f;
    render_driver_apply_settings_005726f0(a,b,width,height);
}

std::uint32_t __cdecl render_display_video_mode_005376c0(
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t two,std::uint32_t one) {
    return render_driver_select_mode_00572a00(width,height,mode,two,one);
}
}
