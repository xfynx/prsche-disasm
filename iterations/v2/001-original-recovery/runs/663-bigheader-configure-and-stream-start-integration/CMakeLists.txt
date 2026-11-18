cmake_minimum_required(VERSION 3.20)
project(porsche_bigheader_configure_and_stream_start_663 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../660-loadat-and-stream-advance-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../661-bigheader-and-audio-probe-configure/bigheader_audio_configure_661.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../662-audio-service-stream-start/audio_service_stream_start_662.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../661-bigheader-and-audio-probe-configure"
  "${CMAKE_CURRENT_SOURCE_DIR}/../662-audio-service-stream-start")
