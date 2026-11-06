cmake_minimum_required(VERSION 3.20)
project(porsche_diagnostic_codec_551 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../548-resource-allocation-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../549-render-diagnostic/render_diagnostic_549.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../550-audio-codec-frontier/audio_codec_process_550.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../549-render-diagnostic"
    "${CMAKE_CURRENT_SOURCE_DIR}/../550-audio-codec-frontier")
