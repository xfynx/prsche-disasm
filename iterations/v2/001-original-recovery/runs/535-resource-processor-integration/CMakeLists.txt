cmake_minimum_required(VERSION 3.20)
project(porsche_resource_processor_535 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../532-library-dsp-integration/CMakeLists.txt")
# Put the existing alias on the final link, before archive-member extraction.
target_link_options(porsche_original_game_link PRIVATE "/alternatename:?network_lifecycle_wait_0053c380@porsche@@YAXH@Z=?application_audio_wait_0053c380@porsche@@YAXH@Z")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../533-render-resource-factories/render_resource_533.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../534-audio-nibble-process/audio_nibble_process_534.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../536-render-resource-nodes/render_resource_node_536.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../533-render-resource-factories"
    "${CMAKE_CURRENT_SOURCE_DIR}/../534-audio-nibble-process"
    "${CMAKE_CURRENT_SOURCE_DIR}/../536-render-resource-nodes"
)
