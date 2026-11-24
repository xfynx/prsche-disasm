cmake_minimum_required(VERSION 3.20)
project(porsche_integration_809 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../808-scene-texture-and-render-query-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../805-scene-stage-reset/scene_stage_reset_805.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../806-input-caps-query/input_caps_query_806.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../805-scene-stage-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../806-input-caps-query")
