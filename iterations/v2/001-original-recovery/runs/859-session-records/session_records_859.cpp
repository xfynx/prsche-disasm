// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "session_records_859.hpp"
#include "porsche/window_handlers.hpp"
#include <algorithm>

extern float _DAT_005b24a8;

namespace porsche {

int __cdecl session_records_compare_0040e5f0(const void* left, const void* right) {
    const auto* a = *static_cast<std::uint32_t* const*>(left);
    const auto* b = *static_cast<std::uint32_t* const*>(right);
    return static_cast<std::int32_t>(a[1] - b[1]);
}

std::uint32_t __fastcall session_records_helper_0040e440(
    SessionResetObject0040e3b0* self, void*, std::uint32_t* record, std::uint32_t flag) {
    const auto type = record[0];
    if (type == 5 && static_cast<std::uint8_t>(flag) != 0) {
        record[15] = reinterpret_cast<std::uint32_t>(record + 16);
    }
    self->records[self->count] = record;
    const auto span = type == 5 ? 0x40u + record[14] * 0x14u :
                      type == 3 ? 0x48u :
                      (type == 1 || type == 2) ? 0x14u : 0u;
    ++self->count;
    return span;
}

void __fastcall session_reset_children_0040e3b0(
    SessionResetObject0040e3b0* self, void*, const void* payload) {
    self->count = 0;
    self->reciprocal = 0.0f;
    std::fill_n(self->slots, 100, 0xfffff600u);
    std::fill_n(self->trailing, 9, 0u);
    if (!payload) return;
    auto* data = static_cast<std::uint32_t*>(const_cast<void*>(payload));
    auto* cursor = data + 1;
    for (int index = 0; index < static_cast<std::int32_t>(*data); ++index) {
        cursor += session_records_helper_0040e440(self, nullptr, cursor, 1) / 4;
    }
    if (self->count != 0) {
        window_handler_sort_005a112b(self->records, self->count, 4, session_records_compare_0040e5f0);
    }
    const std::int32_t count = static_cast<std::int32_t>(self->count);
    if (count != 0) {
        float reciprocal;
        __asm {
            fild count
            fdivr _DAT_005b24a8
            fstp reciprocal
        }
        self->reciprocal = reciprocal;
    }
}

} // namespace porsche
