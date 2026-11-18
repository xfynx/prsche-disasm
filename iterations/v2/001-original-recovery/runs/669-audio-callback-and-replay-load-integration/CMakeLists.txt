cmake_minimum_required(VERSION 3.20)
project(porsche_integration_669 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../666-ribbon-sampler-and-file-exists-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../667-audio-service-callback/audio_service_callback_667.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../668-startup-replay-load/startup_replay_load_668.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../667-audio-service-callback"
  "${CMAKE_CURRENT_SOURCE_DIR}/../668-startup-replay-load")
