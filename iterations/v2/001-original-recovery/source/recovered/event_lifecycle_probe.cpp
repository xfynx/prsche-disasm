#include "porsche/auxiliary_wait.hpp"
#include "porsche/event_lifecycle.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_create.hpp"

#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static_assert(sizeof(void*) == 4, "Run 123 requires the original x86 ABI");

namespace porsche {
void event_callback_a();
void event_callback_b();
void event_callback_c();
}

namespace {
struct Scenario {
    std::uint32_t operation;
    char add_or_remove;
    std::uint32_t lock;
    std::uint32_t stopping;
    std::uint32_t event_before;
    std::uint32_t event_created;
    std::uint32_t lock_created;
    std::uint32_t thread_start_result;
    std::uint32_t current_thread;
    std::uint32_t stop_from_a;
    std::uint32_t stop_after_wait;
    char callbacks[8];
};

Scenario scenario{};
std::uint32_t wait_count{};
std::vector<std::string> trace;

void record(const std::string& item) { trace.push_back(item); }
std::uint32_t bits(const void* pointer) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(pointer));
}
std::string handle_name(const void* pointer) {
    const auto value = bits(pointer);
    if (!value) return "null";
    if (pointer == porsche::auxiliary_event_lock_0069e5d4 ||
        value == scenario.lock_created) return "lock";
    if (pointer == porsche::auxiliary_wait_event_0069e5dc ||
        value == scenario.event_created || value == scenario.event_before) return "event";
    if (pointer == &porsche::auxiliary_event_thread_006bd9c0 ||
        value == 0x006bd9c0) return "record";
    std::ostringstream out; out << std::hex << value; return out.str();
}
char callback_name(porsche::AuxiliaryEventCallback callback) {
    if (!callback) return '-';
    if (callback == porsche::event_callback_a) return 'A';
    if (callback == porsche::event_callback_b) return 'B';
    if (callback == porsche::event_callback_c) return 'C';
    return '?';
}
std::string callback_token(char value) {
    if (value == '-') return "null";
    return std::string(1, value);
}

Scenario scenario_for(unsigned id) {
    switch (id) {
    case 0: return {0, 'A', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0, {}};
    case 1: return {0, 'A', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0, {'A','B'}};
    case 2: return {0, 'C', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0,
        {'A','B','A','B','A','B','A','B'}};
    case 3: return {0, 'A', 0, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, {}};
    case 4: return {0, 'A', 0, 0, 0, 0x3300000, 0x2209000, 0, 0, 0, 0, {}};
    case 5: return {2, '-', 0x2209000, 1, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, {}};
    case 6: return {2, '-', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 1, 0, {'A','B'}};
    case 7: return {2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, {}};
    case 8: return {3, 'B', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, {'A','B','C'}};
    case 9: return {3, 'A', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, {'A'}};
    case 10:return {4, '-', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 1, 0, 0, {}};
    case 11:return {4, '-', 0, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, {}};
    case 12:return {3, 'C', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, {'A','B'}};
    case 13:return {3, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, {'A','-','B'}};
    case 14:return {0, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, {}};
    case 15:return {2, '-', 0x2209000, 1, 0, 0, 0x2209000, 1, 0, 0, 0, {}};
    case 16:return {2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 2, {'A','B'}};
    case 17:return {1, '-', 0, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, {}};
    case 18:return {2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, {'A','-','B'}};
    case 19:return {2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, {'-','B'}};
    case 20:return {2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, {'A','B','A','B','A','B','A','B'}};
    default:return {};
    }
}

void callback_a() {
    record("callback:A");
    if (scenario.stop_from_a) porsche::auxiliary_event_stopping_0069e5d8 = 1;
}
void callback_b() { record("callback:B"); }
void callback_c() { record("callback:C"); }

std::uint32_t* record_words() {
    return reinterpret_cast<std::uint32_t*>(&porsche::auxiliary_event_thread_006bd9c0);
}

void reset(unsigned id) {
    scenario = scenario_for(id);
    wait_count = 0;
    trace.clear();
    porsche::auxiliary_event_lock_0069e5d4 =
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(scenario.lock));
    porsche::auxiliary_event_stopping_0069e5d8 = scenario.stopping;
    porsche::auxiliary_wait_event_0069e5dc = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(scenario.event_before));
    for (std::uint32_t i = 0; i < 8; ++i) {
        const char name = scenario.callbacks[i];
        porsche::auxiliary_event_callbacks_0069e5b4[i] =
            name == 'A' ? porsche::event_callback_a :
            name == 'B' ? porsche::event_callback_b :
            name == 'C' ? porsche::event_callback_c : nullptr;
    }
    for (std::uint32_t i = 0; i < 7; ++i)
        record_words()[i] = 0xa5000000u + i * 0x101u;
    porsche::diagnostic_file_005deb74_set("fixture-before");
    porsche::application_diagnostic_line_005deb78 = 0x77;
}

std::string diagnostic_file_token() {
    const char* text = porsche::diagnostic_file_005deb74();
    if (!text) return "null";
    return std::string(text) == "fixture-before" ? "before" :
        std::string(text) == "\\real\\pc\\lowtimer.c" ? "lowtimer" : "other";
}

