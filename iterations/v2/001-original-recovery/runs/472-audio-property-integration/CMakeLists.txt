cmake_minimum_required(VERSION 3.20)
project(porsche_audio_property_472 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../470-audio-fixed-vector-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../471-audio-property-apply/audio_property_apply_471.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../471-audio-property-apply")
