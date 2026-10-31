cmake_minimum_required(VERSION 3.20)
project(porsche_audio_fixed_vector_470 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../467-audio-mixer-control-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../468-audio-fixed-vector/audio_fixed_vector_468.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../468-audio-fixed-vector")
