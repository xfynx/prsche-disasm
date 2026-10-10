#include "porsche/install_paths.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/render_startup.hpp"

namespace porsche {

// One native backing for original 0065b2a0..0065b38f. The loader owns the
// contents; this storage-only TU keeps the addressable table independent of
// resource-open and free service dependencies for isolated packet fixtures.
void* install_paths_blob_0065b29c = nullptr;
const char* install_paths_table_0065b2a0[60]{};

// Original pointer-cell references proven by the 004b6ff0 table producer and
// their consumers. These are C++ aliases to the canonical slots, not copies.
const char*& game_setup_earts_base_0065b32c = install_paths_table_0065b2a0[35];
const char*& game_setup_load_base_0065b334 = install_paths_table_0065b2a0[37];
const char*& engine_service_root_0065b360 = install_paths_table_0065b2a0[48];
const char*& splash_progress_alternate_base_0065b350 =
    install_paths_table_0065b2a0[44];
const char*& render_display_name_0065b304 = install_paths_table_0065b2a0[25];

} // namespace porsche
