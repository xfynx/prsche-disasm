// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run889: session_extension_service_00406520 (385B) and closed extension
// constructors/destructors (16 functions, 1,322B code).
#pragma once

#include <cstdint>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 pointer ABI");

// Shared arena scalar owned by application_globals.cpp.
extern std::uint32_t& global_006573f0;

// Owned .data/.bss state for session extension creation and tick scaling.
struct SessionExtensionModeItem_889 {
    std::uint32_t words[13];
};
static_assert(sizeof(SessionExtensionModeItem_889) == 52u);

struct SessionExtensionModeEntry_889 {
    std::uint32_t count;
    const SessionExtensionModeItem_889* items;
};
static_assert(sizeof(SessionExtensionModeEntry_889) == 8u);

extern const SessionExtensionModeEntry_889 session_extension_mode_table_005cbd20[6];
extern std::uint32_t session_extension_any_mode20_005e67a0;
extern std::int32_t session_extension_tick_rate_005e7540;

// Native vtable mirrors matching original slot layouts (005b24b0..005b25b0).
extern const std::uint32_t session_extension_vtable_005b25b0[2];
extern const std::uint32_t session_extension_vtable_005b25a0[3];
extern const std::uint32_t session_extension_vtable_005b2594[2];
extern const std::uint32_t session_extension_vtable_005b2500[3];
extern const std::uint32_t session_extension_vtable_005b2544[3];
extern const std::uint32_t session_extension_vtable_005b2560[3];
extern const std::uint32_t session_extension_vtable_005b2588[2];
extern const std::uint32_t session_extension_vtable_005b2510[2];
extern const std::uint32_t session_extension_vtable_005b2570[3];
extern const std::uint32_t session_extension_vtable_005b24d0[3];
extern const std::uint32_t session_extension_vtable_005b24b0[2];

// Unrecovered virtual-slot boundaries referenced only via vtable slots.
void __fastcall session_extension_a_tick_00405690(void* self, void* unused_edx);
void __fastcall session_extension_b_tick_004058a0(void* self, void* unused_edx);
void __fastcall session_extension_c_tick_00406020(void* self, void* unused_edx);
void __fastcall session_extension_d_tick_00403e40(void* self, void* unused_edx);
void __fastcall session_extension_ab_reset_00403990(void* self, void* unused_edx);

// Recovered original functions (16 bodies, 1,322B).
void __cdecl session_extension_service_00406520();
void* __fastcall session_extension_a_ctor_004056b0(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_b_ctor_00405910(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_c_ctor_00406490(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_d_ctor_00403e00(
    void* self, void* unused_edx, void* player, std::uint32_t mode20_index);
void* __fastcall session_extension_ab_base_ctor_00405c30(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_ab_core_ctor_00403cb0(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_d_base_ctor_00403800(
    void* self, void* unused_edx, void* player, std::uint32_t mode20_index);
void* __fastcall session_extension_base_ctor_00406790(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_helper_ctor_0040b510(
    void* self, void* unused_edx, void* player);
void* __fastcall session_extension_base_dtor_00406800(
    void* self, void* unused_edx, std::uint32_t flags);
void __fastcall session_extension_base_fini_00406840(
    void* self, void* unused_edx);
void* __fastcall session_extension_helper_dtor_004066b0(
    void* self, void* unused_edx, std::uint32_t flags);
void* __fastcall session_extension_cd_dtor_004064c0(
    void* self, void* unused_edx, std::uint32_t flags);
void* __fastcall session_extension_ab_dtor_00405950(
    void* self, void* unused_edx, std::uint32_t flags);
std::uint32_t __fastcall session_extension_helper_slot2_00403d80(
    void* self, void* unused_edx);

} // namespace porsche
