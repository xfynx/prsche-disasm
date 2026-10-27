cmake_minimum_required(VERSION 3.20)
project(porsche_audio_stop_437 LANGUAGES CXX)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../433-startup-modem-audio-integration" entry-433)
target_sources(porsche_game_entry_bridges PRIVATE
    ../435-audio-stop-voice/audio_stop_435.cpp
    ../436-audio-channel-shutdown/audio_shutdown_436.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../435-audio-stop-voice"
    "${CMAKE_CURRENT_SOURCE_DIR}/../436-audio-channel-shutdown")
