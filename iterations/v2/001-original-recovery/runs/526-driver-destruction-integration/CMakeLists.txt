cmake_minimum_required(VERSION 3.20)
project(porsche_driver_destruction_526 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../524-decoder-display-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../525-render-driver-destruction/render_driver_destruction_525.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../525-render-driver-destruction")

target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../523-render-resource-buffer/render_buffer_523.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../523-render-resource-buffer")
