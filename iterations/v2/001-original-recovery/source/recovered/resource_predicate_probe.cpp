#include "porsche/resource_predicate.hpp"
#include "porsche/files.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
char file_root_006af168[260]{};
char file_fallback_006af26c[260]{};
char file_roots_enabled_006af370 = 0;
void (__cdecl* missing_file_006afbe4)(const char*, std::int32_t) = nullptr;
}

struct Event {
    std::string op;
    std::string path;
    std::string format;
    std::string root;
    std::int32_t value = 0;
};
static std::vector<Event> events;
static std::int32_t unrooted_result = 0;
static std::int32_t exists_results[8]{};
static std::size_t exists_count = 0;
static std::size_t exists_index = 0;
static const char* current_input = nullptr;
static std::int32_t native_result = 0;
static std::uint32_t native_before = 0;
static std::uint32_t native_after = 0;

namespace porsche {
void __cdecl file_format_005a0fbf(char* out, const char* format,
                                 const char* root, const char* suffix) {
    std::sprintf(out, format, root, suffix);
    events.push_back({"format", out, format, root, 0});
}

std::int32_t __cdecl file_exists_00561b80(const char* path) {
    if (exists_index >= exists_count)
        std::abort();
    const auto result = exists_results[exists_index++];
    events.push_back({"file_probe", path, {}, {}, result});
    return result;
}

std::int32_t __cdecl resource_predicate_unrooted_00561ba0(const char* path) {
    events.push_back({"unrooted_probe", path, {}, {}, unrooted_result});
    return unrooted_result;
}

static void __cdecl missing_file_fixture(const char* path, std::int32_t reason) {
    events.push_back({"missing_callback", path, {}, {}, reason});
}
} // namespace porsche

__declspec(naked) static void invoke_resource_predicate() {
    __asm {
        mov native_before, esp
        push current_input
        call porsche::resource_predicate_0059dd00
        mov native_result, eax
        mov native_after, esp
        add esp, 4
        ret
    }
}

static std::string escape(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (ch == '\\' || ch == '"') result.push_back('\\');
        if (ch == '\n') result += "\\n"; else result.push_back(ch);
    }
    return result;
}

static void copy_text(char (&out)[260], const char* input) {
    std::memset(out, 0, sizeof(out));
    const auto n = std::strlen(input) + 1;
    std::memcpy(out, input, n);
}

static void emit_events() {
    std::cout << '[';
    for (std::size_t i = 0; i < events.size(); ++i) {
        const auto& e = events[i];
        if (i) std::cout << ',';
        std::cout << "{\"op\":\"" << e.op << "\",\"path\":\""
                  << escape(e.path) << "\",\"format\":\""
                  << escape(e.format) << "\",\"root\":\""
                  << escape(e.root) << "\",\"value\":" << e.value << '}';
    }
    std::cout << ']';
}

struct Case {
    const char* input;
    bool roots_enabled;
    const char* primary;
    const char* fallback;
    std::int32_t unrooted;
    std::int32_t exists[4];
    std::size_t exists_count;
};

int main() {
    const Case cases[] = {
        {"cars\\pic16.fsh", false, "DATA\\", "", -7, {0,0,0,0}, 0},
        {"cars\\pic16.fsh", false, "DATA\\", "", 0x1234, {0,0,0,0}, 0},
        {"cars\\pic16.fsh", true, "DATA\\", "BACKUP\\", -9, {1,0,0,0}, 1},
        {"ui\\fonts.fsh", true, "DATA\\", "", 0, {0,0,0,0}, 1},
        {"ui\\fonts.fsh", true, "DATA\\", "BACKUP\\", 0x345, {0,1,0,0}, 2},
        {"missing.fsh", true, "DATA\\", "BACKUP\\", 0, {0,0,0,0}, 2},
        {"zero-after-hit.fsh", true, "DATA\\", "", 0, {static_cast<std::int32_t>(0x80000001u),0,0,0}, 1},
    };

    for (std::size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        const auto& c = cases[i];
        events.clear();
        exists_index = 0;
        exists_count = c.exists_count;
        std::memcpy(exists_results, c.exists, sizeof(c.exists));
        unrooted_result = c.unrooted;
        porsche::file_roots_enabled_006af370 = c.roots_enabled ? 1 : 0;
        copy_text(porsche::file_root_006af168, c.primary);
        copy_text(porsche::file_fallback_006af26c, c.fallback);
        porsche::missing_file_006afbe4 = &porsche::missing_file_fixture;
        static char input_buffer[260];
        copy_text(input_buffer, c.input);
        current_input = input_buffer;
        invoke_resource_predicate();
        if (exists_index != exists_count)
            std::abort();
        std::cout << "{\"case\":" << i << ",\"return\":" << native_result
                  << ",\"caller_argument_bytes\":"
                  << static_cast<std::int32_t>(native_before-native_after)
                  << ",\"events\":";
        emit_events();
        std::cout << "}\n";
    }
    return 0;
}
