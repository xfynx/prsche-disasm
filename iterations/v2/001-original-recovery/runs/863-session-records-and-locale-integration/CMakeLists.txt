cmake_minimum_required(VERSION 3.20)
project(porsche_integration_863 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../860-session-world-and-wide-environment-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../859-session-records/session_records_859.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../862-wide-locale-compare/crt_wide_compare_862.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../859-session-records"
  "${CMAKE_CURRENT_LIST_DIR}/../862-wide-locale-compare")
