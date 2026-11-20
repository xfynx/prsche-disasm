cmake_minimum_required(VERSION 3.20)
project(porsche_integration_714 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../712-reverb-scene-children-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../713-audio-group-decode/audio_group_decode_713.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../713-audio-group-decode")
