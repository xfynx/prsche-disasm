// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run708: recovered body 005556a0..005556a9 (10B).
//
// Original body SHA-256 (raw PE file bytes, verified by the native runner):
//   005556a0 e2213ec12450612a229790db591f3bd5af47df349e8ddcf000fe7f99922900c8
#include "scene_texture_callback_708.hpp"

namespace porsche {

// 005556a0..005556a9. Stores the callback pointer into the loader-zero cell
// at 0x006a3a50 (owned by Run575 as render_texture_notify_callback_006a3a50).
void __cdecl scene_texture_callback_005556a0(void* callback) {
    render_texture_notify_callback_006a3a50 =
        reinterpret_cast<TextureNotifyCallback575>(callback);
}

} // namespace porsche