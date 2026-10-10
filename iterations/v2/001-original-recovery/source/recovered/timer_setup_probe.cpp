#include "porsche/clock_worker.hpp"
#include "porsche/file_events.hpp"
#include "porsche/object_update.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/timer_setup.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_runtime.hpp"

#include <algorithm>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace porsche {
ClockWorkerCallback clock_worker_callbacks_006b7c20[8]{};
std::uint32_t clock_worker_carry_006b7c44{};
std::uint32_t clock_worker_iterations_006b7c7c{};
void* clock_worker_event_006a5bfc{};
std::uint32_t clock_worker_active_006a5c0c{};
std::uint32_t current_tick_006b7c40{};
std::uint32_t timer_rate_005deb48{};
std::uint32_t __cdecl clock_worker_00565270() { return 0; }
}

namespace {
struct Scenario {
    std::uint32_t interval;
    std::uint32_t caps_result;
    std::uint32_t thread_result;
    std::uint32_t begin_result;
    std::uint32_t timer_event_result;
    std::uint32_t initial_active;
    std::uint32_t initial_timer_id;
    std::uint32_t initial_period;
    std::uint32_t initial_thread;
    std::uint32_t kill_clears_id;
    std::uint32_t idle_clears_event;
    std::uint32_t sleep_increments_worker;
    std::vector<std::uint32_t> ticks;
};

Scenario scenario;
std::size_t tick_at{};
std::uint32_t sleep_count{};
std::vector<std::string> events;

void event(const std::string& text) { events.push_back(text); }
std::string hex(std::uint32_t value) {
    std::ostringstream out;
    out << "0x" << std::hex << value;
    return out.str();
}

Scenario get_scenario(unsigned id) {
    switch (id) {
    case 0: return {128, 0, 1, 0, 9, 0, 0, 0, 0, 0, 0, 1,
        {1000, 1000, 1000, 1000, 1010}};
    case 1: return {10001, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 1,
        {2000, 2000, 2000, 2000, 2010}};
    case 2: return {128, 1, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, {3000}};
    case 3: return {1000, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, {4000}};
    case 4: return {1000, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, {5000}};
    case 5: return {1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        {6000, 6000, 6000, 6000}};
    case 6: return {1000, 0, 1, 0, 10, 1, 7, 1, 0x2207000, 2, 0, 0,
        {7000, 7000, 7000, 12000, 17000}};
    case 7: return {1000, 0, 1, 0, 8, 0, 0, 0, 0, 2, 0, 0,
        {8000, 9003, 9004, 9004, 14004}};
    case 8: return {1000, 0, 1, 0, 10, 1, 7, 1, 0x2207000, 0, 1, 0,
        {7000, 7000, 7000, 12000, 17000}};
    default: return {};
    }
}

void reset(unsigned id) {
    scenario = get_scenario(id);
    tick_at = 0;
    sleep_count = 0;
    events.clear();
    porsche::timer_setup_interval_006a5bf8 = 0;
    porsche::timer_setup_fraction_006a5c00 = 0;
    porsche::timer_setup_clock_006a5c04 = 0;
    porsche::timer_setup_period_006a5c08 = scenario.initial_period;
    porsche::timer_setup_event_id_006a5c10 = scenario.initial_timer_id;
    porsche::timer_setup_correction_count_006a5c1c = 0;
    porsche::timer_setup_saved_clock_006a5c20 = 0;
    porsche::clock_worker_event_006a5bfc = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(scenario.initial_thread));
    porsche::clock_worker_active_006a5c0c = scenario.initial_active;
    porsche::clock_worker_iterations_006b7c7c = 0x11111111;
    porsche::clock_worker_carry_006b7c44 = 0x22222222;
    porsche::current_tick_006b7c40 = 0x33333333;
    porsche::timer_rate_005deb48 = 0x44444444;
    auto* record_words = reinterpret_cast<std::uint32_t*>(
        &porsche::timer_setup_thread_record_006b7c60);
    for (std::uint32_t i = 0; i < 7; ++i)
        record_words[i] = 0xa5a50000u + i * 0x101u;
    porsche::shared_runtime_word_005deb74 = 0;
    porsche::shared_runtime_word_005deb78 = 0;
}

void print_result() {
    std::cout << "state="
        << porsche::timer_setup_interval_006a5bf8 << ','
        << porsche::timer_setup_fraction_006a5c00 << ','
        << porsche::timer_setup_clock_006a5c04 << ','
        << porsche::timer_setup_period_006a5c08 << ','
        << porsche::timer_setup_event_id_006a5c10 << ','
        << porsche::timer_setup_correction_count_006a5c1c << ','
        << porsche::timer_setup_saved_clock_006a5c20 << ','
        << porsche::clock_worker_active_006a5c0c << ','
        << porsche::clock_worker_iterations_006b7c7c << ','
        << porsche::clock_worker_carry_006b7c44 << ','
        << porsche::current_tick_006b7c40 << ','
        << porsche::timer_rate_005deb48 << ','
        << static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
            porsche::clock_worker_event_006a5bfc)) << ','
        << porsche::shared_runtime_word_005deb78;
    const auto* record_words = reinterpret_cast<const std::uint32_t*>(
        &porsche::timer_setup_thread_record_006b7c60);
    for (std::uint32_t i = 0; i < 7; ++i) {
        std::cout << ',' << record_words[i];
    }
    std::cout << '\n';
    std::cout << "events=";
    for (std::size_t i = 0; i < events.size(); ++i) {
        if (i) std::cout << ';';
        std::cout << events[i];
    }
    std::cout << '\n';
}
} // namespace

