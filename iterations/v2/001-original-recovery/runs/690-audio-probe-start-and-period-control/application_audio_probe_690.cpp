// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00565c70..00565cc9, 90 bytes, sha256
// c56a238afd144bc4a1576587eab2dde73d4685f5e12c950f54dca9eb2b097754.
// Original 004a8b80..004a8ccb, 332 bytes, sha256
// 25e69719e702b1fed6bd91bfe3322deadcbeffa9ae789a6c3f9cbcefede46cfd.
// Callers: accepted 004ab470/004ab4b0/00565890 (lifecycle), 004a6840/004a6a00
// (services/lifecycle); see runs/143 and functions.json unrecovered lists.
#include "application_audio_probe_690.hpp"

#include <cstring>

namespace porsche {

char* application_audio_path_prefix_0065b318 = nullptr;
const char application_audio_replay_text_005cce90[7] = "replay";
const char application_audio_spl_text_005d1a04[5] = ".spl";
const char application_audio_fesfx_text_005d1a14[6] = "fesfx";
const char application_audio_lil_text_005d1a1c[4] = "Lil";

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

// Original 00565c70..00565cc9 (90 bytes). The selector keeps the original
// AND AL,1F semantics: the upper 24 address bits are not masked away, and the
// period cell group is selected by the low five bits before the |0xe0 fixup.
// Arg3/arg4/arg5 dwords are stored before the callback-set call; arg2 is
// forwarded to the accepted frame-services body only when arg3 was nonzero.
void __cdecl application_audio_period_control_00565c70(std::uint32_t flags,
    std::uint32_t value, std::uint32_t third, std::uint32_t fourth,
    std::uint32_t fifth) {
    const std::uint32_t selector = flags & 0xffffff1fu;
    if ((flags & 0xe0u) == 0u) {
        flags |= 0xe0u;
    }
    std::uint8_t* const cell =
        application_audio_device_state_006b48c0.data() +
        (0x148u + (selector << 4u));
    volatile std::uint32_t* const words =
        reinterpret_cast<volatile std::uint32_t*>(cell);
    *words = third;
    *(words + 2) = fourth;
    *(words + 3) = fifth;
    const std::uint32_t period_flags = flags;
    const std::uint32_t captured_third = third;
    (void)audio_period_callback_set_00590250(period_flags);
    if (captured_third == 0u) {
        frame_services_boundary_00565cd0(period_flags, 0u);
    } else {
        frame_services_boundary_00565cd0(period_flags, value);
    }
}

// Original 004a8b80..004a8ccb (332 bytes). The mode cell is re-read after the
// load call exactly as the original reloads [0x00657c98] at 004a8c4b; the
// buffer name is rebuilt from the prefix pointer for the second call.
void __cdecl application_audio_probe_start_004a8b80() {
    if (static_cast<std::int32_t>(
            application_state_006573e8.word(0x00657c98u)) > 2) {
        return;
    }
    char buffer[0x64];
    copy_string(buffer, application_audio_path_prefix_0065b318);
    append_string(buffer, application_audio_replay_text_005cce90);
    append_string(buffer, application_audio_spl_text_005d1a04);
    (void)resource_loadat_quiet_0059db50(
        buffer, &frame_services_word_005d14b0, 0x3cu);
    // Original 004a8c26 re-copies the prefix pointer after the load call.
    copy_string(buffer, application_audio_path_prefix_0065b318);
    if (static_cast<std::int32_t>(
            application_state_006573e8.word(0x00657c98u)) > 1) {
        append_string(buffer, application_audio_lil_text_005d1a1c);
    }
    append_string(buffer, application_audio_fesfx_text_005d1a14);
    application_audio_probe_message_004a6c90(buffer, 7u);
}

} // namespace porsche
