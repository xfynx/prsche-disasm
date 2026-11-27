#include "selected_player_scene_reset_869.hpp"
#include "porsche/application_state.hpp"
namespace porsche {
extern std::uint16_t startup_night_shape_enabled_00628a28;
extern std::uint32_t startup_head_state_a_0061bcc8;
extern std::uint32_t application_player_object_table_005e8b34[9];
void __cdecl session_world_list_reset_00479dd0();
void __cdecl session_scene_records_reset_00459260();
void __cdecl scene_route_bind_0045dbd0(void*, std::uint32_t);
std::uint32_t selected_player_night_words_0061bd4c[4] = {};
void __cdecl selected_player_night_state_00452680(std::uint32_t player) {
    if (startup_night_shape_enabled_00628a28 != 0) {
        selected_player_night_words_0061bd4c[0] = 0xff808080;
        startup_head_state_a_0061bcc8 = player;
        selected_player_night_words_0061bd4c[1] = 0;
        selected_player_night_words_0061bd4c[2] = 0x3fa3d70a;
        selected_player_night_words_0061bd4c[3] = 0x4067ae14;
    }
}
void __cdecl scene_route_enable_0045dd00(void* root) {
    scene_route_bind_0045dbd0(root, 1);
}
void __cdecl frame_reset_service_004690a0() {
    session_world_list_reset_00479dd0();
    scene_route_enable_0045dd00(&application_state_006573e8.word(0x657444));
    session_scene_records_reset_00459260();
    selected_player_night_state_00452680(application_player_object_table_005e8b34[
        application_state_006573e8.word(0x65741c)]);
}
}
