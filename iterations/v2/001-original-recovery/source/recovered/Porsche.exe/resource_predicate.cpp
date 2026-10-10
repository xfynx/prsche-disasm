#include "porsche/resource_predicate.hpp"

#include "porsche/files.hpp"

#include <cstring>

namespace porsche {

std::int32_t __cdecl resource_predicate_0059dd00(const char* path) {
    char original_path[260];
    const std::size_t path_bytes = std::strlen(path) + 1;
    std::memcpy(original_path, path, path_bytes);

    if (file_roots_enabled_006af370 == 0)
        return resource_predicate_unrooted_00561ba0(original_path);

    char candidate[260];
    file_format_005a0fbf(candidate, "%s%s", file_root_006af168,
                         original_path);
    if (file_exists_00561b80(candidate) != 0)
        return resource_predicate_unrooted_00561ba0(candidate);

    if (file_fallback_006af26c[0] != '\0') {
        file_format_005a0fbf(candidate, "%s%s", file_fallback_006af26c,
                             original_path);
        if (file_exists_00561b80(candidate) != 0)
            return resource_predicate_unrooted_00561ba0(candidate);
    }

    if (missing_file_006afbe4 != nullptr)
        missing_file_006afbe4(path, -2);
    return 0;
}

} // namespace porsche
