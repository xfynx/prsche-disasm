#pragma once
#include <cstdint>
#include <cstddef>

namespace porsche {
struct FeDefinition { std::int32_t opcode; std::uint32_t* target; const char* name; };
struct FeValue { const char* name; std::uint32_t value; };
struct FeAction { const char* name; std::uint32_t prepare_va; std::uint32_t (__cdecl* apply)(std::int32_t); };
static_assert(sizeof(FeDefinition)==12 && sizeof(FeValue)==8 && sizeof(FeAction)==12);
extern FeDefinition fe_definitions_005d1e40[];
extern FeValue fe_values_005d63a0[];
extern FeAction fe_actions_005cc5c8[];
extern char fe_car_names_005d61e8[][7];
extern std::uint32_t fe_enabled_0065b298;
extern std::uint32_t fe_action_state_005e9130[0x21e];

// Original service declarations; recovery status is in recovered/functions.json.
std::int32_t __cdecl compare_005ae3c0(const char*, const char*);
bool __cdecl open_0059e040(const char*, std::uint32_t, std::uint32_t, void**);
std::int32_t __cdecl size_00533de0(void*, std::uint32_t);
std::uint32_t __cdecl read_00533bf0(void*, std::uint32_t, void*, std::uint32_t, std::uint32_t);
std::uint32_t __cdecl close_00533da0(void*, std::uint32_t);
void* __cdecl allocate_00531ca0(const char*, std::int32_t, std::uint32_t);
std::uint32_t __cdecl free_00531f90(void*);
void* __cdecl resize_00569640(void*, std::int32_t);

std::uint32_t __cdecl fe_read_token_004b51e0(char**, char, std::int16_t, char*);
std::uint32_t __cdecl fe_value_004b5250(const char*);
std::int32_t __cdecl fe_action_004b5430(const char*);
void __cdecl fe_assignment_004b5470(char**, char*, std::int32_t, std::uint32_t**);
void __cdecl fe_file_004b5ee0(const char*, std::uint32_t**);
void __cdecl fe_arguments_004b60d0(std::int32_t, char**, std::uint32_t**);
std::uint32_t* __cdecl fe_build_004b6660(std::int32_t, char**);
void __cdecl fe_apply_004b4b80(const std::uint32_t*);
std::int32_t __cdecl fe_record_words_004b4cd0(const std::uint32_t*);
}
