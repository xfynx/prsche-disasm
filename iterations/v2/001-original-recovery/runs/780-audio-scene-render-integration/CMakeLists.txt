cmake_minimum_required(VERSION 3.20)
project(porsche_integration_780 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../776-scene-blur-and-input-render-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../773-audio-voice-allocator/audio_allocator_773.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../778-scene-pass-compile-factory/scene_pass_compile_factory_778.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../779-render-env-and-startup-ff/render_env_startup_ff_779.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../773-audio-voice-allocator"
  "${CMAKE_CURRENT_LIST_DIR}/../778-scene-pass-compile-factory"
  "${CMAKE_CURRENT_LIST_DIR}/../779-render-env-and-startup-ff")
