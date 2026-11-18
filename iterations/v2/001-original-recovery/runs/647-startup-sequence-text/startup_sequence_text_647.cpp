// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044df10..0044df62 (83B), sha256 f5059db380db42931ac81fd47aad19a79e21ea0e7ced174212e3ecbcdd841456.
// Original 0044e010..0044e276 (615B), sha256 6908ff62044e244d73104e8cca4803513fb1b3203729570d73c0513c8d135e5a.
// Owned .data 005ce59c..005ce5fb (96B), sha256 493ed4627abe3ebd9cdd3351d205ae4e0d36cfc856690296f57f716c0f19ed44.
// Owned .data 005ce768..005ce8f3 (396B), sha256 eeda48d0e41e12044ece7788f5c71660ae53c4e1682510366e3d35c7556ac094.
// Owned .data 005ce8f4..005ce8fc (9B), sha256 4aa5d1a1e18d61e122c6fd88a460113283655619714b8556ad07fc15fd76dffe.
#include "startup_sequence_text_647.hpp"

namespace porsche {

std::uint32_t startup_text_quality_masks_005ce59c[24] = {
    0x00200f10u, 0x00080710u, 0x00000f10u, 0x00000f10u, 0x00000010u, 0x00000010u,
    0x00260710u, 0x00080010u, 0x00120710u, 0x00120010u, 0x00120010u, 0x00000010u,
    0x00260010u, 0x00080010u, 0x00120010u, 0x00120010u, 0x00120010u, 0x00000010u,
    0x00060020u, 0x00080020u, 0x00000010u, 0x00000010u, 0x00120010u, 0x00000010u,
};

StartupTextSlotEntry647 startup_text_slots_005ce768[11] = {
    {0x00000080u, 2, 0u, {0u, 0u}, {0u, 0u, 0u, 0u, 0u, 0u, 3u}},
    {0x00000010u, 3, 1u, {0u, 0u}, {0u, 0u, 0u, 0u, 0u, 0u, 0u}},
    {0x00000010u, 7, 1u, {0u, 0u}, {0u, 0u, 0u, 0u, 2u, 0u, 0u}},
    {0x00000020u, 3, 1u, {0u, 0u}, {0u, 0u, 0u, 0u, 0u, 0u, 0u}},
    {0x00000020u, 7, 1u, {0u, 0u}, {0u, 3u, 0u, 0u, 6u, 0u, 1u}},
    {0x00000040u, 3, 1u, {0u, 0u}, {0u, 0u, 0u, 0u, 0u, 0u, 0u}},
    {0x00000040u, 7, 1u, {0u, 0u}, {0u, 0u, 14u, 2u, 6u, 0u, 2u}},
    {0x00000080u, 3, 1u, {0u, 0u}, {0u, 0u, 7u, 1u, 0u, 0u, 0u}},
    {0x00000080u, 7, 1u, {0u, 0u}, {0u, 0u, 0u, 0u, 0u, 0u, 6u}},
    {0x00000100u, 3, 1u, {0u, 0u}, {0u, 0u, 21u, 3u, 0u, 0u, 0u}},
    {0x00000100u, 7, 1u, {0u, 0u}, {0u, 1u, 0u, 0u, 0u, 0u, 0u}},
};

char startup_text_dtx_fmt_005ce8f4[9] = "%s%s.dtx";

bool __cdecl startup_text_load_0044e010(std::uint32_t text_va) {
    (void)text_va;

    const char* const base_path = install_paths_table_0065b2a0[6];
    char* const text_name = application_state_006573e8.characters(0x00657444u);
    const std::uint32_t raw_args[2] = {
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(base_path)),
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(text_name)),
    };
    char path[100];
    (void)formatter_entry_raw_005a0fbf(path, startup_text_dtx_fmt_005ce8f4, raw_args);

    const bool alt_mode = render_mode_state_00619790[0x70] != 0u;
    const std::uint32_t quality = render_quality_selected_00619770;
    const std::uint32_t row_base = quality * 6u;

    const std::uint32_t mask_bc = startup_text_quality_masks_005ce59c[row_base + (alt_mode ? 5u : 2u)];
    startup_text_slots_005ce768[9].counts[2] = ((mask_bc & 0x0200u) != 0u) ? 14u : 21u;

    const std::uint32_t mask_c0 = startup_text_quality_masks_005ce59c[row_base + (alt_mode ? 5u : 3u)];
    startup_text_slots_005ce768[9].counts[3] = ((mask_c0 & 0x0200u) != 0u) ? 2u : 3u;

    if (rooted_file_exists_0059dc30(path) == 0) {
        return false;
    }

    auto* const dtx_bytes = static_cast<const std::uint8_t*>(resource_open_0059d8e0(path, 0u));
    for (std::uint32_t i = 0u; i < 11u; ++i) {
        startup_text_slots_005ce768[i].counts[0] = static_cast<std::uint32_t>(dtx_bytes[i]);
    }

    for (std::uint32_t i = 0u; i < 11u; ++i) {
        StartupTextSlotEntry647& entry = startup_text_slots_005ce768[i];
        std::uint32_t high_total = entry.counts[6];
        std::uint32_t low_total = 0u;

        if (i > 0u) {
            const std::uint32_t size = entry.size;
            const std::uint32_t active_row = render_quality_selected_00619770 * 6u;
            const bool active_alt = render_mode_state_00619790[0x70] != 0u;
            for (std::uint32_t sub = 0u; sub < 5u; ++sub) {
                const std::uint32_t mask =
                    startup_text_quality_masks_005ce59c[active_row + (active_alt ? 5u : sub)];
                const std::uint8_t byte1 = static_cast<std::uint8_t>((mask >> 8u) & 0xffu);
                const std::uint8_t byte2 = static_cast<std::uint8_t>((mask >> 16u) & 0xffu);
                const bool use_low = (byte2 & 0x02u) != 0u && entry.mip_enabled != 0u;

                const bool skip_self =
                    (size == 0x100u && (byte1 & 0x02u) != 0u) ||
                    (size == 0x80u && (byte1 & 0x04u) != 0u) ||
                    (size == 0x40u && (byte1 & 0x08u) != 0u) ||
                    (size == 0x20u && (byte1 & 0x10u) != 0u);
                if (!skip_self) {
                    const std::uint32_t val = entry.counts[sub];
                    if (use_low) {
                        low_total += val;
                    } else {
                        high_total += val;
                    }
                }

                const bool take_next =
                    (size == 0x80u && (byte1 & 0x02u) != 0u) ||
                    (size == 0x40u && (byte1 & 0x04u) != 0u) ||
                    (size == 0x20u && (byte1 & 0x08u) != 0u) ||
                    (size == 0x10u && (byte1 & 0x10u) != 0u);
                if (take_next) {
                    const std::uint32_t val = startup_text_slots_005ce768[i + 2u].counts[sub];
                    if (use_low) {
                        low_total += val;
                    } else {
                        high_total += val;
                    }
                }
            }
        }

        const std::uint32_t size = entry.size;
        std::uint32_t flags = 0u;
        std::int32_t mip_dim = static_cast<std::int32_t>(size) >> 2;
        if (entry.mip_enabled != 0u && mip_dim > 0) {
            do {
                mip_dim >>= 1;
                ++flags;
            } while (mip_dim > 0);
        }

        const std::uint32_t format_b = (entry.format == 2) ? 4u : 0u;
        const std::uint32_t format_a = static_cast<std::uint32_t>(static_cast<std::int32_t>(entry.format));
        render_texture_slot_bind_00555640(0, low_total, size, size, format_a, format_b, flags);
        render_texture_slot_bind_00555640(
            0,
            high_total,
            entry.size,
            entry.size,
            static_cast<std::uint32_t>(static_cast<std::int32_t>(entry.format)),
            format_b,
            0u);
    }

    (void)free_00531f90(const_cast<std::uint8_t*>(dtx_bytes));
    return true;
}

void __cdecl startup_sequence_text_0044df10(std::uint32_t text_va) {
    using FallbackFn = void(__cdecl*)();
    const std::uint32_t quality = render_quality_selected_00619770;
    const FallbackFn fallbacks[5] = {
        &startup_text_fallback_0_0044df70,
        &startup_text_fallback_1_0044df80,
        &startup_text_fallback_2_0044df90,
        &startup_text_fallback_3_0044dfa0,
        nullptr,
    };
    render_texture_format_16bit_mode_00554930(1);
    if (!startup_text_load_0044e010(text_va)) {
        fallbacks[quality]();
    }
}

} // namespace porsche
