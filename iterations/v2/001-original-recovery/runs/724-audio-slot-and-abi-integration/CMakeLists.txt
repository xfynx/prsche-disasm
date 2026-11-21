cmake_minimum_required(VERSION 3.20)
project(porsche_integration_724 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../720-scene-audio-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_SOURCE_DIR}/../723-canonical-abi-bindings/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../722-audio-slot-create/audio_slot_create_722.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../722-audio-slot-create")
