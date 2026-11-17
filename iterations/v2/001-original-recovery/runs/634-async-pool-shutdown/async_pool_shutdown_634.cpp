// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00592590..005925ce (63B), 00567cf0..00567dbe (207B),
// 00564750..0056478c (61B), 00564700..00564745 (70B), 00563d30..00563e0d (222B).
#include "async_pool_shutdown_634.hpp"

#include <cstddef>
#include <cstdint>

#include "../361-startup-device-pool/startup_pool.hpp"
#include "../372-async-callbacks/async_callbacks.hpp"
#include "porsche/application_main.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/file_disk.hpp"
#include "porsche/file_wait.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/files.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/window_scheduler.hpp"

namespace porsche {

static_assert(sizeof(PhysicalFile) == 32, "original x86 PhysicalFile size");
static_assert(offsetof(PhysicalFile, active) == 0u, "PhysicalFile::active at +0");
static_assert(offsetof(PhysicalFile, padding) == 2u, "PhysicalFile::padding[0] at +2");

static_assert(sizeof(FileOperation) == 48, "original x86 FileOperation size");
static_assert(offsetof(FileOperation, id) == 0x04u, "FileOperation::id at +0x04");
static_assert(offsetof(FileOperation, type) == 0x08u, "FileOperation::type at +0x08");
static_assert(offsetof(FileOperation, flags) == 0x0cu, "FileOperation::flags at +0x0c");
static_assert(offsetof(FileOperation, handle) == 0x18u, "FileOperation::handle at +0x18");
static_assert(offsetof(FileOperation, context) == 0x1cu, "FileOperation::context at +0x1c");
static_assert(offsetof(FileOperation, callback) == 0x20u, "FileOperation::callback at +0x20");

static_assert(sizeof(FileDevice) == 0x70, "original x86 FileDevice size");
static_assert(offsetof(FileDevice, initialized) == 0x00u, "FileDevice::initialized at +0x00");
static_assert(offsetof(FileDevice, current) == 0x20u, "FileDevice::current at +0x20");
static_assert(offsetof(FileDevice, queued) == 0x24u, "FileDevice::queued at +0x24");
static_assert(offsetof(FileDevice, completed) == 0x40u, "FileDevice::completed at +0x40");

std::uint32_t __cdecl physical_file_clear_flag_00592590(std::uint32_t handle) {
    const std::int32_t slot = static_cast<std::int32_t>(~handle);
    if (physical_files_006af084 != nullptr && slot >= 0 && slot < physical_count_006af080) {
        PhysicalFile* const file = physical_files_006af084 + slot;
        if (file->active != 0u) {
            const std::uint32_t previous = file->padding[0];
            if (previous != 0u) {
                file->padding[0] = 0u;
            }
            return previous;
        }
    }
    platform_disk_set_last_error(6u);
    return 0u;
}

void __cdecl file_operation_cancel_00567cf0(std::uint32_t operation_id) {
    FileDevice* const dev = &devices_006a5c7c[operation_id & 0x1fu];
    const std::uint32_t token = dev->initialized != 0u ? io_lock_00580ea0(&dev->queued) : 0u;
    std::int32_t state = 0;
    FileOperation* const op = operation_find_00567b80(dev, operation_id, &state);
    if (op != nullptr && state != 0) {
        bool cancel_op = false;
        switch (op->type) {
        case 2u:
        case 3u:
            if (dev->current == op) {
                (void)physical_file_clear_flag_00592590(op->handle);
            }
            cancel_op = true;
            break;
        case 0u:
        case 4u:
        case 6u:
        case 8u:
        case 9u:
            cancel_op = true;
            break;
        case 1u:
        case 5u:
        case 7u:
        default:
            break;
        }
        if (cancel_op) {
            op->flags |= 2u;
            if (io_locked_remove_005808f0(&dev->queued, reinterpret_cast<IoNode*>(op)) != 0u) {
                io_prepend_005806e0(&dev->completed, reinterpret_cast<IoNode*>(op));
                if (op->callback != nullptr) {
                    const FileCompletion callback = op->callback;
                    op->flags |= 8u;
                    callback(op->id, -1, op->context);
                }
            }
        }
    }
    if (dev->initialized != 0u) {
        io_unlock_00580ec0(&dev->queued, token);
    }
}

std::uint32_t* __cdecl async_slot_resolve_00564750(std::uint32_t handle) {
    const std::int32_t idx = static_cast<std::int32_t>(handle & 0xffu);
    if (static_cast<std::int32_t>(handle) < 0x100 ||
        idx >= static_cast<std::int32_t>(async_pool_capacity_006a5be0)) {
        return nullptr;
    }
    auto* const rec = reinterpret_cast<std::uint32_t*>(
        static_cast<std::uint8_t*>(async_pool_base_006a5bc0) +
        static_cast<std::size_t>(idx) * 0x2cu);
    return *rec == handle ? rec : nullptr;
}

void __cdecl async_slot_cancel_00564700(std::uint32_t handle) {
    std::uint32_t* const slot = async_slot_resolve_00564750(handle);
    if (slot != nullptr && slot[3] == 0u) {
        const std::uint32_t op = slot[6];
        slot[3] = 1u;
        file_operation_cancel_00567cf0(op);
        if (op == 0u && slot[5] == 0u) {
            async_dispatch_00563cc0(slot);
        }
    }
}

void __cdecl application_main_function_00563d30() {
    if (async_pool_base_006a5bc0 == nullptr) {
        return;
    }
    for (std::int32_t i = 0; i < static_cast<std::int32_t>(async_pool_capacity_006a5be0); ++i) {
        const auto* const slot = reinterpret_cast<const std::uint32_t*>(
            static_cast<const std::uint8_t*>(async_pool_base_006a5bc0) +
            static_cast<std::size_t>(i) * 0x2cu);
        async_slot_cancel_00564700(slot[0]);
    }
    for (;;) {
        bool pending = false;
        const std::int32_t capacity = static_cast<std::int32_t>(async_pool_capacity_006a5be0);
        if (capacity > 0) {
            const auto* const base = static_cast<const std::uint8_t*>(async_pool_base_006a5bc0);
            for (std::int32_t i = 0; i < capacity; ++i) {
                const auto* const slot = reinterpret_cast<const std::uint32_t*>(
                    base + static_cast<std::size_t>(i) * 0x2cu);
                if (slot[6] != 0u) {
                    pending = true;
                }
            }
        }
        if (!pending) {
            break;
        }
        if (file_current_thread_0055f780(0u) != 0) {
            (void)file_pump_005366e0(0u);
        }
        (void)file_sleep_0055f740(0u);
    }
    if (async_pool_active_006a5be4 != 0u) {
        (void)close_00533da0(
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(async_pool_active_006a5be4)),
            0x64u);
        async_pool_active_006a5be4 = 0u;
    }
    (void)window_scheduler_remove_005366a0(&async_pool_callback_00563bd0);
    (void)async_pool_callback_00563bd0(0u, 0u);
    heap_lock_destroy_005322d0(async_pool_lock_006a5be8);
    (void)free_00531f90(async_pool_base_006a5bc0);
    async_pool_base_006a5bc0 = nullptr;
}

} // namespace porsche
