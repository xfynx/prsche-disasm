#pragma once
#include <cstdint>

namespace porsche {
// Original initialized data at 005ded30..005ded78; these arrays preserve the
// original pair and callback-table boundaries and remain mutable.
extern std::uint32_t render_driver_state_pairs_005ded30[12];
extern void (__cdecl *render_driver_state_callbacks_005ded60[6])(
    std::uint32_t, std::uint32_t);

void __fastcall render_driver_apply_states_00538af0(void* ignored_ecx,
                                                    void* ignored_edx);
void __cdecl render_display_finish_driver_00537850(void* self,
                                                    std::uint32_t value);
void __fastcall render_display_finish_driver_core_00537850(
    void* self, void* ignored_edx, std::uint32_t value);
void __cdecl render_driver_commit_state_005405c0(std::uint32_t key,
                                                std::uint32_t value);
void __cdecl render_driver_select_state_00540550(std::uint32_t key,
                                                std::uint32_t value);
void __cdecl render_driver_set_movie_state_00540590(std::uint32_t ignored,
                                                    std::uint32_t enabled);

// 00540500 is a distinct, unresolved original callback. It is declared for
// address transport only and intentionally has no implementation here.
void __cdecl render_driver_x87_handler_00540500(std::uint32_t,
                                                std::uint32_t);
}
