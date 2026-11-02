cmake_minimum_required(VERSION 3.20)
project(porsche_stream_surface_3dnow_502 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../500-render-pcm-file-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../498-audio-pcm-3dnow-cpp/audio_pcm_3dnow_498.cpp
    ../501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.cpp
    ../503-render-surface-construction/render_surface_503.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../498-audio-pcm-3dnow-cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../501-audio-pcm-stream-lookup"
    "${CMAKE_CURRENT_SOURCE_DIR}/../503-render-surface-construction"
)
