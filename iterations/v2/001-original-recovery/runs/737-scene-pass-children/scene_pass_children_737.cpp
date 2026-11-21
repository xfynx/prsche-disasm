// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 0053f160..0053f1ab, 76B, SHA-256 2ea3c7e041d8794cc2017b15b2074d33abb78d762d15bf88856000ccf4521f77
// 0053f230..0053f29c, 109B, SHA-256 060443d42213095b9afdd7b97296eafc229b38775fd0185ca5d0fc2710f2f089
// 0053f2a0..0053f318, 121B, SHA-256 255ec16ad5d4e59451bf33b30a12c5316f409c64cd89e7f4a8d47c927370e0fd
#include "scene_pass_children_737.hpp"

#include "../599-render-misc-cleanup/render_misc_cleanup_599.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;
using Factory = void* (__cdecl*)(U, U);
using Configure = void (__thiscall*)(void*, U);
using Method = void (__thiscall*)(void*);
using Query = B (__thiscall*)(void*);

U load32(const void* base, U offset) noexcept {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof value);
    return value;
}

void store32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof value);
}

void* pointer(U value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

U address(const void* value) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(value));
}

template <typename T>
T virtual_slot(void* self, U offset) noexcept {
    const U table = load32(self, 0u);
    return reinterpret_cast<T>(static_cast<std::uintptr_t>(load32(pointer(table), offset)));
}

Factory factory_callback(U callback_va) noexcept {
    // Run599 canonically stores the original sentinel identity as a raw VA.
    // Bind only that proved identity to its typed provider; other nodes retain
    // their actual 32-bit callback pointer transport.
    if (callback_va == 0x0053f980u) {
        return &scene_pass_factory_default_0053f980;
    }
    return reinterpret_cast<Factory>(static_cast<std::uintptr_t>(callback_va));
}

} // namespace

void __fastcall scene_pass_append_0053f160(void* self, void*, void* pass) {
    void* tail = pointer(load32(self, 0x04u));
    if (tail == nullptr) {
        store32(self, 0x04u, address(pass));
        store32(pass, 0x08u, 0u);
        store32(pointer(load32(self, 0x04u)), 0x04u, 0u);
        store32(pass, 0x20u, address(self));
        return;
    }

    while (load32(tail, 0x08u) != 0u) {
        tail = pointer(load32(tail, 0x08u));
    }
    store32(tail, 0x08u, address(pass));
    store32(pass, 0x04u, address(tail));
    store32(pass, 0x08u, 0u);
    store32(pass, 0x20u, address(self));
}

void* __cdecl scene_pass_create_0053f230(U kind, U subkind, U flags) {
    RenderCleanupNode_599* node = render_cleanup_head_0069ebb0;
    if (node == nullptr) {
        node = static_cast<RenderCleanupNode_599*>(render_allocate_0059ef90(8u));
        if (node != nullptr) {
            node->next = nullptr;
            node->callback_va = 0x0053f980u;
        }
        render_cleanup_head_0069ebb0 = node;
    }

    while (node != nullptr) {
        void* const pass = factory_callback(node->callback_va)(kind, subkind);
        if (pass != nullptr) {
            virtual_slot<Configure>(pass, 0x08u)(pass, flags);
            return pass;
        }
        node = node->next;
    }
    return nullptr;
}

void __fastcall scene_pass_finalize_0053f2a0(void* self, void*) {
    U index = 0u;
    for (void* pass = pointer(load32(self, 0x04u));
         pass != nullptr;
         pass = pointer(load32(pass, 0x08u))) {
        virtual_slot<Method>(pass, 0x10u)(pass);
        store32(pass, 0x18u, 0u);
        store32(pass, 0x1cu, 0u);
        if (virtual_slot<Query>(pass, 0x14u)(pass) != 0u) {
            store32(pass, 0x18u, index++);
        }
        if (virtual_slot<Query>(pass, 0x18u)(pass) != 0u) {
            store32(pass, 0x1cu, index++);
        }
        if (virtual_slot<Query>(pass, 0x14u)(pass) != 0u &&
            virtual_slot<Query>(pass, 0x18u)(pass) == 0u) {
            store32(pass, 0x1cu, load32(pass, 0x18u));
        }
    }

    for (void* pass = pointer(load32(self, 0x04u));
         pass != nullptr;
         pass = pointer(load32(pass, 0x08u))) {
        scene_pass_compile_0053f380(pass);
    }
}

} // namespace porsche
