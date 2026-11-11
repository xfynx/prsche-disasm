cmake_minimum_required(VERSION 3.20)
project(porsche_audio_stream_creation_563 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../560-audio-stream-routing-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../561-audio-stream-creation/audio_stream_creation_561.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../561-audio-stream-creation")
