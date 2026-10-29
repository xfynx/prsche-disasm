cmake_minimum_required(VERSION 3.20)
project(porsche_cpu_features_447 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../444-audio-initialization-integration" entry-444)
target_sources(porsche_game_entry_bridges PRIVATE
    ../446-cpu-features/cpu_features_446.cpp
    ../446-cpu-features/platform_cpu_446.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../446-cpu-features")
