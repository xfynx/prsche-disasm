#include "porsche/render_window.hpp"
#include <cstring>

namespace porsche {
static std::uint32_t word_at(const RenderDisplay* display,std::size_t offset) {
    std::uint32_t value;
    std::memcpy(&value,display->bytes+offset,sizeof(value));
    return value;
}

void __cdecl render_display_video_result_00468030(RenderDisplay* display,
    std::uint32_t result) {
    // 0x468030 stores the incoming mode result before comparing it to the
    // previously applied table index at 0x619780.
    std::memcpy(display->bytes+0x68,&result,sizeof(result));
    if(result==render_display_mode_index_00619780) return;

    std::uint32_t width,height;
    if(display->bytes[0x60]) {
        // Fullscreen asks the already-recovered positioning consumer to use
        // its current client extent (the original passes four zero words).
        window_position_resize_0053bd40(0,0,0,0);
        width=0x280;height=0x1e0;
    } else {
        std::uint32_t mode_record[10]{};
        render_window_query_mode_info_0044e720(result,mode_record);
        width=mode_record[0];
        height=mode_record[1];
        auto* driver=reinterpret_cast<void*>(static_cast<std::uintptr_t>(word_at(display,0x70)));
        render_window_driver_select_mode_vslot7(driver,result);
    }

    render_window_commit_mode_0044ebf0(result);
    render_window_time_update_0044ed10();
    render_window_video_base_00537600(0,0,0,width,height,0);
    // The original repeats ShowCursor(FALSE) until USER32 reports a negative
    // display count. The boundary retains that return-value contract.
    while(render_window_show_cursor(0)>=0) {}
}
}
