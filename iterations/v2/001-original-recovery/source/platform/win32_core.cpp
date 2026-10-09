#include "porsche/file_device.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/application_heap.hpp"
#include <windows.h>

// Platform adapters only. Original algorithms remain in recovered/Porsche.exe.
// Imports/argument order are pinned by Runs006/009/010/014/025.
static_assert(sizeof(void*) == 4 && sizeof(SYSTEM_INFO) == 36);
static_assert(sizeof(CRITICAL_SECTION) == 24);

namespace porsche {
void __stdcall platform_system_info(void* output) {
    ::GetSystemInfo(static_cast<SYSTEM_INFO*>(output));
}
void* __stdcall platform_virtual_alloc(void* address, std::uint32_t bytes,
    std::uint32_t kind, std::uint32_t protection) {
    return ::VirtualAlloc(address, bytes, kind, protection);
}
std::uint32_t __stdcall platform_virtual_free(void* address,
    std::uint32_t bytes, std::uint32_t kind) {
    return ::VirtualFree(address, bytes, kind);
}
void* __stdcall platform_create_event(void* security, std::int32_t manual,
    std::int32_t initial, const char* name) {
    return ::CreateEventA(static_cast<SECURITY_ATTRIBUTES*>(security), manual,
        initial, name);
}
std::uint32_t __stdcall platform_set_event(void* event) { return ::SetEvent(event); }
std::uint32_t __stdcall platform_reset_event(void* event) { return ::ResetEvent(event); }
std::uint32_t __stdcall platform_wait_events(std::uint32_t count,
    void* const* handles, std::int32_t all, std::uint32_t timeout,
    std::int32_t alertable) {
    return ::WaitForMultipleObjectsEx(count, handles, all, timeout, alertable);
}
std::uint32_t __stdcall platform_close_handle(void* handle) { return ::CloseHandle(handle); }
std::uint32_t __stdcall platform_last_error() { return ::GetLastError(); }
std::uint32_t __stdcall platform_sleep(std::uint32_t timeout, std::int32_t alertable) {
    return ::SleepEx(timeout, alertable);
}
std::uint32_t __stdcall platform_current_thread_id() { return ::GetCurrentThreadId(); }
void* __stdcall platform_current_process() { return ::GetCurrentProcess(); }
void* __stdcall platform_current_thread() { return ::GetCurrentThread(); }
std::uint32_t __stdcall platform_duplicate_handle(void* source_process,
    void* source, void* target_process, void** target, std::uint32_t access,
    std::int32_t inherit, std::uint32_t options) {
    return ::DuplicateHandle(source_process, source, target_process, target,
        access, inherit, options);
}
void* __stdcall platform_create_thread(void* security, std::uint32_t stack,
    ThreadBootstrap entry, void* argument, std::uint32_t flags, std::uint32_t* id) {
    static_assert(sizeof(DWORD) == sizeof(std::uint32_t));
    return ::CreateThread(static_cast<SECURITY_ATTRIBUTES*>(security), stack,
        reinterpret_cast<LPTHREAD_START_ROUTINE>(entry), argument, flags,
        reinterpret_cast<DWORD*>(id));
}
std::uint32_t __stdcall platform_resume_thread(void* thread) { return ::ResumeThread(thread); }
std::uint32_t __stdcall platform_thread_priority(void* thread, std::int32_t value) {
    return ::SetThreadPriority(thread, value);
}
void __stdcall platform_initialize_critical_section(void* lock) {
    ::InitializeCriticalSection(static_cast<CRITICAL_SECTION*>(lock));
}
void __stdcall platform_enter_critical_section(void* lock) {
    ::EnterCriticalSection(static_cast<CRITICAL_SECTION*>(lock));
}
void __stdcall platform_leave_critical_section(void* lock) {
    ::LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(lock));
}
void __stdcall platform_delete_critical_section(void* lock) {
    ::DeleteCriticalSection(static_cast<CRITICAL_SECTION*>(lock));
}
std::uint32_t __cdecl application_system_page_size() {
    SYSTEM_INFO info;
    ::GetSystemInfo(&info);
    return info.dwPageSize;
}
void* __cdecl application_virtual_alloc(void* address, std::uint32_t bytes,
    std::uint32_t kind, std::uint32_t protection) {
    return platform_virtual_alloc(address, bytes, kind, protection);
}
std::uint32_t __cdecl application_virtual_free(void* address,
    std::uint32_t bytes, std::uint32_t kind) {
    return platform_virtual_free(address, bytes, kind);
}
}
