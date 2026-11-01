cmake_minimum_required(VERSION 3.20)
project(porsche_startup_gates_483 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../480-file-resource-ramp-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    ../481-startup-gates/startup_gates_481.cpp)
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../481-startup-gates")
