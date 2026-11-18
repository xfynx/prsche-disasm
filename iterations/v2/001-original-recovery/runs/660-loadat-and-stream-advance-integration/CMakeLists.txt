cmake_minimum_required(VERSION 3.20)
project(porsche_loadat_and_stream_advance_660 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../657-sync-barrier-stream-refill-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../658-resource-loadat-and-reset/resource_loadat_658.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../659-audio-stream-codec-advance/audio_stream_codec_advance_659.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../658-resource-loadat-and-reset"
  "${CMAKE_CURRENT_SOURCE_DIR}/../659-audio-stream-codec-advance")
