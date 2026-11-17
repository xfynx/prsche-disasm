cmake_minimum_required(VERSION 3.20)
project(porsche_frame_audio_ramp_volume_609 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../606-render-callbacks-mode-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../607-frame-audio-stream-ramp/frame_audio_stream_ramp_607.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../608-frame-audio-channel-volume/frame_audio_channel_volume_608.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../607-frame-audio-stream-ramp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../608-frame-audio-channel-volume")
