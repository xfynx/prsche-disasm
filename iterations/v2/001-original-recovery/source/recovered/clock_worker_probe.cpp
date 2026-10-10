#include "porsche/clock_worker.hpp"

#include "porsche/file_device.hpp"
#include "porsche/file_events.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/object_update.hpp"
#include "porsche/window_runtime.hpp"

#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace porsche {
std::uint32_t current_tick_006b7c40 = 0;
std::uint32_t timer_rate_005deb48 = 0;
}

namespace {
struct Mutation {
    std::uint32_t trigger;
    std::uint32_t occurrence;
    std::uint32_t slot;
    std::uint32_t replacement;
};

std::vector<std::string> events;
std::vector<std::uint32_t> waits;
std::vector<std::uint32_t> ticks;
std::vector<Mutation> mutations;
std::array<std::uint32_t, 9> callback_calls{};
std::size_t wait_index = 0;
std::size_t tick_index = 0;
std::uint32_t created_handle = 0;

std::vector<std::string> split(const std::string& value, char delimiter) {
    std::vector<std::string> result;
    std::stringstream stream(value);
    std::string part;
    while (std::getline(stream, part, delimiter)) result.push_back(part);
    if (!value.empty() && value.back() == delimiter) result.emplace_back();
    return result;
}

std::vector<std::uint32_t> numbers(const std::string& value) {
    std::vector<std::uint32_t> result;
    if (value.empty() || value == "-") return result;
    for (const auto& part : split(value, ','))
        result.push_back(static_cast<std::uint32_t>(std::stoull(part)));
    return result;
}

porsche::ClockWorkerCallback callback_for(std::uint32_t id);

void invoke(std::uint32_t id) {
    const auto occurrence = ++callback_calls[id];
    events.push_back("callback:" + std::to_string(id));
    for (const auto& mutation : mutations) {
        if (mutation.trigger == id && mutation.occurrence == occurrence) {
            porsche::clock_worker_callbacks_006b7c20[mutation.slot] =
                callback_for(mutation.replacement);
            events.push_back("mutation:" + std::to_string(id) + ":" +
                std::to_string(occurrence) + ":" +
                std::to_string(mutation.slot) + ":" +
                std::to_string(mutation.replacement));
        }
    }
}
void __cdecl callback1() { invoke(1); }
void __cdecl callback2() { invoke(2); }
void __cdecl callback3() { invoke(3); }
void __cdecl callback4() { invoke(4); }
void __cdecl callback5() { invoke(5); }
void __cdecl callback6() { invoke(6); }
void __cdecl callback7() { invoke(7); }
void __cdecl callback8() { invoke(8); }

porsche::ClockWorkerCallback callback_for(std::uint32_t id) {
    switch (id) {
    case 1: return callback1;
    case 2: return callback2;
    case 3: return callback3;
    case 4: return callback4;
    case 5: return callback5;
    case 6: return callback6;
    case 7: return callback7;
    case 8: return callback8;
    default: return nullptr;
    }
}

std::uint32_t callback_id(porsche::ClockWorkerCallback callback) {
    for (std::uint32_t id = 1; id <= 8; ++id)
        if (callback == callback_for(id)) return id;
    return 0;
}

std::string handle_text(void* handle) {
    return std::to_string(static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(handle)));
}

bool execute(const std::string& line) {
    const auto fields = split(line, '|');
    if (fields.size() != 11) return false;
    const auto waits_in = numbers(fields[7]);
    const auto ticks_in = numbers(fields[8]);
    const auto callback_ids = numbers(fields[9]);
    if (callback_ids.size() != 8) return false;

    waits = waits_in;
    ticks = ticks_in;
    mutations.clear();
    if (fields[10] != "-") {
        for (const auto& item : split(fields[10], ';')) {
            const auto parts = numbers(item);
            if (parts.size() != 4 || parts[2] >= 8 || parts[3] > 8)
                return false;
            mutations.push_back({parts[0], parts[1], parts[2], parts[3]});
        }
    }
    events.clear();
    callback_calls.fill(0);
    wait_index = 0;
    tick_index = 0;
    created_handle = static_cast<std::uint32_t>(std::stoull(fields[6]));

    porsche::current_tick_006b7c40 = static_cast<std::uint32_t>(std::stoull(fields[1]));
    porsche::clock_worker_iterations_006b7c7c = static_cast<std::uint32_t>(std::stoull(fields[2]));
    porsche::clock_worker_carry_006b7c44 = static_cast<std::uint32_t>(std::stoull(fields[3]));
    porsche::clock_worker_active_006a5c0c = static_cast<std::uint32_t>(std::stoull(fields[4]));
    porsche::timer_rate_005deb48 = static_cast<std::uint32_t>(std::stoull(fields[5]));
    porsche::clock_worker_event_006a5bfc = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(0xdeadbeefu));
    for (std::size_t index = 0; index < 8; ++index)
        porsche::clock_worker_callbacks_006b7c20[index] = callback_for(callback_ids[index]);

    const auto result = porsche::clock_worker_00565270();

    std::cout << "{\"return\":" << result
        << ",\"active\":" << porsche::clock_worker_active_006a5c0c
        << ",\"current_tick\":" << porsche::current_tick_006b7c40
        << ",\"carry\":" << porsche::clock_worker_carry_006b7c44
        << ",\"iterations\":" << porsche::clock_worker_iterations_006b7c7c
        << ",\"timer_rate\":" << porsche::timer_rate_005deb48
        << ",\"event\":" << handle_text(porsche::clock_worker_event_006a5bfc)
        << ",\"callbacks\":[";
    for (std::size_t index = 0; index < 8; ++index) {
        if (index) std::cout << ',';
        std::cout << callback_id(porsche::clock_worker_callbacks_006b7c20[index]);
    }
    std::cout << "],\"events\":[";
    for (std::size_t index = 0; index < events.size(); ++index) {
        if (index) std::cout << ',';
        std::cout << '"' << events[index] << '"';
    }
    std::cout << "]}\n";
    return true;
}
} // namespace

namespace porsche {
std::uint32_t __stdcall platform_get_tick_count() {
    const auto value = tick_index < ticks.size() ? ticks[tick_index++] : 0u;
    events.push_back("tick:" + std::to_string(value));
    return value;
}
void* __cdecl file_auto_event_0055fb20() {
    events.push_back("create:" + std::to_string(created_handle));
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(created_handle));
}
void* __cdecl file_worker_wait_0055fb90(void* event) {
    const auto active = wait_index < waits.size() ? waits[wait_index++] : 0u;
    clock_worker_active_006a5c0c = active;
    events.push_back("wait:" + handle_text(event) + ":" + std::to_string(active));
    return active != 0 ? event : nullptr;
}
std::uint32_t __cdecl file_close_event_0055fc10(void* event) {
    events.push_back("close:" + handle_text(event));
    return 1;
}
} // namespace porsche

int main() {
    std::string line;
    while (std::getline(std::cin, line))
        if (!execute(line)) return 2;
    return 0;
}
