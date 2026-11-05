cmake_minimum_required(VERSION 3.20)
project(porsche_resource_continuation_539 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../535-resource-processor-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../538-audio-nibble-continuation/audio_nibble_continuation_538.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../537-render-resource-descriptor-cleanup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../538-audio-nibble-continuation"
)
