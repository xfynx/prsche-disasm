cmake_minimum_required(VERSION 3.20)
project(porsche_integration_709 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../704-next-layer-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../705-audio-bank-open-period-config/audio_bank_period_705.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../706-scene-child-ctor-and-slot-binding/scene_children_706.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../707-view-teardown-child-leaves/view_teardown_child_leaves_707.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../708-scene-texture-callback-leaf/scene_texture_callback_708.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../705-audio-bank-open-period-config"
  "${CMAKE_CURRENT_SOURCE_DIR}/../706-scene-child-ctor-and-slot-binding"
  "${CMAKE_CURRENT_SOURCE_DIR}/../707-view-teardown-child-leaves"
  "${CMAKE_CURRENT_SOURCE_DIR}/../708-scene-texture-callback-leaf")
