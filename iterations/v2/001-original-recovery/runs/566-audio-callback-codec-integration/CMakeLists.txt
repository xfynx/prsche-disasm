cmake_minimum_required(VERSION 3.20)
project(porsche_audio_callback_codec_566 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../563-audio-stream-creation-integration/CMakeLists.txt")
# Frozen ready set: Run564 native008 only. Run565 is excluded.
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../564-audio-callback-resource-chain/audio_callback_resource_564.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../564-audio-callback-resource-chain")
