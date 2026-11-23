cmake_minimum_required(VERSION 3.20)
project(porsche_integration_784 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../780-audio-scene-render-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../777-audio-voice-pitch/audio_voice_pitch_777.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../783-sim-audio-teardown-leaves/sim_audio_teardown_leaves_783.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../777-audio-voice-pitch"
  "${CMAKE_CURRENT_LIST_DIR}/../783-sim-audio-teardown-leaves")
