#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#undef PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE

#include "porsche/files.hpp"
#include "porsche/resource_dispatch.hpp"

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> events;
std::int32_t open_result = 1;
std::int32_t size_result = 0;
std::uint32_t close_result = 0;
std::uint32_t current_device = 0;
std::uint32_t current_group = 0;
void* current_context = nullptr;
void* current_callback_bits = nullptr;
std::uint32_t native_before = 0;
std::uint32_t native_after = 0;
std::int32_t native_return = 0;
std::uint32_t native_saved_ebx = 0, native_saved_esi = 0;
std::uint32_t native_saved_edi = 0, native_saved_ebp = 0;
std::uint32_t native_after_ebx = 0, native_after_esi = 0;
std::uint32_t native_after_edi = 0, native_after_ebp = 0;
constexpr std::uintptr_t kLockBase = 0x2207000;
constexpr std::uintptr_t kEventBase = 0x2207100;
constexpr std::uintptr_t kHandle = 0x2209000;

std::string json_string(const char* text) {
    std::string output = "\"";
    for (const char* p = text ? text : ""; *p; ++p) {
        if (*p == '\\' || *p == '"') output.push_back('\\');
        if (*p == '\n') output += "\\n"; else output.push_back(*p);
    }
    output.push_back('"');
    return output;
}
std::string json_string(const std::string& text) {
    return json_string(text.c_str());
}
std::uintptr_t bits(const void* value) {
    return reinterpret_cast<std::uintptr_t>(value);
}
void record(const std::string& event) { events.push_back(event); }
void __cdecl diagnostic_fixture(const char* format, ...) {
    const char* file = porsche::diagnostic_file_005deb74();
    std::ostringstream out;
    out << "{\"op\":\"diagnostic\",\"file\":" << json_string(file)
        << ",\"line\":" << porsche::diagnostic_line_005deb78
        << ",\"format\":" << json_string(format) << ",\"args\":[";
    va_list args;
    va_start(args, format);
    if (std::strstr(format, "%s") != nullptr) {
        out << json_string(va_arg(args, const char*));
    } else if (std::strstr(format, "%d") != nullptr) {
        const auto first = va_arg(args, int);
        out << first;
        if (std::strstr(std::strstr(format, "%d") + 2, "%d") != nullptr)
            out << ',' << va_arg(args, int);
    }
    va_end(args);
    out << "]}";
    record(out.str());
}
} // namespace

namespace porsche {
FileDevice* devices_006a5c7c = nullptr;
void (__cdecl* diagnostic_handler_005debf0)(const char*) =
    reinterpret_cast<void (__cdecl*)(const char*)>(&diagnostic_fixture);

void __cdecl file_start_device_00568390(std::uint32_t index) {
    std::ostringstream out;
    out << "{\"op\":\"start_device\",\"index\":" << index << '}';
    record(out.str());
    auto& device = devices_006a5c7c[index];
    device.initialized = 1;
    device.lock = reinterpret_cast<void*>(kLockBase + index*4u);
    device.queued_event = reinterpret_cast<void*>(kEventBase + index*4u);
    device.field6c = 0xff;
}
void __cdecl heap_enter_005322b0(void* lock) {
    std::ostringstream out;
    out << "{\"op\":\"enter\",\"lock\":" << bits(lock) << '}';
    record(out.str());
}
void __cdecl heap_leave_005322c0(void* lock) {
    std::ostringstream out;
    out << "{\"op\":\"leave\",\"lock\":" << bits(lock) << '}';
    record(out.str());
}
std::uint32_t __cdecl file_event_signal_0055fb30(void* event) {
    std::ostringstream out;
    out << "{\"op\":\"signal\",\"event\":" << bits(event) << '}';
    record(out.str());
    return 0xdeadbeefu;
}
bool __cdecl file_open_00533b90(const char* path, std::uint32_t mode,
                                std::uint32_t group, void** handle) {
    std::ostringstream out;
    out << "{\"op\":\"open\",\"path\":" << json_string(path)
        << ",\"mode\":" << mode << ",\"group\":" << group
        << ",\"result\":" << open_result << '}';
    record(out.str());
    *handle = open_result ? reinterpret_cast<void*>(kHandle) : nullptr;
    return open_result != 0;
}
std::int32_t __cdecl size_00533de0(void* handle, std::uint32_t group) {
    std::ostringstream out;
    out << "{\"op\":\"size\",\"handle\":" << bits(handle)
        << ",\"group\":" << group << ",\"result\":" << size_result << '}';
    record(out.str());
    return size_result;
}
std::uint32_t __cdecl close_00533da0(void* handle, std::uint32_t group) {
    std::ostringstream out;
    out << "{\"op\":\"close\",\"handle\":" << bits(handle)
        << ",\"group\":" << group << ",\"result\":" << close_result << '}';
    record(out.str());
    return close_result;
}
} // namespace porsche

