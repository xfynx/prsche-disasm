cmake_minimum_required(VERSION 3.20)
project(porsche_driver_state_582 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../580-texture-comparator-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../581-render-driver-state/render_driver_state_581.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../581-render-driver-state")
