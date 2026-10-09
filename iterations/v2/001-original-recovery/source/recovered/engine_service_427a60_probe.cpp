#include "porsche/engine_service_427a60.hpp"

#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
const char* engine_service_root_0065b360 = nullptr;
}

struct Event {
    std::string name;
    std::string path;
    std::uintptr_t a = 0, b = 0, c = 0;
};
static std::vector<Event> events;
static std::int32_t file_result = 0;
static void* load_result = nullptr;
static std::uint32_t native_call_sp = 0;
static std::uint32_t native_return_sp = 0;

namespace porsche {
void __cdecl file_format_005a0fbf(char* out, const char* format,
                                 const char* root, const char* suffix) {
    std::snprintf(out, 100, format, root, suffix);
    events.push_back({"format", std::string(format) + "|" + root + "|" +
        suffix + "|" + out});
}

std::int32_t __cdecl engine_service_file_exists_0059dd00(const char* path) {
    events.push_back({"exists", path});
    return file_result;
}

void* __cdecl game_setup_resource_file_open_0059d8e0(const char* path,
                                                     std::uint32_t zero) {
    events.push_back({"load", path, zero});
    return load_result;
}

void __cdecl engine_service_consume_resource_0048cb50(
    std::uint32_t zero, void* resource, std::int32_t exists) {
    events.push_back({"consume", {}, zero,
        reinterpret_cast<std::uintptr_t>(resource),
        static_cast<std::uint32_t>(exists)});
}

std::uint32_t __cdecl free_00531f90(void* resource) {
    events.push_back({"free", {}, reinterpret_cast<std::uintptr_t>(resource)});
    return 0xdeadbeef;
}
} // namespace porsche

__declspec(naked) static void invoke_engine_service() {
    __asm {
        mov native_call_sp, esp
        call porsche::engine_service_00427a60
        mov native_return_sp, esp
        ret
    }
}

static std::string json_escape(const std::string& s) {
    std::string out;
    for (const char c : s) {
        if (c == '\\' || c == '"') out.push_back('\\');
        if (c == '\n') out += "\\n"; else out.push_back(c);
    }
    return out;
}

int main() {
    constexpr const char* roots[] = {"DATA\\", "./", "C:\\NFS5\\DATA\\"};
    constexpr std::int32_t exists_values[] = {0, 1, -1};
    constexpr std::uintptr_t resources[] = {0, 0x12345678u, 0x87654321u};
    for (std::size_t i = 0; i < 3; ++i) {
        events.clear();
        porsche::engine_service_root_0065b360 = roots[i];
        file_result = exists_values[i];
        load_result = reinterpret_cast<void*>(resources[i]);
        invoke_engine_service();
        std::cout << "{\"case\":" << i << ",\"esp_delta\":"
                  << static_cast<std::int32_t>(native_return_sp-native_call_sp)
                  << ",\"events\":[";
        for (std::size_t j = 0; j < events.size(); ++j) {
            const auto& e = events[j];
            if (j) std::cout << ',';
            std::cout << "{\"name\":\"" << e.name << "\",\"path\":\""
                      << json_escape(e.path) << "\",\"a\":" << e.a
                      << ",\"b\":" << e.b << ",\"c\":" << e.c << '}';
        }
        std::cout << "]}\n";
    }
    return 0;
}
