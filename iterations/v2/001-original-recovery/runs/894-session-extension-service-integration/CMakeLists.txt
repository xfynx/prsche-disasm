cmake_minimum_required(VERSION 3.20)
project(porsche_integration_894 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../891-scene-flare-and-driver-draw-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../889-session-extension-service/session_extension_service_889.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../889-session-extension-service")
