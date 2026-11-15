cmake_minimum_required(VERSION 3.20)
project(porsche_texture_transfer_578 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../576-render-texture-scheduler-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../577-render-texture-transfer/render_texture_transfer_577.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../577-render-texture-transfer/texture_children_577.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../577-render-texture-transfer")
