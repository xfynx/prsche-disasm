cmake_minimum_required(VERSION 3.20)
project(porsche_startup_service_571 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../567-audio-codec-control-integration/CMakeLists.txt")
# Frozen ready set: Run570 native001 only. Runs568/569 are excluded.
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../570-startup-service-bindings/startup_service_570.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../570-startup-service-bindings")
