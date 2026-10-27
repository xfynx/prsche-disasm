cmake_minimum_required(VERSION 3.20)
project(porsche_audio_pool_cleanup_440 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../437-audio-stop-integration" entry-437)
target_sources(porsche_game_entry_bridges PRIVATE
    ../438-audio-pool-allocator/audio_pool_438.cpp
    ../439-audio-voice-cleanup/voice_cleanup_439.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../438-audio-pool-allocator"
    "${CMAKE_CURRENT_SOURCE_DIR}/../439-audio-voice-cleanup")
