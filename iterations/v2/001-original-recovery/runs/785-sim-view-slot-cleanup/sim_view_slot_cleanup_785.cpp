// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004642f0..00464329, 58 bytes, sha256 c78a0d86e00b9e37b27f7c0184b661753b8dcd24398ae86b0cfdb3203efc4165.
#include "sim_view_slot_cleanup_785.hpp"

#include <cstring>

namespace porsche {

void __cdecl application_sim_boundary_004642f0() {
    using DeleteFn = void(__thiscall*)(void*, std::int32_t);
    const std::uint32_t count = (application_state_006573e8.word(0x00657404u) == 1u) ? 2u : 1u;
    std::uint8_t* slot = view_slot_table_00627e80 + 0x20u;
    for (std::uint32_t i = 0u; i < count; ++i) {
        void* obj = nullptr;
        std::memcpy(&obj, slot, sizeof obj);
        if (obj != nullptr) {
            void* const* vtable = nullptr;
            std::memcpy(&vtable, obj, sizeof vtable);
            DeleteFn dtor = nullptr;
            std::memcpy(&dtor, vtable, sizeof dtor);
            dtor(obj, 1);
            std::memset(slot, 0, sizeof obj);
        }
        slot += 0x10cu;
    }
}

} // namespace porsche
