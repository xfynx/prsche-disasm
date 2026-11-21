cmake_minimum_required(VERSION 3.20)
project(porsche_integration_727 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../724-audio-slot-and-abi-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../725-sim-input-teardown/sim_input_teardown_725.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../721-scene-stage-stack-input-core/scene_stage_stack_core_721.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../726-scene-blur-stage-and-stack-binding/scene_blur_stage_726.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../725-sim-input-teardown"
  "${CMAKE_CURRENT_SOURCE_DIR}/../721-scene-stage-stack-input-core"
  "${CMAKE_CURRENT_SOURCE_DIR}/../726-scene-blur-stage-and-stack-binding")
