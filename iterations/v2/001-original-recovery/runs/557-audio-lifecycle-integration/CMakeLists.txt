cmake_minimum_required(VERSION 3.20)
project(porsche_audio_lifecycle_557 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../554-audio-kernel-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../555-audio-backend-finalize/audio_backend_finalize_555.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../556-application-audio-lifecycle/application_audio_lifecycle_556.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../555-audio-backend-finalize"
    "${CMAKE_CURRENT_SOURCE_DIR}/../556-application-audio-lifecycle")
