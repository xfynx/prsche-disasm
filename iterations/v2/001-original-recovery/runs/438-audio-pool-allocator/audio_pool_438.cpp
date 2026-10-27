// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete0058aa60..aa85(38B),0058aae0..ac2e(335B),0058ac30..ac96(103B).
#include "audio_pool_438.hpp"
#include <cstring>

namespace porsche {
namespace {
using U = std::uint32_t;
std::int32_t signed32(U value) { return static_cast<std::int32_t>(value); }
U load(U address) {
    U value;
    std::memcpy(&value,reinterpret_cast<const void*>(static_cast<std::uintptr_t>(address)),4);
    return value;
}
void store(U address,U value) {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(address)),&value,4);
}
}

void __cdecl audio_backend_pool_clamp_0058aa60(const U* offset,U* available) {
    const U pool = audio_backend_pool_006b4a18;
    const U begin = load(static_cast<U>(reinterpret_cast<std::uintptr_t>(offset)));
    const U limit = load(pool + 0x0cu);
    const U gap = load(static_cast<U>(reinterpret_cast<std::uintptr_t>(available)));
    if (signed32(begin + gap) > signed32(limit)) {
        store(static_cast<U>(reinterpret_cast<std::uintptr_t>(available)),limit - begin);
    }
}

U __cdecl application_audio_backend_allocate_0058aae0(U bytes) {
    const U aligned = (bytes + 3u) & 0xfffffffcu;
    U pool = audio_backend_pool_006b4a18;
    const U original_count = load(pool + 0x14u);
    U index = 0;
    U offset;
    U available;
    bool interior = false;
    if (original_count == 0) {
        offset = 0;
        available = load(pool + 0x0cu);
        audio_backend_pool_clamp_0058aa60(&offset,&available);
        if (signed32(aligned) > signed32(available)) return 0;
    } else {
        if (signed32(original_count) < 0) {
            for (;;) {
                const U end = load(pool + 4u);
                if (index == 0) {
                    offset = 0;
                    available = load(end);
                } else {
                    const U length = load(end + index * 8u + 0x0cu);
                    const U begin = load(end + index * 8u + 8u);
                    offset = length + begin;
                    available = load(end + index * 8u) - offset;
                }
                audio_backend_pool_clamp_0058aa60(&offset,&available);
                if (signed32(aligned) <= signed32(available)) {
                    interior = true;
                    break;
                }
                pool = audio_backend_pool_006b4a18;
                index -= 1u;
                if (!(signed32(index) > signed32(load(pool + 0x14u)))) break;
            }
        }
        if (!interior) {
            const U end = load(pool + 4u);
            const U begin = load(end + index * 8u + 8u);
            const U length = load(end + index * 8u + 0x0cu);
            offset = length + begin;
            available = load(pool + 0x0cu) - offset;
            audio_backend_pool_clamp_0058aa60(&offset,&available);
            if (signed32(aligned) > signed32(available)) return 0;
        }
    }
    pool = audio_backend_pool_006b4a18;
    if (interior) {
        const U count = load(pool + 0x14u);
        if (signed32(count) < signed32(index)) {
            U entry = load(pool + 4u) + count * 8u;
            U remaining = index - count;
            do {
                const U begin = load(entry + 8u);
                store(entry,begin);
                const U length = load(entry + 0x0cu);
                store(entry + 4u,length);
                entry += 8u;
                remaining -= 1u;
            } while (remaining != 0);
        }
    }
    const U entry = load(pool + 4u) + index * 8u;
    store(entry,offset);
    const U count = load(pool + 0x14u);
    store(entry + 4u,aligned);
    store(pool + 0x14u,count - 1u);
    const U limit = load(pool + 0x0cu) - 8u;
    store(pool + 0x0cu,limit);
    const U address = load(pool) + offset;
    const U cursor = load(pool + 0x10u);
    const U remaining = limit - offset - aligned;
    if (signed32(remaining) < signed32(cursor)) store(pool + 0x10u,remaining);
    return address;
}

std::int32_t __cdecl audio_backend_pool_release_0058ac30(U address) {
    const U pool = audio_backend_pool_006b4a18;
    const U base = load(pool);
    const U count = load(pool + 0x14u);
    const U offset = address - base;
    U index = 0;
    if (signed32(count) >= 0) return -8;
    U entry = load(pool + 4u);
    for (;;) {
        if (load(entry) == offset) break;
        index -= 1u;
        entry -= 8u;
        if (!(signed32(index) > signed32(count))) return -8;
    }
    store(pool + 0x14u,count + 1u);
    const U limit = load(pool + 0x0cu) + 8u;
    store(pool + 0x0cu,limit);
    const U new_count = load(pool + 0x14u);
    if (signed32(index) > signed32(new_count)) {
        U destination = load(pool + 4u) + index * 8u;
        U remaining = index - new_count;
        U source = destination - 8u;
        do {
            const U begin = load(source);
            source -= 8u;
            store(destination,begin);
            const U length = load(source + 0x0cu);
            store(destination + 4u,length);
            destination -= 8u;
            remaining -= 1u;
        } while (remaining != 0);
    }
    return 0;
}

// Existing application lifecycle caller discards the original EAX. One canonical
// body owns0058ac30; this typed facade adds no original function.
void __cdecl application_audio_backend_release_0058ac30(U address) {
    (void)audio_backend_pool_release_0058ac30(address);
}
} // namespace porsche
