cmake_minimum_required(VERSION 3.20)
project(porsche_integration_877 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../873-session-scene-and-world-reset-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../875-route-keyframe-samples/route_keyframe_samples_875.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../876-scene-emitter-reset/scene_emitter_reset_876.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../875-route-keyframe-samples"
  "${CMAKE_CURRENT_LIST_DIR}/../876-scene-emitter-reset")
