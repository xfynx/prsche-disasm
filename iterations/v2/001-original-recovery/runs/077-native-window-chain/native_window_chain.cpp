#include "porsche/window_callback_bindings.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_procedure.hpp"
#include "porsche/window_worker.hpp"

#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace {
using InitEntry = std::uint32_t(__cdecl*)(std::uint32_t,std::uint32_t,std::uint32_t);
using WorkerEntry = std::uint32_t(__cdecl*)();
using WorkerThunk = void(__cdecl*)();
using ProcedureEntry = std::int32_t(__stdcall*)(void*,std::uint32_t,std::uint32_t,std::int32_t);
volatile InitEntry retain_init = &porsche::window_init_0053ac20;
volatile WorkerEntry retain_worker = &porsche::window_worker_0053b8d0;
volatile WorkerThunk retain_worker_thunk = &porsche::window_worker_thread_entry;
volatile ProcedureEntry retain_wndproc = &porsche::window_procedure_0053aba0;
}

int main() {
    if(!retain_init || !retain_worker || !retain_worker_thunk || !retain_wndproc) {
        std::fprintf(stderr, "a production startup-chain entry did not link\n");
        return 3;
    }
    std::size_t count = 0;
    const auto* relocations = porsche::window_callback_relocations(&count);
    if (!relocations || count != 16) {
        std::fprintf(stderr, "expected 16 unique recovered callback relocations, got %zu\n", count);
        return 1;
    }
    for (std::size_t i = 0; i < count; ++i) {
        if (!relocations[i].native_callback) {
            std::fprintf(stderr, "unresolved callback VA %08x\n", relocations[i].original_va);
            return 2;
        }
    }
    std::puts("native window chain linked; 16 unique production callbacks resolved for 27 registrations; GUI not started");
    return 0;
}
