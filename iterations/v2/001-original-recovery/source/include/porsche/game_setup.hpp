#pragma once

#include "porsche/heap.hpp"
#include "porsche/render_activate.hpp"
#include "porsche/window_shutdown.hpp"
#include <cstdint>

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// BSS pointer cells are owned by the shared runtime integration, not this unit.
extern const char*& game_setup_earts_base_0065b32c;
extern const char*& game_setup_load_base_0065b334;
extern void* game_setup_movie_service_0069ed0c;

// 004dd600 has no arguments and is the optional startup movie/banner pass.
void __cdecl game_setup_004dd600();

// Unrecovered resource/media/UI boundaries. Explicit object parameters model ECX.
void __cdecl game_setup_update_00560030();
void __cdecl game_setup_string_005a0fbf(char* out, const char* format,
                                         const char* base, char* scratch);
void __cdecl game_setup_movie_service_begin_00536080(void* self);
void __cdecl game_setup_movie_service_end_00536050(void* self);
std::uint32_t __cdecl game_setup_file_exists_0059dc30(const char* path);
void __cdecl game_setup_object_init_00403520(void* object, std::uint32_t bytes);
void __cdecl game_setup_resource_open_0059e440(const char* path, void* object);
void __stdcall game_setup_render_begin_006bd9b0(std::uint32_t mode);
void __stdcall game_setup_render_reset_006bd91c();
void __stdcall game_setup_render_prepare_006bd970();
void __stdcall game_setup_render_update_006bd948();
void __stdcall game_setup_render_finish_006bd978(std::uint32_t zero);
void __cdecl game_setup_movie_004dd4a0();
void __cdecl game_setup_movie_004dc850(void* stream, std::uint32_t* stop,
                                       std::uint32_t arg2,
                                       std::uint32_t arg3,
                                       std::uint32_t arg4);
void __cdecl game_setup_movie_delta_004237d0(void* begin, std::uint32_t bytes,
                                              std::uint32_t zero);
void* __cdecl game_setup_resource_file_open_0059d8e0(const char* path,
                                                      std::uint32_t zero);
void __cdecl game_setup_draw_resource_00563440(const void* item,
                                                std::uint32_t index,
                                                std::uint32_t arg3,
                                                std::uint32_t arg4,
                                                std::uint32_t arg5);
void __cdecl game_setup_draw_begin_00534540();
}
