cmake_minimum_required(VERSION 3.20)
project(porsche_texture_cleanup_542 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../539-resource-continuation-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../540-render-texture-cleanup-reader/render_texture_cleanup_540.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../540-render-texture-cleanup-reader"
)
