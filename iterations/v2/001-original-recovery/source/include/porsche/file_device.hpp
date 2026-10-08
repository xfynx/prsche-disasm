#pragma once
#include "porsche/files.hpp"

namespace porsche {
extern std::uint32_t file_page_size_006a6418;
// Original Win32 imports, supplied by the platform/probe. Not game algorithms.
void __stdcall platform_system_info(void*);
void* __stdcall platform_virtual_alloc(void*,std::uint32_t,std::uint32_t,std::uint32_t);
std::uint32_t __stdcall platform_virtual_free(void*,std::uint32_t,std::uint32_t);
std::uint32_t __cdecl io_default_key_00580670(IoNode*,std::uint32_t);
void __cdecl io_init_00580630(IoList*,IoKey,std::uint32_t);
void __cdecl io_borrow_00580680(IoList*,IoKey,std::uint32_t,IoList*);
// Worker/events preserve original services; thread creation is still unrecovered.
using FileWorker=void (__cdecl*)(std::uint32_t);
void __cdecl file_worker_00568530(std::uint32_t);
void* __cdecl file_auto_event_0055fb20();
void* __cdecl file_manual_event_0055fc20();
void* __cdecl file_wait_event_0055fc60(void*);
std::uint32_t __cdecl file_reset_event_0055fc40(void*);
std::int32_t __cdecl file_thread_start_0055f5f0(FileWorker,std::uint32_t,std::uint32_t,
                                            std::uint32_t,std::int32_t,void*);
}
