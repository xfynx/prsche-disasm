#include "porsche/game_setup.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
struct ResourceView {
    std::uint32_t begin;
    std::uint32_t current;
    std::uint32_t end;
};
static_assert(sizeof(ResourceView) == 12);

const void* relative_item(void* resource, std::uint32_t table_offset,
                          std::uint32_t ordinal) {
    auto* bytes = static_cast<std::uint8_t*>(resource);
    std::uint32_t relative;
    const auto byte_offset = table_offset + ordinal * 8;
    // The original loads the DWORD and adds the resource base with 32-bit wrap.
    std::memcpy(&relative, bytes + byte_offset, sizeof(relative));
    const auto address = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(resource)) + relative;
    return reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address));
}

void draw_table(void* resource, std::uint32_t table_offset,
                std::uint32_t step, std::uint32_t arg3,
                std::uint32_t arg4, std::uint32_t arg5) {
    std::uint32_t ordinal = 0;
    for (std::uint32_t index = 0; index < 0x280; index += step, ++ordinal) {
        game_setup_draw_resource_00563440(
            relative_item(resource, table_offset, ordinal), index, arg3,
            arg4, arg5);
    }
}
} // namespace

// Direct control flow and stack-visible parameters follow 004dd600..004dd9f3.
// Unrecovered media/resource/draw services remain typed external boundaries.
void __cdecl game_setup_004dd600() {
    char path[0x104]{};
    ResourceView movie{};

    render_display_reconfigure_00467fc0(render_display_00628130,
                                         640, 480, 0x10, 2);
    game_setup_update_00560030();

    game_setup_string_005a0fbf(path, "%searts-av.mad",
                               game_setup_earts_base_0065b32c, path);
    auto* movie_service_cell = static_cast<std::uint8_t*>(
        game_setup_movie_service_0069ed0c);
    void* movie_service = *reinterpret_cast<void**>(movie_service_cell + 4);
    game_setup_movie_service_begin_00536080(movie_service);
    if (game_setup_file_exists_0059dc30(path)) {
        game_setup_object_init_00403520(&movie, 8);
        *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(movie.current)) = 0;
        game_setup_resource_open_0059e440(path, &movie);
        for (std::uint32_t n = 0; n < 3; ++n) {
            game_setup_render_begin_006bd9b0(2);
            game_setup_render_reset_006bd91c();
            game_setup_render_prepare_006bd970();
            game_setup_render_update_006bd948();
            game_setup_render_finish_006bd978(0);
        }
        std::uint32_t stop = 0;
        game_setup_movie_004dc850(
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(movie.begin)),
            &stop, 0, 3, 0);
        const auto bytes = movie.end - movie.begin;
        if (movie.begin != 0 && bytes != 0)
            game_setup_movie_delta_004237d0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(movie.begin)),
                bytes, 0);
    }
    game_setup_movie_service_end_00536050(movie_service);
    game_setup_movie_004dd4a0();
    render_display_reconfigure_00467fc0(render_display_00628130,
                                         640, 480, 0x10, 2);

    game_setup_string_005a0fbf(path, "%sloadscrn.fsh",
                               game_setup_load_base_0065b334, path);
    if (game_setup_file_exists_0059dc30(path)) {
        void* resource = game_setup_resource_file_open_0059d8e0(path, 0);
        for (std::uint32_t layer = 0; layer < 6; ++layer) {
            game_setup_draw_begin_00534540();
            draw_table(resource, 0x14, 0x20, 0, 32, 32);
            draw_table(resource, 0xb4, 0x40, 32, 64, 64);
            draw_table(resource, 0x104, 0x80, 96, 128, 128);
            draw_table(resource, 0x12c, 0x80, 224, 128, 128);
            draw_table(resource, 0x154, 0x80, 352, 128, 128);
            window_shutdown_prepare_00534550();
            game_setup_render_update_006bd948();
        }
        free_00531f90(resource);
    }
    game_setup_update_00560030();
}

} // namespace porsche
