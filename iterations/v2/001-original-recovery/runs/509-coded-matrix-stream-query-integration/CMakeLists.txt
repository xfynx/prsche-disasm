cmake_minimum_required(VERSION 3.20)
project(porsche_coded_matrix_stream_queries_509 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../507-stream-buffer-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../504-audio-coded-constructors/audio_coded_constructors_504.cpp
    ../506-render-matrix-config/render_matrix_506.cpp
    ../508-audio-stream-producer-lifecycle/audio_stream_producer_lifecycle_508.cpp
    ../510-splash-network-queries/splash_network_queries_510.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../504-audio-coded-constructors"
    "${CMAKE_CURRENT_SOURCE_DIR}/../506-render-matrix-config"
    "${CMAKE_CURRENT_SOURCE_DIR}/../508-audio-stream-producer-lifecycle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../510-splash-network-queries"
)
