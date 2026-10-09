#pragma once
#include <cstddef>
#include <cstdint>

namespace porsche {
// Typed view of only the fields proven by Porsche.exe consumers. Gaps are
// opaque: do not assign semantics to the remaining configuration bytes.
struct alignas(4) OriginalWindowConfiguration {
    std::byte opaque_0000[0x14];
    std::uint32_t width_006b77b4;             // +0x014
    std::uint32_t height_006b77b8;            // +0x018
    std::byte opaque_001c[0x43c];
    void* hwnd_006b7bf8;                      // +0x458
    std::byte opaque_045c[5];
    std::uint8_t fullscreen_006b7c01;         // +0x461
    std::byte opaque_0462[6];
    std::int32_t pos_x_006b7c08;              // +0x468
    std::int32_t pos_y_006b7c0c;              // +0x46c
    std::byte opaque_0470[4];
    std::uint32_t running_006b7c14;           // +0x474
};

static_assert(sizeof(void*)==4,"window configuration reproduces x86 layout");
static_assert(alignof(OriginalWindowConfiguration)==4);
static_assert(offsetof(OriginalWindowConfiguration,width_006b77b4)==0x14);
static_assert(offsetof(OriginalWindowConfiguration,height_006b77b8)==0x18);
static_assert(offsetof(OriginalWindowConfiguration,hwnd_006b7bf8)==0x458);
static_assert(offsetof(OriginalWindowConfiguration,fullscreen_006b7c01)==0x461);
static_assert(offsetof(OriginalWindowConfiguration,pos_x_006b7c08)==0x468);
static_assert(offsetof(OriginalWindowConfiguration,pos_y_006b7c0c)==0x46c);
static_assert(offsetof(OriginalWindowConfiguration,running_006b7c14)==0x474);
static_assert(sizeof(OriginalWindowConfiguration)==0x478);

// Storage is owned alongside the window-create globals in window_create.cpp.
extern OriginalWindowConfiguration window_configuration_storage_006b77a0;

// The procedure's address and worker's configuration name are aliases of one
// pointer variable in window_state.cpp. Probes may bind that pointer to fixtures.
extern void* window_configuration_address_006b77a0;
extern void*& worker_configuration_006b77a0;
}
