cmake_minimum_required(VERSION 3.20)
project(porsche_integration_808 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../804-render-mode-and-sim-startup-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../801-scene-texture-descriptor-shrink/scene_texture_shrink_801.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../802-render-driver-query/render_driver_query_802.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../375-texture-constructor"
  "${CMAKE_CURRENT_LIST_DIR}/../801-scene-texture-descriptor-shrink"
  "${CMAKE_CURRENT_LIST_DIR}/../802-render-driver-query")
