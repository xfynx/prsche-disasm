#include "porsche/render_activate.hpp"
#include <cstring>

namespace porsche {
std::uint32_t render_display_mode_index_00619780;
extern std::uint32_t render_display_actual_width_00619784;
extern std::uint32_t render_display_actual_height_00619788;
extern std::uint32_t render_display_actual_mode_0061978c;

void __cdecl render_display_reconfigure_00467fc0(RenderDisplay* display,
    std::uint32_t width,std::uint32_t height,std::uint32_t mode,
    std::uint32_t transition) {
    // 0x467fc0 compares all three requested values to the actual-mode globals.
    if(width==render_display_actual_width_00619784 &&
       height==render_display_actual_height_00619788 &&
       mode==render_display_actual_mode_0061978c) return;

    if(width==0) {
        width=render_display_actual_width_00619784;
        height=render_display_actual_height_00619788;
    }

    // Display byte +0x60 chooses the fullscreen path. The original skips
    // 0x5376c0 in that path and still forwards a zero result to 0x468030.
    const auto fullscreen=display->bytes[0x60]!=0;
    const auto result=fullscreen ? 0u :
        render_activate_video_mode_005376c0(width,height,mode,transition,1);
    render_display_video_result_00468030(display,result);
}
}
