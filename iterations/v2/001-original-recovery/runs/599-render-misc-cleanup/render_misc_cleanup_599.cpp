// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00449b40..00449b67, 40 bytes, sha256 b9b191b8ab6aa45883a6b8f202868d8ec2ff806078ff7bce86b97e5285bf491b.
// Original 0053f0b0..0053f112, 99 bytes, sha256 dbc5031bd948c1a13a0b7f3390bea9e048436da2d36e12ed38eb5a1a860d33de.
#include "render_misc_cleanup_599.hpp"

namespace porsche {

std::uint8_t render_identity_lut_00618e74[256] = {};
std::uint8_t* render_identity_lut_ptr_00619758 = nullptr;
RenderCleanupNode_599* render_cleanup_head_0069ebb0 = nullptr;

void __cdecl render_cleanup_register_0053f0b0(std::uint32_t callback_va) {
    void* const raw_first = render_allocate_0059ef90(8u);
    RenderCleanupNode_599* esi = nullptr;
    if (raw_first != nullptr) {
        esi = static_cast<RenderCleanupNode_599*>(raw_first);
        esi->next = nullptr;
        esi->callback_va = 0u;
    }
    esi->callback_va = callback_va;
    RenderCleanupNode_599* const head = render_cleanup_head_0069ebb0;
    if (head == nullptr) {
        void* const raw_sentinel = render_allocate_0059ef90(8u);
        RenderCleanupNode_599* sentinel = nullptr;
        if (raw_sentinel != nullptr) {
            sentinel = static_cast<RenderCleanupNode_599*>(raw_sentinel);
            sentinel->next = nullptr;
            sentinel->callback_va = 0x0053f980u;
            esi->next = sentinel;
            render_cleanup_head_0069ebb0 = esi;
            return;
        }
        esi->next = nullptr;
        render_cleanup_head_0069ebb0 = esi;
        return;
    }
    esi->next = head;
    render_cleanup_head_0069ebb0 = esi;
}

void __cdecl render_misc_00449b40() {
    render_cleanup_register_0053f0b0(0x00449b70u);
    for (std::uint32_t i = 0u; i < 256u; ++i) {
        render_identity_lut_00618e74[i] = static_cast<std::uint8_t>(i);
    }
    render_identity_lut_ptr_00619758 = &render_identity_lut_00618e74[0];
}

} // namespace porsche
