cmake_minimum_required(VERSION 3.20)
project(porsche_audio_codec_control_567 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../566-audio-callback-codec-integration/CMakeLists.txt")
# Frozen ready set: Run565 native002 only.
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../565-audio-stream-codec-lifecycle/audio_codec_access_565.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../565-audio-stream-codec-lifecycle")
