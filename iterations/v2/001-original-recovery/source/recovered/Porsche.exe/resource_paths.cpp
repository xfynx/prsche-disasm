#include "porsche/resource_paths.hpp"
#include <cstring>

namespace porsche {
std::int32_t __cdecl resource_paths_0059d650() {
    char module_path[0x104];
    char filename[0x104];
    char drive[0x104];
    char candidate[0x104];
    file_roots_enabled_006af370 = 1;
    resource_module_filename_005b2064(nullptr, module_path, 0x104);
    char* slash = std::strrchr(module_path, '\\');
    if (!slash) {
        resource_invalid_module_path_0059d650(module_path);
        return 0; // only reached if the explicit boundary returns
    }
    std::strcpy(filename, slash + 1);
    slash[1] = '\0';
    file_root_006af168[0] = '\0';
    for (int letter = 'd'; letter <= 'z'; ++letter) {
        resource_format_drive_005a0fbf(drive, "%c:\\", letter);
        if (resource_drive_type_005b2060(drive) != 5) continue;
        resource_format_path_005a0fbf(candidate, "%s%s", drive, filename);
        file_exists_00561b80(candidate);
        std::strcpy(file_fallback_006af26c, drive);
        break;
    }
    file_fallback_006af26c[0] = '\0';
    resource_format_drive_005a0fbf(drive, "%c:\\", 'd');
    if (resource_drive_type_005b2060(drive) == 5) {
        resource_format_path_005a0fbf(candidate, "%s%s", drive, filename);
        file_exists_00561b80(candidate);
    }
    file_fallback_006af26c[0] = '\0';
    resource_format_path_005a0fbf(candidate, "%s%s", module_path, "fe.txt");
    return file_exists_00561b80(candidate);
}
}
