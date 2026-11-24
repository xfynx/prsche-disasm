cmake_minimum_required(VERSION 3.20)
project(porsche_integration_800 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../796-render-font-and-sim-queue-teardown-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../795-scene-route-spec-load/scene_route_spec_795.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../799-scene-texture-descriptor-parse/scene_texture_descriptor_799.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../795-scene-route-spec-load"
  "${CMAKE_CURRENT_LIST_DIR}/../799-scene-texture-descriptor-parse")
