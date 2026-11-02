cmake_minimum_required(VERSION 3.20)
project(porsche_callback_pixel_pcm_491 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../487-render-network-mixer-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../488-network-callback-drain/network_callback_drain_488.cpp
    ../489-render-pixel-compare/render_pixel_489.cpp
    ../492-audio-pcm-cpp/audio_pcm_cpp_492.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../488-network-callback-drain"
    "${CMAKE_CURRENT_SOURCE_DIR}/../489-render-pixel-compare"
    "${CMAKE_CURRENT_SOURCE_DIR}/../492-audio-pcm-cpp")
