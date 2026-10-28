cmake_minimum_required(VERSION 3.20)
project(porsche_audio_initialization_444 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../440-audio-pool-cleanup-integration" entry-440)
target_sources(porsche_game_entry_bridges PRIVATE
    ../442-audio-initialization/audio_initialization_442.cpp
    ../443-audio-device-capabilities/audio_capabilities_443.cpp
    ../443-audio-device-capabilities/platform_audio_443.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../442-audio-initialization"
    "${CMAKE_CURRENT_SOURCE_DIR}/../443-audio-device-capabilities")
target_link_libraries(porsche_original_game_link PRIVATE dsound)
