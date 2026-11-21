cmake_minimum_required(VERSION 3.20)
project(porsche_integration_739 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../735-scene-audio-render-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../736-scene-blur-program-lifecycle/scene_blur_program_736.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../737-scene-pass-children/scene_pass_children_737.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../738-scene-blur-stage-child/scene_blur_stage_child_738.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/scene_blur_stage_abi_bridge_739.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../736-scene-blur-program-lifecycle"
  "${CMAKE_CURRENT_SOURCE_DIR}/../737-scene-pass-children"
  "${CMAKE_CURRENT_SOURCE_DIR}/../738-scene-blur-stage-child"
  "${CMAKE_CURRENT_SOURCE_DIR}")
