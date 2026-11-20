// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a6bc0..004a6c80 (193 bytes) and 005901b0..00590248 (153 bytes).
// Body SHA-256 values are pinned in native-config.json / scope-evidence.json.
#include "audio_finalize_period_703.hpp"

#include "porsche/application_audio_device.hpp"

#include <cstring>

namespace porsche {

const char audio_bank_add_fail_text_005d141c[38] =
    "AudioCmn_AddBank(): DID NOT ADD '%s'\n";

std::uint32_t audio_period_handler_slots_006b16b0[3]{};
std::uint8_t audio_period_default_target_005e25b0[4]{0x46u, 0x58u, 0x00u, 0x00u};

namespace {

inline std::uint32_t device_word(std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, &application_audio_device_state_006b48c0[offset], 4u);
    return value;
}

inline std::uint16_t device_halfword(std::size_t offset) {
    std::uint16_t value = 0u;
    std::memcpy(&value, &application_audio_device_state_006b48c0[offset], 2u);
    return value;
}

} // namespace

// Original 004a6bc0..004a6c80 (193 bytes). Scans text for the last backslash so
// basename points just past it (or at text when none). The bank open result 7
// takes the add path (size, allocate, copy, free, residual size); 8 is accepted
// without work; any other status reports a diagnostic. The three dwords are
// stored into the 16-byte record selected by kind (no original bounds check;
// proof inputs bound kind to 0..7).
std::int32_t __cdecl audio_bank_finalize_004a6bc0(const char* text,
                                                  std::int32_t bank_result,
                                                  const void* handle,
                                                  std::uint32_t kind) {
    const char* basename = text;
    for (const char* scan = text; *scan != '\0'; ++scan) {
        if (*scan == '\\') {
            basename = scan + 1;
        }
    }

    std::uint32_t bank_index = 0xffffffffu;
    const std::int32_t status = audio_bank_open_00565b60(&bank_index, handle);
    const void* stored_pointer = handle;

    if (status == 7) {
        const std::int32_t size =
            audio_bank_get_size_00565b30(static_cast<std::int32_t>(bank_index));
        void* const buffer = allocate_00531ca0(basename, size, 0u);
        audio_bank_copy_00565ad0(buffer, static_cast<std::int32_t>(bank_index));
        free_00531f90(const_cast<void*>(handle));
        const std::int32_t copied =
            audio_bank_get_size_00565b30(static_cast<std::int32_t>(bank_index));
        bank_result -= copied;
        stored_pointer = buffer;
    } else if (status != 8) {
        startup_service_noop_00516950();
        render_display_texture_report_005a177b(
            audio_bank_add_fail_text_005d141c,
            reinterpret_cast<std::uint32_t>(basename));
    }

    ApplicationAudioRecord006564a0& record =
        application_audio_records_006564a0[kind];
    record.raw_00 = bank_index;
    record.raw_08 = reinterpret_cast<std::uint32_t>(stored_pointer);
    record.opaque_0c = static_cast<std::uint32_t>(bank_result);
    return bank_result;
}

// Original 005901b0..00590248 (153 bytes). EAX=ECX, low byte of flags selects
// two independent actions; the upper 24 address bits are deliberately preserved
// (wild upper-bit inputs remain an explicit unproved domain). Flag 0x80 applies
// the current period to the device backend; flag 0x20 changes the handler slots:
// period 0 clears them and resets, otherwise a kind word and a target address
// configure the period and the original three handler constants are stored.
void __cdecl audio_period_callback_005901b0(std::int32_t flags,
                                            std::uint32_t period_value) {
    audio_backend_lock_005896d0();
    const std::uint8_t selector = static_cast<std::uint8_t>(flags);

    if ((selector & 0x80u) != 0u) {
        audio_ds_apply_property_0058e780(period_value, device_word(0x150u),
                                         device_word(0x154u));
    }

    if ((selector & 0x20u) != 0u) {
        if (period_value == 0u) {
            audio_period_handler_slots_006b16b0[0] = 0u;
            audio_period_handler_slots_006b16b0[1] = 0u;
            audio_period_handler_slots_006b16b0[2] = 0u;
            audio_period_reset_00598e80();
            audio_backend_unlock_005896f0();
            return;
        }

        std::uint32_t target = device_word(0x150u);
        if (period_value != 1u) {
            target = reinterpret_cast<std::uint32_t>(
                audio_period_default_target_005e25b0);
        }
        audio_period_configure_00598d10(device_halfword(0x1au), target);
        audio_period_handler_slots_006b16b0[0] = 0x00598a70u;
        audio_period_handler_slots_006b16b0[1] = 0x00598a90u;
        audio_period_handler_slots_006b16b0[2] = 0x00598ae0u;
    }

    audio_backend_unlock_005896f0();
}

} // namespace porsche
