cmake_minimum_required(VERSION 3.20)
project(porsche_audio_mixer_control_467 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../465-audio-device-mix-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../466-audio-mixer-control/audio_mixer_control_466.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../466-audio-mixer-control")
