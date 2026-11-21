#include "scene_stage_stack_core_721.hpp"
#include "porsche/render_startup.hpp"
#include <cstring>

namespace porsche {
void* scene_stage_tree_root_00627df0 = nullptr;
void* scene_stage_group_root_006221d8 = nullptr;
std::uint32_t scene_stage_matrix_00624de8[256][8]{};

namespace {
void put(void* base, unsigned offset, void* value) {
    std::memcpy(static_cast<unsigned char*>(base) + offset, &value, 4);
}
}

void __cdecl scene_stage_stack_core_004552b0(unsigned char* original_stack_bytes) {
    void* const root = render_allocate_0059ef90(8u);
    if (root != nullptr) {
        void* const first = render_allocate_0059ef90(12u);
        if (first != nullptr) {
            (void)scene_stage_tree_ctor_00455830(first, nullptr,
                original_stack_bytes + 1u, original_stack_bytes);
        }
        put(root, 4u, first);
        scene_stage_tree_load_00455570(static_cast<unsigned char*>(root) + 4u, nullptr);
        void* const second = render_allocate_0059ef90(12u);
        if (second != nullptr) {
            (void)scene_stage_tree_ctor_004558b0(second, nullptr,
                original_stack_bytes + 3u, original_stack_bytes + 2u);
        }
        put(root, 0u, second);
        scene_stage_tree_root_00627df0 = root;
    } else {
        scene_stage_tree_root_00627df0 = nullptr;
    }

    void* const group = render_allocate_0059ef90(0x4cu);
    scene_stage_group_root_006221d8 = group == nullptr ? nullptr
        : scene_stage_group_ctor_0059f070(group, nullptr);
    for (unsigned i = 0; i < 256u; ++i) {
        auto& row = scene_stage_matrix_00624de8[i];
        row[0] = 0u;
        row[1] = 0u;
        row[2] = 0x3f800000u;
        row[3] = 0u;
        row[4] = 0x3f800000u;
        row[5] = 0x3f800000u;
        row[6] = 0u;
        row[7] = 0x3f800000u;
    }
    __asm { xor ecx, ecx }
}
}
