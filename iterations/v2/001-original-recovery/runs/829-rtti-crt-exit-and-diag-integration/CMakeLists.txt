cmake_minimum_required(VERSION 3.20)
project(porsche_integration_829 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../826-ff-scene-ctor-and-sprite-sample-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../827-scene-rtti-descriptors/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../827-scene-rtti-descriptors/scene_rtti_descriptors_827.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../828-crt-exit-and-diagnostic-closers/crt_exit_diag_828.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../827-scene-rtti-descriptors"
  "${CMAKE_CURRENT_LIST_DIR}/../828-crt-exit-and-diagnostic-closers")
