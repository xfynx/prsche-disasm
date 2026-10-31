cmake_minimum_required(VERSION 3.20)
project(porsche_audio_sample_474 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../472-audio-property-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../473-audio-sample-dispatch/audio_sample_dispatch_473.cpp
    ../475-audio-sample-processor/audio_sample_processor_475.cpp
    ../476-audio-sample-converter/audio_sample_converter_476.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../473-audio-sample-dispatch"
    "${CMAKE_CURRENT_SOURCE_DIR}/../475-audio-sample-processor"
    "${CMAKE_CURRENT_SOURCE_DIR}/../476-audio-sample-converter")
