cmake_minimum_required(VERSION 3.20)
project(porsche_ribbon_sampler_666 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../663-bigheader-configure-and-stream-start-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../664-road-ribbon-sampler/road_ribbon_sampler_664.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../664-road-ribbon-sampler")
