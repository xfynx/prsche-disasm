// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0055ff60 (15B), 0048d350 (30B), 0048cdf0 (1364B) + owned .data strings 005d0738..005d078d.
#include "network_sync_barrier_655.hpp"
#include "porsche/application_main.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/heap.hpp"
#include "porsche/network_services.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/startup_services.hpp"
#include "porsche/window_runtime.hpp"
#include "../549-render-diagnostic/render_diagnostic_549.hpp"

#include <cstring>

namespace porsche {

char network_sync_abort_str_005d0738[7] = "Abort\n";
char network_sync_wait_low2_str_005d0740[17] = "Wait to go low2\n";
char network_sync_wait_low1_str_005d0754[17] = "Wait to go low1\n";
char network_sync_wait_high2_str_005d0768[18] = "Wait to go high2\n";
char network_sync_wait_high1_str_005d077c[18] = "Wait to go high1\n";

namespace {
using U = std::uint32_t;
using B = std::uint8_t;

B read_u8(const void* base, U off) {
    return static_cast<const B*>(base)[off];
}

U read_u32(const void* base, U off) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + off, 4u);
    return value;
}

void write_u8(void* base, U off, B value) {
    static_cast<B*>(base)[off] = value;
}

void* ptr_from_u32(U value) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

bool abort_barrier(U abort_mode) {
    render_texture_diagnostic_0055ec50(5u, network_sync_abort_str_005d0738);
    void* const net = startup_network_00628c70;
    if (net == nullptr ||
        read_u32(net, 0x08u) == 0u ||
        read_u8(net, 0xbfu) != 0u ||
        read_u8(net, 0xbeu) == 0u ||
        static_cast<std::int32_t>(read_u32(net, 0xdcu)) < 0 ||
        read_u8(net, 0xc5u) != 0u) {
        return false;
    }
    write_u8(net, 0xc5u, 1u);
    write_u8(startup_network_00628c70, 0xbcu, 1u);
    write_u8(startup_network_00628c70, 0xc4u, 0u);
    if (abort_mode == 0u) {
        network_services_action_0048da60(0xfffffffeu, 0xffffffffu);
        return false;
    }
    void* const locked_net = startup_network_00628c70;
    if (locked_net == nullptr ||
        read_u32(locked_net, 0x08u) == 0u ||
        read_u8(locked_net, 0xbfu) != 0u) {
        return false;
    }
    void* const lock_cell = ptr_from_u32(read_u32(locked_net, 0x10u));
    heap_enter_005322b0(ptr_from_u32(read_u32(lock_cell, 0x00u)));
    void* const receiver = ptr_from_u32(read_u32(startup_network_00628c70, 0x0cu));
    if (abort_mode == 1u) {
        application_network_message_short_0048d350(
            receiver, nullptr, 0xb7u, 0xfffffffeu, 0xffffffffu, 0u);
    } else {
        application_network_message_0048c870(
            receiver, nullptr, 0xb7u, 0xfffffffeu, 0xffffffffu, 0u, 0u);
    }
    write_u8(startup_network_00628c70, 0xbdu, 1u);
    heap_leave_005322c0(ptr_from_u32(read_u32(lock_cell, 0x00u)));
    return false;
}

bool wait_barrier_phase(void* self,
                        U seq_offset,
                        const char* wait_str,
                        U flag_offset,
                        bool wait_high,
                        U abort_mode) {
    const U seq = read_u32(startup_network_00628c70, 0xdcu) + seq_offset;
    void* const receiver = ptr_from_u32(read_u32(self, 0x0cu));
    application_network_message_0048c870(receiver, nullptr, 0xbdu, seq, 0x80000000u, 0u, 0u);
    render_texture_diagnostic_0055ec50(5u, wait_str);
    for (;;) {
        splash_progress_004a4a70(-1);
        void* const net = startup_network_00628c70;
        if (net == nullptr || read_u32(net, 0x08u) == 0u) {
            return abort_barrier(abort_mode);
        }
        if (read_u8(net, 0xbfu) == 0u && read_u8(net, 0xc5u) != 0u) {
            return false;
        }
        if (read_u8(net, 0xbfu) != 0u ||
            read_u8(net, 0xbeu) == 0u ||
            static_cast<std::int32_t>(read_u32(net, 0xdcu)) < 0) {
            return abort_barrier(abort_mode);
        }
        if (startup_input_poll_key_0055ff60() == 0x1bu) {
            return abort_barrier(abort_mode);
        }
        file_sleep_0055f740(1u);
        timed_callbacks_005366e0(0u);
        const B mask = read_u8(self, 0xe5u);
        const B state = read_u8(self, flag_offset);
        const bool phase_done = wait_high ? ((state & mask) == mask) : ((state & mask) == 0u);
        if (phase_done) {
            return true;
        }
    }
}
} // namespace

std::uint32_t __cdecl startup_input_poll_key_0055ff60() {
    auto* const cb = reinterpret_cast<std::uint32_t(__cdecl*)()>(startup_input_key_callback_005df6a4);
    if (cb != nullptr) {
        return cb();
    }
    return 0u;
}

void __fastcall application_network_message_short_0048d350(
    void* receiver, void* edx_unused, std::uint32_t message,
    std::uint32_t first, std::uint32_t second, std::uint32_t fourth) {
    (void)edx_unused;
    application_network_message_0048c870(receiver, nullptr, message, first, second, 0u, fourth);
}

bool __fastcall network_sync_barrier_0048cdf0(void* self, void* edx_unused) {
    (void)edx_unused;
    if (!wait_barrier_phase(self, 0u, network_sync_wait_high1_str_005d077c, 0xe6u, true, 0u)) {
        return false;
    }
    if (!wait_barrier_phase(self, 8u, network_sync_wait_high2_str_005d0768, 0xe7u, true, 0u)) {
        return false;
    }
    if (!wait_barrier_phase(self, 0u, network_sync_wait_low1_str_005d0754, 0xe6u, false, 1u)) {
        return false;
    }
    if (!wait_barrier_phase(self, 8u, network_sync_wait_low2_str_005d0740, 0xe7u, false, 2u)) {
        return false;
    }
    return true;
}

void __cdecl application_main_function_0048cdf0() {
    (void)network_sync_barrier_0048cdf0(startup_network_00628c70, nullptr);
}

void __cdecl startup_sequence_call_0048cdf0() {
    (void)network_sync_barrier_0048cdf0(startup_network_00628c70, nullptr);
}

} // namespace porsche
