#pragma once

namespace porsche {

// 00557990 is a cdecl, one-configuration-pointer consumer.
void __cdecl window_exit_object_cleanup_00557990(void* configuration);

// 00558c80 is cdecl with (configuration, handle); both stack words belong
// to its caller. The 005588a0 updater remains an explicit boundary.
void __cdecl window_cleanup_handle_00558c80(void* configuration, void* handle);
void __cdecl window_cleanup_update_005588a0(void* configuration);

} // namespace porsche