__declspec(naked) static void invoke_atomic_dispatch() {
    __asm {
        mov native_saved_ebx, ebx
        mov native_saved_esi, esi
        mov native_saved_edi, edi
        mov native_saved_ebp, ebp
        mov ebx, 0xb1b2b3b4
        mov esi, 0xe1e2e3e4
        mov edi, 0xd1d2d3d4
        mov ebp, 0x1718191a
        mov native_before, esp
        push current_context
        push current_group
        push current_device
        push current_callback_bits
        call porsche::resource_leaf_atomic_dispatch_00568d50
        mov native_return, eax
        mov native_after, esp
        mov native_after_ebx, ebx
        mov native_after_esi, esi
        mov native_after_edi, edi
        mov native_after_ebp, ebp
        add esp, 16
        mov ebx, native_saved_ebx
        mov esi, native_saved_esi
        mov edi, native_saved_edi
        mov ebp, native_saved_ebp
        ret
    }
}

int main() {
    struct Case {
        std::uint32_t device;
        std::uint32_t group;
        std::uint32_t old_group;
        bool initialized;
        bool table_present;
        std::int32_t open;
        std::int32_t size;
    };
    const Case cases[] = {
        {3, 5, 9, true, true, 1, 0x1234},
        {4, 2, 7, true, true, 0, 0},
        {1, 5, 2, true, true, 1, 88},
        {7, 0xffffffffu, 0, true, true, 1, -1},
        {0xffffffffu, 1, 0, true, true, 1, 0},
        {32, 1, 0, true, true, 1, 0},
        {2, 3, 0, false, true, 1, 0},
        {0xffffffffu, 1, 0, true, false, 1, 0},
    };
    static porsche::FileDevice devices[32];
    static char path[] = "DATA\\cars\\pic16.fsh";
    porsche::ResourceAtomicContext context{path, 0xaaaaaaaa, 0xbbbbbbbb, 1};

    for (std::size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        const auto& c = cases[i];
        std::memset(devices, 0, sizeof(devices));
        events.clear();
        open_result = c.open;
        size_result = c.size;
        close_result = 0x7788;
        current_device = c.device;
        current_group = c.group;
        current_context = &context;
        current_callback_bits = reinterpret_cast<void*>(
            reinterpret_cast<std::uintptr_t>(&porsche::resource_leaf_callback_00561be0));
        porsche::devices_006a5c7c = c.table_present ? devices : nullptr;
        if (c.table_present && c.device < 32) {
            auto& d = devices[c.device];
            d.initialized = c.initialized ? 1u : 0u;
            d.lock = reinterpret_cast<void*>(kLockBase + c.device*4u);
            d.queued_event = reinterpret_cast<void*>(kEventBase + c.device*4u);
            d.field6c = c.old_group;
        }
        porsche::diagnostic_file_005deb74_set("fixture-initial");
        porsche::diagnostic_line_005deb78 = 0;
        invoke_atomic_dispatch();
        const porsche::FileDevice* state = c.table_present && c.device < 32
            ? &devices[c.device] : nullptr;
        std::cout << "{\"case\":" << i << ",\"return\":" << native_return
                  << ",\"caller_argument_bytes\":"
                  << static_cast<std::int32_t>(native_before-native_after)
                  << ",\"preserved\":{\"ebx\":" << native_after_ebx
                  << ",\"esi\":" << native_after_esi
                  << ",\"edi\":" << native_after_edi
                  << ",\"ebp\":" << native_after_ebp << "}"
                  << ",\"device_state\":";
        if (state) {
            std::cout << "{\"initialized\":" << state->initialized
                      << ",\"field6c\":" << state->field6c << '}';
        } else std::cout << "null";
        std::cout << ",\"events\":[";
        for (std::size_t j = 0; j < events.size(); ++j)
            std::cout << (j ? "," : "") << events[j];
        std::cout << "]}\n";
    }
    return 0;
}
