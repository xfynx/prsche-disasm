cmake_minimum_required(VERSION 3.20)
project(porsche_integration_672 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../669-audio-callback-and-replay-load-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../670-bigheader-loud-and-startup-diag/bigheader_loud_startup_diag_670.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../671-font-state-and-vec3-dist/font_state_vec3_671.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../670-bigheader-loud-and-startup-diag"
  "${CMAKE_CURRENT_SOURCE_DIR}/../671-font-state-and-vec3-dist")
