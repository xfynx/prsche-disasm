#include "porsche/file_events.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/thread_wait.hpp"

#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static_assert(sizeof(void*) == 4, "Run 127 requires original x86 pointers");

namespace {
struct Scenario {
    std::uint32_t timeout;
    std::uint32_t rate;
    std::uint32_t handle;
    std::uint32_t slot;
    std::uint32_t capacity;
    std::uint32_t record_serial;
    std::uint32_t entry_serial;
    std::uint32_t expire_on_wait;
    std::uint32_t wait_result;
};

Scenario scenario{};
std::uint32_t waits{};
std::vector<std::string> trace;
std::string hx(std::uint32_t value) {
    std::ostringstream out;
    out << std::hex << value;
    return out.str();
}
void record(const std::string& text) { trace.push_back(text); }
std::string handle_name(void* handle) {
    const auto value = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle));
    return value == 0 ? "null" : value == 0x2209000 ? "lock" : hx(value);
}

Scenario scenario_for(unsigned id) {
    switch (id) {
    case 0: return {25, 1000, 0, 0, 3, 0x1234, 0x1234, 0, 0};
    case 1: return {25, 60, 0x2201000, 0, 3, 0x1234, 0x7777, 0, 0};
    case 2: return {25, 60, 0x2201000, 0, 3, 0x1234, 0x1234, 0, 1};
    case 3: return {25, 60, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 4: return {0, 1000, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 5: return {0, 128, 0x2201000, 0, 3, 0x1234, 0x7777, 0, 0};
    case 6: return {0, 0, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 1};
    case 7: return {0, 99, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 8: return {0, 128, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 9: return {0xffffffffu, 100, 0x2201000, 0xffffffffu, 3, 0x1234, 0x1234, 0, 0};
    case 10:return {1, 100, 0x2201000, 3, 3, 0x1234, 0x1234, 0, 0};
    case 11:return {1, 100, 0x2201000, 1, 3, 0, 0, 0, 0};
    case 12:return {0, 0xffffffffu, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 13:return {20, 1000, 0x2201000, 0, 3, 0x1234, 0, 0, 0};
    case 14:return {0, 0x80000000u, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0};
    case 15:return {0, 0x7fffffffu, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 1};
    default:return {};
    }
}

void reset(unsigned id);
} // namespace

namespace porsche {
ThreadEntry fixture_thread_entries[4]{};
ThreadEntry* thread_entries_006a57e4 = fixture_thread_entries;
std::int32_t thread_capacity_006a57e8 = 0;
void* thread_table_lock_006a57ec = nullptr;
std::uint32_t timer_rate_005deb48 = 0;

void* __cdecl thread_handle_0055f730(ThreadRecord* thread_record) {
    return thread_record->handle;
}

void __cdecl heap_enter_005322b0(void* lock) {
    record("lock:enter:" + handle_name(lock));
}
void __cdecl heap_leave_005322c0(void* lock) {
    record("lock:leave:" + handle_name(lock));
}

std::uint32_t __cdecl file_timed_event_0055fbb0(void* handle,
    std::uint32_t ticks) {
    ++waits;
    record("timed:" + handle_name(handle) + ":" + hx(ticks));
    if (scenario.expire_on_wait && waits == scenario.expire_on_wait)
        fixture_thread_entries[scenario.slot < 4 ? scenario.slot : 0].serial = 0xbeef;
    return scenario.wait_result;
}
}

namespace {
porsche::ThreadRecord thread_record{};

void reset(unsigned id) {
    scenario = scenario_for(id);
    waits = 0;
    trace.clear();
    for (auto& entry : porsche::fixture_thread_entries)
        entry = {};
    porsche::fixture_thread_entries[0].serial = scenario.entry_serial;
    porsche::fixture_thread_entries[0].handle =
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(scenario.handle));
    porsche::fixture_thread_entries[0].id = 0x55aa;
    thread_record = {
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(scenario.handle)),
        0x1000, 2, 0xffffffffu, 0x55aa, scenario.record_serial, scenario.slot};
    porsche::thread_entries_006a57e4 = porsche::fixture_thread_entries;
    porsche::thread_capacity_006a57e8 = static_cast<std::int32_t>(scenario.capacity);
    porsche::thread_table_lock_006a57ec =
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x2209000));
    porsche::timer_rate_005deb48 = scenario.rate;
}

void print_result(std::uint32_t result) {
    std::cout << "state=" << std::hex << result << ','
              << scenario.record_serial << ','
              << porsche::fixture_thread_entries[0].serial << ','
              << static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
                    thread_record.handle)) << ','
              << porsche::timer_rate_005deb48 << '\n';
    std::cout << "trace=";
    for (std::size_t i = 0; i < trace.size(); ++i) {
        if (i) std::cout << ';';
        std::cout << trace[i];
    }
    std::cout << '\n';
}
}

int main(int argc, char** argv) {
    const unsigned id = argc > 1 ? static_cast<unsigned>(std::strtoul(argv[1], nullptr, 10)) : 0;
    if (id >= 16) return 2;
    reset(id);
    const auto result = porsche::thread_wait_0055fa10(&thread_record, scenario.timeout);
    print_result(result);
    return 0;
}
