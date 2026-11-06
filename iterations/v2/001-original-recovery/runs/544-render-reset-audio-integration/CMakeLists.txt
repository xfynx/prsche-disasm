cmake_minimum_required(VERSION 3.20)
project(porsche_render_slot_reset_544 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../542-texture-cleanup-integration/CMakeLists.txt")
# Original555390 is already declared as voidcdecl0 by the accepted496 caller.
# Keep one algorithm/COFF owner and expose the existing typed frontier name.
target_link_options(porsche_original_game_link PRIVATE
    "/alternatename:?render_display_thr_cleanup_00555390@porsche@@YAXXZ=?render_texture_reset_00555390@porsche@@YAXXZ"
)
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../543-render-slot-reset/render_slot_reset_543.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../543-render-slot-reset"
)
