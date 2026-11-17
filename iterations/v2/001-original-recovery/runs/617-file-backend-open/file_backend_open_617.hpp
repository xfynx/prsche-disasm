// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/file_worker.hpp"
#include "porsche/formatter_search.hpp"
#include "porsche/formatter_strings.hpp"
#include "porsche/disk_open.hpp"
#include "porsche/files.hpp"
#include "../488-network-callback-drain/network_callback_drain_488.hpp"

namespace porsche {

struct FileOpenContext_617 {
    char* prefix_ptr;         // +0x00 (esp+0x0c -> points to prefix_buf)
    const char* full_path;    // +0x04 (esp+0x10 -> path or pipe + 1)
    void* handle_or_tail;     // +0x08 (esp+0x14 -> opened handle)
    std::uint32_t status;     // +0x0c (esp+0x18 -> open status)
    char prefix_buf[260];     // +0x10 (esp+0x1c..0x11f)
};
static_assert(sizeof(FileOpenContext_617) == 0x114, "FileOpenContext_617 size");

} // namespace porsche
