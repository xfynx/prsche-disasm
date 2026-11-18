cmake_minimum_required(VERSION 3.20)
project(porsche_integration_687 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../684-render-clock-and-input-ff-callers-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../685-render-palette-pixel-expand-leaves/render_palette_expand_685.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../686-render-palette-convert-leaf-table/render_palette_convert_686.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../685-render-palette-pixel-expand-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../686-render-palette-convert-leaf-table")
