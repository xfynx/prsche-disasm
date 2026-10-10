#include "porsche/resource_leaf.hpp"
#include "porsche/files.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
std::uint32_t resource_leaf_group_005df770 = 0;
}

namespace {
struct ContextView {
    const char* path;
    std::uint32_t opaque_04;
    std::uint32_t opaque_08;
    std::uint32_t callback_diagnostic_flag;
};
struct Event {
    std::string op;
    std::string path;
    std::uint32_t a = 0;
    std::uint32_t b = 0;
    std::uint32_t c = 0;
    std::uint32_t d = 0;
    std::int32_t value = 0;
};
std::vector<Event> events;
std::uint32_t route_result = 0;
std::uint32_t group_value = 0;
std::int32_t dispatch_result = 0;
const char* current_path = nullptr;
std::int32_t native_result = 0;
std::uint32_t native_before = 0;
std::uint32_t native_after = 0;

std::string escape(const std::string& text) {
    std::string result;
    for (char ch : text) {
        if (ch == '\\' || ch == '"') result.push_back('\\');
        if (ch == '\n') result += "\\n"; else result.push_back(ch);
    }
    return result;
}
} // namespace

namespace porsche {
std::uint32_t __cdecl file_device_name_00568e90(const char* path) {
    events.push_back({"route", path, 0, 0, 0, 0,
                      static_cast<std::int32_t>(route_result)});
    return route_result;
}

std::int32_t __cdecl resource_leaf_atomic_dispatch_00568d50(
    ResourceLeafAtomicCallback callback, std::uint32_t device,
    std::uint32_t group, void* context) {
    const auto* view = static_cast<const ContextView*>(context);
    const bool callback_matches = callback == &resource_leaf_callback_00561be0;
    events.push_back({"atomic", view->path,
        callback_matches ? 0x00561be0u : 0u, device, group, 0, 0});
    if (!callback_matches || view->callback_diagnostic_flag != 1 ||
        group != resource_leaf_group_005df770)
        std::abort();
    return dispatch_result;
}

std::int32_t __cdecl resource_leaf_callback_00561be0(
    std::uint32_t, void*) {
    // The actual callback body is deliberately an explicit unrecovered
    // boundary in this run; the atomic fixture must record, not invoke it.
    std::abort();
}
} // namespace porsche

__declspec(naked) static void invoke_resource_leaf() {
    __asm {
        mov native_before, esp
        push current_path
        call porsche::resource_leaf_00561ba0
        mov native_result, eax
        mov native_after, esp
        add esp, 4
        ret
    }
}

int main() {
    struct Case {
        const char* path;
        std::uint32_t route;
        std::uint32_t group;
        std::int32_t dispatch;
    };
    const Case cases[] = {
        {"DATA\\cars\\pic16.fsh", 0, 1, 0},
        {"DATA\\ui\\fonts.fsh", 31, 0x104, -13},
        {"BACKUP\\missing.fsh", 7, 0x80000002u, 0x34567},
    };
    for (std::size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        events.clear();
        route_result = cases[i].route;
        group_value = cases[i].group;
        dispatch_result = cases[i].dispatch;
        porsche::resource_leaf_group_005df770 = group_value;
        current_path = cases[i].path;
        invoke_resource_leaf();
        if (events.size() != 2 || events[0].op != "route" ||
            events[1].op != "atomic")
            std::abort();

        const auto& route = events[0];
        const auto& atomic = events[1];
        std::cout << "{\"case\":" << i
                  << ",\"return\":" << native_result
                  << ",\"caller_argument_bytes\":"
                  << static_cast<std::int32_t>(native_before-native_after)
                  << ",\"events\":["
                  << "{\"op\":\"route\",\"path\":\"" << escape(route.path)
                  << "\",\"value\":" << route_result << "},"
                  << "{\"op\":\"atomic\",\"path\":\"" << escape(atomic.path)
                  << "\",\"callback_va\":" << atomic.a
                  << ",\"device\":" << atomic.b
                  << ",\"group\":" << atomic.c
                  << ",\"context_path_matches\":"
                  << (atomic.path == cases[i].path ? "true" : "false")
                  << ",\"context_flag\":1}]}\n";
    }
    return 0;
}
