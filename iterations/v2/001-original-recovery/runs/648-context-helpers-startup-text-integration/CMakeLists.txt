cmake_minimum_required(VERSION 3.20)
project(porsche_context_helpers_startup_text_648 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../645-audio-transition-text-leaves-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../646-startup-context-table-helpers/startup_context_table_helpers_646.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../647-startup-sequence-text/startup_sequence_text_647.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../290-frame-service-cluster"
  "${CMAKE_CURRENT_SOURCE_DIR}/../313-pr9-resource-open"
  "${CMAKE_CURRENT_SOURCE_DIR}/../646-startup-context-table-helpers"
  "${CMAKE_CURRENT_SOURCE_DIR}/../647-startup-sequence-text")
