cmake_minimum_required(VERSION 3.20)
project(porsche_integration_749 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../747-view-teardown-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../744-audio-stream-header-parse/audio_stream_header_parse_744.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../748-audio-stream-schl-parent/audio_stream_schl_parent_748.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../744-audio-stream-header-parse"
  "${CMAKE_CURRENT_LIST_DIR}/../748-audio-stream-schl-parent")
