cmake_minimum_required(VERSION 3.20)
project(porsche_integration_826 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../824-sprite-draw-and-color-closure-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../819-ff-effect-frame-tick-and-report/ff_effect_frame_tick_819.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../821-scene-stage-58b80-ctor/scene_stage_58b80_ctor_821.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../823-render-sprite-sample/sprite_sample_823.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../819-ff-effect-frame-tick-and-report"
  "${CMAKE_CURRENT_LIST_DIR}/../821-scene-stage-58b80-ctor"
  "${CMAKE_CURRENT_LIST_DIR}/../823-render-sprite-sample")
