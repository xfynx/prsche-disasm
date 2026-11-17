cmake_minimum_required(VERSION 3.20)
project(porsche_startup_clock_misc_600 LANGUAGES CXX)
include("${CMAKE_CURRENT_SOURCE_DIR}/../597-startup-transfer-quality-integration/CMakeLists.txt")
target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../598-startup-clock-callback/startup_clock_callback_598.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/../599-render-misc-cleanup/render_misc_cleanup_599.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../598-startup-clock-callback"
  "${CMAKE_CURRENT_SOURCE_DIR}/../599-render-misc-cleanup")
