// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004edc00..004edc2f, 48 bytes. Preserve every mutable cursor reload.
#include "splash_command_dispatch_587.hpp"
#include <cstring>

namespace {
using U = std::uint32_t;
static_assert(sizeof(void*) == 4, "the native comparison models x86 pointers");

U load32(U address) {
    U value;
    std::memcpy(&value, reinterpret_cast<const void*>(address), sizeof value);
    return value;
}
void store32(U address,U value) {
    std::memcpy(reinterpret_cast<void*>(address), &value, sizeof value);
}
U load_cursor(void** cursor_storage) {
    U value;
    std::memcpy(&value, cursor_storage, sizeof value);
    return value;
}
void store_cursor(void** cursor_storage,U value) {
    std::memcpy(cursor_storage, &value, sizeof value);
}
}

namespace porsche {
void __cdecl splash_progress_dispatch_004edc00(U record,void** cursor_storage,
                                                U source,std::int32_t phase) {
    store32(load_cursor(cursor_storage),record);

    U destination = load_cursor(cursor_storage);
    destination += 4u;
    store_cursor(cursor_storage,destination);
    store32(load_cursor(cursor_storage),source);

    destination = load_cursor(cursor_storage);
    destination += 4u;
    store_cursor(cursor_storage,destination);
    U phase_bits;
    std::memcpy(&phase_bits,&phase,sizeof phase_bits);
    store32(load_cursor(cursor_storage),phase_bits);

    destination = load_cursor(cursor_storage);
    destination += 4u;
    store_cursor(cursor_storage,destination);
}
}
