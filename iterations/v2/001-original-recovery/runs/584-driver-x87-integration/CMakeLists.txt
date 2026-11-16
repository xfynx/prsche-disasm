cmake_minimum_required(VERSION 3.20)
project(porsche_driver_x87_584 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../582-driver-state-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../583-render-driver-x87/render_driver_x87_583.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../583-render-driver-x87")
