// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00590250..00590287, 56 bytes, sha256
// 941bc12ee93b6a85c61f21c7cd88e887c9180c36015ff5c6480b1ef64bbbbfda.
// Original 004a6c90..004a6d3f, 176 bytes, sha256
// c6b4dc0f14b0041bfc02853bb07072e4d60c01851ff56422174d92ed055c4753.
// Callers: accepted 00565c70 (Run690) calls 00590250; accepted 004a8b80
// (Run690) calls 004a6c90. Both caller-ignored EAX values are preserved only
// where the accepted declaration claims a scalar return (00590250).
#include "audio_period_callback_probe_697.hpp"

#include <cstring>

namespace porsche {

const char audio_bank_load_fail_text_005d1444[40] =
    "AudioCmn_LoadBank(): DID NOT LOAD '%s'\n";
const char audio_bank_suffix_text_005d146c[5] = ".bnk";

namespace {

// Original inline strcpy expansion: SCASB length plus MOVSD/MOVSB copy of
// length+1 bytes, NUL included.
void copy_string(char* destination, const char* source) {
    std::size_t index = 0u;
    do {
        destination[index] = source[index];
    } while (source[index++] != '\0');
}

void append_string(char* destination, const char* source) {
    copy_string(destination + std::strlen(destination), source);
}

} // namespace

// Original 00590250..00590287 (56 bytes). EAX = ECX; AND AL,0x1f clears only
// bits 5..7 of the low byte, so the selector is flags & 0xffffff1f. The upper
// 24 address bits are deliberately preserved; wild upper-bit inputs remain an
// explicit unproved domain. CL (the low byte of flags) is stored at
// [0x6b4886 + selector], the callback pointer constant is stored at 0x6b4898,
// and - only when the active byte at 0x6b499c is nonzero - the period dword at
// [0x6b4a08 + selector*16] is read and forwarded to 005901b0 with flags.
std::int32_t __cdecl audio_period_callback_set_00590250(std::uint32_t flags) {
    const std::uint32_t selector = flags & 0xffffff1fu;

    const bool active = application_audio_device_state_006b48c0[0xdcu] != 0u;
    std::uint8_t* const notify =
        reinterpret_cast<std::uint8_t*>(&audio_ds_notify_kind_006b4886);
    notify[selector] = static_cast<std::uint8_t>(flags);

    audio_device_callback_006b4898 = reinterpret_cast<std::uint32_t>(&audio_period_callback_005901b0);

    if (active) {
        const std::uint32_t period_value =
            (&audio_ds_notify_value_006b4a08)[selector << 2u];
        audio_period_callback_005901b0(static_cast<std::int32_t>(flags),
                                       period_value);
    }
    return 0;
}

// Original 004a6c90..004a6d3f (176 bytes). Builds <text>.bnk in a 0x50-byte
// stack buffer, opens it with flags 0x10, reports a formatted diagnostic when
// the handle is null, otherwise runs the path predicate and the four-argument
// bank registration tail. The 0x50-byte local has no original bounds check;
// inputs are bounded by the observed caller (Run690 builds a 0x64-byte name).
void __cdecl application_audio_probe_message_004a6c90(const char* text,
                                                      std::uint32_t kind) {
    char buffer[0x50];
    copy_string(buffer, text);
    append_string(buffer, audio_bank_suffix_text_005d146c);

    void* const handle = resource_open_quiet_0059d9b0(buffer, 0x10u);
    if (handle == nullptr) {
        render_display_texture_report_005a177b(
            audio_bank_load_fail_text_005d1444,
            reinterpret_cast<std::uint32_t>(buffer));
        return;
    }

    const std::int32_t bank_result = resource_predicate_0059dd00(buffer);
    (void)audio_bank_finalize_004a6bc0(text, bank_result, handle, kind);
}

} // namespace porsche
