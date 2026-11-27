cmake_minimum_required(VERSION 3.20)
project(porsche_integration_888 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../884-scene-route-binding-and-sky-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../886-wide-locale-compare-engines/crt_wide_engines_886.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../887-render-row-converter-and-leaves/render_row_converter_887.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../886-wide-locale-compare-engines"
  "${CMAKE_CURRENT_LIST_DIR}/../887-render-row-converter-and-leaves")
