cmake_minimum_required(VERSION 3.20)
project(porsche_integration_855 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../852-camera-and-route-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../853-session-input-reset/session_input_reset_853.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../854-crt-putenv/crt_putenv_854.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../853-session-input-reset"
  "${CMAKE_CURRENT_LIST_DIR}/../854-crt-putenv")
