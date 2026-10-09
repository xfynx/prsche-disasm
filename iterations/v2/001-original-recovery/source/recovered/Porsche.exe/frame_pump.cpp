#include "porsche/frame_pump.hpp"

#include "porsche/game_setup.hpp"
#include "porsche/render_display.hpp"
#include "porsche/window_shutdown.hpp"

#include <array>
#include <cstddef>
#include <cstdint>

namespace porsche {
namespace {
alignas(4) std::array<std::uint32_t, 12> frame_pump_storage_006573b8{};
std::uint8_t* storage_bytes() noexcept {
    return reinterpret_cast<std::uint8_t*>(frame_pump_storage_006573b8.data());
}

struct MovieBaseObject {
    virtual void reserved_00() {}
    virtual void reserved_04() {}
    virtual void reserved_08() {}
    virtual void reserved_0c() {}
    virtual void reserved_10() {}
    virtual void reserved_14() {}
    virtual void reserved_18() {}
    virtual std::uint32_t slot_1c(std::uint32_t) = 0;
    virtual std::uint32_t slot_20() = 0;
};
struct MovieService { MovieBaseObject* base; void* frame_object; };
static_assert(offsetof(MovieService, frame_object) == 4);
} // namespace

std::uint32_t& frame_pump_word_006573b8 = frame_pump_storage_006573b8[0];
std::uint32_t& frame_pump_word_006573bc = frame_pump_storage_006573b8[1];
std::uint32_t& frame_pump_word_006573c0 = frame_pump_storage_006573b8[2];
std::uint32_t& frame_pump_word_006573c4 = frame_pump_storage_006573b8[3];
std::uint32_t& frame_pump_word_006573d0 = frame_pump_storage_006573b8[6];
std::uint32_t& frame_pump_word_006573d4 = frame_pump_storage_006573b8[7];
std::uint32_t& frame_pump_word_006573d8 = frame_pump_storage_006573b8[8];
std::uint8_t& frame_pump_byte_006573e0 = storage_bytes()[0x28];
std::uint8_t& frame_pump_byte_006573e1 = storage_bytes()[0x29];
std::uint8_t& frame_pump_byte_006573e2 = storage_bytes()[0x2a];
std::uint8_t& frame_pump_byte_006573e4 = storage_bytes()[0x2c];
std::uint32_t frame_pump_word_00655a08 = 0;
std::uint8_t* frame_pump_storage_bytes_006573b8() noexcept { return storage_bytes(); }

void __cdecl frame_pump_004b0d70() {
    if (frame_pump_byte_006573e1 != 0 && frame_pump_byte_006573e2 == 0) {
        window_shutdown_prepare_00534550();
        frame_pump_boundary_004ab150();
        frame_pump_word_006573d4 = frame_pump_word_00655a08;
        frame_pump_word_00655a08 = 1;
        if (frame_pump_byte_006573e4 != 0)
            frame_pump_boundary_005693e0();
        render_display_flush_006bd970();
        render_display_setstate_006bd97c(0x6c, 1);
        frame_pump_byte_006573e2 = 1;
    }

    if (frame_pump_byte_006573e0 != 0 || frame_pump_byte_006573e2 == 0)
        return;

    frame_pump_byte_006573e1 = 0;
    frame_pump_byte_006573e2 = 0;
    render_display_setstate_006bd97c(0x6c, 0);

    auto* const service = static_cast<MovieService*>(game_setup_movie_service_0069ed0c);
    auto* const base = service->base;
    const auto frame_value = base->slot_20();
    base->slot_1c(frame_value);

    for (std::uint32_t i = 0; i != 3; ++i) {
        render_display_window_006bd9b0(2);
        render_display_clear_window_006bd91c();
        game_setup_render_update_006bd948();
        render_display_sync_006bd978(0);
    }

    if (frame_pump_byte_006573e4 != 0) {
        frame_pump_boundary_00568f30(
            frame_pump_word_006573c0, frame_pump_word_006573c4,
            frame_pump_word_006573bc, frame_pump_word_006573b8,
            frame_pump_word_006573d0, frame_pump_word_006573d8);
    }

    frame_pump_boundary_005360a0(service->frame_object, 1);
    frame_pump_boundary_005363a0(service->frame_object);
    render_display_flush_006bd970();
    render_display_window_006bd9b0(2);
    frame_pump_boundary_004ab200();
    frame_pump_word_00655a08 = frame_pump_word_006573d4;
}
} // namespace porsche
