// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "fe_entry_leaves_692.hpp"

#include "porsche/application_main.hpp"
#include "porsche/application_state.hpp"

namespace porsche {

// Owned zero-initialized .bss cells (Porsche.exe .data virtual tail).
std::uint32_t fe_loop_word_005e99f8 = 0u;
std::uint32_t fe_loop_word_005e9a00 = 0u;
std::uint32_t fe_loop_word_005e9a04 = 0u;
std::uint32_t fe_loop_word_00606850 = 0u;
std::uint32_t fe_loop_word_00606854 = 0u;
std::uint32_t fe_loop_word_00606860 = 0u;
std::uint32_t fe_loop_word_00606864 = 0u;
std::uint32_t fe_loop_word_00606868 = 0u;
std::uint32_t fe_loop_word_0060686c = 0u;
std::uint32_t fe_loop_word_00606870 = 0u;
std::uint32_t fe_replay_scratch_005ed848[0x6400];

// Run-400 cluster-4 reset cells: declared by frame_loop_clusters_400.hpp,
// first defined here because 00414eb0 is first compiled in this batch.
std::uint32_t frame_reset_word_00606ab8 = 0u;
std::uint8_t frame_reset_byte_00656858 = 0u;
std::uint32_t frame_reset_word_00606a8c = 0u;
std::uint32_t frame_reset_word_00606a90 = 0u;
std::uint32_t frame_reset_word_00606a98 = 0u;
std::uint32_t frame_reset_word_00606a9c = 0u;
std::uint32_t frame_reset_word_00606aa0 = 0u;
std::uint32_t frame_reset_word_00606ac8 = 0u;
std::uint32_t frame_reset_word_006280e8 = 0u;
std::uint32_t frame_reset_word_006280ec = 0u;
std::uint32_t frame_reset_word_006280f0 = 0u;
std::uint32_t frame_reset_word_006280f8 = 0u;
std::uint32_t frame_reset_word_006280fc = 0u;
std::uint32_t frame_reset_word_00628100 = 0u;

void __cdecl application_main_function_00413ea0() {
    const std::int32_t mode = static_cast<std::int32_t>(global_005e99f4);
    if (mode == 0 || mode == 1) {
        // 00413f93: STOSD.REP clears 0x6400 dwords at 005ed848.
        for (std::size_t index = 0; index < 0x6400u; ++index) {
            fe_replay_scratch_005ed848[index] = 0u;
        }
        fe_loop_word_005e99f8 = 0u;
        replay_state_005e99fc = 0u;
        replay_mode_flag_00606858 =
            application_state_006573e8.word(0x0065741cu);
    } else if (mode >= 2) {
        // 00413ec3.
        replay_state_005e99fc = 0u;
        fe_loop_word_00606860 = 0u;
        fe_loop_word_00606864 = 2u;
        fe_loop_word_00606868 = 0u;
        fe_loop_word_0060686c = 0u;
        fe_loop_word_00606870 = 0u;
        if (entry_fe_call_0046d960() != 0) {
            if (application_state_006573e8.word(0x006573e8u) == 9u) {
                // 00413f46: (0, 0xa) call, then 0x14.
                entry_fe_call_004659e0(0u, 0xau);
                fe_loop_word_00606850 = 0x14u;
            } else {
                const std::int32_t count = static_cast<std::int32_t>(
                    application_audio_source_storage_005e8bfc[0]);
                if (count > 0) {
                    // 00413f0e: ESI walks cells 1..count of the storage.
                    for (std::int32_t index = 0; index < count; ++index) {
                        const std::uint32_t object =
                            application_audio_source_storage_005e8bfc[1u +
                                static_cast<std::uint32_t>(index)];
                        const std::uint32_t stored = entry_fe_call_0046d890();
                        *reinterpret_cast<std::uint32_t*>(object + 0x10e4u) =
                            stored;
                        const std::uint32_t readback =
                            *reinterpret_cast<std::uint32_t*>(object + 0x10e4u);
                        entry_fe_call_00413960(readback);
                    }
                    fe_loop_word_00606850 = 0x14u;
                } else {
                    // 00413f51.
                    fe_loop_word_00606850 = 0x14u;
                }
            }
        } else {
            // 00413f5d: store 0xa before the (0, 0xa) call.
            fe_loop_word_00606850 = 0xau;
            entry_fe_call_004659e0(0u, 0xau);
        }
        // 00413f72 tail.
        replay_mode_flag_00606858 =
            application_state_006573e8.word(0x0065741cu);
        fe_loop_word_005e9a00 = 0u;
        fe_loop_word_00606854 = 0u;
        fe_loop_word_005e9a04 = 0u;
        return;
    }
    // 00413fb9 tail (also the negative-mode fallthrough from 00413ebd).
    fe_loop_word_005e9a00 = 0u;
    fe_loop_word_005e9a04 = 0u;
}

} // namespace porsche
