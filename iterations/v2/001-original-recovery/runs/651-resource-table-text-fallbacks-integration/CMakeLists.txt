cmake_minimum_required(VERSION 3.20)
project(porsche_resource_table_text_fallbacks_651 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../648-context-helpers-startup-text-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../649-startup-sequence-resource-table/startup_sequence_resource_table_649.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../650-startup-text-fallbacks/startup_text_fallbacks_650.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../334-resource-open"
  "${CMAKE_CURRENT_SOURCE_DIR}/../649-startup-sequence-resource-table"
  "${CMAKE_CURRENT_SOURCE_DIR}/../650-startup-text-fallbacks")
