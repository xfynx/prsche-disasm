// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044de50..0044de5f (16B), sha256 e2517159161164853ac19577fd6386ab24edc851d4f64f3f7f9c206687950074.
// Original 0044de60..0044df02 (163B), sha256 9eab89ed1d6e0b33a94aefa5c1297cbf80060d059f6594b40305e21c66702790.
// Original 0044df70..0044df7f (16B), sha256 feef284f2ef3819e0552a9409754b5d9cd0bee82dab7cfaa66947991db3ab23a.
// Original 0044df80..0044df8f (16B), sha256 361fdb277107a1942d7699806a0b8ebb974fb7be07e3b3dec42c9a0105d7f4a1.
// Original 0044df90..0044df9f (16B), sha256 2850b72d41a2a5eb694ac4cbf1cee08f5871198a3ff510507431c0d2348b9935.
// Original 0044dfa0..0044dfa0 (1B), sha256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e.
// Original 0044dfe0..0044e004 (37B), sha256 b5c2700c0fbb0c804b9ed5826fdaa7ea7374f25810ade35ca65f9d512ac43575.
// Owned .data 005ce658..005ce699 (66B), sha256 db2d2826464c69d117454bb948b3d4d83d8ee5e78245deccb08e3afdb98198bb.
// Owned .data 005ce69c..005ce6d7 (60B), sha256 8902bbe0b888323cfad06dd5d9a8ba39ebb6d09513fc74f969d14bcbd70b8d59.
// Owned .data 005ce6d8..005ce719 (66B), sha256 1c155024cf9bcda39b954b5097444d0788e53ac4449333cbbfab56679ad37d6b.
// Owned .data 005ce71c..005ce763 (72B), sha256 d489fafb492214fc9028381f975ac7a54d4fb9d7ea745095e1b9072ea616189e.
#include "startup_text_fallbacks_650.hpp"

namespace porsche {

StartupTextFallbackEntry650 startup_text_fallback_table_0_005ce658[11] = {
    {128, 2, 0u, 4, 0},
    {16, 3, 0u, 4, 0},
    {16, 7, 0u, 3, 0},
    {32, 3, 0u, 18, 0},
    {32, 7, 0u, 27, 0},
    {64, 3, 0u, 52, 0},
    {64, 7, 0u, 24, 0},
    {128, 3, 0u, 24, 0},
    {128, 7, 0u, 11, 0},
    {256, 3, 0u, 0, 0},
    {256, 7, 0u, 0, 0},
};

StartupTextFallbackEntry650 startup_text_fallback_table_1_005ce69c[10] = {
    {128, 2, 0u, 4, 0},
    {16, 3, 0u, 2, 0},
    {16, 7, 0u, 3, 0},
    {32, 3, 0u, 4, 0},
    {32, 7, 0u, 17, 0},
    {64, 3, 0u, 18, 0},
    {64, 7, 0u, 10, 0},
    {128, 3, 0u, 76, 0},
    {128, 7, 0u, 28, 0},
    {256, 7, 0u, 2, 0},
};

StartupTextFallbackEntry650 startup_text_fallback_table_2_005ce6d8[11] = {
    {128, 2, 0u, 4, 0},
    {16, 3, 1u, 2, 0},
    {16, 7, 1u, 3, 0},
    {32, 3, 1u, 4, 0},
    {32, 7, 1u, 17, 0},
    {64, 3, 1u, 18, 0},
    {64, 7, 1u, 10, 0},
    {128, 3, 1u, 72, 0},
    {128, 7, 1u, 24, 0},
    {256, 3, 1u, 24, 0},
    {256, 7, 1u, 4, 0},
};

StartupTextFallbackEntry650 startup_text_fallback_table_4_005ce71c[12] = {
    {128, 2, 0u, 4, 0},
    {16, 3, 0u, 1, 0},
    {16, 7, 0u, 1, 0},
    {32, 3, 0u, 1, 0},
    {32, 7, 0u, 1, 0},
    {64, 3, 0u, 1, 0},
    {64, 7, 0u, 1, 0},
    {128, 7, 0u, 1, 0},
    {256, 3, 0u, 16, 32},
    {256, 2, 0u, 16, 32},
    {256, 4, 0u, 16, 32},
    {256, 7, 0u, 16, 32},
};

void __cdecl startup_text_fallback_4_0044de50() {
    startup_text_fallback_apply_0044de60(startup_text_fallback_table_4_005ce71c, 12);
}

void __cdecl startup_text_fallback_apply_0044de60(
    const StartupTextFallbackEntry650* entries,
    std::int32_t count) {
    if (count <= 0) {
        return;
    }

    for (std::int32_t i = 0; i < count; ++i) {
        const StartupTextFallbackEntry650& entry = entries[i];
        const bool mip_active =
            (entry.mip_enabled != 0u) && (render_mode_state_00619790[0x1e] != 0u);
        const std::int32_t size = static_cast<std::int32_t>(entry.size);
        std::int32_t mip_dim = size >> 2;
        std::uint32_t mip_levels = 0u;
        if (mip_active && mip_dim > 0) {
            do {
                mip_dim >>= 1;
                ++mip_levels;
            } while (mip_dim > 0);
        }

        const std::uint32_t format_b = (entry.format == 2) ? 4u : 0u;
        const std::uint32_t format_a =
            static_cast<std::uint32_t>(static_cast<std::int32_t>(entry.format));
        const std::uint32_t dim_u = static_cast<std::uint32_t>(size);

        if (entry.slot0_count != 0) {
            render_texture_slot_bind_00555640(
                0,
                static_cast<std::uint32_t>(static_cast<std::int32_t>(entry.slot0_count)),
                dim_u,
                dim_u,
                format_a,
                format_b,
                mip_levels);
        }

        if (entry.slot1_count != 0) {
            render_texture_slot_bind_00555640(
                1,
                static_cast<std::uint32_t>(static_cast<std::int32_t>(entry.slot1_count)),
                dim_u,
                dim_u,
                format_a,
                format_b,
                mip_levels);
        }
    }
}

void __cdecl startup_text_fallback_0_0044df70() {
    startup_text_fallback_apply_0044de60(startup_text_fallback_table_0_005ce658, 11);
}

void __cdecl startup_text_fallback_1_0044df80() {
    startup_text_fallback_apply_0044de60(startup_text_fallback_table_1_005ce69c, 10);
}

void __cdecl startup_text_fallback_2_0044df90() {
    startup_text_fallback_apply_0044de60(startup_text_fallback_table_2_005ce6d8, 11);
}

void __cdecl startup_text_fallback_3_0044dfa0() {
}

std::uint32_t* __cdecl startup_text_quality_mask_ptr_0044dfe0(std::uint32_t index) {
    const std::uint32_t effective_index =
        (render_mode_state_00619790[0x70] != 0u) ? 5u : index;
    const std::uint32_t row_base = render_quality_selected_00619770 * 6u;
    return &startup_text_quality_masks_005ce59c[row_base + effective_index];
}

} // namespace porsche
