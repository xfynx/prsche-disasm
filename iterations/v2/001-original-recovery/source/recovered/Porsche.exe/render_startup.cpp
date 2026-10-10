#include "porsche/render_startup.hpp"
#include <cstring>

namespace porsche {
RenderCore* render_core_0065b39c;
RenderDisplay* render_display_00628130;

static std::uint32_t field(const RenderDisplay* display,std::size_t offset) {
    std::uint32_t result;
    std::memcpy(&result,display->bytes+offset,sizeof(result));
    return result;
}

void __cdecl render_startup_00467470() {
    void* allocated=render_allocate_0059ef90(0x118);
    render_core_0065b39c=allocated ? render_construct_core_00467700(
        allocated,"Electronic Arts","Need for Speed - Porsche Unleashed") : nullptr;
    RenderCore* core=render_core_0065b39c;

    char driver[112];
    std::strcpy(driver,render_selector_00657a38);
    // Original calls vtable[0] without a null check after the allocation.
    core->first_00();
    std::uint32_t selected;
    char resolution[80];
    if (std::strcmp(render_selector_00657a38,"registry")==0) {
        render_registry_text_004b7240(core,0,driver);
        if (driver[0]=='\0') render_missing_setup_00467535();
        if (std::strcmp(driver,"dx")==0) {
            selected=render_registry_choice_004b7340(core,1);
            std::strcat(driver,"7");
        } else selected=0;
        std::strcat(driver,"z");
        render_registry_text_004b7240(core,2,resolution);
    } else {
        selected=render_selected_00657a58;
        render_format_005a0fbf(resolution,"%dx%d",render_width_00657a48,render_height_00657a4c);
    }

    char name[112];
    std::strcpy(name,render_display_name_0065b304);
    std::strcat(name,driver);
    render_registry_activate_004b7220(core);
    if (!render_display_00628130) {
        void* display_memory=render_allocate_0059ef90(0x80);
        render_display_00628130=display_memory ? render_construct_display_004677e0(
            display_memory,name,selected,0,resolution) : nullptr;
    }
    render_display_apply_004b70d0(field(render_display_00628130,0x7c),
                                  field(render_display_00628130,0x74));
    render_misc_00465df0();
    render_misc_00449b40();
}
}
