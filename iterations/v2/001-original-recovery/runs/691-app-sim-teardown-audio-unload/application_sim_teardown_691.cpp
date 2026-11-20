// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 004a88a0..004a8a76 (471B), sha256 e996148d2565f25b81922b6f603030f2bb856ac0503b6993f227e2fb556d5be6.
// Original 004a8cd0..004a8dba (235B), sha256 1ffabd1bd6fc3d960e9b6e94df942d8f3ea004b40b24ed9f7cb48da230e76bbd.
// Original 004b68f0..004b6a40 (337B), sha256 19a24053c09ed8828f4eeb8c6cdc76bc5ee66035fd21673989be6bfd295b5960.
#include "application_sim_teardown_691.hpp"

#include <cstring>

namespace porsche {

SimAudioRecord00656528 application_audio_records_00656528[32]{};
// 0065b318 and the 005d1a1c "Lil" literal are the accepted Run690 cells
// application_audio_path_prefix_0065b318 / application_audio_lil_text_005d1a1c.
const char application_audio_bank_suffix_005d1a20[12] = "SND_coll";
const char sim_deinit_done_log_005d6e60[6] = "Done\n";
const char sim_deinit_log_005d6e68[13] = "Sim De-init ";

namespace {

std::uint32_t load_u32(const void* base, std::uint32_t offset) {
    std::uint32_t value;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, 4u);
    return value;
}

void store_u32(void* base, std::uint32_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, 4u);
}

// Original strlen + REP MOVSD/MOVSB copy: exactly strlen + 1 bytes (NUL included).
void copy_c_string(std::uint8_t* destination, const char* source) {
    const std::size_t length = std::strlen(source);
    std::memcpy(destination, source, length + 1u);
}

// Original append: scan the destination to its NUL, then copy strlen + 1 bytes.
void append_c_string(std::uint8_t* destination, const char* source) {
    std::size_t tail = 0u;
    while (destination[tail] != '\0') {
        ++tail;
    }
    const std::size_t length = std::strlen(source);
    std::memcpy(destination + tail, source, length + 1u);
}

} // namespace

// 004a88a0..004a8a76. Accepted caller: 004b6da5 in 004b6a50 calls this right
// after application_main_function_004acb80; the facade name is the canonical
// application_main.hpp declaration.
void __cdecl application_main_function_004a88a0() {
    frame_services_boundary_004ad510();
    (void)frame_services_boundary_004ae3c0(0x5dcu);
    if (application_state_006573e8.word(0x00657c94u) != 0u) {
        return;
    }
    frame_services_boundary_004af900(0u, 0u);
    application_sim_boundary_004afd30();

    for (std::uint32_t index = 0u; index < 32u; ++index) {
        SimAudioRecord00656528& record = application_audio_records_00656528[index];
        if (record.channel_04 != -1) {
            if (record.handle_08 != -1) {
                application_audio_shutdown_channels_005659f0(record.handle_08);
                const std::uint32_t data = record.data_14;
                record.handle_08 = -1;
                if (data != 0u) {
                    (void)free_00531f90(
                        reinterpret_cast<void*>(static_cast<std::uintptr_t>(data)));
                    record.data_14 = 0u;
                }
            }
            record.channel_04 = -1;
        }
    }

    for (std::uint32_t index = 0u; index < 73u; ++index) {
        std::uint32_t& first = frame_services_records_00656180[index * 2u];
        if (first != 0xffffffffu) {
            (void)audio_channel_stop_00565d60(first);
            first = 0xffffffffu;
            frame_services_records_00656180[index * 2u + 1u] = 0xffffffffu;
        }
    }

    if (frame_services_byte_00656868 != 0) {
        frame_services_boundary_00565cd0(0u, 0u);
        frame_services_byte_00656869 = 0;
        frame_services_byte_00656868 = 0;
    }

    application_sim_boundary_004a8660();
    if (application_audio_active_005d1734 != 0u &&
        static_cast<std::int32_t>(frame_services_words_005d1740[4]) > 0) {
        const std::uint32_t deadline = audio_probe_clock_0053c2e0() + 0x280u;
        for (;;) {
            if (static_cast<std::int32_t>(deadline) <=
                static_cast<std::int32_t>(audio_probe_clock_0053c2e0())) {
                break;
            }
            application_sim_boundary_004b0a20();
            (void)timed_callbacks_005366e0(0u);
            bool progressed = true;
            if (application_state_006573e8.word(0x00657a24u) == 1u) {
                if (application_sim_boundary_004a8570(1, 0, 0) == -1) {
                    progressed = false;
                }
            }
            // The original re-reads the count cell for every record iteration.
            std::uint8_t* const arena = application_state_006573e8.bytes();
            for (std::int32_t index = 0;; ++index) {
                if (index >= static_cast<std::int32_t>(
                                 application_state_006573e8.word(0x00658080u))) {
                    break;
                }
                const std::size_t offset =
                    0xca4u + static_cast<std::size_t>(index) * 0x580u;
                std::uint32_t mode;
                std::memcpy(&mode, arena + offset + 8u, 4u);
                if (mode == 2u) {
                    std::uint32_t object;
                    std::memcpy(&object, arena + offset, 4u);
                    std::int32_t located =
                        application_sim_boundary_004b04d0(static_cast<std::int32_t>(object), 0);
                    if (located > -1 &&
                        application_sim_boundary_004a8570(1, located, 0) == -1) {
                        progressed = false;
                    }
                    located = application_sim_boundary_004b04d0(static_cast<std::int32_t>(object), 1);
                    if (located > -1 &&
                        application_sim_boundary_004a8570(1, located, 0) == -1) {
                        progressed = false;
                    }
                }
            }
            if (progressed) {
                break;
            }
        }
    }

    application_sim_boundary_004af5c0();
    if (static_cast<std::int32_t>(global_005e99f4) < 2) {
        application_sim_boundary_004ae470(
            static_cast<std::int32_t>(application_state_006573e8.word(0x00657cb8u)),
            &application_state_006573e8.word(0x00657cbcu));
        frame_services_boundary_004ae4d0(0u, 0u);
    }
}

