#pragma once
#include <cstdint>
namespace porsche {
extern std::uint8_t startup_lifecycle_mode_005de6b8;
void __fastcall startup_lifecycle_end_raw_00536050(void*,void*);
void __fastcall startup_lifecycle_frame_raw_005360a0(void*,void*,std::uint32_t);
void __cdecl game_setup_movie_service_end_00536050(void*);
void __cdecl frame_pump_boundary_005360a0(void*,std::uint32_t);
}
