// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run795: 00475c80..00475d61 (226B), 00475a60..00475c7b (540B).
#include "scene_route_spec_795.hpp"

#include "porsche/application_state.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/install_paths.hpp"
#include "startup_sequence_resource_table_649.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;
using W = std::uint16_t;
using SW = std::int16_t;

W load16u(const void* base, U offset) {
    W value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

SW load16s(const void* base, U offset) {
    SW value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

I load32s(const void* base, U offset) {
    I value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store16(void* base, U offset, W value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_rgb3(void* base, U offset, B r, B g, B b) {
    B* const dst = static_cast<B*>(base) + offset;
    dst[0] = r;
    dst[1] = g;
    dst[2] = b;
}

} // namespace

std::int32_t scene_route_spec_index_00628a18 = 0;
std::uint8_t scene_route_track_spec_00628a20[0x108u] = {};
std::int32_t scene_route_spec_last_index_00628b28 = 0;
std::int32_t scene_route_spec_count_00628b2c = 0;

void __cdecl scene_route_track_spec_default_00475a60(void* spec_out) {
    B* const out = static_cast<B*>(spec_out);
    store16(out, 0x00u, 0u);
    store16(out, 0x02u, static_cast<W>(application_state_006573e8.word(0x00657a24u)));
    store16(out, 0x04u, 1u);
    store16(out, 0x06u, 1u);
    store16(out, 0x08u, static_cast<W>(application_state_006573e8.word(0x00657a30u)));
    store16(out, 0x0au, 1u);

    store32(out, 0x10u, 0x10000u);
    store_rgb3(out, 0x14u, 0x80u, 0x80u, 0x80u);
    store32(out, 0x18u, 200u);
    store32(out, 0x1cu, 8u);
    store32(out, 0x20u, 0u);
    store32(out, 0x24u, 2u);
    store32(out, 0x28u, 1u);
    store32(out, 0x2cu, 0u);
    store32(out, 0x30u, 0xffffef80u);
    store32(out, 0x34u, 0x4b00u);
    store_rgb3(out, 0x38u, 0x80u, 0x80u, 0x80u);
    store_rgb3(out, 0x3cu, 0x80u, 0x80u, 0x80u);
    store_rgb3(out, 0x40u, 0x80u, 0x80u, 0x80u);
    store_rgb3(out, 0x44u, 0x80u, 0x80u, 0x80u);

    I rev = 0x17;
    for (U idx = 0u; rev > 7; ++idx, --rev) {
        out[0x48u + idx] = static_cast<B>((rev > 15) ? static_cast<I>(idx) : rev);
    }

    store32(out, 0x58u, 0u);
    store32(out, 0x5cu, 4u);

    for (I slot = 0; slot < 5; ++slot) {
        const U base = static_cast<U>(slot) * 4u;
        store_rgb3(out, 0x60u + base, 0x46u, 0x32u, 0x32u);
        store_rgb3(out, 0x74u + base, 0x46u, 0x32u, 0x32u);
        store32(out, 0xc4u + base, 0u);
        store32(out, 0xd8u + base, static_cast<U>(slot * 0x1000));
    }

    store_rgb3(out, 0x88u, 0x08u, 0x10u, 0x08u);
    store32(out, 0x8cu, 0xffffe7b8u);
    store32(out, 0x90u, 0xeeu);
    store32(out, 0x94u, 0u);
    store32(out, 0x98u, 0xeeu);
    store32(out, 0x9cu, 60u);
    store32(out, 0xa0u, 4000u);
    store32(out, 0xa4u, 10000u);
    store32(out, 0xa8u, 64u);
    store32(out, 0xacu, 200u);
    store_rgb3(out, 0xb0u, 0xffu, 0xffu, 0xffu);
    store32(out, 0xb4u, 12345u);
    store_rgb3(out, 0xb8u, 0x10u, 0x21u, 0x21u);
    store_rgb3(out, 0xbcu, 0x00u, 0x0au, 0x19u);
    store32(out, 0xc0u, 0u);
    store_rgb3(out, 0xecu, 0x10u, 0x10u, 0x08u);
    store_rgb3(out, 0xf0u, 0x80u, 0x80u, 0x80u);
    store32(out, 0xf4u, 0x44u);
    store32(out, 0xf8u, 0x4cccu);
    store_rgb3(out, 0xfcu, 0x80u, 0x80u, 0x80u);
    store16(out, 0x100u, 0u);
    store16(out, 0x102u, 0u);
    store16(out, 0x104u, 0u);
    store16(out, 0x106u, 0u);

    if (out == scene_route_track_spec_00628a20) {
        startup_night_shape_enabled_00628a28 = load16u(out, 0x08u);
    }
}

void __cdecl scene_route_dispatch_00475c80(std::uint32_t value) {
    char path[64];
    (void)formatter_entry_005a0fbf(
        path, "%sTr%02d.bin", install_paths_table_0065b2a0[6u], 0u);
    void* const file_data = resource_open_quiet_0059d9b0(path, 0u);
    (void)formatter_stdio_printf_005a177b(
        "-----------------------------------------------\n");
    if (file_data == nullptr) {
        return;
    }

    const I spec_index = static_cast<I>(value);
    scene_route_spec_index_00628a18 = spec_index;
    scene_route_spec_last_index_00628b28 = spec_index;

    const I spec_count = load32s(file_data, 0x04u);
    if (spec_index >= spec_count) {
        (void)formatter_stdio_printf_005a177b(
            "REQUEST FOR SPEC FILE %d WHEN ONLY %d EXIST\n",
            spec_index, spec_count);
        scene_route_track_spec_default_00475a60(scene_route_track_spec_00628a20);
        (void)free_00531f90(file_data);
        return;
    }

    (void)formatter_stdio_printf_005a177b(
        "FOUND TRACK SPEC FILE WITH %d SPECS!\n", spec_count);
    scene_route_spec_count_00628b2c = spec_count + 1;

    const B* const entry = static_cast<const B*>(file_data) + 8 +
                           static_cast<std::ptrdiff_t>(spec_index) * 0x108;
    std::memcpy(scene_route_track_spec_00628a20, entry, 0x108u);
    startup_night_shape_enabled_00628a28 =
        load16u(scene_route_track_spec_00628a20, 0x08u);

    application_state_006573e8.word(0x00657a30u) = static_cast<U>(
        static_cast<I>(load16s(scene_route_track_spec_00628a20, 0x08u)));
    application_state_006573e8.word(0x00657a24u) = static_cast<U>(
        static_cast<I>(load16s(scene_route_track_spec_00628a20, 0x02u)));
    (void)free_00531f90(file_data);
}

} // namespace porsche
