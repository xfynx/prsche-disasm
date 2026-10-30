cmake_minimum_required(VERSION 3.20)
project(porsche_audio_release_thread_459 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../456-audio-lifecycle-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
    ../458-audio-release-chain/audio_release_chain_458.cpp
    ../460-audio-thread-worker/audio_thread_worker_460.cpp
    ../461-audio-filter-kernel/audio_filter_kernel_461.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../458-audio-release-chain"
    "${CMAKE_CURRENT_SOURCE_DIR}/../460-audio-thread-worker"
    "${CMAKE_CURRENT_SOURCE_DIR}/../461-audio-filter-kernel")
