cmake_minimum_required(VERSION 3.20)
project(porsche_integration_812 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../809-scene-reset-and-input-caps-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../810-scene-stage-table-load/scene_stage_table_load_810.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../810-scene-stage-table-load")
