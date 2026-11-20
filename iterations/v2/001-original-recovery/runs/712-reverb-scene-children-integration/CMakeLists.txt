cmake_minimum_required(VERSION 3.20)
project(porsche_integration_712 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../709-audio-scene-child-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../710-audio-reverb-typed-children/audio_reverb_children_710.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../711-scene-root-finish-and-secondary-destroy/scene_root_finish_secondary_destroy_711.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../710-audio-reverb-typed-children"
  "${CMAKE_CURRENT_SOURCE_DIR}/../711-scene-root-finish-and-secondary-destroy")