// 004a8cd0..004a8dba. Accepted caller: 004b6849 in 004b67b0; the facade name
// is the canonical startup_sequence.hpp declaration.
void __cdecl startup_sequence_call_004a8cd0() {
    if (application_audio_active_005d1734 == 0u) {
        return;
    }
    if (static_cast<std::int32_t>(application_state_006573e8.word(0x00657c98u)) > 2) {
        return;
    }
    application_sim_boundary_004acc10(0, 0x00658374u);
    application_sim_boundary_004ad4d0();

    char path[100];
    const std::size_t length = std::strlen(application_audio_path_prefix_0065b318);
    std::memcpy(path, application_audio_path_prefix_0065b318, length + 1u);
    if (static_cast<std::int32_t>(application_state_006573e8.word(0x00657c98u)) > 1) {
        append_c_string(reinterpret_cast<std::uint8_t*>(path),
                        application_audio_lil_text_005d1a1c);
    }
    append_c_string(reinterpret_cast<std::uint8_t*>(path),
                    application_audio_bank_suffix_005d1a20);
    application_sim_boundary_004a6c90(path, 3);

    application_audio_records_006564a0[5].raw_00 = 0xfffffffeu;
    application_audio_records_006564a0[2].raw_00 = 0xfffffffdu;
}

// 004b68f0..004b6a40. Accepted caller: 004b6f2f in 004b6a50; the facade name
// is the canonical application_main.hpp declaration.
void __cdecl application_main_function_004b68f0() {
    application_sim_boundary_004690f0();
    startup_service_noop_00516950();
    const std::int32_t count =
        static_cast<std::int32_t>(application_state_006573e8.word(0x00658080u));
    for (std::int32_t index = 0; index < count; ++index) {
        std::uint8_t* const object = reinterpret_cast<std::uint8_t*>(
            static_cast<std::uintptr_t>(application_player_object_table_005e8b34[index]));
        std::uint8_t* const descriptor = reinterpret_cast<std::uint8_t*>(
            static_cast<std::uintptr_t>(load_u32(object, 0x558u)));
        copy_c_string(object + 0xb78u, reinterpret_cast<const char*>(descriptor + 0x17cu));
        store_u32(object, 0xb6cu, load_u32(descriptor, 0x0u));
        store_u32(object, 0xb70u, load_u32(descriptor, 0x8u));
        store_u32(object, 0xb74u, load_u32(object, 0x52cu));
        copy_c_string(object + 0xbb8u, reinterpret_cast<const char*>(descriptor + 0x534u));
        std::memcpy(
            application_player_setup_table_005e75a0 +
                static_cast<std::size_t>(index) * 0x96u,
            object + 0xad4u,
            0x96u * sizeof(std::uint32_t));
    }
    application_sim_boundary_00413fd0();
    application_sim_boundary_004a8a80();
    application_sim_boundary_004afe50();
    (void)formatter_stdio_printf_005a177b(sim_deinit_log_005d6e68);
    application_sim_boundary_004a4760();
    startup_service_noop_00516950();
    application_sim_boundary_00414f80();
    application_sim_boundary_00471c40();
    application_sim_boundary_004642f0();
    application_sim_boundary_00425330();
    application_sim_boundary_00412cd0();
    application_sim_boundary_00412e60();
    (void)formatter_stdio_printf_005a177b(sim_deinit_done_log_005d6e60);
}

} // namespace porsche
