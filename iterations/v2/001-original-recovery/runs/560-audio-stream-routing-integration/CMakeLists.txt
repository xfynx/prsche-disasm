cmake_minimum_required(VERSION 3.20)
project(porsche_audio_stream_routing_560 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../557-audio-lifecycle-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../559-audio-stream-service/audio_stream_service_559.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../559-audio-stream-service")
