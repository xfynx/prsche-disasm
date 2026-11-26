#pragma once

#include "../856-session-reset-gate/session_reset_gate_856.hpp"

namespace porsche {

struct SessionResetObject0040e3b0 {
    std::uint32_t count;
    float reciprocal;
    std::uint32_t* records[100];
    std::uint32_t slots[100];
    std::uint32_t trailing[9];
};
static_assert(sizeof(SessionResetObject0040e3b0) == 0x34c);

std::uint32_t __fastcall session_records_helper_0040e440(
    SessionResetObject0040e3b0* self, void*, std::uint32_t* record, std::uint32_t flag);
int __cdecl session_records_compare_0040e5f0(const void* left, const void* right);

} // namespace porsche
