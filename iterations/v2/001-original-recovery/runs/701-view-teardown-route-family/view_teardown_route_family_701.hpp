// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run701 packet: view teardown / route family leaves newly exposed by the
// integrated Run693 application view lifecycle. Recovered bodies:
//   00465cf0, 00465e20, 0047f190, 004b7140,
//   00473100, 00473190, 00538d80, 00540420.
//
// The exported function symbols are the exact names/signatures the accepted
// Run693 callers resolve (application_view_lifecycle_693.hpp). They are NOT
// redefined here; only the eight previously-unowned definitions live in this
// translation unit.
#pragma once

#include <cstdint>

namespace porsche {

// ---------------------------------------------------------------------------
// Canonical cells owned elsewhere (extern references, never defined here).
// ---------------------------------------------------------------------------
extern std::uint8_t view_slot_table_00627e80[0x218u]; // Run693, .bss
extern void* startup_context_table_00628bac;         // Run646, loader-zero .data
extern std::uint32_t render_teardown_state_0065b398; // Run601, loader-zero .data
extern void* game_setup_movie_service_0069ed0c;      // game_setup_globals.cpp
// Unowned cell written by the 00465e40 producer chain; first defined here.
extern void* render_secondary_object_0062810c;

// ---------------------------------------------------------------------------
// Opaque callees. Signatures reflect only the observed call-site ABI; their
// algorithms remain outside this recovery and are controlled in the native
// fixture.
// ---------------------------------------------------------------------------
void __fastcall teardown_secondary_destroy_0059f1c0(void* self, void* unused_edx);
std::uint32_t __cdecl application_release_0059f050(void* object); // canonical
void __cdecl startup_service_noop_00516950();                     // canonical
void __cdecl registry_item_noop_00514990(void* item);
void __cdecl application_context_member_destroy_block_00441200(
    void* block, std::uint32_t bytes);                            // canonical
void __fastcall buffer_cell_release_00539eb0(void* self, void* unused_edx);
void __fastcall movie_service_delete_slot0(void* self, void* unused_edx, std::uint32_t arg);

// ---------------------------------------------------------------------------
// Recovered original bodies (exact Run693 extern names/signatures).
// ---------------------------------------------------------------------------
void __cdecl view_route_counter_00465cf0(std::int32_t index);
void __cdecl view_teardown_probe_00465e20();
void __cdecl view_teardown_finish_0047f190();
void __cdecl view_teardown_sync_004b7140();
void __fastcall view_slot_service_00473100(void* self, void* unused_edx,
                                           std::uint32_t mode);
void __fastcall view_slot_snapshot_00473190(void* self, void* unused_edx,
                                            const void* source);
void __fastcall view_teardown_release_00538d80(void* self, void* unused_edx);
void __fastcall view_teardown_release_00540420(void* self, void* unused_edx);

} // namespace porsche
