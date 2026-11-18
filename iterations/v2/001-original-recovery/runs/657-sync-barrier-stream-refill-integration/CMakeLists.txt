cmake_minimum_required(VERSION 3.20)
project(porsche_sync_barrier_stream_refill_657 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../654-movie-setup-codec-release-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../655-network-sync-barrier/network_sync_barrier_655.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../656-audio-stream-codec-refill/audio_stream_codec_refill_656.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../655-network-sync-barrier"
  "${CMAKE_CURRENT_SOURCE_DIR}/../656-audio-stream-codec-refill")
