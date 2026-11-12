cmake_minimum_required(VERSION 3.20)
project(porsche_audio_greedy_573 LANGUAGES CXX)
include(${CMAKE_CURRENT_SOURCE_DIR}/../571-startup-service-integration/CMakeLists.txt)
# Frozen ready set: Run568 native002 only.
target_sources(porsche_game_entry_bridges PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../568-audio-greedy-transition/audio_greedy_transition_568.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../568-audio-greedy-transition)
