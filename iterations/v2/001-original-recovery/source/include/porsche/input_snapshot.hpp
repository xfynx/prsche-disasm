#pragma once

#include <cstddef>
#include <cstdint>

namespace porsche {

// The two original output buffers are one contiguous 0x324-byte region:
// caps at 006a57f0, then 8 bytes through 006a5a0f, then the 006a5a10
// return view whose keyboard payload begins at 006a5a14.
struct InputSnapshotStorage {
    std::uint8_t capabilities_006a57f0[0x21c];
    std::uint8_t interstitial_006a5a0c[4];
    std::uint8_t keyboard_return_view_006a5a10[0x104];
};
static_assert(offsetof(InputSnapshotStorage, capabilities_006a57f0) == 0x000);
static_assert(offsetof(InputSnapshotStorage, interstitial_006a5a0c) == 0x21c);
static_assert(offsetof(InputSnapshotStorage, keyboard_return_view_006a5a10) == 0x220);
static_assert(sizeof(InputSnapshotStorage) == 0x324);

extern InputSnapshotStorage input_snapshot_storage_006a57f0;

// The original invalid-selector call is variadic. Keep it as an explicit
// boundary; production must bind this to the original diagnostic service.
using InputSnapshotDiagnosticBoundary = void (__cdecl *)(const char*, ...);
extern InputSnapshotDiagnosticBoundary input_snapshot_diagnostic_boundary;

void* __cdecl input_snapshot_getstate_0055feb0(std::int32_t selector);
std::uint8_t* input_snapshot_keyboard_bytes_006a5a14() noexcept;
void* input_snapshot_keyboard_return_006a5a10() noexcept;
std::uint8_t* input_snapshot_capabilities_006a57f0() noexcept;

} // namespace porsche
