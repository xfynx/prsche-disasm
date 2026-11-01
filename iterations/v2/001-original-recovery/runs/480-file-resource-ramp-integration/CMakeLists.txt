cmake_minimum_required(VERSION 3.20)
project(porsche_dependency_closure_480 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../474-audio-sample-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../477-file-stream-queries/file_stream_queries_477.cpp
    ../478-audio-resource-controls/audio_resource_controls_478.cpp
    ../479-audio-mixer-ramp-stop/audio_mixer_ramp_stop_479.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../477-file-stream-queries"
    "${CMAKE_CURRENT_SOURCE_DIR}/../478-audio-resource-controls"
    "${CMAKE_CURRENT_SOURCE_DIR}/../479-audio-mixer-ramp-stop")
