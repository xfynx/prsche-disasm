cmake_minimum_required(VERSION 3.20)
project(porsche_integration_820 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../816-scene-register-heap-abi-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../813-sim-audio-and-frame-teardown/sim_audio_and_frame_teardown_813.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../818-scene-stage-entry-insert/scene_stage_entry_insert_818.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../813-sim-audio-and-frame-teardown"
  "${CMAKE_CURRENT_LIST_DIR}/../818-scene-stage-entry-insert")
