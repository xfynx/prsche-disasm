// Complete Porsche.exe 0044e870..0044e883 (20B); two cdecl DWORD arguments.
#include "render_resource_494.hpp"
#include "porsche/render_mode.hpp"
namespace porsche {
void __cdecl render_display_present_0044e870(std::uint32_t result,std::uint32_t read_ok){
    render_mode_state_00619790[0x1b]=static_cast<std::uint8_t>(result);
    render_mode_state_00619790[0x1c]=static_cast<std::uint8_t>(read_ok);
}
}
