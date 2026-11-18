cmake_minimum_required(VERSION 3.20)
project(porsche_audio_transition_text_leaves_645 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../642-pattern-match-codec-leaves-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../643-audio-transition-finish/audio_transition_finish_643.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../644-render-startup-text-leaves/render_startup_text_leaves_644.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../643-audio-transition-finish"
  "${CMAKE_CURRENT_SOURCE_DIR}/../644-render-startup-text-leaves")
