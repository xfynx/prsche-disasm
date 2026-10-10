#include "porsche/auxiliary_wait.hpp"
#include "porsche/event_lifecycle.hpp"
#include "porsche/file_events.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/thread_wait.hpp"
#include "porsche/window_create.hpp"

#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static_assert(sizeof(void*) == 4, "Run 130 requires original x86 pointers");

namespace {
struct Scenario { std::uint32_t self_thread, initially_registered, detach_on_wait; };
Scenario scenario{};
std::vector<std::string> trace;
void rec(const std::string& value) { trace.push_back(value); }
std::uint32_t ptr_bits(const void* value) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
std::string handle_name(const void* value) {
    const auto bits = ptr_bits(value);
    if (bits == 0) return "null";
    if (bits == 0x2201000) return "lifecycle-lock";
    if (bits == 0x2202000) return "event";
    if (bits == 0x2203000) return "table-lock";
    return [&] { std::ostringstream out; out << std::hex << bits; return out.str(); }();
}
}

namespace porsche {
ThreadEntry fixture_thread_entries[2]{};
ThreadEntry* thread_entries_006a57e4 = fixture_thread_entries;
std::int32_t thread_capacity_006a57e8 = 1;
void* thread_table_lock_006a57ec = reinterpret_cast<void*>(0x2203000);
std::uint32_t timer_rate_005deb48 = 1000;
void (__cdecl* diagnostic_handler_005debf0)(const char*) = nullptr;

void __cdecl heap_enter_005322b0(void* lock) {
    rec("lock:enter:" + handle_name(lock));
}
void __cdecl heap_leave_005322c0(void* lock) {
    rec("lock:leave:" + handle_name(lock));
}
void* __cdecl heap_lock_create_005321f0() {
    return reinterpret_cast<void*>(0x2201000);
}
void __cdecl heap_lock_destroy_005322d0(void* lock) {
    rec("lock:destroy:" + handle_name(lock));
}
void __cdecl thread_exit_register_00557380(void (__cdecl*)()) {}
std::uint32_t __cdecl window_thread_start_0055f420(void*, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t*) { return 1; }
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t identity) {
    const auto expected = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        &auxiliary_event_thread_006bd9c0));
    rec(std::string("thread:current:") + (identity == expected ? "record" : "other"));
    return scenario.self_thread ? 1 : 0;
}
void* __cdecl thread_handle_0055f730(ThreadRecord* record) { return record->handle; }
std::uint32_t __cdecl file_timed_event_0055fbb0(void* handle, std::uint32_t ticks) {
    std::ostringstream out;
    out << "timed:" << handle_name(handle) << ':' << std::hex << ticks;
    rec(out.str());
    if (scenario.detach_on_wait)
        fixture_thread_entries[0].serial = 0xbeef;
    return 0;
}


void* __cdecl file_auto_event_0055fb20() { return nullptr; }
void* __cdecl file_worker_wait_0055fb90(void* event) { return event; }
std::uint32_t __cdecl file_event_signal_0055fb30(void* event) {
    rec("event:signal:" + handle_name(event));
    return 1;
}
std::uint32_t __cdecl file_close_event_0055fc10(void*) { return 1; }
}

int main(int argc, char** argv) {
    const unsigned id = argc > 1 ? static_cast<unsigned>(std::strtoul(argv[1], nullptr, 10)) : 0;
    if (id > 2) return 2;
    scenario = id == 0 ? Scenario{0, 1, 1} :
               id == 1 ? Scenario{1, 1, 1} : Scenario{0, 0, 0};
    trace.clear();

    porsche::auxiliary_event_lock_0069e5d4 = reinterpret_cast<void*>(0x2201000);
    porsche::auxiliary_event_stopping_0069e5d8 = 0;
    porsche::auxiliary_wait_event_0069e5dc = reinterpret_cast<void*>(0x2202000);
    porsche::auxiliary_event_thread_006bd9c0 = {
        reinterpret_cast<void*>(0x2204000), 0x1000, 1, 0xffffffffu,
        0x55aa, 0x1234, 0};
    porsche::fixture_thread_entries[0] = {
        scenario.initially_registered ? 0x1234u : 0x7777u,
        reinterpret_cast<void*>(0x2204000), 0x55aa};
    porsche::fixture_thread_entries[1] = {};

    porsche::auxiliary_event_lifecycle_stop_0053c170();

    std::cout << "state=" << std::hex
              << ptr_bits(porsche::auxiliary_event_lock_0069e5d4) << ','
              << porsche::auxiliary_event_stopping_0069e5d8 << ','
              << ptr_bits(porsche::auxiliary_wait_event_0069e5dc) << ','
              << ptr_bits(porsche::auxiliary_event_thread_006bd9c0.handle) << ','
              << porsche::auxiliary_event_thread_006bd9c0.serial << ','
              << porsche::fixture_thread_entries[0].serial << ','
              << porsche::timer_rate_005deb48 << '\n';
    std::cout << "trace=";
    for (std::size_t i = 0; i < trace.size(); ++i) {
        if (i) std::cout << ';';
        std::cout << trace[i];
    }
    std::cout << '\n';
    return 0;
}
