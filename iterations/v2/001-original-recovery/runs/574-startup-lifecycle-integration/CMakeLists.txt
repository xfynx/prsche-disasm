cmake_minimum_required(VERSION 3.20)
project(porsche_startup_lifecycle_574 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../573-audio-greedy-integration/CMakeLists.txt")
# Frozen ready set: Run572 native001 only.
target_sources(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../572-startup-service-lifecycle/startup_lifecycle_572.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../572-startup-service-lifecycle")
