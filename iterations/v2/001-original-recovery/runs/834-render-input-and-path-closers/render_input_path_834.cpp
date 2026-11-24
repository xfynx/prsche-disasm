// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Recovers four 0-child closers:
// - render_missing_setup_00467535 (00467535..0046754d, 25B cold path in 00467470)
//   + .data literals 005cf78c (38B) and 005cf7b4 (7B)
// - input_negative_index_00532e10 (00532e10 negative-index boundary in input_state.cpp)
// - input_unmapped_index_00532e10 (00532e10 >=32-index boundary in input_state.cpp)
// - resource_invalid_module_path_0059d650 (0059d687 no-backslash jump-through boundary in resource_paths.cpp)
#include "render_input_path_834.hpp"

namespace porsche {

const char render_missing_setup_text_005cf78c[38] = "Run 3D Setup before running the game.";
const char render_missing_setup_title_005cf7b4[7] = "Error:";

[[noreturn]] void __cdecl render_missing_setup_00467535() {
    render_message_box_005b2270(
        0u, render_missing_setup_text_005cf78c, render_missing_setup_title_005cf7b4, 0u);
    process_exit_005a246e(1u);
}

void* __cdecl input_negative_index_00532e10(std::int32_t index, std::uint32_t mode) {
    (void)index;
    (void)mode;
    return nullptr;
}

void* __cdecl input_unmapped_index_00532e10(std::uint32_t index, std::uint32_t mode) {
    (void)index;
    (void)mode;
    return nullptr;
}

void __cdecl resource_invalid_module_path_0059d650(const char* module_path) {
    (void)module_path;
}

} // namespace porsche
