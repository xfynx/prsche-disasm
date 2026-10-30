#pragma once
#include "../438-audio-pool-allocator/audio_pool_438.hpp"
#include "../435-audio-stop-voice/audio_stop_435.hpp"
#include "../442-audio-initialization/audio_initialization_442.hpp"
#include "../452-audio-record-resources/audio_record_resources_452.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/application_services.hpp"
namespace porsche {
extern volatile std::uint8_t audio_thread_running_006b4880;
extern volatile std::uint8_t audio_thread_requested_006b4881;
extern std::uint8_t audio_device_exit_registered_006b4882;
struct AudioDeviceBufferStorage455 {std::uint32_t raw[2];std::uint32_t aligned[2];};
extern AudioDeviceBufferStorage455 audio_device_buffers_006b4888;
extern std::uint32_t (&audio_device_raw_buffers_006b4888)[2];
extern std::uint32_t (&audio_device_aligned_buffers_006b4890)[2];
extern std::uint32_t audio_device_callback_006b4898;
void __cdecl audio_thread_start_0058e4a0();
void __cdecl audio_thread_wait_0058e4d0();
std::int32_t __cdecl audio_device_stop_lower_0058f5a0();
// Typed original dependencies; no production implementations in this packet.
std::int32_t __cdecl audio_device_initialize_ds_0058ebe0();
std::int32_t __cdecl audio_device_release_ds_0058f1f0();
std::uint32_t __stdcall audio_thread_worker_0058f880(void* argument);
// Link alias for the already recovered signed-return exit callback; same address.
void __cdecl audio_device_exit_callback_00565890();
// One-argument KERNEL32.Sleep, distinct from existing two-argument SleepEx.
void __stdcall audio_platform_sleep_455(std::uint32_t milliseconds);
}
