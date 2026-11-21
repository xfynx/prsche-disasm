cmake_minimum_required(VERSION 3.20)
project(porsche_integration_730 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../729-frame-control-state-consumer/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../728-audio-resource-copy/audio_resource_copy_728.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../731-scene-tree-constructors/scene_tree_constructors_731.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../728-audio-resource-copy"
  "${CMAKE_CURRENT_SOURCE_DIR}/../731-scene-tree-constructors")
