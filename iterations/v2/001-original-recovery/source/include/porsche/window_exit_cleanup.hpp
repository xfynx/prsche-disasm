#pragma once

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 00558350 is cdecl: one pointer argument, caller-owned stack cleanup.
void __cdecl window_exit_cleanup_00558350(void* configuration);

// The 00557990 cleanup subroutine is not yet recovered into production.
void __cdecl window_exit_object_cleanup_00557990(void* configuration);

} // namespace porsche
