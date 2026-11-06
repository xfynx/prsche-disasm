cmake_minimum_required(VERSION 3.20)
project(porsche_audio_nibble_3dnow_545 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../544-render-reset-audio-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../541-audio-nibble-3dnow/audio_nibble_3dnow_541.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../541-audio-nibble-3dnow")
