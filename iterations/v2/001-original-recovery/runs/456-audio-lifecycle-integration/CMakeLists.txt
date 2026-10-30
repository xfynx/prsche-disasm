cmake_minimum_required(VERSION 3.20)
project(porsche_audio_lifecycle_456 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../453-audio-record-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
    ../455-audio-device-lifecycle/audio_device_lifecycle_455.cpp
    ../455-audio-device-lifecycle/platform_audio_455.cpp
    ../457-startup-win32-bindings/startup_win32_bindings_457.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../455-audio-device-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../457-startup-win32-bindings")
