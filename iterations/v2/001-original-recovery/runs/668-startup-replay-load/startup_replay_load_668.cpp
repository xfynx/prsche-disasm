// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004146f0..0041480b (284B) and 00413cf0..00413e93 (420B).
#include "startup_replay_load_668.hpp"

#include <algorithm>
#include <array>

namespace porsche {

std::uint32_t replay_state_005e99fc = 0u;
std::uint32_t replay_snapshot_005e9a20[application_state_word_count]{};
std::uint32_t replay_tail_word_005ed844 = 0u;
std::uint32_t replay_saved_word_00606a80 = 0u;
std::uint32_t replay_mode_flag_00606858 = 0u;
char replay_filename_00699f34[128]{};

const char replay_msg_file_loaded_005cc698[16] = "%s File Loaded\n";
const char replay_msg_default_loaded_005cc6a8[24] = "replay.rpl File Loaded\n";
const char replay_msg_no_replay_005cc6c0[26] = "No Replay file found!!!!\n";
const char replay_msg_loading_default_005cc6dc[31] = "loading default replay.rpl!!!\n";

void __cdecl replay_load_004146f0() {
    void* handle = nullptr;
    char path[80]{};
    (void)formatter_entry_005a0fbf(
        path, "%s%s", engine_service_root_0065b360, replay_filename_00699f34);
    (void)open_0059e040(path, 1u, 0x64u, &handle);
    if (handle != nullptr) {
        const std::int32_t size = size_00533de0(handle, 0x64u);
        (void)read_00533bf0(
            handle, 0u, replay_snapshot_005e9a20, static_cast<std::uint32_t>(size), 0x64u);
        (void)close_00533da0(handle, 0x64u);
        (void)formatter_stdio_printf_005a177b(replay_msg_file_loaded_005cc698, path);
        return;
    }

    (void)formatter_stdio_printf_005a177b(replay_msg_loading_default_005cc6dc);
    (void)formatter_entry_005a0fbf(
        path, "%s%s", engine_service_root_0065b360, "replay.rpl");
    (void)open_0059e040(path, 1u, 0x64u, &handle);
    if (handle == nullptr) {
        (void)formatter_stdio_printf_005a177b(replay_msg_no_replay_005cc6c0);
        global_005e99f4 = 0u;
        return;
    }

    const std::int32_t size = size_00533de0(handle, 0x64u);
    (void)read_00533bf0(
        handle, 0u, replay_snapshot_005e9a20, static_cast<std::uint32_t>(size), 0x64u);
    (void)close_00533da0(handle, 0x64u);
    (void)formatter_stdio_printf_005a177b(replay_msg_default_loaded_005cc6a8);
}

void __cdecl startup_sequence_call_00413cf0() {
    const std::uint32_t mode = application_state_006573e8.word(0x00657424u);
    const std::uint32_t state_flag = application_state_006573e8.word(0x0065741cu);
    global_005e99f4 = mode;
    replay_mode_flag_00606858 = state_flag;

    if (mode != 2u) {
        std::copy_n(
            application_state_006573e8.words().data(),
            application_state_word_count,
            replay_snapshot_005e9a20);
        return;
    }

    std::array<std::uint32_t, 0x36u> saved_block_00657c84{};
    const std::size_t block_index =
        (0x00657c84u - application_state_base_va) / sizeof(std::uint32_t);
    std::copy_n(
        application_state_006573e8.words().data() + block_index,
        0x36u,
        saved_block_00657c84.data());

    const std::uint32_t saved_00657a48 = application_state_006573e8.word(0x00657a48u);
    const std::uint32_t saved_00657a4c = application_state_006573e8.word(0x00657a4cu);
    const std::uint32_t saved_00657a50 = application_state_006573e8.word(0x00657a50u);
    const std::uint32_t saved_00657d5c = application_state_006573e8.word(0x00657d5cu);
    const std::uint32_t saved_00657d60 = application_state_006573e8.word(0x00657d60u);
    const std::uint32_t saved_00657d68 = application_state_006573e8.word(0x00657d68u);
    const std::uint32_t saved_00657d6c = application_state_006573e8.word(0x00657d6cu);
    const std::uint32_t saved_00657d70 = application_state_006573e8.word(0x00657d70u);
    const std::uint32_t saved_00657d78 = application_state_006573e8.word(0x00657d78u);
    const std::uint32_t saved_00657d7c = application_state_006573e8.word(0x00657d7cu);
    const std::uint32_t saved_00657d80 = application_state_006573e8.word(0x00657d80u);
    const std::uint32_t saved_00657d88 = application_state_006573e8.word(0x00657d88u);
    const std::uint32_t saved_00657d9c = application_state_006573e8.word(0x00657d9cu);
    const std::uint32_t saved_00657db4 = application_state_006573e8.word(0x00657db4u);

    replay_load_004146f0();

    replay_state_005e99fc = 0u;
    std::copy_n(
        replay_snapshot_005e9a20,
        application_state_word_count,
        application_state_006573e8.words().data());

    std::copy_n(
        saved_block_00657c84.data(),
        0x36u,
        application_state_006573e8.words().data() + block_index);

    application_state_006573e8.word(0x00657a48u) = saved_00657a48;
    application_state_006573e8.word(0x00657a4cu) = saved_00657a4c;
    application_state_006573e8.word(0x00657a50u) = saved_00657a50;
    application_state_006573e8.word(0x00657d5cu) = saved_00657d5c;
    application_state_006573e8.word(0x00657d60u) = saved_00657d60;
    application_state_006573e8.word(0x00657d68u) = saved_00657d68;
    application_state_006573e8.word(0x00657d6cu) = saved_00657d6c;
    application_state_006573e8.word(0x00657d70u) = saved_00657d70;
    application_state_006573e8.word(0x00657d78u) = saved_00657d78;
    application_state_006573e8.word(0x00657d7cu) = saved_00657d7c;
    application_state_006573e8.word(0x00657d80u) = saved_00657d80;
    application_state_006573e8.word(0x00657d88u) = saved_00657d88;
    application_state_006573e8.word(0x00657d9cu) = saved_00657d9c;
    application_state_006573e8.word(0x00657db4u) = saved_00657db4;

    replay_saved_word_00606a80 = replay_tail_word_005ed844;
    replay_mode_flag_00606858 = application_state_006573e8.word(0x0065741cu);
}

} // namespace porsche
