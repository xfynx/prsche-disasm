#pragma once
#include "porsche/files.hpp"
#include <cstdint>

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
extern std::int32_t physical_count_006af080;
extern PhysicalFile* physical_files_006af084;
extern FileDevice* devices_006a5c7c;
extern void* free_operation_arena_006a5c54;
extern void* application_pool_lock_006a5c78;
extern std::uint32_t application_pool_shutdown_state_006a5c74;

// 005679f0 plus the first-call path through 00591820.
std::int32_t __cdecl application_pool_initialize_005679f0(
    std::uint32_t disk_slots,std::uint32_t unused,std::int32_t operation_slots);
void __cdecl disk_slots_init_00591820(std::int32_t requested);

// Existing shutdown and CRT exit registration remain explicit boundaries.
void __cdecl application_pool_shutdown_005678f0();
void __cdecl application_pool_disk_slots_release_005918c0();
void __cdecl application_callback_registry_insert_005a2400(void(__cdecl*)());
}
