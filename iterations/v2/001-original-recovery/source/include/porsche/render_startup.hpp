#pragma once
#include <cstddef>
#include <cstdint>

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 0x4674d1..d6 dispatches vtable slot zero with ECX=this.
struct RenderCore {
    virtual void __thiscall first_00() = 0;
};
struct RenderDisplay { std::uint8_t bytes[0x80]; };
static_assert(sizeof(RenderCore)==4 && sizeof(RenderDisplay)==0x80);

extern RenderCore* render_core_0065b39c;
extern RenderDisplay* render_display_00628130;
extern char* render_selector_00657a38;
extern std::uint32_t& render_width_00657a48;
extern std::uint32_t& render_height_00657a4c;
extern std::uint32_t& render_selected_00657a58;
extern const char* render_display_name_0065b304;

// Typed unresolved boundaries. Constructors are thiscall in original asm;
// the explicit object parameter exposes ECX for the recovered unit fixture.
void* __cdecl render_allocate_0059ef90(std::uint32_t size);
RenderCore* __cdecl render_construct_core_00467700(void* object,const char* publisher,const char* title);
RenderDisplay* __cdecl render_construct_display_004677e0(void* object,const char* name,
                                                           std::uint32_t selected,std::uint32_t zero,
                                                           const char* resolution);
void __cdecl render_registry_text_004b7240(RenderCore* core,std::uint32_t index,char* out);
std::uint32_t __cdecl render_registry_choice_004b7340(RenderCore* core,std::uint32_t index);
void __cdecl render_registry_activate_004b7220(RenderCore* core);
void __cdecl render_format_005a0fbf(char* out,const char* format,std::uint32_t width,std::uint32_t height);
void __cdecl render_display_apply_004b70d0(std::uint32_t field7c,std::uint32_t field74);
void __cdecl render_misc_00465df0();
void __cdecl render_misc_00449b40();
[[noreturn]] void __cdecl render_missing_setup_00467535();

void __cdecl render_startup_00467470();
}
