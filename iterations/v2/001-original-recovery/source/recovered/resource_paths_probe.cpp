#include "porsche/resource_paths.hpp"
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {
std::string module_path;
int optical_letter, file_result, final_result;
std::vector<std::string> calls;
void dump(const char* p, std::size_t count) {
    for (std::size_t i = 0; i < count; ++i)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << unsigned(std::uint8_t(p[i]));
}
std::uint32_t __stdcall module_name(void*, char* dest, std::uint32_t capacity) {
    calls.emplace_back("M" + std::to_string(capacity));
    std::memcpy(dest, module_path.c_str(), module_path.size() + 1);
    return std::uint32_t(module_path.size());
}
std::uint32_t __stdcall drive_type(const char* path) {
    calls.emplace_back(std::string("D") + path);
    return optical_letter == int(path[0]) ? 5u : 3u;
}
}
namespace porsche {
ResourceModuleFilename resource_module_filename_005b2064 = module_name;
ResourceDriveType resource_drive_type_005b2060 = drive_type;
char file_root_006af168[260], file_fallback_006af26c[260], file_roots_enabled_006af370;
void __cdecl resource_format_drive_005a0fbf(char* dest, const char*, int letter) {
    std::sprintf(dest, "%c:\\", letter);
    calls.emplace_back(std::string("F") + dest);
}
void __cdecl resource_format_path_005a0fbf(char* dest, const char*, const char* a, const char* b) {
    std::sprintf(dest, "%s%s", a, b);
    calls.emplace_back(std::string("F") + dest);
}
std::int32_t __cdecl file_exists_00561b80(const char* path) {
    calls.emplace_back(std::string("E") + path);
    return std::strstr(path, "fe.txt") ? final_result : file_result;
}
void __cdecl resource_invalid_module_path_0059d650(const char*) {
    calls.emplace_back("U");
}
}
int main() {
    int path_kind;
    while (std::cin >> path_kind >> optical_letter >> file_result >> final_result) {
        module_path = path_kind == 0 ? "C:\\NFS\\Porsche.exe" :
                      path_kind == 1 ? "D:\\Porsche.exe" : "Z:\\Games\\NFS.EXE";
        std::memset(porsche::file_root_006af168, 0xa5, 260);
        std::memset(porsche::file_fallback_006af26c, 0xa5, 260);
        porsche::file_roots_enabled_006af370 = char(0xa5);
        calls.clear();
        const auto result = porsche::resource_paths_0059d650();
        std::cout << std::dec << result << ' ' << unsigned(std::uint8_t(porsche::file_roots_enabled_006af370)) << ' ';
        dump(porsche::file_root_006af168, 260); std::cout << ' ';
        dump(porsche::file_fallback_006af26c, 260); std::cout << ' ';
        for (std::size_t i = 0; i < calls.size(); ++i) {
            if (i) std::cout << ',';
            std::cout << calls[i];
        }
        std::cout << '\n';
    }
}
