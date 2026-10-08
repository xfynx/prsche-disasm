#pragma once
#include "porsche/file_device.hpp"
namespace porsche {
extern std::uint32_t file_shutdown_006a5c80;
void __cdecl io_prepend_005806e0(IoList*,IoNode*);
std::uint32_t __cdecl io_locked_remove_005808f0(IoList*,IoNode*);
// Unrecovered backend and platform boundaries, typed from worker call sites.
void __cdecl file_worker_signal_0055fc30(void*);
void __cdecl file_worker_wait_0055fb90(void*);
std::uint32_t __cdecl file_last_error_0055fce0();
void* __cdecl file_backend_open_00568900(const char*,std::uint32_t,std::uint32_t);
std::uint32_t __cdecl file_backend_seek_00592140(void*,std::uint32_t);
std::uint32_t __cdecl file_backend_read_00591df0(void*,void*,std::uint32_t);
std::uint32_t __cdecl file_backend_write_00591fa0(void*,void*,std::uint32_t);
std::uint32_t __cdecl file_backend_info_00591ce0(void*,void*,void*,std::uint32_t*,void*);
std::uint32_t __cdecl file_backend_005924d0(void*,std::uint32_t);
std::uint32_t __cdecl file_backend_00592490(void*);
std::uint32_t __cdecl file_backend_00591980(void*);
}
