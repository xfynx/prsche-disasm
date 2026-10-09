#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
extern void* startup_network_00628c70;
void __cdecl startup_services_004a5410();
void __cdecl startup_cd_relaunch_004a5c30();

// Recording boundaries for unrecovered subsystem consumers. Their effects are
// controlled by the probe and do not assert the callee's original behavior.
void __cdecl startup_heap_0059e9d0(std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl startup_queue_0059edb0(std::uint32_t,std::uint32_t);
void __cdecl startup_capacity_00565030(std::uint32_t);
void* __cdecl startup_network_allocate_0059ef90(std::uint32_t);
void __cdecl startup_network_construct_0048fc80(void*);
void __cdecl startup_event_0055fcf0();
void __cdecl startup_subsystem_00564e70();
void __cdecl startup_subsystem_00564ab0();
void __cdecl startup_subsystem_00564850(std::uint32_t);
void __cdecl startup_subsystem_00536e50();
void __cdecl startup_subsystem_005367b0(std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl startup_subsystem_004b6ff0();
void __cdecl startup_subsystem_00563ad0(std::uint32_t,std::uint32_t,std::uint32_t);

// Win32/CRT and opaque startup-calculated predicates.
void __cdecl startup_name_005655f0(const char*);
std::uint32_t __stdcall startup_module_filename(void*,char*,std::uint32_t);
std::int32_t __cdecl startup_drive_character_005a2c24(std::int32_t);
void __cdecl startup_drive_format_005a0fbf(char*,const char*,std::int32_t);
void __cdecl startup_command_format_005a0fbf(char*,const char*,const char*);
std::uint32_t __stdcall startup_drive_type(const char*);
std::uint32_t __stdcall startup_create_process(const char*,char*,void*,void*,std::int32_t,
    std::uint32_t,void*,const char*,void*,void*);
void __cdecl startup_exit_005a246e(std::uint32_t);
}
