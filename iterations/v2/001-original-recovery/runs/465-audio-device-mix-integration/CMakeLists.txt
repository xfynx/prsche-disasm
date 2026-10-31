cmake_minimum_required(VERSION 3.20)
project(porsche_audio_device_mix_465 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../459-audio-release-thread-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
    ../462-audio-directsound-initialize/audio_directsound_initialize_462.cpp
    ../462-audio-directsound-initialize/audio_directsound_state_462.cpp
    ../463-audio-thread-mix/audio_thread_mix_463.cpp
    ../464-audio-probe-startup/audio_probe_startup_464.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../462-audio-directsound-initialize"
    "${CMAKE_CURRENT_SOURCE_DIR}/../463-audio-thread-mix"
    "${CMAKE_CURRENT_SOURCE_DIR}/../464-audio-probe-startup")
