#include "porsche/auxiliary_wait.hpp"
#include "porsche/clock_worker.hpp"
#include "porsche/file_events.hpp"
#include "porsche/formatter_original.hpp"
#include "porsche/timer_setup.hpp"
#include "porsche/window_runtime.hpp"

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::uint32_t> signal_calls;

std::string hex32(std::uint32_t value) {
    std::ostringstream out;
    out << "0x" << std::hex << std::setw(8) << std::setfill('0') << value;
    return out.str();
}

std::string bytes_hex(const std::uint8_t* bytes, std::size_t count) {
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (std::size_t i = 0; i < count; ++i)
        out << std::setw(2) << static_cast<unsigned>(bytes[i]);
    return out.str();
}

std::uint32_t pointer_bits(const void* value) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
}

namespace porsche {
void __cdecl timer_diagnostic_boundary(const char*, ...) {
    // Run121 never invokes timer setup's unknown diagnostic callback.
}
void __cdecl thread_exit_register_00557380(void (__cdecl*)()) {}
std::uint32_t __cdecl window_thread_start_0055f420(void*, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t*) { return 0; }
void __cdecl window_idle_0055f740(std::uint32_t) {}

std::int32_t __cdecl formatter_original_cleanup_boundary_005a4259(
    std::uint32_t, FormatterOriginalDescriptor32*) {
    return -1;
}

// Narrow fixture OS bindings let the recovered file-event adapters run without
// creating or waiting on host handles. SetEvent ordering is the observed edge.
void* __stdcall platform_create_event(void*, std::int32_t, std::int32_t,
                                      const char*) { return nullptr; }
std::uint32_t __stdcall platform_set_event(void* event) {
    signal_calls.push_back(pointer_bits(event));
    return 1;
}
std::uint32_t __stdcall platform_reset_event(void*) { return 1; }
std::uint32_t __stdcall platform_wait_events(std::uint32_t, void* const*,
    std::int32_t, std::uint32_t, std::int32_t) { return 0; }
std::uint32_t __stdcall platform_close_handle(void*) { return 1; }
std::uint32_t __stdcall platform_last_error() { return 0; }
std::uint32_t __stdcall platform_sleep(std::uint32_t, std::int32_t) { return 0; }
std::uint32_t __stdcall platform_get_tick_count() { return 0; }

// window_runtime.cpp supplies the canonical current-tick word; these unused
// window imports satisfy its separate creator body in this isolated fixture.
std::int32_t __stdcall window_get_system_metrics(std::int32_t) { return 0; }
std::uint32_t __stdcall window_adjust_rect(WindowRect*, std::uint32_t,
    std::int32_t, std::uint32_t) { return 1; }
void* __stdcall window_create_ex(std::uint32_t, const char*, const char*,
    std::uint32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t,
    void*, void*, void*, void*) { return nullptr; }
void* __stdcall window_set_cursor(void*) { return nullptr; }
std::int32_t __stdcall window_show_cursor(std::int32_t) { return 0; }
void __cdecl window_channel_005739b0(std::uint32_t, std::uint32_t) {}
}

int main() {
    std::uint32_t operation, worker_event, auxiliary_event, saved_clock;
    while (std::cin >> operation >> std::hex >> worker_event >> auxiliary_event
                    >> std::dec >> saved_clock) {
        if (operation != 1 || saved_clock > 1) return 2;
        signal_calls.clear();
        porsche::clock_worker_active_006a5c0c = 0;
        porsche::clock_worker_event_006a5bfc = reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(worker_event));
        porsche::auxiliary_wait_event_0069e5dc = reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(auxiliary_event));
        porsche::timer_setup_interval_006a5bf8 = 5;
        porsche::timer_setup_fraction_006a5c00 = 0xfffdu;
        porsche::timer_setup_clock_006a5c04 = 0x1000u;
        porsche::timer_setup_saved_clock_006a5c20 = saved_clock;
        porsche::timer_producer_00564eb0(0, 0, 0, 0, 0);
        std::cout << "{\"case\":\"timer_tail\",\"worker_event\":\""
                  << hex32(worker_event) << "\",\"auxiliary_event\":\""
                  << hex32(auxiliary_event) << "\",\"saved_clock\":" << saved_clock
                  << ",\"clock\":" << porsche::timer_setup_clock_006a5c04
                  << ",\"fraction\":" << porsche::timer_setup_fraction_006a5c00
                  << ",\"signals\":[";
        for (std::size_t i = 0; i < signal_calls.size(); ++i) {
            if (i) std::cout << ',';
            std::cout << '"' << hex32(signal_calls[i]) << '"';
        }
        std::cout << "]}\n";
    }

    std::uint8_t output[8]{};
    porsche::FormatterOriginalDescriptor32 descriptor{
        reinterpret_cast<char*>(output), 8,
        reinterpret_cast<char*>(output), 0x42, {}};
    for (std::size_t i = 0; i < sizeof(descriptor.opaque_tail); ++i)
        descriptor.opaque_tail[i] = static_cast<std::uint8_t>(0xa0u + i);
    const std::uint8_t input[] = {0x41, 0x00, 0xff};
    std::int32_t emitted = 0;
    porsche::formatter_original_span_005a4b18(input, 3, &descriptor, &emitted);
    std::cout << "{\"case\":\"formatter_span\",\"bytes\":\""
              << bytes_hex(output, 3) << "\",\"remaining\":" << descriptor.remaining
              << ",\"emitted\":" << emitted << ",\"tail\":\""
              << bytes_hex(descriptor.opaque_tail, sizeof(descriptor.opaque_tail))
              << "\"}\n";
}
