// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005a1ebf..005a1f49 (139B), 005a1f4a..005a1f54 (11B),
// and 00555bc0..00555f92 (979B).
#include "render_clock_stricmp_682.hpp"

#include <cstddef>
#include <cstring>

extern "C" {
std::int32_t __stdcall GetVersionExA(void* version_information);
}

namespace porsche {

namespace {

struct OriginalOsVersionInfoA {
    std::uint32_t dwOSVersionInfoSize;
    std::uint32_t dwMajorVersion;
    std::uint32_t dwMinorVersion;
    std::uint32_t dwBuildNumber;
    std::uint32_t dwPlatformId;
    char szCSDVersion[128];
};

static_assert(sizeof(OriginalOsVersionInfoA) == 0x94u);
static_assert(offsetof(OriginalOsVersionInfoA, dwMinorVersion) == 0x08u);
static_assert(offsetof(OriginalOsVersionInfoA, dwPlatformId) == 0x10u);

std::int32_t __stdcall os_get_version_ex_a(void* version_information) {
    return ::GetVersionExA(version_information);
}

} // namespace

RenderClockGetVersionExA render_clock_get_version_ex_a = os_get_version_ex_a;

std::uint32_t render_clock_hz_005deae4 = 0u;
char cpu_vendor_005deae8[16] = {};
std::uint32_t cpu_serial_005deaf8[3] = {};
std::uint32_t cpu_family_005deb04 = 0u;
std::uint32_t cpu_model_005deb08 = 0u;
std::uint32_t cpu_stepping_005deb0c = 0u;
std::uint32_t cpu_has_3dnow_005deb20 = 0u;
std::uint32_t cpu_has_cmov_005deb28 = 0u;
std::uint32_t cpu_has_movnt_005deb2c = 0u;
std::uint32_t cpu_is_centaur_005deb3c = 0u;

std::int32_t __cdecl crt_atol_005a1ebf(const char* str) {
    const auto* cursor = reinterpret_cast<const unsigned char*>(str);
    for (;;) {
        const std::uint32_t ch = *cursor;
        const std::int32_t is_space = (formatter_float_character_width_005e54dc > 1)
            ? formatter_float_classify_005a2eae(static_cast<int>(ch), 8)
            : (static_cast<std::int32_t>(formatter_ctype_table_005e52d0[ch * 2u]) & 8);
        if (is_space == 0) {
            break;
        }
        ++cursor;
    }

    std::uint32_t ch = *cursor++;
    const std::uint32_t sign = ch;
    if (ch == static_cast<std::uint32_t>('-') || ch == static_cast<std::uint32_t>('+')) {
        ch = *cursor++;
    }

    std::uint32_t total = 0u;
    for (;;) {
        const std::int32_t is_digit = (formatter_float_character_width_005e54dc > 1)
            ? formatter_float_classify_005a2eae(static_cast<int>(ch), 4)
            : (static_cast<std::int32_t>(formatter_ctype_table_005e52d0[ch * 2u]) & 4);
        if (is_digit == 0) {
            break;
        }
        total = total * 10u + (ch - 0x30u);
        ch = *cursor++;
    }

    if (sign == static_cast<std::uint32_t>('-')) {
        total = 0u - total;
    }
    return static_cast<std::int32_t>(total);
}

std::int32_t __cdecl crt_atoi_005a1f4a(const char* str) {
    return crt_atol_005a1ebf(str);
}

std::uint32_t __cdecl render_clock_00555bc0() {
    std::int32_t local_hz = 0;

    shared_runtime_word_005deb1c = 0u;
    cpu_has_3dnow_005deb20 = 0u;
    copy_flag_005deb18 = 0u;
    cpu_stepping_005deb0c = 0u;
    cpu_model_005deb08 = 0u;
    cpu_family_005deb04 = 0u;
    cpu_has_movnt_005deb2c = 0u;
    cpu_has_cmov_005deb28 = 0u;
    cpu_has_rdtsc_005deb24 = 0u;
    cpu_has_p6_005deb14 = 0u;
    copy_flag_005deb10 = 0u;
    cpu_is_centaur_005deb3c = 0u;
    cpu_is_amd_005deb38 = 0u;
    cpu_is_cyrix_005deb34 = 0u;
    copy_flag_005deb30 = 0u;
    cpu_vendor_005deae8[0] = '\0';

    if (cpu_check_cpuid_support_00574e50() == 0u) {
        cpu_is_cyrix_005deb34 = cpu_check_div_flags_00574e89();
    } else {
        std::uint32_t regs[4] = {};
        cpu_query_cpuid_00574e6b(regs, 0u);
        const std::int32_t max_leaf = static_cast<std::int32_t>(regs[0]);
        std::memcpy(cpu_vendor_005deae8 + 0u, &regs[1], 4u);
        std::memcpy(cpu_vendor_005deae8 + 4u, &regs[2], 4u);
        std::memcpy(cpu_vendor_005deae8 + 8u, &regs[3], 4u);
        cpu_vendor_005deae8[12] = '\0';

        if (max_leaf > 0) {
            if (std::strcmp(cpu_vendor_005deae8, "GenuineIntel") == 0) {
                copy_flag_005deb30 = 1u;
            } else if (std::strcmp(cpu_vendor_005deae8, "AuthenticAMD") == 0) {
                cpu_is_amd_005deb38 = 1u;
            } else if (std::strcmp(cpu_vendor_005deae8, "CyrixInstead") == 0) {
                cpu_is_cyrix_005deb34 = 1u;
            } else if (std::strcmp(cpu_vendor_005deae8, "CentaurHauls") == 0) {
                cpu_is_centaur_005deb3c = 1u;
            }

            cpu_query_cpuid_00574e6b(regs, 1u);
            const std::int32_t family = (static_cast<std::int32_t>(regs[0]) >> 8) & 0xf;
            const std::int32_t model = (static_cast<std::int32_t>(regs[0]) >> 4) & 0xf;
            const std::int32_t stepping = static_cast<std::int32_t>(regs[0]) & 0xf;
            cpu_family_005deb04 = static_cast<std::uint32_t>(family);
            cpu_model_005deb08 = static_cast<std::uint32_t>(model);
            cpu_stepping_005deb0c = static_cast<std::uint32_t>(stepping);
            if (family >= 5) {
                copy_flag_005deb10 = 1u;
            }
            if (family >= 6) {
                cpu_has_p6_005deb14 = 1u;
            }

            const std::uint32_t features = regs[2];
            copy_flag_005deb18 = (features >> 23) & 1u;
            const std::uint32_t sse_bit = (features >> 25) & 1u;
            shared_runtime_word_005deb1c = sse_bit;
            cpu_has_rdtsc_005deb24 = (features >> 4) & 1u;
            cpu_has_cmov_005deb28 = (features >> 15) & 1u;
            cpu_has_movnt_005deb2c = sse_bit;
            if (family >= 6 && cpu_is_amd_005deb38 != 0u) {
                cpu_has_movnt_005deb2c = 1u;
            }

            cpu_query_cpuid_00574e6b(regs, 0x80000000u);
            if (regs[0] > 0x80000000u) {
                cpu_query_cpuid_00574e6b(regs, 0x80000001u);
                cpu_has_3dnow_005deb20 = (regs[2] >> 31) & 1u;
            }

            if (const char* const env_mmx = application_diagnostic_environment_005a3050("ISMMX")) {
                copy_flag_005deb18 = static_cast<std::uint32_t>(crt_atoi_005a1f4a(env_mmx));
            }
            if (const char* const env_k3d = application_diagnostic_environment_005a3050("ISK3D")) {
                cpu_has_3dnow_005deb20 = static_cast<std::uint32_t>(crt_atoi_005a1f4a(env_k3d));
            }

            OriginalOsVersionInfoA os_info{};
            os_info.dwOSVersionInfoSize = 0x94u;
            (void)render_clock_get_version_ex_a(&os_info);
            if (os_info.dwPlatformId == 1u && os_info.dwMinorVersion == 0u) {
                shared_runtime_word_005deb1c = 0u;
            }

            if (const char* const env_kni = application_diagnostic_environment_005a3050("ISKNI")) {
                shared_runtime_word_005deb1c =
                    static_cast<std::uint32_t>(crt_atoi_005a1f4a(env_kni));
            }
            if (const char* const env_movnt = application_diagnostic_environment_005a3050("ISMOVNT")) {
                cpu_has_movnt_005deb2c =
                    static_cast<std::uint32_t>(crt_atoi_005a1f4a(env_movnt));
            }

            if (max_leaf >= 2) {
                cpu_query_cpuid_00574e6b(regs, 2u);
            }
            if (max_leaf >= 3) {
                cpu_query_cpuid_00574e6b(regs, 3u);
                cpu_serial_005deaf8[0] = regs[3];
                cpu_serial_005deaf8[1] = regs[2];
                cpu_serial_005deaf8[2] = regs[1];
            }
        }
    }

    std::int64_t qpf_freq = 0;
    (void)render_clock_query_performance_frequency(&qpf_freq);
    if (static_cast<std::uint32_t>(static_cast<std::uint64_t>(qpf_freq)) != 0u) {
        if (cpu_has_rdtsc_005deb24 != 0u) {
            local_hz = render_clock_measure_qpc_rdtsc_00555fa0();
        } else {
            local_hz = render_clock_measure_div_loop_005560b0();
        }
    }

    const std::uint32_t quantized_hz =
        static_cast<std::uint32_t>(render_clock_quantize_hz_00555a10(local_hz));
    render_clock_hz_005deae4 = quantized_hz;
    return quantized_hz;
}

std::uint32_t __cdecl render_mode_clock_00555bc0() {
    return render_clock_00555bc0();
}

} // namespace porsche
