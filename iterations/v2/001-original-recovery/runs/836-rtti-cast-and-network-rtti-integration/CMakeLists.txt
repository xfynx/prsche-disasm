cmake_minimum_required(VERSION 3.20)
project(porsche_integration_836 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../833-player-tables-and-entry-fe-integration/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/../825-rtti-dynamic-cast-and-runtime-leaves/bindings.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/../830-network-rtti-bindings/bindings.cmake")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../825-rtti-dynamic-cast-and-runtime-leaves/rtti_cast_825.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../825-rtti-dynamic-cast-and-runtime-leaves")
