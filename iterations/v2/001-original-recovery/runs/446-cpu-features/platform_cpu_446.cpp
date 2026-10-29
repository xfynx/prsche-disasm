#include "cpu_features_446.hpp"
// Original IAT005b2150: KERNEL32.dll!GetVersionExA, stdcall(148B structure*).
extern "C" std::int32_t __stdcall GetVersionExA(void*);
namespace porsche {
std::int32_t __stdcall cpu_platform_version_446(void* version148) {
    return ::GetVersionExA(version148);
}
}
