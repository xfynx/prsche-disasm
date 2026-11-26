cmake_minimum_required(VERSION 3.20)
project(porsche_integration_860 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../855-session-input-and-environment-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../856-session-reset-gate/session_reset_gate_856.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../857-wide-environment-setter/crt_wide_env_857.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../858-world-cleanup/world_cleanup_858.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../856-session-reset-gate"
  "${CMAKE_CURRENT_LIST_DIR}/../857-wide-environment-setter"
  "${CMAKE_CURRENT_LIST_DIR}/../858-world-cleanup")
