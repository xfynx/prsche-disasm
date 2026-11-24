cmake_minimum_required(VERSION 3.20)
project(porsche_integration_816 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../812-scene-table-load-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../815-heap-slot-and-report-abi/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../814-scene-stage-entry-register/scene_stage_entry_register_814.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../815-heap-slot-and-report-abi/heap_slot_815.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../814-scene-stage-entry-register"
  "${CMAKE_CURRENT_LIST_DIR}/../815-heap-slot-and-report-abi")
