cmake_minimum_required(VERSION 3.20)
project(porsche_resource_allocation_548 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../545-audio-nibble-3dnow-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../546-render-resource-allocation/render_resource_allocation_546.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../546-render-resource-allocation")
