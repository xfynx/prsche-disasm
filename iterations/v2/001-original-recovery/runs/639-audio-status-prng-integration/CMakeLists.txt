cmake_minimum_required(VERSION 3.20)
project(porsche_audio_status_prng_639 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../636-async-pool-shutdown-activate-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../637-audio-stream-channel-status/audio_stream_channel_status_637.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../638-render-seed-prng/render_seed_prng_638.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../637-audio-stream-channel-status"
  "${CMAKE_CURRENT_SOURCE_DIR}/../638-render-seed-prng")
