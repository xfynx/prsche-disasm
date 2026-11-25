cmake_minimum_required(VERSION 3.20)
project(porsche_integration_843 LANGUAGES CXX)

include("${CMAKE_CURRENT_SOURCE_DIR}/../841-entry-fe-service-and-crt-shutdown-integration/CMakeLists.txt")

target_sources(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../842-application-replay-save/application_replay_save_842.cpp")

target_include_directories(porsche_game_entry_bridges PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/../842-application-replay-save")
