cmake_minimum_required(VERSION 3.20)
project(porsche_pattern_match_codec_leaves_642 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../639-audio-status-prng-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../640-pattern-match/audio_transition_pattern_match_640.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../641-audio-stream-codec-leaves/audio_stream_codec_leaves_641.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../565-audio-stream-codec-lifecycle"
  "${CMAKE_CURRENT_SOURCE_DIR}/../568-audio-greedy-transition"
  "${CMAKE_CURRENT_SOURCE_DIR}/../640-pattern-match"
  "${CMAKE_CURRENT_SOURCE_DIR}/../641-audio-stream-codec-leaves")
