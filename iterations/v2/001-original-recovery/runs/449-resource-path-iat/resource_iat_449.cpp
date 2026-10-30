// Bind the existing resource-path declarations to the loader-owned import cells.
// These are link-time data aliases: no copied pointers, wrapper addresses or
// dynamic C++ initialization. Original Porsche.exe IAT 005b2060/005b2064.
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error This binding requires the original MSVC x86 import ABI
#endif
#pragma comment(linker, "/alternatename:?resource_module_filename_005b2064@porsche@@3P6GIPAXPADI@ZA=__imp__GetModuleFileNameA@12")
#pragma comment(linker, "/alternatename:?resource_drive_type_005b2060@porsche@@3P6GIPBD@ZA=__imp__GetDriveTypeA@4")
#pragma comment(linker, "/include:__imp__GetModuleFileNameA@12")
#pragma comment(linker, "/include:__imp__GetDriveTypeA@4")
// Keep this directive-bearing object in the static archive's final link.
// This infrastructure anchor is never called by recovered game code and adds
// no original function or original state.
extern "C" void __cdecl resource_path_iat_449_anchor() {}
