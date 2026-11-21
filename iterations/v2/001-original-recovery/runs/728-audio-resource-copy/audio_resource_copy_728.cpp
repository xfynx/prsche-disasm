// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "audio_resource_copy_728.hpp"
#include "../504-audio-coded-constructors/audio_coded_constructors_504.hpp"
#include "../553-audio-resampler-kernel/audio_resampler_kernel_553.hpp"
#include "porsche/application_audio_device.hpp"
#include <cstring>

namespace porsche {
using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

void* __stdcall platform_virtual_alloc(void*, U, U, U);
U __stdcall platform_virtual_free(void*, U, U);
const U audio_copy_min_005c1694 = 0xc7000000u;

namespace {
// Exact original FCOMP/FNSTSW decisions, including unordered inputs.
unsigned short clipped(U input) {
    U status;
    __asm {
        mov ecx, input
        fld dword ptr [ecx]
        fcomp dword ptr [audio_resampler_scalar_005c1698]
        fnstsw ax
        movzx eax, ah
        mov status, eax
    }
    if (!(status & 0x41)) {
        return 0x7fff;
    }
    __asm {
        mov ecx, input
        fld dword ptr [ecx]
        fcomp dword ptr [audio_copy_min_005c1694]
        fnstsw ax
        movzx eax, ah
        mov status, eax
    }
    if (status & 1) {
        return 0x8000;
    }
    __asm {
        mov ecx, input
        fld dword ptr [ecx]
    }
    return static_cast<unsigned short>(audio_stream_ftol_005a0f98());
}
}

U __cdecl audio_resource_copy_0058e310(
    U source, I format, I start, I end, U count, void* destination, I bits) {
    U samples = reinterpret_cast<U>(platform_virtual_alloc(
        nullptr, count * 4u + 20000u, 0x3000, 4));

    // Fields1/2/5 remain opaque. Canonical constructors read written fields only.
    U params[8];
    params[0] = source;
    params[3] = count;
    params[6] = application_audio_device_state_006b48c0[0xe3];

    // Keep unwritten object bytes opaque, as in the original stack frame.
    B pcm[0x1c];
    B nibble[0xa0];
    B adpcm[0xd58];
    U object = 0;
    if (format == 0 || format == 8 || format == 2 || format == 9) {
        params[4] = (format == 0 || format == 8) ? 1u : 0u;
        object = reinterpret_cast<U>(pcm);
        audio_mixer_construct_pcm_00597c10(object, params);
    } else if (format == 3 || format == 10) {
        samples += 8;
        object = reinterpret_cast<U>(nibble);
        audio_mixer_construct_nibble_00597dc0(object, params);
    } else if (format == 4) {
        object = reinterpret_cast<U>(adpcm);
        audio_mixer_construct_adpcm_00597f20(object, params);
    }

    if (object) {
        U process;
        std::memcpy(&process, reinterpret_cast<void*>(object + 4), 4);
        reinterpret_cast<I(__cdecl*)(U, U, U, U, U)>(process)(
            object, count, 0, samples, 0);
    }

    if (end > 0) {
        count = static_cast<U>(end) - static_cast<U>(start) + 1u;
        samples += static_cast<U>(start) * 4u;
    }
    if (bits == 8 && static_cast<I>(count) > 0) {
        U input = samples;
        U output = reinterpret_cast<U>(destination);
        do {
            const auto value = clipped(input);
            std::memcpy(reinterpret_cast<void*>(output), &value, 2);
            input += 4;
            output += 2;
        } while (--count);
    }

    // Preserve the original cropped release pointer, including its quirks.
    if (format == 3 || format == 10) {
        samples -= 8;
    }
    platform_virtual_free(reinterpret_cast<void*>(samples), 0, 0x8000);
    return 0;
}
}
