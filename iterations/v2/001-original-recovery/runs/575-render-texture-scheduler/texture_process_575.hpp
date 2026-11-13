#pragma once
#include <cstdint>
namespace porsche {
struct TextureNotifyDescriptor575 {
    std::uint32_t slot_value;
    std::uint32_t texture_value;
    std::uint32_t payload;
    std::uint32_t texture;
};
static_assert(sizeof(TextureNotifyDescriptor575)==16);
using TextureNotifyCallback575=void (__cdecl*)(TextureNotifyDescriptor575*,TextureNotifyDescriptor575*);
extern TextureNotifyCallback575 render_texture_notify_callback_006a3a50;
void __cdecl render_texture_notify_00555040(void*,void*);
void __cdecl render_texture_process_005554b0(void*);
}
