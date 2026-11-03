cmake_minimum_required(VERSION 3.20)
project(porsche_dsp_state_flush_529 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../526-driver-destruction-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../522-audio-stream-transform/audio_stream_transform_522.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../527-render-state-flush/render_state_flush_527.cpp"
)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../522-audio-stream-transform"
    "${CMAKE_CURRENT_SOURCE_DIR}/../527-render-state-flush"
)