namespace porsche {
std::uint32_t __stdcall platform_get_tick_count() {
    const auto i = tick_at < scenario.ticks.size() ? tick_at++ : tick_at;
    const std::uint32_t value = scenario.ticks.empty() ? 0 :
        scenario.ticks[std::min(i, scenario.ticks.size() - 1)];
    event("tick:" + std::to_string(value));
    return value;
}

std::uint32_t __cdecl file_event_signal_0055fb30(void* handle) {
    event("signal:" + hex(static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(handle))));
    return 1;
}
void __cdecl window_idle_0055f740(std::uint32_t milliseconds) {
    ++sleep_count;
    event("sleep:" + std::to_string(milliseconds));
    if (scenario.sleep_increments_worker && sleep_count == 1)
        ++clock_worker_iterations_006b7c7c;
    if (scenario.kill_clears_id == 2 && clock_worker_active_006a5c0c == 0)
        timer_setup_event_id_006a5c10 = 0;
    if (scenario.idle_clears_event && clock_worker_active_006a5c0c == 0)
        clock_worker_event_006a5bfc = nullptr;
}
void __cdecl thread_exit_register_00557380(void (__cdecl* callback)()) {
    event(std::string("atexit:") + (callback == timer_cleanup_00564fa0 ? "cleanup" : "other"));
}

std::uint32_t __stdcall timer_get_device_caps_boundary(void* caps,
    std::uint32_t size) {
    event("caps:" + std::to_string(size));
    if (scenario.caps_result == 0 && size >= 8) {
        auto* words = static_cast<std::uint32_t*>(caps);
        words[0] = 1;
        words[1] = 1;
    }
    return scenario.caps_result;
}
std::uint32_t __stdcall timer_begin_period_boundary(std::uint32_t period) {
    event("begin:" + std::to_string(period));
    return scenario.begin_result;
}
std::uint32_t __stdcall timer_kill_event_boundary(std::uint32_t id) {
    event("kill:" + std::to_string(id));
    if (scenario.kill_clears_id == 1) timer_setup_event_id_006a5c10 = 0;
    return 0;
}
std::uint32_t __stdcall timer_set_event_boundary(std::uint32_t delay,
    std::uint32_t resolution, MultimediaTimerCallback callback,
    std::uint32_t user, std::uint32_t flags) {
    event("set:" + std::to_string(delay) + "," + std::to_string(resolution) +
        "," + std::to_string(user) + "," + std::to_string(flags) + "," +
        (callback == timer_producer_00564eb0 ? "producer" : "other"));
    return scenario.timer_event_result;
}
std::uint32_t __stdcall timer_end_period_boundary(std::uint32_t period) {
    event("end:" + std::to_string(period));
    return 0;
}
std::uint32_t __cdecl window_thread_start_0055f420(void* entry,
    std::uint32_t stack_size, std::uint32_t priority, std::uint32_t unused,
    std::uint32_t* output) {
    event(std::string("thread:") +
        (entry == reinterpret_cast<void*>(clock_worker_00565270) ? "worker" : "other") +
        "," + std::to_string(stack_size) + "," + std::to_string(priority) + "," +
        std::to_string(unused) + "," +
        (output == reinterpret_cast<std::uint32_t*>(
            &timer_setup_thread_record_006b7c60) ? "out-record" : "out-wrong"));
    if (scenario.thread_result != 0 && output == reinterpret_cast<std::uint32_t*>(
            &timer_setup_thread_record_006b7c60)) {
        auto* record = output;
        record[0] = 0x2207100;
        record[1] = 0;
        record[2] = 2;
        record[3] = 0;
        record[4] = 0x3456;
        record[5] = 0x11223344;
        record[6] = 7;
        clock_worker_event_006a5bfc = reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(scenario.initial_thread ? scenario.initial_thread : 0x2207100));
    }
    return scenario.thread_result;
}
void __cdecl timer_diagnostic_boundary(const char* message, ...) {
    std::uint32_t value = 0;
    if (message && std::string(message).find("%d") != std::string::npos) {
        va_list args;
        va_start(args, message);
        value = va_arg(args, std::uint32_t);
        va_end(args);
    }
    event("diag:" + std::to_string(shared_runtime_word_005deb78) + ":" +
        std::to_string(value) + ":" +
        (diagnostic_file_005deb74() ? diagnostic_file_005deb74() : "null"));
}
void __cdecl timer_auxiliary_wait_boundary() { event("aux-call"); }
} // namespace porsche

int main(int argc, char** argv) {
    const unsigned id = argc > 1 ? static_cast<unsigned>(std::strtoul(argv[1], nullptr, 10)) : 0;
    if (id > 8) return 2;
    reset(id);
    porsche::timer_setup_00565030(scenario.interval);
    print_result();
    return 0;
}
