// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

std::uint32_t __cdecl physical_file_clear_flag_00592590(std::uint32_t handle);
void __cdecl file_operation_cancel_00567cf0(std::uint32_t operation_id);
std::uint32_t* __cdecl async_slot_resolve_00564750(std::uint32_t handle);
void __cdecl async_slot_cancel_00564700(std::uint32_t handle);

} // namespace porsche
