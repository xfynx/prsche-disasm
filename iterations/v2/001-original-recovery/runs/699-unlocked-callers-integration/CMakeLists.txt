cmake_minimum_required(VERSION 3.20)
project(porsche_integration_699 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../698-app-startup-cluster-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../695-ff-effect-initialize/ff_effect_initialize_695.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../696-getclutptr-dispatcher/getclutptr_696.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../697-audio-period-callback-and-probe-message/audio_period_callback_probe_697.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../695-ff-effect-initialize"
  "${CMAKE_CURRENT_SOURCE_DIR}/../696-getclutptr-dispatcher"
  "${CMAKE_CURRENT_SOURCE_DIR}/../697-audio-period-callback-and-probe-message")
