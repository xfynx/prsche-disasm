// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../559-audio-stream-service/audio_stream_service_559.hpp"
#include "porsche/files.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"

namespace porsche {

// Read-only .rdata strings owned by 0056aff0 (248 bytes total).
extern const char stream_err_invalid_filters_005bd8b8[48];
extern const char stream_err_invalid_taps_005bd8e8[45];
extern const char stream_err_too_many_requests_005bd918[40];
extern const char stream_err_min_requests_005bd940[55];
extern const char stream_source_file_005bd978[19];
extern const char stream_err_buf_small_005bd98c[41];

} // namespace porsche