void print_state() {
    std::cout << "state=" << std::hex << bits(porsche::auxiliary_event_lock_0069e5d4)
              << ',' << porsche::auxiliary_event_stopping_0069e5d8 << ','
              << bits(porsche::auxiliary_wait_event_0069e5dc);
    for (const auto callback : porsche::auxiliary_event_callbacks_0069e5b4)
        std::cout << ',' << callback_name(callback);
    for (std::uint32_t i = 0; i < 7; ++i)
        std::cout << ',' << record_words()[i];
    std::cout << ',' << diagnostic_file_token() << ','
              << porsche::application_diagnostic_line_005deb78 << '\n';
    std::cout << "trace=";
    for (std::size_t i = 0; i < trace.size(); ++i) {
        if (i) std::cout << ';';
        std::cout << trace[i];
    }
    std::cout << '\n';
}
} // namespace

namespace porsche {

}

namespace porsche {
void event_callback_a() { callback_a(); }
void event_callback_b() { callback_b(); }
void event_callback_c() { callback_c(); }
}

namespace porsche {

void* __cdecl file_auto_event_0055fb20() {
    record("event:create");
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(scenario.event_created));
}
void* __cdecl file_worker_wait_0055fb90(void* event) {
    ++wait_count;
    record("event:wait:" + handle_name(event));
    if (scenario.stop_after_wait && wait_count == scenario.stop_after_wait)
        auxiliary_event_stopping_0069e5d8 = 1;
    return event;
}
std::uint32_t __cdecl file_event_signal_0055fb30(void* event) {
    record("event:signal:" + handle_name(event)); return 1;
}
std::uint32_t __cdecl file_close_event_0055fc10(void* event) {
    record("event:close:" + handle_name(event)); return 1;
}
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t identity) {
    const auto expected = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        &auxiliary_event_thread_006bd9c0));
    record("thread:current:" + std::string(identity == expected ? "record" : "other"));
    return static_cast<std::int32_t>(scenario.current_thread);
}
std::uint32_t __cdecl thread_wait_0055fa10(
    ThreadRecord* record_ptr, std::uint32_t timeout) {
    record("thread:join:" + handle_name(record_ptr) + "," + std::to_string(timeout));
    return 0;
}
void __cdecl thread_exit_register_00557380(void (__cdecl* callback)()) {
    record(std::string("atexit:") +
        (callback == auxiliary_event_lifecycle_stop_0053c170 ? "stop" : "other"));
}
void* __cdecl heap_lock_create_005321f0() {
    record("lock:create");
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(scenario.lock_created));
}
void __cdecl heap_enter_005322b0(void* lock) { record("lock:enter:" + handle_name(lock)); }
void __cdecl heap_leave_005322c0(void* lock) { record("lock:leave:" + handle_name(lock)); }
void __cdecl heap_lock_destroy_005322d0(void* lock) { record("lock:destroy:" + handle_name(lock)); }
std::uint32_t __cdecl window_thread_start_0055f420(void* entry,
    std::uint32_t stack, std::uint32_t priority, std::uint32_t flags,
    std::uint32_t* output) {
    const bool valid = output == reinterpret_cast<std::uint32_t*>(
        &auxiliary_event_thread_006bd9c0);
    record(std::string("thread:start:") +
        (entry == reinterpret_cast<void*>(auxiliary_event_worker_0053c0f0) ? "worker" : "other") +
        "," + std::to_string(stack) + "," + std::to_string(priority) + "," +
        std::to_string(flags) + "," + (valid ? "record" : "other"));
    if (scenario.thread_start_result && valid) {
        const std::uint32_t values[7] = {0x2401000, 0, 1, 0, 0x3344, 0x44556677, 3};
        for (std::uint32_t i = 0; i < 7; ++i) output[i] = values[i];
    }
    return scenario.thread_start_result;
}
void (__cdecl* diagnostic_handler_005debf0)(const char*) = nullptr;
void __cdecl fixture_diagnostic(const char* message) {
    record(std::string("diagnostic:") + diagnostic_file_token() + "," +
        std::to_string(application_diagnostic_line_005deb78) + "," +
        (message && std::string(message) ==
            "wininittimer - FAILED TO CREATE SECONDARY TIMER`S THREAD.\n" ? "thread-failed" : "other"));
}
}

int main(int argc, char** argv) {
    const unsigned id = argc > 1 ? static_cast<unsigned>(std::strtoul(argv[1], nullptr, 10)) : 0;
    if (id > 20) return 2;
    reset(id);
    porsche::diagnostic_handler_005debf0 = porsche::fixture_diagnostic;
    switch (scenario.operation) {
    case 0:
        porsche::auxiliary_event_callback_add_0053bfe0(
            scenario.add_or_remove == 'A' ? porsche::event_callback_a :
            scenario.add_or_remove == 'B' ? porsche::event_callback_b :
            scenario.add_or_remove == 'C' ? porsche::event_callback_c : nullptr);
        break;
    case 1: porsche::auxiliary_event_lifecycle_start_0053c060(); break;
    case 2: porsche::auxiliary_event_worker_0053c0f0(); break;
    case 3:
        porsche::auxiliary_event_callback_remove_0053c1d0(
            scenario.add_or_remove == 'A' ? porsche::event_callback_a :
            scenario.add_or_remove == 'B' ? porsche::event_callback_b :
            scenario.add_or_remove == 'C' ? porsche::event_callback_c : nullptr);
        break;
    case 4: porsche::auxiliary_event_lifecycle_stop_0053c170(); break;
    }
    print_state();
    return 0;
}
