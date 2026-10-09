#pragma once
#include "porsche/files.hpp"

namespace porsche {
using ResourceModuleFilename = std::uint32_t (__stdcall*)(void*, char*, std::uint32_t);
using ResourceDriveType = std::uint32_t (__stdcall*)(const char*);
extern ResourceModuleFilename resource_module_filename_005b2064;
extern ResourceDriveType resource_drive_type_005b2060;
void __cdecl resource_format_drive_005a0fbf(char*, const char*, int);
void __cdecl resource_format_path_005a0fbf(char*, const char*, const char*, const char*);
void __cdecl resource_invalid_module_path_0059d650(const char*);
std::int32_t __cdecl resource_paths_0059d650();
}
