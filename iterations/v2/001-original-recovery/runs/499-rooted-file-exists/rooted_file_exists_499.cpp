// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original0059dc30..0059dcf5,198B. Existing canonical file state/providers only.
#include "rooted_file_exists_499.hpp"
#include "porsche/files.hpp"
#include <cstring>
namespace porsche {
std::int32_t __cdecl rooted_file_exists_0059dc30(const char* path) {
    char candidate[260];
    if (file_roots_enabled_006af370 == 0) {
        std::memcpy(candidate, path, std::strlen(path) + 1);
    } else {
        file_format_005a0fbf(candidate, "%s%s", file_root_006af168, path);
        if (file_exists_00561b80(candidate) == 0) {
            if (file_fallback_006af26c[0] != '\0') {
                file_format_005a0fbf(candidate, "%s%s", file_fallback_006af26c, path);
                if (file_exists_00561b80(candidate) != 0)
                    return file_exists_00561b80(candidate);
            }
            if (missing_file_006afbe4 != nullptr)
                missing_file_006afbe4(path, -2);
            return 0;
        }
    }
    // A successful rooted probe is followed by a distinct final query.
    return file_exists_00561b80(candidate);
}
std::uint32_t __cdecl game_setup_file_exists_0059dc30(const char* path) {
    return static_cast<std::uint32_t>(rooted_file_exists_0059dc30(path));
}
std::int32_t __cdecl splash_progress_file_exists_0059dc30(const char* path) {
    return rooted_file_exists_0059dc30(path);
}
}
