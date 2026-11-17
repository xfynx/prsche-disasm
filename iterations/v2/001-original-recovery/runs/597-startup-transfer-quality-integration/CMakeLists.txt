cmake_minimum_required(VERSION 3.20)
project(porsche_startup_transfer_quality_597 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../594-context-prevideo-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../595-startup-transfer-end/startup_transfer_end_595.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../596-startup-quality-tier/startup_quality_tier_596.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../595-startup-transfer-end"
  "${CMAKE_CURRENT_SOURCE_DIR}/../596-startup-quality-tier")
