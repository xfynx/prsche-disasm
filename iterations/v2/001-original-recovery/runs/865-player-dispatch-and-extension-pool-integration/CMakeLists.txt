cmake_minimum_required(VERSION 3.20)
project(porsche_integration_865 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../863-session-records-and-locale-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../861-frame-reset-service/frame_reset_service_861.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/../864-session-extension-pool/session_extension_pool_864.cpp")
target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../861-frame-reset-service"
  "${CMAKE_CURRENT_LIST_DIR}/../864-session-extension-pool")
