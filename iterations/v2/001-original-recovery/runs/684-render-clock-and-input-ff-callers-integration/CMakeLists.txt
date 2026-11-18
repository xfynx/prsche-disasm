cmake_minimum_required(VERSION 3.20)
project(porsche_integration_684 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../681-render-clock-calibration-and-ff-slot-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../682-render-clock-and-crt-stricmp/render_clock_stricmp_682.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../682-render-clock-and-crt-stricmp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../683-input-ff-slot-callers-and-render-leaves")
